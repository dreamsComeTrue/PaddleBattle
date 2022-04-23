// Copyright AGADO Studio 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreWall.generated.h"

UCLASS()
class PADDLEBATTLE_API AScoreWall : public AActor
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bounds")
    class UBoxComponent *Bounds;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Score Player Index")
    int PlayerIndex;

public:
    AScoreWall();

protected:
    virtual void BeginPlay() override;
};
