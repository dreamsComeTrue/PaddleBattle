// Copyright AGADO Studio 2022. All rights reserverd

#include "GamePlayer.h"

AGamePlayer::AGamePlayer()
{
    PrimaryActorTick.bCanEverTick = true;
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
}
