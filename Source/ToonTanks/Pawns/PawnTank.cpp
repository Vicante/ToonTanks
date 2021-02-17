// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include "../Components/TankMovementComponent.h"


APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(TEXT("Movement Component"));
}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();
	PlayerReference = Cast<APlayerController>(GetController());

	FVector TankLocation = GetActorLocation();

	//TODO: Fix weird bug
	SetActorLocation(FVector(TankLocation.X, TankLocation.Y, 88.0f));
}

void APawnTank::HandleDestruction()
{
	Super::HandleDestruction();

	bIsPlayerAlive = false;

	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}

bool APawnTank::GetIsPlayerAlive()
{
	return bIsPlayerAlive;
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Rotate();
	//Move();

	if (PlayerReference)
	{
		FHitResult TraceHitResult;
		PlayerReference->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
		FVector HitLocation = TraceHitResult.ImpactPoint;
		RotateTurret(HitLocation);
	}
}

// Called to bind functionality to input
//void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
//	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotationInput);
//	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
//}
