#include "Actors/Base/ActorBase.h"


AActorBase::AActorBase()
{
	PrimaryActorTick.bCanEverTick = true;

}


void AActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

