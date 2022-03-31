/**
 */
package common_model;

import org.eclipse.emf.ecore.EFactory;

/**
 * <!-- begin-user-doc -->
 * The <b>Factory</b> for the model.
 * It provides a create method for each non-abstract class of the model.
 * <!-- end-user-doc -->
 * @see common_model.Common_modelPackage
 * @generated
 */
public interface Common_modelFactory extends EFactory {
    /**
     * The singleton instance of the factory.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    Common_modelFactory eINSTANCE = common_model.impl.Common_modelFactoryImpl.init();

    /**
     * Returns a new object of class '<em>User</em>'.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return a new object of class '<em>User</em>'.
     * @generated
     */
    User createUser();

    /**
     * Returns the package supported by this factory.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the package supported by this factory.
     * @generated
     */
    Common_modelPackage getCommon_modelPackage();

} //Common_modelFactory
