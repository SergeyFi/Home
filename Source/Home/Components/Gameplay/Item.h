// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item.generated.h"

USTRUCT()
struct FItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName ItemName;

	UPROPERTY(EditAnywhere)
	float ItemCount;

	UPROPERTY(EditAnywhere)
	bool bIsStackable;
	
};

UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase="true") )
class HOME_API UItem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(EditAnywhere)
	FItemData ItemProperties;
};
