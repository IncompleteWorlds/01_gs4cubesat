/**
 */
package fds_model.impl;

import fds_model.Fds_modelFactory;
import fds_model.Fds_modelPackage;
import fds_model.GroundStation;
import fds_model.GroundStationMask;
import fds_model.MaskPoint;
import fds_model.Mission;
import fds_model.Satellite;
import fds_model.Subsystem;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

import org.eclipse.emf.ecore.impl.EPackageImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Package</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class Fds_modelPackageImpl extends EPackageImpl implements Fds_modelPackage {
    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private EClass missionEClass = null;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private EClass satelliteEClass = null;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private EClass subsystemEClass = null;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private EClass groundStationEClass = null;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private EClass groundStationMaskEClass = null;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private EClass maskPointEClass = null;

    /**
     * Creates an instance of the model <b>Package</b>, registered with
     * {@link org.eclipse.emf.ecore.EPackage.Registry EPackage.Registry} by the package
     * package URI value.
     * <p>Note: the correct way to create the package is via the static
     * factory method {@link #init init()}, which also performs
     * initialization of the package, or returns the registered package,
     * if one already exists.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see org.eclipse.emf.ecore.EPackage.Registry
     * @see fds_model.Fds_modelPackage#eNS_URI
     * @see #init()
     * @generated
     */
    private Fds_modelPackageImpl() {
        super(eNS_URI, Fds_modelFactory.eINSTANCE);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private static boolean isInited = false;

    /**
     * Creates, registers, and initializes the <b>Package</b> for this model, and for any others upon which it depends.
     *
     * <p>This method is used to initialize {@link Fds_modelPackage#eINSTANCE} when that field is accessed.
     * Clients should not invoke it directly. Instead, they should simply access that field to obtain the package.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #eNS_URI
     * @see #createPackageContents()
     * @see #initializePackageContents()
     * @generated
     */
    public static Fds_modelPackage init() {
        if (isInited) return (Fds_modelPackage)EPackage.Registry.INSTANCE.getEPackage(Fds_modelPackage.eNS_URI);

        // Obtain or create and register package
        Object registeredFds_modelPackage = EPackage.Registry.INSTANCE.get(eNS_URI);
        Fds_modelPackageImpl theFds_modelPackage = registeredFds_modelPackage instanceof Fds_modelPackageImpl ? (Fds_modelPackageImpl)registeredFds_modelPackage : new Fds_modelPackageImpl();

        isInited = true;

        // Create package meta-data objects
        theFds_modelPackage.createPackageContents();

        // Initialize created meta-data
        theFds_modelPackage.initializePackageContents();

        // Mark meta-data to indicate it can't be changed
        theFds_modelPackage.freeze();

        // Update the registry and return the package
        EPackage.Registry.INSTANCE.put(Fds_modelPackage.eNS_URI, theFds_modelPackage);
        return theFds_modelPackage;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EClass getMission() {
        return missionEClass;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_Identifier() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(0);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_Name() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(1);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_Description() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(2);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_Country() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(3);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_Owner() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(4);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_CreationDate() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(5);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_PhoneNumber() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(6);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMission_Email() {
        return (EAttribute)missionEClass.getEStructuralFeatures().get(7);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EReference getMission_ListSatellite() {
        return (EReference)missionEClass.getEStructuralFeatures().get(8);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EClass getSatellite() {
        return satelliteEClass;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSatellite_Identifier() {
        return (EAttribute)satelliteEClass.getEStructuralFeatures().get(0);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSatellite_Name() {
        return (EAttribute)satelliteEClass.getEStructuralFeatures().get(1);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSatellite_Description() {
        return (EAttribute)satelliteEClass.getEStructuralFeatures().get(2);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSatellite_Code() {
        return (EAttribute)satelliteEClass.getEStructuralFeatures().get(3);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSatellite_LaunchDate() {
        return (EAttribute)satelliteEClass.getEStructuralFeatures().get(4);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EReference getSatellite_Admin() {
        return (EReference)satelliteEClass.getEStructuralFeatures().get(5);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EReference getSatellite_ListSubsystem() {
        return (EReference)satelliteEClass.getEStructuralFeatures().get(6);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EClass getSubsystem() {
        return subsystemEClass;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSubsystem_Identifier() {
        return (EAttribute)subsystemEClass.getEStructuralFeatures().get(0);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSubsystem_Name() {
        return (EAttribute)subsystemEClass.getEStructuralFeatures().get(1);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getSubsystem_Description() {
        return (EAttribute)subsystemEClass.getEStructuralFeatures().get(2);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EClass getGroundStation() {
        return groundStationEClass;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_Identifier() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(0);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_Name() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(1);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_Description() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(2);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_Latitude() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(3);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_Longitude() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(4);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_Altitude() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(5);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStation_MinimumElevation() {
        return (EAttribute)groundStationEClass.getEStructuralFeatures().get(6);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EReference getGroundStation_ListMask() {
        return (EReference)groundStationEClass.getEStructuralFeatures().get(7);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EClass getGroundStationMask() {
        return groundStationMaskEClass;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStationMask_Identifier() {
        return (EAttribute)groundStationMaskEClass.getEStructuralFeatures().get(0);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getGroundStationMask_Name() {
        return (EAttribute)groundStationMaskEClass.getEStructuralFeatures().get(1);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EReference getGroundStationMask_ListPoint() {
        return (EReference)groundStationMaskEClass.getEStructuralFeatures().get(2);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EClass getMaskPoint() {
        return maskPointEClass;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMaskPoint_Identifier() {
        return (EAttribute)maskPointEClass.getEStructuralFeatures().get(0);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMaskPoint_Azimuth() {
        return (EAttribute)maskPointEClass.getEStructuralFeatures().get(1);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EAttribute getMaskPoint_Elevation() {
        return (EAttribute)maskPointEClass.getEStructuralFeatures().get(2);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Fds_modelFactory getFds_modelFactory() {
        return (Fds_modelFactory)getEFactoryInstance();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private boolean isCreated = false;

    /**
     * Creates the meta-model objects for the package.  This method is
     * guarded to have no affect on any invocation but its first.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void createPackageContents() {
        if (isCreated) return;
        isCreated = true;

        // Create classes and their features
        missionEClass = createEClass(MISSION);
        createEAttribute(missionEClass, MISSION__IDENTIFIER);
        createEAttribute(missionEClass, MISSION__NAME);
        createEAttribute(missionEClass, MISSION__DESCRIPTION);
        createEAttribute(missionEClass, MISSION__COUNTRY);
        createEAttribute(missionEClass, MISSION__OWNER);
        createEAttribute(missionEClass, MISSION__CREATION_DATE);
        createEAttribute(missionEClass, MISSION__PHONE_NUMBER);
        createEAttribute(missionEClass, MISSION__EMAIL);
        createEReference(missionEClass, MISSION__LIST_SATELLITE);

        satelliteEClass = createEClass(SATELLITE);
        createEAttribute(satelliteEClass, SATELLITE__IDENTIFIER);
        createEAttribute(satelliteEClass, SATELLITE__NAME);
        createEAttribute(satelliteEClass, SATELLITE__DESCRIPTION);
        createEAttribute(satelliteEClass, SATELLITE__CODE);
        createEAttribute(satelliteEClass, SATELLITE__LAUNCH_DATE);
        createEReference(satelliteEClass, SATELLITE__ADMIN);
        createEReference(satelliteEClass, SATELLITE__LIST_SUBSYSTEM);

        subsystemEClass = createEClass(SUBSYSTEM);
        createEAttribute(subsystemEClass, SUBSYSTEM__IDENTIFIER);
        createEAttribute(subsystemEClass, SUBSYSTEM__NAME);
        createEAttribute(subsystemEClass, SUBSYSTEM__DESCRIPTION);

        groundStationEClass = createEClass(GROUND_STATION);
        createEAttribute(groundStationEClass, GROUND_STATION__IDENTIFIER);
        createEAttribute(groundStationEClass, GROUND_STATION__NAME);
        createEAttribute(groundStationEClass, GROUND_STATION__DESCRIPTION);
        createEAttribute(groundStationEClass, GROUND_STATION__LATITUDE);
        createEAttribute(groundStationEClass, GROUND_STATION__LONGITUDE);
        createEAttribute(groundStationEClass, GROUND_STATION__ALTITUDE);
        createEAttribute(groundStationEClass, GROUND_STATION__MINIMUM_ELEVATION);
        createEReference(groundStationEClass, GROUND_STATION__LIST_MASK);

        groundStationMaskEClass = createEClass(GROUND_STATION_MASK);
        createEAttribute(groundStationMaskEClass, GROUND_STATION_MASK__IDENTIFIER);
        createEAttribute(groundStationMaskEClass, GROUND_STATION_MASK__NAME);
        createEReference(groundStationMaskEClass, GROUND_STATION_MASK__LIST_POINT);

        maskPointEClass = createEClass(MASK_POINT);
        createEAttribute(maskPointEClass, MASK_POINT__IDENTIFIER);
        createEAttribute(maskPointEClass, MASK_POINT__AZIMUTH);
        createEAttribute(maskPointEClass, MASK_POINT__ELEVATION);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    private boolean isInitialized = false;

    /**
     * Complete the initialization of the package and its meta-model.  This
     * method is guarded to have no affect on any invocation but its first.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void initializePackageContents() {
        if (isInitialized) return;
        isInitialized = true;

        // Initialize package
        setName(eNAME);
        setNsPrefix(eNS_PREFIX);
        setNsURI(eNS_URI);

        // Create type parameters

        // Set bounds for type parameters

        // Add supertypes to classes

        // Initialize classes, features, and operations; add parameters
        initEClass(missionEClass, Mission.class, "Mission", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
        initEAttribute(getMission_Identifier(), ecorePackage.getEInt(), "identifier", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_Name(), ecorePackage.getEString(), "name", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_Description(), ecorePackage.getEString(), "description", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_Country(), ecorePackage.getEString(), "country", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_Owner(), ecorePackage.getEString(), "owner", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_CreationDate(), ecorePackage.getEDate(), "creationDate", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_PhoneNumber(), ecorePackage.getEString(), "phoneNumber", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMission_Email(), ecorePackage.getEString(), "email", null, 0, 1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEReference(getMission_ListSatellite(), this.getSatellite(), null, "listSatellite", null, 0, -1, Mission.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

        initEClass(satelliteEClass, Satellite.class, "Satellite", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
        initEAttribute(getSatellite_Identifier(), ecorePackage.getEInt(), "identifier", null, 0, 1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getSatellite_Name(), ecorePackage.getEString(), "name", null, 0, 1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getSatellite_Description(), ecorePackage.getEString(), "description", null, 0, 1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getSatellite_Code(), ecorePackage.getEString(), "code", null, 0, 1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getSatellite_LaunchDate(), ecorePackage.getEDate(), "launchDate", null, 0, 1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEReference(getSatellite_Admin(), ecorePackage.getEObject(), null, "admin", null, 0, 1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEReference(getSatellite_ListSubsystem(), this.getSubsystem(), null, "listSubsystem", null, 0, -1, Satellite.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

        initEClass(subsystemEClass, Subsystem.class, "Subsystem", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
        initEAttribute(getSubsystem_Identifier(), ecorePackage.getEInt(), "identifier", null, 0, 1, Subsystem.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getSubsystem_Name(), ecorePackage.getEString(), "name", null, 0, 1, Subsystem.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getSubsystem_Description(), ecorePackage.getEString(), "description", null, 0, 1, Subsystem.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

        initEClass(groundStationEClass, GroundStation.class, "GroundStation", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
        initEAttribute(getGroundStation_Identifier(), ecorePackage.getEInt(), "identifier", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStation_Name(), ecorePackage.getEString(), "name", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStation_Description(), ecorePackage.getEString(), "description", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStation_Latitude(), ecorePackage.getEDouble(), "latitude", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStation_Longitude(), ecorePackage.getEDouble(), "longitude", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStation_Altitude(), ecorePackage.getEDouble(), "altitude", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStation_MinimumElevation(), ecorePackage.getEDouble(), "minimumElevation", null, 0, 1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEReference(getGroundStation_ListMask(), this.getGroundStationMask(), null, "listMask", null, 0, -1, GroundStation.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

        initEClass(groundStationMaskEClass, GroundStationMask.class, "GroundStationMask", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
        initEAttribute(getGroundStationMask_Identifier(), ecorePackage.getEInt(), "identifier", null, 0, 1, GroundStationMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getGroundStationMask_Name(), ecorePackage.getEString(), "name", null, 0, 1, GroundStationMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEReference(getGroundStationMask_ListPoint(), this.getMaskPoint(), null, "listPoint", null, 0, -1, GroundStationMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

        initEClass(maskPointEClass, MaskPoint.class, "MaskPoint", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
        initEAttribute(getMaskPoint_Identifier(), ecorePackage.getEInt(), "identifier", null, 0, 1, MaskPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMaskPoint_Azimuth(), ecorePackage.getEDouble(), "azimuth", null, 0, 1, MaskPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
        initEAttribute(getMaskPoint_Elevation(), ecorePackage.getEDouble(), "elevation", null, 0, 1, MaskPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

        // Create resource
        createResource(eNS_URI);
    }

} //Fds_modelPackageImpl
