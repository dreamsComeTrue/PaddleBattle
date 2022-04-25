// Copyright AGADO Studio 2022. All rights reserved

#include "BoardWall.h"
#include "Components/BoxComponent.h"

ABoardWall::ABoardWall()
{
    Bounds = CreateDefaultSubobject<UBoxComponent>(TEXT("Bounds"));
    RootComponent = Bounds;

    Bounds->SetGenerateOverlapEvents(true);
}

void ABoardWall::BeginPlay()
{
    Super::BeginPlay();
}
