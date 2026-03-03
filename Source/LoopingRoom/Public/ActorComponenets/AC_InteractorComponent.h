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

public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Interaction")
	float InteractionDistance = 250.0f;

	
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void TryInteract();
};
