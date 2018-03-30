// Fill out your copyright notice in the Description page of Project Settings.

#include "OurHero.h"

// Sets default values
AOurHero::AOurHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
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

}

//note: the current implementation of binding our functions to our axis mappings may need reworking.
void AOurHero::RemainingHealth(float delta)
{
	Health += delta;
}

void AOurHero::CheckDead()
{
	if (Health <= 0)
	{
		IsDead = true;
	}
	else
	{
		IsDead = false;
	}
}

void AOurHero::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	IsDead = false;
	Health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);
	CheckDead();
}