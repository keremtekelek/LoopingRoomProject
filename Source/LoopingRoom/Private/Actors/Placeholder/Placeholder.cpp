#include "Actors/Placeholder/Placeholder.h"


APlaceholder::APlaceholder()
{
	PrimaryActorTick.bCanEverTick = false;

	ChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("Child Actor"));
	ChildActor->SetupAttachment(RootComponent);

	if (ChildActor != nullptr)
	{
		ChildActor->SetChildActorClass(PossibleActor->StaticClass());
	}
	if (PossibleActor != nullptr)
	{
		PlaceholderData.SetLocation(RootComponent->GetRelativeTransform().GetLocation());
		PlaceholderData.SetRotation(RootComponent->GetRelativeTransform().GetRotation());
		PlaceholderData.SetScale3D(RootComponent->GetRelativeTransform().GetScale3D());
	}

}


void APlaceholder::BeginPlay()
{
	Super::BeginPlay();
	
}


void APlaceholder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

