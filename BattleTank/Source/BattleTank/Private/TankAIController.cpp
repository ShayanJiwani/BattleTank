// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not posessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController posessing: %s"), *(ControlledTank->GetName()))
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"))

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not found"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player %s found"), *(PlayerTank->GetName()))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// AI finds the player Tank
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}