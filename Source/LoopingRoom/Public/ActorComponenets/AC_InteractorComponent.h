#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_InteractorComponent.generated.h"

class UAC_InteractableComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOOPINGROOM_API UAC_InteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UAC_InteractorComponent();

protected:
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//VARIABLES
public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Interaction")
	float InteractionDistance = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool EnableDebug{false};

	//FUNCTIONS
	
public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void TryInteract();
};
