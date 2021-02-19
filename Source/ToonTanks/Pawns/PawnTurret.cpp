// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
