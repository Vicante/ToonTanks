// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnTurret.h"
#include "PawnEnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnEnemyTank : public APawnTurret
{
	GENERATED_BODY()

public:
	
	FVector MovementDirection;
	FQuat RotationDirection;

	float GetCombatRange();
	void RotateBase();
	void Move();

private:

	APawnEnemyTank();

	void CalculateRotation();
	//MOVEMENT RELATED VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float MovementSpeed = 150.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float RotationSpeed = 75.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float RotationThreshold = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = true))
	float CombatRange = 800.0f;
	bool HasSeenPlayer = false;
};
