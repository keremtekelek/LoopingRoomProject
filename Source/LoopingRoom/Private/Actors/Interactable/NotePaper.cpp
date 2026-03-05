#include "Actors/Interactable/NotePaper.h"

ANotePaper::ANotePaper()
{
	PrimaryActorTick.bCanEverTick = false;

	NotePaperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Note Paper Mesh"));
	NotePaperMesh->SetupAttachment(RootComponent);
}

void ANotePaper::BeginPlay()
{
	Super::BeginPlay();
}

void ANotePaper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANotePaper::OnInteractionTriggered()
{
	Super::OnInteractionTriggered();
}
