// Copyright AGADO Studio 2022. All rights reserverd

#include "Player/GamePlayer.h"
#include "PaddleBattleGameModeBase.h"

APaddleBattleGameModeBase::APaddleBattleGameModeBase(const FObjectInitializer &ObjectInitializer)
{
    static ConstructorHelpers::FClassFinder<AGamePlayer> PlayerPawnBPClass(TEXT("/Game/Blueprints/GamePlay/BP_GamePlayer"));

    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}