#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GlobalStructsAndEnums.generated.h"


 

USTRUCT(BlueprintType)
struct FActor_State
{
	GENERATED_BODY()
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsActorVisible;
    
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform TransformData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> SpawnableLocations;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FRotator> SpawnableRotations;
};

USTRUCT(BlueprintType)
struct FRoom_State
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoomID;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsRoomVisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform TransformData;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FGameplayTag, FActor_State> RoomActors;
};

