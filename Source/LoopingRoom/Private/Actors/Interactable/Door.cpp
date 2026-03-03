#include "Actors/Interactable/Door.h"
#include "ActorComponenets/AC_InteractableComponent.h"


ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	DoorMesh->SetupAttachment(RootComponent);

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	DoorFrame->SetupAttachment(RootComponent);

	InteractableComponent = CreateDefaultSubobject<UAC_InteractableComponent>(TEXT("InteractableComponent"));

}


void ADoor::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (CurveFloat)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));
		DoorTimeline.AddInterpFloat(CurveFloat, ProgressFunction);
	}
	

	FOnTimelineEvent FinishedFunction;
	FinishedFunction.BindUFunction(this, FName("HandleFinished"));
	DoorTimeline.SetTimelineFinishedFunc(FinishedFunction);

	if (InteractableComponent)
	{
		InteractableComponent->OnInteract.AddDynamic(this, &ADoor::OnInteractionTriggered);
	}
	
}


void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorTimeline.TickTimeline(DeltaTime);
	DotProductResult = CalculateDotProduct();

}


void ADoor::OpenTheDoor()
{
	UE_LOG(LogTemp, Warning, TEXT("OpenTheDoor called"))
	
	if (!IsPlaying)
	{
		if (FlipFlopVariable)
		{
			if (DotProductResult >= 0)
			{
				DoorEndFloat = -90.f;
				DoorTimeline.PlayFromStart();
			}
			else
			{
				DoorEndFloat = 90.f;
				DoorTimeline.PlayFromStart();
			}

			if (IsValid(DoorOpenSound) && IsValid(DoorSoundAttenuation))
			{
				FVector DoorLocation = GetActorLocation();
				UGameplayStatics::PlaySoundAtLocation(this, DoorOpenSound, DoorLocation, DoorSoundVolume, 1.f, 0.f, DoorSoundAttenuation);
			}

			FlipFlopVariable = false;
		}
		else
		{

			DoorTimeline.ReverseFromEnd();
			FlipFlopVariable = true;
		}
	}
}

float ADoor::CalculateDotProduct()
{
	if (PlayerCharacter)
	{
		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		FVector DoorLocation = GetActorLocation();
		FVector Door_FV = GetActorForwardVector();
		FVector NormalizedValue = PlayerLocation - DoorLocation;

		NormalizedValue.Normalize();
		float Result = FVector::DotProduct(Door_FV, NormalizedValue);

		return Result;
	}
	else
	{
		return 0.f;
	}
}

void ADoor::HandleProgress(float Value)
{
	float Rotation = FMath::Lerp(DoorStartFloat, DoorEndFloat, Value);

	FRotator  NewRotation(0.f,Rotation, 0.f);
	
	DoorMesh->SetRelativeRotation(NewRotation);

	IsPlaying = true;
}

void ADoor::HandleFinished()
{
	IsPlaying = false;

	if (FlipFlopVariable)
	{
		if (IsValid(DoorCloseSound) && IsValid(DoorSoundAttenuation))
		{
			FVector DoorLocation = GetActorLocation();
			UGameplayStatics::PlaySoundAtLocation(this, DoorCloseSound, DoorLocation, DoorSoundVolume, 1.f, 0.f, DoorSoundAttenuation);
		}
	}
}

void ADoor::OnInteractionTriggered()
{
	OpenTheDoor();
}

