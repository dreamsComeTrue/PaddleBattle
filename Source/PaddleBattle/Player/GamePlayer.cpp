// Copyright AGADO Studio 2022. All rights reserverd

#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GamePlayer.h"

AGamePlayer::AGamePlayer()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    CreateCamera();
    CreateBounds();
    CreateLeftPaddle();
    CreateRightPaddle();

    PrimaryActorTick.bCanEverTick = true;
}

void AGamePlayer::CreateCamera()
{
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetRelativeLocation(FVector(-1500.0f, 0.0f, 120.0f));
    Camera->SetupAttachment(RootComponent);
}

void AGamePlayer::CreateBounds()
{
    PaddleAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("PaddleAnchor"));
    PaddleAnchor->SetupAttachment(RootComponent);

    TopBounds = CreateDefaultSubobject<USceneComponent>(TEXT("TopBounds"));
    TopBounds->SetRelativeLocation(FVector(400.0f, 0.0f, 0.0f));
    TopBounds->SetupAttachment(PaddleAnchor);

    BottomBounds = CreateDefaultSubobject<USceneComponent>(TEXT("BottomBounds"));
    BottomBounds->SetRelativeLocation(FVector(-400.0f, 0.0f, 0.0f));
    BottomBounds->SetupAttachment(PaddleAnchor);
}

void AGamePlayer::CreateLeftPaddle()
{
    LeftPaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftPaddle"));
    LeftPaddleMesh->SetRelativeLocation(FVector(0.0f, -600.0f, 0.0f));
    LeftPaddleMesh->SetupAttachment(PaddleAnchor);

    LeftPaddleMesh->SetGenerateOverlapEvents(true);
    LeftPaddleMesh->OnComponentBeginOverlap.AddDynamic(this, &AGamePlayer::OnPaddleOverlapBegin);
    LeftPaddleMesh->OnComponentEndOverlap.AddDynamic(this, &AGamePlayer::OnPaddleOverlapEnd);
}

void AGamePlayer::CreateRightPaddle()
{
    RightPaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightPaddle"));
    RightPaddleMesh->SetRelativeLocation(FVector(0.0f, 600.0f, 0.0f));
    RightPaddleMesh->SetupAttachment(PaddleAnchor);

    RightPaddleMesh->SetGenerateOverlapEvents(true);
    RightPaddleMesh->OnComponentBeginOverlap.AddDynamic(this, &AGamePlayer::OnPaddleOverlapBegin);
    RightPaddleMesh->OnComponentEndOverlap.AddDynamic(this, &AGamePlayer::OnPaddleOverlapEnd);
}

void AGamePlayer::BeginPlay()
{
    Super::BeginPlay();
}

void AGamePlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGamePlayer::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    InputComponent->BindAxis("LeftPaddleUp", this, &AGamePlayer::LeftPaddleUp);
    InputComponent->BindAxis("LeftPaddleDown", this, &AGamePlayer::LeftPaddleDown);

    InputComponent->BindAxis("RightPaddleUp", this, &AGamePlayer::RightPaddleUp);
    InputComponent->BindAxis("RightPaddleDown", this, &AGamePlayer::RightPaddleDown);
}

void AGamePlayer::OnPaddleOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor,
                                       UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                       const FHitResult &SweepResult)
{
}

void AGamePlayer::OnPaddleOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp,
                                     int32 OtherBodyIndex)
{
}

void AGamePlayer::LeftPaddleUp(float AxisValue)
{
    float Delta = MovementSpeed * AxisValue;

    MovePaddleMesh(LeftPaddleMesh, Delta);
}

void AGamePlayer::LeftPaddleDown(float AxisValue)
{
    float Delta = -MovementSpeed * AxisValue;

    MovePaddleMesh(LeftPaddleMesh, Delta);
}

void AGamePlayer::RightPaddleUp(float AxisValue)
{
    float Delta = MovementSpeed * AxisValue;

    MovePaddleMesh(RightPaddleMesh, Delta);
}

void AGamePlayer::RightPaddleDown(float AxisValue)
{
    float Delta = -MovementSpeed * AxisValue;

    MovePaddleMesh(RightPaddleMesh, Delta);
}

void AGamePlayer::MovePaddleMesh(UStaticMeshComponent *MeshComponent, float Delta)
{
    FVector Location = MeshComponent->GetRelativeLocation();
    Location.X += Delta;

    ClampPaddleLocation(Location);

    MeshComponent->SetRelativeLocation(Location);
}

void AGamePlayer::ClampPaddleLocation(FVector &CurrentLocation)
{
    if (CurrentLocation.X > TopBounds->GetRelativeLocation().X)
    {
        CurrentLocation.X = TopBounds->GetRelativeLocation().X;
    }

    if (CurrentLocation.X < BottomBounds->GetRelativeLocation().X)
    {
        CurrentLocation.X = BottomBounds->GetRelativeLocation().X;
    }
}