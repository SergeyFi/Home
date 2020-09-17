// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Math/NumericLimits.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	LastId = TNumericLimits<int32>::Min();

}

void UInventoryComponent::AddItemFromComponent(UItem* ItemComponent)
{
	if (ItemComponent)
	{
		AddItem(ItemComponent->GetItemData());
	}
}

bool UInventoryComponent::AddItem(FItemData Item)
{
	if (Item.ItemCount == 0)
	{
		return false;
	}
	
	if (InventoryItemCount + Item.ItemCount <= InventorySize)
	{
		if (ItemsData.Contains(Item.ItemName))
		{
			auto& Items = *ItemsData.Find(Item.ItemName);

			if (Items.Num() > 0)
			{
				if (Item.bIsStackable)
				{
					Items[0].ItemData.ItemCount += Item.ItemCount;

					return true;
				}
			}

			Items.Add(FInventoryItem{Item, GetNextId()});
		}
		else
		{
			ItemsData.Add(Item.ItemName, {FInventoryItem{Item, GetNextId()}});
		}

		return true;
	}

	return false;
}

bool UInventoryComponent::RemoveItemById(FName ItemName, int32 ItemID, float Count)
{
	if (ItemsData.Contains(ItemName))
	{
		auto& Items = *ItemsData.Find(ItemName);

		int Index = 0;
		bool Find = false;
		for (;Index < Items.Num(); ++Index)
		{
			if (Items[Index].ID == ItemID)
			{
				Find = true;
				break;
			}
		}

		if (Find)
		{
			Items.RemoveAt(Index);
			return true;
		}
	}

	return false;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

int32 UInventoryComponent::GetNextId()
{
	LastId += 1;

	return  LastId;
}
