// Copyright AGADO Studio 2022. All rights reserved
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardBall.generated.h"

UCLASS()
class PADDLEBATTLE_API ABoardBall : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category = "Ball Anchor")
	USceneComponent* BallAnchor;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ball Mesh")
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere, Category = "Ball Settings")
	FVector InitialLocation;

	UPROPERTY(EditAnywhere, Category = "Ball Settings")
	bool FaceRight;

	UPROPERTY(EditAnywhere, Category = "Ball Settings")
	float InitialVelocity;

public:
	ABoardBall();

	void StartMoving();

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

private:
	FVector ConvertWorldToLocal(FVector Vector) const;
	FVector ConvertLocalToWorld(FVector Vector) const;
};
