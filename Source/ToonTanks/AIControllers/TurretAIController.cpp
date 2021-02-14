// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretAIController.h"
#include "Kismet/GameplayStatics.h"
#include "../Pawns/PawnTank.h"
#include "BehaviorTree/BlackboardComponent.h"

void ATurretAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void ATurretAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TurretBehavior != nullptr && PlayerTank) 
	{
		RunBehaviorTree(TurretBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerTank->GetActorLocation());
	}
}