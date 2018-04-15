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

public:

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
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void Fire();
	
	// FPS camera.
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FPSCameraComponent;


	// Gun muzzle's offset(distance) from the camera location.
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Gameplay")
	FVector MuzzleOffset;

	//The projectile to spawn when the shoot function is called.
	//notice how the projectile class is of a type which is a derived instance of our bullet class.
	UPROPERTY(EditDefaultsOnly, Category = "projectile")
	TSubclassOf<class ABullet> ProjectileClass;
};
