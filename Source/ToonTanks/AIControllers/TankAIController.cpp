// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "../Pawns/PawnTank.h"
#include "../Pawns/PawnEnemyTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = Cast<APawnTank> (GetWorld()->GetFirstPlayerController()->GetPawn());
	ControlledTank = Cast<APawnEnemyTank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	//If the player is either dead, do nothing
	if (!PlayerTank)
	{
		return;
	}
	//Check if the player was seen
	if (ReturnDistanceToPlayer() <= ControlledTank->GetCombatRange())
	{
		HasSeenPlayer = true;
	}

	//Chase player
	if (HasSeenPlayer)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
	}
}

float ATankAIController::ReturnDistanceToPlayer() const
{
	if (!PlayerTank)
	{
		return 0.0f;
	}
	return FVector::Dist(PlayerTank->GetActorLocation(), ControlledTank->GetActorLocation());
}

