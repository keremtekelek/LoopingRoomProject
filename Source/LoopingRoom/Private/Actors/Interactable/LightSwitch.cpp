#include "Actors/Interactable/LightSwitch.h"

ALightSwitch::ALightSwitch()
{
	PrimaryActorTick.bCanEverTick = false;

	LightSwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Light Switch Mesh"));
	LightSwitchMesh->SetupAttachment(RootComponent);

	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch Mesh"));
	SwitchMesh->SetupAttachment(LightSwitchMesh);
}

void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
}

void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALightSwitch::OnInteractionTriggered()
{
	Super::OnInteractionTriggered();
	
	
}