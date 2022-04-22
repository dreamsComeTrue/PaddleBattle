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
    UPROPERTY(VisibleDefaultsOnly, Category = "Camera")
    class UCameraComponent *Camera;

    UPROPERTY(VisibleDefaultsOnly, Category = "Paddle Anchor")
    class USceneComponent *PaddleAnchor;

    UPROPERTY(VisibleDefaultsOnly, Category = "Top Bounds")
    class USceneComponent *TopBounds;

    UPROPERTY(VisibleDefaultsOnly, Category = "Bottom Bounds")
    class USceneComponent *BottomBounds;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Left Paddle Mesh")
    class UStaticMeshComponent *LeftPaddleMesh;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Right Paddle Mesh")
    class UStaticMeshComponent *RightPaddleMesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Paddle Movement Speed")
    float MovementSpeed = 5.0f;

public:
    AGamePlayer();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnPaddleOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnPaddleOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

private:
    void CreateCamera();
    void CreateBounds();
    void CreateLeftPaddle();
    void CreateRightPaddle();

    void LeftPaddleUp(float AxisValue);
    void LeftPaddleDown(float AxisValue);
    void RightPaddleUp(float AxisValue);
    void RightPaddleDown(float AxisValue);

    void MovePaddleMesh(UStaticMeshComponent *MeshComponent, float Delta);
    void ClampPaddleLocation(FVector &CurrentLocation);
};
