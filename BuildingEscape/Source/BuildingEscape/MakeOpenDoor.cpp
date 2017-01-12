// Copyright Ben Tristem 2016.

#include "BuildingEscape.h"
#include "MakeOpenDoor.h"


// Sets default values for this component's properties
UMakeOpenDoor::UMakeOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMakeOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Find Owner
	ActorOwner = GetOwner();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UMakeOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	//Trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();

	}
	
	

	//check if it's time to close




	


}

void UMakeOpenDoor::OpenDoor()
{
	ActorOwner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UMakeOpenDoor::CloseDoor()
{
	ActorOwner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}

