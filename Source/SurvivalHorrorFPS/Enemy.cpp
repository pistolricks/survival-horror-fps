// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "SurvivalHorrorFPSCharacter.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	EnemyAIC = Cast<AAIController>(GetController());

	SeekPlayer();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::SeekPlayer()
{
	GetWorld()->GetTimerManager().SetTimer(SeekPlayerTH, this, &AEnemy::SeekPlayer, 0.25f, true);

	if (PlayerREF)
	{
		EnemyAIC->MoveToLocation(PlayerREF->GetActorLocation(), StoppingDistance,true);
	}
	else
	{
		PlayerREF = Cast<ASurvivalHorrorFPSCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
		SeekPlayer();
	}
}

