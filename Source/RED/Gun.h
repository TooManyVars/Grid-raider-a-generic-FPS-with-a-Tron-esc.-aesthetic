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

	// Gun muzzle's offset(distance) from the camera location(now in the gun class).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunMuzzleOffset;

	//The projectile to spawn when the shoot function is called.
	//notice how the projectile class is of a type which is a derived instance of our bullet class.
	UPROPERTY(EditDefaultsOnly, Category = "projectile")
	TSubclassOf<class ABullet> BulletType;

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void fireWeapon();
};
