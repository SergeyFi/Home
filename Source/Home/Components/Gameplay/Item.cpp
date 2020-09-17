// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values for this component's properties
UItem::UItem()
{
	PrimaryComponentTick.bCanEverTick = false;

}

FItemData UItem::GetItemData()
{
	return ItemProperties;
}


// Called when the game starts
void UItem::BeginPlay()
{
	Super::BeginPlay();

}
