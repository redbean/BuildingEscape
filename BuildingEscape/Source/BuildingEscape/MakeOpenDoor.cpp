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
	AActor* Owner = GetOwner();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	//Create a Rotator

	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);

	//Set Rotation

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UMakeOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	//Trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
	else
	{
		CloseDoor();
	}
}

void UMakeOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);
	Owner->SetActorRotation(NewRotation);
}

void UMakeOpenDoor::CloseDoor()
{
	AActor* Owner = GetOwner();
	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
	Owner->SetActorRotation(NewRotation);
}

