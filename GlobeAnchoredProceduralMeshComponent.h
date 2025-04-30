#pragma once

#include "ProceduralMeshComponent.h"
#include "CesiumGlobeAnchorComponent.h"
#include "GlobeAnchoredProceduralMeshComponent.generated.h"


UCLASS(BlueprintType)
class NAMESPACE_API AGlobeAnchoredProceduralMeshComponent : public APawn
{
    GENERATED_BODY()

public:
    explicit AGlobeAnchoredProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    USceneComponent* Root;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UProceduralMeshComponent* MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UCesiumGlobeAnchorComponent* GlobeAnchor;
};
