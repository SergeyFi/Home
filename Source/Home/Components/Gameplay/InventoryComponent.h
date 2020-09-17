// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Home/Components/Gameplay/Item.h"
#include "Containers/Map.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	FItemData ItemData;
	int32 ID;
};

inline bool operator == (const FInventoryItem& A, const FInventoryItem& B)
{
	return A.ItemData.ItemName == B.ItemData.ItemName && A.ID == B.ID;
}

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UFUNCTION(BlueprintCallable)
	void AddItemFromComponent(UItem* ItemComponent);

	UFUNCTION(BlueprintCallable)
	bool AddItem(FItemData Item);

	UFUNCTION(BlueprintCallable)
	bool RemoveItemById(FName ItemName, int32 ItemID, float Count = 0);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:

	TMap<FName, TArray<FInventoryItem>> ItemsData;

	UPROPERTY(EditAnywhere)
	int InventorySize;

	UPROPERTY(EditAnywhere)
	int InventoryItemCount;

	int32 LastId;

	int32 GetNextId();
	

};
