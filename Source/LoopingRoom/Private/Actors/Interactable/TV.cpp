#include "Actors/Interactable/TV.h"

ATV::ATV()
{
	PrimaryActorTick.bCanEverTick = false;

	TVMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TV Mesh"));
	TVMesh->SetupAttachment(RootComponent);

	TV_TableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TV Table Mesh"));
	TV_TableMesh->SetupAttachment(TVMesh);
}

void ATV::BeginPlay()
{
	Super::BeginPlay();
}

void ATV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATV::OnInteractionTriggered()
{
	Super::OnInteractionTriggered();
}