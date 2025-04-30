#pragma once

#include "Components/SplineComponent.h"
#include "CesiumGlobeAnchorComponent.h"
#include "GlobeAnchoredSpline.generated.h"


UCLASS(BlueprintType)
class NAMESPACE_API AGlobeAnchoredSpline : public APawn
{
    GENERATED_BODY()

public:
    explicit AGlobeAnchoredSpline(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    USceneComponent* Root;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    USplineComponent* SplineComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UCesiumGlobeAnchorComponent* GlobeAnchor;
};
