#include "ProceduralMeshFunctionLibrary.h"

void UProceduralMeshFunctionLibrary::GenerateCylinderMesh(UProceduralMeshComponent* MeshComponent, const float& CylinderRadius, const float& Height, const bool& bVUp, const int32& nVerticalFaces, UMaterialInterface* TopBottomMaterial, UMaterialInterface* SidesMaterial)
{
    if (MeshComponent)
    {
        MeshComponent->ClearAllMeshSections();

        const float AngularStep = 360.0f / static_cast<float>(nVerticalFaces);

        const FVector Up(0,0,1);
        const FVector Down(0,0,-1);
        const FVector Right(0,1,0);
        const FVector UpVector = Height * Up;
        const FVector BottomCenterPoint(0,0,0);
        const FVector TopCenterPoint = BottomCenterPoint + UpVector;
        const int32 nVerticalFacesMinusOne = nVerticalFaces - 1;

        TArray<FVector> CylinderBaseVerticies;
        TArray<FVector> CylinderTopVerticies;

        FVector P1(0, CylinderRadius, 0);

        CylinderBaseVerticies.Add(P1);
        
        for (int32 i = 0; i < nVerticalFacesMinusOne; ++i)
        {
            P1 = P1.RotateAngleAxis(AngularStep, Up);
            const FVector P2 = P1 + UpVector;
            CylinderBaseVerticies.Add(P1);
            CylinderTopVerticies.Add(P2);
        }

        int32 SectionIndex = 0;

        const TArray<int32> TriangleIndicies1 = {0,1,2};
        const TArray<int32> TriangleIndicies2 = {0, 1, 3, 1, 2, 3};
        const TArray<FVector> Normals1 = {Up, Up, Up};
        const TArray<FVector> Normals2 = {Down, Down, Down};
        TArray<FProcMeshTangent> Tangents1;
        if(bVUp)
        {
            Tangents1.Init(FProcMeshTangent(Right, false), 4);
        } else {
            Tangents1.Init(FProcMeshTangent(Up, false), 4);
        }


        for (int32 i = 0; i < nVerticalFacesMinusOne; ++i)
        {
            const int32 ii = (i + 1) % nVerticalFacesMinusOne;
            
            const FVector Point1 = CylinderBaseVerticies[i];
            const FVector Point2 = CylinderTopVerticies[i];
            const FVector Point3 = CylinderTopVerticies[ii];
            const FVector Point4 = CylinderBaseVerticies[ii];

            FVector Out = FVector::CrossProduct(Up, (Point3 - Point1).GetSafeNormal());

            MeshComponent->CreateMeshSection(SectionIndex, {TopCenterPoint, Point2, Point3}, TriangleIndicies1, Normals1, {}, {}, {}, false);

            if(TopBottomMaterial)
            {
                MeshComponent->SetMaterial(SectionIndex, TopBottomMaterial);
            }

            ++SectionIndex;

            MeshComponent->CreateMeshSection(SectionIndex, {Point1, Point2, Point3, Point4}, TriangleIndicies2, {Out, Out, Out, Out}, {FVector2D(0,1), FVector2D(0,0), FVector2D(1,0), FVector2D(1,1)}, {}, Tangents1, false);

            if(SidesMaterial)
            {
                MeshComponent->SetMaterial(SectionIndex, SidesMaterial);
            }

            ++SectionIndex;

            MeshComponent->CreateMeshSection(SectionIndex, {BottomCenterPoint, Point1, Point4}, TriangleIndicies1, Normals2, {}, {}, {}, false);

            if(TopBottomMaterial)
            {
                MeshComponent->SetMaterial(SectionIndex, TopBottomMaterial);
            }

            ++SectionIndex;
        }
    }
}
