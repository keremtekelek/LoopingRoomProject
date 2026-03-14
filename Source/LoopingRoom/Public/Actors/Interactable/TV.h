#pragma once

#include "CoreMinimal.h"
#include "Actors/Base/InteractableActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "TV.generated.h"


UCLASS()
class LOOPINGROOM_API ATV : public AInteractableActorBase
{
	GENERATED_BODY()

public:
	ATV();
protected:

	virtual void BeginPlay() override;
	virtual void OnInteractionTriggered() override;
	virtual void Tick(float DeltaTime) override;

	
	//VARIABLES
public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* TVMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* TV_TableMesh;

	//FUNCTIONS
public:
	
};
