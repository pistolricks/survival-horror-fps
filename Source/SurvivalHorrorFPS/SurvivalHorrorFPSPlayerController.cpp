// Copyright Epic Games, Inc. All Rights Reserved.


#include "SurvivalHorrorFPSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "SurvivalHorrorFPSCameraManager.h"

ASurvivalHorrorFPSPlayerController::ASurvivalHorrorFPSPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ASurvivalHorrorFPSCameraManager::StaticClass();
}

void ASurvivalHorrorFPSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
