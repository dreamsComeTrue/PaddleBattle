// Copyright AGADO Studio 2022. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PaddleGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScorePoint, int, PlayerIndex);

UCLASS()
class PADDLEBATTLE_API APaddleGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Game Delegates")
	FOnScorePoint OnScorePoint;
};
