// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerTank = Cast<APawnTank> (UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void APawnTurret::CheckFireCondition()
{
	if (!PlayerTank || !PlayerTank->GetIsPlayerAlive()) 
	{
		return;
	}

	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
	
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerTank)
	{
		return 0.0f;
	}
	return FVector::Dist(PlayerTank->GetActorLocation(), GetActorLocation());
}


void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerTank || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}
	
	RotateTurret(PlayerTank->GetActorLocation());
}