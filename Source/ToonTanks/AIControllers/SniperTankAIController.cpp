// Fill out your copyright notice in the Description page of Project Settings.


#include "SniperTankAIController.h"
#include "../Pawns/PawnTank.h"
#include "../Pawns/PawnEnemyTank.h"

void ASniperTankAIController::Tick(float DeltaTime)
{
	//If the player is either dead, do nothing
	//if (!PlayerTank)
	//{
	//	return;
	//}
	////Check if the player was seen
	//if (ReturnDistanceToPlayer() <= ControlledTank->GetCombatRange())
	//{
	//	HasSeenPlayer = true;
	//}

	////Chase Player until near enough
	//	//Pause
	//	//Shoot
	////If player gets near
	//	//Retreat

	////Chase player
	//if (HasSeenPlayer)
	//{
	//	MoveToActor(PlayerTank, AcceptanceRadius);
	//}
}