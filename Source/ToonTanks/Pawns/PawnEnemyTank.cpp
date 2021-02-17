// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnEnemyTank.h"
#include "PawnTank.h"
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