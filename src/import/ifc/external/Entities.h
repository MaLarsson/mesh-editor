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

struct IfcActionRequest : IfcControl {
  IfcActionRequestTypeEnum PredefinedType;
  IfcLabel Status;
  IfcText LongDescription;
};

struct IfcActor : IfcObject {
  IfcActorSelect TheActor;
};

struct IfcActorRole : IfcEntity {
  IfcRoleEnum Role;
  IfcLabel UserDefinedRole;
  IfcText Description;
};

struct IfcActuator : IfcDistributionControlElement {
  IfcActuatorTypeEnum PredefinedType;
};

struct IfcActuatorType : IfcDistributionControlElementType {
  IfcActuatorTypeEnum PredefinedType;
};

struct IfcAddress : IfcEntity {
  IfcAddressTypeEnum Purpose;
  IfcText Description;
  IfcLabel UserDefinedPurpose;
};

struct IfcAdvancedBrep : IfcManifoldSolidBrep {};

struct IfcAdvancedBrepWithVoids : IfcAdvancedBrep {
  std::unordered_set<IfcClosedShell> Voids;
};

struct IfcAdvancedFace : IfcFaceSurface {};

struct IfcAirTerminal : IfcFlowTerminal {
  IfcAirTerminalTypeEnum PredefinedType;
};

struct IfcAirTerminalBox : IfcFlowController {
  IfcAirTerminalBoxTypeEnum PredefinedType;
};

struct IfcAirTerminalBoxType : IfcFlowControllerType {
  IfcAirTerminalBoxTypeEnum PredefinedType;
};

struct IfcAirTerminalType : IfcFlowTerminalType {
  IfcAirTerminalTypeEnum PredefinedType;
};

struct IfcAirToAirHeatRecovery : IfcEnergyConversionDevice {
  IfcAirToAirHeatRecoveryTypeEnum PredefinedType;
};

struct IfcAirToAirHeatRecoveryType : IfcEnergyConversionDeviceType {
  IfcAirToAirHeatRecoveryTypeEnum PredefinedType;
};

struct IfcAlarm : IfcDistributionControlElement {
  IfcAlarmTypeEnum PredefinedType;
};

struct IfcAlarmType : IfcDistributionControlElementType {
  IfcAlarmTypeEnum PredefinedType;
};

struct IfcAlignment : IfcLinearPositioningElement {
  IfcAlignmentTypeEnum PredefinedType;
};

struct IfcAlignment2DHorizontal : IfcGeometricRepresentationItem {
  IfcLengthMeasure StartDistAlong;
  SmallVector<IfcAlignment2DHorizontalSegment, 4> Segments;
};

struct IfcAlignment2DHorizontalSegment : IfcAlignment2DSegment {
  IfcCurveSegment2D CurveGeometry;
};

struct IfcAlignment2DSegment : IfcGeometricRepresentationItem {
  IfcBoolean TangentialContinuity;
  IfcLabel StartTag;
  IfcLabel EndTag;
};

struct IfcAlignment2DVerSegCircularArc : IfcAlignment2DVerticalSegment {
  IfcPositiveLengthMeasure Radius;
  IfcBoolean IsConvex;
};

struct IfcAlignment2DVerSegLine : IfcAlignment2DVerticalSegment {};

struct IfcAlignment2DVerSegParabolicArc : IfcAlignment2DVerticalSegment {
  IfcPositiveLengthMeasure ParabolaConstant;
  IfcBoolean IsConvex;
};

struct IfcAlignment2DVertical : IfcGeometricRepresentationItem {
  SmallVector<IfcAlignment2DVerticalSegment, 4> Segments;
};

struct IfcAlignment2DVerticalSegment : IfcAlignment2DSegment {
  IfcLengthMeasure StartDistAlong;
  IfcPositiveLengthMeasure HorizontalLength;
  IfcLengthMeasure StartHeight;
  IfcRatioMeasure StartGradient;
};

struct IfcAlignmentCurve : IfcBoundedCurve {
  IfcAlignment2DHorizontal Horizontal;
  IfcAlignment2DVertical Vertical;
  IfcLabel Tag;
};

struct IfcAnnotation : IfcProduct {};

struct IfcAnnotationFillArea : IfcGeometricRepresentationItem {
  IfcCurve OuterBoundary;
  std::unordered_set<IfcCurve> InnerBoundaries;
};

struct IfcApplication : IfcEntity {
  IfcOrganization ApplicationDeveloper;
  IfcLabel Version;
  IfcLabel ApplicationFullName;
  IfcIdentifier ApplicationIdentifier;
};

struct IfcAppliedValue : IfcEntity {
  IfcLabel Name;
  IfcText Description;
  IfcAppliedValueSelect AppliedValue;
  IfcMeasureWithUnit UnitBasis;
  IfcDate ApplicableDate;
  IfcDate FixedUntilDate;
  IfcLabel Category;
  IfcLabel Condition;
  IfcArithmeticOperatorEnum ArithmeticOperator;
  SmallVector<IfcAppliedValue, 4> Components;
};

struct IfcApproval : IfcEntity {
  IfcIdentifier Identifier;
  IfcLabel Name;
  IfcText Description;
  IfcDateTime TimeOfApproval;
  IfcLabel Status;
  IfcLabel Level;
  IfcText Qualifier;
  IfcActorSelect RequestingApproval;
  IfcActorSelect GivingApproval;
};

struct IfcApprovalRelationship : IfcResourceLevelRelationship {
  IfcApproval RelatingApproval;
  std::unordered_set<IfcApproval> RelatedApprovals;
};

struct IfcArbitraryClosedProfileDef : IfcProfileDef {
  IfcCurve OuterCurve;
};

struct IfcArbitraryOpenProfileDef : IfcProfileDef {
  IfcBoundedCurve Curve;
};

struct IfcArbitraryProfileDefWithVoids : IfcArbitraryClosedProfileDef {
  std::unordered_set<IfcCurve> InnerCurves;
};

struct IfcAsset : IfcGroup {
  IfcIdentifier Identification;
  IfcCostValue OriginalValue;
  IfcCostValue CurrentValue;
  IfcCostValue TotalReplacementCost;
  IfcActorSelect Owner;
  IfcActorSelect User;
  IfcPerson ResponsiblePerson;
  IfcDate IncorporationDate;
  IfcCostValue DepreciatedValue;
};

struct IfcAsymmetricIShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure BottomFlangeWidth;
  IfcPositiveLengthMeasure OverallDepth;
  IfcPositiveLengthMeasure WebThickness;
  IfcPositiveLengthMeasure BottomFlangeThickness;
  IfcNonNegativeLengthMeasure BottomFlangeFilletRadius;
  IfcPositiveLengthMeasure TopFlangeWidth;
  IfcPositiveLengthMeasure TopFlangeThickness;
  IfcNonNegativeLengthMeasure TopFlangeFilletRadius;
  IfcNonNegativeLengthMeasure BottomFlangeEdgeRadius;
  IfcPlaneAngleMeasure BottomFlangeSlope;
  IfcNonNegativeLengthMeasure TopFlangeEdgeRadius;
  IfcPlaneAngleMeasure TopFlangeSlope;
};

struct IfcAudioVisualAppliance : IfcFlowTerminal {
  IfcAudioVisualApplianceTypeEnum PredefinedType;
};

struct IfcAudioVisualApplianceType : IfcFlowTerminalType {
  IfcAudioVisualApplianceTypeEnum PredefinedType;
};

struct IfcAxis1Placement : IfcPlacement {
  IfcDirection Axis;
};

struct IfcAxis2Placement2D : IfcPlacement {
  IfcDirection RefDirection;
};

struct IfcAxis2Placement3D : IfcPlacement {
  IfcDirection Axis;
  IfcDirection RefDirection;
};

struct IfcBSplineCurve : IfcBoundedCurve {
  IfcInteger Degree;
  SmallVector<IfcCartesianPoint, 4> ControlPointsList;
  IfcBSplineCurveForm CurveForm;
  IfcLogical ClosedCurve;
  IfcLogical SelfIntersect;
};

struct IfcBSplineCurveWithKnots : IfcBSplineCurve {
  SmallVector<IfcInteger, 4> KnotMultiplicities;
  SmallVector<IfcParameterValue, 4> Knots;
  IfcKnotType KnotSpec;
};

struct IfcBSplineSurface : IfcBoundedSurface {
  IfcInteger UDegree;
  IfcInteger VDegree;
  SmallVector<SmallVector<IfcCartesianPoint, 4>, 4> ControlPointsList;
  IfcBSplineSurfaceForm SurfaceForm;
  IfcLogical UClosed;
  IfcLogical VClosed;
  IfcLogical SelfIntersect;
};

struct IfcBSplineSurfaceWithKnots : IfcBSplineSurface {
  SmallVector<IfcInteger, 4> UMultiplicities;
  SmallVector<IfcInteger, 4> VMultiplicities;
  SmallVector<IfcParameterValue, 4> UKnots;
  SmallVector<IfcParameterValue, 4> VKnots;
  IfcKnotType KnotSpec;
};

struct IfcBeam : IfcBuildingElement {
  IfcBeamTypeEnum PredefinedType;
};

struct IfcBeamStandardCase : IfcBeam {};

struct IfcBeamType : IfcBuildingElementType {
  IfcBeamTypeEnum PredefinedType;
};

struct IfcBlobTexture : IfcSurfaceTexture {
  IfcIdentifier RasterFormat;
  IfcBinary RasterCode;
};

struct IfcBlock : IfcCsgPrimitive3D {
  IfcPositiveLengthMeasure XLength;
  IfcPositiveLengthMeasure YLength;
  IfcPositiveLengthMeasure ZLength;
};

struct IfcBoiler : IfcEnergyConversionDevice {
  IfcBoilerTypeEnum PredefinedType;
};

struct IfcBoilerType : IfcEnergyConversionDeviceType {
  IfcBoilerTypeEnum PredefinedType;
};

struct IfcBooleanClippingResult : IfcBooleanResult {};

struct IfcBooleanResult : IfcGeometricRepresentationItem {
  IfcBooleanOperator Operator;
  IfcBooleanOperand FirstOperand;
  IfcBooleanOperand SecondOperand;
};

struct IfcBoundaryCondition : IfcEntity {
  IfcLabel Name;
};

struct IfcBoundaryCurve : IfcCompositeCurveOnSurface {};

struct IfcBoundaryEdgeCondition : IfcBoundaryCondition {
  IfcModulusOfTranslationalSubgradeReactionSelect TranslationalStiffnessByLengthX;
  IfcModulusOfTranslationalSubgradeReactionSelect TranslationalStiffnessByLengthY;
  IfcModulusOfTranslationalSubgradeReactionSelect TranslationalStiffnessByLengthZ;
  IfcModulusOfRotationalSubgradeReactionSelect RotationalStiffnessByLengthX;
  IfcModulusOfRotationalSubgradeReactionSelect RotationalStiffnessByLengthY;
  IfcModulusOfRotationalSubgradeReactionSelect RotationalStiffnessByLengthZ;
};

struct IfcBoundaryFaceCondition : IfcBoundaryCondition {
  IfcModulusOfSubgradeReactionSelect TranslationalStiffnessByAreaX;
  IfcModulusOfSubgradeReactionSelect TranslationalStiffnessByAreaY;
  IfcModulusOfSubgradeReactionSelect TranslationalStiffnessByAreaZ;
};

struct IfcBoundaryNodeCondition : IfcBoundaryCondition {
  IfcTranslationalStiffnessSelect TranslationalStiffnessX;
  IfcTranslationalStiffnessSelect TranslationalStiffnessY;
  IfcTranslationalStiffnessSelect TranslationalStiffnessZ;
  IfcRotationalStiffnessSelect RotationalStiffnessX;
  IfcRotationalStiffnessSelect RotationalStiffnessY;
  IfcRotationalStiffnessSelect RotationalStiffnessZ;
};

struct IfcBoundaryNodeConditionWarping : IfcBoundaryNodeCondition {
  IfcWarpingStiffnessSelect WarpingStiffness;
};

struct IfcBoundedCurve : IfcCurve {};

struct IfcBoundedSurface : IfcSurface {};

struct IfcBoundingBox : IfcGeometricRepresentationItem {
  IfcCartesianPoint Corner;
  IfcPositiveLengthMeasure XDim;
  IfcPositiveLengthMeasure YDim;
  IfcPositiveLengthMeasure ZDim;
};

struct IfcBoxedHalfSpace : IfcHalfSpaceSolid {
  IfcBoundingBox Enclosure;
};

struct IfcBuilding : IfcSpatialStructureElement {
  IfcLengthMeasure ElevationOfRefHeight;
  IfcLengthMeasure ElevationOfTerrain;
  IfcPostalAddress BuildingAddress;
};

struct IfcBuildingElement : IfcElement {};

struct IfcBuildingElementPart : IfcElementComponent {
  IfcBuildingElementPartTypeEnum PredefinedType;
};

struct IfcBuildingElementPartType : IfcElementComponentType {
  IfcBuildingElementPartTypeEnum PredefinedType;
};

struct IfcBuildingElementProxy : IfcBuildingElement {
  IfcBuildingElementProxyTypeEnum PredefinedType;
};

struct IfcBuildingElementProxyType : IfcBuildingElementType {
  IfcBuildingElementProxyTypeEnum PredefinedType;
};

struct IfcBuildingElementType : IfcElementType {};

struct IfcBuildingStorey : IfcSpatialStructureElement {
  IfcLengthMeasure Elevation;
};

struct IfcBuildingSystem : IfcSystem {
  IfcBuildingSystemTypeEnum PredefinedType;
  IfcLabel LongName;
};

struct IfcBurner : IfcEnergyConversionDevice {
  IfcBurnerTypeEnum PredefinedType;
};

struct IfcBurnerType : IfcEnergyConversionDeviceType {
  IfcBurnerTypeEnum PredefinedType;
};

struct IfcCShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure Depth;
  IfcPositiveLengthMeasure Width;
  IfcPositiveLengthMeasure WallThickness;
  IfcPositiveLengthMeasure Girth;
  IfcNonNegativeLengthMeasure InternalFilletRadius;
};

struct IfcCableCarrierFitting : IfcFlowFitting {
  IfcCableCarrierFittingTypeEnum PredefinedType;
};

struct IfcCableCarrierFittingType : IfcFlowFittingType {
  IfcCableCarrierFittingTypeEnum PredefinedType;
};

struct IfcCableCarrierSegment : IfcFlowSegment {
  IfcCableCarrierSegmentTypeEnum PredefinedType;
};

struct IfcCableCarrierSegmentType : IfcFlowSegmentType {
  IfcCableCarrierSegmentTypeEnum PredefinedType;
};

struct IfcCableFitting : IfcFlowFitting {
  IfcCableFittingTypeEnum PredefinedType;
};

struct IfcCableFittingType : IfcFlowFittingType {
  IfcCableFittingTypeEnum PredefinedType;
};

struct IfcCableSegment : IfcFlowSegment {
  IfcCableSegmentTypeEnum PredefinedType;
};

struct IfcCableSegmentType : IfcFlowSegmentType {
  IfcCableSegmentTypeEnum PredefinedType;
};

struct IfcCartesianPoint : IfcPoint {
  SmallVector<IfcLengthMeasure, 3> Coordinates;
};

struct IfcCartesianPointList : IfcGeometricRepresentationItem {};

struct IfcCartesianPointList2D : IfcCartesianPointList {
  SmallVector<SmallVector<IfcLengthMeasure, 2>, 4> CoordList;
  SmallVector<IfcLabel, 4> TagList;
};

struct IfcCartesianPointList3D : IfcCartesianPointList {
  SmallVector<SmallVector<IfcLengthMeasure, 3>, 4> CoordList;
  SmallVector<IfcLabel, 4> TagList;
};

struct IfcCartesianTransformationOperator : IfcGeometricRepresentationItem {
  IfcDirection Axis1;
  IfcDirection Axis2;
  IfcCartesianPoint LocalOrigin;
  IfcReal Scale;
};

struct IfcCartesianTransformationOperator2D : IfcCartesianTransformationOperator {};

struct IfcCartesianTransformationOperator2DnonUniform : IfcCartesianTransformationOperator2D {
  IfcReal Scale2;
};

struct IfcCartesianTransformationOperator3D : IfcCartesianTransformationOperator {
  IfcDirection Axis3;
};

struct IfcCartesianTransformationOperator3DnonUniform : IfcCartesianTransformationOperator3D {
  IfcReal Scale2;
  IfcReal Scale3;
};

struct IfcCenterLineProfileDef : IfcArbitraryOpenProfileDef {
  IfcPositiveLengthMeasure Thickness;
};

struct IfcChiller : IfcEnergyConversionDevice {
  IfcChillerTypeEnum PredefinedType;
};

struct IfcChillerType : IfcEnergyConversionDeviceType {
  IfcChillerTypeEnum PredefinedType;
};

struct IfcChimney : IfcBuildingElement {
  IfcChimneyTypeEnum PredefinedType;
};

struct IfcChimneyType : IfcBuildingElementType {
  IfcChimneyTypeEnum PredefinedType;
};

struct IfcCircle : IfcConic {
  IfcPositiveLengthMeasure Radius;
};

struct IfcCircleHollowProfileDef : IfcCircleProfileDef {
  IfcPositiveLengthMeasure WallThickness;
};

struct IfcCircleProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure Radius;
};

struct IfcCircularArcSegment2D : IfcCurveSegment2D {
  IfcPositiveLengthMeasure Radius;
  IfcBoolean IsCCW;
};

struct IfcCivilElement : IfcElement {};

struct IfcCivilElementType : IfcElementType {};

struct IfcClassification : IfcExternalInformation {
  IfcLabel Source;
  IfcLabel Edition;
  IfcDate EditionDate;
  IfcLabel Name;
  IfcText Description;
  IfcURIReference Location;
  SmallVector<IfcIdentifier, 4> ReferenceTokens;
};

struct IfcClassificationReference : IfcExternalReference {
  IfcClassificationReferenceSelect ReferencedSource;
  IfcText Description;
  IfcIdentifier Sort;
};

struct IfcClosedShell : IfcConnectedFaceSet {};

struct IfcCoil : IfcEnergyConversionDevice {
  IfcCoilTypeEnum PredefinedType;
};

struct IfcCoilType : IfcEnergyConversionDeviceType {
  IfcCoilTypeEnum PredefinedType;
};

struct IfcColourRgb : IfcColourSpecification {
  IfcNormalisedRatioMeasure Red;
  IfcNormalisedRatioMeasure Green;
  IfcNormalisedRatioMeasure Blue;
};

struct IfcColourRgbList : IfcPresentationItem {
  SmallVector<SmallVector<IfcNormalisedRatioMeasure, 3>, 4> ColourList;
};

struct IfcColourSpecification : IfcPresentationItem {
  IfcLabel Name;
};

struct IfcColumn : IfcBuildingElement {
  IfcColumnTypeEnum PredefinedType;
};

struct IfcColumnStandardCase : IfcColumn {};

struct IfcColumnType : IfcBuildingElementType {
  IfcColumnTypeEnum PredefinedType;
};

struct IfcCommunicationsAppliance : IfcFlowTerminal {
  IfcCommunicationsApplianceTypeEnum PredefinedType;
};

struct IfcCommunicationsApplianceType : IfcFlowTerminalType {
  IfcCommunicationsApplianceTypeEnum PredefinedType;
};

struct IfcComplexProperty : IfcProperty {
  IfcIdentifier UsageName;
  std::unordered_set<IfcProperty> HasProperties;
};

struct IfcComplexPropertyTemplate : IfcPropertyTemplate {
  IfcLabel UsageName;
  IfcComplexPropertyTemplateTypeEnum TemplateType;
  std::unordered_set<IfcPropertyTemplate> HasPropertyTemplates;
};

struct IfcCompositeCurve : IfcBoundedCurve {
  SmallVector<IfcCompositeCurveSegment, 4> Segments;
  IfcLogical SelfIntersect;
};

struct IfcCompositeCurveOnSurface : IfcCompositeCurve {};

struct IfcCompositeCurveSegment : IfcGeometricRepresentationItem {
  IfcTransitionCode Transition;
  IfcBoolean SameSense;
  IfcCurve ParentCurve;
};

struct IfcCompositeProfileDef : IfcProfileDef {
  std::unordered_set<IfcProfileDef> Profiles;
  IfcLabel Label;
};

struct IfcCompressor : IfcFlowMovingDevice {
  IfcCompressorTypeEnum PredefinedType;
};

struct IfcCompressorType : IfcFlowMovingDeviceType {
  IfcCompressorTypeEnum PredefinedType;
};

struct IfcCondenser : IfcEnergyConversionDevice {
  IfcCondenserTypeEnum PredefinedType;
};

struct IfcCondenserType : IfcEnergyConversionDeviceType {
  IfcCondenserTypeEnum PredefinedType;
};

struct IfcConic : IfcCurve {
  IfcAxis2Placement Position;
};

struct IfcConnectedFaceSet : IfcTopologicalRepresentationItem {
  std::unordered_set<IfcFace> CfsFaces;
};

struct IfcConnectionCurveGeometry : IfcConnectionGeometry {
  IfcCurveOrEdgeCurve CurveOnRelatingElement;
  IfcCurveOrEdgeCurve CurveOnRelatedElement;
};

struct IfcConnectionGeometry : IfcEntity {};

struct IfcConnectionPointEccentricity : IfcConnectionPointGeometry {
  IfcLengthMeasure EccentricityInX;
  IfcLengthMeasure EccentricityInY;
  IfcLengthMeasure EccentricityInZ;
};

struct IfcConnectionPointGeometry : IfcConnectionGeometry {
  IfcPointOrVertexPoint PointOnRelatingElement;
  IfcPointOrVertexPoint PointOnRelatedElement;
};

struct IfcConnectionSurfaceGeometry : IfcConnectionGeometry {
  IfcSurfaceOrFaceSurface SurfaceOnRelatingElement;
  IfcSurfaceOrFaceSurface SurfaceOnRelatedElement;
};

struct IfcConnectionVolumeGeometry : IfcConnectionGeometry {
  IfcSolidOrShell VolumeOnRelatingElement;
  IfcSolidOrShell VolumeOnRelatedElement;
};

struct IfcConstraint : IfcEntity {
  IfcLabel Name;
  IfcText Description;
  IfcConstraintEnum ConstraintGrade;
  IfcLabel ConstraintSource;
  IfcActorSelect CreatingActor;
  IfcDateTime CreationTime;
  IfcLabel UserDefinedGrade;
};

struct IfcConstructionEquipmentResource : IfcConstructionResource {
  IfcConstructionEquipmentResourceTypeEnum PredefinedType;
};

struct IfcConstructionEquipmentResourceType : IfcConstructionResourceType {
  IfcConstructionEquipmentResourceTypeEnum PredefinedType;
};

struct IfcConstructionMaterialResource : IfcConstructionResource {
  IfcConstructionMaterialResourceTypeEnum PredefinedType;
};

struct IfcConstructionMaterialResourceType : IfcConstructionResourceType {
  IfcConstructionMaterialResourceTypeEnum PredefinedType;
};

struct IfcConstructionProductResource : IfcConstructionResource {
  IfcConstructionProductResourceTypeEnum PredefinedType;
};

struct IfcConstructionProductResourceType : IfcConstructionResourceType {
  IfcConstructionProductResourceTypeEnum PredefinedType;
};

struct IfcConstructionResource : IfcResource {
  IfcResourceTime Usage;
  SmallVector<IfcAppliedValue, 4> BaseCosts;
  IfcPhysicalQuantity BaseQuantity;
};

struct IfcConstructionResourceType : IfcTypeResource {
  SmallVector<IfcAppliedValue, 4> BaseCosts;
  IfcPhysicalQuantity BaseQuantity;
};

struct IfcContext : IfcObjectDefinition {
  IfcLabel ObjectType;
  IfcLabel LongName;
  IfcLabel Phase;
  std::unordered_set<IfcRepresentationContext> RepresentationContexts;
  IfcUnitAssignment UnitsInContext;
};

struct IfcContextDependentUnit : IfcNamedUnit {
  IfcLabel Name;
};

struct IfcControl : IfcObject {
  IfcIdentifier Identification;
};

struct IfcController : IfcDistributionControlElement {
  IfcControllerTypeEnum PredefinedType;
};

struct IfcControllerType : IfcDistributionControlElementType {
  IfcControllerTypeEnum PredefinedType;
};

struct IfcConversionBasedUnit : IfcNamedUnit {
  IfcLabel Name;
  IfcMeasureWithUnit ConversionFactor;
};

struct IfcConversionBasedUnitWithOffset : IfcConversionBasedUnit {
  IfcReal ConversionOffset;
};

struct IfcCooledBeam : IfcEnergyConversionDevice {
  IfcCooledBeamTypeEnum PredefinedType;
};

struct IfcCooledBeamType : IfcEnergyConversionDeviceType {
  IfcCooledBeamTypeEnum PredefinedType;
};

struct IfcCoolingTower : IfcEnergyConversionDevice {
  IfcCoolingTowerTypeEnum PredefinedType;
};

struct IfcCoolingTowerType : IfcEnergyConversionDeviceType {
  IfcCoolingTowerTypeEnum PredefinedType;
};

struct IfcCoordinateOperation : IfcEntity {
  IfcCoordinateReferenceSystemSelect SourceCRS;
  IfcCoordinateReferenceSystem TargetCRS;
};

struct IfcCoordinateReferenceSystem : IfcEntity {
  IfcLabel Name;
  IfcText Description;
  IfcIdentifier GeodeticDatum;
  IfcIdentifier VerticalDatum;
};

struct IfcCostItem : IfcControl {
  IfcCostItemTypeEnum PredefinedType;
  SmallVector<IfcCostValue, 4> CostValues;
  SmallVector<IfcPhysicalQuantity, 4> CostQuantities;
};

struct IfcCostSchedule : IfcControl {
  IfcCostScheduleTypeEnum PredefinedType;
  IfcLabel Status;
  IfcDateTime SubmittedOn;
  IfcDateTime UpdateDate;
};

struct IfcCostValue : IfcAppliedValue {};

struct IfcCovering : IfcBuildingElement {
  IfcCoveringTypeEnum PredefinedType;
};

struct IfcCoveringType : IfcBuildingElementType {
  IfcCoveringTypeEnum PredefinedType;
};

struct IfcCrewResource : IfcConstructionResource {
  IfcCrewResourceTypeEnum PredefinedType;
};

struct IfcCrewResourceType : IfcConstructionResourceType {
  IfcCrewResourceTypeEnum PredefinedType;
};

struct IfcCsgPrimitive3D : IfcGeometricRepresentationItem {
  IfcAxis2Placement3D Position;
};

struct IfcCsgSolid : IfcSolidModel {
  IfcCsgSelect TreeRootExpression;
};

struct IfcCurrencyRelationship : IfcResourceLevelRelationship {
  IfcMonetaryUnit RelatingMonetaryUnit;
  IfcMonetaryUnit RelatedMonetaryUnit;
  IfcPositiveRatioMeasure ExchangeRate;
  IfcDateTime RateDateTime;
  IfcLibraryInformation RateSource;
};

struct IfcCurtainWall : IfcBuildingElement {
  IfcCurtainWallTypeEnum PredefinedType;
};

struct IfcCurtainWallType : IfcBuildingElementType {
  IfcCurtainWallTypeEnum PredefinedType;
};

struct IfcCurve : IfcGeometricRepresentationItem {};

struct IfcCurveBoundedPlane : IfcBoundedSurface {
  IfcPlane BasisSurface;
  IfcCurve OuterBoundary;
  std::unordered_set<IfcCurve> InnerBoundaries;
};

struct IfcCurveBoundedSurface : IfcBoundedSurface {
  IfcSurface BasisSurface;
  std::unordered_set<IfcBoundaryCurve> Boundaries;
  IfcBoolean ImplicitOuter;
};

struct IfcCurveSegment2D : IfcBoundedCurve {
  IfcCartesianPoint StartPoint;
  IfcPlaneAngleMeasure StartDirection;
  IfcPositiveLengthMeasure SegmentLength;
};

struct IfcCurveStyle : IfcPresentationStyle {
  IfcCurveFontOrScaledCurveFontSelect CurveFont;
  IfcSizeSelect CurveWidth;
  IfcColour CurveColour;
  IfcBoolean ModelOrDraughting;
};

struct IfcCurveStyleFont : IfcPresentationItem {
  IfcLabel Name;
  SmallVector<IfcCurveStyleFontPattern, 4> PatternList;
};

struct IfcCurveStyleFontAndScaling : IfcPresentationItem {
  IfcLabel Name;
  IfcCurveStyleFontSelect CurveFont;
  IfcPositiveRatioMeasure CurveFontScaling;
};

struct IfcCurveStyleFontPattern : IfcPresentationItem {
  IfcLengthMeasure VisibleSegmentLength;
  IfcPositiveLengthMeasure InvisibleSegmentLength;
};

struct IfcCylindricalSurface : IfcElementarySurface {
  IfcPositiveLengthMeasure Radius;
};

struct IfcDamper : IfcFlowController {
  IfcDamperTypeEnum PredefinedType;
};

struct IfcDamperType : IfcFlowControllerType {
  IfcDamperTypeEnum PredefinedType;
};

struct IfcDerivedProfileDef : IfcProfileDef {
  IfcProfileDef ParentProfile;
  IfcCartesianTransformationOperator2D Operator;
  IfcLabel Label;
};

struct IfcDerivedUnit : IfcEntity {
  std::unordered_set<IfcDerivedUnitElement> Elements;
  IfcDerivedUnitEnum UnitType;
  IfcLabel UserDefinedType;
};

struct IfcDerivedUnitElement : IfcEntity {
  IfcNamedUnit Unit;
  int Exponent;
};

struct IfcDimensionalExponents : IfcEntity {
  int LengthExponent;
  int MassExponent;
  int TimeExponent;
  int ElectricCurrentExponent;
  int ThermodynamicTemperatureExponent;
  int AmountOfSubstanceExponent;
  int LuminousIntensityExponent;
};

struct IfcDirection : IfcGeometricRepresentationItem {
  SmallVector<IfcReal, 3> DirectionRatios;
};

struct IfcDiscreteAccessory : IfcElementComponent {
  IfcDiscreteAccessoryTypeEnum PredefinedType;
};

struct IfcDiscreteAccessoryType : IfcElementComponentType {
  IfcDiscreteAccessoryTypeEnum PredefinedType;
};

struct IfcDistanceExpression : IfcGeometricRepresentationItem {
  IfcLengthMeasure DistanceAlong;
  IfcLengthMeasure OffsetLateral;
  IfcLengthMeasure OffsetVertical;
  IfcLengthMeasure OffsetLongitudinal;
  IfcBoolean AlongHorizontal;
};

struct IfcDistributionChamberElement : IfcDistributionFlowElement {
  IfcDistributionChamberElementTypeEnum PredefinedType;
};

struct IfcDistributionChamberElementType : IfcDistributionFlowElementType {
  IfcDistributionChamberElementTypeEnum PredefinedType;
};

struct IfcDistributionCircuit : IfcDistributionSystem {};

struct IfcDistributionControlElement : IfcDistributionElement {};

struct IfcDistributionControlElementType : IfcDistributionElementType {};

struct IfcDistributionElement : IfcElement {};

struct IfcDistributionElementType : IfcElementType {};

struct IfcDistributionFlowElement : IfcDistributionElement {};

struct IfcDistributionFlowElementType : IfcDistributionElementType {};

struct IfcDistributionPort : IfcPort {
  IfcFlowDirectionEnum FlowDirection;
  IfcDistributionPortTypeEnum PredefinedType;
  IfcDistributionSystemEnum SystemType;
};

struct IfcDistributionSystem : IfcSystem {
  IfcLabel LongName;
  IfcDistributionSystemEnum PredefinedType;
};

struct IfcDocumentInformation : IfcExternalInformation {
  IfcIdentifier Identification;
  IfcLabel Name;
  IfcText Description;
  IfcURIReference Location;
  IfcText Purpose;
  IfcText IntendedUse;
  IfcText Scope;
  IfcLabel Revision;
  IfcActorSelect DocumentOwner;
  std::unordered_set<IfcActorSelect> Editors;
  IfcDateTime CreationTime;
  IfcDateTime LastRevisionTime;
  IfcIdentifier ElectronicFormat;
  IfcDate ValidFrom;
  IfcDate ValidUntil;
  IfcDocumentConfidentialityEnum Confidentiality;
  IfcDocumentStatusEnum Status;
};

struct IfcDocumentInformationRelationship : IfcResourceLevelRelationship {
  IfcDocumentInformation RelatingDocument;
  std::unordered_set<IfcDocumentInformation> RelatedDocuments;
  IfcLabel RelationshipType;
};

struct IfcDocumentReference : IfcExternalReference {
  IfcText Description;
  IfcDocumentInformation ReferencedDocument;
};

struct IfcDoor : IfcBuildingElement {
  IfcPositiveLengthMeasure OverallHeight;
  IfcPositiveLengthMeasure OverallWidth;
  IfcDoorTypeEnum PredefinedType;
  IfcDoorTypeOperationEnum OperationType;
  IfcLabel UserDefinedOperationType;
};

struct IfcDoorLiningProperties : IfcPreDefinedPropertySet {
  IfcPositiveLengthMeasure LiningDepth;
  IfcNonNegativeLengthMeasure LiningThickness;
  IfcPositiveLengthMeasure ThresholdDepth;
  IfcNonNegativeLengthMeasure ThresholdThickness;
  IfcNonNegativeLengthMeasure TransomThickness;
  IfcLengthMeasure TransomOffset;
  IfcLengthMeasure LiningOffset;
  IfcLengthMeasure ThresholdOffset;
  IfcPositiveLengthMeasure CasingThickness;
  IfcPositiveLengthMeasure CasingDepth;
  IfcShapeAspect ShapeAspectStyle;
  IfcLengthMeasure LiningToPanelOffsetX;
  IfcLengthMeasure LiningToPanelOffsetY;
};

struct IfcDoorPanelProperties : IfcPreDefinedPropertySet {
  IfcPositiveLengthMeasure PanelDepth;
  IfcDoorPanelOperationEnum PanelOperation;
  IfcNormalisedRatioMeasure PanelWidth;
  IfcDoorPanelPositionEnum PanelPosition;
  IfcShapeAspect ShapeAspectStyle;
};

struct IfcDoorStandardCase : IfcDoor {};

struct IfcDoorStyle : IfcTypeProduct {
  IfcDoorStyleOperationEnum OperationType;
  IfcDoorStyleConstructionEnum ConstructionType;
  IfcBoolean ParameterTakesPrecedence;
  IfcBoolean Sizeable;
};

struct IfcDoorType : IfcBuildingElementType {
  IfcDoorTypeEnum PredefinedType;
  IfcDoorTypeOperationEnum OperationType;
  IfcBoolean ParameterTakesPrecedence;
  IfcLabel UserDefinedOperationType;
};

struct IfcDraughtingPreDefinedColour : IfcPreDefinedColour {};

struct IfcDraughtingPreDefinedCurveFont : IfcPreDefinedCurveFont {};

struct IfcDuctFitting : IfcFlowFitting {
  IfcDuctFittingTypeEnum PredefinedType;
};

struct IfcDuctFittingType : IfcFlowFittingType {
  IfcDuctFittingTypeEnum PredefinedType;
};

struct IfcDuctSegment : IfcFlowSegment {
  IfcDuctSegmentTypeEnum PredefinedType;
};

struct IfcDuctSegmentType : IfcFlowSegmentType {
  IfcDuctSegmentTypeEnum PredefinedType;
};

struct IfcDuctSilencer : IfcFlowTreatmentDevice {
  IfcDuctSilencerTypeEnum PredefinedType;
};

struct IfcDuctSilencerType : IfcFlowTreatmentDeviceType {
  IfcDuctSilencerTypeEnum PredefinedType;
};

struct IfcEdge : IfcTopologicalRepresentationItem {
  IfcVertex EdgeStart;
  IfcVertex EdgeEnd;
};

struct IfcEdgeCurve : IfcEdge {
  IfcCurve EdgeGeometry;
  IfcBoolean SameSense;
};

struct IfcEdgeLoop : IfcLoop {
  SmallVector<IfcOrientedEdge, 4> EdgeList;
};

struct IfcElectricAppliance : IfcFlowTerminal {
  IfcElectricApplianceTypeEnum PredefinedType;
};

struct IfcElectricApplianceType : IfcFlowTerminalType {
  IfcElectricApplianceTypeEnum PredefinedType;
};

struct IfcElectricDistributionBoard : IfcFlowController {
  IfcElectricDistributionBoardTypeEnum PredefinedType;
};

struct IfcElectricDistributionBoardType : IfcFlowControllerType {
  IfcElectricDistributionBoardTypeEnum PredefinedType;
};

struct IfcElectricFlowStorageDevice : IfcFlowStorageDevice {
  IfcElectricFlowStorageDeviceTypeEnum PredefinedType;
};

struct IfcElectricFlowStorageDeviceType : IfcFlowStorageDeviceType {
  IfcElectricFlowStorageDeviceTypeEnum PredefinedType;
};

struct IfcElectricGenerator : IfcEnergyConversionDevice {
  IfcElectricGeneratorTypeEnum PredefinedType;
};

struct IfcElectricGeneratorType : IfcEnergyConversionDeviceType {
  IfcElectricGeneratorTypeEnum PredefinedType;
};

struct IfcElectricMotor : IfcEnergyConversionDevice {
  IfcElectricMotorTypeEnum PredefinedType;
};

struct IfcElectricMotorType : IfcEnergyConversionDeviceType {
  IfcElectricMotorTypeEnum PredefinedType;
};

struct IfcElectricTimeControl : IfcFlowController {
  IfcElectricTimeControlTypeEnum PredefinedType;
};

struct IfcElectricTimeControlType : IfcFlowControllerType {
  IfcElectricTimeControlTypeEnum PredefinedType;
};

struct IfcElement : IfcProduct {
  IfcIdentifier Tag;
};

struct IfcElementAssembly : IfcElement {
  IfcAssemblyPlaceEnum AssemblyPlace;
  IfcElementAssemblyTypeEnum PredefinedType;
};

struct IfcElementAssemblyType : IfcElementType {
  IfcElementAssemblyTypeEnum PredefinedType;
};

struct IfcElementComponent : IfcElement {};

struct IfcElementComponentType : IfcElementType {};

struct IfcElementQuantity : IfcQuantitySet {
  IfcLabel MethodOfMeasurement;
  std::unordered_set<IfcPhysicalQuantity> Quantities;
};

struct IfcElementType : IfcTypeProduct {
  IfcLabel ElementType;
};

struct IfcElementarySurface : IfcSurface {
  IfcAxis2Placement3D Position;
};

struct IfcEllipse : IfcConic {
  IfcPositiveLengthMeasure SemiAxis1;
  IfcPositiveLengthMeasure SemiAxis2;
};

struct IfcEllipseProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure SemiAxis1;
  IfcPositiveLengthMeasure SemiAxis2;
};

struct IfcEnergyConversionDevice : IfcDistributionFlowElement {};

struct IfcEnergyConversionDeviceType : IfcDistributionFlowElementType {};

struct IfcEngine : IfcEnergyConversionDevice {
  IfcEngineTypeEnum PredefinedType;
};

struct IfcEngineType : IfcEnergyConversionDeviceType {
  IfcEngineTypeEnum PredefinedType;
};

struct IfcEvaporativeCooler : IfcEnergyConversionDevice {
  IfcEvaporativeCoolerTypeEnum PredefinedType;
};

struct IfcEvaporativeCoolerType : IfcEnergyConversionDeviceType {
  IfcEvaporativeCoolerTypeEnum PredefinedType;
};

struct IfcEvaporator : IfcEnergyConversionDevice {
  IfcEvaporatorTypeEnum PredefinedType;
};

struct IfcEvaporatorType : IfcEnergyConversionDeviceType {
  IfcEvaporatorTypeEnum PredefinedType;
};

struct IfcEvent : IfcProcess {
  IfcEventTypeEnum PredefinedType;
  IfcEventTriggerTypeEnum EventTriggerType;
  IfcLabel UserDefinedEventTriggerType;
  IfcEventTime EventOccurenceTime;
};

struct IfcEventTime : IfcSchedulingTime {
  IfcDateTime ActualDate;
  IfcDateTime EarlyDate;
  IfcDateTime LateDate;
  IfcDateTime ScheduleDate;
};

struct IfcEventType : IfcTypeProcess {
  IfcEventTypeEnum PredefinedType;
  IfcEventTriggerTypeEnum EventTriggerType;
  IfcLabel UserDefinedEventTriggerType;
};

struct IfcExtendedProperties : IfcPropertyAbstraction {
  IfcIdentifier Name;
  IfcText Description;
  std::unordered_set<IfcProperty> Properties;
};

struct IfcExternalInformation : IfcEntity {};

struct IfcExternalReference : IfcEntity {
  IfcURIReference Location;
  IfcIdentifier Identification;
  IfcLabel Name;
};

struct IfcExternalReferenceRelationship : IfcResourceLevelRelationship {
  IfcExternalReference RelatingReference;
  std::unordered_set<IfcResourceObjectSelect> RelatedResourceObjects;
};

struct IfcExternalSpatialElement : IfcExternalSpatialStructureElement {
  IfcExternalSpatialElementTypeEnum PredefinedType;
};

struct IfcExternalSpatialStructureElement : IfcSpatialElement {};

struct IfcExternallyDefinedHatchStyle : IfcExternalReference {};

struct IfcExternallyDefinedSurfaceStyle : IfcExternalReference {};

struct IfcExternallyDefinedTextFont : IfcExternalReference {};

struct IfcExtrudedAreaSolid : IfcSweptAreaSolid {
  IfcDirection ExtrudedDirection;
  IfcPositiveLengthMeasure Depth;
};

struct IfcExtrudedAreaSolidTapered : IfcExtrudedAreaSolid {
  IfcProfileDef EndSweptArea;
};

struct IfcFace : IfcTopologicalRepresentationItem {
  std::unordered_set<IfcFaceBound> Bounds;
};

struct IfcFaceBasedSurfaceModel : IfcGeometricRepresentationItem {
  std::unordered_set<IfcConnectedFaceSet> FbsmFaces;
};

struct IfcFaceBound : IfcTopologicalRepresentationItem {
  IfcLoop Bound;
  IfcBoolean Orientation;
};

struct IfcFaceOuterBound : IfcFaceBound {};

struct IfcFaceSurface : IfcFace {
  IfcSurface FaceSurface;
  IfcBoolean SameSense;
};

struct IfcFacetedBrep : IfcManifoldSolidBrep {};

struct IfcFacetedBrepWithVoids : IfcFacetedBrep {
  std::unordered_set<IfcClosedShell> Voids;
};

struct IfcFailureConnectionCondition : IfcStructuralConnectionCondition {
  IfcForceMeasure TensionFailureX;
  IfcForceMeasure TensionFailureY;
  IfcForceMeasure TensionFailureZ;
  IfcForceMeasure CompressionFailureX;
  IfcForceMeasure CompressionFailureY;
  IfcForceMeasure CompressionFailureZ;
};

struct IfcFan : IfcFlowMovingDevice {
  IfcFanTypeEnum PredefinedType;
};

struct IfcFanType : IfcFlowMovingDeviceType {
  IfcFanTypeEnum PredefinedType;
};

struct IfcFastener : IfcElementComponent {
  IfcFastenerTypeEnum PredefinedType;
};

struct IfcFastenerType : IfcElementComponentType {
  IfcFastenerTypeEnum PredefinedType;
};

struct IfcFeatureElement : IfcElement {};

struct IfcFeatureElementAddition : IfcFeatureElement {};

struct IfcFeatureElementSubtraction : IfcFeatureElement {};

struct IfcFillAreaStyle : IfcPresentationStyle {
  std::unordered_set<IfcFillStyleSelect> FillStyles;
  IfcBoolean ModelorDraughting;
};

struct IfcFillAreaStyleHatching : IfcGeometricRepresentationItem {
  IfcCurveStyle HatchLineAppearance;
  IfcHatchLineDistanceSelect StartOfNextHatchLine;
  IfcCartesianPoint PointOfReferenceHatchLine;
  IfcCartesianPoint PatternStart;
  IfcPlaneAngleMeasure HatchLineAngle;
};

struct IfcFillAreaStyleTiles : IfcGeometricRepresentationItem {
  SmallVector<IfcVector, 2> TilingPattern;
  std::unordered_set<IfcStyledItem> Tiles;
  IfcPositiveRatioMeasure TilingScale;
};

struct IfcFilter : IfcFlowTreatmentDevice {
  IfcFilterTypeEnum PredefinedType;
};

struct IfcFilterType : IfcFlowTreatmentDeviceType {
  IfcFilterTypeEnum PredefinedType;
};

struct IfcFireSuppressionTerminal : IfcFlowTerminal {
  IfcFireSuppressionTerminalTypeEnum PredefinedType;
};

struct IfcFireSuppressionTerminalType : IfcFlowTerminalType {
  IfcFireSuppressionTerminalTypeEnum PredefinedType;
};

struct IfcFixedReferenceSweptAreaSolid : IfcSweptAreaSolid {
  IfcCurve Directrix;
  IfcParameterValue StartParam;
  IfcParameterValue EndParam;
  IfcDirection FixedReference;
};

struct IfcFlowController : IfcDistributionFlowElement {};

struct IfcFlowControllerType : IfcDistributionFlowElementType {};

struct IfcFlowFitting : IfcDistributionFlowElement {};

struct IfcFlowFittingType : IfcDistributionFlowElementType {};

struct IfcFlowInstrument : IfcDistributionControlElement {
  IfcFlowInstrumentTypeEnum PredefinedType;
};

struct IfcFlowInstrumentType : IfcDistributionControlElementType {
  IfcFlowInstrumentTypeEnum PredefinedType;
};

struct IfcFlowMeter : IfcFlowController {
  IfcFlowMeterTypeEnum PredefinedType;
};

struct IfcFlowMeterType : IfcFlowControllerType {
  IfcFlowMeterTypeEnum PredefinedType;
};

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

struct IfcFooting : IfcBuildingElement {
  IfcFootingTypeEnum PredefinedType;
};

struct IfcFootingType : IfcBuildingElementType {
  IfcFootingTypeEnum PredefinedType;
};

struct IfcFurnishingElement : IfcElement {};

struct IfcFurnishingElementType : IfcElementType {};

struct IfcFurniture : IfcFurnishingElement {
  IfcFurnitureTypeEnum PredefinedType;
};

struct IfcFurnitureType : IfcFurnishingElementType {
  IfcAssemblyPlaceEnum AssemblyPlace;
  IfcFurnitureTypeEnum PredefinedType;
};

struct IfcGeographicElement : IfcElement {
  IfcGeographicElementTypeEnum PredefinedType;
};

struct IfcGeographicElementType : IfcElementType {
  IfcGeographicElementTypeEnum PredefinedType;
};

struct IfcGeometricCurveSet : IfcGeometricSet {};

struct IfcGeometricRepresentationContext : IfcRepresentationContext {
  IfcDimensionCount CoordinateSpaceDimension;
  IfcReal Precision;
  IfcAxis2Placement WorldCoordinateSystem;
  IfcDirection TrueNorth;
};

struct IfcGeometricRepresentationItem : IfcRepresentationItem {};

struct IfcGeometricRepresentationSubContext : IfcGeometricRepresentationContext {
  IfcGeometricRepresentationContext ParentContext;
  IfcPositiveRatioMeasure TargetScale;
  IfcGeometricProjectionEnum TargetView;
  IfcLabel UserDefinedTargetView;
};

struct IfcGeometricSet : IfcGeometricRepresentationItem {
  std::unordered_set<IfcGeometricSetSelect> Elements;
};

struct IfcGrid : IfcPositioningElement {
  SmallVector<IfcGridAxis, 4> UAxes;
  SmallVector<IfcGridAxis, 4> VAxes;
  SmallVector<IfcGridAxis, 4> WAxes;
  IfcGridTypeEnum PredefinedType;
};

struct IfcGridAxis : IfcEntity {
  IfcLabel AxisTag;
  IfcCurve AxisCurve;
  IfcBoolean SameSense;
};

struct IfcGridPlacement : IfcObjectPlacement {
  IfcVirtualGridIntersection PlacementLocation;
  IfcGridPlacementDirectionSelect PlacementRefDirection;
};

struct IfcGroup : IfcObject {};

struct IfcHalfSpaceSolid : IfcGeometricRepresentationItem {
  IfcSurface BaseSurface;
  IfcBoolean AgreementFlag;
};

struct IfcHeatExchanger : IfcEnergyConversionDevice {
  IfcHeatExchangerTypeEnum PredefinedType;
};

struct IfcHeatExchangerType : IfcEnergyConversionDeviceType {
  IfcHeatExchangerTypeEnum PredefinedType;
};

struct IfcHumidifier : IfcEnergyConversionDevice {
  IfcHumidifierTypeEnum PredefinedType;
};

struct IfcHumidifierType : IfcEnergyConversionDeviceType {
  IfcHumidifierTypeEnum PredefinedType;
};

struct IfcIShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure OverallWidth;
  IfcPositiveLengthMeasure OverallDepth;
  IfcPositiveLengthMeasure WebThickness;
  IfcPositiveLengthMeasure FlangeThickness;
  IfcNonNegativeLengthMeasure FilletRadius;
  IfcNonNegativeLengthMeasure FlangeEdgeRadius;
  IfcPlaneAngleMeasure FlangeSlope;
};

struct IfcImageTexture : IfcSurfaceTexture {
  IfcURIReference URLReference;
};

struct IfcIndexedColourMap : IfcPresentationItem {
  IfcTessellatedFaceSet MappedTo;
  IfcNormalisedRatioMeasure Opacity;
  IfcColourRgbList Colours;
  SmallVector<IfcPositiveInteger, 4> ColourIndex;
};

struct IfcIndexedPolyCurve : IfcBoundedCurve {
  IfcCartesianPointList Points;
  SmallVector<IfcSegmentIndexSelect, 4> Segments;
  IfcBoolean SelfIntersect;
};

struct IfcIndexedPolygonalFace : IfcTessellatedItem {
  SmallVector<IfcPositiveInteger, 4> CoordIndex;
};

struct IfcIndexedPolygonalFaceWithVoids : IfcIndexedPolygonalFace {
  SmallVector<SmallVector<IfcPositiveInteger, 4>, 4> InnerCoordIndices;
};

struct IfcIndexedTextureMap : IfcTextureCoordinate {
  IfcTessellatedFaceSet MappedTo;
  IfcTextureVertexList TexCoords;
};

struct IfcIndexedTriangleTextureMap : IfcIndexedTextureMap {
  SmallVector<SmallVector<IfcPositiveInteger, 3>, 4> TexCoordIndex;
};

struct IfcInterceptor : IfcFlowTreatmentDevice {
  IfcInterceptorTypeEnum PredefinedType;
};

struct IfcInterceptorType : IfcFlowTreatmentDeviceType {
  IfcInterceptorTypeEnum PredefinedType;
};

struct IfcIntersectionCurve : IfcSurfaceCurve {};

struct IfcInventory : IfcGroup {
  IfcInventoryTypeEnum PredefinedType;
  IfcActorSelect Jurisdiction;
  std::unordered_set<IfcPerson> ResponsiblePersons;
  IfcDate LastUpdateDate;
  IfcCostValue CurrentValue;
  IfcCostValue OriginalValue;
};

struct IfcIrregularTimeSeries : IfcTimeSeries {
  SmallVector<IfcIrregularTimeSeriesValue, 4> Values;
};

struct IfcIrregularTimeSeriesValue : IfcEntity {
  IfcDateTime TimeStamp;
  SmallVector<IfcValue, 4> ListValues;
};

struct IfcJunctionBox : IfcFlowFitting {
  IfcJunctionBoxTypeEnum PredefinedType;
};

struct IfcJunctionBoxType : IfcFlowFittingType {
  IfcJunctionBoxTypeEnum PredefinedType;
};

struct IfcLShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure Depth;
  IfcPositiveLengthMeasure Width;
  IfcPositiveLengthMeasure Thickness;
  IfcNonNegativeLengthMeasure FilletRadius;
  IfcNonNegativeLengthMeasure EdgeRadius;
  IfcPlaneAngleMeasure LegSlope;
};

struct IfcLaborResource : IfcConstructionResource {
  IfcLaborResourceTypeEnum PredefinedType;
};

struct IfcLaborResourceType : IfcConstructionResourceType {
  IfcLaborResourceTypeEnum PredefinedType;
};

struct IfcLagTime : IfcSchedulingTime {
  IfcTimeOrRatioSelect LagValue;
  IfcTaskDurationEnum DurationType;
};

struct IfcLamp : IfcFlowTerminal {
  IfcLampTypeEnum PredefinedType;
};

struct IfcLampType : IfcFlowTerminalType {
  IfcLampTypeEnum PredefinedType;
};

struct IfcLibraryInformation : IfcExternalInformation {
  IfcLabel Name;
  IfcLabel Version;
  IfcActorSelect Publisher;
  IfcDateTime VersionDate;
  IfcURIReference Location;
  IfcText Description;
};

struct IfcLibraryReference : IfcExternalReference {
  IfcText Description;
  IfcLanguageId Language;
  IfcLibraryInformation ReferencedLibrary;
};

struct IfcLightDistributionData : IfcEntity {
  IfcPlaneAngleMeasure MainPlaneAngle;
  SmallVector<IfcPlaneAngleMeasure, 4> SecondaryPlaneAngle;
  SmallVector<IfcLuminousIntensityDistributionMeasure, 4> LuminousIntensity;
};

struct IfcLightFixture : IfcFlowTerminal {
  IfcLightFixtureTypeEnum PredefinedType;
};

struct IfcLightFixtureType : IfcFlowTerminalType {
  IfcLightFixtureTypeEnum PredefinedType;
};

struct IfcLightIntensityDistribution : IfcEntity {
  IfcLightDistributionCurveEnum LightDistributionCurve;
  SmallVector<IfcLightDistributionData, 4> DistributionData;
};

struct IfcLightSource : IfcGeometricRepresentationItem {
  IfcLabel Name;
  IfcColourRgb LightColour;
  IfcNormalisedRatioMeasure AmbientIntensity;
  IfcNormalisedRatioMeasure Intensity;
};

struct IfcLightSourceAmbient : IfcLightSource {};

struct IfcLightSourceDirectional : IfcLightSource {
  IfcDirection Orientation;
};

struct IfcLightSourceGoniometric : IfcLightSource {
  IfcAxis2Placement3D Position;
  IfcColourRgb ColourAppearance;
  IfcThermodynamicTemperatureMeasure ColourTemperature;
  IfcLuminousFluxMeasure LuminousFlux;
  IfcLightEmissionSourceEnum LightEmissionSource;
  IfcLightDistributionDataSourceSelect LightDistributionDataSource;
};

struct IfcLightSourcePositional : IfcLightSource {
  IfcCartesianPoint Position;
  IfcPositiveLengthMeasure Radius;
  IfcReal ConstantAttenuation;
  IfcReal DistanceAttenuation;
  IfcReal QuadricAttenuation;
};

struct IfcLightSourceSpot : IfcLightSourcePositional {
  IfcDirection Orientation;
  IfcReal ConcentrationExponent;
  IfcPositivePlaneAngleMeasure SpreadAngle;
  IfcPositivePlaneAngleMeasure BeamWidthAngle;
};

struct IfcLine : IfcCurve {
  IfcCartesianPoint Pnt;
  IfcVector Dir;
};

struct IfcLineSegment2D : IfcCurveSegment2D {};

struct IfcLinearPlacement : IfcObjectPlacement {
  IfcCurve PlacementRelTo;
  IfcDistanceExpression Distance;
  IfcOrientationExpression Orientation;
  IfcAxis2Placement3D CartesianPosition;
};

struct IfcLinearPositioningElement : IfcPositioningElement {
  IfcCurve Axis;
};

struct IfcLocalPlacement : IfcObjectPlacement {
  IfcObjectPlacement PlacementRelTo;
  IfcAxis2Placement RelativePlacement;
};

struct IfcLoop : IfcTopologicalRepresentationItem {};

struct IfcManifoldSolidBrep : IfcSolidModel {
  IfcClosedShell Outer;
};

struct IfcMapConversion : IfcCoordinateOperation {
  IfcLengthMeasure Eastings;
  IfcLengthMeasure Northings;
  IfcLengthMeasure OrthogonalHeight;
  IfcReal XAxisAbscissa;
  IfcReal XAxisOrdinate;
  IfcReal Scale;
};

struct IfcMappedItem : IfcRepresentationItem {
  IfcRepresentationMap MappingSource;
  IfcCartesianTransformationOperator MappingTarget;
};

struct IfcMaterial : IfcMaterialDefinition {
  IfcLabel Name;
  IfcText Description;
  IfcLabel Category;
};

struct IfcMaterialClassificationRelationship : IfcEntity {
  std::unordered_set<IfcClassificationSelect> MaterialClassifications;
  IfcMaterial ClassifiedMaterial;
};

struct IfcMaterialConstituent : IfcMaterialDefinition {
  IfcLabel Name;
  IfcText Description;
  IfcMaterial Material;
  IfcNormalisedRatioMeasure Fraction;
  IfcLabel Category;
};

struct IfcMaterialConstituentSet : IfcMaterialDefinition {
  IfcLabel Name;
  IfcText Description;
  std::unordered_set<IfcMaterialConstituent> MaterialConstituents;
};

struct IfcMaterialDefinition : IfcEntity {};

struct IfcMaterialDefinitionRepresentation : IfcProductRepresentation {
  IfcMaterial RepresentedMaterial;
};

struct IfcMaterialLayer : IfcMaterialDefinition {
  IfcMaterial Material;
  IfcNonNegativeLengthMeasure LayerThickness;
  IfcLogical IsVentilated;
  IfcLabel Name;
  IfcText Description;
  IfcLabel Category;
  IfcInteger Priority;
};

struct IfcMaterialLayerSet : IfcMaterialDefinition {
  SmallVector<IfcMaterialLayer, 4> MaterialLayers;
  IfcLabel LayerSetName;
  IfcText Description;
};

struct IfcMaterialLayerSetUsage : IfcMaterialUsageDefinition {
  IfcMaterialLayerSet ForLayerSet;
  IfcLayerSetDirectionEnum LayerSetDirection;
  IfcDirectionSenseEnum DirectionSense;
  IfcLengthMeasure OffsetFromReferenceLine;
  IfcPositiveLengthMeasure ReferenceExtent;
};

struct IfcMaterialLayerWithOffsets : IfcMaterialLayer {
  IfcLayerSetDirectionEnum OffsetDirection;
  SmallVector<IfcLengthMeasure, 2> OffsetValues;
};

struct IfcMaterialList : IfcEntity {
  SmallVector<IfcMaterial, 4> Materials;
};

struct IfcMaterialProfile : IfcMaterialDefinition {
  IfcLabel Name;
  IfcText Description;
  IfcMaterial Material;
  IfcProfileDef Profile;
  IfcInteger Priority;
  IfcLabel Category;
};

struct IfcMaterialProfileSet : IfcMaterialDefinition {
  IfcLabel Name;
  IfcText Description;
  SmallVector<IfcMaterialProfile, 4> MaterialProfiles;
  IfcCompositeProfileDef CompositeProfile;
};

struct IfcMaterialProfileSetUsage : IfcMaterialUsageDefinition {
  IfcMaterialProfileSet ForProfileSet;
  IfcCardinalPointReference CardinalPoint;
  IfcPositiveLengthMeasure ReferenceExtent;
};

struct IfcMaterialProfileSetUsageTapering : IfcMaterialProfileSetUsage {
  IfcMaterialProfileSet ForProfileEndSet;
  IfcCardinalPointReference CardinalEndPoint;
};

struct IfcMaterialProfileWithOffsets : IfcMaterialProfile {
  SmallVector<IfcLengthMeasure, 2> OffsetValues;
};

struct IfcMaterialProperties : IfcExtendedProperties {
  IfcMaterialDefinition Material;
};

struct IfcMaterialRelationship : IfcResourceLevelRelationship {
  IfcMaterial RelatingMaterial;
  std::unordered_set<IfcMaterial> RelatedMaterials;
  IfcLabel Expression;
};

struct IfcMaterialUsageDefinition : IfcEntity {};

struct IfcMeasureWithUnit : IfcEntity {
  IfcValue ValueComponent;
  IfcUnit UnitComponent;
};

struct IfcMechanicalFastener : IfcElementComponent {
  IfcPositiveLengthMeasure NominalDiameter;
  IfcPositiveLengthMeasure NominalLength;
  IfcMechanicalFastenerTypeEnum PredefinedType;
};

struct IfcMechanicalFastenerType : IfcElementComponentType {
  IfcMechanicalFastenerTypeEnum PredefinedType;
  IfcPositiveLengthMeasure NominalDiameter;
  IfcPositiveLengthMeasure NominalLength;
};

struct IfcMedicalDevice : IfcFlowTerminal {
  IfcMedicalDeviceTypeEnum PredefinedType;
};

struct IfcMedicalDeviceType : IfcFlowTerminalType {
  IfcMedicalDeviceTypeEnum PredefinedType;
};

struct IfcMember : IfcBuildingElement {
  IfcMemberTypeEnum PredefinedType;
};

struct IfcMemberStandardCase : IfcMember {};

struct IfcMemberType : IfcBuildingElementType {
  IfcMemberTypeEnum PredefinedType;
};

struct IfcMetric : IfcConstraint {
  IfcBenchmarkEnum Benchmark;
  IfcLabel ValueSource;
  IfcMetricValueSelect DataValue;
  IfcReference ReferencePath;
};

struct IfcMirroredProfileDef : IfcDerivedProfileDef {};

struct IfcMonetaryUnit : IfcEntity {
  IfcLabel Currency;
};

struct IfcMotorConnection : IfcEnergyConversionDevice {
  IfcMotorConnectionTypeEnum PredefinedType;
};

struct IfcMotorConnectionType : IfcEnergyConversionDeviceType {
  IfcMotorConnectionTypeEnum PredefinedType;
};

struct IfcNamedUnit : IfcEntity {
  IfcDimensionalExponents Dimensions;
  IfcUnitEnum UnitType;
};

struct IfcObject : IfcObjectDefinition {
  IfcLabel ObjectType;
};

struct IfcObjectDefinition : IfcRoot {};

struct IfcObjectPlacement : IfcEntity {};

struct IfcObjective : IfcConstraint {
  SmallVector<IfcConstraint, 4> BenchmarkValues;
  IfcLogicalOperatorEnum LogicalAggregator;
  IfcObjectiveEnum ObjectiveQualifier;
  IfcLabel UserDefinedQualifier;
};

struct IfcOccupant : IfcActor {
  IfcOccupantTypeEnum PredefinedType;
};

struct IfcOffsetCurve : IfcCurve {
  IfcCurve BasisCurve;
};

struct IfcOffsetCurve2D : IfcOffsetCurve {
  IfcLengthMeasure Distance;
  IfcLogical SelfIntersect;
};

struct IfcOffsetCurve3D : IfcOffsetCurve {
  IfcLengthMeasure Distance;
  IfcLogical SelfIntersect;
  IfcDirection RefDirection;
};

struct IfcOffsetCurveByDistances : IfcOffsetCurve {
  SmallVector<IfcDistanceExpression, 4> OffsetValues;
  IfcLabel Tag;
};

struct IfcOpenShell : IfcConnectedFaceSet {};

struct IfcOpeningElement : IfcFeatureElementSubtraction {
  IfcOpeningElementTypeEnum PredefinedType;
};

struct IfcOpeningStandardCase : IfcOpeningElement {};

struct IfcOrganization : IfcEntity {
  IfcIdentifier Identification;
  IfcLabel Name;
  IfcText Description;
  SmallVector<IfcActorRole, 4> Roles;
  SmallVector<IfcAddress, 4> Addresses;
};

struct IfcOrganizationRelationship : IfcResourceLevelRelationship {
  IfcOrganization RelatingOrganization;
  std::unordered_set<IfcOrganization> RelatedOrganizations;
};

struct IfcOrientationExpression : IfcGeometricRepresentationItem {
  IfcDirection LateralAxisDirection;
  IfcDirection VerticalAxisDirection;
};

struct IfcOrientedEdge : IfcEdge {
  IfcEdge EdgeElement;
  IfcBoolean Orientation;
};

struct IfcOuterBoundaryCurve : IfcBoundaryCurve {};

struct IfcOutlet : IfcFlowTerminal {
  IfcOutletTypeEnum PredefinedType;
};

struct IfcOutletType : IfcFlowTerminalType {
  IfcOutletTypeEnum PredefinedType;
};

struct IfcOwnerHistory : IfcEntity {
  IfcPersonAndOrganization OwningUser;
  IfcApplication OwningApplication;
  IfcStateEnum State;
  IfcChangeActionEnum ChangeAction;
  IfcTimeStamp LastModifiedDate;
  IfcPersonAndOrganization LastModifyingUser;
  IfcApplication LastModifyingApplication;
  IfcTimeStamp CreationDate;
};

struct IfcParameterizedProfileDef : IfcProfileDef {
  IfcAxis2Placement2D Position;
};

struct IfcPath : IfcTopologicalRepresentationItem {
  SmallVector<IfcOrientedEdge, 4> EdgeList;
};

struct IfcPcurve : IfcCurve {
  IfcSurface BasisSurface;
  IfcCurve ReferenceCurve;
};

struct IfcPerformanceHistory : IfcControl {
  IfcLabel LifeCyclePhase;
  IfcPerformanceHistoryTypeEnum PredefinedType;
};

struct IfcPermeableCoveringProperties : IfcPreDefinedPropertySet {
  IfcPermeableCoveringOperationEnum OperationType;
  IfcWindowPanelPositionEnum PanelPosition;
  IfcPositiveLengthMeasure FrameDepth;
  IfcPositiveLengthMeasure FrameThickness;
  IfcShapeAspect ShapeAspectStyle;
};

struct IfcPermit : IfcControl {
  IfcPermitTypeEnum PredefinedType;
  IfcLabel Status;
  IfcText LongDescription;
};

struct IfcPerson : IfcEntity {
  IfcIdentifier Identification;
  IfcLabel FamilyName;
  IfcLabel GivenName;
  SmallVector<IfcLabel, 4> MiddleNames;
  SmallVector<IfcLabel, 4> PrefixTitles;
  SmallVector<IfcLabel, 4> SuffixTitles;
  SmallVector<IfcActorRole, 4> Roles;
  SmallVector<IfcAddress, 4> Addresses;
};

struct IfcPersonAndOrganization : IfcEntity {
  IfcPerson ThePerson;
  IfcOrganization TheOrganization;
  SmallVector<IfcActorRole, 4> Roles;
};

struct IfcPhysicalComplexQuantity : IfcPhysicalQuantity {
  std::unordered_set<IfcPhysicalQuantity> HasQuantities;
  IfcLabel Discrimination;
  IfcLabel Quality;
  IfcLabel Usage;
};

struct IfcPhysicalQuantity : IfcEntity {
  IfcLabel Name;
  IfcText Description;
};

struct IfcPhysicalSimpleQuantity : IfcPhysicalQuantity {
  IfcNamedUnit Unit;
};

struct IfcPile : IfcBuildingElement {
  IfcPileTypeEnum PredefinedType;
  IfcPileConstructionEnum ConstructionType;
};

struct IfcPileType : IfcBuildingElementType {
  IfcPileTypeEnum PredefinedType;
};

struct IfcPipeFitting : IfcFlowFitting {
  IfcPipeFittingTypeEnum PredefinedType;
};

struct IfcPipeFittingType : IfcFlowFittingType {
  IfcPipeFittingTypeEnum PredefinedType;
};

struct IfcPipeSegment : IfcFlowSegment {
  IfcPipeSegmentTypeEnum PredefinedType;
};

struct IfcPipeSegmentType : IfcFlowSegmentType {
  IfcPipeSegmentTypeEnum PredefinedType;
};

struct IfcPixelTexture : IfcSurfaceTexture {
  IfcInteger Width;
  IfcInteger Height;
  IfcInteger ColourComponents;
  SmallVector<IfcBinary, 4> Pixel;
};

struct IfcPlacement : IfcGeometricRepresentationItem {
  IfcCartesianPoint Location;
};

struct IfcPlanarBox : IfcPlanarExtent {
  IfcAxis2Placement Placement;
};

struct IfcPlanarExtent : IfcGeometricRepresentationItem {
  IfcLengthMeasure SizeInX;
  IfcLengthMeasure SizeInY;
};

struct IfcPlane : IfcElementarySurface {};

struct IfcPlate : IfcBuildingElement {
  IfcPlateTypeEnum PredefinedType;
};

struct IfcPlateStandardCase : IfcPlate {};

struct IfcPlateType : IfcBuildingElementType {
  IfcPlateTypeEnum PredefinedType;
};

struct IfcPoint : IfcGeometricRepresentationItem {};

struct IfcPointOnCurve : IfcPoint {
  IfcCurve BasisCurve;
  IfcParameterValue PointParameter;
};

struct IfcPointOnSurface : IfcPoint {
  IfcSurface BasisSurface;
  IfcParameterValue PointParameterU;
  IfcParameterValue PointParameterV;
};

struct IfcPolyLoop : IfcLoop {
  SmallVector<IfcCartesianPoint, 4> Polygon;
};

struct IfcPolygonalBoundedHalfSpace : IfcHalfSpaceSolid {
  IfcAxis2Placement3D Position;
  IfcBoundedCurve PolygonalBoundary;
};

struct IfcPolygonalFaceSet : IfcTessellatedFaceSet {
  IfcBoolean Closed;
  SmallVector<IfcIndexedPolygonalFace, 4> Faces;
  SmallVector<IfcPositiveInteger, 4> PnIndex;
};

struct IfcPolyline : IfcBoundedCurve {
  SmallVector<IfcCartesianPoint, 4> Points;
};

struct IfcPort : IfcProduct {};

struct IfcPositioningElement : IfcProduct {};

struct IfcPostalAddress : IfcAddress {
  IfcLabel InternalLocation;
  SmallVector<IfcLabel, 4> AddressLines;
  IfcLabel PostalBox;
  IfcLabel Town;
  IfcLabel Region;
  IfcLabel PostalCode;
  IfcLabel Country;
};

struct IfcPreDefinedColour : IfcPreDefinedItem {};

struct IfcPreDefinedCurveFont : IfcPreDefinedItem {};

struct IfcPreDefinedItem : IfcPresentationItem {
  IfcLabel Name;
};

struct IfcPreDefinedProperties : IfcPropertyAbstraction {};

struct IfcPreDefinedPropertySet : IfcPropertySetDefinition {};

struct IfcPreDefinedTextFont : IfcPreDefinedItem {};

struct IfcPresentationItem : IfcEntity {};

struct IfcPresentationLayerAssignment : IfcEntity {
  IfcLabel Name;
  IfcText Description;
  std::unordered_set<IfcLayeredItem> AssignedItems;
  IfcIdentifier Identifier;
};

struct IfcPresentationLayerWithStyle : IfcPresentationLayerAssignment {
  IfcLogical LayerOn;
  IfcLogical LayerFrozen;
  IfcLogical LayerBlocked;
  std::unordered_set<IfcPresentationStyle> LayerStyles;
};

struct IfcPresentationStyle : IfcEntity {
  IfcLabel Name;
};

struct IfcPresentationStyleAssignment : IfcEntity {
  std::unordered_set<IfcPresentationStyleSelect> Styles;
};

struct IfcProcedure : IfcProcess {
  IfcProcedureTypeEnum PredefinedType;
};

struct IfcProcedureType : IfcTypeProcess {
  IfcProcedureTypeEnum PredefinedType;
};

struct IfcProcess : IfcObject {
  IfcIdentifier Identification;
  IfcText LongDescription;
};

struct IfcProduct : IfcObject {
  IfcObjectPlacement ObjectPlacement;
  IfcProductRepresentation Representation;
};

struct IfcProductDefinitionShape : IfcProductRepresentation {};

struct IfcProductRepresentation : IfcEntity {
  IfcLabel Name;
  IfcText Description;
  SmallVector<IfcRepresentation, 4> Representations;
};

struct IfcProfileDef : IfcEntity {
  IfcProfileTypeEnum ProfileType;
  IfcLabel ProfileName;
};

struct IfcProfileProperties : IfcExtendedProperties {
  IfcProfileDef ProfileDefinition;
};

struct IfcProject : IfcContext {};

struct IfcProjectLibrary : IfcContext {};

struct IfcProjectOrder : IfcControl {
  IfcProjectOrderTypeEnum PredefinedType;
  IfcLabel Status;
  IfcText LongDescription;
};

struct IfcProjectedCRS : IfcCoordinateReferenceSystem {
  IfcIdentifier MapProjection;
  IfcIdentifier MapZone;
  IfcNamedUnit MapUnit;
};

struct IfcProjectionElement : IfcFeatureElementAddition {
  IfcProjectionElementTypeEnum PredefinedType;
};

struct IfcProperty : IfcPropertyAbstraction {
  IfcIdentifier Name;
  IfcText Description;
};

struct IfcPropertyAbstraction : IfcEntity {};

struct IfcPropertyBoundedValue : IfcSimpleProperty {
  IfcValue UpperBoundValue;
  IfcValue LowerBoundValue;
  IfcUnit Unit;
  IfcValue SetPointValue;
};

struct IfcPropertyDefinition : IfcRoot {};

struct IfcPropertyDependencyRelationship : IfcResourceLevelRelationship {
  IfcProperty DependingProperty;
  IfcProperty DependantProperty;
  IfcText Expression;
};

struct IfcPropertyEnumeratedValue : IfcSimpleProperty {
  SmallVector<IfcValue, 4> EnumerationValues;
  IfcPropertyEnumeration EnumerationReference;
};

struct IfcPropertyEnumeration : IfcPropertyAbstraction {
  IfcLabel Name;
  SmallVector<IfcValue, 4> EnumerationValues;
  IfcUnit Unit;
};

struct IfcPropertyListValue : IfcSimpleProperty {
  SmallVector<IfcValue, 4> ListValues;
  IfcUnit Unit;
};

struct IfcPropertyReferenceValue : IfcSimpleProperty {
  IfcText UsageName;
  IfcObjectReferenceSelect PropertyReference;
};

struct IfcPropertySet : IfcPropertySetDefinition {
  std::unordered_set<IfcProperty> HasProperties;
};

struct IfcPropertySetDefinition : IfcPropertyDefinition {};

struct IfcPropertySetTemplate : IfcPropertyTemplateDefinition {
  IfcPropertySetTemplateTypeEnum TemplateType;
  IfcIdentifier ApplicableEntity;
  std::unordered_set<IfcPropertyTemplate> HasPropertyTemplates;
};

struct IfcPropertySingleValue : IfcSimpleProperty {
  IfcValue NominalValue;
  IfcUnit Unit;
};

struct IfcPropertyTableValue : IfcSimpleProperty {
  SmallVector<IfcValue, 4> DefiningValues;
  SmallVector<IfcValue, 4> DefinedValues;
  IfcText Expression;
  IfcUnit DefiningUnit;
  IfcUnit DefinedUnit;
  IfcCurveInterpolationEnum CurveInterpolation;
};

struct IfcPropertyTemplate : IfcPropertyTemplateDefinition {};

struct IfcPropertyTemplateDefinition : IfcPropertyDefinition {};

struct IfcProtectiveDevice : IfcFlowController {
  IfcProtectiveDeviceTypeEnum PredefinedType;
};

struct IfcProtectiveDeviceTrippingUnit : IfcDistributionControlElement {
  IfcProtectiveDeviceTrippingUnitTypeEnum PredefinedType;
};

struct IfcProtectiveDeviceTrippingUnitType : IfcDistributionControlElementType {
  IfcProtectiveDeviceTrippingUnitTypeEnum PredefinedType;
};

struct IfcProtectiveDeviceType : IfcFlowControllerType {
  IfcProtectiveDeviceTypeEnum PredefinedType;
};

struct IfcProxy : IfcProduct {
  IfcObjectTypeEnum ProxyType;
  IfcLabel Tag;
};

struct IfcPump : IfcFlowMovingDevice {
  IfcPumpTypeEnum PredefinedType;
};

struct IfcPumpType : IfcFlowMovingDeviceType {
  IfcPumpTypeEnum PredefinedType;
};

struct IfcQuantityArea : IfcPhysicalSimpleQuantity {
  IfcAreaMeasure AreaValue;
  IfcLabel Formula;
};

struct IfcQuantityCount : IfcPhysicalSimpleQuantity {
  IfcCountMeasure CountValue;
  IfcLabel Formula;
};

struct IfcQuantityLength : IfcPhysicalSimpleQuantity {
  IfcLengthMeasure LengthValue;
  IfcLabel Formula;
};

struct IfcQuantitySet : IfcPropertySetDefinition {};

struct IfcQuantityTime : IfcPhysicalSimpleQuantity {
  IfcTimeMeasure TimeValue;
  IfcLabel Formula;
};

struct IfcQuantityVolume : IfcPhysicalSimpleQuantity {
  IfcVolumeMeasure VolumeValue;
  IfcLabel Formula;
};

struct IfcQuantityWeight : IfcPhysicalSimpleQuantity {
  IfcMassMeasure WeightValue;
  IfcLabel Formula;
};

struct IfcRailing : IfcBuildingElement {
  IfcRailingTypeEnum PredefinedType;
};

struct IfcRailingType : IfcBuildingElementType {
  IfcRailingTypeEnum PredefinedType;
};

struct IfcRamp : IfcBuildingElement {
  IfcRampTypeEnum PredefinedType;
};

struct IfcRampFlight : IfcBuildingElement {
  IfcRampFlightTypeEnum PredefinedType;
};

struct IfcRampFlightType : IfcBuildingElementType {
  IfcRampFlightTypeEnum PredefinedType;
};

struct IfcRampType : IfcBuildingElementType {
  IfcRampTypeEnum PredefinedType;
};

struct IfcRationalBSplineCurveWithKnots : IfcBSplineCurveWithKnots {
  SmallVector<IfcReal, 4> WeightsData;
};

struct IfcRationalBSplineSurfaceWithKnots : IfcBSplineSurfaceWithKnots {
  SmallVector<SmallVector<IfcReal, 4>, 4> WeightsData;
};

struct IfcRectangleHollowProfileDef : IfcRectangleProfileDef {
  IfcPositiveLengthMeasure WallThickness;
  IfcNonNegativeLengthMeasure InnerFilletRadius;
  IfcNonNegativeLengthMeasure OuterFilletRadius;
};

struct IfcRectangleProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure XDim;
  IfcPositiveLengthMeasure YDim;
};

struct IfcRectangularPyramid : IfcCsgPrimitive3D {
  IfcPositiveLengthMeasure XLength;
  IfcPositiveLengthMeasure YLength;
  IfcPositiveLengthMeasure Height;
};

struct IfcRectangularTrimmedSurface : IfcBoundedSurface {
  IfcSurface BasisSurface;
  IfcParameterValue U1;
  IfcParameterValue V1;
  IfcParameterValue U2;
  IfcParameterValue V2;
  IfcBoolean Usense;
  IfcBoolean Vsense;
};

struct IfcRecurrencePattern : IfcEntity {
  IfcRecurrenceTypeEnum RecurrenceType;
  std::unordered_set<IfcDayInMonthNumber> DayComponent;
  std::unordered_set<IfcDayInWeekNumber> WeekdayComponent;
  std::unordered_set<IfcMonthInYearNumber> MonthComponent;
  IfcInteger Position;
  IfcInteger Interval;
  IfcInteger Occurrences;
  SmallVector<IfcTimePeriod, 4> TimePeriods;
};

struct IfcReference : IfcEntity {
  IfcIdentifier TypeIdentifier;
  IfcIdentifier AttributeIdentifier;
  IfcLabel InstanceName;
  SmallVector<IfcInteger, 4> ListPositions;
  IfcReference InnerReference;
};

struct IfcReferent : IfcPositioningElement {
  IfcReferentTypeEnum PredefinedType;
  IfcLengthMeasure RestartDistance;
};

struct IfcRegularTimeSeries : IfcTimeSeries {
  IfcTimeMeasure TimeStep;
  SmallVector<IfcTimeSeriesValue, 4> Values;
};

struct IfcReinforcementBarProperties : IfcPreDefinedProperties {
  IfcAreaMeasure TotalCrossSectionArea;
  IfcLabel SteelGrade;
  IfcReinforcingBarSurfaceEnum BarSurface;
  IfcLengthMeasure EffectiveDepth;
  IfcPositiveLengthMeasure NominalBarDiameter;
  IfcCountMeasure BarCount;
};

struct IfcReinforcementDefinitionProperties : IfcPreDefinedPropertySet {
  IfcLabel DefinitionType;
  SmallVector<IfcSectionReinforcementProperties, 4> ReinforcementSectionDefinitions;
};

struct IfcReinforcingBar : IfcReinforcingElement {
  IfcPositiveLengthMeasure NominalDiameter;
  IfcAreaMeasure CrossSectionArea;
  IfcPositiveLengthMeasure BarLength;
  IfcReinforcingBarTypeEnum PredefinedType;
  IfcReinforcingBarSurfaceEnum BarSurface;
};

struct IfcReinforcingBarType : IfcReinforcingElementType {
  IfcReinforcingBarTypeEnum PredefinedType;
  IfcPositiveLengthMeasure NominalDiameter;
  IfcAreaMeasure CrossSectionArea;
  IfcPositiveLengthMeasure BarLength;
  IfcReinforcingBarSurfaceEnum BarSurface;
  IfcLabel BendingShapeCode;
  SmallVector<IfcBendingParameterSelect, 4> BendingParameters;
};

struct IfcReinforcingElement : IfcElementComponent {
  IfcLabel SteelGrade;
};

struct IfcReinforcingElementType : IfcElementComponentType {};

struct IfcReinforcingMesh : IfcReinforcingElement {
  IfcPositiveLengthMeasure MeshLength;
  IfcPositiveLengthMeasure MeshWidth;
  IfcPositiveLengthMeasure LongitudinalBarNominalDiameter;
  IfcPositiveLengthMeasure TransverseBarNominalDiameter;
  IfcAreaMeasure LongitudinalBarCrossSectionArea;
  IfcAreaMeasure TransverseBarCrossSectionArea;
  IfcPositiveLengthMeasure LongitudinalBarSpacing;
  IfcPositiveLengthMeasure TransverseBarSpacing;
  IfcReinforcingMeshTypeEnum PredefinedType;
};

struct IfcReinforcingMeshType : IfcReinforcingElementType {
  IfcReinforcingMeshTypeEnum PredefinedType;
  IfcPositiveLengthMeasure MeshLength;
  IfcPositiveLengthMeasure MeshWidth;
  IfcPositiveLengthMeasure LongitudinalBarNominalDiameter;
  IfcPositiveLengthMeasure TransverseBarNominalDiameter;
  IfcAreaMeasure LongitudinalBarCrossSectionArea;
  IfcAreaMeasure TransverseBarCrossSectionArea;
  IfcPositiveLengthMeasure LongitudinalBarSpacing;
  IfcPositiveLengthMeasure TransverseBarSpacing;
  IfcLabel BendingShapeCode;
  SmallVector<IfcBendingParameterSelect, 4> BendingParameters;
};

struct IfcRelAggregates : IfcRelDecomposes {
  IfcObjectDefinition RelatingObject;
  std::unordered_set<IfcObjectDefinition> RelatedObjects;
};

struct IfcRelAssigns : IfcRelationship {
  std::unordered_set<IfcObjectDefinition> RelatedObjects;
  IfcObjectTypeEnum RelatedObjectsType;
};

struct IfcRelAssignsToActor : IfcRelAssigns {
  IfcActor RelatingActor;
  IfcActorRole ActingRole;
};

struct IfcRelAssignsToControl : IfcRelAssigns {
  IfcControl RelatingControl;
};

struct IfcRelAssignsToGroup : IfcRelAssigns {
  IfcGroup RelatingGroup;
};

struct IfcRelAssignsToGroupByFactor : IfcRelAssignsToGroup {
  IfcRatioMeasure Factor;
};

struct IfcRelAssignsToProcess : IfcRelAssigns {
  IfcProcessSelect RelatingProcess;
  IfcMeasureWithUnit QuantityInProcess;
};

struct IfcRelAssignsToProduct : IfcRelAssigns {
  IfcProductSelect RelatingProduct;
};

struct IfcRelAssignsToResource : IfcRelAssigns {
  IfcResourceSelect RelatingResource;
};

struct IfcRelAssociates : IfcRelationship {
  std::unordered_set<IfcDefinitionSelect> RelatedObjects;
};

struct IfcRelAssociatesApproval : IfcRelAssociates {
  IfcApproval RelatingApproval;
};

struct IfcRelAssociatesClassification : IfcRelAssociates {
  IfcClassificationSelect RelatingClassification;
};

struct IfcRelAssociatesConstraint : IfcRelAssociates {
  IfcLabel Intent;
  IfcConstraint RelatingConstraint;
};

struct IfcRelAssociatesDocument : IfcRelAssociates {
  IfcDocumentSelect RelatingDocument;
};

struct IfcRelAssociatesLibrary : IfcRelAssociates {
  IfcLibrarySelect RelatingLibrary;
};

struct IfcRelAssociatesMaterial : IfcRelAssociates {
  IfcMaterialSelect RelatingMaterial;
};

struct IfcRelConnects : IfcRelationship {};

struct IfcRelConnectsElements : IfcRelConnects {
  IfcConnectionGeometry ConnectionGeometry;
  IfcElement RelatingElement;
  IfcElement RelatedElement;
};

struct IfcRelConnectsPathElements : IfcRelConnectsElements {
  SmallVector<IfcInteger, 4> RelatingPriorities;
  SmallVector<IfcInteger, 4> RelatedPriorities;
  IfcConnectionTypeEnum RelatedConnectionType;
  IfcConnectionTypeEnum RelatingConnectionType;
};

struct IfcRelConnectsPortToElement : IfcRelConnects {
  IfcPort RelatingPort;
  IfcDistributionElement RelatedElement;
};

struct IfcRelConnectsPorts : IfcRelConnects {
  IfcPort RelatingPort;
  IfcPort RelatedPort;
  IfcElement RealizingElement;
};

struct IfcRelConnectsStructuralActivity : IfcRelConnects {
  IfcStructuralActivityAssignmentSelect RelatingElement;
  IfcStructuralActivity RelatedStructuralActivity;
};

struct IfcRelConnectsStructuralMember : IfcRelConnects {
  IfcStructuralMember RelatingStructuralMember;
  IfcStructuralConnection RelatedStructuralConnection;
  IfcBoundaryCondition AppliedCondition;
  IfcStructuralConnectionCondition AdditionalConditions;
  IfcLengthMeasure SupportedLength;
  IfcAxis2Placement3D ConditionCoordinateSystem;
};

struct IfcRelConnectsWithEccentricity : IfcRelConnectsStructuralMember {
  IfcConnectionGeometry ConnectionConstraint;
};

struct IfcRelConnectsWithRealizingElements : IfcRelConnectsElements {
  std::unordered_set<IfcElement> RealizingElements;
  IfcLabel ConnectionType;
};

struct IfcRelContainedInSpatialStructure : IfcRelConnects {
  std::unordered_set<IfcProduct> RelatedElements;
  IfcSpatialElement RelatingStructure;
};

struct IfcRelCoversBldgElements : IfcRelConnects {
  IfcElement RelatingBuildingElement;
  std::unordered_set<IfcCovering> RelatedCoverings;
};

struct IfcRelCoversSpaces : IfcRelConnects {
  IfcSpace RelatingSpace;
  std::unordered_set<IfcCovering> RelatedCoverings;
};

struct IfcRelDeclares : IfcRelationship {
  IfcContext RelatingContext;
  std::unordered_set<IfcDefinitionSelect> RelatedDefinitions;
};

struct IfcRelDecomposes : IfcRelationship {};

struct IfcRelDefines : IfcRelationship {};

struct IfcRelDefinesByObject : IfcRelDefines {
  std::unordered_set<IfcObject> RelatedObjects;
  IfcObject RelatingObject;
};

struct IfcRelDefinesByProperties : IfcRelDefines {
  std::unordered_set<IfcObjectDefinition> RelatedObjects;
  IfcPropertySetDefinitionSelect RelatingPropertyDefinition;
};

struct IfcRelDefinesByTemplate : IfcRelDefines {
  std::unordered_set<IfcPropertySetDefinition> RelatedPropertySets;
  IfcPropertySetTemplate RelatingTemplate;
};

struct IfcRelDefinesByType : IfcRelDefines {
  std::unordered_set<IfcObject> RelatedObjects;
  IfcTypeObject RelatingType;
};

struct IfcRelFillsElement : IfcRelConnects {
  IfcOpeningElement RelatingOpeningElement;
  IfcElement RelatedBuildingElement;
};

struct IfcRelFlowControlElements : IfcRelConnects {
  std::unordered_set<IfcDistributionControlElement> RelatedControlElements;
  IfcDistributionFlowElement RelatingFlowElement;
};

struct IfcRelInterferesElements : IfcRelConnects {
  IfcElement RelatingElement;
  IfcElement RelatedElement;
  IfcConnectionGeometry InterferenceGeometry;
  IfcIdentifier InterferenceType;
  IfcLogical ImpliedOrder;
};

struct IfcRelNests : IfcRelDecomposes {
  IfcObjectDefinition RelatingObject;
  SmallVector<IfcObjectDefinition, 4> RelatedObjects;
};

struct IfcRelProjectsElement : IfcRelDecomposes {
  IfcElement RelatingElement;
  IfcFeatureElementAddition RelatedFeatureElement;
};

struct IfcRelReferencedInSpatialStructure : IfcRelConnects {
  std::unordered_set<IfcProduct> RelatedElements;
  IfcSpatialElement RelatingStructure;
};

struct IfcRelSequence : IfcRelConnects {
  IfcProcess RelatingProcess;
  IfcProcess RelatedProcess;
  IfcLagTime TimeLag;
  IfcSequenceEnum SequenceType;
  IfcLabel UserDefinedSequenceType;
};

struct IfcRelServicesBuildings : IfcRelConnects {
  IfcSystem RelatingSystem;
  std::unordered_set<IfcSpatialElement> RelatedBuildings;
};

struct IfcRelSpaceBoundary : IfcRelConnects {
  IfcSpaceBoundarySelect RelatingSpace;
  IfcElement RelatedBuildingElement;
  IfcConnectionGeometry ConnectionGeometry;
  IfcPhysicalOrVirtualEnum PhysicalOrVirtualBoundary;
  IfcInternalOrExternalEnum InternalOrExternalBoundary;
};

struct IfcRelSpaceBoundary1stLevel : IfcRelSpaceBoundary {
  IfcRelSpaceBoundary1stLevel ParentBoundary;
};

struct IfcRelSpaceBoundary2ndLevel : IfcRelSpaceBoundary1stLevel {
  IfcRelSpaceBoundary2ndLevel CorrespondingBoundary;
};

struct IfcRelVoidsElement : IfcRelDecomposes {
  IfcElement RelatingBuildingElement;
  IfcFeatureElementSubtraction RelatedOpeningElement;
};

struct IfcRelationship : IfcRoot {};

struct IfcReparametrisedCompositeCurveSegment : IfcCompositeCurveSegment {
  IfcParameterValue ParamLength;
};

struct IfcRepresentation : IfcEntity {
  IfcRepresentationContext ContextOfItems;
  IfcLabel RepresentationIdentifier;
  IfcLabel RepresentationType;
  std::unordered_set<IfcRepresentationItem> Items;
};

struct IfcRepresentationContext : IfcEntity {
  IfcLabel ContextIdentifier;
  IfcLabel ContextType;
};

struct IfcRepresentationItem : IfcEntity {};

struct IfcRepresentationMap : IfcEntity {
  IfcAxis2Placement MappingOrigin;
  IfcRepresentation MappedRepresentation;
};

struct IfcResource : IfcObject {
  IfcIdentifier Identification;
  IfcText LongDescription;
};

struct IfcResourceApprovalRelationship : IfcResourceLevelRelationship {
  std::unordered_set<IfcResourceObjectSelect> RelatedResourceObjects;
  IfcApproval RelatingApproval;
};

struct IfcResourceConstraintRelationship : IfcResourceLevelRelationship {
  IfcConstraint RelatingConstraint;
  std::unordered_set<IfcResourceObjectSelect> RelatedResourceObjects;
};

struct IfcResourceLevelRelationship : IfcEntity {
  IfcLabel Name;
  IfcText Description;
};

struct IfcResourceTime : IfcSchedulingTime {
  IfcDuration ScheduleWork;
  IfcPositiveRatioMeasure ScheduleUsage;
  IfcDateTime ScheduleStart;
  IfcDateTime ScheduleFinish;
  IfcLabel ScheduleContour;
  IfcDuration LevelingDelay;
  IfcBoolean IsOverAllocated;
  IfcDateTime StatusTime;
  IfcDuration ActualWork;
  IfcPositiveRatioMeasure ActualUsage;
  IfcDateTime ActualStart;
  IfcDateTime ActualFinish;
  IfcDuration RemainingWork;
  IfcPositiveRatioMeasure RemainingUsage;
  IfcPositiveRatioMeasure Completion;
};

struct IfcRevolvedAreaSolid : IfcSweptAreaSolid {
  IfcAxis1Placement Axis;
  IfcPlaneAngleMeasure Angle;
};

struct IfcRevolvedAreaSolidTapered : IfcRevolvedAreaSolid {
  IfcProfileDef EndSweptArea;
};

struct IfcRightCircularCone : IfcCsgPrimitive3D {
  IfcPositiveLengthMeasure Height;
  IfcPositiveLengthMeasure BottomRadius;
};

struct IfcRightCircularCylinder : IfcCsgPrimitive3D {
  IfcPositiveLengthMeasure Height;
  IfcPositiveLengthMeasure Radius;
};

struct IfcRoof : IfcBuildingElement {
  IfcRoofTypeEnum PredefinedType;
};

struct IfcRoofType : IfcBuildingElementType {
  IfcRoofTypeEnum PredefinedType;
};

struct IfcRoot : IfcEntity {
  IfcGloballyUniqueId GlobalId;
  IfcOwnerHistory OwnerHistory;
  IfcLabel Name;
  IfcText Description;
};

struct IfcRoundedRectangleProfileDef : IfcRectangleProfileDef {
  IfcPositiveLengthMeasure RoundingRadius;
};

struct IfcSIUnit : IfcNamedUnit {
  IfcSIPrefix Prefix;
  IfcSIUnitName Name;
};

struct IfcSanitaryTerminal : IfcFlowTerminal {
  IfcSanitaryTerminalTypeEnum PredefinedType;
};

struct IfcSanitaryTerminalType : IfcFlowTerminalType {
  IfcSanitaryTerminalTypeEnum PredefinedType;
};

struct IfcSchedulingTime : IfcEntity {
  IfcLabel Name;
  IfcDataOriginEnum DataOrigin;
  IfcLabel UserDefinedDataOrigin;
};

struct IfcSeamCurve : IfcSurfaceCurve {};

struct IfcSectionProperties : IfcPreDefinedProperties {
  IfcSectionTypeEnum SectionType;
  IfcProfileDef StartProfile;
  IfcProfileDef EndProfile;
};

struct IfcSectionReinforcementProperties : IfcPreDefinedProperties {
  IfcLengthMeasure LongitudinalStartPosition;
  IfcLengthMeasure LongitudinalEndPosition;
  IfcLengthMeasure TransversePosition;
  IfcReinforcingBarRoleEnum ReinforcementRole;
  IfcSectionProperties SectionDefinition;
  std::unordered_set<IfcReinforcementBarProperties> CrossSectionReinforcementDefinitions;
};

struct IfcSectionedSolid : IfcSolidModel {
  IfcCurve Directrix;
  SmallVector<IfcProfileDef, 4> CrossSections;
};

struct IfcSectionedSolidHorizontal : IfcSectionedSolid {
  SmallVector<IfcDistanceExpression, 4> CrossSectionPositions;
  IfcBoolean FixedAxisVertical;
};

struct IfcSectionedSpine : IfcGeometricRepresentationItem {
  IfcCompositeCurve SpineCurve;
  SmallVector<IfcProfileDef, 4> CrossSections;
  SmallVector<IfcAxis2Placement3D, 4> CrossSectionPositions;
};

struct IfcSensor : IfcDistributionControlElement {
  IfcSensorTypeEnum PredefinedType;
};

struct IfcSensorType : IfcDistributionControlElementType {
  IfcSensorTypeEnum PredefinedType;
};

struct IfcShadingDevice : IfcBuildingElement {
  IfcShadingDeviceTypeEnum PredefinedType;
};

struct IfcShadingDeviceType : IfcBuildingElementType {
  IfcShadingDeviceTypeEnum PredefinedType;
};

struct IfcShapeAspect : IfcEntity {
  SmallVector<IfcShapeModel, 4> ShapeRepresentations;
  IfcLabel Name;
  IfcText Description;
  IfcLogical ProductDefinitional;
  IfcProductRepresentationSelect PartOfProductDefinitionShape;
};

struct IfcShapeModel : IfcRepresentation {};

struct IfcShapeRepresentation : IfcShapeModel {};

struct IfcShellBasedSurfaceModel : IfcGeometricRepresentationItem {
  std::unordered_set<IfcShell> SbsmBoundary;
};

struct IfcSimpleProperty : IfcProperty {};

struct IfcSimplePropertyTemplate : IfcPropertyTemplate {
  IfcSimplePropertyTemplateTypeEnum TemplateType;
  IfcLabel PrimaryMeasureType;
  IfcLabel SecondaryMeasureType;
  IfcPropertyEnumeration Enumerators;
  IfcUnit PrimaryUnit;
  IfcUnit SecondaryUnit;
  IfcLabel Expression;
  IfcStateEnum AccessState;
};

struct IfcSite : IfcSpatialStructureElement {
  IfcCompoundPlaneAngleMeasure RefLatitude;
  IfcCompoundPlaneAngleMeasure RefLongitude;
  IfcLengthMeasure RefElevation;
  IfcLabel LandTitleNumber;
  IfcPostalAddress SiteAddress;
};

struct IfcSlab : IfcBuildingElement {
  IfcSlabTypeEnum PredefinedType;
};

struct IfcSlabElementedCase : IfcSlab {};

struct IfcSlabStandardCase : IfcSlab {};

struct IfcSlabType : IfcBuildingElementType {
  IfcSlabTypeEnum PredefinedType;
};

struct IfcSlippageConnectionCondition : IfcStructuralConnectionCondition {
  IfcLengthMeasure SlippageX;
  IfcLengthMeasure SlippageY;
  IfcLengthMeasure SlippageZ;
};

struct IfcSolarDevice : IfcEnergyConversionDevice {
  IfcSolarDeviceTypeEnum PredefinedType;
};

struct IfcSolarDeviceType : IfcEnergyConversionDeviceType {
  IfcSolarDeviceTypeEnum PredefinedType;
};

struct IfcSolidModel : IfcGeometricRepresentationItem {};

struct IfcSpace : IfcSpatialStructureElement {
  IfcSpaceTypeEnum PredefinedType;
  IfcLengthMeasure ElevationWithFlooring;
};

struct IfcSpaceHeater : IfcFlowTerminal {
  IfcSpaceHeaterTypeEnum PredefinedType;
};

struct IfcSpaceHeaterType : IfcFlowTerminalType {
  IfcSpaceHeaterTypeEnum PredefinedType;
};

struct IfcSpaceType : IfcSpatialStructureElementType {
  IfcSpaceTypeEnum PredefinedType;
  IfcLabel LongName;
};

struct IfcSpatialElement : IfcProduct {
  IfcLabel LongName;
};

struct IfcSpatialElementType : IfcTypeProduct {
  IfcLabel ElementType;
};

struct IfcSpatialStructureElement : IfcSpatialElement {
  IfcElementCompositionEnum CompositionType;
};

struct IfcSpatialStructureElementType : IfcSpatialElementType {};

struct IfcSpatialZone : IfcSpatialElement {
  IfcSpatialZoneTypeEnum PredefinedType;
};

struct IfcSpatialZoneType : IfcSpatialElementType {
  IfcSpatialZoneTypeEnum PredefinedType;
  IfcLabel LongName;
};

struct IfcSphere : IfcCsgPrimitive3D {
  IfcPositiveLengthMeasure Radius;
};

struct IfcSphericalSurface : IfcElementarySurface {
  IfcPositiveLengthMeasure Radius;
};

struct IfcStackTerminal : IfcFlowTerminal {
  IfcStackTerminalTypeEnum PredefinedType;
};

struct IfcStackTerminalType : IfcFlowTerminalType {
  IfcStackTerminalTypeEnum PredefinedType;
};

struct IfcStair : IfcBuildingElement {
  IfcStairTypeEnum PredefinedType;
};

struct IfcStairFlight : IfcBuildingElement {
  IfcInteger NumberOfRisers;
  IfcInteger NumberOfTreads;
  IfcPositiveLengthMeasure RiserHeight;
  IfcPositiveLengthMeasure TreadLength;
  IfcStairFlightTypeEnum PredefinedType;
};

struct IfcStairFlightType : IfcBuildingElementType {
  IfcStairFlightTypeEnum PredefinedType;
};

struct IfcStairType : IfcBuildingElementType {
  IfcStairTypeEnum PredefinedType;
};

struct IfcStructuralAction : IfcStructuralActivity {
  IfcBoolean DestabilizingLoad;
};

struct IfcStructuralActivity : IfcProduct {
  IfcStructuralLoad AppliedLoad;
  IfcGlobalOrLocalEnum GlobalOrLocal;
};

struct IfcStructuralAnalysisModel : IfcSystem {
  IfcAnalysisModelTypeEnum PredefinedType;
  IfcAxis2Placement3D OrientationOf2DPlane;
  std::unordered_set<IfcStructuralLoadGroup> LoadedBy;
  std::unordered_set<IfcStructuralResultGroup> HasResults;
  IfcObjectPlacement SharedPlacement;
};

struct IfcStructuralConnection : IfcStructuralItem {
  IfcBoundaryCondition AppliedCondition;
};

struct IfcStructuralConnectionCondition : IfcEntity {
  IfcLabel Name;
};

struct IfcStructuralCurveAction : IfcStructuralAction {
  IfcProjectedOrTrueLengthEnum ProjectedOrTrue;
  IfcStructuralCurveActivityTypeEnum PredefinedType;
};

struct IfcStructuralCurveConnection : IfcStructuralConnection {
  IfcDirection Axis;
};

struct IfcStructuralCurveMember : IfcStructuralMember {
  IfcStructuralCurveMemberTypeEnum PredefinedType;
  IfcDirection Axis;
};

struct IfcStructuralCurveMemberVarying : IfcStructuralCurveMember {};

struct IfcStructuralCurveReaction : IfcStructuralReaction {
  IfcStructuralCurveActivityTypeEnum PredefinedType;
};

struct IfcStructuralItem : IfcProduct {};

struct IfcStructuralLinearAction : IfcStructuralCurveAction {};

struct IfcStructuralLoad : IfcEntity {
  IfcLabel Name;
};

struct IfcStructuralLoadCase : IfcStructuralLoadGroup {
  SmallVector<IfcRatioMeasure, 3> SelfWeightCoefficients;
};

struct IfcStructuralLoadConfiguration : IfcStructuralLoad {
  SmallVector<IfcStructuralLoadOrResult, 4> Values;
  SmallVector<SmallVector<IfcLengthMeasure, 2>, 4> Locations;
};

struct IfcStructuralLoadGroup : IfcGroup {
  IfcLoadGroupTypeEnum PredefinedType;
  IfcActionTypeEnum ActionType;
  IfcActionSourceTypeEnum ActionSource;
  IfcRatioMeasure Coefficient;
  IfcLabel Purpose;
};

struct IfcStructuralLoadLinearForce : IfcStructuralLoadStatic {
  IfcLinearForceMeasure LinearForceX;
  IfcLinearForceMeasure LinearForceY;
  IfcLinearForceMeasure LinearForceZ;
  IfcLinearMomentMeasure LinearMomentX;
  IfcLinearMomentMeasure LinearMomentY;
  IfcLinearMomentMeasure LinearMomentZ;
};

struct IfcStructuralLoadOrResult : IfcStructuralLoad {};

struct IfcStructuralLoadPlanarForce : IfcStructuralLoadStatic {
  IfcPlanarForceMeasure PlanarForceX;
  IfcPlanarForceMeasure PlanarForceY;
  IfcPlanarForceMeasure PlanarForceZ;
};

struct IfcStructuralLoadSingleDisplacement : IfcStructuralLoadStatic {
  IfcLengthMeasure DisplacementX;
  IfcLengthMeasure DisplacementY;
  IfcLengthMeasure DisplacementZ;
  IfcPlaneAngleMeasure RotationalDisplacementRX;
  IfcPlaneAngleMeasure RotationalDisplacementRY;
  IfcPlaneAngleMeasure RotationalDisplacementRZ;
};

struct IfcStructuralLoadSingleDisplacementDistortion : IfcStructuralLoadSingleDisplacement {
  IfcCurvatureMeasure Distortion;
};

struct IfcStructuralLoadSingleForce : IfcStructuralLoadStatic {
  IfcForceMeasure ForceX;
  IfcForceMeasure ForceY;
  IfcForceMeasure ForceZ;
  IfcTorqueMeasure MomentX;
  IfcTorqueMeasure MomentY;
  IfcTorqueMeasure MomentZ;
};

struct IfcStructuralLoadSingleForceWarping : IfcStructuralLoadSingleForce {
  IfcWarpingMomentMeasure WarpingMoment;
};

struct IfcStructuralLoadStatic : IfcStructuralLoadOrResult {};

struct IfcStructuralLoadTemperature : IfcStructuralLoadStatic {
  IfcThermodynamicTemperatureMeasure DeltaTConstant;
  IfcThermodynamicTemperatureMeasure DeltaTY;
  IfcThermodynamicTemperatureMeasure DeltaTZ;
};

struct IfcStructuralMember : IfcStructuralItem {};

struct IfcStructuralPlanarAction : IfcStructuralSurfaceAction {};

struct IfcStructuralPointAction : IfcStructuralAction {};

struct IfcStructuralPointConnection : IfcStructuralConnection {
  IfcAxis2Placement3D ConditionCoordinateSystem;
};

struct IfcStructuralPointReaction : IfcStructuralReaction {};

struct IfcStructuralReaction : IfcStructuralActivity {};

struct IfcStructuralResultGroup : IfcGroup {
  IfcAnalysisTheoryTypeEnum TheoryType;
  IfcStructuralLoadGroup ResultForLoadGroup;
  IfcBoolean IsLinear;
};

struct IfcStructuralSurfaceAction : IfcStructuralAction {
  IfcProjectedOrTrueLengthEnum ProjectedOrTrue;
  IfcStructuralSurfaceActivityTypeEnum PredefinedType;
};

struct IfcStructuralSurfaceConnection : IfcStructuralConnection {};

struct IfcStructuralSurfaceMember : IfcStructuralMember {
  IfcStructuralSurfaceMemberTypeEnum PredefinedType;
  IfcPositiveLengthMeasure Thickness;
};

struct IfcStructuralSurfaceMemberVarying : IfcStructuralSurfaceMember {};

struct IfcStructuralSurfaceReaction : IfcStructuralReaction {
  IfcStructuralSurfaceActivityTypeEnum PredefinedType;
};

struct IfcStyleModel : IfcRepresentation {};

struct IfcStyledItem : IfcRepresentationItem {
  IfcRepresentationItem Item;
  std::unordered_set<IfcStyleAssignmentSelect> Styles;
  IfcLabel Name;
};

struct IfcStyledRepresentation : IfcStyleModel {};

struct IfcSubContractResource : IfcConstructionResource {
  IfcSubContractResourceTypeEnum PredefinedType;
};

struct IfcSubContractResourceType : IfcConstructionResourceType {
  IfcSubContractResourceTypeEnum PredefinedType;
};

struct IfcSubedge : IfcEdge {
  IfcEdge ParentEdge;
};

struct IfcSurface : IfcGeometricRepresentationItem {};

struct IfcSurfaceCurve : IfcCurve {
  IfcCurve Curve3D;
  SmallVector<IfcPcurve, 2> AssociatedGeometry;
  IfcPreferredSurfaceCurveRepresentation MasterRepresentation;
};

struct IfcSurfaceCurveSweptAreaSolid : IfcSweptAreaSolid {
  IfcCurve Directrix;
  IfcParameterValue StartParam;
  IfcParameterValue EndParam;
  IfcSurface ReferenceSurface;
};

struct IfcSurfaceFeature : IfcFeatureElement {
  IfcSurfaceFeatureTypeEnum PredefinedType;
};

struct IfcSurfaceOfLinearExtrusion : IfcSweptSurface {
  IfcDirection ExtrudedDirection;
  IfcLengthMeasure Depth;
};

struct IfcSurfaceOfRevolution : IfcSweptSurface {
  IfcAxis1Placement AxisPosition;
};

struct IfcSurfaceReinforcementArea : IfcStructuralLoadOrResult {
  SmallVector<IfcLengthMeasure, 3> SurfaceReinforcement1;
  SmallVector<IfcLengthMeasure, 3> SurfaceReinforcement2;
  IfcRatioMeasure ShearReinforcement;
};

struct IfcSurfaceStyle : IfcPresentationStyle {
  IfcSurfaceSide Side;
  std::unordered_set<IfcSurfaceStyleElementSelect> Styles;
};

struct IfcSurfaceStyleLighting : IfcPresentationItem {
  IfcColourRgb DiffuseTransmissionColour;
  IfcColourRgb DiffuseReflectionColour;
  IfcColourRgb TransmissionColour;
  IfcColourRgb ReflectanceColour;
};

struct IfcSurfaceStyleRefraction : IfcPresentationItem {
  IfcReal RefractionIndex;
  IfcReal DispersionFactor;
};

struct IfcSurfaceStyleRendering : IfcSurfaceStyleShading {
  IfcColourOrFactor DiffuseColour;
  IfcColourOrFactor TransmissionColour;
  IfcColourOrFactor DiffuseTransmissionColour;
  IfcColourOrFactor ReflectionColour;
  IfcColourOrFactor SpecularColour;
  IfcSpecularHighlightSelect SpecularHighlight;
  IfcReflectanceMethodEnum ReflectanceMethod;
};

struct IfcSurfaceStyleShading : IfcPresentationItem {
  IfcColourRgb SurfaceColour;
  IfcNormalisedRatioMeasure Transparency;
};

struct IfcSurfaceStyleWithTextures : IfcPresentationItem {
  SmallVector<IfcSurfaceTexture, 4> Textures;
};

struct IfcSurfaceTexture : IfcPresentationItem {
  IfcBoolean RepeatS;
  IfcBoolean RepeatT;
  IfcIdentifier Mode;
  IfcCartesianTransformationOperator2D TextureTransform;
  SmallVector<IfcIdentifier, 4> Parameter;
};

struct IfcSweptAreaSolid : IfcSolidModel {
  IfcProfileDef SweptArea;
  IfcAxis2Placement3D Position;
};

struct IfcSweptDiskSolid : IfcSolidModel {
  IfcCurve Directrix;
  IfcPositiveLengthMeasure Radius;
  IfcPositiveLengthMeasure InnerRadius;
  IfcParameterValue StartParam;
  IfcParameterValue EndParam;
};

struct IfcSweptDiskSolidPolygonal : IfcSweptDiskSolid {
  IfcPositiveLengthMeasure FilletRadius;
};

struct IfcSweptSurface : IfcSurface {
  IfcProfileDef SweptCurve;
  IfcAxis2Placement3D Position;
};

struct IfcSwitchingDevice : IfcFlowController {
  IfcSwitchingDeviceTypeEnum PredefinedType;
};

struct IfcSwitchingDeviceType : IfcFlowControllerType {
  IfcSwitchingDeviceTypeEnum PredefinedType;
};

struct IfcSystem : IfcGroup {};

struct IfcSystemFurnitureElement : IfcFurnishingElement {
  IfcSystemFurnitureElementTypeEnum PredefinedType;
};

struct IfcSystemFurnitureElementType : IfcFurnishingElementType {
  IfcSystemFurnitureElementTypeEnum PredefinedType;
};

struct IfcTShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure Depth;
  IfcPositiveLengthMeasure FlangeWidth;
  IfcPositiveLengthMeasure WebThickness;
  IfcPositiveLengthMeasure FlangeThickness;
  IfcNonNegativeLengthMeasure FilletRadius;
  IfcNonNegativeLengthMeasure FlangeEdgeRadius;
  IfcNonNegativeLengthMeasure WebEdgeRadius;
  IfcPlaneAngleMeasure WebSlope;
  IfcPlaneAngleMeasure FlangeSlope;
};

struct IfcTable : IfcEntity {
  IfcLabel Name;
  SmallVector<IfcTableRow, 4> Rows;
  SmallVector<IfcTableColumn, 4> Columns;
};

struct IfcTableColumn : IfcEntity {
  IfcIdentifier Identifier;
  IfcLabel Name;
  IfcText Description;
  IfcUnit Unit;
  IfcReference ReferencePath;
};

struct IfcTableRow : IfcEntity {
  SmallVector<IfcValue, 4> RowCells;
  IfcBoolean IsHeading;
};

struct IfcTank : IfcFlowStorageDevice {
  IfcTankTypeEnum PredefinedType;
};

struct IfcTankType : IfcFlowStorageDeviceType {
  IfcTankTypeEnum PredefinedType;
};

struct IfcTask : IfcProcess {
  IfcLabel Status;
  IfcLabel WorkMethod;
  IfcBoolean IsMilestone;
  IfcInteger Priority;
  IfcTaskTime TaskTime;
  IfcTaskTypeEnum PredefinedType;
};

struct IfcTaskTime : IfcSchedulingTime {
  IfcTaskDurationEnum DurationType;
  IfcDuration ScheduleDuration;
  IfcDateTime ScheduleStart;
  IfcDateTime ScheduleFinish;
  IfcDateTime EarlyStart;
  IfcDateTime EarlyFinish;
  IfcDateTime LateStart;
  IfcDateTime LateFinish;
  IfcDuration FreeFloat;
  IfcDuration TotalFloat;
  IfcBoolean IsCritical;
  IfcDateTime StatusTime;
  IfcDuration ActualDuration;
  IfcDateTime ActualStart;
  IfcDateTime ActualFinish;
  IfcDuration RemainingTime;
  IfcPositiveRatioMeasure Completion;
};

struct IfcTaskTimeRecurring : IfcTaskTime {
  IfcRecurrencePattern Recurrence;
};

struct IfcTaskType : IfcTypeProcess {
  IfcTaskTypeEnum PredefinedType;
  IfcLabel WorkMethod;
};

struct IfcTelecomAddress : IfcAddress {
  SmallVector<IfcLabel, 4> TelephoneNumbers;
  SmallVector<IfcLabel, 4> FacsimileNumbers;
  IfcLabel PagerNumber;
  SmallVector<IfcLabel, 4> ElectronicMailAddresses;
  IfcURIReference WWWHomePageURL;
  SmallVector<IfcURIReference, 4> MessagingIDs;
};

struct IfcTendon : IfcReinforcingElement {
  IfcTendonTypeEnum PredefinedType;
  IfcPositiveLengthMeasure NominalDiameter;
  IfcAreaMeasure CrossSectionArea;
  IfcForceMeasure TensionForce;
  IfcPressureMeasure PreStress;
  IfcNormalisedRatioMeasure FrictionCoefficient;
  IfcPositiveLengthMeasure AnchorageSlip;
  IfcPositiveLengthMeasure MinCurvatureRadius;
};

struct IfcTendonAnchor : IfcReinforcingElement {
  IfcTendonAnchorTypeEnum PredefinedType;
};

struct IfcTendonAnchorType : IfcReinforcingElementType {
  IfcTendonAnchorTypeEnum PredefinedType;
};

struct IfcTendonType : IfcReinforcingElementType {
  IfcTendonTypeEnum PredefinedType;
  IfcPositiveLengthMeasure NominalDiameter;
  IfcAreaMeasure CrossSectionArea;
  IfcPositiveLengthMeasure SheathDiameter;
};

struct IfcTessellatedFaceSet : IfcTessellatedItem {
  IfcCartesianPointList3D Coordinates;
};

struct IfcTessellatedItem : IfcGeometricRepresentationItem {};

struct IfcTextLiteral : IfcGeometricRepresentationItem {
  IfcPresentableText Literal;
  IfcAxis2Placement Placement;
  IfcTextPath Path;
};

struct IfcTextLiteralWithExtent : IfcTextLiteral {
  IfcPlanarExtent Extent;
  IfcBoxAlignment BoxAlignment;
};

struct IfcTextStyle : IfcPresentationStyle {
  IfcTextStyleForDefinedFont TextCharacterAppearance;
  IfcTextStyleTextModel TextStyle;
  IfcTextFontSelect TextFontStyle;
  IfcBoolean ModelOrDraughting;
};

struct IfcTextStyleFontModel : IfcPreDefinedTextFont {
  SmallVector<IfcTextFontName, 4> FontFamily;
  IfcFontStyle FontStyle;
  IfcFontVariant FontVariant;
  IfcFontWeight FontWeight;
  IfcSizeSelect FontSize;
};

struct IfcTextStyleForDefinedFont : IfcPresentationItem {
  IfcColour Colour;
  IfcColour BackgroundColour;
};

struct IfcTextStyleTextModel : IfcPresentationItem {
  IfcSizeSelect TextIndent;
  IfcTextAlignment TextAlign;
  IfcTextDecoration TextDecoration;
  IfcSizeSelect LetterSpacing;
  IfcSizeSelect WordSpacing;
  IfcTextTransformation TextTransform;
  IfcSizeSelect LineHeight;
};

struct IfcTextureCoordinate : IfcPresentationItem {
  SmallVector<IfcSurfaceTexture, 4> Maps;
};

struct IfcTextureCoordinateGenerator : IfcTextureCoordinate {
  IfcLabel Mode;
  SmallVector<IfcReal, 4> Parameter;
};

struct IfcTextureMap : IfcTextureCoordinate {
  SmallVector<IfcTextureVertex, 4> Vertices;
  IfcFace MappedTo;
};

struct IfcTextureVertex : IfcPresentationItem {
  SmallVector<IfcParameterValue, 2> Coordinates;
};

struct IfcTextureVertexList : IfcPresentationItem {
  SmallVector<SmallVector<IfcParameterValue, 2>, 4> TexCoordsList;
};

struct IfcTimePeriod : IfcEntity {
  IfcTime StartTime;
  IfcTime EndTime;
};

struct IfcTimeSeries : IfcEntity {
  IfcLabel Name;
  IfcText Description;
  IfcDateTime StartTime;
  IfcDateTime EndTime;
  IfcTimeSeriesDataTypeEnum TimeSeriesDataType;
  IfcDataOriginEnum DataOrigin;
  IfcLabel UserDefinedDataOrigin;
  IfcUnit Unit;
};

struct IfcTimeSeriesValue : IfcEntity {
  SmallVector<IfcValue, 4> ListValues;
};

struct IfcTopologicalRepresentationItem : IfcRepresentationItem {};

struct IfcTopologyRepresentation : IfcShapeModel {};

struct IfcToroidalSurface : IfcElementarySurface {
  IfcPositiveLengthMeasure MajorRadius;
  IfcPositiveLengthMeasure MinorRadius;
};

struct IfcTransformer : IfcEnergyConversionDevice {
  IfcTransformerTypeEnum PredefinedType;
};

struct IfcTransformerType : IfcEnergyConversionDeviceType {
  IfcTransformerTypeEnum PredefinedType;
};

struct IfcTransitionCurveSegment2D : IfcCurveSegment2D {
  IfcPositiveLengthMeasure StartRadius;
  IfcPositiveLengthMeasure EndRadius;
  IfcBoolean IsStartRadiusCCW;
  IfcBoolean IsEndRadiusCCW;
  IfcTransitionCurveType TransitionCurveType;
};

struct IfcTransportElement : IfcElement {
  IfcTransportElementTypeEnum PredefinedType;
};

struct IfcTransportElementType : IfcElementType {
  IfcTransportElementTypeEnum PredefinedType;
};

struct IfcTrapeziumProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure BottomXDim;
  IfcPositiveLengthMeasure TopXDim;
  IfcPositiveLengthMeasure YDim;
  IfcLengthMeasure TopXOffset;
};

struct IfcTriangulatedFaceSet : IfcTessellatedFaceSet {
  SmallVector<SmallVector<IfcParameterValue, 3>, 4> Normals;
  IfcBoolean Closed;
  SmallVector<SmallVector<IfcPositiveInteger, 3>, 4> CoordIndex;
  SmallVector<IfcPositiveInteger, 4> PnIndex;
};

struct IfcTriangulatedIrregularNetwork : IfcTriangulatedFaceSet {
  SmallVector<IfcInteger, 4> Flags;
};

struct IfcTrimmedCurve : IfcBoundedCurve {
  IfcCurve BasisCurve;
  std::unordered_set<IfcTrimmingSelect> Trim1;
  std::unordered_set<IfcTrimmingSelect> Trim2;
  IfcBoolean SenseAgreement;
  IfcTrimmingPreference MasterRepresentation;
};

struct IfcTubeBundle : IfcEnergyConversionDevice {
  IfcTubeBundleTypeEnum PredefinedType;
};

struct IfcTubeBundleType : IfcEnergyConversionDeviceType {
  IfcTubeBundleTypeEnum PredefinedType;
};

struct IfcTypeObject : IfcObjectDefinition {
  IfcIdentifier ApplicableOccurrence;
  std::unordered_set<IfcPropertySetDefinition> HasPropertySets;
};

struct IfcTypeProcess : IfcTypeObject {
  IfcIdentifier Identification;
  IfcText LongDescription;
  IfcLabel ProcessType;
};

struct IfcTypeProduct : IfcTypeObject {
  SmallVector<IfcRepresentationMap, 4> RepresentationMaps;
  IfcLabel Tag;
};

struct IfcTypeResource : IfcTypeObject {
  IfcIdentifier Identification;
  IfcText LongDescription;
  IfcLabel ResourceType;
};

struct IfcUShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure Depth;
  IfcPositiveLengthMeasure FlangeWidth;
  IfcPositiveLengthMeasure WebThickness;
  IfcPositiveLengthMeasure FlangeThickness;
  IfcNonNegativeLengthMeasure FilletRadius;
  IfcNonNegativeLengthMeasure EdgeRadius;
  IfcPlaneAngleMeasure FlangeSlope;
};

struct IfcUnitAssignment : IfcEntity {
  std::unordered_set<IfcUnit> Units;
};

struct IfcUnitaryControlElement : IfcDistributionControlElement {
  IfcUnitaryControlElementTypeEnum PredefinedType;
};

struct IfcUnitaryControlElementType : IfcDistributionControlElementType {
  IfcUnitaryControlElementTypeEnum PredefinedType;
};

struct IfcUnitaryEquipment : IfcEnergyConversionDevice {
  IfcUnitaryEquipmentTypeEnum PredefinedType;
};

struct IfcUnitaryEquipmentType : IfcEnergyConversionDeviceType {
  IfcUnitaryEquipmentTypeEnum PredefinedType;
};

struct IfcValve : IfcFlowController {
  IfcValveTypeEnum PredefinedType;
};

struct IfcValveType : IfcFlowControllerType {
  IfcValveTypeEnum PredefinedType;
};

struct IfcVector : IfcGeometricRepresentationItem {
  IfcDirection Orientation;
  IfcLengthMeasure Magnitude;
};

struct IfcVertex : IfcTopologicalRepresentationItem {};

struct IfcVertexLoop : IfcLoop {
  IfcVertex LoopVertex;
};

struct IfcVertexPoint : IfcVertex {
  IfcPoint VertexGeometry;
};

struct IfcVibrationIsolator : IfcElementComponent {
  IfcVibrationIsolatorTypeEnum PredefinedType;
};

struct IfcVibrationIsolatorType : IfcElementComponentType {
  IfcVibrationIsolatorTypeEnum PredefinedType;
};

struct IfcVirtualElement : IfcElement {};

struct IfcVirtualGridIntersection : IfcEntity {
  SmallVector<IfcGridAxis, 2> IntersectingAxes;
  SmallVector<IfcLengthMeasure, 3> OffsetDistances;
};

struct IfcVoidingFeature : IfcFeatureElementSubtraction {
  IfcVoidingFeatureTypeEnum PredefinedType;
};

struct IfcWall : IfcBuildingElement {
  IfcWallTypeEnum PredefinedType;
};

struct IfcWallElementedCase : IfcWall {};

struct IfcWallStandardCase : IfcWall {};

struct IfcWallType : IfcBuildingElementType {
  IfcWallTypeEnum PredefinedType;
};

struct IfcWasteTerminal : IfcFlowTerminal {
  IfcWasteTerminalTypeEnum PredefinedType;
};

struct IfcWasteTerminalType : IfcFlowTerminalType {
  IfcWasteTerminalTypeEnum PredefinedType;
};

struct IfcWindow : IfcBuildingElement {
  IfcPositiveLengthMeasure OverallHeight;
  IfcPositiveLengthMeasure OverallWidth;
  IfcWindowTypeEnum PredefinedType;
  IfcWindowTypePartitioningEnum PartitioningType;
  IfcLabel UserDefinedPartitioningType;
};

struct IfcWindowLiningProperties : IfcPreDefinedPropertySet {
  IfcPositiveLengthMeasure LiningDepth;
  IfcNonNegativeLengthMeasure LiningThickness;
  IfcNonNegativeLengthMeasure TransomThickness;
  IfcNonNegativeLengthMeasure MullionThickness;
  IfcNormalisedRatioMeasure FirstTransomOffset;
  IfcNormalisedRatioMeasure SecondTransomOffset;
  IfcNormalisedRatioMeasure FirstMullionOffset;
  IfcNormalisedRatioMeasure SecondMullionOffset;
  IfcShapeAspect ShapeAspectStyle;
  IfcLengthMeasure LiningOffset;
  IfcLengthMeasure LiningToPanelOffsetX;
  IfcLengthMeasure LiningToPanelOffsetY;
};

struct IfcWindowPanelProperties : IfcPreDefinedPropertySet {
  IfcWindowPanelOperationEnum OperationType;
  IfcWindowPanelPositionEnum PanelPosition;
  IfcPositiveLengthMeasure FrameDepth;
  IfcPositiveLengthMeasure FrameThickness;
  IfcShapeAspect ShapeAspectStyle;
};

struct IfcWindowStandardCase : IfcWindow {};

struct IfcWindowStyle : IfcTypeProduct {
  IfcWindowStyleConstructionEnum ConstructionType;
  IfcWindowStyleOperationEnum OperationType;
  IfcBoolean ParameterTakesPrecedence;
  IfcBoolean Sizeable;
};

struct IfcWindowType : IfcBuildingElementType {
  IfcWindowTypeEnum PredefinedType;
  IfcWindowTypePartitioningEnum PartitioningType;
  IfcBoolean ParameterTakesPrecedence;
  IfcLabel UserDefinedPartitioningType;
};

struct IfcWorkCalendar : IfcControl {
  std::unordered_set<IfcWorkTime> WorkingTimes;
  std::unordered_set<IfcWorkTime> ExceptionTimes;
  IfcWorkCalendarTypeEnum PredefinedType;
};

struct IfcWorkControl : IfcControl {
  IfcDateTime CreationDate;
  std::unordered_set<IfcPerson> Creators;
  IfcLabel Purpose;
  IfcDuration Duration;
  IfcDuration TotalFloat;
  IfcDateTime StartTime;
  IfcDateTime FinishTime;
};

struct IfcWorkPlan : IfcWorkControl {
  IfcWorkPlanTypeEnum PredefinedType;
};

struct IfcWorkSchedule : IfcWorkControl {
  IfcWorkScheduleTypeEnum PredefinedType;
};

struct IfcWorkTime : IfcSchedulingTime {
  IfcRecurrencePattern RecurrencePattern;
  IfcDate Start;
  IfcDate Finish;
};

struct IfcZShapeProfileDef : IfcParameterizedProfileDef {
  IfcPositiveLengthMeasure Depth;
  IfcPositiveLengthMeasure FlangeWidth;
  IfcPositiveLengthMeasure WebThickness;
  IfcPositiveLengthMeasure FlangeThickness;
  IfcNonNegativeLengthMeasure FilletRadius;
  IfcNonNegativeLengthMeasure EdgeRadius;
};

struct IfcZone : IfcSystem {
  IfcLabel LongName;
};

} // namespace ifc::internal

#endif // IMPORT_IFC_EXTERNAL_ENTITIES_H_
