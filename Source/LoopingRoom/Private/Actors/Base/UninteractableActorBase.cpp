#include "Actors/Base/UninteractableActorBase.h"

AUninteractableActorBase::AUninteractableActorBase()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object Mesh"));
	ObjectMesh->SetupAttachment(RootComponent);
}

void AUninteractableActorBase::BeginPlay()
{
	Super::BeginPlay();
}

void AUninteractableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

