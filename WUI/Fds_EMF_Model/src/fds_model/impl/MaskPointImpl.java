/**
 */
package fds_model.impl;

import fds_model.Fds_modelPackage;
import fds_model.MaskPoint;

import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Mask Point</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link fds_model.impl.MaskPointImpl#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.impl.MaskPointImpl#getAzimuth <em>Azimuth</em>}</li>
 *   <li>{@link fds_model.impl.MaskPointImpl#getElevation <em>Elevation</em>}</li>
 * </ul>
 *
 * @generated
 */
public class MaskPointImpl extends MinimalEObjectImpl.Container implements MaskPoint {
    /**
     * The default value of the '{@link #getIdentifier() <em>Identifier</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getIdentifier()
     * @generated
     * @ordered
     */
    protected static final int IDENTIFIER_EDEFAULT = 0;

    /**
     * The cached value of the '{@link #getIdentifier() <em>Identifier</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getIdentifier()
     * @generated
     * @ordered
     */
    protected int identifier = IDENTIFIER_EDEFAULT;

    /**
     * The default value of the '{@link #getAzimuth() <em>Azimuth</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getAzimuth()
     * @generated
     * @ordered
     */
    protected static final double AZIMUTH_EDEFAULT = 0.0;

    /**
     * The cached value of the '{@link #getAzimuth() <em>Azimuth</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getAzimuth()
     * @generated
     * @ordered
     */
    protected double azimuth = AZIMUTH_EDEFAULT;

    /**
     * The default value of the '{@link #getElevation() <em>Elevation</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getElevation()
     * @generated
     * @ordered
     */
    protected static final double ELEVATION_EDEFAULT = 0.0;

    /**
     * The cached value of the '{@link #getElevation() <em>Elevation</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getElevation()
     * @generated
     * @ordered
     */
    protected double elevation = ELEVATION_EDEFAULT;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected MaskPointImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return Fds_modelPackage.Literals.MASK_POINT;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public int getIdentifier() {
        return identifier;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setIdentifier(int newIdentifier) {
        int oldIdentifier = identifier;
        identifier = newIdentifier;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MASK_POINT__IDENTIFIER, oldIdentifier, identifier));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public double getAzimuth() {
        return azimuth;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setAzimuth(double newAzimuth) {
        double oldAzimuth = azimuth;
        azimuth = newAzimuth;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MASK_POINT__AZIMUTH, oldAzimuth, azimuth));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public double getElevation() {
        return elevation;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setElevation(double newElevation) {
        double oldElevation = elevation;
        elevation = newElevation;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MASK_POINT__ELEVATION, oldElevation, elevation));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public Object eGet(int featureID, boolean resolve, boolean coreType) {
        switch (featureID) {
            case Fds_modelPackage.MASK_POINT__IDENTIFIER:
                return getIdentifier();
            case Fds_modelPackage.MASK_POINT__AZIMUTH:
                return getAzimuth();
            case Fds_modelPackage.MASK_POINT__ELEVATION:
                return getElevation();
        }
        return super.eGet(featureID, resolve, coreType);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public void eSet(int featureID, Object newValue) {
        switch (featureID) {
            case Fds_modelPackage.MASK_POINT__IDENTIFIER:
                setIdentifier((Integer)newValue);
                return;
            case Fds_modelPackage.MASK_POINT__AZIMUTH:
                setAzimuth((Double)newValue);
                return;
            case Fds_modelPackage.MASK_POINT__ELEVATION:
                setElevation((Double)newValue);
                return;
        }
        super.eSet(featureID, newValue);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public void eUnset(int featureID) {
        switch (featureID) {
            case Fds_modelPackage.MASK_POINT__IDENTIFIER:
                setIdentifier(IDENTIFIER_EDEFAULT);
                return;
            case Fds_modelPackage.MASK_POINT__AZIMUTH:
                setAzimuth(AZIMUTH_EDEFAULT);
                return;
            case Fds_modelPackage.MASK_POINT__ELEVATION:
                setElevation(ELEVATION_EDEFAULT);
                return;
        }
        super.eUnset(featureID);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public boolean eIsSet(int featureID) {
        switch (featureID) {
            case Fds_modelPackage.MASK_POINT__IDENTIFIER:
                return identifier != IDENTIFIER_EDEFAULT;
            case Fds_modelPackage.MASK_POINT__AZIMUTH:
                return azimuth != AZIMUTH_EDEFAULT;
            case Fds_modelPackage.MASK_POINT__ELEVATION:
                return elevation != ELEVATION_EDEFAULT;
        }
        return super.eIsSet(featureID);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public String toString() {
        if (eIsProxy()) return super.toString();

        StringBuilder result = new StringBuilder(super.toString());
        result.append(" (identifier: ");
        result.append(identifier);
        result.append(", azimuth: ");
        result.append(azimuth);
        result.append(", elevation: ");
        result.append(elevation);
        result.append(')');
        return result.toString();
    }

} //MaskPointImpl
