// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnTurret.h"
#include "PawnEnemyTank.generated.h"

class UTankMovementComponent;
/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnEnemyTank : public APawnTurret
{
	GENERATED_BODY()

public:
	float GetCombatRange();

private:

	APawnEnemyTank();

	//COMBAT RELATED VARIABLES
	float CombatRange = 800.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UTankMovementComponent* MovementComponent;
};
