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
		
		Location = this->GetActorLocation();
		Rotation = this->GetActorRotation();
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

