// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"


void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI()); //Simply setup the controller so that it can take input from the player.
}

