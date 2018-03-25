// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OurHero.generated.h"

UCLASS()
class RED_API AOurHero : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOurHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void moveForward(float value);
	
	UFUNCTION()
	void moveRight(float value);

	//a skeletal mesh for our character(make a camera component first).
	UPROPERTY(EditAnywhere, Category = "Character mesh")
	class USkeletalMeshComponent * charMesh;

	//camera mesh component.
	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent * cameraMesh;

};
