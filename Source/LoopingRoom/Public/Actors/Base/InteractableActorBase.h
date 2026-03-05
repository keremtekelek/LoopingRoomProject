#pragma once

#include "CoreMinimal.h"
#include "Actors/Base/ActorBase.h"
#include "InteractableActorBase.generated.h"

class UAC_InteractableComponent;

UCLASS()
class LOOPINGROOM_API AInteractableActorBase : public AActorBase
{
	GENERATED_BODY()

public:

	AInteractableActorBase();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//VARIABLES!
public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAC_InteractableComponent* InteractableComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* DefaultSceneRoot;


	//FUNCTIONS
public:
	
	UFUNCTION()
	virtual void OnInteractionTriggered();
};
