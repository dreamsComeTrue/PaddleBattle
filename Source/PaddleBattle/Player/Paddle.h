// Copyright AGADO Studio 2022. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paddle.generated.h"

UCLASS()
class PADDLEBATTLE_API APaddle : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Paddle Mesh")
	UStaticMeshComponent* PaddleMesh;

public:
	APaddle();

	virtual void Tick(float DeltaTime) override;

	void MovePaddleUp(float MovementSpeed, float AxisValue, FVector TopBoundsLocation);
	void MovePaddleDown(float MovementSpeed, float AxisValue, FVector BottomBoundsLocation);

protected:
	virtual void BeginPlay() override;

private:
	void MovePaddleMesh(float Delta, FVector TopBoundsLocation, FVector BottomBoundsLocation);
	void ClampPaddleLocation(FVector& CurrentLocation, FVector TopBoundsLocation, FVector BottomBoundsLocation);

	UFUNCTION()
	void OnPaddleOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                          int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPaddleOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                        int32 OtherBodyIndex);
};
