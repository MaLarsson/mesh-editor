#pragma once

#ifndef IMPORT_IFC_EXTERNAL_TYPES_H_
#define IMPORT_IFC_EXTERNAL_TYPES_H_

#include "../../utility/SmallVector.h"
#include "Forward.h"

#include <cstddef>
#include <string>
#include <unordered_set>
#include <variant>

namespace ifc {

using IfcAbsorbedDoseMeasure = double;
using IfcAccelerationMeasure = double;
using IfcAmountOfSubstanceMeasure = double;
using IfcAngularVelocityMeasure = double;
using IfcArcIndex = SmallVector<IfcPositiveInteger, 3>;
using IfcAreaDensityMeasure = double;
using IfcAreaMeasure = double;
using IfcBinary = SmallVector<std::byte, 4>;
using IfcBoolean = bool;
using IfcBoxAlignment = IfcLabel;
using IfcCardinalPointReference = int;
using IfcComplexNumber = SmallVector<double, 2>;
using IfcCompoundPlaneAngleMeasure = SmallVector<int, 4>;
using IfcContextDependentMeasure = double;
using IfcCountMeasure = double;
using IfcCurvatureMeasure = double;
using IfcDate = std::string;
using IfcDateTime = std::string;
using IfcDayInMonthNumber = int;
using IfcDayInWeekNumber = int;
using IfcDescriptiveMeasure = std::string;
using IfcDimensionCount = int;
using IfcDoseEquivalentMeasure = double;
using IfcDuration = std::string;
using IfcDynamicViscosityMeasure = double;
using IfcElectricCapacitanceMeasure = double;
using IfcElectricChargeMeasure = double;
using IfcElectricConductanceMeasure = double;
using IfcElectricCurrentMeasure = double;
using IfcElectricResistanceMeasure = double;
using IfcElectricVoltageMeasure = double;
using IfcEnergyMeasure = double;
using IfcFontStyle = std::string;
using IfcFontVariant = std::string;
using IfcFontWeight = std::string;
using IfcForceMeasure = double;
using IfcFrequencyMeasure = double;
using IfcGloballyUniqueId = std::string;
using IfcHeatFluxDensityMeasure = double;
using IfcHeatingValueMeasure = double;
using IfcIdentifier = std::string;
using IfcIlluminanceMeasure = double;
using IfcInductanceMeasure = double;
using IfcInteger = int;
using IfcIntegerCountRateMeasure = int;
using IfcIonConcentrationMeasure = double;
using IfcIsothermalMoistureCapacityMeasure = double;
using IfcKinematicViscosityMeasure = double;
using IfcLabel = std::string;
using IfcLanguageId = IfcIdentifier;
using IfcLengthMeasure = double;
using IfcLineIndex = SmallVector<IfcPositiveInteger, 4>;
using IfcLinearForceMeasure = double;
using IfcLinearMomentMeasure = double;
using IfcLinearStiffnessMeasure = double;
using IfcLinearVelocityMeasure = double;

enum class IfcLogical { TRUE, FALSE, UNKNOWN };

using IfcLuminousFluxMeasure = double;
using IfcLuminousIntensityDistributionMeasure = double;
using IfcLuminousIntensityMeasure = double;
using IfcMagneticFluxDensityMeasure = double;
using IfcMagneticFluxMeasure = double;
using IfcMassDensityMeasure = double;
using IfcMassFlowRateMeasure = double;
using IfcMassMeasure = double;
using IfcMassPerLengthMeasure = double;
using IfcModulusOfElasticityMeasure = double;
using IfcModulusOfLinearSubgradeReactionMeasure = double;
using IfcModulusOfRotationalSubgradeReactionMeasure = double;
using IfcModulusOfSubgradeReactionMeasure = double;
using IfcMoistureDiffusivityMeasure = double;
using IfcMolecularWeightMeasure = double;
using IfcMomentOfInertiaMeasure = double;
using IfcMonetaryMeasure = double;
using IfcMonthInYearNumber = int;
using IfcNonNegativeLengthMeasure = IfcLengthMeasure;
using IfcNormalisedRatioMeasure = IfcRatioMeasure;
using IfcNumericMeasure = double;
using IfcPHMeasure = double;
using IfcParameterValue = double;
using IfcPlanarForceMeasure = double;
using IfcPlaneAngleMeasure = double;
using IfcPositiveInteger = IfcInteger;
using IfcPositiveLengthMeasure = IfcLengthMeasure;
using IfcPositivePlaneAngleMeasure = IfcPlaneAngleMeasure;
using IfcPositiveRatioMeasure = IfcRatioMeasure;
using IfcPowerMeasure = double;
using IfcPresentableText = std::string;
using IfcPressureMeasure = double;
using IfcPropertySetDefinitionSet = std::unordered_set<IfcPropertySetDefinition>;
using IfcRadioActivityMeasure = double;
using IfcRatioMeasure = double;
using IfcReal = double;
using IfcRotationalFrequencyMeasure = double;
using IfcRotationalMassMeasure = double;
using IfcRotationalStiffnessMeasure = double;
using IfcSectionModulusMeasure = double;
using IfcSectionalAreaIntegralMeasure = double;
using IfcShearModulusMeasure = double;
using IfcSolidAngleMeasure = double;
using IfcSoundPowerLevelMeasure = double;
using IfcSoundPowerMeasure = double;
using IfcSoundPressureLevelMeasure = double;
using IfcSoundPressureMeasure = double;
using IfcSpecificHeatCapacityMeasure = double;
using IfcSpecularExponent = double;
using IfcSpecularRoughness = double;
using IfcTemperatureGradientMeasure = double;
using IfcTemperatureRateOfChangeMeasure = double;
using IfcText = std::string;
using IfcTextAlignment = std::string;
using IfcTextDecoration = std::string;
using IfcTextFontName = std::string;
using IfcTextTransformation = std::string;
using IfcThermalAdmittanceMeasure = double;
using IfcThermalConductivityMeasure = double;
using IfcThermalExpansionCoefficientMeasure = double;
using IfcThermalResistanceMeasure = double;
using IfcThermalTransmittanceMeasure = double;
using IfcThermodynamicTemperatureMeasure = double;
using IfcTime = std::string;
using IfcTimeMeasure = double;
using IfcTimeStamp = int;
using IfcTorqueMeasure = double;
using IfcURIReference = std::string;
using IfcVaporPermeabilityMeasure = double;
using IfcVolumeMeasure = double;
using IfcVolumetricFlowRateMeasure = double;
using IfcWarpingConstantMeasure = double;
using IfcWarpingMomentMeasure = double;

enum class IfcActionRequestTypeEnum { EMAIL, FAX, PHONE, POST, VERBAL, USERDEFINED, NOTDEFINED };

enum class IfcActionSourceTypeEnum {
  DEAD_LOAD_G,
  COMPLETION_G1,
  LIVE_LOAD_Q,
  SNOW_S,
  WIND_W,
  PRESTRESSING_P,
  SETTLEMENT_U,
  TEMPERATURE_T,
  EARTHQUAKE_E,
  FIRE,
  IMPULSE,
  IMPACT,
  TRANSPORT,
  ERECTION,
  PROPPING,
  SYSTEM_IMPERFECTION,
  SHRINKAGE,
  CREEP,
  LACK_OF_FIT,
  BUOYANCY,
  ICE,
  CURRENT,
  WAVE,
  RAIN,
  BRAKES,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcActionTypeEnum { PERMANENT_G, VARIABLE_Q, EXTRAORDINARY_A, USERDEFINED, NOTDEFINED };

enum class IfcActuatorTypeEnum {
  ELECTRICACTUATOR,
  HANDOPERATEDACTUATOR,
  HYDRAULICACTUATOR,
  PNEUMATICACTUATOR,
  THERMOSTATICACTUATOR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcAddressTypeEnum { OFFICE, SITE, HOME, DISTRIBUTIONPOINT, USERDEFINED };

enum class IfcAirTerminalBoxTypeEnum {
  CONSTANTFLOW,
  VARIABLEFLOWPRESSUREDEPENDANT,
  VARIABLEFLOWPRESSUREINDEPENDANT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcAirTerminalTypeEnum { DIFFUSER, GRILLE, LOUVRE, REGISTER, USERDEFINED, NOTDEFINED };

enum class IfcAirToAirHeatRecoveryTypeEnum {
  FIXEDPLATECOUNTERFLOWEXCHANGER,
  FIXEDPLATECROSSFLOWEXCHANGER,
  FIXEDPLATEPARALLELFLOWEXCHANGER,
  ROTARYWHEEL,
  RUNAROUNDCOILLOOP,
  HEATPIPE,
  TWINTOWERENTHALPYRECOVERYLOOPS,
  THERMOSIPHONSEALEDTUBEHEATEXCHANGERS,
  THERMOSIPHONCOILTYPEHEATEXCHANGERS,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcAlarmTypeEnum {
  BELL,
  BREAKGLASSBUTTON,
  LIGHT,
  MANUALPULLBOX,
  SIREN,
  WHISTLE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcAlignmentTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcAnalysisModelTypeEnum {
  IN_PLANE_LOADING_2D,
  OUT_PLANE_LOADING_2D,
  LOADING_3D,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcAnalysisTheoryTypeEnum {
  FIRST_ORDER_THEORY,
  SECOND_ORDER_THEORY,
  THIRD_ORDER_THEORY,
  FULL_NONLINEAR_THEORY,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcArithmeticOperatorEnum { ADD, DIVIDE, MULTIPLY, SUBTRACT };

enum class IfcAssemblyPlaceEnum { SITE, FACTORY, NOTDEFINED };

enum class IfcAudioVisualApplianceTypeEnum {
  AMPLIFIER,
  CAMERA,
  DISPLAY,
  MICROPHONE,
  PLAYER,
  PROJECTOR,
  RECEIVER,
  SPEAKER,
  SWITCHER,
  TELEPHONE,
  TUNER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcBSplineCurveForm {
  POLYLINE_FORM,
  CIRCULAR_ARC,
  ELLIPTIC_ARC,
  PARABOLIC_ARC,
  HYPERBOLIC_ARC,
  UNSPECIFIED
};

enum class IfcBSplineSurfaceForm {
  PLANE_SURF,
  CYLINDRICAL_SURF,
  CONICAL_SURF,
  SPHERICAL_SURF,
  TOROIDAL_SURF,
  SURF_OF_REVOLUTION,
  RULED_SURF,
  GENERALISED_CONE,
  QUADRIC_SURF,
  SURF_OF_LINEAR_EXTRUSION,
  UNSPECIFIED
};

enum class IfcBeamTypeEnum {
  BEAM,
  JOIST,
  HOLLOWCORE,
  LINTEL,
  SPANDREL,
  T_BEAM,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcBenchmarkEnum {
  GREATERTHAN,
  GREATERTHANOREQUALTO,
  LESSTHAN,
  LESSTHANOREQUALTO,
  EQUALTO,
  NOTEQUALTO,
  INCLUDES,
  NOTINCLUDES,
  INCLUDEDIN,
  NOTINCLUDEDIN
};

enum class IfcBoilerTypeEnum { WATER, STEAM, USERDEFINED, NOTDEFINED };

enum class IfcBooleanOperator { UNION, INTERSECTION, DIFFERENCE };

enum class IfcBuildingElementPartTypeEnum { INSULATION, PRECASTPANEL, USERDEFINED, NOTDEFINED };

enum class IfcBuildingElementProxyTypeEnum {
  COMPLEX,
  ELEMENT,
  PARTIAL,
  PROVISIONFORVOID,
  PROVISIONFORSPACE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcBuildingSystemTypeEnum {
  FENESTRATION,
  FOUNDATION,
  LOADBEARING,
  OUTERSHELL,
  SHADING,
  TRANSPORT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcBurnerTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcCableCarrierFittingTypeEnum { BEND, CROSS, REDUCER, TEE, USERDEFINED, NOTDEFINED };

enum class IfcCableCarrierSegmentTypeEnum {
  CABLELADDERSEGMENT,
  CABLETRAYSEGMENT,
  CABLETRUNKINGSEGMENT,
  CONDUITSEGMENT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCableFittingTypeEnum {
  CONNECTOR,
  ENTRY,
  EXIT,
  JUNCTION,
  TRANSITION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCableSegmentTypeEnum {
  BUSBARSEGMENT,
  CABLESEGMENT,
  CONDUCTORSEGMENT,
  CORESEGMENT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcChangeActionEnum { NOCHANGE, MODIFIED, ADDED, DELETED, NOTDEFINED };

enum class IfcChillerTypeEnum { AIRCOOLED, WATERCOOLED, HEATRECOVERY, USERDEFINED, NOTDEFINED };

enum class IfcChimneyTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcCoilTypeEnum {
  DXCOOLINGCOIL,
  ELECTRICHEATINGCOIL,
  GASHEATINGCOIL,
  HYDRONICCOIL,
  STEAMHEATINGCOIL,
  WATERCOOLINGCOIL,
  WATERHEATINGCOIL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcColumnTypeEnum { COLUMN, PILASTER, USERDEFINED, NOTDEFINED };

enum class IfcCommunicationsApplianceTypeEnum {
  ANTENNA,
  COMPUTER,
  FAX,
  GATEWAY,
  MODEM,
  NETWORKAPPLIANCE,
  NETWORKBRIDGE,
  NETWORKHUB,
  PRINTER,
  REPEATER,
  ROUTER,
  SCANNER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcComplexPropertyTemplateTypeEnum { P_COMPLEX, Q_COMPLEX };

enum class IfcCompressorTypeEnum {
  DYNAMIC,
  RECIPROCATING,
  ROTARY,
  SCROLL,
  TROCHOIDAL,
  SINGLESTAGE,
  BOOSTER,
  OPENTYPE,
  HERMETIC,
  SEMIHERMETIC,
  WELDEDSHELLHERMETIC,
  ROLLINGPISTON,
  ROTARYVANE,
  SINGLESCREW,
  TWINSCREW,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCondenserTypeEnum {
  AIRCOOLED,
  EVAPORATIVECOOLED,
  WATERCOOLED,
  WATERCOOLEDBRAZEDPLATE,
  WATERCOOLEDSHELLCOIL,
  WATERCOOLEDSHELLTUBE,
  WATERCOOLEDTUBEINTUBE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcConnectionTypeEnum { ATPATH, ATSTART, ATEND, NOTDEFINED };

enum class IfcConstraintEnum { HARD, SOFT, ADVISORY, USERDEFINED, NOTDEFINED };

enum class IfcConstructionEquipmentResourceTypeEnum {
  DEMOLISHING,
  EARTHMOVING,
  ERECTING,
  HEATING,
  LIGHTING,
  PAVING,
  PUMPING,
  TRANSPORTING,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcConstructionMaterialResourceTypeEnum {
  AGGREGATES,
  CONCRETE,
  DRYWALL,
  FUEL,
  GYPSUM,
  MASONRY,
  METAL,
  PLASTIC,
  WOOD,
  NOTDEFINED,
  USERDEFINED
};

enum class IfcConstructionProductResourceTypeEnum { ASSEMBLY, FORMWORK, USERDEFINED, NOTDEFINED };

enum class IfcControllerTypeEnum {
  FLOATING,
  PROGRAMMABLE,
  PROPORTIONAL,
  MULTIPOSITION,
  TWOPOSITION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCooledBeamTypeEnum { ACTIVE, PASSIVE, USERDEFINED, NOTDEFINED };

enum class IfcCoolingTowerTypeEnum {
  NATURALDRAFT,
  MECHANICALINDUCEDDRAFT,
  MECHANICALFORCEDDRAFT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCostItemTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcCostScheduleTypeEnum {
  BUDGET,
  COSTPLAN,
  ESTIMATE,
  TENDER,
  PRICEDBILLOFQUANTITIES,
  UNPRICEDBILLOFQUANTITIES,
  SCHEDULEOFRATES,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCoveringTypeEnum {
  CEILING,
  FLOORING,
  CLADDING,
  ROOFING,
  MOLDING,
  SKIRTINGBOARD,
  INSULATION,
  MEMBRANE,
  SLEEVING,
  WRAPPING,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcCrewResourceTypeEnum { OFFICE, SITE, USERDEFINED, NOTDEFINED };

enum class IfcCurtainWallTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcCurveInterpolationEnum { LINEAR, LOG_LINEAR, LOG_LOG, NOTDEFINED };

enum class IfcDamperTypeEnum {
  BACKDRAFTDAMPER,
  BALANCINGDAMPER,
  BLASTDAMPER,
  CONTROLDAMPER,
  FIREDAMPER,
  FIRESMOKEDAMPER,
  FUMEHOODEXHAUST,
  GRAVITYDAMPER,
  GRAVITYRELIEFDAMPER,
  RELIEFDAMPER,
  SMOKEDAMPER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDataOriginEnum { MEASURED, PREDICTED, SIMULATED, USERDEFINED, NOTDEFINED };

enum class IfcDerivedUnitEnum {
  ANGULARVELOCITYUNIT,
  AREADENSITYUNIT,
  COMPOUNDPLANEANGLEUNIT,
  DYNAMICVISCOSITYUNIT,
  HEATFLUXDENSITYUNIT,
  INTEGERCOUNTRATEUNIT,
  ISOTHERMALMOISTURECAPACITYUNIT,
  KINEMATICVISCOSITYUNIT,
  LINEARVELOCITYUNIT,
  MASSDENSITYUNIT,
  MASSFLOWRATEUNIT,
  MOISTUREDIFFUSIVITYUNIT,
  MOLECULARWEIGHTUNIT,
  SPECIFICHEATCAPACITYUNIT,
  THERMALADMITTANCEUNIT,
  THERMALCONDUCTANCEUNIT,
  THERMALRESISTANCEUNIT,
  THERMALTRANSMITTANCEUNIT,
  VAPORPERMEABILITYUNIT,
  VOLUMETRICFLOWRATEUNIT,
  ROTATIONALFREQUENCYUNIT,
  TORQUEUNIT,
  MOMENTOFINERTIAUNIT,
  LINEARMOMENTUNIT,
  LINEARFORCEUNIT,
  PLANARFORCEUNIT,
  MODULUSOFELASTICITYUNIT,
  SHEARMODULUSUNIT,
  LINEARSTIFFNESSUNIT,
  ROTATIONALSTIFFNESSUNIT,
  MODULUSOFSUBGRADEREACTIONUNIT,
  ACCELERATIONUNIT,
  CURVATUREUNIT,
  HEATINGVALUEUNIT,
  IONCONCENTRATIONUNIT,
  LUMINOUSINTENSITYDISTRIBUTIONUNIT,
  MASSPERLENGTHUNIT,
  MODULUSOFLINEARSUBGRADEREACTIONUNIT,
  MODULUSOFROTATIONALSUBGRADEREACTIONUNIT,
  PHUNIT,
  ROTATIONALMASSUNIT,
  SECTIONAREAINTEGRALUNIT,
  SECTIONMODULUSUNIT,
  SOUNDPOWERLEVELUNIT,
  SOUNDPOWERUNIT,
  SOUNDPRESSURELEVELUNIT,
  SOUNDPRESSUREUNIT,
  TEMPERATUREGRADIENTUNIT,
  TEMPERATURERATEOFCHANGEUNIT,
  THERMALEXPANSIONCOEFFICIENTUNIT,
  WARPINGCONSTANTUNIT,
  WARPINGMOMENTUNIT,
  USERDEFINED
};

enum class IfcDirectionSenseEnum { POSITIVE, NEGATIVE };

enum class IfcDiscreteAccessoryTypeEnum { ANCHORPLATE, BRACKET, SHOE, USERDEFINED, NOTDEFINED };

enum class IfcDistributionChamberElementTypeEnum {
  FORMEDDUCT,
  INSPECTIONCHAMBER,
  INSPECTIONPIT,
  MANHOLE,
  METERCHAMBER,
  SUMP,
  TRENCH,
  VALVECHAMBER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDistributionPortTypeEnum { CABLE, CABLECARRIER, DUCT, PIPE, USERDEFINED, NOTDEFINED };

enum class IfcDistributionSystemEnum {
  AIRCONDITIONING,
  AUDIOVISUAL,
  CHEMICAL,
  CHILLEDWATER,
  COMMUNICATION,
  COMPRESSEDAIR,
  CONDENSERWATER,
  CONTROL,
  CONVEYING,
  DATA,
  DISPOSAL,
  DOMESTICCOLDWATER,
  DOMESTICHOTWATER,
  DRAINAGE,
  EARTHING,
  ELECTRICAL,
  ELECTROACOUSTIC,
  EXHAUST,
  FIREPROTECTION,
  FUEL,
  GAS,
  HAZARDOUS,
  HEATING,
  LIGHTING,
  LIGHTNINGPROTECTION,
  MUNICIPALSOLIDWASTE,
  OIL,
  OPERATIONAL,
  POWERGENERATION,
  RAINWATER,
  REFRIGERATION,
  SECURITY,
  SEWAGE,
  SIGNAL,
  STORMWATER,
  TELEPHONE,
  TV,
  VACUUM,
  VENT,
  VENTILATION,
  WASTEWATER,
  WATERSUPPLY,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDocumentConfidentialityEnum {
  PUBLIC,
  RESTRICTED,
  CONFIDENTIAL,
  PERSONAL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDocumentStatusEnum { DRAFT, FINALDRAFT, FINAL, REVISION, NOTDEFINED };

enum class IfcDoorPanelOperationEnum {
  SWINGING,
  DOUBLE_ACTING,
  SLIDING,
  FOLDING,
  REVOLVING,
  ROLLINGUP,
  FIXEDPANEL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDoorPanelPositionEnum { LEFT, MIDDLE, RIGHT, NOTDEFINED };

enum class IfcDoorStyleConstructionEnum {
  ALUMINIUM,
  HIGH_GRADE_STEEL,
  STEEL,
  WOOD,
  ALUMINIUM_WOOD,
  ALUMINIUM_PLASTIC,
  PLASTIC,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDoorStyleOperationEnum {
  SINGLE_SWING_LEFT,
  SINGLE_SWING_RIGHT,
  DOUBLE_DOOR_SINGLE_SWING,
  DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT,
  DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT,
  DOUBLE_SWING_LEFT,
  DOUBLE_SWING_RIGHT,
  DOUBLE_DOOR_DOUBLE_SWING,
  SLIDING_TO_LEFT,
  SLIDING_TO_RIGHT,
  DOUBLE_DOOR_SLIDING,
  FOLDING_TO_LEFT,
  FOLDING_TO_RIGHT,
  DOUBLE_DOOR_FOLDING,
  REVOLVING,
  ROLLINGUP,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDoorTypeEnum { DOOR, GATE, TRAPDOOR, USERDEFINED, NOTDEFINED };

enum class IfcDoorTypeOperationEnum {
  SINGLE_SWING_LEFT,
  SINGLE_SWING_RIGHT,
  DOUBLE_DOOR_SINGLE_SWING,
  DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT,
  DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT,
  DOUBLE_SWING_LEFT,
  DOUBLE_SWING_RIGHT,
  DOUBLE_DOOR_DOUBLE_SWING,
  SLIDING_TO_LEFT,
  SLIDING_TO_RIGHT,
  DOUBLE_DOOR_SLIDING,
  FOLDING_TO_LEFT,
  FOLDING_TO_RIGHT,
  DOUBLE_DOOR_FOLDING,
  REVOLVING,
  ROLLINGUP,
  SWING_FIXED_LEFT,
  SWING_FIXED_RIGHT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDuctFittingTypeEnum {
  BEND,
  CONNECTOR,
  ENTRY,
  EXIT,
  JUNCTION,
  OBSTRUCTION,
  TRANSITION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcDuctSegmentTypeEnum { RIGIDSEGMENT, FLEXIBLESEGMENT, USERDEFINED, NOTDEFINED };

enum class IfcDuctSilencerTypeEnum { FLATOVAL, RECTANGULAR, ROUND, USERDEFINED, NOTDEFINED };

enum class IfcElectricApplianceTypeEnum {
  DISHWASHER,
  ELECTRICCOOKER,
  FREESTANDINGELECTRICHEATER,
  FREESTANDINGFAN,
  FREESTANDINGWATERHEATER,
  FREESTANDINGWATERCOOLER,
  FREEZER,
  FRIDGE_FREEZER,
  HANDDRYER,
  KITCHENMACHINE,
  MICROWAVE,
  PHOTOCOPIER,
  REFRIGERATOR,
  TUMBLEDRYER,
  VENDINGMACHINE,
  WASHINGMACHINE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcElectricDistributionBoardTypeEnum {
  CONSUMERUNIT,
  DISTRIBUTIONBOARD,
  MOTORCONTROLCENTRE,
  SWITCHBOARD,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcElectricFlowStorageDeviceTypeEnum {
  BATTERY,
  CAPACITORBANK,
  HARMONICFILTER,
  INDUCTORBANK,
  UPS,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcElectricGeneratorTypeEnum {
  CHP,
  ENGINEGENERATOR,
  STANDALONE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcElectricMotorTypeEnum {
  DC,
  INDUCTION,
  POLYPHASE,
  RELUCTANCESYNCHRONOUS,
  SYNCHRONOUS,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcElectricTimeControlTypeEnum { TIMECLOCK, TIMEDELAY, RELAY, USERDEFINED, NOTDEFINED };

enum class IfcElementAssemblyTypeEnum {
  ACCESSORY_ASSEMBLY,
  ARCH,
  BEAM_GRID,
  BRACED_FRAME,
  GIRDER,
  REINFORCEMENT_UNIT,
  RIGID_FRAME,
  SLAB_FIELD,
  TRUSS,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcElementCompositionEnum { COMPLEX, ELEMENT, PARTIAL };

enum class IfcEngineTypeEnum { EXTERNALCOMBUSTION, INTERNALCOMBUSTION, USERDEFINED, NOTDEFINED };

enum class IfcEvaporativeCoolerTypeEnum {
  DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER,
  DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER,
  DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER,
  DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER,
  DIRECTEVAPORATIVEAIRWASHER,
  INDIRECTEVAPORATIVEPACKAGEAIRCOOLER,
  INDIRECTEVAPORATIVEWETCOIL,
  INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER,
  INDIRECTDIRECTCOMBINATION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcEvaporatorTypeEnum {
  DIRECTEXPANSION,
  DIRECTEXPANSIONSHELLANDTUBE,
  DIRECTEXPANSIONTUBEINTUBE,
  DIRECTEXPANSIONBRAZEDPLATE,
  FLOODEDSHELLANDTUBE,
  SHELLANDCOIL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcEventTriggerTypeEnum {
  EVENTRULE,
  EVENTMESSAGE,
  EVENTTIME,
  EVENTCOMPLEX,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcEventTypeEnum { STARTEVENT, ENDEVENT, INTERMEDIATEEVENT, USERDEFINED, NOTDEFINED };

enum class IfcExternalSpatialElementTypeEnum {
  EXTERNAL,
  EXTERNAL_EARTH,
  EXTERNAL_WATER,
  EXTERNAL_FIRE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFanTypeEnum {
  CENTRIFUGALFORWARDCURVED,
  CENTRIFUGALRADIAL,
  CENTRIFUGALBACKWARDINCLINEDCURVED,
  CENTRIFUGALAIRFOIL,
  TUBEAXIAL,
  VANEAXIAL,
  PROPELLORAXIAL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFastenerTypeEnum { GLUE, MORTAR, WELD, USERDEFINED, NOTDEFINED };

enum class IfcFilterTypeEnum {
  AIRPARTICLEFILTER,
  COMPRESSEDAIRFILTER,
  ODORFILTER,
  OILFILTER,
  STRAINER,
  WATERFILTER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFireSuppressionTerminalTypeEnum {
  BREECHINGINLET,
  FIREHYDRANT,
  HOSEREEL,
  SPRINKLER,
  SPRINKLERDEFLECTOR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFlowDirectionEnum { SOURCE, SINK, SOURCEANDSINK, NOTDEFINED };

enum class IfcFlowInstrumentTypeEnum {
  PRESSUREGAUGE,
  THERMOMETER,
  AMMETER,
  FREQUENCYMETER,
  POWERFACTORMETER,
  PHASEANGLEMETER,
  VOLTMETER_PEAK,
  VOLTMETER_RMS,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFlowMeterTypeEnum {
  ENERGYMETER,
  GASMETER,
  OILMETER,
  WATERMETER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFootingTypeEnum {
  CAISSON_FOUNDATION,
  FOOTING_BEAM,
  PAD_FOOTING,
  PILE_CAP,
  STRIP_FOOTING,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcFurnitureTypeEnum {
  CHAIR,
  TABLE,
  DESK,
  BED,
  FILECABINET,
  SHELF,
  SOFA,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcGeographicElementTypeEnum { TERRAIN, USERDEFINED, NOTDEFINED };

enum class IfcGeometricProjectionEnum {
  GRAPH_VIEW,
  SKETCH_VIEW,
  MODEL_VIEW,
  PLAN_VIEW,
  REFLECTED_PLAN_VIEW,
  SECTION_VIEW,
  ELEVATION_VIEW,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcGlobalOrLocalEnum { GLOBAL_COORDS, LOCAL_COORDS };

enum class IfcGridTypeEnum { RECTANGULAR, RADIAL, TRIANGULAR, IRREGULAR, USERDEFINED, NOTDEFINED };

enum class IfcHeatExchangerTypeEnum { PLATE, SHELLANDTUBE, USERDEFINED, NOTDEFINED };

enum class IfcHumidifierTypeEnum {
  STEAMINJECTION,
  ADIABATICAIRWASHER,
  ADIABATICPAN,
  ADIABATICWETTEDELEMENT,
  ADIABATICATOMIZING,
  ADIABATICULTRASONIC,
  ADIABATICRIGIDMEDIA,
  ADIABATICCOMPRESSEDAIRNOZZLE,
  ASSISTEDELECTRIC,
  ASSISTEDNATURALGAS,
  ASSISTEDPROPANE,
  ASSISTEDBUTANE,
  ASSISTEDSTEAM,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcInterceptorTypeEnum { CYCLONIC, GREASE, OIL, PETROL, USERDEFINED, NOTDEFINED };

enum class IfcInternalOrExternalEnum {
  INTERNAL,
  EXTERNAL,
  EXTERNAL_EARTH,
  EXTERNAL_WATER,
  EXTERNAL_FIRE,
  NOTDEFINED
};

enum class IfcInventoryTypeEnum {
  ASSETINVENTORY,
  SPACEINVENTORY,
  FURNITUREINVENTORY,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcJunctionBoxTypeEnum { DATA, POWER, USERDEFINED, NOTDEFINED };

enum class IfcKnotType { UNIFORM_KNOTS, QUASI_UNIFORM_KNOTS, PIECEWISE_BEZIER_KNOTS, UNSPECIFIED };

enum class IfcLaborResourceTypeEnum {
  ADMINISTRATION,
  CARPENTRY,
  CLEANING,
  CONCRETE,
  DRYWALL,
  ELECTRIC,
  FINISHING,
  FLOORING,
  GENERAL,
  HVAC,
  LANDSCAPING,
  MASONRY,
  PAINTING,
  PAVING,
  PLUMBING,
  ROOFING,
  SITEGRADING,
  STEELWORK,
  SURVEYING,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcLampTypeEnum {
  COMPACTFLUORESCENT,
  FLUORESCENT,
  HALOGEN,
  HIGHPRESSUREMERCURY,
  HIGHPRESSURESODIUM,
  LED,
  METALHALIDE,
  OLED,
  TUNGSTENFILAMENT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcLayerSetDirectionEnum { AXIS1, AXIS2, AXIS3 };

enum class IfcLightDistributionCurveEnum { TYPE_A, TYPE_B, TYPE_C, NOTDEFINED };

enum class IfcLightEmissionSourceEnum {
  COMPACTFLUORESCENT,
  FLUORESCENT,
  HIGHPRESSUREMERCURY,
  HIGHPRESSURESODIUM,
  LIGHTEMITTINGDIODE,
  LOWPRESSURESODIUM,
  LOWVOLTAGEHALOGEN,
  MAINVOLTAGEHALOGEN,
  METALHALIDE,
  TUNGSTENFILAMENT,
  NOTDEFINED
};

enum class IfcLightFixtureTypeEnum {
  POINTSOURCE,
  DIRECTIONSOURCE,
  SECURITYLIGHTING,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcLoadGroupTypeEnum {
  LOAD_GROUP,
  LOAD_CASE,
  LOAD_COMBINATION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcLogicalOperatorEnum {
  LOGICALAND,
  LOGICALOR,
  LOGICALXOR,
  LOGICALNOTAND,
  LOGICALNOTOR
};

enum class IfcMechanicalFastenerTypeEnum {
  ANCHORBOLT,
  BOLT,
  DOWEL,
  NAIL,
  NAILPLATE,
  RIVET,
  SCREW,
  SHEARCONNECTOR,
  STAPLE,
  STUDSHEARCONNECTOR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcMedicalDeviceTypeEnum {
  AIRSTATION,
  FEEDAIRUNIT,
  OXYGENGENERATOR,
  OXYGENPLANT,
  VACUUMSTATION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcMemberTypeEnum {
  BRACE,
  CHORD,
  COLLAR,
  MEMBER,
  MULLION,
  PLATE,
  POST,
  PURLIN,
  RAFTER,
  STRINGER,
  STRUT,
  STUD,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcMotorConnectionTypeEnum { BELTDRIVE, COUPLING, DIRECTDRIVE, USERDEFINED, NOTDEFINED };

enum class IfcNullStyle { NULL };

enum class IfcObjectTypeEnum {
  PRODUCT,
  PROCESS,
  CONTROL,
  RESOURCE,
  ACTOR,
  GROUP,
  PROJECT,
  NOTDEFINED
};

enum class IfcObjectiveEnum {
  CODECOMPLIANCE,
  CODEWAIVER,
  DESIGNINTENT,
  EXTERNAL,
  HEALTHANDSAFETY,
  MERGECONFLICT,
  MODELVIEW,
  PARAMETER,
  REQUIREMENT,
  SPECIFICATION,
  TRIGGERCONDITION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcOccupantTypeEnum {
  ASSIGNEE,
  ASSIGNOR,
  LESSEE,
  LESSOR,
  LETTINGAGENT,
  OWNER,
  TENANT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcOpeningElementTypeEnum { OPENING, RECESS, USERDEFINED, NOTDEFINED };

enum class IfcOutletTypeEnum {
  AUDIOVISUALOUTLET,
  COMMUNICATIONSOUTLET,
  POWEROUTLET,
  DATAOUTLET,
  TELEPHONEOUTLET,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcPerformanceHistoryTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcPermeableCoveringOperationEnum { GRILL, LOUVER, SCREEN, USERDEFINED, NOTDEFINED };

enum class IfcPermitTypeEnum { ACCESS, BUILDING, WORK, USERDEFINED, NOTDEFINED };

enum class IfcPhysicalOrVirtualEnum { PHYSICAL, VIRTUAL, NOTDEFINED };

enum class IfcPileConstructionEnum {
  CAST_IN_PLACE,
  COMPOSITE,
  PRECAST_CONCRETE,
  PREFAB_STEEL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcPileTypeEnum {
  BORED,
  DRIVEN,
  JETGROUTING,
  COHESION,
  FRICTION,
  SUPPORT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcPipeFittingTypeEnum {
  BEND,
  CONNECTOR,
  ENTRY,
  EXIT,
  JUNCTION,
  OBSTRUCTION,
  TRANSITION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcPipeSegmentTypeEnum {
  CULVERT,
  FLEXIBLESEGMENT,
  RIGIDSEGMENT,
  GUTTER,
  SPOOL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcPlateTypeEnum { CURTAIN_PANEL, SHEET, USERDEFINED, NOTDEFINED };

enum class IfcPreferredSurfaceCurveRepresentation { CURVE3D, PCURVE_S1, PCURVE_S2 };

enum class IfcProcedureTypeEnum {
  ADVICE_CAUTION,
  ADVICE_NOTE,
  ADVICE_WARNING,
  CALIBRATION,
  DIAGNOSTIC,
  SHUTDOWN,
  STARTUP,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcProfileTypeEnum { CURVE, AREA };

enum class IfcProjectOrderTypeEnum {
  CHANGEORDER,
  MAINTENANCEWORKORDER,
  MOVEORDER,
  PURCHASEORDER,
  WORKORDER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcProjectedOrTrueLengthEnum { PROJECTED_LENGTH, TRUE_LENGTH };

enum class IfcProjectionElementTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcPropertySetTemplateTypeEnum {
  PSET_TYPEDRIVENONLY,
  PSET_TYPEDRIVENOVERRIDE,
  PSET_OCCURRENCEDRIVEN,
  PSET_PERFORMANCEDRIVEN,
  QTO_TYPEDRIVENONLY,
  QTO_TYPEDRIVENOVERRIDE,
  QTO_OCCURRENCEDRIVEN,
  NOTDEFINED
};

enum class IfcProtectiveDeviceTrippingUnitTypeEnum {
  ELECTRONIC,
  ELECTROMAGNETIC,
  RESIDUALCURRENT,
  THERMAL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcProtectiveDeviceTypeEnum {
  CIRCUITBREAKER,
  EARTHLEAKAGECIRCUITBREAKER,
  EARTHINGSWITCH,
  FUSEDISCONNECTOR,
  RESIDUALCURRENTCIRCUITBREAKER,
  RESIDUALCURRENTSWITCH,
  VARISTOR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcPumpTypeEnum {
  CIRCULATOR,
  ENDSUCTION,
  SPLITCASE,
  SUBMERSIBLEPUMP,
  SUMPPUMP,
  VERTICALINLINE,
  VERTICALTURBINE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcRailingTypeEnum { HANDRAIL, GUARDRAIL, BALUSTRADE, USERDEFINED, NOTDEFINED };

enum class IfcRampFlightTypeEnum { STRAIGHT, SPIRAL, USERDEFINED, NOTDEFINED };

enum class IfcRampTypeEnum {
  STRAIGHT_RUN_RAMP,
  TWO_STRAIGHT_RUN_RAMP,
  QUARTER_TURN_RAMP,
  TWO_QUARTER_TURN_RAMP,
  HALF_TURN_RAMP,
  SPIRAL_RAMP,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcRecurrenceTypeEnum {
  DAILY,
  WEEKLY,
  MONTHLY_BY_DAY_OF_MONTH,
  MONTHLY_BY_POSITION,
  BY_DAY_COUNT,
  BY_WEEKDAY_COUNT,
  YEARLY_BY_DAY_OF_MONTH,
  YEARLY_BY_POSITION
};

enum class IfcReferentTypeEnum { KILOPOINT, MILEPOINT, STATION, USERDEFINED, NOTDEFINED };

enum class IfcReflectanceMethodEnum {
  BLINN,
  FLAT,
  GLASS,
  MATT,
  METAL,
  MIRROR,
  PHONG,
  PLASTIC,
  STRAUSS,
  NOTDEFINED
};

enum class IfcReinforcingBarRoleEnum {
  MAIN,
  SHEAR,
  LIGATURE,
  STUD,
  PUNCHING,
  EDGE,
  RING,
  ANCHORING,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcReinforcingBarSurfaceEnum { PLAIN, TEXTURED };

enum class IfcReinforcingBarTypeEnum {
  ANCHORING,
  EDGE,
  LIGATURE,
  MAIN,
  PUNCHING,
  RING,
  SHEAR,
  STUD,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcReinforcingMeshTypeEnum { USERDEFINED, NOTDEFINED };

enum class IfcRoleEnum {
  SUPPLIER,
  MANUFACTURER,
  CONTRACTOR,
  SUBCONTRACTOR,
  ARCHITECT,
  STRUCTURALENGINEER,
  COSTENGINEER,
  CLIENT,
  BUILDINGOWNER,
  BUILDINGOPERATOR,
  MECHANICALENGINEER,
  ELECTRICALENGINEER,
  PROJECTMANAGER,
  FACILITIESMANAGER,
  CIVILENGINEER,
  COMMISSIONINGENGINEER,
  ENGINEER,
  OWNER,
  CONSULTANT,
  CONSTRUCTIONMANAGER,
  FIELDCONSTRUCTIONMANAGER,
  RESELLER,
  USERDEFINED
};

enum class IfcRoofTypeEnum {
  FLAT_ROOF,
  SHED_ROOF,
  GABLE_ROOF,
  HIP_ROOF,
  HIPPED_GABLE_ROOF,
  GAMBREL_ROOF,
  MANSARD_ROOF,
  BARREL_ROOF,
  RAINBOW_ROOF,
  BUTTERFLY_ROOF,
  PAVILION_ROOF,
  DOME_ROOF,
  FREEFORM,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcSIPrefix {
  EXA,
  PETA,
  TERA,
  GIGA,
  MEGA,
  KILO,
  HECTO,
  DECA,
  DECI,
  CENTI,
  MILLI,
  MICRO,
  NANO,
  PICO,
  FEMTO,
  ATTO
};

enum class IfcSIUnitName {
  AMPERE,
  BECQUEREL,
  CANDELA,
  COULOMB,
  CUBIC_METRE,
  DEGREE_CELSIUS,
  FARAD,
  GRAM,
  GRAY,
  HENRY,
  HERTZ,
  JOULE,
  KELVIN,
  LUMEN,
  LUX,
  METRE,
  MOLE,
  NEWTON,
  OHM,
  PASCAL,
  RADIAN,
  SECOND,
  SIEMENS,
  SIEVERT,
  SQUARE_METRE,
  STERADIAN,
  TESLA,
  VOLT,
  WATT,
  WEBER
};

enum class IfcSanitaryTerminalTypeEnum {
  BATH,
  BIDET,
  CISTERN,
  SHOWER,
  SINK,
  SANITARYFOUNTAIN,
  TOILETPAN,
  URINAL,
  WASHHANDBASIN,
  WCSEAT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcSectionTypeEnum { UNIFORM, TAPERED };

enum class IfcSensorTypeEnum {
  COSENSOR,
  CO2SENSOR,
  CONDUCTANCESENSOR,
  CONTACTSENSOR,
  FIRESENSOR,
  FLOWSENSOR,
  FROSTSENSOR,
  GASSENSOR,
  HEATSENSOR,
  HUMIDITYSENSOR,
  IDENTIFIERSENSOR,
  IONCONCENTRATIONSENSOR,
  LEVELSENSOR,
  LIGHTSENSOR,
  MOISTURESENSOR,
  MOVEMENTSENSOR,
  PHSENSOR,
  PRESSURESENSOR,
  RADIATIONSENSOR,
  RADIOACTIVITYSENSOR,
  SMOKESENSOR,
  SOUNDSENSOR,
  TEMPERATURESENSOR,
  WINDSENSOR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcSequenceEnum {
  START_START,
  START_FINISH,
  FINISH_START,
  FINISH_FINISH,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcShadingDeviceTypeEnum { JALOUSIE, SHUTTER, AWNING, USERDEFINED, NOTDEFINED };

enum class IfcSimplePropertyTemplateTypeEnum {
  P_SINGLEVALUE,
  P_ENUMERATEDVALUE,
  P_BOUNDEDVALUE,
  P_LISTVALUE,
  P_TABLEVALUE,
  P_REFERENCEVALUE,
  Q_LENGTH,
  Q_AREA,
  Q_VOLUME,
  Q_COUNT,
  Q_WEIGHT,
  Q_TIME
};

enum class IfcSlabTypeEnum { FLOOR, ROOF, LANDING, BASESLAB, USERDEFINED, NOTDEFINED };

enum class IfcSolarDeviceTypeEnum { SOLARCOLLECTOR, SOLARPANEL, USERDEFINED, NOTDEFINED };

enum class IfcSpaceHeaterTypeEnum { CONVECTOR, RADIATOR, USERDEFINED, NOTDEFINED };

enum class IfcSpaceTypeEnum { SPACE, PARKING, GFA, INTERNAL, EXTERNAL, USERDEFINED, NOTDEFINED };

enum class IfcSpatialZoneTypeEnum {
  CONSTRUCTION,
  FIRESAFETY,
  LIGHTING,
  OCCUPANCY,
  SECURITY,
  THERMAL,
  TRANSPORT,
  VENTILATION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcStackTerminalTypeEnum { BIRDCAGE, COWL, RAINWATERHOPPER, USERDEFINED, NOTDEFINED };

enum class IfcStairFlightTypeEnum {
  STRAIGHT,
  WINDER,
  SPIRAL,
  CURVED,
  FREEFORM,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcStairTypeEnum {
  STRAIGHT_RUN_STAIR,
  TWO_STRAIGHT_RUN_STAIR,
  QUARTER_WINDING_STAIR,
  QUARTER_TURN_STAIR,
  HALF_WINDING_STAIR,
  HALF_TURN_STAIR,
  TWO_QUARTER_WINDING_STAIR,
  TWO_QUARTER_TURN_STAIR,
  THREE_QUARTER_WINDING_STAIR,
  THREE_QUARTER_TURN_STAIR,
  SPIRAL_STAIR,
  DOUBLE_RETURN_STAIR,
  CURVED_RUN_STAIR,
  TWO_CURVED_RUN_STAIR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcStateEnum { READWRITE, READONLY, LOCKED, READWRITELOCKED, READONLYLOCKED };

enum class IfcStructuralCurveActivityTypeEnum {
  CONST,
  LINEAR,
  POLYGONAL,
  EQUIDISTANT,
  SINUS,
  PARABOLA,
  DISCRETE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcStructuralCurveMemberTypeEnum {
  RIGID_JOINED_MEMBER,
  PIN_JOINED_MEMBER,
  CABLE,
  TENSION_MEMBER,
  COMPRESSION_MEMBER,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcStructuralSurfaceActivityTypeEnum {
  CONST,
  BILINEAR,
  DISCRETE,
  ISOCONTOUR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcStructuralSurfaceMemberTypeEnum {
  BENDING_ELEMENT,
  MEMBRANE_ELEMENT,
  SHELL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcSubContractResourceTypeEnum { PURCHASE, WORK, USERDEFINED, NOTDEFINED };

enum class IfcSurfaceFeatureTypeEnum { MARK, TAG, TREATMENT, USERDEFINED, NOTDEFINED };

enum class IfcSurfaceSide { POSITIVE, NEGATIVE, BOTH };

enum class IfcSwitchingDeviceTypeEnum {
  CONTACTOR,
  DIMMERSWITCH,
  EMERGENCYSTOP,
  KEYPAD,
  MOMENTARYSWITCH,
  SELECTORSWITCH,
  STARTER,
  SWITCHDISCONNECTOR,
  TOGGLESWITCH,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcSystemFurnitureElementTypeEnum { PANEL, WORKSURFACE, USERDEFINED, NOTDEFINED };

enum class IfcTankTypeEnum {
  BASIN,
  BREAKPRESSURE,
  EXPANSION,
  FEEDANDEXPANSION,
  PRESSUREVESSEL,
  STORAGE,
  VESSEL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcTaskDurationEnum { ELAPSEDTIME, WORKTIME, NOTDEFINED };

enum class IfcTaskTypeEnum {
  ATTENDANCE,
  CONSTRUCTION,
  DEMOLITION,
  DISMANTLE,
  DISPOSAL,
  INSTALLATION,
  LOGISTIC,
  MAINTENANCE,
  MOVE,
  OPERATION,
  REMOVAL,
  RENOVATION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcTendonAnchorTypeEnum { COUPLER, FIXED_END, TENSIONING_END, USERDEFINED, NOTDEFINED };

enum class IfcTendonTypeEnum { BAR, COATED, STRAND, WIRE, USERDEFINED, NOTDEFINED };

enum class IfcTextPath { LEFT, RIGHT, UP, DOWN };

enum class IfcTimeSeriesDataTypeEnum {
  CONTINUOUS,
  DISCRETE,
  DISCRETEBINARY,
  PIECEWISEBINARY,
  PIECEWISECONSTANT,
  PIECEWISECONTINUOUS,
  NOTDEFINED
};

enum class IfcTransformerTypeEnum {
  CURRENT,
  FREQUENCY,
  INVERTER,
  RECTIFIER,
  VOLTAGE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcTransitionCode {
  DISCONTINUOUS,
  CONTINUOUS,
  CONTSAMEGRADIENT,
  CONTSAMEGRADIENTSAMECURVATURE
};

enum class IfcTransitionCurveType {
  BIQUADRATICPARABOLA,
  BLOSSCURVE,
  CLOTHOIDCURVE,
  COSINECURVE,
  CUBICPARABOLA,
  SINECURVE
};

enum class IfcTransportElementTypeEnum {
  ELEVATOR,
  ESCALATOR,
  MOVINGWALKWAY,
  CRANEWAY,
  LIFTINGGEAR,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcTrimmingPreference { CARTESIAN, PARAMETER, UNSPECIFIED };

enum class IfcTubeBundleTypeEnum { FINNED, USERDEFINED, NOTDEFINED };

enum class IfcUnitEnum {
  ABSORBEDDOSEUNIT,
  AMOUNTOFSUBSTANCEUNIT,
  AREAUNIT,
  DOSEEQUIVALENTUNIT,
  ELECTRICCAPACITANCEUNIT,
  ELECTRICCHARGEUNIT,
  ELECTRICCONDUCTANCEUNIT,
  ELECTRICCURRENTUNIT,
  ELECTRICRESISTANCEUNIT,
  ELECTRICVOLTAGEUNIT,
  ENERGYUNIT,
  FORCEUNIT,
  FREQUENCYUNIT,
  ILLUMINANCEUNIT,
  INDUCTANCEUNIT,
  LENGTHUNIT,
  LUMINOUSFLUXUNIT,
  LUMINOUSINTENSITYUNIT,
  MAGNETICFLUXDENSITYUNIT,
  MAGNETICFLUXUNIT,
  MASSUNIT,
  PLANEANGLEUNIT,
  POWERUNIT,
  PRESSUREUNIT,
  RADIOACTIVITYUNIT,
  SOLIDANGLEUNIT,
  THERMODYNAMICTEMPERATUREUNIT,
  TIMEUNIT,
  VOLUMEUNIT,
  USERDEFINED
};

enum class IfcUnitaryControlElementTypeEnum {
  ALARMPANEL,
  CONTROLPANEL,
  GASDETECTIONPANEL,
  INDICATORPANEL,
  MIMICPANEL,
  HUMIDISTAT,
  THERMOSTAT,
  WEATHERSTATION,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcUnitaryEquipmentTypeEnum {
  AIRHANDLER,
  AIRCONDITIONINGUNIT,
  DEHUMIDIFIER,
  SPLITSYSTEM,
  ROOFTOPUNIT,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcValveTypeEnum {
  AIRRELEASE,
  ANTIVACUUM,
  CHANGEOVER,
  CHECK,
  COMMISSIONING,
  DIVERTING,
  DRAWOFFCOCK,
  DOUBLECHECK,
  DOUBLEREGULATING,
  FAUCET,
  FLUSHING,
  GASCOCK,
  GASTAP,
  ISOLATING,
  MIXING,
  PRESSUREREDUCING,
  PRESSURERELIEF,
  REGULATING,
  SAFETYCUTOFF,
  STEAMTRAP,
  STOPCOCK,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcVibrationIsolatorTypeEnum { COMPRESSION, SPRING, USERDEFINED, NOTDEFINED };

enum class IfcVoidingFeatureTypeEnum {
  CUTOUT,
  NOTCH,
  HOLE,
  MITER,
  CHAMFER,
  EDGE,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcWallTypeEnum {
  MOVABLE,
  PARAPET,
  PARTITIONING,
  PLUMBINGWALL,
  SHEAR,
  SOLIDWALL,
  STANDARD,
  POLYGONAL,
  ELEMENTEDWALL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcWasteTerminalTypeEnum {
  FLOORTRAP,
  FLOORWASTE,
  GULLYSUMP,
  GULLYTRAP,
  ROOFDRAIN,
  WASTEDISPOSALUNIT,
  WASTETRAP,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcWindowPanelOperationEnum {
  SIDEHUNGRIGHTHAND,
  SIDEHUNGLEFTHAND,
  TILTANDTURNRIGHTHAND,
  TILTANDTURNLEFTHAND,
  TOPHUNG,
  BOTTOMHUNG,
  PIVOTHORIZONTAL,
  PIVOTVERTICAL,
  SLIDINGHORIZONTAL,
  SLIDINGVERTICAL,
  REMOVABLECASEMENT,
  FIXEDCASEMENT,
  OTHEROPERATION,
  NOTDEFINED
};

enum class IfcWindowPanelPositionEnum { LEFT, MIDDLE, RIGHT, BOTTOM, TOP, NOTDEFINED };

enum class IfcWindowStyleConstructionEnum {
  ALUMINIUM,
  HIGH_GRADE_STEEL,
  STEEL,
  WOOD,
  ALUMINIUM_WOOD,
  PLASTIC,
  OTHER_CONSTRUCTION,
  NOTDEFINED
};

enum class IfcWindowStyleOperationEnum {
  SINGLE_PANEL,
  DOUBLE_PANEL_VERTICAL,
  DOUBLE_PANEL_HORIZONTAL,
  TRIPLE_PANEL_VERTICAL,
  TRIPLE_PANEL_BOTTOM,
  TRIPLE_PANEL_TOP,
  TRIPLE_PANEL_LEFT,
  TRIPLE_PANEL_RIGHT,
  TRIPLE_PANEL_HORIZONTAL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcWindowTypeEnum { WINDOW, SKYLIGHT, LIGHTDOME, USERDEFINED, NOTDEFINED };

enum class IfcWindowTypePartitioningEnum {
  SINGLE_PANEL,
  DOUBLE_PANEL_VERTICAL,
  DOUBLE_PANEL_HORIZONTAL,
  TRIPLE_PANEL_VERTICAL,
  TRIPLE_PANEL_BOTTOM,
  TRIPLE_PANEL_TOP,
  TRIPLE_PANEL_LEFT,
  TRIPLE_PANEL_RIGHT,
  TRIPLE_PANEL_HORIZONTAL,
  USERDEFINED,
  NOTDEFINED
};

enum class IfcWorkCalendarTypeEnum { FIRSTSHIFT, SECONDSHIFT, THIRDSHIFT, USERDEFINED, NOTDEFINED };

enum class IfcWorkPlanTypeEnum { ACTUAL, BASELINE, PLANNED, USERDEFINED, NOTDEFINED };

enum class IfcWorkScheduleTypeEnum { ACTUAL, BASELINE, PLANNED, USERDEFINED, NOTDEFINED };

using IfcActorSelect = std::variant<IfcOrganization, IfcPerson, IfcPersonAndOrganization>;

using IfcAppliedValueSelect = std::variant<IfcMeasureWithUnit, IfcReference, IfcValue>;

using IfcAxis2Placement = std::variant<IfcAxis2Placement2D, IfcAxis2Placement3D>;

using IfcBendingParameterSelect = std::variant<IfcLengthMeasure, IfcPlaneAngleMeasure>;

using IfcBooleanOperand = std::variant<IfcBooleanResult, IfcCsgPrimitive3D, IfcHalfSpaceSolid,
                                       IfcSolidModel, IfcTessellatedFaceSet>;

using IfcClassificationReferenceSelect =
    std::variant<IfcClassification, IfcClassificationReference>;

using IfcClassificationSelect = std::variant<IfcClassification, IfcClassificationReference>;

using IfcColour = std::variant<IfcColourSpecification, IfcPreDefinedColour>;

using IfcColourOrFactor = std::variant<IfcColourRgb, IfcNormalisedRatioMeasure>;

using IfcCoordinateReferenceSystemSelect =
    std::variant<IfcCoordinateReferenceSystem, IfcGeometricRepresentationContext>;

using IfcCsgSelect = std::variant<IfcBooleanResult, IfcCsgPrimitive3D>;

using IfcCurveFontOrScaledCurveFontSelect =
    std::variant<IfcCurveStyleFontAndScaling, IfcCurveStyleFontSelect>;

using IfcCurveOnSurface = std::variant<IfcCompositeCurveOnSurface, IfcPcurve, IfcSurfaceCurve>;

using IfcCurveOrEdgeCurve = std::variant<IfcBoundedCurve, IfcEdgeCurve>;

using IfcCurveStyleFontSelect = std::variant<IfcCurveStyleFont, IfcPreDefinedCurveFont>;

using IfcDefinitionSelect = std::variant<IfcObjectDefinition, IfcPropertyDefinition>;

using IfcDerivedMeasureValue = std::variant<
    IfcAbsorbedDoseMeasure, IfcAccelerationMeasure, IfcAngularVelocityMeasure,
    IfcAreaDensityMeasure, IfcCompoundPlaneAngleMeasure, IfcCurvatureMeasure,
    IfcDoseEquivalentMeasure, IfcDynamicViscosityMeasure, IfcElectricCapacitanceMeasure,
    IfcElectricChargeMeasure, IfcElectricConductanceMeasure, IfcElectricResistanceMeasure,
    IfcElectricVoltageMeasure, IfcEnergyMeasure, IfcForceMeasure, IfcFrequencyMeasure,
    IfcHeatFluxDensityMeasure, IfcHeatingValueMeasure, IfcIlluminanceMeasure, IfcInductanceMeasure,
    IfcIntegerCountRateMeasure, IfcIonConcentrationMeasure, IfcIsothermalMoistureCapacityMeasure,
    IfcKinematicViscosityMeasure, IfcLinearForceMeasure, IfcLinearMomentMeasure,
    IfcLinearStiffnessMeasure, IfcLinearVelocityMeasure, IfcLuminousFluxMeasure,
    IfcLuminousIntensityDistributionMeasure, IfcMagneticFluxDensityMeasure, IfcMagneticFluxMeasure,
    IfcMassDensityMeasure, IfcMassFlowRateMeasure, IfcMassPerLengthMeasure,
    IfcModulusOfElasticityMeasure, IfcModulusOfLinearSubgradeReactionMeasure,
    IfcModulusOfRotationalSubgradeReactionMeasure, IfcModulusOfSubgradeReactionMeasure,
    IfcMoistureDiffusivityMeasure, IfcMolecularWeightMeasure, IfcMomentOfInertiaMeasure,
    IfcMonetaryMeasure, IfcPHMeasure, IfcPlanarForceMeasure, IfcPowerMeasure, IfcPressureMeasure,
    IfcRadioActivityMeasure, IfcRotationalFrequencyMeasure, IfcRotationalMassMeasure,
    IfcRotationalStiffnessMeasure, IfcSectionModulusMeasure, IfcSectionalAreaIntegralMeasure,
    IfcShearModulusMeasure, IfcSoundPowerLevelMeasure, IfcSoundPowerMeasure,
    IfcSoundPressureLevelMeasure, IfcSoundPressureMeasure, IfcSpecificHeatCapacityMeasure,
    IfcTemperatureGradientMeasure, IfcTemperatureRateOfChangeMeasure, IfcThermalAdmittanceMeasure,
    IfcThermalConductivityMeasure, IfcThermalExpansionCoefficientMeasure,
    IfcThermalResistanceMeasure, IfcThermalTransmittanceMeasure, IfcTorqueMeasure,
    IfcVaporPermeabilityMeasure, IfcVolumetricFlowRateMeasure, IfcWarpingConstantMeasure,
    IfcWarpingMomentMeasure>;

using IfcDocumentSelect = std::variant<IfcDocumentInformation, IfcDocumentReference>;

using IfcFillStyleSelect = std::variant<IfcColour, IfcExternallyDefinedHatchStyle,
                                        IfcFillAreaStyleHatching, IfcFillAreaStyleTiles>;

using IfcGeometricSetSelect = std::variant<IfcCurve, IfcPoint, IfcSurface>;

using IfcGridPlacementDirectionSelect = std::variant<IfcDirection, IfcVirtualGridIntersection>;

using IfcHatchLineDistanceSelect = std::variant<IfcPositiveLengthMeasure, IfcVector>;

using IfcLayeredItem = std::variant<IfcRepresentation, IfcRepresentationItem>;

using IfcLibrarySelect = std::variant<IfcLibraryInformation, IfcLibraryReference>;

using IfcLightDistributionDataSourceSelect =
    std::variant<IfcExternalReference, IfcLightIntensityDistribution>;

using IfcMaterialSelect =
    std::variant<IfcMaterialDefinition, IfcMaterialList, IfcMaterialUsageDefinition>;

using IfcMeasureValue =
    std::variant<IfcAmountOfSubstanceMeasure, IfcAreaMeasure, IfcComplexNumber,
                 IfcContextDependentMeasure, IfcCountMeasure, IfcDescriptiveMeasure,
                 IfcElectricCurrentMeasure, IfcLengthMeasure, IfcLuminousIntensityMeasure,
                 IfcMassMeasure, IfcNonNegativeLengthMeasure, IfcNormalisedRatioMeasure,
                 IfcNumericMeasure, IfcParameterValue, IfcPlaneAngleMeasure,
                 IfcPositiveLengthMeasure, IfcPositivePlaneAngleMeasure, IfcPositiveRatioMeasure,
                 IfcRatioMeasure, IfcSolidAngleMeasure, IfcThermodynamicTemperatureMeasure,
                 IfcTimeMeasure, IfcVolumeMeasure>;

using IfcMetricValueSelect = std::variant<IfcAppliedValue, IfcMeasureWithUnit, IfcReference,
                                          IfcTable, IfcTimeSeries, IfcValue>;

using IfcModulusOfRotationalSubgradeReactionSelect =
    std::variant<IfcBoolean, IfcModulusOfRotationalSubgradeReactionMeasure>;

using IfcModulusOfSubgradeReactionSelect =
    std::variant<IfcBoolean, IfcModulusOfSubgradeReactionMeasure>;

using IfcModulusOfTranslationalSubgradeReactionSelect =
    std::variant<IfcBoolean, IfcModulusOfLinearSubgradeReactionMeasure>;

using IfcObjectReferenceSelect =
    std::variant<IfcAddress, IfcAppliedValue, IfcExternalReference, IfcMaterialDefinition,
                 IfcOrganization, IfcPerson, IfcPersonAndOrganization, IfcTable, IfcTimeSeries>;

using IfcPointOrVertexPoint = std::variant<IfcPoint, IfcVertexPoint>;

using IfcPresentationStyleSelect =
    std::variant<IfcCurveStyle, IfcFillAreaStyle, IfcNullStyle, IfcSurfaceStyle, IfcTextStyle>;

using IfcProcessSelect = std::variant<IfcProcess, IfcTypeProcess>;

using IfcProductRepresentationSelect =
    std::variant<IfcProductDefinitionShape, IfcRepresentationMap>;

using IfcProductSelect = std::variant<IfcProduct, IfcTypeProduct>;

using IfcPropertySetDefinitionSelect =
    std::variant<IfcPropertySetDefinition, IfcPropertySetDefinitionSet>;

using IfcResourceObjectSelect =
    std::variant<IfcActorRole, IfcAppliedValue, IfcApproval, IfcConstraint, IfcContextDependentUnit,
                 IfcConversionBasedUnit, IfcExternalInformation, IfcExternalReference,
                 IfcMaterialDefinition, IfcOrganization, IfcPerson, IfcPersonAndOrganization,
                 IfcPhysicalQuantity, IfcProfileDef, IfcPropertyAbstraction, IfcShapeAspect,
                 IfcTimeSeries>;

using IfcResourceSelect = std::variant<IfcResource, IfcTypeResource>;

using IfcRotationalStiffnessSelect = std::variant<IfcBoolean, IfcRotationalStiffnessMeasure>;

using IfcSegmentIndexSelect = std::variant<IfcArcIndex, IfcLineIndex>;

using IfcShell = std::variant<IfcClosedShell, IfcOpenShell>;

using IfcSimpleValue = std::variant<IfcBinary, IfcBoolean, IfcDate, IfcDateTime, IfcDuration,
                                    IfcIdentifier, IfcInteger, IfcLabel, IfcLogical,
                                    IfcPositiveInteger, IfcReal, IfcText, IfcTime, IfcTimeStamp>;

using IfcSizeSelect =
    std::variant<IfcDescriptiveMeasure, IfcLengthMeasure, IfcNormalisedRatioMeasure,
                 IfcPositiveLengthMeasure, IfcPositiveRatioMeasure, IfcRatioMeasure>;

using IfcSolidOrShell = std::variant<IfcClosedShell, IfcSolidModel>;

using IfcSpaceBoundarySelect = std::variant<IfcExternalSpatialElement, IfcSpace>;

using IfcSpecularHighlightSelect = std::variant<IfcSpecularExponent, IfcSpecularRoughness>;

using IfcStructuralActivityAssignmentSelect = std::variant<IfcElement, IfcStructuralItem>;

using IfcStyleAssignmentSelect = std::variant<IfcPresentationStyle, IfcPresentationStyleAssignment>;

using IfcSurfaceOrFaceSurface = std::variant<IfcFaceBasedSurfaceModel, IfcFaceSurface, IfcSurface>;

using IfcSurfaceStyleElementSelect =
    std::variant<IfcExternallyDefinedSurfaceStyle, IfcSurfaceStyleLighting,
                 IfcSurfaceStyleRefraction, IfcSurfaceStyleShading, IfcSurfaceStyleWithTextures>;

using IfcTextFontSelect = std::variant<IfcExternallyDefinedTextFont, IfcPreDefinedTextFont>;

using IfcTimeOrRatioSelect = std::variant<IfcDuration, IfcRatioMeasure>;

using IfcTranslationalStiffnessSelect = std::variant<IfcBoolean, IfcLinearStiffnessMeasure>;

using IfcTrimmingSelect = std::variant<IfcCartesianPoint, IfcParameterValue>;

using IfcUnit = std::variant<IfcDerivedUnit, IfcMonetaryUnit, IfcNamedUnit>;

using IfcValue = std::variant<IfcDerivedMeasureValue, IfcMeasureValue, IfcSimpleValue>;

using IfcVectorOrDirection = std::variant<IfcDirection, IfcVector>;

using IfcWarpingStiffnessSelect = std::variant<IfcBoolean, IfcWarpingMomentMeasure>;

} // namespace ifc

#endif // IMPORT_IFC_EXTERNAL_TYPES_H_
