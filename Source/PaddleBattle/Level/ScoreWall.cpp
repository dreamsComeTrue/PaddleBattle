// Copyright AGADO Studio 2022. All rights reserved

#include "ScoreWall.h"
#include "Components/BoxComponent.h"

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
