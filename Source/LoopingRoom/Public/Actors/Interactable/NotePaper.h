#pragma once

#include "CoreMinimal.h"
#include "Actors/Base/InteractableActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "NotePaper.generated.h"


UCLASS()
class LOOPINGROOM_API ANotePaper : public AInteractableActorBase
{
	GENERATED_BODY()

public:

	ANotePaper();
protected:

	virtual void BeginPlay() override;
	virtual void OnInteractionTriggered() override;
	virtual void Tick(float DeltaTime) override;

	
	//VARIABLES
public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* NotePaperMesh;

	//FUNCTIONS
public:

	
};
