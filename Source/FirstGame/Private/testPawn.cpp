// Fill out your copyright notice in the Description page of Project Settings.


#include "testPawn.h"

// Sets default values
AtestPawn::AtestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AtestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AtestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

