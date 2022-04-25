// Copyright AGADO Studio 2022. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardWall.generated.h"

class UBoxComponent;
UCLASS()
class PADDLEBATTLE_API ABoardWall : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bounds")
	UBoxComponent* Bounds;

public:
	ABoardWall();

protected:
	virtual void BeginPlay() override;
};
