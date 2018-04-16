// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class RED_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Property that dictates the look and design of the gun.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * Design;

	//an arrow component dictating where the barrel is.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UArrowComponent * Barrel;

};
