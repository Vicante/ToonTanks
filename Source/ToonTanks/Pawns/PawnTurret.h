// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;

	float GetFireRange();
	FTimerHandle GetFireRateTimerHandle();

protected:

	virtual void BeginPlay() override;
	APawnTank* PlayerTank;

	float ReturnDistanceToPlayer();

private:

	void CheckFireCondition();
	
	FTimerHandle FireRateTimerHandle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = true))
	float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = true))
	float FireRange = 500.0f;
};
