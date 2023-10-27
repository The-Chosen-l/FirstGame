// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"

class AHexTile;

UCLASS()
class FIRSTGAME_API AHexGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, CallinEditor, Category = "HexGrid|Action")
	void InitGrid();

	UFUNCTION(BlueprintCallable, CallinEditor, Category = "HexGrid|Action")
	void InitMap();

	UFUNCTION(BlueprintCallable, CallinEditor, Category = "HexGrid|Action")
	void RemoveAllActors();

protected:
	TArray<TArray<AHexTile*>> Map2DArray;

	//TArray<TArray<EHexTileType>> TileType2DArray;

	UPROPERTY(BlueprintReadOnly, Category = "Hexgrid|Preview")
	TArray<FVector4> MapPointArray;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 MapWidth;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 MapHeight;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileOffsetX;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileOffsetYX;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileOffsetYY;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> GroundTile;
};
