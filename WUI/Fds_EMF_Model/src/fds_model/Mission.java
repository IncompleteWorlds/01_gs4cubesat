/**
 */
package fds_model;

import java.util.Date;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Mission</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link fds_model.Mission#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.Mission#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.Mission#getDescription <em>Description</em>}</li>
 *   <li>{@link fds_model.Mission#getCountry <em>Country</em>}</li>
 *   <li>{@link fds_model.Mission#getOwner <em>Owner</em>}</li>
 *   <li>{@link fds_model.Mission#getCreationDate <em>Creation Date</em>}</li>
 *   <li>{@link fds_model.Mission#getPhoneNumber <em>Phone Number</em>}</li>
 *   <li>{@link fds_model.Mission#getEmail <em>Email</em>}</li>
 *   <li>{@link fds_model.Mission#getListSatellite <em>List Satellite</em>}</li>
 * </ul>
 *
 * @see fds_model.Fds_modelPackage#getMission()
 * @model
 * @generated
 */
public interface Mission extends EObject {
    /**
     * Returns the value of the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Identifier</em>' attribute.
     * @see #setIdentifier(int)
     * @see fds_model.Fds_modelPackage#getMission_Identifier()
     * @model
     * @generated
     */
    int getIdentifier();

    /**
     * Sets the value of the '{@link fds_model.Mission#getIdentifier <em>Identifier</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getMission_Name()
     * @model
     * @generated
     */
    String getName();

    /**
     * Sets the value of the '{@link fds_model.Mission#getName <em>Name</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getMission_Description()
     * @model
     * @generated
     */
    String getDescription();

    /**
     * Sets the value of the '{@link fds_model.Mission#getDescription <em>Description</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Description</em>' attribute.
     * @see #getDescription()
     * @generated
     */
    void setDescription(String value);

    /**
     * Returns the value of the '<em><b>Country</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Country</em>' attribute.
     * @see #setCountry(String)
     * @see fds_model.Fds_modelPackage#getMission_Country()
     * @model
     * @generated
     */
    String getCountry();

    /**
     * Sets the value of the '{@link fds_model.Mission#getCountry <em>Country</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Country</em>' attribute.
     * @see #getCountry()
     * @generated
     */
    void setCountry(String value);

    /**
     * Returns the value of the '<em><b>Owner</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Owner</em>' attribute.
     * @see #setOwner(String)
     * @see fds_model.Fds_modelPackage#getMission_Owner()
     * @model
     * @generated
     */
    String getOwner();

    /**
     * Sets the value of the '{@link fds_model.Mission#getOwner <em>Owner</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Owner</em>' attribute.
     * @see #getOwner()
     * @generated
     */
    void setOwner(String value);

    /**
     * Returns the value of the '<em><b>Creation Date</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Creation Date</em>' attribute.
     * @see #setCreationDate(Date)
     * @see fds_model.Fds_modelPackage#getMission_CreationDate()
     * @model
     * @generated
     */
    Date getCreationDate();

    /**
     * Sets the value of the '{@link fds_model.Mission#getCreationDate <em>Creation Date</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Creation Date</em>' attribute.
     * @see #getCreationDate()
     * @generated
     */
    void setCreationDate(Date value);

    /**
     * Returns the value of the '<em><b>Phone Number</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Phone Number</em>' attribute.
     * @see #setPhoneNumber(String)
     * @see fds_model.Fds_modelPackage#getMission_PhoneNumber()
     * @model
     * @generated
     */
    String getPhoneNumber();

    /**
     * Sets the value of the '{@link fds_model.Mission#getPhoneNumber <em>Phone Number</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Phone Number</em>' attribute.
     * @see #getPhoneNumber()
     * @generated
     */
    void setPhoneNumber(String value);

    /**
     * Returns the value of the '<em><b>Email</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Email</em>' attribute.
     * @see #setEmail(String)
     * @see fds_model.Fds_modelPackage#getMission_Email()
     * @model
     * @generated
     */
    String getEmail();

    /**
     * Sets the value of the '{@link fds_model.Mission#getEmail <em>Email</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Email</em>' attribute.
     * @see #getEmail()
     * @generated
     */
    void setEmail(String value);

    /**
     * Returns the value of the '<em><b>List Satellite</b></em>' containment reference list.
     * The list contents are of type {@link fds_model.Satellite}.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>List Satellite</em>' containment reference list.
     * @see fds_model.Fds_modelPackage#getMission_ListSatellite()
     * @model containment="true"
     * @generated
     */
    EList<Satellite> getListSatellite();

} // Mission
