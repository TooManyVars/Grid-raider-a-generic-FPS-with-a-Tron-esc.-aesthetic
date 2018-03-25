// Fill out your copyright notice in the Description page of Project Settings.

#include "OurHero.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AOurHero::AOurHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//initialise our character movement component.
	CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("PawnMovement"));
	//init camera
	cameraMesh = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraMeshComponent"));
	//inti skeletal mesh.
	charMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMeshComponent"));


}

// Called when the game starts or when spawned
void AOurHero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOurHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOurHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//binds the "moveForward" function and the "move right" function to their corresponding binds.
	PlayerInputComponent->BindAxis("MoveForward", this, &AOurHero::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AOurHero::moveRight);

}

//note: the current implementation of binding our functions to our axis mappings may need reworking.

void AOurHero::moveForward(float value)
{
	//allows for forward movement.
	AddMovementInput(GetActorForwardVector(), value);
}


void AOurHero::moveRight(float value)
{
	//allows for right movement.
	AddMovementInput(GetActorRightVector(), value);
}

