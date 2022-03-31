/**
 */
package fds_model;

import org.eclipse.emf.ecore.EFactory;

/**
 * <!-- begin-user-doc -->
 * The <b>Factory</b> for the model.
 * It provides a create method for each non-abstract class of the model.
 * <!-- end-user-doc -->
 * @see fds_model.Fds_modelPackage
 * @generated
 */
public interface Fds_modelFactory extends EFactory {
    /**
     * The singleton instance of the factory.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    Fds_modelFactory eINSTANCE = fds_model.impl.Fds_modelFactoryImpl.init();

    /**
     * Returns a new object of class '<em>Mission</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>Mission</em>'.
     * @generated
     */
    Mission createMission();

    /**
     * Returns a new object of class '<em>Satellite</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>Satellite</em>'.
     * @generated
     */
    Satellite createSatellite();

    /**
     * Returns a new object of class '<em>Subsystem</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>Subsystem</em>'.
     * @generated
     */
    Subsystem createSubsystem();

    /**
     * Returns a new object of class '<em>Ground Station</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>Ground Station</em>'.
     * @generated
     */
    GroundStation createGroundStation();

    /**
     * Returns a new object of class '<em>Ground Station Mask</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>Ground Station Mask</em>'.
     * @generated
     */
    GroundStationMask createGroundStationMask();

    /**
     * Returns a new object of class '<em>Mask Point</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>Mask Point</em>'.
     * @generated
     */
    MaskPoint createMaskPoint();

    /**
     * Returns the package supported by this factory.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the package supported by this factory.
     * @generated
     */
    Fds_modelPackage getFds_modelPackage();

} //Fds_modelFactory
