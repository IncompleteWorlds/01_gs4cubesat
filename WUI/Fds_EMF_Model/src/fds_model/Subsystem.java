/**
 */
package fds_model;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Subsystem</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link fds_model.Subsystem#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.Subsystem#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.Subsystem#getDescription <em>Description</em>}</li>
 * </ul>
 *
 * @see fds_model.Fds_modelPackage#getSubsystem()
 * @model
 * @generated
 */
public interface Subsystem extends EObject {
    /**
     * Returns the value of the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Identifier</em>' attribute.
     * @see #setIdentifier(int)
     * @see fds_model.Fds_modelPackage#getSubsystem_Identifier()
     * @model
     * @generated
     */
    int getIdentifier();

    /**
     * Sets the value of the '{@link fds_model.Subsystem#getIdentifier <em>Identifier</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Identifier</em>' attribute.
     * @see #getIdentifier()
     * @generated
     */
    void setIdentifier(int value);

    /**
     * Returns the value of the '<em><b>Name</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Name</em>' attribute.
     * @see #setName(String)
     * @see fds_model.Fds_modelPackage#getSubsystem_Name()
     * @model
     * @generated
     */
    String getName();

    /**
     * Sets the value of the '{@link fds_model.Subsystem#getName <em>Name</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Name</em>' attribute.
     * @see #getName()
     * @generated
     */
    void setName(String value);

    /**
     * Returns the value of the '<em><b>Description</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Description</em>' attribute.
     * @see #setDescription(String)
     * @see fds_model.Fds_modelPackage#getSubsystem_Description()
     * @model
     * @generated
     */
    String getDescription();

    /**
     * Sets the value of the '{@link fds_model.Subsystem#getDescription <em>Description</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Description</em>' attribute.
     * @see #getDescription()
     * @generated
     */
    void setDescription(String value);

} // Subsystem
