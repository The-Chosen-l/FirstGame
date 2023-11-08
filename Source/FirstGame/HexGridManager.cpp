// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGridManager.h"
#include "HexTile.h"
#include <iostream>
#include <sstream>
#include <string>

// Sets default values
AHexGridManager::AHexGridManager() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay() {
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(2, 5, FColor::Cyan, TEXT("GridManager"));
	InitMap();		// 根据地图TXT初始化地块属性
	InitGrid();		// 初始化地图地块
}

void AHexGridManager::InitGrid() {
	RemoveAllActors();

	mapPointArray.Reset();

	// 根据地图的长宽初始化存储地图的数组
	map2DArray.SetNumZeroed(mapWidth);
	for (int i = 0;i < map2DArray.Num();i++) {
		map2DArray[i].SetNumZeroed(mapHeight);
	}

	TSubclassOf<AHexTile> tileToSpawn = noneTile;
	for (int y = 0;y < mapHeight;y++) {
		for (int x = 0;x < mapWidth;x++) {
			// 计算每个地块的位置
			float xPos = x * tileOffsetX * tileGapFactor - y * tileOffsetYX * tileGapFactor;
			float yPos = y * tileOffsetYY * tileGapFactor;

			// 确定每个地块的类型
			switch (tileType2DArray[y][x])
			{
			case 0:
				tileToSpawn = noneTile;
				break;
			case 1:
				tileToSpawn = groundTile;
				break;
			case 2:
				tileToSpawn = platformTile;
				break;
			default:
				break;
			}
			
			// 创建地图
			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn,  FVector(FIntPoint(xPos,yPos)) + GetActorLocation(), FRotator::ZeroRotator);
			newTile->tileIndex = FIntPoint(x, y);
			newTile->tileType.SetTileType(tileType2DArray[y][x]);
			newTile->SetActorLabel(FString::Printf(TEXT("Tile_%d-%d"), y, x));	// 测试用
			newTile->AttachToActor(this,FAttachmentTransformRules::KeepWorldTransform,"");
 
			map2DArray[x][y] = newTile;
		}
	}
}

void AHexGridManager::InitMap() {	
	// 获取项目文件路径
	FString projectDir = FPaths::GameSourceDir();
	// 得到地图TXT文件的具体路径
	FString mapDir = projectDir + "FirstGame/MapContents/MapContent.txt";
	FString mapContent = ReadFile(*mapDir);
	std::string mapContentStr(TCHAR_TO_UTF8(*mapContent));

	// 得到地图的具体大小
	int32 width, height;
	std::istringstream iss(mapContentStr);
	std::string line;
	std::getline(iss, line);
	std::istringstream iss_line(line);
	iss_line >> width >> height;

	if (width != mapWidth || height != mapHeight) {
		//地图文件的长宽和本身设置的长宽不一致，发生严重错误。
		UE_LOG(LogTemp, Error, TEXT("SEVERITY ERROR: The length and width of the map file do not match the length and width set by itself."));
		return;
	}

	// 初始化属性数组
	tileType2DArray.SetNumZeroed(height);
	for (auto& str : tileType2DArray) {
		str.SetNumZeroed(width);
	}

	int32 isEqualHeight = 0;
	int32 isEqualWidth = 0;
	// 读取文件中的数据
	while (std::getline(iss, line)) {
		std::istringstream iss_l(line);
		isEqualWidth = 0;
		std::string tempTileType;
		while (iss_l >> tempTileType) {
			tileType2DArray[isEqualHeight][isEqualWidth] = std::stoul(tempTileType);	// string转为unsigned long
			isEqualWidth++;
			if (isEqualWidth > width) {
				//地图文件本身存在不一致。
				UE_LOG(LogTemp, Error, TEXT("SEVERITY ERROR: There is a contradiction in the data in the map file."));
				return;
			}
		}
		
		isEqualHeight++;
		if (isEqualHeight > height) {
			//地图文件本身存在不一致。
			UE_LOG(LogTemp, Error, TEXT("SEVERITY ERROR: There is a contradiction in the data in the map file."));
			return;
		}
	}
}

FString AHexGridManager::ReadFile(FString dir) {
	FString result;
	if (!IFileManager::Get().FileExists(*dir)) 			// 判断是否存在文件
	{
		FPaths::MakeValidFileName(dir); 				// 创建文件
		FFileHelper::SaveStringToFile(TEXT("1"), *dir); // 写入内容
	}

	FFileHelper::LoadFileToString(result, *dir);
	return result;
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

