#include "ActorComponenets/AC_InteractableComponent.h"


UAC_InteractableComponent::UAC_InteractableComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UAC_InteractableComponent::BeginPlay()
{
	Super::BeginPlay();
}



void UAC_InteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAC_InteractableComponent::TriggerInteraction()
{
	if (OnInteract.IsBound())
	{
		OnInteract.Broadcast();
	}
}


