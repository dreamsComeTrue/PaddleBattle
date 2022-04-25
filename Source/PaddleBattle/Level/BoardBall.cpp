// Copyright AGADO Studio 2022. All rights reserved

#include "BoardBall.h"
#include "../Player/Paddle.h"
#include "BoardWall.h"
#include "ScoreWall.h"
#include "../PaddleGameState.h"

#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

ABoardBall::ABoardBall()
{
	BallAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("BallAnchor"));
	RootComponent = BallAnchor;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetSimulatePhysics(true);
	BallMesh->SetEnableGravity(false);
	BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BallMesh->SetCollisionProfileName("Custom");
	BallMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	BallMesh->SetupAttachment(RootComponent);

	BallMesh->BodyInstance.bLockXRotation = true;
	BallMesh->BodyInstance.bLockYRotation = true;

	InitialVelocity = 500.0f;
	FaceRight = true;
}

void ABoardBall::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = BallAnchor->GetRelativeLocation();

	StartMoving();
}

void ABoardBall::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	this->OnActorBeginOverlap.AddDynamic(this, &ABoardBall::OnOverlapBegin);
}

void ABoardBall::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	// GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "OVERLAP!", false);

	const APaddle* Paddle = Cast<APaddle>(OtherActor);

	if (IsValid(Paddle))
	{
		FVector BallVelocity = BallMesh->GetPhysicsLinearVelocity();
		BallVelocity = ConvertWorldToLocal(BallVelocity);

		FVector PaddleVelocity = Paddle->PaddleMesh->GetPhysicsLinearVelocity();
		PaddleVelocity = ConvertWorldToLocal(PaddleVelocity);

		FVector FinalVelocity = FVector(BallVelocity.X + PaddleVelocity.X, -BallVelocity.Y, BallVelocity.Z);
		FinalVelocity = ConvertLocalToWorld(FinalVelocity);

		BallMesh->SetPhysicsLinearVelocity(FinalVelocity);

		return;
	}

	const ABoardWall* BoardWall = Cast<ABoardWall>(OtherActor);

	if (IsValid(BoardWall))
	{
		FVector BallVelocity = BallMesh->GetPhysicsLinearVelocity();
		BallVelocity = ConvertWorldToLocal(BallVelocity);

		FVector FinalVelocity = FVector(-BallVelocity.X, BallVelocity.Y, BallVelocity.Z);
		FinalVelocity = ConvertLocalToWorld(FinalVelocity);

		BallMesh->SetPhysicsLinearVelocity(FinalVelocity);

		return;
	}

	const AScoreWall* ScoreWall = Cast<AScoreWall>(OtherActor);

	if (IsValid(ScoreWall))
	{
		APaddleGameState* GameState = GetWorld() != nullptr ? GetWorld()->GetGameState<APaddleGameState>() : nullptr;

		if (GameState != nullptr)
		{
			GameState->OnScorePoint.Broadcast(ScoreWall->PlayerIndex);
		}

		BallMesh->SetRelativeLocation(InitialLocation);

		StartMoving();
	}
}

void ABoardBall::StartMoving()
{
	FVector Velocity = FVector(0.0f, FMath::Abs(InitialVelocity), 0.0f);

	if (!FaceRight)
	{
		Velocity *= -1.0f;
	}

	BallMesh->SetPhysicsLinearVelocity(Velocity);

	FaceRight = !FaceRight;
}

FVector ABoardBall::ConvertWorldToLocal(const FVector Vector) const
{
	const FTransform WorldTransform = BallAnchor->GetComponentTransform();
	const FVector NewVector = UKismetMathLibrary::InverseTransformDirection(WorldTransform, Vector);

	return NewVector;
}

FVector ABoardBall::ConvertLocalToWorld(const FVector Vector) const
{
	const FTransform WorldTransform = BallAnchor->GetComponentTransform();
	const FVector NewVector = UKismetMathLibrary::TransformDirection(WorldTransform, Vector);

	return NewVector;
}
