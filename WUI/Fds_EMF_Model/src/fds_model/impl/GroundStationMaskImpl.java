/**
 */
package fds_model.impl;

import fds_model.Fds_modelPackage;
import fds_model.GroundStationMask;
import fds_model.MaskPoint;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Ground Station Mask</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link fds_model.impl.GroundStationMaskImpl#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationMaskImpl#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationMaskImpl#getListPoint <em>List Point</em>}</li>
 * </ul>
 *
 * @generated
 */
public class GroundStationMaskImpl extends MinimalEObjectImpl.Container implements GroundStationMask {
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
     * The default value of the '{@link #getName() <em>Name</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getName()
     * @generated
     * @ordered
     */
    protected static final String NAME_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getName() <em>Name</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getName()
     * @generated
     * @ordered
     */
    protected String name = NAME_EDEFAULT;

    /**
     * The cached value of the '{@link #getListPoint() <em>List Point</em>}' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getListPoint()
     * @generated
     * @ordered
     */
    protected EList<MaskPoint> listPoint;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected GroundStationMaskImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return Fds_modelPackage.Literals.GROUND_STATION_MASK;
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION_MASK__IDENTIFIER, oldIdentifier, identifier));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getName() {
        return name;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setName(String newName) {
        String oldName = name;
        name = newName;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION_MASK__NAME, oldName, name));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EList<MaskPoint> getListPoint() {
        if (listPoint == null) {
            listPoint = new EObjectContainmentEList<MaskPoint>(MaskPoint.class, this, Fds_modelPackage.GROUND_STATION_MASK__LIST_POINT);
        }
        return listPoint;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
        switch (featureID) {
            case Fds_modelPackage.GROUND_STATION_MASK__LIST_POINT:
                return ((InternalEList<?>)getListPoint()).basicRemove(otherEnd, msgs);
        }
        return super.eInverseRemove(otherEnd, featureID, msgs);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public Object eGet(int featureID, boolean resolve, boolean coreType) {
        switch (featureID) {
            case Fds_modelPackage.GROUND_STATION_MASK__IDENTIFIER:
                return getIdentifier();
            case Fds_modelPackage.GROUND_STATION_MASK__NAME:
                return getName();
            case Fds_modelPackage.GROUND_STATION_MASK__LIST_POINT:
                return getListPoint();
        }
        return super.eGet(featureID, resolve, coreType);
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @SuppressWarnings("unchecked")
    @Override
    public void eSet(int featureID, Object newValue) {
        switch (featureID) {
            case Fds_modelPackage.GROUND_STATION_MASK__IDENTIFIER:
                setIdentifier((Integer)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION_MASK__NAME:
                setName((String)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION_MASK__LIST_POINT:
                getListPoint().clear();
                getListPoint().addAll((Collection<? extends MaskPoint>)newValue);
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
            case Fds_modelPackage.GROUND_STATION_MASK__IDENTIFIER:
                setIdentifier(IDENTIFIER_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION_MASK__NAME:
                setName(NAME_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION_MASK__LIST_POINT:
                getListPoint().clear();
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
            case Fds_modelPackage.GROUND_STATION_MASK__IDENTIFIER:
                return identifier != IDENTIFIER_EDEFAULT;
            case Fds_modelPackage.GROUND_STATION_MASK__NAME:
                return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
            case Fds_modelPackage.GROUND_STATION_MASK__LIST_POINT:
                return listPoint != null && !listPoint.isEmpty();
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
        result.append(", name: ");
        result.append(name);
        result.append(')');
        return result.toString();
    }

} //GroundStationMaskImpl
