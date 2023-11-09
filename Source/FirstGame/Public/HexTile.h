// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumTileType.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"


class UStaticMeshComponent;

UCLASS()
class FIRSTGAME_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	// 地块的位置坐标
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Tile")
	FIntPoint tileIndex;
	
	// 地块对应的静态网格体
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* tileStaticMesh;

	// 地块的类型
	EnumTileType tileType;
	
public:	
	// Sets default values for this actor's properties
	AHexTile();
	AHexTile(uint8 type);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
