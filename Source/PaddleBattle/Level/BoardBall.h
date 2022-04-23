// Copyright AGADO Studio 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardBall.generated.h"

UCLASS()
class PADDLEBATTLE_API ABoardBall : public AActor
{
    GENERATED_BODY()

public:
    ABoardBall();

protected:
    virtual void BeginPlay() override;
};
