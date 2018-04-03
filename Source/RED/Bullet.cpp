// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Engine.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere collision component"));
	CollisionComponent->InitSphereRadius(15.0f);
	//attach the collision component to the root component.
	RootComponent = CollisionComponent;

	// Use this component to drive this bullet's movement.
	BulletMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BulletMovementComponent"));
	BulletMovementComponent->SetUpdatedComponent(CollisionComponent);
	BulletMovementComponent->InitialSpeed = 3000.0f;
	BulletMovementComponent->MaxSpeed = 3000.0f;
	BulletMovementComponent->bRotationFollowsVelocity = true;
	BulletMovementComponent->bShouldBounce = true;
	BulletMovementComponent->Bounciness = 0.3f;
	
	//set how long the actor lives before dying.
	InitialLifeSpan = 1.5f;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//dictates the direction the projectile will be shot in.
void ABullet::FireInDirection(const FVector& ShootDirection)
{
	BulletMovementComponent->Velocity = ShootDirection * BulletMovementComponent->InitialSpeed;
}