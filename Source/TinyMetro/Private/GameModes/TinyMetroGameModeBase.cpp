// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/TinyMetroGameModeBase.h"

FString ATinyMetroGameModeBase::GetFileName() const {
    return TEXT("Base");
}

TMap<FIntPoint, StationType> ATinyMetroGameModeBase::GetInitData() const {
    TMap<FIntPoint, StationType> Tmp;
    Tmp.Add(FIntPoint(0, 0), StationType::Circle);
    return Tmp;
}
