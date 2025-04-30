#include "Actors/GlobeAnchoredSpline.h"

AGlobeAnchoredSpline::AGlobeAnchoredSpline(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = false;
    
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    check(Root != nullptr);

    Root->SetMobility(EComponentMobility::Movable);
    Root->SetAutoActivate(true);
    this->SetRootComponent(Root);
    check(RootComponent != nullptr);

    SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
    check(SplineComponent != nullptr);

    SplineComponent->SetAutoActivate(true);
    SplineComponent->SetupAttachment(Root);

    GlobeAnchor = CreateDefaultSubobject<UCesiumGlobeAnchorComponent>(TEXT("GlobeAnchor"));
    check(GlobeAnchor != nullptr);

    GlobeAnchor->SetAutoActivate(true);
}
