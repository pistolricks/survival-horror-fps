// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class SURVIVALHORRORFPS_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class ASurvivalHorrorFPSCharacter* PlayerREF;
	class AAIController* EnemyAIC;

	UPROPERTY(editAnywhere)
	float StoppingDistance = 100.0f;
	FTimerHandle SeekPlayerTH;

	UFUNCTION()
	void SeekPlayer();
};
