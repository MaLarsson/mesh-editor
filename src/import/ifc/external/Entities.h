#pragma once

#ifndef IMPORT_IFC_EXTERNAL_ENTITIES_H_
#define IMPORT_IFC_EXTERNAL_ENTITIES_H_

#include "../../../utility/SmallVector.h"
#include "Forward.h"
#include "Types.h"

#include <cstddef>
#include <string>
#include <unordered_set>
#include <variant>

namespace ifc::internal {

struct IfcEntity {};

struct IfcRoot : ifc::internal::IfcEntity {
  ifc::IfcGloballyUniqueId GlobalId;
  ifc::IfcOwnerHistory OwnerHistory;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
};

struct IfcObjectDefinition : ifc::internal::IfcRoot {};

struct IfcObject : ifc::internal::IfcObjectDefinition {
  ifc::IfcLabel ObjectType;
};

struct IfcControl : ifc::internal::IfcObject {
  ifc::IfcIdentifier Identification;
};

struct IfcActionRequest : ifc::internal::IfcControl {
  ifc::IfcActionRequestTypeEnum PredefinedType;
  ifc::IfcLabel Status;
  ifc::IfcText LongDescription;
};

struct IfcActor : ifc::internal::IfcObject {
  ifc::IfcActorSelect TheActor;
};

struct IfcActorRole : ifc::internal::IfcEntity {
  ifc::IfcRoleEnum Role;
  ifc::IfcLabel UserDefinedRole;
  ifc::IfcText Description;
};

struct IfcProduct : ifc::internal::IfcObject {
  ifc::IfcObjectPlacement ObjectPlacement;
  ifc::IfcProductRepresentation Representation;
};

struct IfcElement : ifc::internal::IfcProduct {
  ifc::IfcIdentifier Tag;
};

struct IfcDistributionElement : ifc::internal::IfcElement {};

struct IfcDistributionControlElement : ifc::internal::IfcDistributionElement {};

struct IfcActuator : ifc::internal::IfcDistributionControlElement {
  ifc::IfcActuatorTypeEnum PredefinedType;
};

struct IfcTypeObject : ifc::internal::IfcObjectDefinition {
  ifc::IfcIdentifier ApplicableOccurrence;
  std::unordered_set<ifc::IfcPropertySetDefinition> HasPropertySets;
};

struct IfcTypeProduct : ifc::internal::IfcTypeObject {
  SmallVector<ifc::IfcRepresentationMap, 4> RepresentationMaps;
  ifc::IfcLabel Tag;
};

struct IfcElementType : ifc::internal::IfcTypeProduct {
  ifc::IfcLabel ElementType;
};

struct IfcDistributionElementType : ifc::internal::IfcElementType {};

struct IfcDistributionControlElementType : ifc::internal::IfcDistributionElementType {};

struct IfcActuatorType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcActuatorTypeEnum PredefinedType;
};

struct IfcAddress : ifc::internal::IfcEntity {
  ifc::IfcAddressTypeEnum Purpose;
  ifc::IfcText Description;
  ifc::IfcLabel UserDefinedPurpose;
};

struct IfcRepresentationItem : ifc::internal::IfcEntity {};

struct IfcGeometricRepresentationItem : ifc::internal::IfcRepresentationItem {};

struct IfcSolidModel : ifc::internal::IfcGeometricRepresentationItem {};

struct IfcManifoldSolidBrep : ifc::internal::IfcSolidModel {
  ifc::IfcClosedShell Outer;
};

struct IfcAdvancedBrep : ifc::internal::IfcManifoldSolidBrep {};

struct IfcAdvancedBrepWithVoids : ifc::internal::IfcAdvancedBrep {
  std::unordered_set<ifc::IfcClosedShell> Voids;
};

struct IfcTopologicalRepresentationItem : ifc::internal::IfcRepresentationItem {};

struct IfcFace : ifc::internal::IfcTopologicalRepresentationItem {
  std::unordered_set<ifc::IfcFaceBound> Bounds;
};

struct IfcFaceSurface : ifc::internal::IfcFace {
  ifc::IfcSurface FaceSurface;
  ifc::IfcBoolean SameSense;
};

struct IfcAdvancedFace : ifc::internal::IfcFaceSurface {};

struct IfcDistributionFlowElement : ifc::internal::IfcDistributionElement {};

struct IfcFlowTerminal : ifc::internal::IfcDistributionFlowElement {};

struct IfcAirTerminal : ifc::internal::IfcFlowTerminal {
  ifc::IfcAirTerminalTypeEnum PredefinedType;
};

struct IfcFlowController : ifc::internal::IfcDistributionFlowElement {};

struct IfcAirTerminalBox : ifc::internal::IfcFlowController {
  ifc::IfcAirTerminalBoxTypeEnum PredefinedType;
};

struct IfcDistributionFlowElementType : ifc::internal::IfcDistributionElementType {};

struct IfcFlowControllerType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcAirTerminalBoxType : ifc::internal::IfcFlowControllerType {
  ifc::IfcAirTerminalBoxTypeEnum PredefinedType;
};

struct IfcFlowTerminalType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcAirTerminalType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcAirTerminalTypeEnum PredefinedType;
};

struct IfcEnergyConversionDevice : ifc::internal::IfcDistributionFlowElement {};

struct IfcAirToAirHeatRecovery : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcAirToAirHeatRecoveryTypeEnum PredefinedType;
};

struct IfcEnergyConversionDeviceType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcAirToAirHeatRecoveryType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcAirToAirHeatRecoveryTypeEnum PredefinedType;
};

struct IfcAlarm : ifc::internal::IfcDistributionControlElement {
  ifc::IfcAlarmTypeEnum PredefinedType;
};

struct IfcAlarmType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcAlarmTypeEnum PredefinedType;
};

struct IfcPositioningElement : ifc::internal::IfcProduct {};

struct IfcLinearPositioningElement : ifc::internal::IfcPositioningElement {
  ifc::IfcCurve Axis;
};

struct IfcAlignment : ifc::internal::IfcLinearPositioningElement {
  ifc::IfcAlignmentTypeEnum PredefinedType;
};

struct IfcAlignment2DHorizontal : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcLengthMeasure StartDistAlong;
  SmallVector<ifc::IfcAlignment2DHorizontalSegment, 4> Segments;
};

struct IfcAlignment2DSegment : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcBoolean TangentialContinuity;
  ifc::IfcLabel StartTag;
  ifc::IfcLabel EndTag;
};

struct IfcAlignment2DHorizontalSegment : ifc::internal::IfcAlignment2DSegment {
  ifc::IfcCurveSegment2D CurveGeometry;
};

struct IfcAlignment2DVerticalSegment : ifc::internal::IfcAlignment2DSegment {
  ifc::IfcLengthMeasure StartDistAlong;
  ifc::IfcPositiveLengthMeasure HorizontalLength;
  ifc::IfcLengthMeasure StartHeight;
  ifc::IfcRatioMeasure StartGradient;
};

struct IfcAlignment2DVerSegCircularArc : ifc::internal::IfcAlignment2DVerticalSegment {
  ifc::IfcPositiveLengthMeasure Radius;
  ifc::IfcBoolean IsConvex;
};

struct IfcAlignment2DVerSegLine : ifc::internal::IfcAlignment2DVerticalSegment {};

struct IfcAlignment2DVerSegParabolicArc : ifc::internal::IfcAlignment2DVerticalSegment {
  ifc::IfcPositiveLengthMeasure ParabolaConstant;
  ifc::IfcBoolean IsConvex;
};

struct IfcAlignment2DVertical : ifc::internal::IfcGeometricRepresentationItem {
  SmallVector<ifc::IfcAlignment2DVerticalSegment, 4> Segments;
};

struct IfcCurve : ifc::internal::IfcGeometricRepresentationItem {};

struct IfcBoundedCurve : ifc::internal::IfcCurve {};

struct IfcAlignmentCurve : ifc::internal::IfcBoundedCurve {
  ifc::IfcAlignment2DHorizontal Horizontal;
  ifc::IfcAlignment2DVertical Vertical;
  ifc::IfcLabel Tag;
};

struct IfcAnnotation : ifc::internal::IfcProduct {};

struct IfcAnnotationFillArea : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcCurve OuterBoundary;
  std::unordered_set<ifc::IfcCurve> InnerBoundaries;
};

struct IfcApplication : ifc::internal::IfcEntity {
  ifc::IfcOrganization ApplicationDeveloper;
  ifc::IfcLabel Version;
  ifc::IfcLabel ApplicationFullName;
  ifc::IfcIdentifier ApplicationIdentifier;
};

struct IfcAppliedValue : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcAppliedValueSelect AppliedValue;
  ifc::IfcMeasureWithUnit UnitBasis;
  ifc::IfcDate ApplicableDate;
  ifc::IfcDate FixedUntilDate;
  ifc::IfcLabel Category;
  ifc::IfcLabel Condition;
  ifc::IfcArithmeticOperatorEnum ArithmeticOperator;
  SmallVector<ifc::IfcAppliedValue, 4> Components;
};

struct IfcApproval : ifc::internal::IfcEntity {
  ifc::IfcIdentifier Identifier;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcDateTime TimeOfApproval;
  ifc::IfcLabel Status;
  ifc::IfcLabel Level;
  ifc::IfcText Qualifier;
  ifc::IfcActorSelect RequestingApproval;
  ifc::IfcActorSelect GivingApproval;
};

struct IfcResourceLevelRelationship : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
};

struct IfcApprovalRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcApproval RelatingApproval;
  std::unordered_set<ifc::IfcApproval> RelatedApprovals;
};

struct IfcProfileDef : ifc::internal::IfcEntity {
  ifc::IfcProfileTypeEnum ProfileType;
  ifc::IfcLabel ProfileName;
};

struct IfcArbitraryClosedProfileDef : ifc::internal::IfcProfileDef {
  ifc::IfcCurve OuterCurve;
};

struct IfcArbitraryOpenProfileDef : ifc::internal::IfcProfileDef {
  ifc::IfcBoundedCurve Curve;
};

struct IfcArbitraryProfileDefWithVoids : ifc::internal::IfcArbitraryClosedProfileDef {
  std::unordered_set<ifc::IfcCurve> InnerCurves;
};

struct IfcGroup : ifc::internal::IfcObject {};

struct IfcAsset : ifc::internal::IfcGroup {
  ifc::IfcIdentifier Identification;
  ifc::IfcCostValue OriginalValue;
  ifc::IfcCostValue CurrentValue;
  ifc::IfcCostValue TotalReplacementCost;
  ifc::IfcActorSelect Owner;
  ifc::IfcActorSelect User;
  ifc::IfcPerson ResponsiblePerson;
  ifc::IfcDate IncorporationDate;
  ifc::IfcCostValue DepreciatedValue;
};

struct IfcParameterizedProfileDef : ifc::internal::IfcProfileDef {
  ifc::IfcAxis2Placement2D Position;
};

struct IfcAsymmetricIShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure BottomFlangeWidth;
  ifc::IfcPositiveLengthMeasure OverallDepth;
  ifc::IfcPositiveLengthMeasure WebThickness;
  ifc::IfcPositiveLengthMeasure BottomFlangeThickness;
  ifc::IfcNonNegativeLengthMeasure BottomFlangeFilletRadius;
  ifc::IfcPositiveLengthMeasure TopFlangeWidth;
  ifc::IfcPositiveLengthMeasure TopFlangeThickness;
  ifc::IfcNonNegativeLengthMeasure TopFlangeFilletRadius;
  ifc::IfcNonNegativeLengthMeasure BottomFlangeEdgeRadius;
  ifc::IfcPlaneAngleMeasure BottomFlangeSlope;
  ifc::IfcNonNegativeLengthMeasure TopFlangeEdgeRadius;
  ifc::IfcPlaneAngleMeasure TopFlangeSlope;
};

struct IfcAudioVisualAppliance : ifc::internal::IfcFlowTerminal {
  ifc::IfcAudioVisualApplianceTypeEnum PredefinedType;
};

struct IfcAudioVisualApplianceType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcAudioVisualApplianceTypeEnum PredefinedType;
};

struct IfcPlacement : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcCartesianPoint Location;
};

struct IfcAxis1Placement : ifc::internal::IfcPlacement {
  ifc::IfcDirection Axis;
};

struct IfcAxis2Placement2D : ifc::internal::IfcPlacement {
  ifc::IfcDirection RefDirection;
};

struct IfcAxis2Placement3D : ifc::internal::IfcPlacement {
  ifc::IfcDirection Axis;
  ifc::IfcDirection RefDirection;
};

struct IfcBSplineCurve : ifc::internal::IfcBoundedCurve {
  ifc::IfcInteger Degree;
  SmallVector<ifc::IfcCartesianPoint, 4> ControlPointsList;
  ifc::IfcBSplineCurveForm CurveForm;
  ifc::IfcLogical ClosedCurve;
  ifc::IfcLogical SelfIntersect;
};

struct IfcBSplineCurveWithKnots : ifc::internal::IfcBSplineCurve {
  SmallVector<ifc::IfcInteger, 4> KnotMultiplicities;
  SmallVector<ifc::IfcParameterValue, 4> Knots;
  ifc::IfcKnotType KnotSpec;
};

struct IfcSurface : ifc::internal::IfcGeometricRepresentationItem {};

struct IfcBoundedSurface : ifc::internal::IfcSurface {};

struct IfcBSplineSurface : ifc::internal::IfcBoundedSurface {
  ifc::IfcInteger UDegree;
  ifc::IfcInteger VDegree;
  SmallVector<SmallVector<ifc::IfcCartesianPoint, 4>, 4> ControlPointsList;
  ifc::IfcBSplineSurfaceForm SurfaceForm;
  ifc::IfcLogical UClosed;
  ifc::IfcLogical VClosed;
  ifc::IfcLogical SelfIntersect;
};

struct IfcBSplineSurfaceWithKnots : ifc::internal::IfcBSplineSurface {
  SmallVector<ifc::IfcInteger, 4> UMultiplicities;
  SmallVector<ifc::IfcInteger, 4> VMultiplicities;
  SmallVector<ifc::IfcParameterValue, 4> UKnots;
  SmallVector<ifc::IfcParameterValue, 4> VKnots;
  ifc::IfcKnotType KnotSpec;
};

struct IfcBuildingElement : ifc::internal::IfcElement {};

struct IfcBeam : ifc::internal::IfcBuildingElement {
  ifc::IfcBeamTypeEnum PredefinedType;
};

struct IfcBeamStandardCase : ifc::internal::IfcBeam {};

struct IfcBuildingElementType : ifc::internal::IfcElementType {};

struct IfcBeamType : ifc::internal::IfcBuildingElementType {
  ifc::IfcBeamTypeEnum PredefinedType;
};

struct IfcPresentationItem : ifc::internal::IfcEntity {};

struct IfcSurfaceTexture : ifc::internal::IfcPresentationItem {
  ifc::IfcBoolean RepeatS;
  ifc::IfcBoolean RepeatT;
  ifc::IfcIdentifier Mode;
  ifc::IfcCartesianTransformationOperator2D TextureTransform;
  SmallVector<ifc::IfcIdentifier, 4> Parameter;
};

struct IfcBlobTexture : ifc::internal::IfcSurfaceTexture {
  ifc::IfcIdentifier RasterFormat;
  ifc::IfcBinary RasterCode;
};

struct IfcCsgPrimitive3D : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcAxis2Placement3D Position;
};

struct IfcBlock : ifc::internal::IfcCsgPrimitive3D {
  ifc::IfcPositiveLengthMeasure XLength;
  ifc::IfcPositiveLengthMeasure YLength;
  ifc::IfcPositiveLengthMeasure ZLength;
};

struct IfcBoiler : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcBoilerTypeEnum PredefinedType;
};

struct IfcBoilerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcBoilerTypeEnum PredefinedType;
};

struct IfcBooleanResult : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcBooleanOperator Operator;
  ifc::IfcBooleanOperand FirstOperand;
  ifc::IfcBooleanOperand SecondOperand;
};

struct IfcBooleanClippingResult : ifc::internal::IfcBooleanResult {};

struct IfcBoundaryCondition : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
};

struct IfcCompositeCurve : ifc::internal::IfcBoundedCurve {
  SmallVector<ifc::IfcCompositeCurveSegment, 4> Segments;
  ifc::IfcLogical SelfIntersect;
};

struct IfcCompositeCurveOnSurface : ifc::internal::IfcCompositeCurve {};

struct IfcBoundaryCurve : ifc::internal::IfcCompositeCurveOnSurface {};

struct IfcBoundaryEdgeCondition : ifc::internal::IfcBoundaryCondition {
  ifc::IfcModulusOfTranslationalSubgradeReactionSelect TranslationalStiffnessByLengthX;
  ifc::IfcModulusOfTranslationalSubgradeReactionSelect TranslationalStiffnessByLengthY;
  ifc::IfcModulusOfTranslationalSubgradeReactionSelect TranslationalStiffnessByLengthZ;
  ifc::IfcModulusOfRotationalSubgradeReactionSelect RotationalStiffnessByLengthX;
  ifc::IfcModulusOfRotationalSubgradeReactionSelect RotationalStiffnessByLengthY;
  ifc::IfcModulusOfRotationalSubgradeReactionSelect RotationalStiffnessByLengthZ;
};

struct IfcBoundaryFaceCondition : ifc::internal::IfcBoundaryCondition {
  ifc::IfcModulusOfSubgradeReactionSelect TranslationalStiffnessByAreaX;
  ifc::IfcModulusOfSubgradeReactionSelect TranslationalStiffnessByAreaY;
  ifc::IfcModulusOfSubgradeReactionSelect TranslationalStiffnessByAreaZ;
};

struct IfcBoundaryNodeCondition : ifc::internal::IfcBoundaryCondition {
  ifc::IfcTranslationalStiffnessSelect TranslationalStiffnessX;
  ifc::IfcTranslationalStiffnessSelect TranslationalStiffnessY;
  ifc::IfcTranslationalStiffnessSelect TranslationalStiffnessZ;
  ifc::IfcRotationalStiffnessSelect RotationalStiffnessX;
  ifc::IfcRotationalStiffnessSelect RotationalStiffnessY;
  ifc::IfcRotationalStiffnessSelect RotationalStiffnessZ;
};

struct IfcBoundaryNodeConditionWarping : ifc::internal::IfcBoundaryNodeCondition {
  ifc::IfcWarpingStiffnessSelect WarpingStiffness;
};

struct IfcBoundingBox : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcCartesianPoint Corner;
  ifc::IfcPositiveLengthMeasure XDim;
  ifc::IfcPositiveLengthMeasure YDim;
  ifc::IfcPositiveLengthMeasure ZDim;
};

struct IfcHalfSpaceSolid : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcSurface BaseSurface;
  ifc::IfcBoolean AgreementFlag;
};

struct IfcBoxedHalfSpace : ifc::internal::IfcHalfSpaceSolid {
  ifc::IfcBoundingBox Enclosure;
};

struct IfcSpatialElement : ifc::internal::IfcProduct {
  ifc::IfcLabel LongName;
};

struct IfcSpatialStructureElement : ifc::internal::IfcSpatialElement {
  ifc::IfcElementCompositionEnum CompositionType;
};

struct IfcBuilding : ifc::internal::IfcSpatialStructureElement {
  ifc::IfcLengthMeasure ElevationOfRefHeight;
  ifc::IfcLengthMeasure ElevationOfTerrain;
  ifc::IfcPostalAddress BuildingAddress;
};

struct IfcElementComponent : ifc::internal::IfcElement {};

struct IfcBuildingElementPart : ifc::internal::IfcElementComponent {
  ifc::IfcBuildingElementPartTypeEnum PredefinedType;
};

struct IfcElementComponentType : ifc::internal::IfcElementType {};

struct IfcBuildingElementPartType : ifc::internal::IfcElementComponentType {
  ifc::IfcBuildingElementPartTypeEnum PredefinedType;
};

struct IfcBuildingElementProxy : ifc::internal::IfcBuildingElement {
  ifc::IfcBuildingElementProxyTypeEnum PredefinedType;
};

struct IfcBuildingElementProxyType : ifc::internal::IfcBuildingElementType {
  ifc::IfcBuildingElementProxyTypeEnum PredefinedType;
};

struct IfcBuildingStorey : ifc::internal::IfcSpatialStructureElement {
  ifc::IfcLengthMeasure Elevation;
};

struct IfcSystem : ifc::internal::IfcGroup {};

struct IfcBuildingSystem : ifc::internal::IfcSystem {
  ifc::IfcBuildingSystemTypeEnum PredefinedType;
  ifc::IfcLabel LongName;
};

struct IfcBurner : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcBurnerTypeEnum PredefinedType;
};

struct IfcBurnerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcBurnerTypeEnum PredefinedType;
};

struct IfcCShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure Depth;
  ifc::IfcPositiveLengthMeasure Width;
  ifc::IfcPositiveLengthMeasure WallThickness;
  ifc::IfcPositiveLengthMeasure Girth;
  ifc::IfcNonNegativeLengthMeasure InternalFilletRadius;
};

struct IfcFlowFitting : ifc::internal::IfcDistributionFlowElement {};

struct IfcCableCarrierFitting : ifc::internal::IfcFlowFitting {
  ifc::IfcCableCarrierFittingTypeEnum PredefinedType;
};

struct IfcFlowFittingType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcCableCarrierFittingType : ifc::internal::IfcFlowFittingType {
  ifc::IfcCableCarrierFittingTypeEnum PredefinedType;
};

struct IfcFlowSegment : ifc::internal::IfcDistributionFlowElement {};

struct IfcCableCarrierSegment : ifc::internal::IfcFlowSegment {
  ifc::IfcCableCarrierSegmentTypeEnum PredefinedType;
};

struct IfcFlowSegmentType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcCableCarrierSegmentType : ifc::internal::IfcFlowSegmentType {
  ifc::IfcCableCarrierSegmentTypeEnum PredefinedType;
};

struct IfcCableFitting : ifc::internal::IfcFlowFitting {
  ifc::IfcCableFittingTypeEnum PredefinedType;
};

struct IfcCableFittingType : ifc::internal::IfcFlowFittingType {
  ifc::IfcCableFittingTypeEnum PredefinedType;
};

struct IfcCableSegment : ifc::internal::IfcFlowSegment {
  ifc::IfcCableSegmentTypeEnum PredefinedType;
};

struct IfcCableSegmentType : ifc::internal::IfcFlowSegmentType {
  ifc::IfcCableSegmentTypeEnum PredefinedType;
};

struct IfcPoint : ifc::internal::IfcGeometricRepresentationItem {};

struct IfcCartesianPoint : ifc::internal::IfcPoint {
  SmallVector<ifc::IfcLengthMeasure, 3> Coordinates;
};

struct IfcCartesianPointList : ifc::internal::IfcGeometricRepresentationItem {};

struct IfcCartesianPointList2D : ifc::internal::IfcCartesianPointList {
  SmallVector<SmallVector<ifc::IfcLengthMeasure, 2>, 4> CoordList;
  SmallVector<ifc::IfcLabel, 4> TagList;
};

struct IfcCartesianPointList3D : ifc::internal::IfcCartesianPointList {
  SmallVector<SmallVector<ifc::IfcLengthMeasure, 3>, 4> CoordList;
  SmallVector<ifc::IfcLabel, 4> TagList;
};

struct IfcCartesianTransformationOperator : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcDirection Axis1;
  ifc::IfcDirection Axis2;
  ifc::IfcCartesianPoint LocalOrigin;
  ifc::IfcReal Scale;
};

struct IfcCartesianTransformationOperator2D : ifc::internal::IfcCartesianTransformationOperator {};

struct IfcCartesianTransformationOperator2DnonUniform
    : ifc::internal::IfcCartesianTransformationOperator2D {
  ifc::IfcReal Scale2;
};

struct IfcCartesianTransformationOperator3D : ifc::internal::IfcCartesianTransformationOperator {
  ifc::IfcDirection Axis3;
};

struct IfcCartesianTransformationOperator3DnonUniform
    : ifc::internal::IfcCartesianTransformationOperator3D {
  ifc::IfcReal Scale2;
  ifc::IfcReal Scale3;
};

struct IfcCenterLineProfileDef : ifc::internal::IfcArbitraryOpenProfileDef {
  ifc::IfcPositiveLengthMeasure Thickness;
};

struct IfcChiller : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcChillerTypeEnum PredefinedType;
};

struct IfcChillerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcChillerTypeEnum PredefinedType;
};

struct IfcChimney : ifc::internal::IfcBuildingElement {
  ifc::IfcChimneyTypeEnum PredefinedType;
};

struct IfcChimneyType : ifc::internal::IfcBuildingElementType {
  ifc::IfcChimneyTypeEnum PredefinedType;
};

struct IfcConic : ifc::internal::IfcCurve {
  ifc::IfcAxis2Placement Position;
};

struct IfcCircle : ifc::internal::IfcConic {
  ifc::IfcPositiveLengthMeasure Radius;
};

struct IfcCircleProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure Radius;
};

struct IfcCircleHollowProfileDef : ifc::internal::IfcCircleProfileDef {
  ifc::IfcPositiveLengthMeasure WallThickness;
};

struct IfcCurveSegment2D : ifc::internal::IfcBoundedCurve {
  ifc::IfcCartesianPoint StartPoint;
  ifc::IfcPlaneAngleMeasure StartDirection;
  ifc::IfcPositiveLengthMeasure SegmentLength;
};

struct IfcCircularArcSegment2D : ifc::internal::IfcCurveSegment2D {
  ifc::IfcPositiveLengthMeasure Radius;
  ifc::IfcBoolean IsCCW;
};

struct IfcCivilElement : ifc::internal::IfcElement {};

struct IfcCivilElementType : ifc::internal::IfcElementType {};

struct IfcExternalInformation : ifc::internal::IfcEntity {};

struct IfcClassification : ifc::internal::IfcExternalInformation {
  ifc::IfcLabel Source;
  ifc::IfcLabel Edition;
  ifc::IfcDate EditionDate;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcURIReference Location;
  SmallVector<ifc::IfcIdentifier, 4> ReferenceTokens;
};

struct IfcExternalReference : ifc::internal::IfcEntity {
  ifc::IfcURIReference Location;
  ifc::IfcIdentifier Identification;
  ifc::IfcLabel Name;
};

struct IfcClassificationReference : ifc::internal::IfcExternalReference {
  ifc::IfcClassificationReferenceSelect ReferencedSource;
  ifc::IfcText Description;
  ifc::IfcIdentifier Sort;
};

struct IfcConnectedFaceSet : ifc::internal::IfcTopologicalRepresentationItem {
  std::unordered_set<ifc::IfcFace> CfsFaces;
};

struct IfcClosedShell : ifc::internal::IfcConnectedFaceSet {};

struct IfcCoil : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcCoilTypeEnum PredefinedType;
};

struct IfcCoilType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcCoilTypeEnum PredefinedType;
};

struct IfcColourSpecification : ifc::internal::IfcPresentationItem {
  ifc::IfcLabel Name;
};

struct IfcColourRgb : ifc::internal::IfcColourSpecification {
  ifc::IfcNormalisedRatioMeasure Red;
  ifc::IfcNormalisedRatioMeasure Green;
  ifc::IfcNormalisedRatioMeasure Blue;
};

struct IfcColourRgbList : ifc::internal::IfcPresentationItem {
  SmallVector<SmallVector<ifc::IfcNormalisedRatioMeasure, 3>, 4> ColourList;
};

struct IfcColumn : ifc::internal::IfcBuildingElement {
  ifc::IfcColumnTypeEnum PredefinedType;
};

struct IfcColumnStandardCase : ifc::internal::IfcColumn {};

struct IfcColumnType : ifc::internal::IfcBuildingElementType {
  ifc::IfcColumnTypeEnum PredefinedType;
};

struct IfcCommunicationsAppliance : ifc::internal::IfcFlowTerminal {
  ifc::IfcCommunicationsApplianceTypeEnum PredefinedType;
};

struct IfcCommunicationsApplianceType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcCommunicationsApplianceTypeEnum PredefinedType;
};

struct IfcPropertyAbstraction : ifc::internal::IfcEntity {};

struct IfcProperty : ifc::internal::IfcPropertyAbstraction {
  ifc::IfcIdentifier Name;
  ifc::IfcText Description;
};

struct IfcComplexProperty : ifc::internal::IfcProperty {
  ifc::IfcIdentifier UsageName;
  std::unordered_set<ifc::IfcProperty> HasProperties;
};

struct IfcPropertyDefinition : ifc::internal::IfcRoot {};

struct IfcPropertyTemplateDefinition : ifc::internal::IfcPropertyDefinition {};

struct IfcPropertyTemplate : ifc::internal::IfcPropertyTemplateDefinition {};

struct IfcComplexPropertyTemplate : ifc::internal::IfcPropertyTemplate {
  ifc::IfcLabel UsageName;
  ifc::IfcComplexPropertyTemplateTypeEnum TemplateType;
  std::unordered_set<ifc::IfcPropertyTemplate> HasPropertyTemplates;
};

struct IfcCompositeCurveSegment : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcTransitionCode Transition;
  ifc::IfcBoolean SameSense;
  ifc::IfcCurve ParentCurve;
};

struct IfcCompositeProfileDef : ifc::internal::IfcProfileDef {
  std::unordered_set<ifc::IfcProfileDef> Profiles;
  ifc::IfcLabel Label;
};

struct IfcFlowMovingDevice : ifc::internal::IfcDistributionFlowElement {};

struct IfcCompressor : ifc::internal::IfcFlowMovingDevice {
  ifc::IfcCompressorTypeEnum PredefinedType;
};

struct IfcFlowMovingDeviceType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcCompressorType : ifc::internal::IfcFlowMovingDeviceType {
  ifc::IfcCompressorTypeEnum PredefinedType;
};

struct IfcCondenser : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcCondenserTypeEnum PredefinedType;
};

struct IfcCondenserType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcCondenserTypeEnum PredefinedType;
};

struct IfcConnectionGeometry : ifc::internal::IfcEntity {};

struct IfcConnectionCurveGeometry : ifc::internal::IfcConnectionGeometry {
  ifc::IfcCurveOrEdgeCurve CurveOnRelatingElement;
  ifc::IfcCurveOrEdgeCurve CurveOnRelatedElement;
};

struct IfcConnectionPointGeometry : ifc::internal::IfcConnectionGeometry {
  ifc::IfcPointOrVertexPoint PointOnRelatingElement;
  ifc::IfcPointOrVertexPoint PointOnRelatedElement;
};

struct IfcConnectionPointEccentricity : ifc::internal::IfcConnectionPointGeometry {
  ifc::IfcLengthMeasure EccentricityInX;
  ifc::IfcLengthMeasure EccentricityInY;
  ifc::IfcLengthMeasure EccentricityInZ;
};

struct IfcConnectionSurfaceGeometry : ifc::internal::IfcConnectionGeometry {
  ifc::IfcSurfaceOrFaceSurface SurfaceOnRelatingElement;
  ifc::IfcSurfaceOrFaceSurface SurfaceOnRelatedElement;
};

struct IfcConnectionVolumeGeometry : ifc::internal::IfcConnectionGeometry {
  ifc::IfcSolidOrShell VolumeOnRelatingElement;
  ifc::IfcSolidOrShell VolumeOnRelatedElement;
};

struct IfcConstraint : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcConstraintEnum ConstraintGrade;
  ifc::IfcLabel ConstraintSource;
  ifc::IfcActorSelect CreatingActor;
  ifc::IfcDateTime CreationTime;
  ifc::IfcLabel UserDefinedGrade;
};

struct IfcResource : ifc::internal::IfcObject {
  ifc::IfcIdentifier Identification;
  ifc::IfcText LongDescription;
};

struct IfcConstructionResource : ifc::internal::IfcResource {
  ifc::IfcResourceTime Usage;
  SmallVector<ifc::IfcAppliedValue, 4> BaseCosts;
  ifc::IfcPhysicalQuantity BaseQuantity;
};

struct IfcConstructionEquipmentResource : ifc::internal::IfcConstructionResource {
  ifc::IfcConstructionEquipmentResourceTypeEnum PredefinedType;
};

struct IfcTypeResource : ifc::internal::IfcTypeObject {
  ifc::IfcIdentifier Identification;
  ifc::IfcText LongDescription;
  ifc::IfcLabel ResourceType;
};

struct IfcConstructionResourceType : ifc::internal::IfcTypeResource {
  SmallVector<ifc::IfcAppliedValue, 4> BaseCosts;
  ifc::IfcPhysicalQuantity BaseQuantity;
};

struct IfcConstructionEquipmentResourceType : ifc::internal::IfcConstructionResourceType {
  ifc::IfcConstructionEquipmentResourceTypeEnum PredefinedType;
};

struct IfcConstructionMaterialResource : ifc::internal::IfcConstructionResource {
  ifc::IfcConstructionMaterialResourceTypeEnum PredefinedType;
};

struct IfcConstructionMaterialResourceType : ifc::internal::IfcConstructionResourceType {
  ifc::IfcConstructionMaterialResourceTypeEnum PredefinedType;
};

struct IfcConstructionProductResource : ifc::internal::IfcConstructionResource {
  ifc::IfcConstructionProductResourceTypeEnum PredefinedType;
};

struct IfcConstructionProductResourceType : ifc::internal::IfcConstructionResourceType {
  ifc::IfcConstructionProductResourceTypeEnum PredefinedType;
};

struct IfcContext : ifc::internal::IfcObjectDefinition {
  ifc::IfcLabel ObjectType;
  ifc::IfcLabel LongName;
  ifc::IfcLabel Phase;
  std::unordered_set<ifc::IfcRepresentationContext> RepresentationContexts;
  ifc::IfcUnitAssignment UnitsInContext;
};

struct IfcNamedUnit : ifc::internal::IfcEntity {
  ifc::IfcDimensionalExponents Dimensions;
  ifc::IfcUnitEnum UnitType;
};

struct IfcContextDependentUnit : ifc::internal::IfcNamedUnit {
  ifc::IfcLabel Name;
};

struct IfcController : ifc::internal::IfcDistributionControlElement {
  ifc::IfcControllerTypeEnum PredefinedType;
};

struct IfcControllerType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcControllerTypeEnum PredefinedType;
};

struct IfcConversionBasedUnit : ifc::internal::IfcNamedUnit {
  ifc::IfcLabel Name;
  ifc::IfcMeasureWithUnit ConversionFactor;
};

struct IfcConversionBasedUnitWithOffset : ifc::internal::IfcConversionBasedUnit {
  ifc::IfcReal ConversionOffset;
};

struct IfcCooledBeam : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcCooledBeamTypeEnum PredefinedType;
};

struct IfcCooledBeamType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcCooledBeamTypeEnum PredefinedType;
};

struct IfcCoolingTower : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcCoolingTowerTypeEnum PredefinedType;
};

struct IfcCoolingTowerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcCoolingTowerTypeEnum PredefinedType;
};

struct IfcCoordinateOperation : ifc::internal::IfcEntity {
  ifc::IfcCoordinateReferenceSystemSelect SourceCRS;
  ifc::IfcCoordinateReferenceSystem TargetCRS;
};

struct IfcCoordinateReferenceSystem : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcIdentifier GeodeticDatum;
  ifc::IfcIdentifier VerticalDatum;
};

struct IfcCostItem : ifc::internal::IfcControl {
  ifc::IfcCostItemTypeEnum PredefinedType;
  SmallVector<ifc::IfcCostValue, 4> CostValues;
  SmallVector<ifc::IfcPhysicalQuantity, 4> CostQuantities;
};

struct IfcCostSchedule : ifc::internal::IfcControl {
  ifc::IfcCostScheduleTypeEnum PredefinedType;
  ifc::IfcLabel Status;
  ifc::IfcDateTime SubmittedOn;
  ifc::IfcDateTime UpdateDate;
};

struct IfcCostValue : ifc::internal::IfcAppliedValue {};

struct IfcCovering : ifc::internal::IfcBuildingElement {
  ifc::IfcCoveringTypeEnum PredefinedType;
};

struct IfcCoveringType : ifc::internal::IfcBuildingElementType {
  ifc::IfcCoveringTypeEnum PredefinedType;
};

struct IfcCrewResource : ifc::internal::IfcConstructionResource {
  ifc::IfcCrewResourceTypeEnum PredefinedType;
};

struct IfcCrewResourceType : ifc::internal::IfcConstructionResourceType {
  ifc::IfcCrewResourceTypeEnum PredefinedType;
};

struct IfcCsgSolid : ifc::internal::IfcSolidModel {
  ifc::IfcCsgSelect TreeRootExpression;
};

struct IfcCurrencyRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcMonetaryUnit RelatingMonetaryUnit;
  ifc::IfcMonetaryUnit RelatedMonetaryUnit;
  ifc::IfcPositiveRatioMeasure ExchangeRate;
  ifc::IfcDateTime RateDateTime;
  ifc::IfcLibraryInformation RateSource;
};

struct IfcCurtainWall : ifc::internal::IfcBuildingElement {
  ifc::IfcCurtainWallTypeEnum PredefinedType;
};

struct IfcCurtainWallType : ifc::internal::IfcBuildingElementType {
  ifc::IfcCurtainWallTypeEnum PredefinedType;
};

struct IfcCurveBoundedPlane : ifc::internal::IfcBoundedSurface {
  ifc::IfcPlane BasisSurface;
  ifc::IfcCurve OuterBoundary;
  std::unordered_set<ifc::IfcCurve> InnerBoundaries;
};

struct IfcCurveBoundedSurface : ifc::internal::IfcBoundedSurface {
  ifc::IfcSurface BasisSurface;
  std::unordered_set<ifc::IfcBoundaryCurve> Boundaries;
  ifc::IfcBoolean ImplicitOuter;
};

struct IfcPresentationStyle : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
};

struct IfcCurveStyle : ifc::internal::IfcPresentationStyle {
  ifc::IfcCurveFontOrScaledCurveFontSelect CurveFont;
  ifc::IfcSizeSelect CurveWidth;
  ifc::IfcColour CurveColour;
  ifc::IfcBoolean ModelOrDraughting;
};

struct IfcCurveStyleFont : ifc::internal::IfcPresentationItem {
  ifc::IfcLabel Name;
  SmallVector<ifc::IfcCurveStyleFontPattern, 4> PatternList;
};

struct IfcCurveStyleFontAndScaling : ifc::internal::IfcPresentationItem {
  ifc::IfcLabel Name;
  ifc::IfcCurveStyleFontSelect CurveFont;
  ifc::IfcPositiveRatioMeasure CurveFontScaling;
};

struct IfcCurveStyleFontPattern : ifc::internal::IfcPresentationItem {
  ifc::IfcLengthMeasure VisibleSegmentLength;
  ifc::IfcPositiveLengthMeasure InvisibleSegmentLength;
};

struct IfcElementarySurface : ifc::internal::IfcSurface {
  ifc::IfcAxis2Placement3D Position;
};

struct IfcCylindricalSurface : ifc::internal::IfcElementarySurface {
  ifc::IfcPositiveLengthMeasure Radius;
};

struct IfcDamper : ifc::internal::IfcFlowController {
  ifc::IfcDamperTypeEnum PredefinedType;
};

struct IfcDamperType : ifc::internal::IfcFlowControllerType {
  ifc::IfcDamperTypeEnum PredefinedType;
};

struct IfcDerivedProfileDef : ifc::internal::IfcProfileDef {
  ifc::IfcProfileDef ParentProfile;
  ifc::IfcCartesianTransformationOperator2D Operator;
  ifc::IfcLabel Label;
};

struct IfcDerivedUnit : ifc::internal::IfcEntity {
  std::unordered_set<ifc::IfcDerivedUnitElement> Elements;
  ifc::IfcDerivedUnitEnum UnitType;
  ifc::IfcLabel UserDefinedType;
};

struct IfcDerivedUnitElement : ifc::internal::IfcEntity {
  ifc::IfcNamedUnit Unit;
  int Exponent;
};

struct IfcDimensionalExponents : ifc::internal::IfcEntity {
  int LengthExponent;
  int MassExponent;
  int TimeExponent;
  int ElectricCurrentExponent;
  int ThermodynamicTemperatureExponent;
  int AmountOfSubstanceExponent;
  int LuminousIntensityExponent;
};

struct IfcDirection : ifc::internal::IfcGeometricRepresentationItem {
  SmallVector<ifc::IfcReal, 3> DirectionRatios;
};

struct IfcDiscreteAccessory : ifc::internal::IfcElementComponent {
  ifc::IfcDiscreteAccessoryTypeEnum PredefinedType;
};

struct IfcDiscreteAccessoryType : ifc::internal::IfcElementComponentType {
  ifc::IfcDiscreteAccessoryTypeEnum PredefinedType;
};

struct IfcDistanceExpression : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcLengthMeasure DistanceAlong;
  ifc::IfcLengthMeasure OffsetLateral;
  ifc::IfcLengthMeasure OffsetVertical;
  ifc::IfcLengthMeasure OffsetLongitudinal;
  ifc::IfcBoolean AlongHorizontal;
};

struct IfcDistributionChamberElement : ifc::internal::IfcDistributionFlowElement {
  ifc::IfcDistributionChamberElementTypeEnum PredefinedType;
};

struct IfcDistributionChamberElementType : ifc::internal::IfcDistributionFlowElementType {
  ifc::IfcDistributionChamberElementTypeEnum PredefinedType;
};

struct IfcDistributionSystem : ifc::internal::IfcSystem {
  ifc::IfcLabel LongName;
  ifc::IfcDistributionSystemEnum PredefinedType;
};

struct IfcDistributionCircuit : ifc::internal::IfcDistributionSystem {};

struct IfcPort : ifc::internal::IfcProduct {};

struct IfcDistributionPort : ifc::internal::IfcPort {
  ifc::IfcFlowDirectionEnum FlowDirection;
  ifc::IfcDistributionPortTypeEnum PredefinedType;
  ifc::IfcDistributionSystemEnum SystemType;
};

struct IfcDocumentInformation : ifc::internal::IfcExternalInformation {
  ifc::IfcIdentifier Identification;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcURIReference Location;
  ifc::IfcText Purpose;
  ifc::IfcText IntendedUse;
  ifc::IfcText Scope;
  ifc::IfcLabel Revision;
  ifc::IfcActorSelect DocumentOwner;
  std::unordered_set<ifc::IfcActorSelect> Editors;
  ifc::IfcDateTime CreationTime;
  ifc::IfcDateTime LastRevisionTime;
  ifc::IfcIdentifier ElectronicFormat;
  ifc::IfcDate ValidFrom;
  ifc::IfcDate ValidUntil;
  ifc::IfcDocumentConfidentialityEnum Confidentiality;
  ifc::IfcDocumentStatusEnum Status;
};

struct IfcDocumentInformationRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcDocumentInformation RelatingDocument;
  std::unordered_set<ifc::IfcDocumentInformation> RelatedDocuments;
  ifc::IfcLabel RelationshipType;
};

struct IfcDocumentReference : ifc::internal::IfcExternalReference {
  ifc::IfcText Description;
  ifc::IfcDocumentInformation ReferencedDocument;
};

struct IfcDoor : ifc::internal::IfcBuildingElement {
  ifc::IfcPositiveLengthMeasure OverallHeight;
  ifc::IfcPositiveLengthMeasure OverallWidth;
  ifc::IfcDoorTypeEnum PredefinedType;
  ifc::IfcDoorTypeOperationEnum OperationType;
  ifc::IfcLabel UserDefinedOperationType;
};

struct IfcPropertySetDefinition : ifc::internal::IfcPropertyDefinition {};

struct IfcPreDefinedPropertySet : ifc::internal::IfcPropertySetDefinition {};

struct IfcDoorLiningProperties : ifc::internal::IfcPreDefinedPropertySet {
  ifc::IfcPositiveLengthMeasure LiningDepth;
  ifc::IfcNonNegativeLengthMeasure LiningThickness;
  ifc::IfcPositiveLengthMeasure ThresholdDepth;
  ifc::IfcNonNegativeLengthMeasure ThresholdThickness;
  ifc::IfcNonNegativeLengthMeasure TransomThickness;
  ifc::IfcLengthMeasure TransomOffset;
  ifc::IfcLengthMeasure LiningOffset;
  ifc::IfcLengthMeasure ThresholdOffset;
  ifc::IfcPositiveLengthMeasure CasingThickness;
  ifc::IfcPositiveLengthMeasure CasingDepth;
  ifc::IfcShapeAspect ShapeAspectStyle;
  ifc::IfcLengthMeasure LiningToPanelOffsetX;
  ifc::IfcLengthMeasure LiningToPanelOffsetY;
};

struct IfcDoorPanelProperties : ifc::internal::IfcPreDefinedPropertySet {
  ifc::IfcPositiveLengthMeasure PanelDepth;
  ifc::IfcDoorPanelOperationEnum PanelOperation;
  ifc::IfcNormalisedRatioMeasure PanelWidth;
  ifc::IfcDoorPanelPositionEnum PanelPosition;
  ifc::IfcShapeAspect ShapeAspectStyle;
};

struct IfcDoorStandardCase : ifc::internal::IfcDoor {};

struct IfcDoorStyle : ifc::internal::IfcTypeProduct {
  ifc::IfcDoorStyleOperationEnum OperationType;
  ifc::IfcDoorStyleConstructionEnum ConstructionType;
  ifc::IfcBoolean ParameterTakesPrecedence;
  ifc::IfcBoolean Sizeable;
};

struct IfcDoorType : ifc::internal::IfcBuildingElementType {
  ifc::IfcDoorTypeEnum PredefinedType;
  ifc::IfcDoorTypeOperationEnum OperationType;
  ifc::IfcBoolean ParameterTakesPrecedence;
  ifc::IfcLabel UserDefinedOperationType;
};

struct IfcPreDefinedItem : ifc::internal::IfcPresentationItem {
  ifc::IfcLabel Name;
};

struct IfcPreDefinedColour : ifc::internal::IfcPreDefinedItem {};

struct IfcDraughtingPreDefinedColour : ifc::internal::IfcPreDefinedColour {};

struct IfcPreDefinedCurveFont : ifc::internal::IfcPreDefinedItem {};

struct IfcDraughtingPreDefinedCurveFont : ifc::internal::IfcPreDefinedCurveFont {};

struct IfcDuctFitting : ifc::internal::IfcFlowFitting {
  ifc::IfcDuctFittingTypeEnum PredefinedType;
};

struct IfcDuctFittingType : ifc::internal::IfcFlowFittingType {
  ifc::IfcDuctFittingTypeEnum PredefinedType;
};

struct IfcDuctSegment : ifc::internal::IfcFlowSegment {
  ifc::IfcDuctSegmentTypeEnum PredefinedType;
};

struct IfcDuctSegmentType : ifc::internal::IfcFlowSegmentType {
  ifc::IfcDuctSegmentTypeEnum PredefinedType;
};

struct IfcFlowTreatmentDevice : ifc::internal::IfcDistributionFlowElement {};

struct IfcDuctSilencer : ifc::internal::IfcFlowTreatmentDevice {
  ifc::IfcDuctSilencerTypeEnum PredefinedType;
};

struct IfcFlowTreatmentDeviceType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcDuctSilencerType : ifc::internal::IfcFlowTreatmentDeviceType {
  ifc::IfcDuctSilencerTypeEnum PredefinedType;
};

struct IfcEdge : ifc::internal::IfcTopologicalRepresentationItem {
  ifc::IfcVertex EdgeStart;
  ifc::IfcVertex EdgeEnd;
};

struct IfcEdgeCurve : ifc::internal::IfcEdge {
  ifc::IfcCurve EdgeGeometry;
  ifc::IfcBoolean SameSense;
};

struct IfcLoop : ifc::internal::IfcTopologicalRepresentationItem {};

struct IfcEdgeLoop : ifc::internal::IfcLoop {
  SmallVector<ifc::IfcOrientedEdge, 4> EdgeList;
};

struct IfcElectricAppliance : ifc::internal::IfcFlowTerminal {
  ifc::IfcElectricApplianceTypeEnum PredefinedType;
};

struct IfcElectricApplianceType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcElectricApplianceTypeEnum PredefinedType;
};

struct IfcElectricDistributionBoard : ifc::internal::IfcFlowController {
  ifc::IfcElectricDistributionBoardTypeEnum PredefinedType;
};

struct IfcElectricDistributionBoardType : ifc::internal::IfcFlowControllerType {
  ifc::IfcElectricDistributionBoardTypeEnum PredefinedType;
};

struct IfcFlowStorageDevice : ifc::internal::IfcDistributionFlowElement {};

struct IfcElectricFlowStorageDevice : ifc::internal::IfcFlowStorageDevice {
  ifc::IfcElectricFlowStorageDeviceTypeEnum PredefinedType;
};

struct IfcFlowStorageDeviceType : ifc::internal::IfcDistributionFlowElementType {};

struct IfcElectricFlowStorageDeviceType : ifc::internal::IfcFlowStorageDeviceType {
  ifc::IfcElectricFlowStorageDeviceTypeEnum PredefinedType;
};

struct IfcElectricGenerator : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcElectricGeneratorTypeEnum PredefinedType;
};

struct IfcElectricGeneratorType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcElectricGeneratorTypeEnum PredefinedType;
};

struct IfcElectricMotor : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcElectricMotorTypeEnum PredefinedType;
};

struct IfcElectricMotorType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcElectricMotorTypeEnum PredefinedType;
};

struct IfcElectricTimeControl : ifc::internal::IfcFlowController {
  ifc::IfcElectricTimeControlTypeEnum PredefinedType;
};

struct IfcElectricTimeControlType : ifc::internal::IfcFlowControllerType {
  ifc::IfcElectricTimeControlTypeEnum PredefinedType;
};

struct IfcElementAssembly : ifc::internal::IfcElement {
  ifc::IfcAssemblyPlaceEnum AssemblyPlace;
  ifc::IfcElementAssemblyTypeEnum PredefinedType;
};

struct IfcElementAssemblyType : ifc::internal::IfcElementType {
  ifc::IfcElementAssemblyTypeEnum PredefinedType;
};

struct IfcQuantitySet : ifc::internal::IfcPropertySetDefinition {};

struct IfcElementQuantity : ifc::internal::IfcQuantitySet {
  ifc::IfcLabel MethodOfMeasurement;
  std::unordered_set<ifc::IfcPhysicalQuantity> Quantities;
};

struct IfcEllipse : ifc::internal::IfcConic {
  ifc::IfcPositiveLengthMeasure SemiAxis1;
  ifc::IfcPositiveLengthMeasure SemiAxis2;
};

struct IfcEllipseProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure SemiAxis1;
  ifc::IfcPositiveLengthMeasure SemiAxis2;
};

struct IfcEngine : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcEngineTypeEnum PredefinedType;
};

struct IfcEngineType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcEngineTypeEnum PredefinedType;
};

struct IfcEvaporativeCooler : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcEvaporativeCoolerTypeEnum PredefinedType;
};

struct IfcEvaporativeCoolerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcEvaporativeCoolerTypeEnum PredefinedType;
};

struct IfcEvaporator : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcEvaporatorTypeEnum PredefinedType;
};

struct IfcEvaporatorType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcEvaporatorTypeEnum PredefinedType;
};

struct IfcProcess : ifc::internal::IfcObject {
  ifc::IfcIdentifier Identification;
  ifc::IfcText LongDescription;
};

struct IfcEvent : ifc::internal::IfcProcess {
  ifc::IfcEventTypeEnum PredefinedType;
  ifc::IfcEventTriggerTypeEnum EventTriggerType;
  ifc::IfcLabel UserDefinedEventTriggerType;
  ifc::IfcEventTime EventOccurenceTime;
};

struct IfcSchedulingTime : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcDataOriginEnum DataOrigin;
  ifc::IfcLabel UserDefinedDataOrigin;
};

struct IfcEventTime : ifc::internal::IfcSchedulingTime {
  ifc::IfcDateTime ActualDate;
  ifc::IfcDateTime EarlyDate;
  ifc::IfcDateTime LateDate;
  ifc::IfcDateTime ScheduleDate;
};

struct IfcTypeProcess : ifc::internal::IfcTypeObject {
  ifc::IfcIdentifier Identification;
  ifc::IfcText LongDescription;
  ifc::IfcLabel ProcessType;
};

struct IfcEventType : ifc::internal::IfcTypeProcess {
  ifc::IfcEventTypeEnum PredefinedType;
  ifc::IfcEventTriggerTypeEnum EventTriggerType;
  ifc::IfcLabel UserDefinedEventTriggerType;
};

struct IfcExtendedProperties : ifc::internal::IfcPropertyAbstraction {
  ifc::IfcIdentifier Name;
  ifc::IfcText Description;
  std::unordered_set<ifc::IfcProperty> Properties;
};

struct IfcExternalReferenceRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcExternalReference RelatingReference;
  std::unordered_set<ifc::IfcResourceObjectSelect> RelatedResourceObjects;
};

struct IfcExternalSpatialStructureElement : ifc::internal::IfcSpatialElement {};

struct IfcExternalSpatialElement : ifc::internal::IfcExternalSpatialStructureElement {
  ifc::IfcExternalSpatialElementTypeEnum PredefinedType;
};

struct IfcExternallyDefinedHatchStyle : ifc::internal::IfcExternalReference {};

struct IfcExternallyDefinedSurfaceStyle : ifc::internal::IfcExternalReference {};

struct IfcExternallyDefinedTextFont : ifc::internal::IfcExternalReference {};

struct IfcSweptAreaSolid : ifc::internal::IfcSolidModel {
  ifc::IfcProfileDef SweptArea;
  ifc::IfcAxis2Placement3D Position;
};

struct IfcExtrudedAreaSolid : ifc::internal::IfcSweptAreaSolid {
  ifc::IfcDirection ExtrudedDirection;
  ifc::IfcPositiveLengthMeasure Depth;
};

struct IfcExtrudedAreaSolidTapered : ifc::internal::IfcExtrudedAreaSolid {
  ifc::IfcProfileDef EndSweptArea;
};

struct IfcFaceBasedSurfaceModel : ifc::internal::IfcGeometricRepresentationItem {
  std::unordered_set<ifc::IfcConnectedFaceSet> FbsmFaces;
};

struct IfcFaceBound : ifc::internal::IfcTopologicalRepresentationItem {
  ifc::IfcLoop Bound;
  ifc::IfcBoolean Orientation;
};

struct IfcFaceOuterBound : ifc::internal::IfcFaceBound {};

struct IfcFacetedBrep : ifc::internal::IfcManifoldSolidBrep {};

struct IfcFacetedBrepWithVoids : ifc::internal::IfcFacetedBrep {
  std::unordered_set<ifc::IfcClosedShell> Voids;
};

struct IfcStructuralConnectionCondition : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
};

struct IfcFailureConnectionCondition : ifc::internal::IfcStructuralConnectionCondition {
  ifc::IfcForceMeasure TensionFailureX;
  ifc::IfcForceMeasure TensionFailureY;
  ifc::IfcForceMeasure TensionFailureZ;
  ifc::IfcForceMeasure CompressionFailureX;
  ifc::IfcForceMeasure CompressionFailureY;
  ifc::IfcForceMeasure CompressionFailureZ;
};

struct IfcFan : ifc::internal::IfcFlowMovingDevice {
  ifc::IfcFanTypeEnum PredefinedType;
};

struct IfcFanType : ifc::internal::IfcFlowMovingDeviceType {
  ifc::IfcFanTypeEnum PredefinedType;
};

struct IfcFastener : ifc::internal::IfcElementComponent {
  ifc::IfcFastenerTypeEnum PredefinedType;
};

struct IfcFastenerType : ifc::internal::IfcElementComponentType {
  ifc::IfcFastenerTypeEnum PredefinedType;
};

struct IfcFeatureElement : ifc::internal::IfcElement {};

struct IfcFeatureElementAddition : ifc::internal::IfcFeatureElement {};

struct IfcFeatureElementSubtraction : ifc::internal::IfcFeatureElement {};

struct IfcFillAreaStyle : ifc::internal::IfcPresentationStyle {
  std::unordered_set<ifc::IfcFillStyleSelect> FillStyles;
  ifc::IfcBoolean ModelorDraughting;
};

struct IfcFillAreaStyleHatching : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcCurveStyle HatchLineAppearance;
  ifc::IfcHatchLineDistanceSelect StartOfNextHatchLine;
  ifc::IfcCartesianPoint PointOfReferenceHatchLine;
  ifc::IfcCartesianPoint PatternStart;
  ifc::IfcPlaneAngleMeasure HatchLineAngle;
};

struct IfcFillAreaStyleTiles : ifc::internal::IfcGeometricRepresentationItem {
  SmallVector<ifc::IfcVector, 2> TilingPattern;
  std::unordered_set<ifc::IfcStyledItem> Tiles;
  ifc::IfcPositiveRatioMeasure TilingScale;
};

struct IfcFilter : ifc::internal::IfcFlowTreatmentDevice {
  ifc::IfcFilterTypeEnum PredefinedType;
};

struct IfcFilterType : ifc::internal::IfcFlowTreatmentDeviceType {
  ifc::IfcFilterTypeEnum PredefinedType;
};

struct IfcFireSuppressionTerminal : ifc::internal::IfcFlowTerminal {
  ifc::IfcFireSuppressionTerminalTypeEnum PredefinedType;
};

struct IfcFireSuppressionTerminalType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcFireSuppressionTerminalTypeEnum PredefinedType;
};

struct IfcFixedReferenceSweptAreaSolid : ifc::internal::IfcSweptAreaSolid {
  ifc::IfcCurve Directrix;
  ifc::IfcParameterValue StartParam;
  ifc::IfcParameterValue EndParam;
  ifc::IfcDirection FixedReference;
};

struct IfcFlowInstrument : ifc::internal::IfcDistributionControlElement {
  ifc::IfcFlowInstrumentTypeEnum PredefinedType;
};

struct IfcFlowInstrumentType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcFlowInstrumentTypeEnum PredefinedType;
};

struct IfcFlowMeter : ifc::internal::IfcFlowController {
  ifc::IfcFlowMeterTypeEnum PredefinedType;
};

struct IfcFlowMeterType : ifc::internal::IfcFlowControllerType {
  ifc::IfcFlowMeterTypeEnum PredefinedType;
};

struct IfcFooting : ifc::internal::IfcBuildingElement {
  ifc::IfcFootingTypeEnum PredefinedType;
};

struct IfcFootingType : ifc::internal::IfcBuildingElementType {
  ifc::IfcFootingTypeEnum PredefinedType;
};

struct IfcFurnishingElement : ifc::internal::IfcElement {};

struct IfcFurnishingElementType : ifc::internal::IfcElementType {};

struct IfcFurniture : ifc::internal::IfcFurnishingElement {
  ifc::IfcFurnitureTypeEnum PredefinedType;
};

struct IfcFurnitureType : ifc::internal::IfcFurnishingElementType {
  ifc::IfcAssemblyPlaceEnum AssemblyPlace;
  ifc::IfcFurnitureTypeEnum PredefinedType;
};

struct IfcGeographicElement : ifc::internal::IfcElement {
  ifc::IfcGeographicElementTypeEnum PredefinedType;
};

struct IfcGeographicElementType : ifc::internal::IfcElementType {
  ifc::IfcGeographicElementTypeEnum PredefinedType;
};

struct IfcGeometricSet : ifc::internal::IfcGeometricRepresentationItem {
  std::unordered_set<ifc::IfcGeometricSetSelect> Elements;
};

struct IfcGeometricCurveSet : ifc::internal::IfcGeometricSet {};

struct IfcRepresentationContext : ifc::internal::IfcEntity {
  ifc::IfcLabel ContextIdentifier;
  ifc::IfcLabel ContextType;
};

struct IfcGeometricRepresentationContext : ifc::internal::IfcRepresentationContext {
  ifc::IfcDimensionCount CoordinateSpaceDimension;
  ifc::IfcReal Precision;
  ifc::IfcAxis2Placement WorldCoordinateSystem;
  ifc::IfcDirection TrueNorth;
};

struct IfcGeometricRepresentationSubContext : ifc::internal::IfcGeometricRepresentationContext {
  ifc::IfcGeometricRepresentationContext ParentContext;
  ifc::IfcPositiveRatioMeasure TargetScale;
  ifc::IfcGeometricProjectionEnum TargetView;
  ifc::IfcLabel UserDefinedTargetView;
};

struct IfcGrid : ifc::internal::IfcPositioningElement {
  SmallVector<ifc::IfcGridAxis, 4> UAxes;
  SmallVector<ifc::IfcGridAxis, 4> VAxes;
  SmallVector<ifc::IfcGridAxis, 4> WAxes;
  ifc::IfcGridTypeEnum PredefinedType;
};

struct IfcGridAxis : ifc::internal::IfcEntity {
  ifc::IfcLabel AxisTag;
  ifc::IfcCurve AxisCurve;
  ifc::IfcBoolean SameSense;
};

struct IfcObjectPlacement : ifc::internal::IfcEntity {};

struct IfcGridPlacement : ifc::internal::IfcObjectPlacement {
  ifc::IfcVirtualGridIntersection PlacementLocation;
  ifc::IfcGridPlacementDirectionSelect PlacementRefDirection;
};

struct IfcHeatExchanger : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcHeatExchangerTypeEnum PredefinedType;
};

struct IfcHeatExchangerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcHeatExchangerTypeEnum PredefinedType;
};

struct IfcHumidifier : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcHumidifierTypeEnum PredefinedType;
};

struct IfcHumidifierType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcHumidifierTypeEnum PredefinedType;
};

struct IfcIShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure OverallWidth;
  ifc::IfcPositiveLengthMeasure OverallDepth;
  ifc::IfcPositiveLengthMeasure WebThickness;
  ifc::IfcPositiveLengthMeasure FlangeThickness;
  ifc::IfcNonNegativeLengthMeasure FilletRadius;
  ifc::IfcNonNegativeLengthMeasure FlangeEdgeRadius;
  ifc::IfcPlaneAngleMeasure FlangeSlope;
};

struct IfcImageTexture : ifc::internal::IfcSurfaceTexture {
  ifc::IfcURIReference URLReference;
};

struct IfcIndexedColourMap : ifc::internal::IfcPresentationItem {
  ifc::IfcTessellatedFaceSet MappedTo;
  ifc::IfcNormalisedRatioMeasure Opacity;
  ifc::IfcColourRgbList Colours;
  SmallVector<ifc::IfcPositiveInteger, 4> ColourIndex;
};

struct IfcIndexedPolyCurve : ifc::internal::IfcBoundedCurve {
  ifc::IfcCartesianPointList Points;
  SmallVector<ifc::IfcSegmentIndexSelect, 4> Segments;
  ifc::IfcBoolean SelfIntersect;
};

struct IfcTessellatedItem : ifc::internal::IfcGeometricRepresentationItem {};

struct IfcIndexedPolygonalFace : ifc::internal::IfcTessellatedItem {
  SmallVector<ifc::IfcPositiveInteger, 4> CoordIndex;
};

struct IfcIndexedPolygonalFaceWithVoids : ifc::internal::IfcIndexedPolygonalFace {
  SmallVector<SmallVector<ifc::IfcPositiveInteger, 4>, 4> InnerCoordIndices;
};

struct IfcTextureCoordinate : ifc::internal::IfcPresentationItem {
  SmallVector<ifc::IfcSurfaceTexture, 4> Maps;
};

struct IfcIndexedTextureMap : ifc::internal::IfcTextureCoordinate {
  ifc::IfcTessellatedFaceSet MappedTo;
  ifc::IfcTextureVertexList TexCoords;
};

struct IfcIndexedTriangleTextureMap : ifc::internal::IfcIndexedTextureMap {
  SmallVector<SmallVector<ifc::IfcPositiveInteger, 3>, 4> TexCoordIndex;
};

struct IfcInterceptor : ifc::internal::IfcFlowTreatmentDevice {
  ifc::IfcInterceptorTypeEnum PredefinedType;
};

struct IfcInterceptorType : ifc::internal::IfcFlowTreatmentDeviceType {
  ifc::IfcInterceptorTypeEnum PredefinedType;
};

struct IfcSurfaceCurve : ifc::internal::IfcCurve {
  ifc::IfcCurve Curve3D;
  SmallVector<ifc::IfcPcurve, 2> AssociatedGeometry;
  ifc::IfcPreferredSurfaceCurveRepresentation MasterRepresentation;
};

struct IfcIntersectionCurve : ifc::internal::IfcSurfaceCurve {};

struct IfcInventory : ifc::internal::IfcGroup {
  ifc::IfcInventoryTypeEnum PredefinedType;
  ifc::IfcActorSelect Jurisdiction;
  std::unordered_set<ifc::IfcPerson> ResponsiblePersons;
  ifc::IfcDate LastUpdateDate;
  ifc::IfcCostValue CurrentValue;
  ifc::IfcCostValue OriginalValue;
};

struct IfcTimeSeries : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcDateTime StartTime;
  ifc::IfcDateTime EndTime;
  ifc::IfcTimeSeriesDataTypeEnum TimeSeriesDataType;
  ifc::IfcDataOriginEnum DataOrigin;
  ifc::IfcLabel UserDefinedDataOrigin;
  ifc::IfcUnit Unit;
};

struct IfcIrregularTimeSeries : ifc::internal::IfcTimeSeries {
  SmallVector<ifc::IfcIrregularTimeSeriesValue, 4> Values;
};

struct IfcIrregularTimeSeriesValue : ifc::internal::IfcEntity {
  ifc::IfcDateTime TimeStamp;
  SmallVector<ifc::IfcValue, 4> ListValues;
};

struct IfcJunctionBox : ifc::internal::IfcFlowFitting {
  ifc::IfcJunctionBoxTypeEnum PredefinedType;
};

struct IfcJunctionBoxType : ifc::internal::IfcFlowFittingType {
  ifc::IfcJunctionBoxTypeEnum PredefinedType;
};

struct IfcLShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure Depth;
  ifc::IfcPositiveLengthMeasure Width;
  ifc::IfcPositiveLengthMeasure Thickness;
  ifc::IfcNonNegativeLengthMeasure FilletRadius;
  ifc::IfcNonNegativeLengthMeasure EdgeRadius;
  ifc::IfcPlaneAngleMeasure LegSlope;
};

struct IfcLaborResource : ifc::internal::IfcConstructionResource {
  ifc::IfcLaborResourceTypeEnum PredefinedType;
};

struct IfcLaborResourceType : ifc::internal::IfcConstructionResourceType {
  ifc::IfcLaborResourceTypeEnum PredefinedType;
};

struct IfcLagTime : ifc::internal::IfcSchedulingTime {
  ifc::IfcTimeOrRatioSelect LagValue;
  ifc::IfcTaskDurationEnum DurationType;
};

struct IfcLamp : ifc::internal::IfcFlowTerminal {
  ifc::IfcLampTypeEnum PredefinedType;
};

struct IfcLampType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcLampTypeEnum PredefinedType;
};

struct IfcLibraryInformation : ifc::internal::IfcExternalInformation {
  ifc::IfcLabel Name;
  ifc::IfcLabel Version;
  ifc::IfcActorSelect Publisher;
  ifc::IfcDateTime VersionDate;
  ifc::IfcURIReference Location;
  ifc::IfcText Description;
};

struct IfcLibraryReference : ifc::internal::IfcExternalReference {
  ifc::IfcText Description;
  ifc::IfcLanguageId Language;
  ifc::IfcLibraryInformation ReferencedLibrary;
};

struct IfcLightDistributionData : ifc::internal::IfcEntity {
  ifc::IfcPlaneAngleMeasure MainPlaneAngle;
  SmallVector<ifc::IfcPlaneAngleMeasure, 4> SecondaryPlaneAngle;
  SmallVector<ifc::IfcLuminousIntensityDistributionMeasure, 4> LuminousIntensity;
};

struct IfcLightFixture : ifc::internal::IfcFlowTerminal {
  ifc::IfcLightFixtureTypeEnum PredefinedType;
};

struct IfcLightFixtureType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcLightFixtureTypeEnum PredefinedType;
};

struct IfcLightIntensityDistribution : ifc::internal::IfcEntity {
  ifc::IfcLightDistributionCurveEnum LightDistributionCurve;
  SmallVector<ifc::IfcLightDistributionData, 4> DistributionData;
};

struct IfcLightSource : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcLabel Name;
  ifc::IfcColourRgb LightColour;
  ifc::IfcNormalisedRatioMeasure AmbientIntensity;
  ifc::IfcNormalisedRatioMeasure Intensity;
};

struct IfcLightSourceAmbient : ifc::internal::IfcLightSource {};

struct IfcLightSourceDirectional : ifc::internal::IfcLightSource {
  ifc::IfcDirection Orientation;
};

struct IfcLightSourceGoniometric : ifc::internal::IfcLightSource {
  ifc::IfcAxis2Placement3D Position;
  ifc::IfcColourRgb ColourAppearance;
  ifc::IfcThermodynamicTemperatureMeasure ColourTemperature;
  ifc::IfcLuminousFluxMeasure LuminousFlux;
  ifc::IfcLightEmissionSourceEnum LightEmissionSource;
  ifc::IfcLightDistributionDataSourceSelect LightDistributionDataSource;
};

struct IfcLightSourcePositional : ifc::internal::IfcLightSource {
  ifc::IfcCartesianPoint Position;
  ifc::IfcPositiveLengthMeasure Radius;
  ifc::IfcReal ConstantAttenuation;
  ifc::IfcReal DistanceAttenuation;
  ifc::IfcReal QuadricAttenuation;
};

struct IfcLightSourceSpot : ifc::internal::IfcLightSourcePositional {
  ifc::IfcDirection Orientation;
  ifc::IfcReal ConcentrationExponent;
  ifc::IfcPositivePlaneAngleMeasure SpreadAngle;
  ifc::IfcPositivePlaneAngleMeasure BeamWidthAngle;
};

struct IfcLine : ifc::internal::IfcCurve {
  ifc::IfcCartesianPoint Pnt;
  ifc::IfcVector Dir;
};

struct IfcLineSegment2D : ifc::internal::IfcCurveSegment2D {};

struct IfcLinearPlacement : ifc::internal::IfcObjectPlacement {
  ifc::IfcCurve PlacementRelTo;
  ifc::IfcDistanceExpression Distance;
  ifc::IfcOrientationExpression Orientation;
  ifc::IfcAxis2Placement3D CartesianPosition;
};

struct IfcLocalPlacement : ifc::internal::IfcObjectPlacement {
  ifc::IfcObjectPlacement PlacementRelTo;
  ifc::IfcAxis2Placement RelativePlacement;
};

struct IfcMapConversion : ifc::internal::IfcCoordinateOperation {
  ifc::IfcLengthMeasure Eastings;
  ifc::IfcLengthMeasure Northings;
  ifc::IfcLengthMeasure OrthogonalHeight;
  ifc::IfcReal XAxisAbscissa;
  ifc::IfcReal XAxisOrdinate;
  ifc::IfcReal Scale;
};

struct IfcMappedItem : ifc::internal::IfcRepresentationItem {
  ifc::IfcRepresentationMap MappingSource;
  ifc::IfcCartesianTransformationOperator MappingTarget;
};

struct IfcMaterialDefinition : ifc::internal::IfcEntity {};

struct IfcMaterial : ifc::internal::IfcMaterialDefinition {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcLabel Category;
};

struct IfcMaterialClassificationRelationship : ifc::internal::IfcEntity {
  std::unordered_set<ifc::IfcClassificationSelect> MaterialClassifications;
  ifc::IfcMaterial ClassifiedMaterial;
};

struct IfcMaterialConstituent : ifc::internal::IfcMaterialDefinition {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcMaterial Material;
  ifc::IfcNormalisedRatioMeasure Fraction;
  ifc::IfcLabel Category;
};

struct IfcMaterialConstituentSet : ifc::internal::IfcMaterialDefinition {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  std::unordered_set<ifc::IfcMaterialConstituent> MaterialConstituents;
};

struct IfcProductRepresentation : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  SmallVector<ifc::IfcRepresentation, 4> Representations;
};

struct IfcMaterialDefinitionRepresentation : ifc::internal::IfcProductRepresentation {
  ifc::IfcMaterial RepresentedMaterial;
};

struct IfcMaterialLayer : ifc::internal::IfcMaterialDefinition {
  ifc::IfcMaterial Material;
  ifc::IfcNonNegativeLengthMeasure LayerThickness;
  ifc::IfcLogical IsVentilated;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcLabel Category;
  ifc::IfcInteger Priority;
};

struct IfcMaterialLayerSet : ifc::internal::IfcMaterialDefinition {
  SmallVector<ifc::IfcMaterialLayer, 4> MaterialLayers;
  ifc::IfcLabel LayerSetName;
  ifc::IfcText Description;
};

struct IfcMaterialUsageDefinition : ifc::internal::IfcEntity {};

struct IfcMaterialLayerSetUsage : ifc::internal::IfcMaterialUsageDefinition {
  ifc::IfcMaterialLayerSet ForLayerSet;
  ifc::IfcLayerSetDirectionEnum LayerSetDirection;
  ifc::IfcDirectionSenseEnum DirectionSense;
  ifc::IfcLengthMeasure OffsetFromReferenceLine;
  ifc::IfcPositiveLengthMeasure ReferenceExtent;
};

struct IfcMaterialLayerWithOffsets : ifc::internal::IfcMaterialLayer {
  ifc::IfcLayerSetDirectionEnum OffsetDirection;
  SmallVector<ifc::IfcLengthMeasure, 2> OffsetValues;
};

struct IfcMaterialList : ifc::internal::IfcEntity {
  SmallVector<ifc::IfcMaterial, 4> Materials;
};

struct IfcMaterialProfile : ifc::internal::IfcMaterialDefinition {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcMaterial Material;
  ifc::IfcProfileDef Profile;
  ifc::IfcInteger Priority;
  ifc::IfcLabel Category;
};

struct IfcMaterialProfileSet : ifc::internal::IfcMaterialDefinition {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  SmallVector<ifc::IfcMaterialProfile, 4> MaterialProfiles;
  ifc::IfcCompositeProfileDef CompositeProfile;
};

struct IfcMaterialProfileSetUsage : ifc::internal::IfcMaterialUsageDefinition {
  ifc::IfcMaterialProfileSet ForProfileSet;
  ifc::IfcCardinalPointReference CardinalPoint;
  ifc::IfcPositiveLengthMeasure ReferenceExtent;
};

struct IfcMaterialProfileSetUsageTapering : ifc::internal::IfcMaterialProfileSetUsage {
  ifc::IfcMaterialProfileSet ForProfileEndSet;
  ifc::IfcCardinalPointReference CardinalEndPoint;
};

struct IfcMaterialProfileWithOffsets : ifc::internal::IfcMaterialProfile {
  SmallVector<ifc::IfcLengthMeasure, 2> OffsetValues;
};

struct IfcMaterialProperties : ifc::internal::IfcExtendedProperties {
  ifc::IfcMaterialDefinition Material;
};

struct IfcMaterialRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcMaterial RelatingMaterial;
  std::unordered_set<ifc::IfcMaterial> RelatedMaterials;
  ifc::IfcLabel Expression;
};

struct IfcMeasureWithUnit : ifc::internal::IfcEntity {
  ifc::IfcValue ValueComponent;
  ifc::IfcUnit UnitComponent;
};

struct IfcMechanicalFastener : ifc::internal::IfcElementComponent {
  ifc::IfcPositiveLengthMeasure NominalDiameter;
  ifc::IfcPositiveLengthMeasure NominalLength;
  ifc::IfcMechanicalFastenerTypeEnum PredefinedType;
};

struct IfcMechanicalFastenerType : ifc::internal::IfcElementComponentType {
  ifc::IfcMechanicalFastenerTypeEnum PredefinedType;
  ifc::IfcPositiveLengthMeasure NominalDiameter;
  ifc::IfcPositiveLengthMeasure NominalLength;
};

struct IfcMedicalDevice : ifc::internal::IfcFlowTerminal {
  ifc::IfcMedicalDeviceTypeEnum PredefinedType;
};

struct IfcMedicalDeviceType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcMedicalDeviceTypeEnum PredefinedType;
};

struct IfcMember : ifc::internal::IfcBuildingElement {
  ifc::IfcMemberTypeEnum PredefinedType;
};

struct IfcMemberStandardCase : ifc::internal::IfcMember {};

struct IfcMemberType : ifc::internal::IfcBuildingElementType {
  ifc::IfcMemberTypeEnum PredefinedType;
};

struct IfcMetric : ifc::internal::IfcConstraint {
  ifc::IfcBenchmarkEnum Benchmark;
  ifc::IfcLabel ValueSource;
  ifc::IfcMetricValueSelect DataValue;
  ifc::IfcReference ReferencePath;
};

struct IfcMirroredProfileDef : ifc::internal::IfcDerivedProfileDef {};

struct IfcMonetaryUnit : ifc::internal::IfcEntity {
  ifc::IfcLabel Currency;
};

struct IfcMotorConnection : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcMotorConnectionTypeEnum PredefinedType;
};

struct IfcMotorConnectionType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcMotorConnectionTypeEnum PredefinedType;
};

struct IfcObjective : ifc::internal::IfcConstraint {
  SmallVector<ifc::IfcConstraint, 4> BenchmarkValues;
  ifc::IfcLogicalOperatorEnum LogicalAggregator;
  ifc::IfcObjectiveEnum ObjectiveQualifier;
  ifc::IfcLabel UserDefinedQualifier;
};

struct IfcOccupant : ifc::internal::IfcActor {
  ifc::IfcOccupantTypeEnum PredefinedType;
};

struct IfcOffsetCurve : ifc::internal::IfcCurve {
  ifc::IfcCurve BasisCurve;
};

struct IfcOffsetCurve2D : ifc::internal::IfcOffsetCurve {
  ifc::IfcLengthMeasure Distance;
  ifc::IfcLogical SelfIntersect;
};

struct IfcOffsetCurve3D : ifc::internal::IfcOffsetCurve {
  ifc::IfcLengthMeasure Distance;
  ifc::IfcLogical SelfIntersect;
  ifc::IfcDirection RefDirection;
};

struct IfcOffsetCurveByDistances : ifc::internal::IfcOffsetCurve {
  SmallVector<ifc::IfcDistanceExpression, 4> OffsetValues;
  ifc::IfcLabel Tag;
};

struct IfcOpenShell : ifc::internal::IfcConnectedFaceSet {};

struct IfcOpeningElement : ifc::internal::IfcFeatureElementSubtraction {
  ifc::IfcOpeningElementTypeEnum PredefinedType;
};

struct IfcOpeningStandardCase : ifc::internal::IfcOpeningElement {};

struct IfcOrganization : ifc::internal::IfcEntity {
  ifc::IfcIdentifier Identification;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  SmallVector<ifc::IfcActorRole, 4> Roles;
  SmallVector<ifc::IfcAddress, 4> Addresses;
};

struct IfcOrganizationRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcOrganization RelatingOrganization;
  std::unordered_set<ifc::IfcOrganization> RelatedOrganizations;
};

struct IfcOrientationExpression : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcDirection LateralAxisDirection;
  ifc::IfcDirection VerticalAxisDirection;
};

struct IfcOrientedEdge : ifc::internal::IfcEdge {
  ifc::IfcEdge EdgeElement;
  ifc::IfcBoolean Orientation;
};

struct IfcOuterBoundaryCurve : ifc::internal::IfcBoundaryCurve {};

struct IfcOutlet : ifc::internal::IfcFlowTerminal {
  ifc::IfcOutletTypeEnum PredefinedType;
};

struct IfcOutletType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcOutletTypeEnum PredefinedType;
};

struct IfcOwnerHistory : ifc::internal::IfcEntity {
  ifc::IfcPersonAndOrganization OwningUser;
  ifc::IfcApplication OwningApplication;
  ifc::IfcStateEnum State;
  ifc::IfcChangeActionEnum ChangeAction;
  ifc::IfcTimeStamp LastModifiedDate;
  ifc::IfcPersonAndOrganization LastModifyingUser;
  ifc::IfcApplication LastModifyingApplication;
  ifc::IfcTimeStamp CreationDate;
};

struct IfcPath : ifc::internal::IfcTopologicalRepresentationItem {
  SmallVector<ifc::IfcOrientedEdge, 4> EdgeList;
};

struct IfcPcurve : ifc::internal::IfcCurve {
  ifc::IfcSurface BasisSurface;
  ifc::IfcCurve ReferenceCurve;
};

struct IfcPerformanceHistory : ifc::internal::IfcControl {
  ifc::IfcLabel LifeCyclePhase;
  ifc::IfcPerformanceHistoryTypeEnum PredefinedType;
};

struct IfcPermeableCoveringProperties : ifc::internal::IfcPreDefinedPropertySet {
  ifc::IfcPermeableCoveringOperationEnum OperationType;
  ifc::IfcWindowPanelPositionEnum PanelPosition;
  ifc::IfcPositiveLengthMeasure FrameDepth;
  ifc::IfcPositiveLengthMeasure FrameThickness;
  ifc::IfcShapeAspect ShapeAspectStyle;
};

struct IfcPermit : ifc::internal::IfcControl {
  ifc::IfcPermitTypeEnum PredefinedType;
  ifc::IfcLabel Status;
  ifc::IfcText LongDescription;
};

struct IfcPerson : ifc::internal::IfcEntity {
  ifc::IfcIdentifier Identification;
  ifc::IfcLabel FamilyName;
  ifc::IfcLabel GivenName;
  SmallVector<ifc::IfcLabel, 4> MiddleNames;
  SmallVector<ifc::IfcLabel, 4> PrefixTitles;
  SmallVector<ifc::IfcLabel, 4> SuffixTitles;
  SmallVector<ifc::IfcActorRole, 4> Roles;
  SmallVector<ifc::IfcAddress, 4> Addresses;
};

struct IfcPersonAndOrganization : ifc::internal::IfcEntity {
  ifc::IfcPerson ThePerson;
  ifc::IfcOrganization TheOrganization;
  SmallVector<ifc::IfcActorRole, 4> Roles;
};

struct IfcPhysicalQuantity : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
};

struct IfcPhysicalComplexQuantity : ifc::internal::IfcPhysicalQuantity {
  std::unordered_set<ifc::IfcPhysicalQuantity> HasQuantities;
  ifc::IfcLabel Discrimination;
  ifc::IfcLabel Quality;
  ifc::IfcLabel Usage;
};

struct IfcPhysicalSimpleQuantity : ifc::internal::IfcPhysicalQuantity {
  ifc::IfcNamedUnit Unit;
};

struct IfcPile : ifc::internal::IfcBuildingElement {
  ifc::IfcPileTypeEnum PredefinedType;
  ifc::IfcPileConstructionEnum ConstructionType;
};

struct IfcPileType : ifc::internal::IfcBuildingElementType {
  ifc::IfcPileTypeEnum PredefinedType;
};

struct IfcPipeFitting : ifc::internal::IfcFlowFitting {
  ifc::IfcPipeFittingTypeEnum PredefinedType;
};

struct IfcPipeFittingType : ifc::internal::IfcFlowFittingType {
  ifc::IfcPipeFittingTypeEnum PredefinedType;
};

struct IfcPipeSegment : ifc::internal::IfcFlowSegment {
  ifc::IfcPipeSegmentTypeEnum PredefinedType;
};

struct IfcPipeSegmentType : ifc::internal::IfcFlowSegmentType {
  ifc::IfcPipeSegmentTypeEnum PredefinedType;
};

struct IfcPixelTexture : ifc::internal::IfcSurfaceTexture {
  ifc::IfcInteger Width;
  ifc::IfcInteger Height;
  ifc::IfcInteger ColourComponents;
  SmallVector<ifc::IfcBinary, 4> Pixel;
};

struct IfcPlanarExtent : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcLengthMeasure SizeInX;
  ifc::IfcLengthMeasure SizeInY;
};

struct IfcPlanarBox : ifc::internal::IfcPlanarExtent {
  ifc::IfcAxis2Placement Placement;
};

struct IfcPlane : ifc::internal::IfcElementarySurface {};

struct IfcPlate : ifc::internal::IfcBuildingElement {
  ifc::IfcPlateTypeEnum PredefinedType;
};

struct IfcPlateStandardCase : ifc::internal::IfcPlate {};

struct IfcPlateType : ifc::internal::IfcBuildingElementType {
  ifc::IfcPlateTypeEnum PredefinedType;
};

struct IfcPointOnCurve : ifc::internal::IfcPoint {
  ifc::IfcCurve BasisCurve;
  ifc::IfcParameterValue PointParameter;
};

struct IfcPointOnSurface : ifc::internal::IfcPoint {
  ifc::IfcSurface BasisSurface;
  ifc::IfcParameterValue PointParameterU;
  ifc::IfcParameterValue PointParameterV;
};

struct IfcPolyLoop : ifc::internal::IfcLoop {
  SmallVector<ifc::IfcCartesianPoint, 4> Polygon;
};

struct IfcPolygonalBoundedHalfSpace : ifc::internal::IfcHalfSpaceSolid {
  ifc::IfcAxis2Placement3D Position;
  ifc::IfcBoundedCurve PolygonalBoundary;
};

struct IfcTessellatedFaceSet : ifc::internal::IfcTessellatedItem {
  ifc::IfcCartesianPointList3D Coordinates;
};

struct IfcPolygonalFaceSet : ifc::internal::IfcTessellatedFaceSet {
  ifc::IfcBoolean Closed;
  SmallVector<ifc::IfcIndexedPolygonalFace, 4> Faces;
  SmallVector<ifc::IfcPositiveInteger, 4> PnIndex;
};

struct IfcPolyline : ifc::internal::IfcBoundedCurve {
  SmallVector<ifc::IfcCartesianPoint, 4> Points;
};

struct IfcPostalAddress : ifc::internal::IfcAddress {
  ifc::IfcLabel InternalLocation;
  SmallVector<ifc::IfcLabel, 4> AddressLines;
  ifc::IfcLabel PostalBox;
  ifc::IfcLabel Town;
  ifc::IfcLabel Region;
  ifc::IfcLabel PostalCode;
  ifc::IfcLabel Country;
};

struct IfcPreDefinedProperties : ifc::internal::IfcPropertyAbstraction {};

struct IfcPreDefinedTextFont : ifc::internal::IfcPreDefinedItem {};

struct IfcPresentationLayerAssignment : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  std::unordered_set<ifc::IfcLayeredItem> AssignedItems;
  ifc::IfcIdentifier Identifier;
};

struct IfcPresentationLayerWithStyle : ifc::internal::IfcPresentationLayerAssignment {
  ifc::IfcLogical LayerOn;
  ifc::IfcLogical LayerFrozen;
  ifc::IfcLogical LayerBlocked;
  std::unordered_set<ifc::IfcPresentationStyle> LayerStyles;
};

struct IfcPresentationStyleAssignment : ifc::internal::IfcEntity {
  std::unordered_set<ifc::IfcPresentationStyleSelect> Styles;
};

struct IfcProcedure : ifc::internal::IfcProcess {
  ifc::IfcProcedureTypeEnum PredefinedType;
};

struct IfcProcedureType : ifc::internal::IfcTypeProcess {
  ifc::IfcProcedureTypeEnum PredefinedType;
};

struct IfcProductDefinitionShape : ifc::internal::IfcProductRepresentation {};

struct IfcProfileProperties : ifc::internal::IfcExtendedProperties {
  ifc::IfcProfileDef ProfileDefinition;
};

struct IfcProject : ifc::internal::IfcContext {};

struct IfcProjectLibrary : ifc::internal::IfcContext {};

struct IfcProjectOrder : ifc::internal::IfcControl {
  ifc::IfcProjectOrderTypeEnum PredefinedType;
  ifc::IfcLabel Status;
  ifc::IfcText LongDescription;
};

struct IfcProjectedCRS : ifc::internal::IfcCoordinateReferenceSystem {
  ifc::IfcIdentifier MapProjection;
  ifc::IfcIdentifier MapZone;
  ifc::IfcNamedUnit MapUnit;
};

struct IfcProjectionElement : ifc::internal::IfcFeatureElementAddition {
  ifc::IfcProjectionElementTypeEnum PredefinedType;
};

struct IfcSimpleProperty : ifc::internal::IfcProperty {};

struct IfcPropertyBoundedValue : ifc::internal::IfcSimpleProperty {
  ifc::IfcValue UpperBoundValue;
  ifc::IfcValue LowerBoundValue;
  ifc::IfcUnit Unit;
  ifc::IfcValue SetPointValue;
};

struct IfcPropertyDependencyRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcProperty DependingProperty;
  ifc::IfcProperty DependantProperty;
  ifc::IfcText Expression;
};

struct IfcPropertyEnumeratedValue : ifc::internal::IfcSimpleProperty {
  SmallVector<ifc::IfcValue, 4> EnumerationValues;
  ifc::IfcPropertyEnumeration EnumerationReference;
};

struct IfcPropertyEnumeration : ifc::internal::IfcPropertyAbstraction {
  ifc::IfcLabel Name;
  SmallVector<ifc::IfcValue, 4> EnumerationValues;
  ifc::IfcUnit Unit;
};

struct IfcPropertyListValue : ifc::internal::IfcSimpleProperty {
  SmallVector<ifc::IfcValue, 4> ListValues;
  ifc::IfcUnit Unit;
};

struct IfcPropertyReferenceValue : ifc::internal::IfcSimpleProperty {
  ifc::IfcText UsageName;
  ifc::IfcObjectReferenceSelect PropertyReference;
};

struct IfcPropertySet : ifc::internal::IfcPropertySetDefinition {
  std::unordered_set<ifc::IfcProperty> HasProperties;
};

struct IfcPropertySetTemplate : ifc::internal::IfcPropertyTemplateDefinition {
  ifc::IfcPropertySetTemplateTypeEnum TemplateType;
  ifc::IfcIdentifier ApplicableEntity;
  std::unordered_set<ifc::IfcPropertyTemplate> HasPropertyTemplates;
};

struct IfcPropertySingleValue : ifc::internal::IfcSimpleProperty {
  ifc::IfcValue NominalValue;
  ifc::IfcUnit Unit;
};

struct IfcPropertyTableValue : ifc::internal::IfcSimpleProperty {
  SmallVector<ifc::IfcValue, 4> DefiningValues;
  SmallVector<ifc::IfcValue, 4> DefinedValues;
  ifc::IfcText Expression;
  ifc::IfcUnit DefiningUnit;
  ifc::IfcUnit DefinedUnit;
  ifc::IfcCurveInterpolationEnum CurveInterpolation;
};

struct IfcProtectiveDevice : ifc::internal::IfcFlowController {
  ifc::IfcProtectiveDeviceTypeEnum PredefinedType;
};

struct IfcProtectiveDeviceTrippingUnit : ifc::internal::IfcDistributionControlElement {
  ifc::IfcProtectiveDeviceTrippingUnitTypeEnum PredefinedType;
};

struct IfcProtectiveDeviceTrippingUnitType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcProtectiveDeviceTrippingUnitTypeEnum PredefinedType;
};

struct IfcProtectiveDeviceType : ifc::internal::IfcFlowControllerType {
  ifc::IfcProtectiveDeviceTypeEnum PredefinedType;
};

struct IfcProxy : ifc::internal::IfcProduct {
  ifc::IfcObjectTypeEnum ProxyType;
  ifc::IfcLabel Tag;
};

struct IfcPump : ifc::internal::IfcFlowMovingDevice {
  ifc::IfcPumpTypeEnum PredefinedType;
};

struct IfcPumpType : ifc::internal::IfcFlowMovingDeviceType {
  ifc::IfcPumpTypeEnum PredefinedType;
};

struct IfcQuantityArea : ifc::internal::IfcPhysicalSimpleQuantity {
  ifc::IfcAreaMeasure AreaValue;
  ifc::IfcLabel Formula;
};

struct IfcQuantityCount : ifc::internal::IfcPhysicalSimpleQuantity {
  ifc::IfcCountMeasure CountValue;
  ifc::IfcLabel Formula;
};

struct IfcQuantityLength : ifc::internal::IfcPhysicalSimpleQuantity {
  ifc::IfcLengthMeasure LengthValue;
  ifc::IfcLabel Formula;
};

struct IfcQuantityTime : ifc::internal::IfcPhysicalSimpleQuantity {
  ifc::IfcTimeMeasure TimeValue;
  ifc::IfcLabel Formula;
};

struct IfcQuantityVolume : ifc::internal::IfcPhysicalSimpleQuantity {
  ifc::IfcVolumeMeasure VolumeValue;
  ifc::IfcLabel Formula;
};

struct IfcQuantityWeight : ifc::internal::IfcPhysicalSimpleQuantity {
  ifc::IfcMassMeasure WeightValue;
  ifc::IfcLabel Formula;
};

struct IfcRailing : ifc::internal::IfcBuildingElement {
  ifc::IfcRailingTypeEnum PredefinedType;
};

struct IfcRailingType : ifc::internal::IfcBuildingElementType {
  ifc::IfcRailingTypeEnum PredefinedType;
};

struct IfcRamp : ifc::internal::IfcBuildingElement {
  ifc::IfcRampTypeEnum PredefinedType;
};

struct IfcRampFlight : ifc::internal::IfcBuildingElement {
  ifc::IfcRampFlightTypeEnum PredefinedType;
};

struct IfcRampFlightType : ifc::internal::IfcBuildingElementType {
  ifc::IfcRampFlightTypeEnum PredefinedType;
};

struct IfcRampType : ifc::internal::IfcBuildingElementType {
  ifc::IfcRampTypeEnum PredefinedType;
};

struct IfcRationalBSplineCurveWithKnots : ifc::internal::IfcBSplineCurveWithKnots {
  SmallVector<ifc::IfcReal, 4> WeightsData;
};

struct IfcRationalBSplineSurfaceWithKnots : ifc::internal::IfcBSplineSurfaceWithKnots {
  SmallVector<SmallVector<ifc::IfcReal, 4>, 4> WeightsData;
};

struct IfcRectangleProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure XDim;
  ifc::IfcPositiveLengthMeasure YDim;
};

struct IfcRectangleHollowProfileDef : ifc::internal::IfcRectangleProfileDef {
  ifc::IfcPositiveLengthMeasure WallThickness;
  ifc::IfcNonNegativeLengthMeasure InnerFilletRadius;
  ifc::IfcNonNegativeLengthMeasure OuterFilletRadius;
};

struct IfcRectangularPyramid : ifc::internal::IfcCsgPrimitive3D {
  ifc::IfcPositiveLengthMeasure XLength;
  ifc::IfcPositiveLengthMeasure YLength;
  ifc::IfcPositiveLengthMeasure Height;
};

struct IfcRectangularTrimmedSurface : ifc::internal::IfcBoundedSurface {
  ifc::IfcSurface BasisSurface;
  ifc::IfcParameterValue U1;
  ifc::IfcParameterValue V1;
  ifc::IfcParameterValue U2;
  ifc::IfcParameterValue V2;
  ifc::IfcBoolean Usense;
  ifc::IfcBoolean Vsense;
};

struct IfcRecurrencePattern : ifc::internal::IfcEntity {
  ifc::IfcRecurrenceTypeEnum RecurrenceType;
  std::unordered_set<ifc::IfcDayInMonthNumber> DayComponent;
  std::unordered_set<ifc::IfcDayInWeekNumber> WeekdayComponent;
  std::unordered_set<ifc::IfcMonthInYearNumber> MonthComponent;
  ifc::IfcInteger Position;
  ifc::IfcInteger Interval;
  ifc::IfcInteger Occurrences;
  SmallVector<ifc::IfcTimePeriod, 4> TimePeriods;
};

struct IfcReference : ifc::internal::IfcEntity {
  ifc::IfcIdentifier TypeIdentifier;
  ifc::IfcIdentifier AttributeIdentifier;
  ifc::IfcLabel InstanceName;
  SmallVector<ifc::IfcInteger, 4> ListPositions;
  ifc::IfcReference InnerReference;
};

struct IfcReferent : ifc::internal::IfcPositioningElement {
  ifc::IfcReferentTypeEnum PredefinedType;
  ifc::IfcLengthMeasure RestartDistance;
};

struct IfcRegularTimeSeries : ifc::internal::IfcTimeSeries {
  ifc::IfcTimeMeasure TimeStep;
  SmallVector<ifc::IfcTimeSeriesValue, 4> Values;
};

struct IfcReinforcementBarProperties : ifc::internal::IfcPreDefinedProperties {
  ifc::IfcAreaMeasure TotalCrossSectionArea;
  ifc::IfcLabel SteelGrade;
  ifc::IfcReinforcingBarSurfaceEnum BarSurface;
  ifc::IfcLengthMeasure EffectiveDepth;
  ifc::IfcPositiveLengthMeasure NominalBarDiameter;
  ifc::IfcCountMeasure BarCount;
};

struct IfcReinforcementDefinitionProperties : ifc::internal::IfcPreDefinedPropertySet {
  ifc::IfcLabel DefinitionType;
  SmallVector<ifc::IfcSectionReinforcementProperties, 4> ReinforcementSectionDefinitions;
};

struct IfcReinforcingElement : ifc::internal::IfcElementComponent {
  ifc::IfcLabel SteelGrade;
};

struct IfcReinforcingBar : ifc::internal::IfcReinforcingElement {
  ifc::IfcPositiveLengthMeasure NominalDiameter;
  ifc::IfcAreaMeasure CrossSectionArea;
  ifc::IfcPositiveLengthMeasure BarLength;
  ifc::IfcReinforcingBarTypeEnum PredefinedType;
  ifc::IfcReinforcingBarSurfaceEnum BarSurface;
};

struct IfcReinforcingElementType : ifc::internal::IfcElementComponentType {};

struct IfcReinforcingBarType : ifc::internal::IfcReinforcingElementType {
  ifc::IfcReinforcingBarTypeEnum PredefinedType;
  ifc::IfcPositiveLengthMeasure NominalDiameter;
  ifc::IfcAreaMeasure CrossSectionArea;
  ifc::IfcPositiveLengthMeasure BarLength;
  ifc::IfcReinforcingBarSurfaceEnum BarSurface;
  ifc::IfcLabel BendingShapeCode;
  SmallVector<ifc::IfcBendingParameterSelect, 4> BendingParameters;
};

struct IfcReinforcingMesh : ifc::internal::IfcReinforcingElement {
  ifc::IfcPositiveLengthMeasure MeshLength;
  ifc::IfcPositiveLengthMeasure MeshWidth;
  ifc::IfcPositiveLengthMeasure LongitudinalBarNominalDiameter;
  ifc::IfcPositiveLengthMeasure TransverseBarNominalDiameter;
  ifc::IfcAreaMeasure LongitudinalBarCrossSectionArea;
  ifc::IfcAreaMeasure TransverseBarCrossSectionArea;
  ifc::IfcPositiveLengthMeasure LongitudinalBarSpacing;
  ifc::IfcPositiveLengthMeasure TransverseBarSpacing;
  ifc::IfcReinforcingMeshTypeEnum PredefinedType;
};

struct IfcReinforcingMeshType : ifc::internal::IfcReinforcingElementType {
  ifc::IfcReinforcingMeshTypeEnum PredefinedType;
  ifc::IfcPositiveLengthMeasure MeshLength;
  ifc::IfcPositiveLengthMeasure MeshWidth;
  ifc::IfcPositiveLengthMeasure LongitudinalBarNominalDiameter;
  ifc::IfcPositiveLengthMeasure TransverseBarNominalDiameter;
  ifc::IfcAreaMeasure LongitudinalBarCrossSectionArea;
  ifc::IfcAreaMeasure TransverseBarCrossSectionArea;
  ifc::IfcPositiveLengthMeasure LongitudinalBarSpacing;
  ifc::IfcPositiveLengthMeasure TransverseBarSpacing;
  ifc::IfcLabel BendingShapeCode;
  SmallVector<ifc::IfcBendingParameterSelect, 4> BendingParameters;
};

struct IfcRelationship : ifc::internal::IfcRoot {};

struct IfcRelDecomposes : ifc::internal::IfcRelationship {};

struct IfcRelAggregates : ifc::internal::IfcRelDecomposes {
  ifc::IfcObjectDefinition RelatingObject;
  std::unordered_set<ifc::IfcObjectDefinition> RelatedObjects;
};

struct IfcRelAssigns : ifc::internal::IfcRelationship {
  std::unordered_set<ifc::IfcObjectDefinition> RelatedObjects;
  ifc::IfcObjectTypeEnum RelatedObjectsType;
};

struct IfcRelAssignsToActor : ifc::internal::IfcRelAssigns {
  ifc::IfcActor RelatingActor;
  ifc::IfcActorRole ActingRole;
};

struct IfcRelAssignsToControl : ifc::internal::IfcRelAssigns {
  ifc::IfcControl RelatingControl;
};

struct IfcRelAssignsToGroup : ifc::internal::IfcRelAssigns {
  ifc::IfcGroup RelatingGroup;
};

struct IfcRelAssignsToGroupByFactor : ifc::internal::IfcRelAssignsToGroup {
  ifc::IfcRatioMeasure Factor;
};

struct IfcRelAssignsToProcess : ifc::internal::IfcRelAssigns {
  ifc::IfcProcessSelect RelatingProcess;
  ifc::IfcMeasureWithUnit QuantityInProcess;
};

struct IfcRelAssignsToProduct : ifc::internal::IfcRelAssigns {
  ifc::IfcProductSelect RelatingProduct;
};

struct IfcRelAssignsToResource : ifc::internal::IfcRelAssigns {
  ifc::IfcResourceSelect RelatingResource;
};

struct IfcRelAssociates : ifc::internal::IfcRelationship {
  std::unordered_set<ifc::IfcDefinitionSelect> RelatedObjects;
};

struct IfcRelAssociatesApproval : ifc::internal::IfcRelAssociates {
  ifc::IfcApproval RelatingApproval;
};

struct IfcRelAssociatesClassification : ifc::internal::IfcRelAssociates {
  ifc::IfcClassificationSelect RelatingClassification;
};

struct IfcRelAssociatesConstraint : ifc::internal::IfcRelAssociates {
  ifc::IfcLabel Intent;
  ifc::IfcConstraint RelatingConstraint;
};

struct IfcRelAssociatesDocument : ifc::internal::IfcRelAssociates {
  ifc::IfcDocumentSelect RelatingDocument;
};

struct IfcRelAssociatesLibrary : ifc::internal::IfcRelAssociates {
  ifc::IfcLibrarySelect RelatingLibrary;
};

struct IfcRelAssociatesMaterial : ifc::internal::IfcRelAssociates {
  ifc::IfcMaterialSelect RelatingMaterial;
};

struct IfcRelConnects : ifc::internal::IfcRelationship {};

struct IfcRelConnectsElements : ifc::internal::IfcRelConnects {
  ifc::IfcConnectionGeometry ConnectionGeometry;
  ifc::IfcElement RelatingElement;
  ifc::IfcElement RelatedElement;
};

struct IfcRelConnectsPathElements : ifc::internal::IfcRelConnectsElements {
  SmallVector<ifc::IfcInteger, 4> RelatingPriorities;
  SmallVector<ifc::IfcInteger, 4> RelatedPriorities;
  ifc::IfcConnectionTypeEnum RelatedConnectionType;
  ifc::IfcConnectionTypeEnum RelatingConnectionType;
};

struct IfcRelConnectsPortToElement : ifc::internal::IfcRelConnects {
  ifc::IfcPort RelatingPort;
  ifc::IfcDistributionElement RelatedElement;
};

struct IfcRelConnectsPorts : ifc::internal::IfcRelConnects {
  ifc::IfcPort RelatingPort;
  ifc::IfcPort RelatedPort;
  ifc::IfcElement RealizingElement;
};

struct IfcRelConnectsStructuralActivity : ifc::internal::IfcRelConnects {
  ifc::IfcStructuralActivityAssignmentSelect RelatingElement;
  ifc::IfcStructuralActivity RelatedStructuralActivity;
};

struct IfcRelConnectsStructuralMember : ifc::internal::IfcRelConnects {
  ifc::IfcStructuralMember RelatingStructuralMember;
  ifc::IfcStructuralConnection RelatedStructuralConnection;
  ifc::IfcBoundaryCondition AppliedCondition;
  ifc::IfcStructuralConnectionCondition AdditionalConditions;
  ifc::IfcLengthMeasure SupportedLength;
  ifc::IfcAxis2Placement3D ConditionCoordinateSystem;
};

struct IfcRelConnectsWithEccentricity : ifc::internal::IfcRelConnectsStructuralMember {
  ifc::IfcConnectionGeometry ConnectionConstraint;
};

struct IfcRelConnectsWithRealizingElements : ifc::internal::IfcRelConnectsElements {
  std::unordered_set<ifc::IfcElement> RealizingElements;
  ifc::IfcLabel ConnectionType;
};

struct IfcRelContainedInSpatialStructure : ifc::internal::IfcRelConnects {
  std::unordered_set<ifc::IfcProduct> RelatedElements;
  ifc::IfcSpatialElement RelatingStructure;
};

struct IfcRelCoversBldgElements : ifc::internal::IfcRelConnects {
  ifc::IfcElement RelatingBuildingElement;
  std::unordered_set<ifc::IfcCovering> RelatedCoverings;
};

struct IfcRelCoversSpaces : ifc::internal::IfcRelConnects {
  ifc::IfcSpace RelatingSpace;
  std::unordered_set<ifc::IfcCovering> RelatedCoverings;
};

struct IfcRelDeclares : ifc::internal::IfcRelationship {
  ifc::IfcContext RelatingContext;
  std::unordered_set<ifc::IfcDefinitionSelect> RelatedDefinitions;
};

struct IfcRelDefines : ifc::internal::IfcRelationship {};

struct IfcRelDefinesByObject : ifc::internal::IfcRelDefines {
  std::unordered_set<ifc::IfcObject> RelatedObjects;
  ifc::IfcObject RelatingObject;
};

struct IfcRelDefinesByProperties : ifc::internal::IfcRelDefines {
  std::unordered_set<ifc::IfcObjectDefinition> RelatedObjects;
  ifc::IfcPropertySetDefinitionSelect RelatingPropertyDefinition;
};

struct IfcRelDefinesByTemplate : ifc::internal::IfcRelDefines {
  std::unordered_set<ifc::IfcPropertySetDefinition> RelatedPropertySets;
  ifc::IfcPropertySetTemplate RelatingTemplate;
};

struct IfcRelDefinesByType : ifc::internal::IfcRelDefines {
  std::unordered_set<ifc::IfcObject> RelatedObjects;
  ifc::IfcTypeObject RelatingType;
};

struct IfcRelFillsElement : ifc::internal::IfcRelConnects {
  ifc::IfcOpeningElement RelatingOpeningElement;
  ifc::IfcElement RelatedBuildingElement;
};

struct IfcRelFlowControlElements : ifc::internal::IfcRelConnects {
  std::unordered_set<ifc::IfcDistributionControlElement> RelatedControlElements;
  ifc::IfcDistributionFlowElement RelatingFlowElement;
};

struct IfcRelInterferesElements : ifc::internal::IfcRelConnects {
  ifc::IfcElement RelatingElement;
  ifc::IfcElement RelatedElement;
  ifc::IfcConnectionGeometry InterferenceGeometry;
  ifc::IfcIdentifier InterferenceType;
  ifc::IfcLogical ImpliedOrder;
};

struct IfcRelNests : ifc::internal::IfcRelDecomposes {
  ifc::IfcObjectDefinition RelatingObject;
  SmallVector<ifc::IfcObjectDefinition, 4> RelatedObjects;
};

struct IfcRelProjectsElement : ifc::internal::IfcRelDecomposes {
  ifc::IfcElement RelatingElement;
  ifc::IfcFeatureElementAddition RelatedFeatureElement;
};

struct IfcRelReferencedInSpatialStructure : ifc::internal::IfcRelConnects {
  std::unordered_set<ifc::IfcProduct> RelatedElements;
  ifc::IfcSpatialElement RelatingStructure;
};

struct IfcRelSequence : ifc::internal::IfcRelConnects {
  ifc::IfcProcess RelatingProcess;
  ifc::IfcProcess RelatedProcess;
  ifc::IfcLagTime TimeLag;
  ifc::IfcSequenceEnum SequenceType;
  ifc::IfcLabel UserDefinedSequenceType;
};

struct IfcRelServicesBuildings : ifc::internal::IfcRelConnects {
  ifc::IfcSystem RelatingSystem;
  std::unordered_set<ifc::IfcSpatialElement> RelatedBuildings;
};

struct IfcRelSpaceBoundary : ifc::internal::IfcRelConnects {
  ifc::IfcSpaceBoundarySelect RelatingSpace;
  ifc::IfcElement RelatedBuildingElement;
  ifc::IfcConnectionGeometry ConnectionGeometry;
  ifc::IfcPhysicalOrVirtualEnum PhysicalOrVirtualBoundary;
  ifc::IfcInternalOrExternalEnum InternalOrExternalBoundary;
};

struct IfcRelSpaceBoundary1stLevel : ifc::internal::IfcRelSpaceBoundary {
  ifc::IfcRelSpaceBoundary1stLevel ParentBoundary;
};

struct IfcRelSpaceBoundary2ndLevel : ifc::internal::IfcRelSpaceBoundary1stLevel {
  ifc::IfcRelSpaceBoundary2ndLevel CorrespondingBoundary;
};

struct IfcRelVoidsElement : ifc::internal::IfcRelDecomposes {
  ifc::IfcElement RelatingBuildingElement;
  ifc::IfcFeatureElementSubtraction RelatedOpeningElement;
};

struct IfcReparametrisedCompositeCurveSegment : ifc::internal::IfcCompositeCurveSegment {
  ifc::IfcParameterValue ParamLength;
};

struct IfcRepresentation : ifc::internal::IfcEntity {
  ifc::IfcRepresentationContext ContextOfItems;
  ifc::IfcLabel RepresentationIdentifier;
  ifc::IfcLabel RepresentationType;
  std::unordered_set<ifc::IfcRepresentationItem> Items;
};

struct IfcRepresentationMap : ifc::internal::IfcEntity {
  ifc::IfcAxis2Placement MappingOrigin;
  ifc::IfcRepresentation MappedRepresentation;
};

struct IfcResourceApprovalRelationship : ifc::internal::IfcResourceLevelRelationship {
  std::unordered_set<ifc::IfcResourceObjectSelect> RelatedResourceObjects;
  ifc::IfcApproval RelatingApproval;
};

struct IfcResourceConstraintRelationship : ifc::internal::IfcResourceLevelRelationship {
  ifc::IfcConstraint RelatingConstraint;
  std::unordered_set<ifc::IfcResourceObjectSelect> RelatedResourceObjects;
};

struct IfcResourceTime : ifc::internal::IfcSchedulingTime {
  ifc::IfcDuration ScheduleWork;
  ifc::IfcPositiveRatioMeasure ScheduleUsage;
  ifc::IfcDateTime ScheduleStart;
  ifc::IfcDateTime ScheduleFinish;
  ifc::IfcLabel ScheduleContour;
  ifc::IfcDuration LevelingDelay;
  ifc::IfcBoolean IsOverAllocated;
  ifc::IfcDateTime StatusTime;
  ifc::IfcDuration ActualWork;
  ifc::IfcPositiveRatioMeasure ActualUsage;
  ifc::IfcDateTime ActualStart;
  ifc::IfcDateTime ActualFinish;
  ifc::IfcDuration RemainingWork;
  ifc::IfcPositiveRatioMeasure RemainingUsage;
  ifc::IfcPositiveRatioMeasure Completion;
};

struct IfcRevolvedAreaSolid : ifc::internal::IfcSweptAreaSolid {
  ifc::IfcAxis1Placement Axis;
  ifc::IfcPlaneAngleMeasure Angle;
};

struct IfcRevolvedAreaSolidTapered : ifc::internal::IfcRevolvedAreaSolid {
  ifc::IfcProfileDef EndSweptArea;
};

struct IfcRightCircularCone : ifc::internal::IfcCsgPrimitive3D {
  ifc::IfcPositiveLengthMeasure Height;
  ifc::IfcPositiveLengthMeasure BottomRadius;
};

struct IfcRightCircularCylinder : ifc::internal::IfcCsgPrimitive3D {
  ifc::IfcPositiveLengthMeasure Height;
  ifc::IfcPositiveLengthMeasure Radius;
};

struct IfcRoof : ifc::internal::IfcBuildingElement {
  ifc::IfcRoofTypeEnum PredefinedType;
};

struct IfcRoofType : ifc::internal::IfcBuildingElementType {
  ifc::IfcRoofTypeEnum PredefinedType;
};

struct IfcRoundedRectangleProfileDef : ifc::internal::IfcRectangleProfileDef {
  ifc::IfcPositiveLengthMeasure RoundingRadius;
};

struct IfcSIUnit : ifc::internal::IfcNamedUnit {
  ifc::IfcSIPrefix Prefix;
  ifc::IfcSIUnitName Name;
};

struct IfcSanitaryTerminal : ifc::internal::IfcFlowTerminal {
  ifc::IfcSanitaryTerminalTypeEnum PredefinedType;
};

struct IfcSanitaryTerminalType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcSanitaryTerminalTypeEnum PredefinedType;
};

struct IfcSeamCurve : ifc::internal::IfcSurfaceCurve {};

struct IfcSectionProperties : ifc::internal::IfcPreDefinedProperties {
  ifc::IfcSectionTypeEnum SectionType;
  ifc::IfcProfileDef StartProfile;
  ifc::IfcProfileDef EndProfile;
};

struct IfcSectionReinforcementProperties : ifc::internal::IfcPreDefinedProperties {
  ifc::IfcLengthMeasure LongitudinalStartPosition;
  ifc::IfcLengthMeasure LongitudinalEndPosition;
  ifc::IfcLengthMeasure TransversePosition;
  ifc::IfcReinforcingBarRoleEnum ReinforcementRole;
  ifc::IfcSectionProperties SectionDefinition;
  std::unordered_set<ifc::IfcReinforcementBarProperties> CrossSectionReinforcementDefinitions;
};

struct IfcSectionedSolid : ifc::internal::IfcSolidModel {
  ifc::IfcCurve Directrix;
  SmallVector<ifc::IfcProfileDef, 4> CrossSections;
};

struct IfcSectionedSolidHorizontal : ifc::internal::IfcSectionedSolid {
  SmallVector<ifc::IfcDistanceExpression, 4> CrossSectionPositions;
  ifc::IfcBoolean FixedAxisVertical;
};

struct IfcSectionedSpine : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcCompositeCurve SpineCurve;
  SmallVector<ifc::IfcProfileDef, 4> CrossSections;
  SmallVector<ifc::IfcAxis2Placement3D, 4> CrossSectionPositions;
};

struct IfcSensor : ifc::internal::IfcDistributionControlElement {
  ifc::IfcSensorTypeEnum PredefinedType;
};

struct IfcSensorType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcSensorTypeEnum PredefinedType;
};

struct IfcShadingDevice : ifc::internal::IfcBuildingElement {
  ifc::IfcShadingDeviceTypeEnum PredefinedType;
};

struct IfcShadingDeviceType : ifc::internal::IfcBuildingElementType {
  ifc::IfcShadingDeviceTypeEnum PredefinedType;
};

struct IfcShapeAspect : ifc::internal::IfcEntity {
  SmallVector<ifc::IfcShapeModel, 4> ShapeRepresentations;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcLogical ProductDefinitional;
  ifc::IfcProductRepresentationSelect PartOfProductDefinitionShape;
};

struct IfcShapeModel : ifc::internal::IfcRepresentation {};

struct IfcShapeRepresentation : ifc::internal::IfcShapeModel {};

struct IfcShellBasedSurfaceModel : ifc::internal::IfcGeometricRepresentationItem {
  std::unordered_set<ifc::IfcShell> SbsmBoundary;
};

struct IfcSimplePropertyTemplate : ifc::internal::IfcPropertyTemplate {
  ifc::IfcSimplePropertyTemplateTypeEnum TemplateType;
  ifc::IfcLabel PrimaryMeasureType;
  ifc::IfcLabel SecondaryMeasureType;
  ifc::IfcPropertyEnumeration Enumerators;
  ifc::IfcUnit PrimaryUnit;
  ifc::IfcUnit SecondaryUnit;
  ifc::IfcLabel Expression;
  ifc::IfcStateEnum AccessState;
};

struct IfcSite : ifc::internal::IfcSpatialStructureElement {
  ifc::IfcCompoundPlaneAngleMeasure RefLatitude;
  ifc::IfcCompoundPlaneAngleMeasure RefLongitude;
  ifc::IfcLengthMeasure RefElevation;
  ifc::IfcLabel LandTitleNumber;
  ifc::IfcPostalAddress SiteAddress;
};

struct IfcSlab : ifc::internal::IfcBuildingElement {
  ifc::IfcSlabTypeEnum PredefinedType;
};

struct IfcSlabElementedCase : ifc::internal::IfcSlab {};

struct IfcSlabStandardCase : ifc::internal::IfcSlab {};

struct IfcSlabType : ifc::internal::IfcBuildingElementType {
  ifc::IfcSlabTypeEnum PredefinedType;
};

struct IfcSlippageConnectionCondition : ifc::internal::IfcStructuralConnectionCondition {
  ifc::IfcLengthMeasure SlippageX;
  ifc::IfcLengthMeasure SlippageY;
  ifc::IfcLengthMeasure SlippageZ;
};

struct IfcSolarDevice : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcSolarDeviceTypeEnum PredefinedType;
};

struct IfcSolarDeviceType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcSolarDeviceTypeEnum PredefinedType;
};

struct IfcSpace : ifc::internal::IfcSpatialStructureElement {
  ifc::IfcSpaceTypeEnum PredefinedType;
  ifc::IfcLengthMeasure ElevationWithFlooring;
};

struct IfcSpaceHeater : ifc::internal::IfcFlowTerminal {
  ifc::IfcSpaceHeaterTypeEnum PredefinedType;
};

struct IfcSpaceHeaterType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcSpaceHeaterTypeEnum PredefinedType;
};

struct IfcSpatialElementType : ifc::internal::IfcTypeProduct {
  ifc::IfcLabel ElementType;
};

struct IfcSpatialStructureElementType : ifc::internal::IfcSpatialElementType {};

struct IfcSpaceType : ifc::internal::IfcSpatialStructureElementType {
  ifc::IfcSpaceTypeEnum PredefinedType;
  ifc::IfcLabel LongName;
};

struct IfcSpatialZone : ifc::internal::IfcSpatialElement {
  ifc::IfcSpatialZoneTypeEnum PredefinedType;
};

struct IfcSpatialZoneType : ifc::internal::IfcSpatialElementType {
  ifc::IfcSpatialZoneTypeEnum PredefinedType;
  ifc::IfcLabel LongName;
};

struct IfcSphere : ifc::internal::IfcCsgPrimitive3D {
  ifc::IfcPositiveLengthMeasure Radius;
};

struct IfcSphericalSurface : ifc::internal::IfcElementarySurface {
  ifc::IfcPositiveLengthMeasure Radius;
};

struct IfcStackTerminal : ifc::internal::IfcFlowTerminal {
  ifc::IfcStackTerminalTypeEnum PredefinedType;
};

struct IfcStackTerminalType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcStackTerminalTypeEnum PredefinedType;
};

struct IfcStair : ifc::internal::IfcBuildingElement {
  ifc::IfcStairTypeEnum PredefinedType;
};

struct IfcStairFlight : ifc::internal::IfcBuildingElement {
  ifc::IfcInteger NumberOfRisers;
  ifc::IfcInteger NumberOfTreads;
  ifc::IfcPositiveLengthMeasure RiserHeight;
  ifc::IfcPositiveLengthMeasure TreadLength;
  ifc::IfcStairFlightTypeEnum PredefinedType;
};

struct IfcStairFlightType : ifc::internal::IfcBuildingElementType {
  ifc::IfcStairFlightTypeEnum PredefinedType;
};

struct IfcStairType : ifc::internal::IfcBuildingElementType {
  ifc::IfcStairTypeEnum PredefinedType;
};

struct IfcStructuralActivity : ifc::internal::IfcProduct {
  ifc::IfcStructuralLoad AppliedLoad;
  ifc::IfcGlobalOrLocalEnum GlobalOrLocal;
};

struct IfcStructuralAction : ifc::internal::IfcStructuralActivity {
  ifc::IfcBoolean DestabilizingLoad;
};

struct IfcStructuralAnalysisModel : ifc::internal::IfcSystem {
  ifc::IfcAnalysisModelTypeEnum PredefinedType;
  ifc::IfcAxis2Placement3D OrientationOf2DPlane;
  std::unordered_set<ifc::IfcStructuralLoadGroup> LoadedBy;
  std::unordered_set<ifc::IfcStructuralResultGroup> HasResults;
  ifc::IfcObjectPlacement SharedPlacement;
};

struct IfcStructuralItem : ifc::internal::IfcProduct {};

struct IfcStructuralConnection : ifc::internal::IfcStructuralItem {
  ifc::IfcBoundaryCondition AppliedCondition;
};

struct IfcStructuralCurveAction : ifc::internal::IfcStructuralAction {
  ifc::IfcProjectedOrTrueLengthEnum ProjectedOrTrue;
  ifc::IfcStructuralCurveActivityTypeEnum PredefinedType;
};

struct IfcStructuralCurveConnection : ifc::internal::IfcStructuralConnection {
  ifc::IfcDirection Axis;
};

struct IfcStructuralMember : ifc::internal::IfcStructuralItem {};

struct IfcStructuralCurveMember : ifc::internal::IfcStructuralMember {
  ifc::IfcStructuralCurveMemberTypeEnum PredefinedType;
  ifc::IfcDirection Axis;
};

struct IfcStructuralCurveMemberVarying : ifc::internal::IfcStructuralCurveMember {};

struct IfcStructuralReaction : ifc::internal::IfcStructuralActivity {};

struct IfcStructuralCurveReaction : ifc::internal::IfcStructuralReaction {
  ifc::IfcStructuralCurveActivityTypeEnum PredefinedType;
};

struct IfcStructuralLinearAction : ifc::internal::IfcStructuralCurveAction {};

struct IfcStructuralLoad : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
};

struct IfcStructuralLoadGroup : ifc::internal::IfcGroup {
  ifc::IfcLoadGroupTypeEnum PredefinedType;
  ifc::IfcActionTypeEnum ActionType;
  ifc::IfcActionSourceTypeEnum ActionSource;
  ifc::IfcRatioMeasure Coefficient;
  ifc::IfcLabel Purpose;
};

struct IfcStructuralLoadCase : ifc::internal::IfcStructuralLoadGroup {
  SmallVector<ifc::IfcRatioMeasure, 3> SelfWeightCoefficients;
};

struct IfcStructuralLoadConfiguration : ifc::internal::IfcStructuralLoad {
  SmallVector<ifc::IfcStructuralLoadOrResult, 4> Values;
  SmallVector<SmallVector<ifc::IfcLengthMeasure, 2>, 4> Locations;
};

struct IfcStructuralLoadOrResult : ifc::internal::IfcStructuralLoad {};

struct IfcStructuralLoadStatic : ifc::internal::IfcStructuralLoadOrResult {};

struct IfcStructuralLoadLinearForce : ifc::internal::IfcStructuralLoadStatic {
  ifc::IfcLinearForceMeasure LinearForceX;
  ifc::IfcLinearForceMeasure LinearForceY;
  ifc::IfcLinearForceMeasure LinearForceZ;
  ifc::IfcLinearMomentMeasure LinearMomentX;
  ifc::IfcLinearMomentMeasure LinearMomentY;
  ifc::IfcLinearMomentMeasure LinearMomentZ;
};

struct IfcStructuralLoadPlanarForce : ifc::internal::IfcStructuralLoadStatic {
  ifc::IfcPlanarForceMeasure PlanarForceX;
  ifc::IfcPlanarForceMeasure PlanarForceY;
  ifc::IfcPlanarForceMeasure PlanarForceZ;
};

struct IfcStructuralLoadSingleDisplacement : ifc::internal::IfcStructuralLoadStatic {
  ifc::IfcLengthMeasure DisplacementX;
  ifc::IfcLengthMeasure DisplacementY;
  ifc::IfcLengthMeasure DisplacementZ;
  ifc::IfcPlaneAngleMeasure RotationalDisplacementRX;
  ifc::IfcPlaneAngleMeasure RotationalDisplacementRY;
  ifc::IfcPlaneAngleMeasure RotationalDisplacementRZ;
};

struct IfcStructuralLoadSingleDisplacementDistortion
    : ifc::internal::IfcStructuralLoadSingleDisplacement {
  ifc::IfcCurvatureMeasure Distortion;
};

struct IfcStructuralLoadSingleForce : ifc::internal::IfcStructuralLoadStatic {
  ifc::IfcForceMeasure ForceX;
  ifc::IfcForceMeasure ForceY;
  ifc::IfcForceMeasure ForceZ;
  ifc::IfcTorqueMeasure MomentX;
  ifc::IfcTorqueMeasure MomentY;
  ifc::IfcTorqueMeasure MomentZ;
};

struct IfcStructuralLoadSingleForceWarping : ifc::internal::IfcStructuralLoadSingleForce {
  ifc::IfcWarpingMomentMeasure WarpingMoment;
};

struct IfcStructuralLoadTemperature : ifc::internal::IfcStructuralLoadStatic {
  ifc::IfcThermodynamicTemperatureMeasure DeltaTConstant;
  ifc::IfcThermodynamicTemperatureMeasure DeltaTY;
  ifc::IfcThermodynamicTemperatureMeasure DeltaTZ;
};

struct IfcStructuralSurfaceAction : ifc::internal::IfcStructuralAction {
  ifc::IfcProjectedOrTrueLengthEnum ProjectedOrTrue;
  ifc::IfcStructuralSurfaceActivityTypeEnum PredefinedType;
};

struct IfcStructuralPlanarAction : ifc::internal::IfcStructuralSurfaceAction {};

struct IfcStructuralPointAction : ifc::internal::IfcStructuralAction {};

struct IfcStructuralPointConnection : ifc::internal::IfcStructuralConnection {
  ifc::IfcAxis2Placement3D ConditionCoordinateSystem;
};

struct IfcStructuralPointReaction : ifc::internal::IfcStructuralReaction {};

struct IfcStructuralResultGroup : ifc::internal::IfcGroup {
  ifc::IfcAnalysisTheoryTypeEnum TheoryType;
  ifc::IfcStructuralLoadGroup ResultForLoadGroup;
  ifc::IfcBoolean IsLinear;
};

struct IfcStructuralSurfaceConnection : ifc::internal::IfcStructuralConnection {};

struct IfcStructuralSurfaceMember : ifc::internal::IfcStructuralMember {
  ifc::IfcStructuralSurfaceMemberTypeEnum PredefinedType;
  ifc::IfcPositiveLengthMeasure Thickness;
};

struct IfcStructuralSurfaceMemberVarying : ifc::internal::IfcStructuralSurfaceMember {};

struct IfcStructuralSurfaceReaction : ifc::internal::IfcStructuralReaction {
  ifc::IfcStructuralSurfaceActivityTypeEnum PredefinedType;
};

struct IfcStyleModel : ifc::internal::IfcRepresentation {};

struct IfcStyledItem : ifc::internal::IfcRepresentationItem {
  ifc::IfcRepresentationItem Item;
  std::unordered_set<ifc::IfcStyleAssignmentSelect> Styles;
  ifc::IfcLabel Name;
};

struct IfcStyledRepresentation : ifc::internal::IfcStyleModel {};

struct IfcSubContractResource : ifc::internal::IfcConstructionResource {
  ifc::IfcSubContractResourceTypeEnum PredefinedType;
};

struct IfcSubContractResourceType : ifc::internal::IfcConstructionResourceType {
  ifc::IfcSubContractResourceTypeEnum PredefinedType;
};

struct IfcSubedge : ifc::internal::IfcEdge {
  ifc::IfcEdge ParentEdge;
};

struct IfcSurfaceCurveSweptAreaSolid : ifc::internal::IfcSweptAreaSolid {
  ifc::IfcCurve Directrix;
  ifc::IfcParameterValue StartParam;
  ifc::IfcParameterValue EndParam;
  ifc::IfcSurface ReferenceSurface;
};

struct IfcSurfaceFeature : ifc::internal::IfcFeatureElement {
  ifc::IfcSurfaceFeatureTypeEnum PredefinedType;
};

struct IfcSweptSurface : ifc::internal::IfcSurface {
  ifc::IfcProfileDef SweptCurve;
  ifc::IfcAxis2Placement3D Position;
};

struct IfcSurfaceOfLinearExtrusion : ifc::internal::IfcSweptSurface {
  ifc::IfcDirection ExtrudedDirection;
  ifc::IfcLengthMeasure Depth;
};

struct IfcSurfaceOfRevolution : ifc::internal::IfcSweptSurface {
  ifc::IfcAxis1Placement AxisPosition;
};

struct IfcSurfaceReinforcementArea : ifc::internal::IfcStructuralLoadOrResult {
  SmallVector<ifc::IfcLengthMeasure, 3> SurfaceReinforcement1;
  SmallVector<ifc::IfcLengthMeasure, 3> SurfaceReinforcement2;
  ifc::IfcRatioMeasure ShearReinforcement;
};

struct IfcSurfaceStyle : ifc::internal::IfcPresentationStyle {
  ifc::IfcSurfaceSide Side;
  std::unordered_set<ifc::IfcSurfaceStyleElementSelect> Styles;
};

struct IfcSurfaceStyleLighting : ifc::internal::IfcPresentationItem {
  ifc::IfcColourRgb DiffuseTransmissionColour;
  ifc::IfcColourRgb DiffuseReflectionColour;
  ifc::IfcColourRgb TransmissionColour;
  ifc::IfcColourRgb ReflectanceColour;
};

struct IfcSurfaceStyleRefraction : ifc::internal::IfcPresentationItem {
  ifc::IfcReal RefractionIndex;
  ifc::IfcReal DispersionFactor;
};

struct IfcSurfaceStyleShading : ifc::internal::IfcPresentationItem {
  ifc::IfcColourRgb SurfaceColour;
  ifc::IfcNormalisedRatioMeasure Transparency;
};

struct IfcSurfaceStyleRendering : ifc::internal::IfcSurfaceStyleShading {
  ifc::IfcColourOrFactor DiffuseColour;
  ifc::IfcColourOrFactor TransmissionColour;
  ifc::IfcColourOrFactor DiffuseTransmissionColour;
  ifc::IfcColourOrFactor ReflectionColour;
  ifc::IfcColourOrFactor SpecularColour;
  ifc::IfcSpecularHighlightSelect SpecularHighlight;
  ifc::IfcReflectanceMethodEnum ReflectanceMethod;
};

struct IfcSurfaceStyleWithTextures : ifc::internal::IfcPresentationItem {
  SmallVector<ifc::IfcSurfaceTexture, 4> Textures;
};

struct IfcSweptDiskSolid : ifc::internal::IfcSolidModel {
  ifc::IfcCurve Directrix;
  ifc::IfcPositiveLengthMeasure Radius;
  ifc::IfcPositiveLengthMeasure InnerRadius;
  ifc::IfcParameterValue StartParam;
  ifc::IfcParameterValue EndParam;
};

struct IfcSweptDiskSolidPolygonal : ifc::internal::IfcSweptDiskSolid {
  ifc::IfcPositiveLengthMeasure FilletRadius;
};

struct IfcSwitchingDevice : ifc::internal::IfcFlowController {
  ifc::IfcSwitchingDeviceTypeEnum PredefinedType;
};

struct IfcSwitchingDeviceType : ifc::internal::IfcFlowControllerType {
  ifc::IfcSwitchingDeviceTypeEnum PredefinedType;
};

struct IfcSystemFurnitureElement : ifc::internal::IfcFurnishingElement {
  ifc::IfcSystemFurnitureElementTypeEnum PredefinedType;
};

struct IfcSystemFurnitureElementType : ifc::internal::IfcFurnishingElementType {
  ifc::IfcSystemFurnitureElementTypeEnum PredefinedType;
};

struct IfcTShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure Depth;
  ifc::IfcPositiveLengthMeasure FlangeWidth;
  ifc::IfcPositiveLengthMeasure WebThickness;
  ifc::IfcPositiveLengthMeasure FlangeThickness;
  ifc::IfcNonNegativeLengthMeasure FilletRadius;
  ifc::IfcNonNegativeLengthMeasure FlangeEdgeRadius;
  ifc::IfcNonNegativeLengthMeasure WebEdgeRadius;
  ifc::IfcPlaneAngleMeasure WebSlope;
  ifc::IfcPlaneAngleMeasure FlangeSlope;
};

struct IfcTable : ifc::internal::IfcEntity {
  ifc::IfcLabel Name;
  SmallVector<ifc::IfcTableRow, 4> Rows;
  SmallVector<ifc::IfcTableColumn, 4> Columns;
};

struct IfcTableColumn : ifc::internal::IfcEntity {
  ifc::IfcIdentifier Identifier;
  ifc::IfcLabel Name;
  ifc::IfcText Description;
  ifc::IfcUnit Unit;
  ifc::IfcReference ReferencePath;
};

struct IfcTableRow : ifc::internal::IfcEntity {
  SmallVector<ifc::IfcValue, 4> RowCells;
  ifc::IfcBoolean IsHeading;
};

struct IfcTank : ifc::internal::IfcFlowStorageDevice {
  ifc::IfcTankTypeEnum PredefinedType;
};

struct IfcTankType : ifc::internal::IfcFlowStorageDeviceType {
  ifc::IfcTankTypeEnum PredefinedType;
};

struct IfcTask : ifc::internal::IfcProcess {
  ifc::IfcLabel Status;
  ifc::IfcLabel WorkMethod;
  ifc::IfcBoolean IsMilestone;
  ifc::IfcInteger Priority;
  ifc::IfcTaskTime TaskTime;
  ifc::IfcTaskTypeEnum PredefinedType;
};

struct IfcTaskTime : ifc::internal::IfcSchedulingTime {
  ifc::IfcTaskDurationEnum DurationType;
  ifc::IfcDuration ScheduleDuration;
  ifc::IfcDateTime ScheduleStart;
  ifc::IfcDateTime ScheduleFinish;
  ifc::IfcDateTime EarlyStart;
  ifc::IfcDateTime EarlyFinish;
  ifc::IfcDateTime LateStart;
  ifc::IfcDateTime LateFinish;
  ifc::IfcDuration FreeFloat;
  ifc::IfcDuration TotalFloat;
  ifc::IfcBoolean IsCritical;
  ifc::IfcDateTime StatusTime;
  ifc::IfcDuration ActualDuration;
  ifc::IfcDateTime ActualStart;
  ifc::IfcDateTime ActualFinish;
  ifc::IfcDuration RemainingTime;
  ifc::IfcPositiveRatioMeasure Completion;
};

struct IfcTaskTimeRecurring : ifc::internal::IfcTaskTime {
  ifc::IfcRecurrencePattern Recurrence;
};

struct IfcTaskType : ifc::internal::IfcTypeProcess {
  ifc::IfcTaskTypeEnum PredefinedType;
  ifc::IfcLabel WorkMethod;
};

struct IfcTelecomAddress : ifc::internal::IfcAddress {
  SmallVector<ifc::IfcLabel, 4> TelephoneNumbers;
  SmallVector<ifc::IfcLabel, 4> FacsimileNumbers;
  ifc::IfcLabel PagerNumber;
  SmallVector<ifc::IfcLabel, 4> ElectronicMailAddresses;
  ifc::IfcURIReference WWWHomePageURL;
  SmallVector<ifc::IfcURIReference, 4> MessagingIDs;
};

struct IfcTendon : ifc::internal::IfcReinforcingElement {
  ifc::IfcTendonTypeEnum PredefinedType;
  ifc::IfcPositiveLengthMeasure NominalDiameter;
  ifc::IfcAreaMeasure CrossSectionArea;
  ifc::IfcForceMeasure TensionForce;
  ifc::IfcPressureMeasure PreStress;
  ifc::IfcNormalisedRatioMeasure FrictionCoefficient;
  ifc::IfcPositiveLengthMeasure AnchorageSlip;
  ifc::IfcPositiveLengthMeasure MinCurvatureRadius;
};

struct IfcTendonAnchor : ifc::internal::IfcReinforcingElement {
  ifc::IfcTendonAnchorTypeEnum PredefinedType;
};

struct IfcTendonAnchorType : ifc::internal::IfcReinforcingElementType {
  ifc::IfcTendonAnchorTypeEnum PredefinedType;
};

struct IfcTendonType : ifc::internal::IfcReinforcingElementType {
  ifc::IfcTendonTypeEnum PredefinedType;
  ifc::IfcPositiveLengthMeasure NominalDiameter;
  ifc::IfcAreaMeasure CrossSectionArea;
  ifc::IfcPositiveLengthMeasure SheathDiameter;
};

struct IfcTextLiteral : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcPresentableText Literal;
  ifc::IfcAxis2Placement Placement;
  ifc::IfcTextPath Path;
};

struct IfcTextLiteralWithExtent : ifc::internal::IfcTextLiteral {
  ifc::IfcPlanarExtent Extent;
  ifc::IfcBoxAlignment BoxAlignment;
};

struct IfcTextStyle : ifc::internal::IfcPresentationStyle {
  ifc::IfcTextStyleForDefinedFont TextCharacterAppearance;
  ifc::IfcTextStyleTextModel TextStyle;
  ifc::IfcTextFontSelect TextFontStyle;
  ifc::IfcBoolean ModelOrDraughting;
};

struct IfcTextStyleFontModel : ifc::internal::IfcPreDefinedTextFont {
  SmallVector<ifc::IfcTextFontName, 4> FontFamily;
  ifc::IfcFontStyle FontStyle;
  ifc::IfcFontVariant FontVariant;
  ifc::IfcFontWeight FontWeight;
  ifc::IfcSizeSelect FontSize;
};

struct IfcTextStyleForDefinedFont : ifc::internal::IfcPresentationItem {
  ifc::IfcColour Colour;
  ifc::IfcColour BackgroundColour;
};

struct IfcTextStyleTextModel : ifc::internal::IfcPresentationItem {
  ifc::IfcSizeSelect TextIndent;
  ifc::IfcTextAlignment TextAlign;
  ifc::IfcTextDecoration TextDecoration;
  ifc::IfcSizeSelect LetterSpacing;
  ifc::IfcSizeSelect WordSpacing;
  ifc::IfcTextTransformation TextTransform;
  ifc::IfcSizeSelect LineHeight;
};

struct IfcTextureCoordinateGenerator : ifc::internal::IfcTextureCoordinate {
  ifc::IfcLabel Mode;
  SmallVector<ifc::IfcReal, 4> Parameter;
};

struct IfcTextureMap : ifc::internal::IfcTextureCoordinate {
  SmallVector<ifc::IfcTextureVertex, 4> Vertices;
  ifc::IfcFace MappedTo;
};

struct IfcTextureVertex : ifc::internal::IfcPresentationItem {
  SmallVector<ifc::IfcParameterValue, 2> Coordinates;
};

struct IfcTextureVertexList : ifc::internal::IfcPresentationItem {
  SmallVector<SmallVector<ifc::IfcParameterValue, 2>, 4> TexCoordsList;
};

struct IfcTimePeriod : ifc::internal::IfcEntity {
  ifc::IfcTime StartTime;
  ifc::IfcTime EndTime;
};

struct IfcTimeSeriesValue : ifc::internal::IfcEntity {
  SmallVector<ifc::IfcValue, 4> ListValues;
};

struct IfcTopologyRepresentation : ifc::internal::IfcShapeModel {};

struct IfcToroidalSurface : ifc::internal::IfcElementarySurface {
  ifc::IfcPositiveLengthMeasure MajorRadius;
  ifc::IfcPositiveLengthMeasure MinorRadius;
};

struct IfcTransformer : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcTransformerTypeEnum PredefinedType;
};

struct IfcTransformerType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcTransformerTypeEnum PredefinedType;
};

struct IfcTransitionCurveSegment2D : ifc::internal::IfcCurveSegment2D {
  ifc::IfcPositiveLengthMeasure StartRadius;
  ifc::IfcPositiveLengthMeasure EndRadius;
  ifc::IfcBoolean IsStartRadiusCCW;
  ifc::IfcBoolean IsEndRadiusCCW;
  ifc::IfcTransitionCurveType TransitionCurveType;
};

struct IfcTransportElement : ifc::internal::IfcElement {
  ifc::IfcTransportElementTypeEnum PredefinedType;
};

struct IfcTransportElementType : ifc::internal::IfcElementType {
  ifc::IfcTransportElementTypeEnum PredefinedType;
};

struct IfcTrapeziumProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure BottomXDim;
  ifc::IfcPositiveLengthMeasure TopXDim;
  ifc::IfcPositiveLengthMeasure YDim;
  ifc::IfcLengthMeasure TopXOffset;
};

struct IfcTriangulatedFaceSet : ifc::internal::IfcTessellatedFaceSet {
  SmallVector<SmallVector<ifc::IfcParameterValue, 3>, 4> Normals;
  ifc::IfcBoolean Closed;
  SmallVector<SmallVector<ifc::IfcPositiveInteger, 3>, 4> CoordIndex;
  SmallVector<ifc::IfcPositiveInteger, 4> PnIndex;
};

struct IfcTriangulatedIrregularNetwork : ifc::internal::IfcTriangulatedFaceSet {
  SmallVector<ifc::IfcInteger, 4> Flags;
};

struct IfcTrimmedCurve : ifc::internal::IfcBoundedCurve {
  ifc::IfcCurve BasisCurve;
  std::unordered_set<ifc::IfcTrimmingSelect> Trim1;
  std::unordered_set<ifc::IfcTrimmingSelect> Trim2;
  ifc::IfcBoolean SenseAgreement;
  ifc::IfcTrimmingPreference MasterRepresentation;
};

struct IfcTubeBundle : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcTubeBundleTypeEnum PredefinedType;
};

struct IfcTubeBundleType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcTubeBundleTypeEnum PredefinedType;
};

struct IfcUShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure Depth;
  ifc::IfcPositiveLengthMeasure FlangeWidth;
  ifc::IfcPositiveLengthMeasure WebThickness;
  ifc::IfcPositiveLengthMeasure FlangeThickness;
  ifc::IfcNonNegativeLengthMeasure FilletRadius;
  ifc::IfcNonNegativeLengthMeasure EdgeRadius;
  ifc::IfcPlaneAngleMeasure FlangeSlope;
};

struct IfcUnitAssignment : ifc::internal::IfcEntity {
  std::unordered_set<ifc::IfcUnit> Units;
};

struct IfcUnitaryControlElement : ifc::internal::IfcDistributionControlElement {
  ifc::IfcUnitaryControlElementTypeEnum PredefinedType;
};

struct IfcUnitaryControlElementType : ifc::internal::IfcDistributionControlElementType {
  ifc::IfcUnitaryControlElementTypeEnum PredefinedType;
};

struct IfcUnitaryEquipment : ifc::internal::IfcEnergyConversionDevice {
  ifc::IfcUnitaryEquipmentTypeEnum PredefinedType;
};

struct IfcUnitaryEquipmentType : ifc::internal::IfcEnergyConversionDeviceType {
  ifc::IfcUnitaryEquipmentTypeEnum PredefinedType;
};

struct IfcValve : ifc::internal::IfcFlowController {
  ifc::IfcValveTypeEnum PredefinedType;
};

struct IfcValveType : ifc::internal::IfcFlowControllerType {
  ifc::IfcValveTypeEnum PredefinedType;
};

struct IfcVector : ifc::internal::IfcGeometricRepresentationItem {
  ifc::IfcDirection Orientation;
  ifc::IfcLengthMeasure Magnitude;
};

struct IfcVertex : ifc::internal::IfcTopologicalRepresentationItem {};

struct IfcVertexLoop : ifc::internal::IfcLoop {
  ifc::IfcVertex LoopVertex;
};

struct IfcVertexPoint : ifc::internal::IfcVertex {
  ifc::IfcPoint VertexGeometry;
};

struct IfcVibrationIsolator : ifc::internal::IfcElementComponent {
  ifc::IfcVibrationIsolatorTypeEnum PredefinedType;
};

struct IfcVibrationIsolatorType : ifc::internal::IfcElementComponentType {
  ifc::IfcVibrationIsolatorTypeEnum PredefinedType;
};

struct IfcVirtualElement : ifc::internal::IfcElement {};

struct IfcVirtualGridIntersection : ifc::internal::IfcEntity {
  SmallVector<ifc::IfcGridAxis, 2> IntersectingAxes;
  SmallVector<ifc::IfcLengthMeasure, 3> OffsetDistances;
};

struct IfcVoidingFeature : ifc::internal::IfcFeatureElementSubtraction {
  ifc::IfcVoidingFeatureTypeEnum PredefinedType;
};

struct IfcWall : ifc::internal::IfcBuildingElement {
  ifc::IfcWallTypeEnum PredefinedType;
};

struct IfcWallElementedCase : ifc::internal::IfcWall {};

struct IfcWallStandardCase : ifc::internal::IfcWall {};

struct IfcWallType : ifc::internal::IfcBuildingElementType {
  ifc::IfcWallTypeEnum PredefinedType;
};

struct IfcWasteTerminal : ifc::internal::IfcFlowTerminal {
  ifc::IfcWasteTerminalTypeEnum PredefinedType;
};

struct IfcWasteTerminalType : ifc::internal::IfcFlowTerminalType {
  ifc::IfcWasteTerminalTypeEnum PredefinedType;
};

struct IfcWindow : ifc::internal::IfcBuildingElement {
  ifc::IfcPositiveLengthMeasure OverallHeight;
  ifc::IfcPositiveLengthMeasure OverallWidth;
  ifc::IfcWindowTypeEnum PredefinedType;
  ifc::IfcWindowTypePartitioningEnum PartitioningType;
  ifc::IfcLabel UserDefinedPartitioningType;
};

struct IfcWindowLiningProperties : ifc::internal::IfcPreDefinedPropertySet {
  ifc::IfcPositiveLengthMeasure LiningDepth;
  ifc::IfcNonNegativeLengthMeasure LiningThickness;
  ifc::IfcNonNegativeLengthMeasure TransomThickness;
  ifc::IfcNonNegativeLengthMeasure MullionThickness;
  ifc::IfcNormalisedRatioMeasure FirstTransomOffset;
  ifc::IfcNormalisedRatioMeasure SecondTransomOffset;
  ifc::IfcNormalisedRatioMeasure FirstMullionOffset;
  ifc::IfcNormalisedRatioMeasure SecondMullionOffset;
  ifc::IfcShapeAspect ShapeAspectStyle;
  ifc::IfcLengthMeasure LiningOffset;
  ifc::IfcLengthMeasure LiningToPanelOffsetX;
  ifc::IfcLengthMeasure LiningToPanelOffsetY;
};

struct IfcWindowPanelProperties : ifc::internal::IfcPreDefinedPropertySet {
  ifc::IfcWindowPanelOperationEnum OperationType;
  ifc::IfcWindowPanelPositionEnum PanelPosition;
  ifc::IfcPositiveLengthMeasure FrameDepth;
  ifc::IfcPositiveLengthMeasure FrameThickness;
  ifc::IfcShapeAspect ShapeAspectStyle;
};

struct IfcWindowStandardCase : ifc::internal::IfcWindow {};

struct IfcWindowStyle : ifc::internal::IfcTypeProduct {
  ifc::IfcWindowStyleConstructionEnum ConstructionType;
  ifc::IfcWindowStyleOperationEnum OperationType;
  ifc::IfcBoolean ParameterTakesPrecedence;
  ifc::IfcBoolean Sizeable;
};

struct IfcWindowType : ifc::internal::IfcBuildingElementType {
  ifc::IfcWindowTypeEnum PredefinedType;
  ifc::IfcWindowTypePartitioningEnum PartitioningType;
  ifc::IfcBoolean ParameterTakesPrecedence;
  ifc::IfcLabel UserDefinedPartitioningType;
};

struct IfcWorkCalendar : ifc::internal::IfcControl {
  std::unordered_set<ifc::IfcWorkTime> WorkingTimes;
  std::unordered_set<ifc::IfcWorkTime> ExceptionTimes;
  ifc::IfcWorkCalendarTypeEnum PredefinedType;
};

struct IfcWorkControl : ifc::internal::IfcControl {
  ifc::IfcDateTime CreationDate;
  std::unordered_set<ifc::IfcPerson> Creators;
  ifc::IfcLabel Purpose;
  ifc::IfcDuration Duration;
  ifc::IfcDuration TotalFloat;
  ifc::IfcDateTime StartTime;
  ifc::IfcDateTime FinishTime;
};

struct IfcWorkPlan : ifc::internal::IfcWorkControl {
  ifc::IfcWorkPlanTypeEnum PredefinedType;
};

struct IfcWorkSchedule : ifc::internal::IfcWorkControl {
  ifc::IfcWorkScheduleTypeEnum PredefinedType;
};

struct IfcWorkTime : ifc::internal::IfcSchedulingTime {
  ifc::IfcRecurrencePattern RecurrencePattern;
  ifc::IfcDate Start;
  ifc::IfcDate Finish;
};

struct IfcZShapeProfileDef : ifc::internal::IfcParameterizedProfileDef {
  ifc::IfcPositiveLengthMeasure Depth;
  ifc::IfcPositiveLengthMeasure FlangeWidth;
  ifc::IfcPositiveLengthMeasure WebThickness;
  ifc::IfcPositiveLengthMeasure FlangeThickness;
  ifc::IfcNonNegativeLengthMeasure FilletRadius;
  ifc::IfcNonNegativeLengthMeasure EdgeRadius;
};

struct IfcZone : ifc::internal::IfcSystem {
  ifc::IfcLabel LongName;
};

} // namespace ifc::internal

#endif // IMPORT_IFC_EXTERNAL_ENTITIES_H_
