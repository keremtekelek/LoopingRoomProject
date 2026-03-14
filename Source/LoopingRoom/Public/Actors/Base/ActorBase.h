#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructAndEnums/GlobalStructsAndEnums.h"
#include "ActorBase.generated.h"

UCLASS()
class LOOPINGROOM_API AActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AActorBase();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	// VARIABLES!
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FActor_State ActorData; 


	//FUNCTIONS!
public:

	

};
