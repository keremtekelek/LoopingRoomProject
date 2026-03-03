
#include "LoopingRoomGameMode.h"
#include "LoopingRoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALoopingRoomGameMode::ALoopingRoomGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/01_MyContent/Blueprints/Characters/MainCharacter/BP_MainCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
