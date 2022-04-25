// Copyright AGADO Studio 2022. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreWall.generated.h"

class UBoxComponent;

UCLASS()
class PADDLEBATTLE_API AScoreWall : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bounds")
	UBoxComponent* Bounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Score Player Index")
	int PlayerIndex;

public:
	AScoreWall();

protected:
	virtual void BeginPlay() override;
};
