// Copyright AGADO Studio 2022. All rights reserverd

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.h"
#include "GamePlayer.generated.h"

UCLASS()
class PADDLEBATTLE_API AGamePlayer : public APawn
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
    class UCameraComponent *Camera;

    UPROPERTY(VisibleDefaultsOnly, Category = "Paddle Anchor")
    class USceneComponent *PaddleAnchor;

    UPROPERTY(VisibleDefaultsOnly, Category = "Top Bounds")
    class USceneComponent *TopBounds;

    UPROPERTY(VisibleDefaultsOnly, Category = "Bottom Bounds")
    class USceneComponent *BottomBounds;

    // UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Left Paddle")
    // TSubclassOf<APaddle> LeftPaddleBP;

    UPROPERTY(EditInstanceOnly, Category = "Right Paddle")
    APaddle *LeftPaddle;

    // UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Right Paddle")
    // TSubclassOf<APaddle> RightPaddleBP;

    UPROPERTY(EditInstanceOnly, Category = "Right Paddle")
    APaddle *RightPaddle;

    UPROPERTY(EditAnywhere, Category = "Paddles Distance")
    float PaddlesDistance = 900.0f;

    UPROPERTY(EditAnywhere, Category = "Paddle Movement Speed")
    float MovementSpeed = 5.0f;

public:
    AGamePlayer();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;

private:
    void CreateCamera();
    void CreateBounds();
    void CreateLeftPaddle();
    void CreateRightPaddle();

    void LeftPaddleUp(float AxisValue);
    void LeftPaddleDown(float AxisValue);
    void RightPaddleUp(float AxisValue);
    void RightPaddleDown(float AxisValue);
};
