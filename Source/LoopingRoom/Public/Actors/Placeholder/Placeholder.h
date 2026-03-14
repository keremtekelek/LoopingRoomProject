#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ChildActorComponent.h"
#include "Placeholder.generated.h"

UCLASS()
class LOOPINGROOM_API APlaceholder : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APlaceholder();

protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
	// VARIABLES
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UChildActorComponent* ChildActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* PossibleActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform PlaceholderData;
	
	
	//FUNCTIONS!
public:
	
	

};
