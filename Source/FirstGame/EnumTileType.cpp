// Fill out your copyright notice in the Description page of Project Settings.


#include "EnumTileType.h"

EnumTileType::EnumTileType() {}

EnumTileType::EnumTileType(uint8 type) {
    SetTileType(type);
}

void EnumTileType::SetTileType(uint8 type) {
    switch (type)
    {
    case 0:
        tileType = EHexTileType::NONE;
        break;
    case 1:
        tileType = EHexTileType::GROUND;
        break;
    case 2:
        tileType = EHexTileType::PLATFORM;
        break;
    default:
        break;
    }
}

EHexTileType EnumTileType::GetTileType() {
    return EnumTileType::tileType;
}
