/**
 */
package fds_model;

import java.util.Date;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Satellite</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link fds_model.Satellite#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.Satellite#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.Satellite#getDescription <em>Description</em>}</li>
 *   <li>{@link fds_model.Satellite#getCode <em>Code</em>}</li>
 *   <li>{@link fds_model.Satellite#getLaunchDate <em>Launch Date</em>}</li>
 *   <li>{@link fds_model.Satellite#getAdmin <em>Admin</em>}</li>
 *   <li>{@link fds_model.Satellite#getListSubsystem <em>List Subsystem</em>}</li>
 * </ul>
 *
 * @see fds_model.Fds_modelPackage#getSatellite()
 * @model
 * @generated
 */
public interface Satellite extends EObject {
    /**
     * Returns the value of the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Identifier</em>' attribute.
     * @see #setIdentifier(int)
     * @see fds_model.Fds_modelPackage#getSatellite_Identifier()
     * @model
     * @generated
     */
    int getIdentifier();

    /**
     * Sets the value of the '{@link fds_model.Satellite#getIdentifier <em>Identifier</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getSatellite_Name()
     * @model
     * @generated
     */
    String getName();

    /**
     * Sets the value of the '{@link fds_model.Satellite#getName <em>Name</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getSatellite_Description()
     * @model
     * @generated
     */
    String getDescription();

    /**
     * Sets the value of the '{@link fds_model.Satellite#getDescription <em>Description</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Description</em>' attribute.
     * @see #getDescription()
     * @generated
     */
    void setDescription(String value);

    /**
     * Returns the value of the '<em><b>Code</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Code</em>' attribute.
     * @see #setCode(String)
     * @see fds_model.Fds_modelPackage#getSatellite_Code()
     * @model
     * @generated
     */
    String getCode();

    /**
     * Sets the value of the '{@link fds_model.Satellite#getCode <em>Code</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Code</em>' attribute.
     * @see #getCode()
     * @generated
     */
    void setCode(String value);

    /**
     * Returns the value of the '<em><b>Launch Date</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Launch Date</em>' attribute.
     * @see #setLaunchDate(Date)
     * @see fds_model.Fds_modelPackage#getSatellite_LaunchDate()
     * @model
     * @generated
     */
    Date getLaunchDate();

    /**
     * Sets the value of the '{@link fds_model.Satellite#getLaunchDate <em>Launch Date</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Launch Date</em>' attribute.
     * @see #getLaunchDate()
     * @generated
     */
    void setLaunchDate(Date value);

    /**
     * Returns the value of the '<em><b>Admin</b></em>' containment reference.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Admin</em>' containment reference.
     * @see #setAdmin(EObject)
     * @see fds_model.Fds_modelPackage#getSatellite_Admin()
     * @model containment="true"
     * @generated
     */
    EObject getAdmin();

    /**
     * Sets the value of the '{@link fds_model.Satellite#getAdmin <em>Admin</em>}' containment reference.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Admin</em>' containment reference.
     * @see #getAdmin()
     * @generated
     */
    void setAdmin(EObject value);

    /**
     * Returns the value of the '<em><b>List Subsystem</b></em>' containment reference list.
     * The list contents are of type {@link fds_model.Subsystem}.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>List Subsystem</em>' containment reference list.
     * @see fds_model.Fds_modelPackage#getSatellite_ListSubsystem()
     * @model containment="true"
     * @generated
     */
    EList<Subsystem> getListSubsystem();

} // Satellite
