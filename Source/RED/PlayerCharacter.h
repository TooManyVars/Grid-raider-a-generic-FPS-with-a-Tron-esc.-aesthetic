// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OurHero.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RED_API APlayerCharacter : public AOurHero
{
	GENERATED_BODY()

	APlayerCharacter();

	//Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void moveForward(float value);

	UFUNCTION()
	void moveRight(float value);

	//Jump bindings.
	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void EndJump();

	//firing.
	UFUNCTION()
	void Fire();
	
	// FPS camera.
	//UPROPERTY(VisibleAnywhere)
	//class UCameraComponent* FPSCameraComponent;
};
