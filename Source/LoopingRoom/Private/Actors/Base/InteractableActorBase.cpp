#include "Actors/Base/InteractableActorBase.h"
#include "ActorComponenets/AC_InteractableComponent.h"

AInteractableActorBase::AInteractableActorBase()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	InteractableComponent = CreateDefaultSubobject<UAC_InteractableComponent>(TEXT("InteractableComponent"));

	if (InteractableComponent)
	{
		InteractableComponent->OnInteract.AddDynamic(this, &AInteractableActorBase::OnInteractionTriggered);
	}
}

void AInteractableActorBase::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableActorBase::OnInteractionTriggered()
{
	
}
