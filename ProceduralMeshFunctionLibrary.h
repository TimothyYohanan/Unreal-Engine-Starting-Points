#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshFunctionLibrary.generated.h"

UCLASS(BlueprintType, Blueprintable)
class NAMESPACE_API UProceduralMeshFunctionLibrary : public UKismetProceduralMeshLibrary
{
    GENERATED_BODY()

public:
    /*
    * With a carefully constructed animated material, you can do quite a bit with this simple shape, and others like it.
    */
    UFUNCTION(BlueprintCallable)
    static void GenerateCylinderMesh(UProceduralMeshComponent* MeshComponent, const float& CylinderRadius, const float& Height, const bool& bVUp, const int32& nVerticalFaces, UMaterialInterface* TopBottomMaterial, UMaterialInterface* SidesMaterial);

};
