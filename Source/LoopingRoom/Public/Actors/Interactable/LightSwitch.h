#pragma once

#include "CoreMinimal.h"
#include "Actors/Base/InteractableActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "LightSwitch.generated.h"


UCLASS()
class LOOPINGROOM_API ALightSwitch : public AInteractableActorBase
{
	GENERATED_BODY()

public:

	ALightSwitch();

protected:

	virtual void BeginPlay() override;
	virtual void OnInteractionTriggered() override;
	virtual void Tick(float DeltaTime) override;

	
	//VARIABLES
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* LightSwitchMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* SwitchMesh;

	//FUNCTIONS
public:

	
	
};
