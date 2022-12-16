// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LoanData.h"
#include "Loan.generated.h"

/**
 * 
 */
UCLASS()
class TINYMETRO_API ULoan : public UObject
{
	GENERATED_BODY()

public:
	void Test();
	void Repay();
	void CalculateInterest();
	void SetLoanData(FLoanData Data);
	void SetDaytime();

public:
	UFUNCTION(BlueprintCallable)
	FLoanData GetLoanData() const;

protected:

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Data")
	FLoanData LoanData;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data")
	int32 Daytime;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data")
	bool IsActivate;
	FTimerHandle TestHandle;
};
