// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UTankMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	void Move(float Direction);
	void RotateBase(float Direction);

private:
	FVector MovementDirection;
	FQuat RotationDirection;
	float MovementSpeed = 300.0f;
	float RotationSpeed = 100.0f;
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};



