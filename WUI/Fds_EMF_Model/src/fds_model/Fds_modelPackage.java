/**
 */
package fds_model;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

/**
 * <!-- begin-user-doc -->
 * The <b>Package</b> for the model.
 * It contains accessors for the meta objects to represent
 * <ul>
 *   <li>each class,</li>
 *   <li>each feature of each class,</li>
 *   <li>each operation of each class,</li>
 *   <li>each enum,</li>
 *   <li>and each data type</li>
 * </ul>
 * <!-- end-user-doc -->
 * @see fds_model.Fds_modelFactory
 * @model kind="package"
 * @generated
 */
public interface Fds_modelPackage extends EPackage {
    /**
     * The package name.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    String eNAME = "fds_model";

    /**
     * The package namespace URI.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    String eNS_URI = "http://com/incomplete/cubegs/fds_model";

    /**
     * The package namespace name.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    String eNS_PREFIX = "com.incomplete.cubegs.fds_model";

    /**
     * The singleton instance of the package.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    Fds_modelPackage eINSTANCE = fds_model.impl.Fds_modelPackageImpl.init();

    /**
     * The meta object id for the '{@link fds_model.impl.MissionImpl <em>Mission</em>}' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see fds_model.impl.MissionImpl
     * @see fds_model.impl.Fds_modelPackageImpl#getMission()
     * @generated
     */
    int MISSION = 0;

    /**
     * The feature id for the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__IDENTIFIER = 0;

    /**
     * The feature id for the '<em><b>Name</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__NAME = 1;

    /**
     * The feature id for the '<em><b>Description</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__DESCRIPTION = 2;

    /**
     * The feature id for the '<em><b>Country</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__COUNTRY = 3;

    /**
     * The feature id for the '<em><b>Owner</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__OWNER = 4;

    /**
     * The feature id for the '<em><b>Creation Date</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__CREATION_DATE = 5;

    /**
     * The feature id for the '<em><b>Phone Number</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__PHONE_NUMBER = 6;

    /**
     * The feature id for the '<em><b>Email</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__EMAIL = 7;

    /**
     * The feature id for the '<em><b>List Satellite</b></em>' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION__LIST_SATELLITE = 8;

    /**
     * The number of structural features of the '<em>Mission</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION_FEATURE_COUNT = 9;

    /**
     * The number of operations of the '<em>Mission</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MISSION_OPERATION_COUNT = 0;

    /**
     * The meta object id for the '{@link fds_model.impl.SatelliteImpl <em>Satellite</em>}' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see fds_model.impl.SatelliteImpl
     * @see fds_model.impl.Fds_modelPackageImpl#getSatellite()
     * @generated
     */
    int SATELLITE = 1;

    /**
     * The feature id for the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__IDENTIFIER = 0;

    /**
     * The feature id for the '<em><b>Name</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__NAME = 1;

    /**
     * The feature id for the '<em><b>Description</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__DESCRIPTION = 2;

    /**
     * The feature id for the '<em><b>Code</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__CODE = 3;

    /**
     * The feature id for the '<em><b>Launch Date</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__LAUNCH_DATE = 4;

    /**
     * The feature id for the '<em><b>Admin</b></em>' containment reference.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__ADMIN = 5;

    /**
     * The feature id for the '<em><b>List Subsystem</b></em>' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE__LIST_SUBSYSTEM = 6;

    /**
     * The number of structural features of the '<em>Satellite</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE_FEATURE_COUNT = 7;

    /**
     * The number of operations of the '<em>Satellite</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SATELLITE_OPERATION_COUNT = 0;

    /**
     * The meta object id for the '{@link fds_model.impl.SubsystemImpl <em>Subsystem</em>}' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see fds_model.impl.SubsystemImpl
     * @see fds_model.impl.Fds_modelPackageImpl#getSubsystem()
     * @generated
     */
    int SUBSYSTEM = 2;

    /**
     * The feature id for the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SUBSYSTEM__IDENTIFIER = 0;

    /**
     * The feature id for the '<em><b>Name</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SUBSYSTEM__NAME = 1;

    /**
     * The feature id for the '<em><b>Description</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SUBSYSTEM__DESCRIPTION = 2;

    /**
     * The number of structural features of the '<em>Subsystem</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SUBSYSTEM_FEATURE_COUNT = 3;

    /**
     * The number of operations of the '<em>Subsystem</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int SUBSYSTEM_OPERATION_COUNT = 0;

    /**
     * The meta object id for the '{@link fds_model.impl.GroundStationImpl <em>Ground Station</em>}' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see fds_model.impl.GroundStationImpl
     * @see fds_model.impl.Fds_modelPackageImpl#getGroundStation()
     * @generated
     */
    int GROUND_STATION = 3;

    /**
     * The feature id for the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__IDENTIFIER = 0;

    /**
     * The feature id for the '<em><b>Name</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__NAME = 1;

    /**
     * The feature id for the '<em><b>Description</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__DESCRIPTION = 2;

    /**
     * The feature id for the '<em><b>Latitude</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__LATITUDE = 3;

    /**
     * The feature id for the '<em><b>Longitude</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__LONGITUDE = 4;

    /**
     * The feature id for the '<em><b>Altitude</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__ALTITUDE = 5;

    /**
     * The feature id for the '<em><b>Minimum Elevation</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__MINIMUM_ELEVATION = 6;

    /**
     * The feature id for the '<em><b>List Mask</b></em>' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION__LIST_MASK = 7;

    /**
     * The number of structural features of the '<em>Ground Station</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_FEATURE_COUNT = 8;

    /**
     * The number of operations of the '<em>Ground Station</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_OPERATION_COUNT = 0;

    /**
     * The meta object id for the '{@link fds_model.impl.GroundStationMaskImpl <em>Ground Station Mask</em>}' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see fds_model.impl.GroundStationMaskImpl
     * @see fds_model.impl.Fds_modelPackageImpl#getGroundStationMask()
     * @generated
     */
    int GROUND_STATION_MASK = 4;

    /**
     * The feature id for the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_MASK__IDENTIFIER = 0;

    /**
     * The feature id for the '<em><b>Name</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_MASK__NAME = 1;

    /**
     * The feature id for the '<em><b>List Point</b></em>' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_MASK__LIST_POINT = 2;

    /**
     * The number of structural features of the '<em>Ground Station Mask</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_MASK_FEATURE_COUNT = 3;

    /**
     * The number of operations of the '<em>Ground Station Mask</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int GROUND_STATION_MASK_OPERATION_COUNT = 0;

    /**
     * The meta object id for the '{@link fds_model.impl.MaskPointImpl <em>Mask Point</em>}' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see fds_model.impl.MaskPointImpl
     * @see fds_model.impl.Fds_modelPackageImpl#getMaskPoint()
     * @generated
     */
    int MASK_POINT = 5;

    /**
     * The feature id for the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MASK_POINT__IDENTIFIER = 0;

    /**
     * The feature id for the '<em><b>Azimuth</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MASK_POINT__AZIMUTH = 1;

    /**
     * The feature id for the '<em><b>Elevation</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MASK_POINT__ELEVATION = 2;

    /**
     * The number of structural features of the '<em>Mask Point</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MASK_POINT_FEATURE_COUNT = 3;

    /**
     * The number of operations of the '<em>Mask Point</em>' class.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     * @ordered
     */
    int MASK_POINT_OPERATION_COUNT = 0;


    /**
     * Returns the meta object for class '{@link fds_model.Mission <em>Mission</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for class '<em>Mission</em>'.
     * @see fds_model.Mission
     * @generated
     */
    EClass getMission();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getIdentifier <em>Identifier</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Identifier</em>'.
     * @see fds_model.Mission#getIdentifier()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_Identifier();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getName <em>Name</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Name</em>'.
     * @see fds_model.Mission#getName()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_Name();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getDescription <em>Description</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Description</em>'.
     * @see fds_model.Mission#getDescription()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_Description();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getCountry <em>Country</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Country</em>'.
     * @see fds_model.Mission#getCountry()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_Country();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getOwner <em>Owner</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Owner</em>'.
     * @see fds_model.Mission#getOwner()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_Owner();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getCreationDate <em>Creation Date</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Creation Date</em>'.
     * @see fds_model.Mission#getCreationDate()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_CreationDate();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getPhoneNumber <em>Phone Number</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Phone Number</em>'.
     * @see fds_model.Mission#getPhoneNumber()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_PhoneNumber();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Mission#getEmail <em>Email</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Email</em>'.
     * @see fds_model.Mission#getEmail()
     * @see #getMission()
     * @generated
     */
    EAttribute getMission_Email();

    /**
     * Returns the meta object for the containment reference list '{@link fds_model.Mission#getListSatellite <em>List Satellite</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the containment reference list '<em>List Satellite</em>'.
     * @see fds_model.Mission#getListSatellite()
     * @see #getMission()
     * @generated
     */
    EReference getMission_ListSatellite();

    /**
     * Returns the meta object for class '{@link fds_model.Satellite <em>Satellite</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for class '<em>Satellite</em>'.
     * @see fds_model.Satellite
     * @generated
     */
    EClass getSatellite();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Satellite#getIdentifier <em>Identifier</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Identifier</em>'.
     * @see fds_model.Satellite#getIdentifier()
     * @see #getSatellite()
     * @generated
     */
    EAttribute getSatellite_Identifier();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Satellite#getName <em>Name</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Name</em>'.
     * @see fds_model.Satellite#getName()
     * @see #getSatellite()
     * @generated
     */
    EAttribute getSatellite_Name();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Satellite#getDescription <em>Description</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Description</em>'.
     * @see fds_model.Satellite#getDescription()
     * @see #getSatellite()
     * @generated
     */
    EAttribute getSatellite_Description();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Satellite#getCode <em>Code</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Code</em>'.
     * @see fds_model.Satellite#getCode()
     * @see #getSatellite()
     * @generated
     */
    EAttribute getSatellite_Code();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Satellite#getLaunchDate <em>Launch Date</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Launch Date</em>'.
     * @see fds_model.Satellite#getLaunchDate()
     * @see #getSatellite()
     * @generated
     */
    EAttribute getSatellite_LaunchDate();

    /**
     * Returns the meta object for the containment reference '{@link fds_model.Satellite#getAdmin <em>Admin</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the containment reference '<em>Admin</em>'.
     * @see fds_model.Satellite#getAdmin()
     * @see #getSatellite()
     * @generated
     */
    EReference getSatellite_Admin();

    /**
     * Returns the meta object for the containment reference list '{@link fds_model.Satellite#getListSubsystem <em>List Subsystem</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the containment reference list '<em>List Subsystem</em>'.
     * @see fds_model.Satellite#getListSubsystem()
     * @see #getSatellite()
     * @generated
     */
    EReference getSatellite_ListSubsystem();

    /**
     * Returns the meta object for class '{@link fds_model.Subsystem <em>Subsystem</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for class '<em>Subsystem</em>'.
     * @see fds_model.Subsystem
     * @generated
     */
    EClass getSubsystem();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Subsystem#getIdentifier <em>Identifier</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Identifier</em>'.
     * @see fds_model.Subsystem#getIdentifier()
     * @see #getSubsystem()
     * @generated
     */
    EAttribute getSubsystem_Identifier();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Subsystem#getName <em>Name</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Name</em>'.
     * @see fds_model.Subsystem#getName()
     * @see #getSubsystem()
     * @generated
     */
    EAttribute getSubsystem_Name();

    /**
     * Returns the meta object for the attribute '{@link fds_model.Subsystem#getDescription <em>Description</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Description</em>'.
     * @see fds_model.Subsystem#getDescription()
     * @see #getSubsystem()
     * @generated
     */
    EAttribute getSubsystem_Description();

    /**
     * Returns the meta object for class '{@link fds_model.GroundStation <em>Ground Station</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for class '<em>Ground Station</em>'.
     * @see fds_model.GroundStation
     * @generated
     */
    EClass getGroundStation();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getIdentifier <em>Identifier</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Identifier</em>'.
     * @see fds_model.GroundStation#getIdentifier()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_Identifier();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getName <em>Name</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Name</em>'.
     * @see fds_model.GroundStation#getName()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_Name();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getDescription <em>Description</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Description</em>'.
     * @see fds_model.GroundStation#getDescription()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_Description();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getLatitude <em>Latitude</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Latitude</em>'.
     * @see fds_model.GroundStation#getLatitude()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_Latitude();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getLongitude <em>Longitude</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Longitude</em>'.
     * @see fds_model.GroundStation#getLongitude()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_Longitude();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getAltitude <em>Altitude</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Altitude</em>'.
     * @see fds_model.GroundStation#getAltitude()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_Altitude();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStation#getMinimumElevation <em>Minimum Elevation</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Minimum Elevation</em>'.
     * @see fds_model.GroundStation#getMinimumElevation()
     * @see #getGroundStation()
     * @generated
     */
    EAttribute getGroundStation_MinimumElevation();

    /**
     * Returns the meta object for the containment reference list '{@link fds_model.GroundStation#getListMask <em>List Mask</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the containment reference list '<em>List Mask</em>'.
     * @see fds_model.GroundStation#getListMask()
     * @see #getGroundStation()
     * @generated
     */
    EReference getGroundStation_ListMask();

    /**
     * Returns the meta object for class '{@link fds_model.GroundStationMask <em>Ground Station Mask</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for class '<em>Ground Station Mask</em>'.
     * @see fds_model.GroundStationMask
     * @generated
     */
    EClass getGroundStationMask();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStationMask#getIdentifier <em>Identifier</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Identifier</em>'.
     * @see fds_model.GroundStationMask#getIdentifier()
     * @see #getGroundStationMask()
     * @generated
     */
    EAttribute getGroundStationMask_Identifier();

    /**
     * Returns the meta object for the attribute '{@link fds_model.GroundStationMask#getName <em>Name</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Name</em>'.
     * @see fds_model.GroundStationMask#getName()
     * @see #getGroundStationMask()
     * @generated
     */
    EAttribute getGroundStationMask_Name();

    /**
     * Returns the meta object for the containment reference list '{@link fds_model.GroundStationMask#getListPoint <em>List Point</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the containment reference list '<em>List Point</em>'.
     * @see fds_model.GroundStationMask#getListPoint()
     * @see #getGroundStationMask()
     * @generated
     */
    EReference getGroundStationMask_ListPoint();

    /**
     * Returns the meta object for class '{@link fds_model.MaskPoint <em>Mask Point</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for class '<em>Mask Point</em>'.
     * @see fds_model.MaskPoint
     * @generated
     */
    EClass getMaskPoint();

    /**
     * Returns the meta object for the attribute '{@link fds_model.MaskPoint#getIdentifier <em>Identifier</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Identifier</em>'.
     * @see fds_model.MaskPoint#getIdentifier()
     * @see #getMaskPoint()
     * @generated
     */
    EAttribute getMaskPoint_Identifier();

    /**
     * Returns the meta object for the attribute '{@link fds_model.MaskPoint#getAzimuth <em>Azimuth</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Azimuth</em>'.
     * @see fds_model.MaskPoint#getAzimuth()
     * @see #getMaskPoint()
     * @generated
     */
    EAttribute getMaskPoint_Azimuth();

    /**
     * Returns the meta object for the attribute '{@link fds_model.MaskPoint#getElevation <em>Elevation</em>}'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the meta object for the attribute '<em>Elevation</em>'.
     * @see fds_model.MaskPoint#getElevation()
     * @see #getMaskPoint()
     * @generated
     */
    EAttribute getMaskPoint_Elevation();

    /**
     * Returns the factory that creates the instances of the model.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the factory that creates the instances of the model.
     * @generated
     */
    Fds_modelFactory getFds_modelFactory();

    /**
     * <!-- begin-user-doc -->
     * Defines literals for the meta objects that represent
     * <ul>
     *   <li>each class,</li>
     *   <li>each feature of each class,</li>
     *   <li>each operation of each class,</li>
     *   <li>each enum,</li>
     *   <li>and each data type</li>
     * </ul>
     * <!-- end-user-doc -->
     * @generated
     */
    interface Literals {
        /**
         * The meta object literal for the '{@link fds_model.impl.MissionImpl <em>Mission</em>}' class.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @see fds_model.impl.MissionImpl
         * @see fds_model.impl.Fds_modelPackageImpl#getMission()
         * @generated
         */
        EClass MISSION = eINSTANCE.getMission();

        /**
         * The meta object literal for the '<em><b>Identifier</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__IDENTIFIER = eINSTANCE.getMission_Identifier();

        /**
         * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__NAME = eINSTANCE.getMission_Name();

        /**
         * The meta object literal for the '<em><b>Description</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__DESCRIPTION = eINSTANCE.getMission_Description();

        /**
         * The meta object literal for the '<em><b>Country</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__COUNTRY = eINSTANCE.getMission_Country();

        /**
         * The meta object literal for the '<em><b>Owner</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__OWNER = eINSTANCE.getMission_Owner();

        /**
         * The meta object literal for the '<em><b>Creation Date</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__CREATION_DATE = eINSTANCE.getMission_CreationDate();

        /**
         * The meta object literal for the '<em><b>Phone Number</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__PHONE_NUMBER = eINSTANCE.getMission_PhoneNumber();

        /**
         * The meta object literal for the '<em><b>Email</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MISSION__EMAIL = eINSTANCE.getMission_Email();

        /**
         * The meta object literal for the '<em><b>List Satellite</b></em>' containment reference list feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EReference MISSION__LIST_SATELLITE = eINSTANCE.getMission_ListSatellite();

        /**
         * The meta object literal for the '{@link fds_model.impl.SatelliteImpl <em>Satellite</em>}' class.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @see fds_model.impl.SatelliteImpl
         * @see fds_model.impl.Fds_modelPackageImpl#getSatellite()
         * @generated
         */
        EClass SATELLITE = eINSTANCE.getSatellite();

        /**
         * The meta object literal for the '<em><b>Identifier</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SATELLITE__IDENTIFIER = eINSTANCE.getSatellite_Identifier();

        /**
         * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SATELLITE__NAME = eINSTANCE.getSatellite_Name();

        /**
         * The meta object literal for the '<em><b>Description</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SATELLITE__DESCRIPTION = eINSTANCE.getSatellite_Description();

        /**
         * The meta object literal for the '<em><b>Code</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SATELLITE__CODE = eINSTANCE.getSatellite_Code();

        /**
         * The meta object literal for the '<em><b>Launch Date</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SATELLITE__LAUNCH_DATE = eINSTANCE.getSatellite_LaunchDate();

        /**
         * The meta object literal for the '<em><b>Admin</b></em>' containment reference feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EReference SATELLITE__ADMIN = eINSTANCE.getSatellite_Admin();

        /**
         * The meta object literal for the '<em><b>List Subsystem</b></em>' containment reference list feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EReference SATELLITE__LIST_SUBSYSTEM = eINSTANCE.getSatellite_ListSubsystem();

        /**
         * The meta object literal for the '{@link fds_model.impl.SubsystemImpl <em>Subsystem</em>}' class.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @see fds_model.impl.SubsystemImpl
         * @see fds_model.impl.Fds_modelPackageImpl#getSubsystem()
         * @generated
         */
        EClass SUBSYSTEM = eINSTANCE.getSubsystem();

        /**
         * The meta object literal for the '<em><b>Identifier</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SUBSYSTEM__IDENTIFIER = eINSTANCE.getSubsystem_Identifier();

        /**
         * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SUBSYSTEM__NAME = eINSTANCE.getSubsystem_Name();

        /**
         * The meta object literal for the '<em><b>Description</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute SUBSYSTEM__DESCRIPTION = eINSTANCE.getSubsystem_Description();

        /**
         * The meta object literal for the '{@link fds_model.impl.GroundStationImpl <em>Ground Station</em>}' class.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @see fds_model.impl.GroundStationImpl
         * @see fds_model.impl.Fds_modelPackageImpl#getGroundStation()
         * @generated
         */
        EClass GROUND_STATION = eINSTANCE.getGroundStation();

        /**
         * The meta object literal for the '<em><b>Identifier</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__IDENTIFIER = eINSTANCE.getGroundStation_Identifier();

        /**
         * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__NAME = eINSTANCE.getGroundStation_Name();

        /**
         * The meta object literal for the '<em><b>Description</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__DESCRIPTION = eINSTANCE.getGroundStation_Description();

        /**
         * The meta object literal for the '<em><b>Latitude</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__LATITUDE = eINSTANCE.getGroundStation_Latitude();

        /**
         * The meta object literal for the '<em><b>Longitude</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__LONGITUDE = eINSTANCE.getGroundStation_Longitude();

        /**
         * The meta object literal for the '<em><b>Altitude</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__ALTITUDE = eINSTANCE.getGroundStation_Altitude();

        /**
         * The meta object literal for the '<em><b>Minimum Elevation</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION__MINIMUM_ELEVATION = eINSTANCE.getGroundStation_MinimumElevation();

        /**
         * The meta object literal for the '<em><b>List Mask</b></em>' containment reference list feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EReference GROUND_STATION__LIST_MASK = eINSTANCE.getGroundStation_ListMask();

        /**
         * The meta object literal for the '{@link fds_model.impl.GroundStationMaskImpl <em>Ground Station Mask</em>}' class.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @see fds_model.impl.GroundStationMaskImpl
         * @see fds_model.impl.Fds_modelPackageImpl#getGroundStationMask()
         * @generated
         */
        EClass GROUND_STATION_MASK = eINSTANCE.getGroundStationMask();

        /**
         * The meta object literal for the '<em><b>Identifier</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION_MASK__IDENTIFIER = eINSTANCE.getGroundStationMask_Identifier();

        /**
         * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute GROUND_STATION_MASK__NAME = eINSTANCE.getGroundStationMask_Name();

        /**
         * The meta object literal for the '<em><b>List Point</b></em>' containment reference list feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EReference GROUND_STATION_MASK__LIST_POINT = eINSTANCE.getGroundStationMask_ListPoint();

        /**
         * The meta object literal for the '{@link fds_model.impl.MaskPointImpl <em>Mask Point</em>}' class.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @see fds_model.impl.MaskPointImpl
         * @see fds_model.impl.Fds_modelPackageImpl#getMaskPoint()
         * @generated
         */
        EClass MASK_POINT = eINSTANCE.getMaskPoint();

        /**
         * The meta object literal for the '<em><b>Identifier</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MASK_POINT__IDENTIFIER = eINSTANCE.getMaskPoint_Identifier();

        /**
         * The meta object literal for the '<em><b>Azimuth</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MASK_POINT__AZIMUTH = eINSTANCE.getMaskPoint_Azimuth();

        /**
         * The meta object literal for the '<em><b>Elevation</b></em>' attribute feature.
         * <!-- begin-user-doc -->
         * <!-- end-user-doc -->
         * @generated
         */
        EAttribute MASK_POINT__ELEVATION = eINSTANCE.getMaskPoint_Elevation();

    }

} //Fds_modelPackage
