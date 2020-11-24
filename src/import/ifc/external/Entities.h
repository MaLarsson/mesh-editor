#pragma once

#ifndef IMPORT_IFC_EXTERNAL_ENTITIES_H_
#define IMPORT_IFC_EXTERNAL_ENTITIES_H_

#include "../../utility/SmallVector.h"
#include "Forward.h"
#include "Types.h"

#include <cstddef>
#include <string>
#include <unordered_set>
#include <variant>

namespace ifc::internal {

struct IfcEntity {};

struct IfcActionRequest : IfcControl {};

struct IfcActor : IfcObject {};

struct IfcActorRole : IfcEntity {};

struct IfcActuator : IfcDistributionControlElement {};

struct IfcActuatorType : IfcDistributionControlElementType {};

struct IfcAddress : IfcEntity {};

struct IfcAdvancedBrep : IfcManifoldSolidBrep {};

struct IfcAdvancedBrepWithVoids : IfcAdvancedBrep {};

struct IfcAdvancedFace : IfcFaceSurface {};

struct IfcAirTerminal : IfcFlowTerminal {};

struct IfcAirTerminalBox : IfcFlowController {};

struct IfcAirTerminalBoxType : IfcFlowControllerType {};

struct IfcAirTerminalType : IfcFlowTerminalType {};

struct IfcAirToAirHeatRecovery : IfcEnergyConversionDevice {};

struct IfcAirToAirHeatRecoveryType : IfcEnergyConversionDeviceType {};

struct IfcAlarm : IfcDistributionControlElement {};

struct IfcAlarmType : IfcDistributionControlElementType {};

struct IfcAlignment : IfcLinearPositioningElement {};

struct IfcAlignment2DHorizontal : IfcGeometricRepresentationItem {};

struct IfcAlignment2DHorizontalSegment : IfcAlignment2DSegment {};

struct IfcAlignment2DSegment : IfcGeometricRepresentationItem {};

struct IfcAlignment2DVerSegCircularArc : IfcAlignment2DVerticalSegment {};

struct IfcAlignment2DVerSegLine : IfcAlignment2DVerticalSegment {};

struct IfcAlignment2DVerSegParabolicArc : IfcAlignment2DVerticalSegment {};

struct IfcAlignment2DVertical : IfcGeometricRepresentationItem {};

struct IfcAlignment2DVerticalSegment : IfcAlignment2DSegment {};

struct IfcAlignmentCurve : IfcBoundedCurve {};

struct IfcAnnotation : IfcProduct {};

struct IfcAnnotationFillArea : IfcGeometricRepresentationItem {};

struct IfcApplication : IfcEntity {};

struct IfcAppliedValue : IfcEntity {};

struct IfcApproval : IfcEntity {};

struct IfcApprovalRelationship : IfcResourceLevelRelationship {};

struct IfcArbitraryClosedProfileDef : IfcProfileDef {};

struct IfcArbitraryOpenProfileDef : IfcProfileDef {};

struct IfcArbitraryProfileDefWithVoids : IfcArbitraryClosedProfileDef {};

struct IfcAsset : IfcGroup {};

struct IfcAsymmetricIShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcAudioVisualAppliance : IfcFlowTerminal {};

struct IfcAudioVisualApplianceType : IfcFlowTerminalType {};

struct IfcAxis1Placement : IfcPlacement {};

struct IfcAxis2Placement2D : IfcPlacement {};

struct IfcAxis2Placement3D : IfcPlacement {};

struct IfcBSplineCurve : IfcBoundedCurve {};

struct IfcBSplineCurveWithKnots : IfcBSplineCurve {};

struct IfcBSplineSurface : IfcBoundedSurface {};

struct IfcBSplineSurfaceWithKnots : IfcBSplineSurface {};

struct IfcBeam : IfcBuildingElement {};

struct IfcBeamStandardCase : IfcBeam {};

struct IfcBeamType : IfcBuildingElementType {};

struct IfcBlobTexture : IfcSurfaceTexture {};

struct IfcBlock : IfcCsgPrimitive3D {};

struct IfcBoiler : IfcEnergyConversionDevice {};

struct IfcBoilerType : IfcEnergyConversionDeviceType {};

struct IfcBooleanClippingResult : IfcBooleanResult {};

struct IfcBooleanResult : IfcGeometricRepresentationItem {};

struct IfcBoundaryCondition : IfcEntity {};

struct IfcBoundaryCurve : IfcCompositeCurveOnSurface {};

struct IfcBoundaryEdgeCondition : IfcBoundaryCondition {};

struct IfcBoundaryFaceCondition : IfcBoundaryCondition {};

struct IfcBoundaryNodeCondition : IfcBoundaryCondition {};

struct IfcBoundaryNodeConditionWarping : IfcBoundaryNodeCondition {};

struct IfcBoundedCurve : IfcCurve {};

struct IfcBoundedSurface : IfcSurface {};

struct IfcBoundingBox : IfcGeometricRepresentationItem {};

struct IfcBoxedHalfSpace : IfcHalfSpaceSolid {};

struct IfcBuilding : IfcSpatialStructureElement {};

struct IfcBuildingElement : IfcElement {};

struct IfcBuildingElementPart : IfcElementComponent {};

struct IfcBuildingElementPartType : IfcElementComponentType {};

struct IfcBuildingElementProxy : IfcBuildingElement {};

struct IfcBuildingElementProxyType : IfcBuildingElementType {};

struct IfcBuildingElementType : IfcElementType {};

struct IfcBuildingStorey : IfcSpatialStructureElement {};

struct IfcBuildingSystem : IfcSystem {};

struct IfcBurner : IfcEnergyConversionDevice {};

struct IfcBurnerType : IfcEnergyConversionDeviceType {};

struct IfcCShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcCableCarrierFitting : IfcFlowFitting {};

struct IfcCableCarrierFittingType : IfcFlowFittingType {};

struct IfcCableCarrierSegment : IfcFlowSegment {};

struct IfcCableCarrierSegmentType : IfcFlowSegmentType {};

struct IfcCableFitting : IfcFlowFitting {};

struct IfcCableFittingType : IfcFlowFittingType {};

struct IfcCableSegment : IfcFlowSegment {};

struct IfcCableSegmentType : IfcFlowSegmentType {};

struct IfcCartesianPoint : IfcPoint {};

struct IfcCartesianPointList : IfcGeometricRepresentationItem {};

struct IfcCartesianPointList2D : IfcCartesianPointList {};

struct IfcCartesianPointList3D : IfcCartesianPointList {};

struct IfcCartesianTransformationOperator : IfcGeometricRepresentationItem {};

struct IfcCartesianTransformationOperator2D : IfcCartesianTransformationOperator {};

struct IfcCartesianTransformationOperator2DnonUniform : IfcCartesianTransformationOperator2D {};

struct IfcCartesianTransformationOperator3D : IfcCartesianTransformationOperator {};

struct IfcCartesianTransformationOperator3DnonUniform : IfcCartesianTransformationOperator3D {};

struct IfcCenterLineProfileDef : IfcArbitraryOpenProfileDef {};

struct IfcChiller : IfcEnergyConversionDevice {};

struct IfcChillerType : IfcEnergyConversionDeviceType {};

struct IfcChimney : IfcBuildingElement {};

struct IfcChimneyType : IfcBuildingElementType {};

struct IfcCircle : IfcConic {};

struct IfcCircleHollowProfileDef : IfcCircleProfileDef {};

struct IfcCircleProfileDef : IfcParameterizedProfileDef {};

struct IfcCircularArcSegment2D : IfcCurveSegment2D {};

struct IfcCivilElement : IfcElement {};

struct IfcCivilElementType : IfcElementType {};

struct IfcClassification : IfcExternalInformation {};

struct IfcClassificationReference : IfcExternalReference {};

struct IfcClosedShell : IfcConnectedFaceSet {};

struct IfcCoil : IfcEnergyConversionDevice {};

struct IfcCoilType : IfcEnergyConversionDeviceType {};

struct IfcColourRgb : IfcColourSpecification {};

struct IfcColourRgbList : IfcPresentationItem {};

struct IfcColourSpecification : IfcPresentationItem {};

struct IfcColumn : IfcBuildingElement {};

struct IfcColumnStandardCase : IfcColumn {};

struct IfcColumnType : IfcBuildingElementType {};

struct IfcCommunicationsAppliance : IfcFlowTerminal {};

struct IfcCommunicationsApplianceType : IfcFlowTerminalType {};

struct IfcComplexProperty : IfcProperty {};

struct IfcComplexPropertyTemplate : IfcPropertyTemplate {};

struct IfcCompositeCurve : IfcBoundedCurve {};

struct IfcCompositeCurveOnSurface : IfcCompositeCurve {};

struct IfcCompositeCurveSegment : IfcGeometricRepresentationItem {};

struct IfcCompositeProfileDef : IfcProfileDef {};

struct IfcCompressor : IfcFlowMovingDevice {};

struct IfcCompressorType : IfcFlowMovingDeviceType {};

struct IfcCondenser : IfcEnergyConversionDevice {};

struct IfcCondenserType : IfcEnergyConversionDeviceType {};

struct IfcConic : IfcCurve {};

struct IfcConnectedFaceSet : IfcTopologicalRepresentationItem {};

struct IfcConnectionCurveGeometry : IfcConnectionGeometry {};

struct IfcConnectionGeometry : IfcEntity {};

struct IfcConnectionPointEccentricity : IfcConnectionPointGeometry {};

struct IfcConnectionPointGeometry : IfcConnectionGeometry {};

struct IfcConnectionSurfaceGeometry : IfcConnectionGeometry {};

struct IfcConnectionVolumeGeometry : IfcConnectionGeometry {};

struct IfcConstraint : IfcEntity {};

struct IfcConstructionEquipmentResource : IfcConstructionResource {};

struct IfcConstructionEquipmentResourceType : IfcConstructionResourceType {};

struct IfcConstructionMaterialResource : IfcConstructionResource {};

struct IfcConstructionMaterialResourceType : IfcConstructionResourceType {};

struct IfcConstructionProductResource : IfcConstructionResource {};

struct IfcConstructionProductResourceType : IfcConstructionResourceType {};

struct IfcConstructionResource : IfcResource {};

struct IfcConstructionResourceType : IfcTypeResource {};

struct IfcContext : IfcObjectDefinition {};

struct IfcContextDependentUnit : IfcNamedUnit {};

struct IfcControl : IfcObject {};

struct IfcController : IfcDistributionControlElement {};

struct IfcControllerType : IfcDistributionControlElementType {};

struct IfcConversionBasedUnit : IfcNamedUnit {};

struct IfcConversionBasedUnitWithOffset : IfcConversionBasedUnit {};

struct IfcCooledBeam : IfcEnergyConversionDevice {};

struct IfcCooledBeamType : IfcEnergyConversionDeviceType {};

struct IfcCoolingTower : IfcEnergyConversionDevice {};

struct IfcCoolingTowerType : IfcEnergyConversionDeviceType {};

struct IfcCoordinateOperation : IfcEntity {};

struct IfcCoordinateReferenceSystem : IfcEntity {};

struct IfcCostItem : IfcControl {};

struct IfcCostSchedule : IfcControl {};

struct IfcCostValue : IfcAppliedValue {};

struct IfcCovering : IfcBuildingElement {};

struct IfcCoveringType : IfcBuildingElementType {};

struct IfcCrewResource : IfcConstructionResource {};

struct IfcCrewResourceType : IfcConstructionResourceType {};

struct IfcCsgPrimitive3D : IfcGeometricRepresentationItem {};

struct IfcCsgSolid : IfcSolidModel {};

struct IfcCurrencyRelationship : IfcResourceLevelRelationship {};

struct IfcCurtainWall : IfcBuildingElement {};

struct IfcCurtainWallType : IfcBuildingElementType {};

struct IfcCurve : IfcGeometricRepresentationItem {};

struct IfcCurveBoundedPlane : IfcBoundedSurface {};

struct IfcCurveBoundedSurface : IfcBoundedSurface {};

struct IfcCurveSegment2D : IfcBoundedCurve {};

struct IfcCurveStyle : IfcPresentationStyle {};

struct IfcCurveStyleFont : IfcPresentationItem {};

struct IfcCurveStyleFontAndScaling : IfcPresentationItem {};

struct IfcCurveStyleFontPattern : IfcPresentationItem {};

struct IfcCylindricalSurface : IfcElementarySurface {};

struct IfcDamper : IfcFlowController {};

struct IfcDamperType : IfcFlowControllerType {};

struct IfcDerivedProfileDef : IfcProfileDef {};

struct IfcDerivedUnit : IfcEntity {};

struct IfcDerivedUnitElement : IfcEntity {};

struct IfcDimensionalExponents : IfcEntity {};

struct IfcDirection : IfcGeometricRepresentationItem {};

struct IfcDiscreteAccessory : IfcElementComponent {};

struct IfcDiscreteAccessoryType : IfcElementComponentType {};

struct IfcDistanceExpression : IfcGeometricRepresentationItem {};

struct IfcDistributionChamberElement : IfcDistributionFlowElement {};

struct IfcDistributionChamberElementType : IfcDistributionFlowElementType {};

struct IfcDistributionCircuit : IfcDistributionSystem {};

struct IfcDistributionControlElement : IfcDistributionElement {};

struct IfcDistributionControlElementType : IfcDistributionElementType {};

struct IfcDistributionElement : IfcElement {};

struct IfcDistributionElementType : IfcElementType {};

struct IfcDistributionFlowElement : IfcDistributionElement {};

struct IfcDistributionFlowElementType : IfcDistributionElementType {};

struct IfcDistributionPort : IfcPort {};

struct IfcDistributionSystem : IfcSystem {};

struct IfcDocumentInformation : IfcExternalInformation {};

struct IfcDocumentInformationRelationship : IfcResourceLevelRelationship {};

struct IfcDocumentReference : IfcExternalReference {};

struct IfcDoor : IfcBuildingElement {};

struct IfcDoorLiningProperties : IfcPreDefinedPropertySet {};

struct IfcDoorPanelProperties : IfcPreDefinedPropertySet {};

struct IfcDoorStandardCase : IfcDoor {};

struct IfcDoorStyle : IfcTypeProduct {};

struct IfcDoorType : IfcBuildingElementType {};

struct IfcDraughtingPreDefinedColour : IfcPreDefinedColour {};

struct IfcDraughtingPreDefinedCurveFont : IfcPreDefinedCurveFont {};

struct IfcDuctFitting : IfcFlowFitting {};

struct IfcDuctFittingType : IfcFlowFittingType {};

struct IfcDuctSegment : IfcFlowSegment {};

struct IfcDuctSegmentType : IfcFlowSegmentType {};

struct IfcDuctSilencer : IfcFlowTreatmentDevice {};

struct IfcDuctSilencerType : IfcFlowTreatmentDeviceType {};

struct IfcEdge : IfcTopologicalRepresentationItem {};

struct IfcEdgeCurve : IfcEdge {};

struct IfcEdgeLoop : IfcLoop {};

struct IfcElectricAppliance : IfcFlowTerminal {};

struct IfcElectricApplianceType : IfcFlowTerminalType {};

struct IfcElectricDistributionBoard : IfcFlowController {};

struct IfcElectricDistributionBoardType : IfcFlowControllerType {};

struct IfcElectricFlowStorageDevice : IfcFlowStorageDevice {};

struct IfcElectricFlowStorageDeviceType : IfcFlowStorageDeviceType {};

struct IfcElectricGenerator : IfcEnergyConversionDevice {};

struct IfcElectricGeneratorType : IfcEnergyConversionDeviceType {};

struct IfcElectricMotor : IfcEnergyConversionDevice {};

struct IfcElectricMotorType : IfcEnergyConversionDeviceType {};

struct IfcElectricTimeControl : IfcFlowController {};

struct IfcElectricTimeControlType : IfcFlowControllerType {};

struct IfcElement : IfcProduct {};

struct IfcElementAssembly : IfcElement {};

struct IfcElementAssemblyType : IfcElementType {};

struct IfcElementComponent : IfcElement {};

struct IfcElementComponentType : IfcElementType {};

struct IfcElementQuantity : IfcQuantitySet {};

struct IfcElementType : IfcTypeProduct {};

struct IfcElementarySurface : IfcSurface {};

struct IfcEllipse : IfcConic {};

struct IfcEllipseProfileDef : IfcParameterizedProfileDef {};

struct IfcEnergyConversionDevice : IfcDistributionFlowElement {};

struct IfcEnergyConversionDeviceType : IfcDistributionFlowElementType {};

struct IfcEngine : IfcEnergyConversionDevice {};

struct IfcEngineType : IfcEnergyConversionDeviceType {};

struct IfcEvaporativeCooler : IfcEnergyConversionDevice {};

struct IfcEvaporativeCoolerType : IfcEnergyConversionDeviceType {};

struct IfcEvaporator : IfcEnergyConversionDevice {};

struct IfcEvaporatorType : IfcEnergyConversionDeviceType {};

struct IfcEvent : IfcProcess {};

struct IfcEventTime : IfcSchedulingTime {};

struct IfcEventType : IfcTypeProcess {};

struct IfcExtendedProperties : IfcPropertyAbstraction {};

struct IfcExternalInformation : IfcEntity {};

struct IfcExternalReference : IfcEntity {};

struct IfcExternalReferenceRelationship : IfcResourceLevelRelationship {};

struct IfcExternalSpatialElement : IfcExternalSpatialStructureElement {};

struct IfcExternalSpatialStructureElement : IfcSpatialElement {};

struct IfcExternallyDefinedHatchStyle : IfcExternalReference {};

struct IfcExternallyDefinedSurfaceStyle : IfcExternalReference {};

struct IfcExternallyDefinedTextFont : IfcExternalReference {};

struct IfcExtrudedAreaSolid : IfcSweptAreaSolid {};

struct IfcExtrudedAreaSolidTapered : IfcExtrudedAreaSolid {};

struct IfcFace : IfcTopologicalRepresentationItem {};

struct IfcFaceBasedSurfaceModel : IfcGeometricRepresentationItem {};

struct IfcFaceBound : IfcTopologicalRepresentationItem {};

struct IfcFaceOuterBound : IfcFaceBound {};

struct IfcFaceSurface : IfcFace {};

struct IfcFacetedBrep : IfcManifoldSolidBrep {};

struct IfcFacetedBrepWithVoids : IfcFacetedBrep {};

struct IfcFailureConnectionCondition : IfcStructuralConnectionCondition {};

struct IfcFan : IfcFlowMovingDevice {};

struct IfcFanType : IfcFlowMovingDeviceType {};

struct IfcFastener : IfcElementComponent {};

struct IfcFastenerType : IfcElementComponentType {};

struct IfcFeatureElement : IfcElement {};

struct IfcFeatureElementAddition : IfcFeatureElement {};

struct IfcFeatureElementSubtraction : IfcFeatureElement {};

struct IfcFillAreaStyle : IfcPresentationStyle {};

struct IfcFillAreaStyleHatching : IfcGeometricRepresentationItem {};

struct IfcFillAreaStyleTiles : IfcGeometricRepresentationItem {};

struct IfcFilter : IfcFlowTreatmentDevice {};

struct IfcFilterType : IfcFlowTreatmentDeviceType {};

struct IfcFireSuppressionTerminal : IfcFlowTerminal {};

struct IfcFireSuppressionTerminalType : IfcFlowTerminalType {};

struct IfcFixedReferenceSweptAreaSolid : IfcSweptAreaSolid {};

struct IfcFlowController : IfcDistributionFlowElement {};

struct IfcFlowControllerType : IfcDistributionFlowElementType {};

struct IfcFlowFitting : IfcDistributionFlowElement {};

struct IfcFlowFittingType : IfcDistributionFlowElementType {};

struct IfcFlowInstrument : IfcDistributionControlElement {};

struct IfcFlowInstrumentType : IfcDistributionControlElementType {};

struct IfcFlowMeter : IfcFlowController {};

struct IfcFlowMeterType : IfcFlowControllerType {};

struct IfcFlowMovingDevice : IfcDistributionFlowElement {};

struct IfcFlowMovingDeviceType : IfcDistributionFlowElementType {};

struct IfcFlowSegment : IfcDistributionFlowElement {};

struct IfcFlowSegmentType : IfcDistributionFlowElementType {};

struct IfcFlowStorageDevice : IfcDistributionFlowElement {};

struct IfcFlowStorageDeviceType : IfcDistributionFlowElementType {};

struct IfcFlowTerminal : IfcDistributionFlowElement {};

struct IfcFlowTerminalType : IfcDistributionFlowElementType {};

struct IfcFlowTreatmentDevice : IfcDistributionFlowElement {};

struct IfcFlowTreatmentDeviceType : IfcDistributionFlowElementType {};

struct IfcFooting : IfcBuildingElement {};

struct IfcFootingType : IfcBuildingElementType {};

struct IfcFurnishingElement : IfcElement {};

struct IfcFurnishingElementType : IfcElementType {};

struct IfcFurniture : IfcFurnishingElement {};

struct IfcFurnitureType : IfcFurnishingElementType {};

struct IfcGeographicElement : IfcElement {};

struct IfcGeographicElementType : IfcElementType {};

struct IfcGeometricCurveSet : IfcGeometricSet {};

struct IfcGeometricRepresentationContext : IfcRepresentationContext {};

struct IfcGeometricRepresentationItem : IfcRepresentationItem {};

struct IfcGeometricRepresentationSubContext : IfcGeometricRepresentationContext {};

struct IfcGeometricSet : IfcGeometricRepresentationItem {};

struct IfcGrid : IfcPositioningElement {};

struct IfcGridAxis : IfcEntity {};

struct IfcGridPlacement : IfcObjectPlacement {};

struct IfcGroup : IfcObject {};

struct IfcHalfSpaceSolid : IfcGeometricRepresentationItem {};

struct IfcHeatExchanger : IfcEnergyConversionDevice {};

struct IfcHeatExchangerType : IfcEnergyConversionDeviceType {};

struct IfcHumidifier : IfcEnergyConversionDevice {};

struct IfcHumidifierType : IfcEnergyConversionDeviceType {};

struct IfcIShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcImageTexture : IfcSurfaceTexture {};

struct IfcIndexedColourMap : IfcPresentationItem {};

struct IfcIndexedPolyCurve : IfcBoundedCurve {};

struct IfcIndexedPolygonalFace : IfcTessellatedItem {};

struct IfcIndexedPolygonalFaceWithVoids : IfcIndexedPolygonalFace {};

struct IfcIndexedTextureMap : IfcTextureCoordinate {};

struct IfcIndexedTriangleTextureMap : IfcIndexedTextureMap {};

struct IfcInterceptor : IfcFlowTreatmentDevice {};

struct IfcInterceptorType : IfcFlowTreatmentDeviceType {};

struct IfcIntersectionCurve : IfcSurfaceCurve {};

struct IfcInventory : IfcGroup {};

struct IfcIrregularTimeSeries : IfcTimeSeries {};

struct IfcIrregularTimeSeriesValue : IfcEntity {};

struct IfcJunctionBox : IfcFlowFitting {};

struct IfcJunctionBoxType : IfcFlowFittingType {};

struct IfcLShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcLaborResource : IfcConstructionResource {};

struct IfcLaborResourceType : IfcConstructionResourceType {};

struct IfcLagTime : IfcSchedulingTime {};

struct IfcLamp : IfcFlowTerminal {};

struct IfcLampType : IfcFlowTerminalType {};

struct IfcLibraryInformation : IfcExternalInformation {};

struct IfcLibraryReference : IfcExternalReference {};

struct IfcLightDistributionData : IfcEntity {};

struct IfcLightFixture : IfcFlowTerminal {};

struct IfcLightFixtureType : IfcFlowTerminalType {};

struct IfcLightIntensityDistribution : IfcEntity {};

struct IfcLightSource : IfcGeometricRepresentationItem {};

struct IfcLightSourceAmbient : IfcLightSource {};

struct IfcLightSourceDirectional : IfcLightSource {};

struct IfcLightSourceGoniometric : IfcLightSource {};

struct IfcLightSourcePositional : IfcLightSource {};

struct IfcLightSourceSpot : IfcLightSourcePositional {};

struct IfcLine : IfcCurve {};

struct IfcLineSegment2D : IfcCurveSegment2D {};

struct IfcLinearPlacement : IfcObjectPlacement {};

struct IfcLinearPositioningElement : IfcPositioningElement {};

struct IfcLocalPlacement : IfcObjectPlacement {};

struct IfcLoop : IfcTopologicalRepresentationItem {};

struct IfcManifoldSolidBrep : IfcSolidModel {};

struct IfcMapConversion : IfcCoordinateOperation {};

struct IfcMappedItem : IfcRepresentationItem {};

struct IfcMaterial : IfcMaterialDefinition {};

struct IfcMaterialClassificationRelationship : IfcEntity {};

struct IfcMaterialConstituent : IfcMaterialDefinition {};

struct IfcMaterialConstituentSet : IfcMaterialDefinition {};

struct IfcMaterialDefinition : IfcEntity {};

struct IfcMaterialDefinitionRepresentation : IfcProductRepresentation {};

struct IfcMaterialLayer : IfcMaterialDefinition {};

struct IfcMaterialLayerSet : IfcMaterialDefinition {};

struct IfcMaterialLayerSetUsage : IfcMaterialUsageDefinition {};

struct IfcMaterialLayerWithOffsets : IfcMaterialLayer {};

struct IfcMaterialList : IfcEntity {};

struct IfcMaterialProfile : IfcMaterialDefinition {};

struct IfcMaterialProfileSet : IfcMaterialDefinition {};

struct IfcMaterialProfileSetUsage : IfcMaterialUsageDefinition {};

struct IfcMaterialProfileSetUsageTapering : IfcMaterialProfileSetUsage {};

struct IfcMaterialProfileWithOffsets : IfcMaterialProfile {};

struct IfcMaterialProperties : IfcExtendedProperties {};

struct IfcMaterialRelationship : IfcResourceLevelRelationship {};

struct IfcMaterialUsageDefinition : IfcEntity {};

struct IfcMeasureWithUnit : IfcEntity {};

struct IfcMechanicalFastener : IfcElementComponent {};

struct IfcMechanicalFastenerType : IfcElementComponentType {};

struct IfcMedicalDevice : IfcFlowTerminal {};

struct IfcMedicalDeviceType : IfcFlowTerminalType {};

struct IfcMember : IfcBuildingElement {};

struct IfcMemberStandardCase : IfcMember {};

struct IfcMemberType : IfcBuildingElementType {};

struct IfcMetric : IfcConstraint {};

struct IfcMirroredProfileDef : IfcDerivedProfileDef {};

struct IfcMonetaryUnit : IfcEntity {};

struct IfcMotorConnection : IfcEnergyConversionDevice {};

struct IfcMotorConnectionType : IfcEnergyConversionDeviceType {};

struct IfcNamedUnit : IfcEntity {};

struct IfcObject : IfcObjectDefinition {};

struct IfcObjectDefinition : IfcRoot {};

struct IfcObjectPlacement : IfcEntity {};

struct IfcObjective : IfcConstraint {};

struct IfcOccupant : IfcActor {};

struct IfcOffsetCurve : IfcCurve {};

struct IfcOffsetCurve2D : IfcOffsetCurve {};

struct IfcOffsetCurve3D : IfcOffsetCurve {};

struct IfcOffsetCurveByDistances : IfcOffsetCurve {};

struct IfcOpenShell : IfcConnectedFaceSet {};

struct IfcOpeningElement : IfcFeatureElementSubtraction {};

struct IfcOpeningStandardCase : IfcOpeningElement {};

struct IfcOrganization : IfcEntity {};

struct IfcOrganizationRelationship : IfcResourceLevelRelationship {};

struct IfcOrientationExpression : IfcGeometricRepresentationItem {};

struct IfcOrientedEdge : IfcEdge {};

struct IfcOuterBoundaryCurve : IfcBoundaryCurve {};

struct IfcOutlet : IfcFlowTerminal {};

struct IfcOutletType : IfcFlowTerminalType {};

struct IfcOwnerHistory : IfcEntity {};

struct IfcParameterizedProfileDef : IfcProfileDef {};

struct IfcPath : IfcTopologicalRepresentationItem {};

struct IfcPcurve : IfcCurve {};

struct IfcPerformanceHistory : IfcControl {};

struct IfcPermeableCoveringProperties : IfcPreDefinedPropertySet {};

struct IfcPermit : IfcControl {};

struct IfcPerson : IfcEntity {};

struct IfcPersonAndOrganization : IfcEntity {};

struct IfcPhysicalComplexQuantity : IfcPhysicalQuantity {};

struct IfcPhysicalQuantity : IfcEntity {};

struct IfcPhysicalSimpleQuantity : IfcPhysicalQuantity {};

struct IfcPile : IfcBuildingElement {};

struct IfcPileType : IfcBuildingElementType {};

struct IfcPipeFitting : IfcFlowFitting {};

struct IfcPipeFittingType : IfcFlowFittingType {};

struct IfcPipeSegment : IfcFlowSegment {};

struct IfcPipeSegmentType : IfcFlowSegmentType {};

struct IfcPixelTexture : IfcSurfaceTexture {};

struct IfcPlacement : IfcGeometricRepresentationItem {};

struct IfcPlanarBox : IfcPlanarExtent {};

struct IfcPlanarExtent : IfcGeometricRepresentationItem {};

struct IfcPlane : IfcElementarySurface {};

struct IfcPlate : IfcBuildingElement {};

struct IfcPlateStandardCase : IfcPlate {};

struct IfcPlateType : IfcBuildingElementType {};

struct IfcPoint : IfcGeometricRepresentationItem {};

struct IfcPointOnCurve : IfcPoint {};

struct IfcPointOnSurface : IfcPoint {};

struct IfcPolyLoop : IfcLoop {};

struct IfcPolygonalBoundedHalfSpace : IfcHalfSpaceSolid {};

struct IfcPolygonalFaceSet : IfcTessellatedFaceSet {};

struct IfcPolyline : IfcBoundedCurve {};

struct IfcPort : IfcProduct {};

struct IfcPositioningElement : IfcProduct {};

struct IfcPostalAddress : IfcAddress {};

struct IfcPreDefinedColour : IfcPreDefinedItem {};

struct IfcPreDefinedCurveFont : IfcPreDefinedItem {};

struct IfcPreDefinedItem : IfcPresentationItem {};

struct IfcPreDefinedProperties : IfcPropertyAbstraction {};

struct IfcPreDefinedPropertySet : IfcPropertySetDefinition {};

struct IfcPreDefinedTextFont : IfcPreDefinedItem {};

struct IfcPresentationItem : IfcEntity {};

struct IfcPresentationLayerAssignment : IfcEntity {};

struct IfcPresentationLayerWithStyle : IfcPresentationLayerAssignment {};

struct IfcPresentationStyle : IfcEntity {};

struct IfcPresentationStyleAssignment : IfcEntity {};

struct IfcProcedure : IfcProcess {};

struct IfcProcedureType : IfcTypeProcess {};

struct IfcProcess : IfcObject {};

struct IfcProduct : IfcObject {};

struct IfcProductDefinitionShape : IfcProductRepresentation {};

struct IfcProductRepresentation : IfcEntity {};

struct IfcProfileDef : IfcEntity {};

struct IfcProfileProperties : IfcExtendedProperties {};

struct IfcProject : IfcContext {};

struct IfcProjectLibrary : IfcContext {};

struct IfcProjectOrder : IfcControl {};

struct IfcProjectedCRS : IfcCoordinateReferenceSystem {};

struct IfcProjectionElement : IfcFeatureElementAddition {};

struct IfcProperty : IfcPropertyAbstraction {};

struct IfcPropertyAbstraction : IfcEntity {};

struct IfcPropertyBoundedValue : IfcSimpleProperty {};

struct IfcPropertyDefinition : IfcRoot {};

struct IfcPropertyDependencyRelationship : IfcResourceLevelRelationship {};

struct IfcPropertyEnumeratedValue : IfcSimpleProperty {};

struct IfcPropertyEnumeration : IfcPropertyAbstraction {};

struct IfcPropertyListValue : IfcSimpleProperty {};

struct IfcPropertyReferenceValue : IfcSimpleProperty {};

struct IfcPropertySet : IfcPropertySetDefinition {};

struct IfcPropertySetDefinition : IfcPropertyDefinition {};

struct IfcPropertySetTemplate : IfcPropertyTemplateDefinition {};

struct IfcPropertySingleValue : IfcSimpleProperty {};

struct IfcPropertyTableValue : IfcSimpleProperty {};

struct IfcPropertyTemplate : IfcPropertyTemplateDefinition {};

struct IfcPropertyTemplateDefinition : IfcPropertyDefinition {};

struct IfcProtectiveDevice : IfcFlowController {};

struct IfcProtectiveDeviceTrippingUnit : IfcDistributionControlElement {};

struct IfcProtectiveDeviceTrippingUnitType : IfcDistributionControlElementType {};

struct IfcProtectiveDeviceType : IfcFlowControllerType {};

struct IfcProxy : IfcProduct {};

struct IfcPump : IfcFlowMovingDevice {};

struct IfcPumpType : IfcFlowMovingDeviceType {};

struct IfcQuantityArea : IfcPhysicalSimpleQuantity {};

struct IfcQuantityCount : IfcPhysicalSimpleQuantity {};

struct IfcQuantityLength : IfcPhysicalSimpleQuantity {};

struct IfcQuantitySet : IfcPropertySetDefinition {};

struct IfcQuantityTime : IfcPhysicalSimpleQuantity {};

struct IfcQuantityVolume : IfcPhysicalSimpleQuantity {};

struct IfcQuantityWeight : IfcPhysicalSimpleQuantity {};

struct IfcRailing : IfcBuildingElement {};

struct IfcRailingType : IfcBuildingElementType {};

struct IfcRamp : IfcBuildingElement {};

struct IfcRampFlight : IfcBuildingElement {};

struct IfcRampFlightType : IfcBuildingElementType {};

struct IfcRampType : IfcBuildingElementType {};

struct IfcRationalBSplineCurveWithKnots : IfcBSplineCurveWithKnots {};

struct IfcRationalBSplineSurfaceWithKnots : IfcBSplineSurfaceWithKnots {};

struct IfcRectangleHollowProfileDef : IfcRectangleProfileDef {};

struct IfcRectangleProfileDef : IfcParameterizedProfileDef {};

struct IfcRectangularPyramid : IfcCsgPrimitive3D {};

struct IfcRectangularTrimmedSurface : IfcBoundedSurface {};

struct IfcRecurrencePattern : IfcEntity {};

struct IfcReference : IfcEntity {};

struct IfcReferent : IfcPositioningElement {};

struct IfcRegularTimeSeries : IfcTimeSeries {};

struct IfcReinforcementBarProperties : IfcPreDefinedProperties {};

struct IfcReinforcementDefinitionProperties : IfcPreDefinedPropertySet {};

struct IfcReinforcingBar : IfcReinforcingElement {};

struct IfcReinforcingBarType : IfcReinforcingElementType {};

struct IfcReinforcingElement : IfcElementComponent {};

struct IfcReinforcingElementType : IfcElementComponentType {};

struct IfcReinforcingMesh : IfcReinforcingElement {};

struct IfcReinforcingMeshType : IfcReinforcingElementType {};

struct IfcRelAggregates : IfcRelDecomposes {};

struct IfcRelAssigns : IfcRelationship {};

struct IfcRelAssignsToActor : IfcRelAssigns {};

struct IfcRelAssignsToControl : IfcRelAssigns {};

struct IfcRelAssignsToGroup : IfcRelAssigns {};

struct IfcRelAssignsToGroupByFactor : IfcRelAssignsToGroup {};

struct IfcRelAssignsToProcess : IfcRelAssigns {};

struct IfcRelAssignsToProduct : IfcRelAssigns {};

struct IfcRelAssignsToResource : IfcRelAssigns {};

struct IfcRelAssociates : IfcRelationship {};

struct IfcRelAssociatesApproval : IfcRelAssociates {};

struct IfcRelAssociatesClassification : IfcRelAssociates {};

struct IfcRelAssociatesConstraint : IfcRelAssociates {};

struct IfcRelAssociatesDocument : IfcRelAssociates {};

struct IfcRelAssociatesLibrary : IfcRelAssociates {};

struct IfcRelAssociatesMaterial : IfcRelAssociates {};

struct IfcRelConnects : IfcRelationship {};

struct IfcRelConnectsElements : IfcRelConnects {};

struct IfcRelConnectsPathElements : IfcRelConnectsElements {};

struct IfcRelConnectsPortToElement : IfcRelConnects {};

struct IfcRelConnectsPorts : IfcRelConnects {};

struct IfcRelConnectsStructuralActivity : IfcRelConnects {};

struct IfcRelConnectsStructuralMember : IfcRelConnects {};

struct IfcRelConnectsWithEccentricity : IfcRelConnectsStructuralMember {};

struct IfcRelConnectsWithRealizingElements : IfcRelConnectsElements {};

struct IfcRelContainedInSpatialStructure : IfcRelConnects {};

struct IfcRelCoversBldgElements : IfcRelConnects {};

struct IfcRelCoversSpaces : IfcRelConnects {};

struct IfcRelDeclares : IfcRelationship {};

struct IfcRelDecomposes : IfcRelationship {};

struct IfcRelDefines : IfcRelationship {};

struct IfcRelDefinesByObject : IfcRelDefines {};

struct IfcRelDefinesByProperties : IfcRelDefines {};

struct IfcRelDefinesByTemplate : IfcRelDefines {};

struct IfcRelDefinesByType : IfcRelDefines {};

struct IfcRelFillsElement : IfcRelConnects {};

struct IfcRelFlowControlElements : IfcRelConnects {};

struct IfcRelInterferesElements : IfcRelConnects {};

struct IfcRelNests : IfcRelDecomposes {};

struct IfcRelProjectsElement : IfcRelDecomposes {};

struct IfcRelReferencedInSpatialStructure : IfcRelConnects {};

struct IfcRelSequence : IfcRelConnects {};

struct IfcRelServicesBuildings : IfcRelConnects {};

struct IfcRelSpaceBoundary : IfcRelConnects {};

struct IfcRelSpaceBoundary1stLevel : IfcRelSpaceBoundary {};

struct IfcRelSpaceBoundary2ndLevel : IfcRelSpaceBoundary1stLevel {};

struct IfcRelVoidsElement : IfcRelDecomposes {};

struct IfcRelationship : IfcRoot {};

struct IfcReparametrisedCompositeCurveSegment : IfcCompositeCurveSegment {};

struct IfcRepresentation : IfcEntity {};

struct IfcRepresentationContext : IfcEntity {};

struct IfcRepresentationItem : IfcEntity {};

struct IfcRepresentationMap : IfcEntity {};

struct IfcResource : IfcObject {};

struct IfcResourceApprovalRelationship : IfcResourceLevelRelationship {};

struct IfcResourceConstraintRelationship : IfcResourceLevelRelationship {};

struct IfcResourceLevelRelationship : IfcEntity {};

struct IfcResourceTime : IfcSchedulingTime {};

struct IfcRevolvedAreaSolid : IfcSweptAreaSolid {};

struct IfcRevolvedAreaSolidTapered : IfcRevolvedAreaSolid {};

struct IfcRightCircularCone : IfcCsgPrimitive3D {};

struct IfcRightCircularCylinder : IfcCsgPrimitive3D {};

struct IfcRoof : IfcBuildingElement {};

struct IfcRoofType : IfcBuildingElementType {};

struct IfcRoot : IfcEntity {};

struct IfcRoundedRectangleProfileDef : IfcRectangleProfileDef {};

struct IfcSIUnit : IfcNamedUnit {};

struct IfcSanitaryTerminal : IfcFlowTerminal {};

struct IfcSanitaryTerminalType : IfcFlowTerminalType {};

struct IfcSchedulingTime : IfcEntity {};

struct IfcSeamCurve : IfcSurfaceCurve {};

struct IfcSectionProperties : IfcPreDefinedProperties {};

struct IfcSectionReinforcementProperties : IfcPreDefinedProperties {};

struct IfcSectionedSolid : IfcSolidModel {};

struct IfcSectionedSolidHorizontal : IfcSectionedSolid {};

struct IfcSectionedSpine : IfcGeometricRepresentationItem {};

struct IfcSensor : IfcDistributionControlElement {};

struct IfcSensorType : IfcDistributionControlElementType {};

struct IfcShadingDevice : IfcBuildingElement {};

struct IfcShadingDeviceType : IfcBuildingElementType {};

struct IfcShapeAspect : IfcEntity {};

struct IfcShapeModel : IfcRepresentation {};

struct IfcShapeRepresentation : IfcShapeModel {};

struct IfcShellBasedSurfaceModel : IfcGeometricRepresentationItem {};

struct IfcSimpleProperty : IfcProperty {};

struct IfcSimplePropertyTemplate : IfcPropertyTemplate {};

struct IfcSite : IfcSpatialStructureElement {};

struct IfcSlab : IfcBuildingElement {};

struct IfcSlabElementedCase : IfcSlab {};

struct IfcSlabStandardCase : IfcSlab {};

struct IfcSlabType : IfcBuildingElementType {};

struct IfcSlippageConnectionCondition : IfcStructuralConnectionCondition {};

struct IfcSolarDevice : IfcEnergyConversionDevice {};

struct IfcSolarDeviceType : IfcEnergyConversionDeviceType {};

struct IfcSolidModel : IfcGeometricRepresentationItem {};

struct IfcSpace : IfcSpatialStructureElement {};

struct IfcSpaceHeater : IfcFlowTerminal {};

struct IfcSpaceHeaterType : IfcFlowTerminalType {};

struct IfcSpaceType : IfcSpatialStructureElementType {};

struct IfcSpatialElement : IfcProduct {};

struct IfcSpatialElementType : IfcTypeProduct {};

struct IfcSpatialStructureElement : IfcSpatialElement {};

struct IfcSpatialStructureElementType : IfcSpatialElementType {};

struct IfcSpatialZone : IfcSpatialElement {};

struct IfcSpatialZoneType : IfcSpatialElementType {};

struct IfcSphere : IfcCsgPrimitive3D {};

struct IfcSphericalSurface : IfcElementarySurface {};

struct IfcStackTerminal : IfcFlowTerminal {};

struct IfcStackTerminalType : IfcFlowTerminalType {};

struct IfcStair : IfcBuildingElement {};

struct IfcStairFlight : IfcBuildingElement {};

struct IfcStairFlightType : IfcBuildingElementType {};

struct IfcStairType : IfcBuildingElementType {};

struct IfcStructuralAction : IfcStructuralActivity {};

struct IfcStructuralActivity : IfcProduct {};

struct IfcStructuralAnalysisModel : IfcSystem {};

struct IfcStructuralConnection : IfcStructuralItem {};

struct IfcStructuralConnectionCondition : IfcEntity {};

struct IfcStructuralCurveAction : IfcStructuralAction {};

struct IfcStructuralCurveConnection : IfcStructuralConnection {};

struct IfcStructuralCurveMember : IfcStructuralMember {};

struct IfcStructuralCurveMemberVarying : IfcStructuralCurveMember {};

struct IfcStructuralCurveReaction : IfcStructuralReaction {};

struct IfcStructuralItem : IfcProduct {};

struct IfcStructuralLinearAction : IfcStructuralCurveAction {};

struct IfcStructuralLoad : IfcEntity {};

struct IfcStructuralLoadCase : IfcStructuralLoadGroup {};

struct IfcStructuralLoadConfiguration : IfcStructuralLoad {};

struct IfcStructuralLoadGroup : IfcGroup {};

struct IfcStructuralLoadLinearForce : IfcStructuralLoadStatic {};

struct IfcStructuralLoadOrResult : IfcStructuralLoad {};

struct IfcStructuralLoadPlanarForce : IfcStructuralLoadStatic {};

struct IfcStructuralLoadSingleDisplacement : IfcStructuralLoadStatic {};

struct IfcStructuralLoadSingleDisplacementDistortion : IfcStructuralLoadSingleDisplacement {};

struct IfcStructuralLoadSingleForce : IfcStructuralLoadStatic {};

struct IfcStructuralLoadSingleForceWarping : IfcStructuralLoadSingleForce {};

struct IfcStructuralLoadStatic : IfcStructuralLoadOrResult {};

struct IfcStructuralLoadTemperature : IfcStructuralLoadStatic {};

struct IfcStructuralMember : IfcStructuralItem {};

struct IfcStructuralPlanarAction : IfcStructuralSurfaceAction {};

struct IfcStructuralPointAction : IfcStructuralAction {};

struct IfcStructuralPointConnection : IfcStructuralConnection {};

struct IfcStructuralPointReaction : IfcStructuralReaction {};

struct IfcStructuralReaction : IfcStructuralActivity {};

struct IfcStructuralResultGroup : IfcGroup {};

struct IfcStructuralSurfaceAction : IfcStructuralAction {};

struct IfcStructuralSurfaceConnection : IfcStructuralConnection {};

struct IfcStructuralSurfaceMember : IfcStructuralMember {};

struct IfcStructuralSurfaceMemberVarying : IfcStructuralSurfaceMember {};

struct IfcStructuralSurfaceReaction : IfcStructuralReaction {};

struct IfcStyleModel : IfcRepresentation {};

struct IfcStyledItem : IfcRepresentationItem {};

struct IfcStyledRepresentation : IfcStyleModel {};

struct IfcSubContractResource : IfcConstructionResource {};

struct IfcSubContractResourceType : IfcConstructionResourceType {};

struct IfcSubedge : IfcEdge {};

struct IfcSurface : IfcGeometricRepresentationItem {};

struct IfcSurfaceCurve : IfcCurve {};

struct IfcSurfaceCurveSweptAreaSolid : IfcSweptAreaSolid {};

struct IfcSurfaceFeature : IfcFeatureElement {};

struct IfcSurfaceOfLinearExtrusion : IfcSweptSurface {};

struct IfcSurfaceOfRevolution : IfcSweptSurface {};

struct IfcSurfaceReinforcementArea : IfcStructuralLoadOrResult {};

struct IfcSurfaceStyle : IfcPresentationStyle {};

struct IfcSurfaceStyleLighting : IfcPresentationItem {};

struct IfcSurfaceStyleRefraction : IfcPresentationItem {};

struct IfcSurfaceStyleRendering : IfcSurfaceStyleShading {};

struct IfcSurfaceStyleShading : IfcPresentationItem {};

struct IfcSurfaceStyleWithTextures : IfcPresentationItem {};

struct IfcSurfaceTexture : IfcPresentationItem {};

struct IfcSweptAreaSolid : IfcSolidModel {};

struct IfcSweptDiskSolid : IfcSolidModel {};

struct IfcSweptDiskSolidPolygonal : IfcSweptDiskSolid {};

struct IfcSweptSurface : IfcSurface {};

struct IfcSwitchingDevice : IfcFlowController {};

struct IfcSwitchingDeviceType : IfcFlowControllerType {};

struct IfcSystem : IfcGroup {};

struct IfcSystemFurnitureElement : IfcFurnishingElement {};

struct IfcSystemFurnitureElementType : IfcFurnishingElementType {};

struct IfcTShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcTable : IfcEntity {};

struct IfcTableColumn : IfcEntity {};

struct IfcTableRow : IfcEntity {};

struct IfcTank : IfcFlowStorageDevice {};

struct IfcTankType : IfcFlowStorageDeviceType {};

struct IfcTask : IfcProcess {};

struct IfcTaskTime : IfcSchedulingTime {};

struct IfcTaskTimeRecurring : IfcTaskTime {};

struct IfcTaskType : IfcTypeProcess {};

struct IfcTelecomAddress : IfcAddress {};

struct IfcTendon : IfcReinforcingElement {};

struct IfcTendonAnchor : IfcReinforcingElement {};

struct IfcTendonAnchorType : IfcReinforcingElementType {};

struct IfcTendonType : IfcReinforcingElementType {};

struct IfcTessellatedFaceSet : IfcTessellatedItem {};

struct IfcTessellatedItem : IfcGeometricRepresentationItem {};

struct IfcTextLiteral : IfcGeometricRepresentationItem {};

struct IfcTextLiteralWithExtent : IfcTextLiteral {};

struct IfcTextStyle : IfcPresentationStyle {};

struct IfcTextStyleFontModel : IfcPreDefinedTextFont {};

struct IfcTextStyleForDefinedFont : IfcPresentationItem {};

struct IfcTextStyleTextModel : IfcPresentationItem {};

struct IfcTextureCoordinate : IfcPresentationItem {};

struct IfcTextureCoordinateGenerator : IfcTextureCoordinate {};

struct IfcTextureMap : IfcTextureCoordinate {};

struct IfcTextureVertex : IfcPresentationItem {};

struct IfcTextureVertexList : IfcPresentationItem {};

struct IfcTimePeriod : IfcEntity {};

struct IfcTimeSeries : IfcEntity {};

struct IfcTimeSeriesValue : IfcEntity {};

struct IfcTopologicalRepresentationItem : IfcRepresentationItem {};

struct IfcTopologyRepresentation : IfcShapeModel {};

struct IfcToroidalSurface : IfcElementarySurface {};

struct IfcTransformer : IfcEnergyConversionDevice {};

struct IfcTransformerType : IfcEnergyConversionDeviceType {};

struct IfcTransitionCurveSegment2D : IfcCurveSegment2D {};

struct IfcTransportElement : IfcElement {};

struct IfcTransportElementType : IfcElementType {};

struct IfcTrapeziumProfileDef : IfcParameterizedProfileDef {};

struct IfcTriangulatedFaceSet : IfcTessellatedFaceSet {};

struct IfcTriangulatedIrregularNetwork : IfcTriangulatedFaceSet {};

struct IfcTrimmedCurve : IfcBoundedCurve {};

struct IfcTubeBundle : IfcEnergyConversionDevice {};

struct IfcTubeBundleType : IfcEnergyConversionDeviceType {};

struct IfcTypeObject : IfcObjectDefinition {};

struct IfcTypeProcess : IfcTypeObject {};

struct IfcTypeProduct : IfcTypeObject {};

struct IfcTypeResource : IfcTypeObject {};

struct IfcUShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcUnitAssignment : IfcEntity {};

struct IfcUnitaryControlElement : IfcDistributionControlElement {};

struct IfcUnitaryControlElementType : IfcDistributionControlElementType {};

struct IfcUnitaryEquipment : IfcEnergyConversionDevice {};

struct IfcUnitaryEquipmentType : IfcEnergyConversionDeviceType {};

struct IfcValve : IfcFlowController {};

struct IfcValveType : IfcFlowControllerType {};

struct IfcVector : IfcGeometricRepresentationItem {};

struct IfcVertex : IfcTopologicalRepresentationItem {};

struct IfcVertexLoop : IfcLoop {};

struct IfcVertexPoint : IfcVertex {};

struct IfcVibrationIsolator : IfcElementComponent {};

struct IfcVibrationIsolatorType : IfcElementComponentType {};

struct IfcVirtualElement : IfcElement {};

struct IfcVirtualGridIntersection : IfcEntity {};

struct IfcVoidingFeature : IfcFeatureElementSubtraction {};

struct IfcWall : IfcBuildingElement {};

struct IfcWallElementedCase : IfcWall {};

struct IfcWallStandardCase : IfcWall {};

struct IfcWallType : IfcBuildingElementType {};

struct IfcWasteTerminal : IfcFlowTerminal {};

struct IfcWasteTerminalType : IfcFlowTerminalType {};

struct IfcWindow : IfcBuildingElement {};

struct IfcWindowLiningProperties : IfcPreDefinedPropertySet {};

struct IfcWindowPanelProperties : IfcPreDefinedPropertySet {};

struct IfcWindowStandardCase : IfcWindow {};

struct IfcWindowStyle : IfcTypeProduct {};

struct IfcWindowType : IfcBuildingElementType {};

struct IfcWorkCalendar : IfcControl {};

struct IfcWorkControl : IfcControl {};

struct IfcWorkPlan : IfcWorkControl {};

struct IfcWorkSchedule : IfcWorkControl {};

struct IfcWorkTime : IfcSchedulingTime {};

struct IfcZShapeProfileDef : IfcParameterizedProfileDef {};

struct IfcZone : IfcSystem {};

} // namespace ifc::internal

#endif // IMPORT_IFC_EXTERNAL_ENTITIES_H_
