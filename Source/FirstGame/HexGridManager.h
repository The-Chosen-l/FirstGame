// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "EnumTileType.h"
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

	// 初始化地图的每个六边形地块
	UFUNCTION(BlueprintCallable, CallinEditor, Category = "HexGrid|Action")
	void InitGrid();

	// 根据地图TXT文件初始化每个地块的属性
	UFUNCTION(BlueprintCallable, CallinEditor, Category = "HexGrid|Action")
	void InitMap();

	// 读取地图TXT文件
	UFUNCTION(BlueprintCallable, Category = "Read File")
	static FString ReadFile(FString Dir);

	// 清空画面
	UFUNCTION(BlueprintCallable, CallinEditor, Category = "HexGrid|Action")
	void RemoveAllActors();

protected:
	// 存储六边形地块的二维数组
	TArray<TArray<AHexTile*>> map2DArray;

	// 存储地块属性的二维数组
	TArray<TArray<uint8>> tileType2DArray;

	UPROPERTY(BlueprintReadOnly, Category = "Hexgrid|Preview")
	TArray<FVector4> mapPointArray;

	// 地图宽度（X轴地块的最大数量）
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 mapWidth;

	// 地图长度（Y轴地块的最大数量）
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 mapHeight;

	// X轴地块间的偏移量
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float tileOffsetX;

	// Y轴地块间的偏移量
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float tileOffsetYX;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float tileOffsetYY;

	// 地块间间隔大小的系数（大于等于1）
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float tileGapFactor;

	// 空地块
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> noneTile;

	// 地面地块
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> groundTile;

	// 高台地块
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> platformTile;
};
