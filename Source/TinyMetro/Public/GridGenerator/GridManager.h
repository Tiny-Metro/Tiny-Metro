// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCellData.h"
#include "GridManager.generated.h"

UCLASS()
class TINYMETRO_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetGridCellSize() const;
	UFUNCTION(BlueprintCallable)
	void SetGridCellData(TArray<FGridCellData>& data);
	UFUNCTION(BlueprintCallable)
	void SetGridSize(FIntPoint& Size);
	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FGridCellData> GetGridCellData() const;
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FGridCellData GetGridCellDataByPoint(int X, int Y) const;
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FGridCellData GetGridCellDataByIndex(int Index) const;
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FGridCellData GetGridCellDataRandom();
	UFUNCTION(BlueprintCallable)
	void SetGridStructure(int X, int Y, GridStructure Structure);

private:
	TPair<FVector2D, double> FindCircleWith2Points(FVector2D P1, FVector2D P2, int Index, int Index2);
	TPair<FVector2D, double> FindCircleWithPoints(FVector2D P1, int Index);
	TPair<FVector2D, double> FindCircle();
	FVector2D FindCenter(FVector2D A, FVector2D B);
	FVector2D FindCenter(FVector2D A, FVector2D B, FVector2D C);
	double GetDistance(FVector2D A, FVector2D B);
	bool IsValidStationSpawn(int Coord);
	bool IsValidStationSpawn(int X, int Y);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	float GridCellSize = 400;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int32 StationSpawnExtend = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	int32 StationSpawnPrevent = 3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	FIntPoint GridSize;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
	TArray<FGridCellData> GridCellData;

protected:
	TArray<TPair<FIntPoint, GridStructure>> GridStructures;
	TArray<FIntPoint> StationLocation;
};
