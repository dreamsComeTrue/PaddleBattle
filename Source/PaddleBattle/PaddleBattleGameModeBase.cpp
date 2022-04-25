// Copyright AGADO Studio 2022. All rights reserved

#include "Player/GamePlayer.h"
#include "PaddleBattleGameModeBase.h"

#include "PaddleGameState.h"

APaddleBattleGameModeBase::APaddleBattleGameModeBase(const FObjectInitializer &ObjectInitializer)
{
    static ConstructorHelpers::FClassFinder<AGamePlayer> PlayerPawnBPClass(TEXT("/Game/Blueprints/GamePlay/Player/BP_GamePlayer"));
    static ConstructorHelpers::FClassFinder<APaddleGameState> GameStateBPClass(TEXT("/Game/Blueprints/GamePlay/BP_PaddleGameState"));

    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    if (GameStateBPClass.Class != nullptr)
    {
        GameStateClass = GameStateBPClass.Class;
    }
}
