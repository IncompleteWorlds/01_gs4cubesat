/**
 */
package fds_model.util;

import fds_model.*;

import org.eclipse.emf.common.notify.Adapter;
import org.eclipse.emf.common.notify.Notifier;

import org.eclipse.emf.common.notify.impl.AdapterFactoryImpl;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * The <b>Adapter Factory</b> for the model.
 * It provides an adapter <code>createXXX</code> method for each class of the model.
 * <!-- end-user-doc -->
 * @see fds_model.Fds_modelPackage
 * @generated
 */
public class Fds_modelAdapterFactory extends AdapterFactoryImpl {
    /**
     * The cached model package.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected static Fds_modelPackage modelPackage;

    /**
     * Creates an instance of the adapter factory.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Fds_modelAdapterFactory() {
        if (modelPackage == null) {
            modelPackage = Fds_modelPackage.eINSTANCE;
        }
    }

    /**
     * Returns whether this factory is applicable for the type of the object.
     * <!-- begin-user-doc -->
     * This implementation returns <code>true</code> if the object is either the model's package or is an instance object of the model.
     * <!-- end-user-doc -->
     * @return whether this factory is applicable for the type of the object.
     * @generated
     */
    @Override
    public boolean isFactoryForType(Object object) {
        if (object == modelPackage) {
            return true;
        }
        if (object instanceof EObject) {
            return ((EObject)object).eClass().getEPackage() == modelPackage;
        }
        return false;
    }

    /**
     * The switch that delegates to the <code>createXXX</code> methods.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected Fds_modelSwitch<Adapter> modelSwitch =
        new Fds_modelSwitch<Adapter>() {
            @Override
            public Adapter caseMission(Mission object) {
                return createMissionAdapter();
            }
            @Override
            public Adapter caseSatellite(Satellite object) {
                return createSatelliteAdapter();
            }
            @Override
            public Adapter caseSubsystem(Subsystem object) {
                return createSubsystemAdapter();
            }
            @Override
            public Adapter caseGroundStation(GroundStation object) {
                return createGroundStationAdapter();
            }
            @Override
            public Adapter caseGroundStationMask(GroundStationMask object) {
                return createGroundStationMaskAdapter();
            }
            @Override
            public Adapter caseMaskPoint(MaskPoint object) {
                return createMaskPointAdapter();
            }
            @Override
            public Adapter defaultCase(EObject object) {
                return createEObjectAdapter();
            }
        };

    /**
     * Creates an adapter for the <code>target</code>.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param target the object to adapt.
     * @return the adapter for the <code>target</code>.
     * @generated
     */
    @Override
    public Adapter createAdapter(Notifier target) {
        return modelSwitch.doSwitch((EObject)target);
    }


    /**
     * Creates a new adapter for an object of class '{@link fds_model.Mission <em>Mission</em>}'.
     * <!-- begin-user-doc -->
     * This default implementation returns null so that we can easily ignore cases;
     * it's useful to ignore a case when inheritance will catch all the cases anyway.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @see fds_model.Mission
     * @generated
     */
    public Adapter createMissionAdapter() {
        return null;
    }

    /**
     * Creates a new adapter for an object of class '{@link fds_model.Satellite <em>Satellite</em>}'.
     * <!-- begin-user-doc -->
     * This default implementation returns null so that we can easily ignore cases;
     * it's useful to ignore a case when inheritance will catch all the cases anyway.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @see fds_model.Satellite
     * @generated
     */
    public Adapter createSatelliteAdapter() {
        return null;
    }

    /**
     * Creates a new adapter for an object of class '{@link fds_model.Subsystem <em>Subsystem</em>}'.
     * <!-- begin-user-doc -->
     * This default implementation returns null so that we can easily ignore cases;
     * it's useful to ignore a case when inheritance will catch all the cases anyway.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @see fds_model.Subsystem
     * @generated
     */
    public Adapter createSubsystemAdapter() {
        return null;
    }

    /**
     * Creates a new adapter for an object of class '{@link fds_model.GroundStation <em>Ground Station</em>}'.
     * <!-- begin-user-doc -->
     * This default implementation returns null so that we can easily ignore cases;
     * it's useful to ignore a case when inheritance will catch all the cases anyway.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @see fds_model.GroundStation
     * @generated
     */
    public Adapter createGroundStationAdapter() {
        return null;
    }

    /**
     * Creates a new adapter for an object of class '{@link fds_model.GroundStationMask <em>Ground Station Mask</em>}'.
     * <!-- begin-user-doc -->
     * This default implementation returns null so that we can easily ignore cases;
     * it's useful to ignore a case when inheritance will catch all the cases anyway.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @see fds_model.GroundStationMask
     * @generated
     */
    public Adapter createGroundStationMaskAdapter() {
        return null;
    }

    /**
     * Creates a new adapter for an object of class '{@link fds_model.MaskPoint <em>Mask Point</em>}'.
     * <!-- begin-user-doc -->
     * This default implementation returns null so that we can easily ignore cases;
     * it's useful to ignore a case when inheritance will catch all the cases anyway.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @see fds_model.MaskPoint
     * @generated
     */
    public Adapter createMaskPointAdapter() {
        return null;
    }

    /**
     * Creates a new adapter for the default case.
     * <!-- begin-user-doc -->
     * This default implementation returns null.
     * <!-- end-user-doc -->
     * @return the new adapter.
     * @generated
     */
    public Adapter createEObjectAdapter() {
        return null;
    }

} //Fds_modelAdapterFactory
