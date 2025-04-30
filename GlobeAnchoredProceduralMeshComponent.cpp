#include "GlobeAnchoredProceduralMeshComponent.h"

AGlobeAnchoredProceduralMeshComponent::AGlobeAnchoredProceduralMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = false;
    
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    check(Root != nullptr);

    Root->SetMobility(EComponentMobility::Movable);
    Root->SetAutoActivate(true);
    this->SetRootComponent(Root);
    check(RootComponent != nullptr);

    MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("MeshComponent"));
    check(MeshComponent != nullptr);

    MeshComponent->SetAutoActivate(true);
    MeshComponent->SetupAttachment(Root);
    MeshComponent->bUseAttachParentBound = false;

    GlobeAnchor = CreateDefaultSubobject<UCesiumGlobeAnchorComponent>(TEXT("GlobeAnchor"));
    check(GlobeAnchor != nullptr);

    GlobeAnchor->SetAutoActivate(true);
}
