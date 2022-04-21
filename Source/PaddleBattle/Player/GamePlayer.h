// Copyright AGADO Studio 2022. All rights reserverd

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GamePlayer.generated.h"

UCLASS()
class PADDLEBATTLE_API AGamePlayer : public APawn
{
    GENERATED_BODY()

public:
    AGamePlayer();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};
