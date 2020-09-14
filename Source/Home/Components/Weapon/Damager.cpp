// Fill out your copyright notice in the Description page of Project Settings.


#include "Damager.h"
#include "Home/Components/Gameplay/HealthComponent.h"
#include "Components/ShapeComponent.h"

// Sets default values for this component's properties
UDamager::UDamager()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UDamager::BeginPlay()
{
	Super::BeginPlay();

	BindToDetector();
}

void UDamager::BindToDetector()
{
	if (Detector)
	{
		Detector->OnComponentBeginOverlap.AddDynamic(this, &UDamager::OnDetectorOverlaped);
	}
}

void UDamager::OnDetectorOverlaped(UPrimitiveComponent* OtherComp2, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		auto HealthComp = OtherActor->FindComponentByClass<UHealthComponent>();

		if (HealthComp)
		{
			HealthComp->ApplyDamage(Damage, OtherActor->GetInstigator());

			if (bDestroyOnOverlap)
			{
				DestroyComponent();
			}
		}
	}
}
