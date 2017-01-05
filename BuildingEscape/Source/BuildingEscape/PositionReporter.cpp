// Copyright Ben Tristem 2016.

#include "BuildingEscape.h"
#include "PositionReporter.h"
#include "Engine.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;


	
	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
	
	FString ObjectName = GetOwner()->GetName();
	FVector ObjectLocation = GetOwner()->GetActorLocation();
	

	UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty on %s at %s"), *ObjectName, *ObjectLocation.ToString());
	
	// ...
	
}


// Called every frame
void UPositionReporter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

