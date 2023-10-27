// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTile.h"
#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AHexTile::AHexTile()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    TileStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
    TileStaticMesh->SetupAttachment(RootComponent);
}

