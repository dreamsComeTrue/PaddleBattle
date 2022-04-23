// Copyright AGADO Studio 2022

#include "Components/BoxComponent.h"
#include "BoardWall.h"

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
