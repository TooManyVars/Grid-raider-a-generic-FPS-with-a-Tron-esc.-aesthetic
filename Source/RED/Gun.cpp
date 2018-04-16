// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Bullet.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Design = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	Barrel = CreateDefaultSubobject<UArrowComponent>(TEXT("Barrel"));
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::fireWeapon()
{
	// Attempt to fire a projectile.
	if (BulletType)
	{
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		// Transform MuzzleOffset from camera space to world space.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(GunMuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		// Skew the aim to be slightly upwards.
		//MuzzleRotation.Pitch += 10.0f;
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			// Spawn the projectile at the muzzle.
			ABullet * Projectile = World->SpawnActor<ABullet>(BulletType, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// Set the projectile's initial trajectory.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}

