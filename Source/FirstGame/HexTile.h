// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

class UStaticMeshComponent;

UENUM()
enum class EHexTileType : uint8
{
	NONE,
	GROUND,
	PLATFORM,
	MAX UMETA(Hidden)	
};

UCLASS()
class FIRSTGAME_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Tile")
	FIntPoint TileIndex;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* TileStaticMesh;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	EHexTileType TileType;
	
public:	
	// Sets default values for this actor's properties
	AHexTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
