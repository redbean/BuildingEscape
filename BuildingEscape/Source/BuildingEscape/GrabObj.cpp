// Copyright Ben Tristem 2016.

#include "BuildingEscape.h"
#include "GrabObj.h"


#define OUT

// Sets default values for this component's properties
UGrabObj::UGrabObj()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabObj::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("test"));


	// ...
	
}


// Called every frame
void UGrabObj::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get Player viewpoint this tick


	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;


	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	//UE_LOG(LogTemp, Warning, TEXT("Location : %s, Position :%s"), 
	//	*PlayerViewPointLocation.ToString(), 
	//	*PlayerViewPointRotation.ToString());
	// raycast out to reach
	
	FVector LineTraceEnd = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);
	
	
	PlayerViewPointRotation.Vector();


	//
}

