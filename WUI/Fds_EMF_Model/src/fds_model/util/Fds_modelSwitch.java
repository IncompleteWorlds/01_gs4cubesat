/**
 */
package fds_model.util;

import fds_model.*;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.util.Switch;

/**
 * <!-- begin-user-doc -->
 * The <b>Switch</b> for the model's inheritance hierarchy.
 * It supports the call {@link #doSwitch(EObject) doSwitch(object)}
 * to invoke the <code>caseXXX</code> method for each class of the model,
 * starting with the actual class of the object
 * and proceeding up the inheritance hierarchy
 * until a non-null result is returned,
 * which is the result of the switch.
 * <!-- end-user-doc -->
 * @see fds_model.Fds_modelPackage
 * @generated
 */
public class Fds_modelSwitch<T> extends Switch<T> {
    /**
     * The cached model package
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected static Fds_modelPackage modelPackage;

    /**
     * Creates an instance of the switch.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Fds_modelSwitch() {
        if (modelPackage == null) {
            modelPackage = Fds_modelPackage.eINSTANCE;
        }
    }

    /**
     * Checks whether this is a switch for the given package.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param ePackage the package in question.
     * @return whether this is a switch for the given package.
     * @generated
     */
    @Override
    protected boolean isSwitchFor(EPackage ePackage) {
        return ePackage == modelPackage;
    }

    /**
     * Calls <code>caseXXX</code> for each class of the model until one returns a non null result; it yields that result.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the first non-null result returned by a <code>caseXXX</code> call.
     * @generated
     */
    @Override
    protected T doSwitch(int classifierID, EObject theEObject) {
        switch (classifierID) {
            case Fds_modelPackage.MISSION: {
                Mission mission = (Mission)theEObject;
                T result = caseMission(mission);
                if (result == null) result = defaultCase(theEObject);
                return result;
            }
            case Fds_modelPackage.SATELLITE: {
                Satellite satellite = (Satellite)theEObject;
                T result = caseSatellite(satellite);
                if (result == null) result = defaultCase(theEObject);
                return result;
            }
            case Fds_modelPackage.SUBSYSTEM: {
                Subsystem subsystem = (Subsystem)theEObject;
                T result = caseSubsystem(subsystem);
                if (result == null) result = defaultCase(theEObject);
                return result;
            }
            case Fds_modelPackage.GROUND_STATION: {
                GroundStation groundStation = (GroundStation)theEObject;
                T result = caseGroundStation(groundStation);
                if (result == null) result = defaultCase(theEObject);
                return result;
            }
            case Fds_modelPackage.GROUND_STATION_MASK: {
                GroundStationMask groundStationMask = (GroundStationMask)theEObject;
                T result = caseGroundStationMask(groundStationMask);
                if (result == null) result = defaultCase(theEObject);
                return result;
            }
            case Fds_modelPackage.MASK_POINT: {
                MaskPoint maskPoint = (MaskPoint)theEObject;
                T result = caseMaskPoint(maskPoint);
                if (result == null) result = defaultCase(theEObject);
                return result;
            }
            default: return defaultCase(theEObject);
        }
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>Mission</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>Mission</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
     * @generated
     */
    public T caseMission(Mission object) {
        return null;
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>Satellite</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>Satellite</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
     * @generated
     */
    public T caseSatellite(Satellite object) {
        return null;
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>Subsystem</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>Subsystem</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
     * @generated
     */
    public T caseSubsystem(Subsystem object) {
        return null;
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>Ground Station</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>Ground Station</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
     * @generated
     */
    public T caseGroundStation(GroundStation object) {
        return null;
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>Ground Station Mask</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>Ground Station Mask</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
     * @generated
     */
    public T caseGroundStationMask(GroundStationMask object) {
        return null;
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>Mask Point</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>Mask Point</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
     * @generated
     */
    public T caseMaskPoint(MaskPoint object) {
        return null;
    }

    /**
     * Returns the result of interpreting the object as an instance of '<em>EObject</em>'.
     * <!-- begin-user-doc -->
     * This implementation returns null;
     * returning a non-null result will terminate the switch, but this is the last case anyway.
     * <!-- end-user-doc -->
     * @param object the target of the switch.
     * @return the result of interpreting the object as an instance of '<em>EObject</em>'.
     * @see #doSwitch(org.eclipse.emf.ecore.EObject)
     * @generated
     */
    @Override
    public T defaultCase(EObject object) {
        return null;
    }

} //Fds_modelSwitch
