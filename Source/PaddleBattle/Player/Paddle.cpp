// Copyright AGADO Studio 2022. All rights reserved

#include "Paddle.h"

FVector POSITIVE_BOUNDS_INFINITY(BIG_NUMBER, 0.0f, 0.0f);
FVector NEGATIVE_BOUNDS_INFINITY(-BIG_NUMBER, 0.0f, 0.0f);

APaddle::APaddle()
{
	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Paddle"));
	RootComponent = PaddleMesh;

	PaddleMesh->SetGenerateOverlapEvents(true);
	PaddleMesh->OnComponentBeginOverlap.AddDynamic(this, &APaddle::OnPaddleOverlapBegin);
	PaddleMesh->OnComponentEndOverlap.AddDynamic(this, &APaddle::OnPaddleOverlapEnd);

	PrimaryActorTick.bCanEverTick = true;
}

void APaddle::BeginPlay()
{
	Super::BeginPlay();
}

void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APaddle::MovePaddleUp(float MovementSpeed, float AxisValue, FVector TopBoundsLocation)
{
	float Delta = MovementSpeed * AxisValue;

	MovePaddleMesh(Delta, TopBoundsLocation, NEGATIVE_BOUNDS_INFINITY);
}

void APaddle::MovePaddleDown(float MovementSpeed, float AxisValue, FVector BottomBoundsLocation)
{
	float Delta = -MovementSpeed * AxisValue;

	MovePaddleMesh(Delta, POSITIVE_BOUNDS_INFINITY, BottomBoundsLocation);
}

void APaddle::MovePaddleMesh(float Delta, FVector TopBoundsLocation, FVector BottomBoundsLocation)
{
	FVector Location = GetRootComponent()->GetRelativeLocation();
	Location.X += Delta;

	ClampPaddleLocation(Location, TopBoundsLocation, BottomBoundsLocation);

	SetActorRelativeLocation(Location);
}

void APaddle::ClampPaddleLocation(FVector& CurrentLocation, FVector TopBoundsLocation, FVector BottomBoundsLocation)
{
	if (CurrentLocation.X > TopBoundsLocation.X)
	{
		CurrentLocation.X = TopBoundsLocation.X;
	}

	if (CurrentLocation.X < BottomBoundsLocation.X)
	{
		CurrentLocation.X = BottomBoundsLocation.X;
	}
}

void APaddle::OnPaddleOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                   const FHitResult& SweepResult)
{
}

void APaddle::OnPaddleOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp,
                                 int32 OtherBodyIndex)
{
}
