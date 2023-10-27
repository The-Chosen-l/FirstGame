// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGridManager.h"
#include "HexTile.h"

// Sets default values
AHexGridManager::AHexGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(2, 5, FColor::Cyan, TEXT("GridManager"));
	InitGrid();
}

void AHexGridManager::InitGrid() {
	RemoveAllActors();

	MapPointArray.Reset();

	Map2DArray.SetNumZeroed(MapWidth);
	for (int i = 0;i < Map2DArray.Num();i++) {
		Map2DArray[i].SetNumZeroed(MapHeight);
	}

	TSubclassOf<AHexTile> TileToSpawn = GroundTile;
	for (int y = 0;y < MapHeight;y++) {
		for (int x = 0;x < MapWidth;x++) {
			float xPos = x * TileOffsetX - y * TileOffsetYX;
			float yPos = y * TileOffsetYY;

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(TileToSpawn,  FVector(FIntPoint(xPos,yPos)) + GetActorLocation(), FRotator::ZeroRotator);
			newTile->TileIndex = FIntPoint(x, y);
			newTile->SetActorLabel(FString::Printf(TEXT("Tile_%d_%d"), x, y));
			newTile->AttachToActor(this,FAttachmentTransformRules::KeepWorldTransform,"");
 
			Map2DArray[x][y] = newTile;
		}
	}
}

void AHexGridManager::InitMap() {
	
}

void AHexGridManager::RemoveAllActors() {
	TArray<AActor*> children;
	GetAttachedActors(children);
	for (int i = 0; i < children.Num(); i++) {
		AActor* actor = children[i];
		if (actor != nullptr) {
			actor->Destroy();
		}
	}
}

