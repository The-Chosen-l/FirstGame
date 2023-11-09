// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EHexTileType : uint8
{
	NONE = 0		UMETA(DisplayName = "空"),
	GROUND = 1		UMETA(DisplayName = "地面"),
	PLATFORM = 2	UMETA(DisplayName = "高台")
};

class FIRSTGAME_API EnumTileType
{
public:
	EnumTileType();
	EnumTileType(uint8 type);

	UFUNCTION(BlueprintCallable, CallinEditor, Category = "Tile")
	void SetTileType(uint8 type);

	UFUNCTION(BlueprintCallable, CallinEditor, Category = "Tile")
	EHexTileType GetTileType();
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "Tile")
	EHexTileType tileType;
};
