// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnEnemyTank.h"
#include "PawnTank.h"
#include "Kismet/KismetMathLibrary.h"


APawnEnemyTank::APawnEnemyTank()
{
	PrimaryActorTick.bCanEverTick = false;
}

float APawnEnemyTank::GetCombatRange()
{
	return CombatRange;
}

void APawnEnemyTank::RotateBase()
{	
	CalculateRotation();
	AddActorLocalRotation(RotationDirection, true);
}

void APawnEnemyTank::CalculateRotation()
{
	//Direction where the player is at the moment
	FRotator DesiredRotation = CalculateComponentRotation(PlayerTank->GetActorLocation(), GetBaseMesh()->GetComponentLocation());

	//Calculate difference between rotation of base and the direction where the player is
	float DeltaRotation = UKismetMathLibrary::NormalizedDeltaRotator(GetBaseMesh()->GetComponentRotation(), DesiredRotation).Yaw;

	float RotationOrientation = 1.0f;
	if (DeltaRotation > RotationThreshold)
	{
		RotationOrientation = -1.0f;
	}
	else if (DeltaRotation < RotationThreshold)
	{
		RotationOrientation = 1.0f;
	}
	else
	{
		return;
	}
	float RotateAmount = RotationOrientation * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0.0f, RotateAmount, 0.0f);
	RotationDirection = FQuat(Rotation);
}

void APawnEnemyTank::Move()
{	
	MovementDirection = FVector(MovementSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
	AddActorLocalOffset(MovementDirection, true);
}