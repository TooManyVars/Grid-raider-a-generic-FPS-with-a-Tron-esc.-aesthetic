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

