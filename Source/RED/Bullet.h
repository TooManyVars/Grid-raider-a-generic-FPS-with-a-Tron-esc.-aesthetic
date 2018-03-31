// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class RED_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//collision component for the sphere.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "projectiles")
	class USphereComponent * CollisionComponent;

	//projectile movement component for the bullet.
	UPROPERTY(VisibleAnywhere, Category = "projectiles")
	class UProjectileMovementComponent * BulletMovementComponent;

	//function responsible for launching the projectile.
	void FireInDirection(const FVector& ShootDirection);
	
	
};
