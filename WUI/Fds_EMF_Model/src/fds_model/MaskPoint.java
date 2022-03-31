/**
 */
package fds_model;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Mask Point</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link fds_model.MaskPoint#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.MaskPoint#getAzimuth <em>Azimuth</em>}</li>
 *   <li>{@link fds_model.MaskPoint#getElevation <em>Elevation</em>}</li>
 * </ul>
 *
 * @see fds_model.Fds_modelPackage#getMaskPoint()
 * @model
 * @generated
 */
public interface MaskPoint extends EObject {
    /**
     * Returns the value of the '<em><b>Identifier</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Identifier</em>' attribute.
     * @see #setIdentifier(int)
     * @see fds_model.Fds_modelPackage#getMaskPoint_Identifier()
     * @model
     * @generated
     */
    int getIdentifier();

    /**
     * Sets the value of the '{@link fds_model.MaskPoint#getIdentifier <em>Identifier</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Identifier</em>' attribute.
     * @see #getIdentifier()
     * @generated
     */
    void setIdentifier(int value);

    /**
     * Returns the value of the '<em><b>Azimuth</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Azimuth</em>' attribute.
     * @see #setAzimuth(double)
     * @see fds_model.Fds_modelPackage#getMaskPoint_Azimuth()
     * @model
     * @generated
     */
    double getAzimuth();

    /**
     * Sets the value of the '{@link fds_model.MaskPoint#getAzimuth <em>Azimuth</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Azimuth</em>' attribute.
     * @see #getAzimuth()
     * @generated
     */
    void setAzimuth(double value);

    /**
     * Returns the value of the '<em><b>Elevation</b></em>' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @return the value of the '<em>Elevation</em>' attribute.
     * @see #setElevation(double)
     * @see fds_model.Fds_modelPackage#getMaskPoint_Elevation()
     * @model
     * @generated
     */
    double getElevation();

    /**
     * Sets the value of the '{@link fds_model.MaskPoint#getElevation <em>Elevation</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @param value the new value of the '<em>Elevation</em>' attribute.
     * @see #getElevation()
     * @generated
     */
    void setElevation(double value);

} // MaskPoint
