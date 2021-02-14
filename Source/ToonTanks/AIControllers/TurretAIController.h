// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurretAIController.generated.h"


class UBehaviorTree;
class APawnTank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATurretAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* TurretBehavior;

	APawnTank* PlayerTank;
};
