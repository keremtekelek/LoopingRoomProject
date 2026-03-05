#pragma once

#include "CoreMinimal.h"
#include "Actors/Base/ActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "UninteractableActorBase.generated.h"


UCLASS()
class LOOPINGROOM_API AUninteractableActorBase : public AActorBase
{
	GENERATED_BODY()

public:

	AUninteractableActorBase();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
	//VARIABLES
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* ObjectMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	//FUNCTIONS
public:

	
	
};
	

