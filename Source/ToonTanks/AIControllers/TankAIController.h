// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class APawnPlayerTank;
class APawnBase;

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

	void CheckFireCondition();

	APawnPlayerTank* PlayerTank;
	APawnBase* ControlledTank;
	bool HasSeenPlayer = false;
	bool HasMovementComponent = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Acceptance Radius", meta = (AllowPrivateAccess = true))
	float AcceptanceRadius = 200.0f;
	FTimerHandle FireRateTimerHandle;

};
