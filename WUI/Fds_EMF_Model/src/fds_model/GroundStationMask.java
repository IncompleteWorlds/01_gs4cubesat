/**
 */
package fds_model;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Ground Station Mask</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link fds_model.GroundStationMask#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.GroundStationMask#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.GroundStationMask#getListPoint <em>List Point</em>}</li>
 * </ul>
 *
 * @see fds_model.Fds_modelPackage#getGroundStationMask()
 * @model
 * @generated
 */
public interface GroundStationMask extends EObject {
    /**
     * Returns the value of the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Identifier</em>' attribute.
     * @see #setIdentifier(int)
     * @see fds_model.Fds_modelPackage#getGroundStationMask_Identifier()
     * @model
     * @generated
     */
    int getIdentifier();

    /**
     * Sets the value of the '{@link fds_model.GroundStationMask#getIdentifier <em>Identifier</em>}' attribute.
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
     * @see fds_model.Fds_modelPackage#getGroundStationMask_Name()
     * @model
     * @generated
     */
    String getName();

    /**
     * Sets the value of the '{@link fds_model.GroundStationMask#getName <em>Name</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Name</em>' attribute.
     * @see #getName()
     * @generated
     */
    void setName(String value);

    /**
     * Returns the value of the '<em><b>List Point</b></em>' containment reference list.
     * The list contents are of type {@link fds_model.MaskPoint}.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>List Point</em>' containment reference list.
     * @see fds_model.Fds_modelPackage#getGroundStationMask_ListPoint()
     * @model containment="true"
     * @generated
     */
    EList<MaskPoint> getListPoint();

} // GroundStationMask
