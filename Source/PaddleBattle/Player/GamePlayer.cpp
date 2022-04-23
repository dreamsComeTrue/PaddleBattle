// Copyright AGADO Studio 2022. All rights reserverd

#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GamePlayer.h"

AGamePlayer::AGamePlayer()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    CreateCamera();
    CreateBounds();

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
    FVector Location = PaddleAnchor->GetRelativeLocation() + FVector(0.0f, -PaddlesDistance, 0.0f);
    // FRotator Rotation = GetActorRotation();

    // FActorSpawnParameters SpawnInfo;
    // SpawnInfo.Name = "LeftPaddle";
    // SpawnInfo.Owner = this;

    //    LeftPaddle = GetWorld()->SpawnActor<APaddle>(LeftPaddleBP, Location, Rotation, SpawnInfo);
    if (IsValid(LeftPaddle))
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "OK", false);
        LeftPaddle->AttachToComponent(PaddleAnchor, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
        LeftPaddle->SetActorLocation(Location);
    }
}

void AGamePlayer::CreateRightPaddle()
{
    FVector Location = PaddleAnchor->GetRelativeLocation() + FVector(0.0f, PaddlesDistance, 0.0f);
    // FRotator Rotation = GetActorRotation();

    // FActorSpawnParameters SpawnInfo;
    // SpawnInfo.Name = "RightPaddle";
    // SpawnInfo.Owner = this;

    // RightPaddle = GetWorld()->SpawnActor<APaddle>(RightPaddleBP, Location, Rotation, SpawnInfo);
    if (IsValid(RightPaddle))
    {
        RightPaddle->AttachToComponent(PaddleAnchor, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
        RightPaddle->SetActorLocation(Location);
    }
}

void AGamePlayer::BeginPlay()
{
    Super::BeginPlay();

    CreateLeftPaddle();
    CreateRightPaddle();
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

void AGamePlayer::LeftPaddleUp(float AxisValue)
{
    LeftPaddle->MovePaddleUp(MovementSpeed, AxisValue, TopBounds->GetRelativeLocation());
}

void AGamePlayer::LeftPaddleDown(float AxisValue)
{
    LeftPaddle->MovePaddleDown(MovementSpeed, AxisValue, BottomBounds->GetRelativeLocation());
}

void AGamePlayer::RightPaddleUp(float AxisValue)
{
    RightPaddle->MovePaddleUp(MovementSpeed, AxisValue, TopBounds->GetRelativeLocation());
}

void AGamePlayer::RightPaddleDown(float AxisValue)
{
    RightPaddle->MovePaddleDown(MovementSpeed, AxisValue, BottomBounds->GetRelativeLocation());
}