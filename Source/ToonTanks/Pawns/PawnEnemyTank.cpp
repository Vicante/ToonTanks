// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnEnemyTank.h"
#include "PawnTank.h"
#include "Kismet/KismetMathLibrary.h"
#include "../Components/TankMovementComponent.h"


APawnEnemyTank::APawnEnemyTank()
{
	PrimaryActorTick.bCanEverTick = false;
	MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(TEXT("Movement Component"));
}

float APawnEnemyTank::GetCombatRange()
{
	return CombatRange;
}

//DEPRECATED
void APawnEnemyTank::RotateBase()
{	
	CalculateRotation();
	AddActorLocalRotation(RotationDirection, true);
}

//DEPRECATED
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
	//UE_LOG(LogTemp, Warning, TEXT("DIRECTION CLASSIC: %f"), RotateAmount);
	FRotator Rotation = FRotator(0.0f, RotateAmount, 0.0f);
	RotationDirection = FQuat(Rotation);
}

//DEPRECATED
void APawnEnemyTank::Move()
{	
	MovementDirection = FVector(MovementSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
	AddActorLocalOffset(MovementDirection, true);
}
