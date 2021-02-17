// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class APawnTank;
class APawnEnemyTank;

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	float ReturnDistanceToPlayer() const;

	APawnTank* PlayerTank;
	APawnEnemyTank* ControlledTank;
	bool HasSeenPlayer = false;
	float AcceptanceRadius = 200.0f;

};
