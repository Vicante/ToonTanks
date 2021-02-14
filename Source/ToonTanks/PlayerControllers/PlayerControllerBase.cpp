// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "Blueprint/UserWidget.h"


void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	UUserWidget* HealWidget = CreateWidget(this, HealthScreenClass);
	if (HealWidget != nullptr)
	{
		HealWidget->AddToViewport();
	}
}

void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}

	bShowMouseCursor = SetPlayerEnabled;
}