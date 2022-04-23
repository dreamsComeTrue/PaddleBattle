// Copyright AGADO Studio 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardWall.generated.h"

UCLASS()
class PADDLEBATTLE_API ABoardWall : public AActor
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bounds")
    class UBoxComponent *Bounds;

public:
    ABoardWall();

protected:
    virtual void BeginPlay() override;
};
