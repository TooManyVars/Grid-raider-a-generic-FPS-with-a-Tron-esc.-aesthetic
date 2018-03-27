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

	//Jump bindings.
	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void EndJump();

	//player health and death related functions.

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Character")
	float Health;

	//Whether the player should be dead or not.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Player Character")
	bool IsDead = false;

	//subtracts health when the player is damaged.
	UFUNCTION(BlueprintCallable, Category = "Player Character")
	virtual void RemainingHealth(float delta);

	//function to check if the player should dead or not, and set the isDead property appropriately.
	UFUNCTION()
	virtual void CheckDead();

	//add a function that makes property changes easier in the editor.
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif


};
