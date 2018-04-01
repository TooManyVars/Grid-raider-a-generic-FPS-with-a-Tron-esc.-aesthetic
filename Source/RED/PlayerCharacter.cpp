// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

APlayerCharacter::APlayerCharacter()
{
	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// Attach the camera component to our capsule component.
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//binds the "moveForward" function and the "move right" function to their corresponding binds.
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::moveRight);
	//camera inputs.
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	//jump inputs.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::EndJump);
	//fire inputs.
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::Fire);

}

void APlayerCharacter::moveForward(float value)
{
	//allows for forward movement.
	//AddMovementInput(GetActorForwardVector(), value); //i'm changing this code in order to get movement more comfortable for the player.

	if ((Controller != NULL) && (value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}


void APlayerCharacter::moveRight(float value)
{
	//allows for right movement.
	//AddMovementInput(GetActorRightVector(), value);//i'm changing this code in order to get movement more comfortable for the player.

	if ((Controller != NULL) && (value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, value);
	}

}

void APlayerCharacter::StartJump()
{
	//enables jumping.
	bPressedJump = true;
}

void APlayerCharacter::EndJump()
{
	bPressedJump = false;
}

void APlayerCharacter::Fire()
{

}