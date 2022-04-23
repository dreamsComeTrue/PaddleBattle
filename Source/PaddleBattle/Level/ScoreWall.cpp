// Copyright AGADO Studio 2022

#include "Components/BoxComponent.h"
#include "ScoreWall.h"

AScoreWall::AScoreWall()
{
    Bounds = CreateDefaultSubobject<UBoxComponent>(TEXT("Bounds"));
    RootComponent = Bounds;

    Bounds->SetGenerateOverlapEvents(true);
}

void AScoreWall::BeginPlay()
{
    Super::BeginPlay();
}
