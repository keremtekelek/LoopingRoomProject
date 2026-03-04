#pragma once

#include "CoreMinimal.h"
#include "Actors/Base/InteractableActorBase.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Sound/SoundAttenuation.h"
#include "Door.generated.h"


class UAC_InteractableComponent;

UCLASS()
class LOOPINGROOM_API ADoor : public AInteractableActorBase
{
	GENERATED_BODY()
	
public:	
	
	ADoor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	//For variables
public:

	UPROPERTY(VisibleAnywhere)
	ACharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAC_InteractableComponent* InteractableComponent;
	
	UPROPERTY(VisibleAnywhere)
	bool CanInteract = false;

	UPROPERTY(VisibleAnywhere)
	bool IsDoorOpen = false;

	UPROPERTY(VisibleAnywhere)
	bool IsPlaying = false;

	UPROPERTY(VisibleAnywhere)
	bool FlipFlopVariable = true;

	UPROPERTY(VisibleAnywhere)
	float DotProductResult = 0.f;

	UPROPERTY(VisibleAnywhere)
	float DoorStartFloat = 0.f;

	UPROPERTY(VisibleAnywhere)
	float DoorEndFloat = 90.f;

	UPROPERTY(EditAnywhere)
	float DoorSoundVolume = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* DoorOpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* DoorCloseSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundAttenuation* DoorSoundAttenuation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	UPROPERTY()
	FTimeline DoorTimeline;

	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;

	//For functions
public:

	UFUNCTION()
	void OpenTheDoor();

	UFUNCTION()
	float CalculateDotProduct();

	UFUNCTION()
	void HandleProgress(float Value);

	UFUNCTION()
	void HandleFinished();

	UFUNCTION()
	void OnInteractionTriggered();

};
