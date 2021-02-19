// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"


class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;
class UAimingComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

	virtual void HandleDestruction();

	UFUNCTION(BlueprintPure)
	float GetRemainingHealth() const;

	UAimingComponent* GetAimingComponent() const;
	USceneComponent* GetProjectileSpawnPoint() const;
	UStaticMeshComponent* GetTurretMesh() const;
	float GetCombatRange() const;

private:
	//COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly ,Category = "Components", meta = (AllowPrivateAccess = true))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UHealthComponent* HealthComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UAimingComponent* AimingComponent;

	float CombatRange = 800.0f;

protected:
	//EFFECTS
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UCameraShake> DeathShake;

};