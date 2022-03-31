/**
 */
package fds_model;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Ground Station</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link fds_model.GroundStation#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.GroundStation#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.GroundStation#getDescription <em>Description</em>}</li>
 *   <li>{@link fds_model.GroundStation#getLatitude <em>Latitude</em>}</li>
 *   <li>{@link fds_model.GroundStation#getLongitude <em>Longitude</em>}</li>
 *   <li>{@link fds_model.GroundStation#getAltitude <em>Altitude</em>}</li>
 *   <li>{@link fds_model.GroundStation#getMinimumElevation <em>Minimum Elevation</em>}</li>
 *   <li>{@link fds_model.GroundStation#getListMask <em>List Mask</em>}</li>
 * </ul>
 *
 * @see fds_model.Fds_modelPackage#getGroundStation()
 * @model
 * @generated
 */
public interface GroundStation extends EObject {
    /**
     * Returns the value of the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Identifier</em>' attribute.
     * @see #setIdentifier(int)
     * @see fds_model.Fds_modelPackage#getGroundStation_Identifier()
     * @model
     * @generated
     */
    int getIdentifier();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getIdentifier <em>Identifier</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getGroundStation_Name()
     * @model
     * @generated
     */
    String getName();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getName <em>Name</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getGroundStation_Description()
     * @model
     * @generated
     */
    String getDescription();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getDescription <em>Description</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Description</em>' attribute.
     * @see #getDescription()
     * @generated
     */
    void setDescription(String value);

    /**
     * Returns the value of the '<em><b>Latitude</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Latitude</em>' attribute.
     * @see #setLatitude(double)
     * @see fds_model.Fds_modelPackage#getGroundStation_Latitude()
     * @model
     * @generated
     */
    double getLatitude();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getLatitude <em>Latitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Latitude</em>' attribute.
     * @see #getLatitude()
     * @generated
     */
    void setLatitude(double value);

    /**
     * Returns the value of the '<em><b>Longitude</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Longitude</em>' attribute.
     * @see #setLongitude(double)
     * @see fds_model.Fds_modelPackage#getGroundStation_Longitude()
     * @model
     * @generated
     */
    double getLongitude();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getLongitude <em>Longitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Longitude</em>' attribute.
     * @see #getLongitude()
     * @generated
     */
    void setLongitude(double value);

    /**
     * Returns the value of the '<em><b>Altitude</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Altitude</em>' attribute.
     * @see #setAltitude(double)
     * @see fds_model.Fds_modelPackage#getGroundStation_Altitude()
     * @model
     * @generated
     */
    double getAltitude();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getAltitude <em>Altitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Altitude</em>' attribute.
     * @see #getAltitude()
     * @generated
     */
    void setAltitude(double value);

    /**
     * Returns the value of the '<em><b>Minimum Elevation</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Minimum Elevation</em>' attribute.
     * @see #setMinimumElevation(double)
     * @see fds_model.Fds_modelPackage#getGroundStation_MinimumElevation()
     * @model
     * @generated
     */
    double getMinimumElevation();

    /**
     * Sets the value of the '{@link fds_model.GroundStation#getMinimumElevation <em>Minimum Elevation</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Minimum Elevation</em>' attribute.
     * @see #getMinimumElevation()
     * @generated
     */
    void setMinimumElevation(double value);

    /**
     * Returns the value of the '<em><b>List Mask</b></em>' containment reference list.
     * The list contents are of type {@link fds_model.GroundStationMask}.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>List Mask</em>' containment reference list.
     * @see fds_model.Fds_modelPackage#getGroundStation_ListMask()
     * @model containment="true"
     * @generated
     */
    EList<GroundStationMask> getListMask();

} // GroundStation
