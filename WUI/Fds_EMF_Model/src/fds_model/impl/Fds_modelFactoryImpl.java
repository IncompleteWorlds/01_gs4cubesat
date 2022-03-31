/**
 */
package fds_model.impl;

import fds_model.*;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.impl.EFactoryImpl;

import org.eclipse.emf.ecore.plugin.EcorePlugin;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Factory</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class Fds_modelFactoryImpl extends EFactoryImpl implements Fds_modelFactory {
    /**
     * Creates the default factory implementation.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public static Fds_modelFactory init() {
        try {
            Fds_modelFactory theFds_modelFactory = (Fds_modelFactory)EPackage.Registry.INSTANCE.getEFactory(Fds_modelPackage.eNS_URI);
            if (theFds_modelFactory != null) {
                return theFds_modelFactory;
            }
        }
        catch (Exception exception) {
            EcorePlugin.INSTANCE.log(exception);
        }
        return new Fds_modelFactoryImpl();
    }

    /**
     * Creates an instance of the factory.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Fds_modelFactoryImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public EObject create(EClass eClass) {
        switch (eClass.getClassifierID()) {
            case Fds_modelPackage.MISSION: return createMission();
            case Fds_modelPackage.SATELLITE: return createSatellite();
            case Fds_modelPackage.SUBSYSTEM: return createSubsystem();
            case Fds_modelPackage.GROUND_STATION: return createGroundStation();
            case Fds_modelPackage.GROUND_STATION_MASK: return createGroundStationMask();
            case Fds_modelPackage.MASK_POINT: return createMaskPoint();
            default:
                throw new IllegalArgumentException("The class '" + eClass.getName() + "' is not a valid classifier");
        }
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Mission createMission() {
        MissionImpl mission = new MissionImpl();
        return mission;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Satellite createSatellite() {
        SatelliteImpl satellite = new SatelliteImpl();
        return satellite;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Subsystem createSubsystem() {
        SubsystemImpl subsystem = new SubsystemImpl();
        return subsystem;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public GroundStation createGroundStation() {
        GroundStationImpl groundStation = new GroundStationImpl();
        return groundStation;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public GroundStationMask createGroundStationMask() {
        GroundStationMaskImpl groundStationMask = new GroundStationMaskImpl();
        return groundStationMask;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public MaskPoint createMaskPoint() {
        MaskPointImpl maskPoint = new MaskPointImpl();
        return maskPoint;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Fds_modelPackage getFds_modelPackage() {
        return (Fds_modelPackage)getEPackage();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @deprecated
     * @generated
     */
    @Deprecated
    public static Fds_modelPackage getPackage() {
        return Fds_modelPackage.eINSTANCE;
    }

} //Fds_modelFactoryImpl
