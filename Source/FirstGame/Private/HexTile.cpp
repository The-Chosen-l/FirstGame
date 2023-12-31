// Fill out your copyright notice in the Description page of Project Settings.

#include "HexTile.h"
#include "EnumTileType.h"
#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AHexTile::AHexTile() {
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    tileStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
    tileStaticMesh->SetupAttachment(RootComponent);
}

AHexTile::AHexTile(uint8 type) {
    tileType.SetTileType(type);

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    tileStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
    tileStaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHexTile::BeginPlay() {
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Blue, TEXT("Hello Cpp hex"));
}
