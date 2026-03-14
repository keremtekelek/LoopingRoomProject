#include "ActorComponenets/AC_InteractorComponent.h"
#include "ActorComponenets/AC_InteractableComponent.h"

//#define ENABLE_DEBUG

UAC_InteractorComponent::UAC_InteractorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}



void UAC_InteractorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}



void UAC_InteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAC_InteractorComponent::TryInteract()
{
	AActor* Owner = GetOwner();
	
	if (!Owner)
	{
		return;
	}

	
	FVector EyeLocation;
	FRotator EyeRotation;
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	
	FVector EndLocation = EyeLocation + (EyeRotation.Vector() * InteractionDistance);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Owner); 

	
	bool Hit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		EyeLocation,
		EndLocation,
		ECC_Visibility, 
		QueryParams
	);

	
	DrawDebugLine(GetWorld(), EyeLocation, EndLocation, Hit ? FColor::Green : FColor::Red, false, 2.0f, 0, 1.0f);

	if (Hit && HitResult.GetActor())
	{
		AActor* HitActor = HitResult.GetActor();

		#ifdef ENABLE_DEBUG
			UE_LOG(LogTemp, Warning, TEXT("Line Trace Hit Actor: %s"), *HitActor->GetName());
		#endif
		
		
		UAC_InteractableComponent* InteractableComponent = HitActor->GetComponentByClass<UAC_InteractableComponent>();
		
		if (InteractableComponent)
		{
			InteractableComponent->TriggerInteraction();

			#ifdef ENABLE_DEBUG
				UE_LOG(LogTemp, Warning, TEXT("Interactable Component found at Interactable Actor!"))
			#endif
		}
		else
		{
			#ifdef ENABLE_DEBUG
				UE_LOG(LogTemp, Warning, TEXT("Interactable Component DIDN'T found at Interactable Actor!"))
			#endif
		}
	}
}





