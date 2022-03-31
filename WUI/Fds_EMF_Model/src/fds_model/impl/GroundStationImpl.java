/**
 */
package fds_model.impl;

import fds_model.Fds_modelPackage;
import fds_model.GroundStation;
import fds_model.GroundStationMask;

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
 * An implementation of the model object '<em><b>Ground Station</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link fds_model.impl.GroundStationImpl#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getDescription <em>Description</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getLatitude <em>Latitude</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getLongitude <em>Longitude</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getAltitude <em>Altitude</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getMinimumElevation <em>Minimum Elevation</em>}</li>
 *   <li>{@link fds_model.impl.GroundStationImpl#getListMask <em>List Mask</em>}</li>
 * </ul>
 *
 * @generated
 */
public class GroundStationImpl extends MinimalEObjectImpl.Container implements GroundStation {
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
     * The default value of the '{@link #getDescription() <em>Description</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getDescription()
     * @generated
     * @ordered
     */
    protected static final String DESCRIPTION_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getDescription() <em>Description</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getDescription()
     * @generated
     * @ordered
     */
    protected String description = DESCRIPTION_EDEFAULT;

    /**
     * The default value of the '{@link #getLatitude() <em>Latitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getLatitude()
     * @generated
     * @ordered
     */
    protected static final double LATITUDE_EDEFAULT = 0.0;

    /**
     * The cached value of the '{@link #getLatitude() <em>Latitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getLatitude()
     * @generated
     * @ordered
     */
    protected double latitude = LATITUDE_EDEFAULT;

    /**
     * The default value of the '{@link #getLongitude() <em>Longitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getLongitude()
     * @generated
     * @ordered
     */
    protected static final double LONGITUDE_EDEFAULT = 0.0;

    /**
     * The cached value of the '{@link #getLongitude() <em>Longitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getLongitude()
     * @generated
     * @ordered
     */
    protected double longitude = LONGITUDE_EDEFAULT;

    /**
     * The default value of the '{@link #getAltitude() <em>Altitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getAltitude()
     * @generated
     * @ordered
     */
    protected static final double ALTITUDE_EDEFAULT = 0.0;

    /**
     * The cached value of the '{@link #getAltitude() <em>Altitude</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getAltitude()
     * @generated
     * @ordered
     */
    protected double altitude = ALTITUDE_EDEFAULT;

    /**
     * The default value of the '{@link #getMinimumElevation() <em>Minimum Elevation</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getMinimumElevation()
     * @generated
     * @ordered
     */
    protected static final double MINIMUM_ELEVATION_EDEFAULT = 0.0;

    /**
     * The cached value of the '{@link #getMinimumElevation() <em>Minimum Elevation</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getMinimumElevation()
     * @generated
     * @ordered
     */
    protected double minimumElevation = MINIMUM_ELEVATION_EDEFAULT;

    /**
     * The cached value of the '{@link #getListMask() <em>List Mask</em>}' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getListMask()
     * @generated
     * @ordered
     */
    protected EList<GroundStationMask> listMask;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected GroundStationImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return Fds_modelPackage.Literals.GROUND_STATION;
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__IDENTIFIER, oldIdentifier, identifier));
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__NAME, oldName, name));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getDescription() {
        return description;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setDescription(String newDescription) {
        String oldDescription = description;
        description = newDescription;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__DESCRIPTION, oldDescription, description));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public double getLatitude() {
        return latitude;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setLatitude(double newLatitude) {
        double oldLatitude = latitude;
        latitude = newLatitude;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__LATITUDE, oldLatitude, latitude));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public double getLongitude() {
        return longitude;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setLongitude(double newLongitude) {
        double oldLongitude = longitude;
        longitude = newLongitude;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__LONGITUDE, oldLongitude, longitude));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public double getAltitude() {
        return altitude;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setAltitude(double newAltitude) {
        double oldAltitude = altitude;
        altitude = newAltitude;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__ALTITUDE, oldAltitude, altitude));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public double getMinimumElevation() {
        return minimumElevation;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setMinimumElevation(double newMinimumElevation) {
        double oldMinimumElevation = minimumElevation;
        minimumElevation = newMinimumElevation;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.GROUND_STATION__MINIMUM_ELEVATION, oldMinimumElevation, minimumElevation));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EList<GroundStationMask> getListMask() {
        if (listMask == null) {
            listMask = new EObjectContainmentEList<GroundStationMask>(GroundStationMask.class, this, Fds_modelPackage.GROUND_STATION__LIST_MASK);
        }
        return listMask;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
        switch (featureID) {
            case Fds_modelPackage.GROUND_STATION__LIST_MASK:
                return ((InternalEList<?>)getListMask()).basicRemove(otherEnd, msgs);
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
            case Fds_modelPackage.GROUND_STATION__IDENTIFIER:
                return getIdentifier();
            case Fds_modelPackage.GROUND_STATION__NAME:
                return getName();
            case Fds_modelPackage.GROUND_STATION__DESCRIPTION:
                return getDescription();
            case Fds_modelPackage.GROUND_STATION__LATITUDE:
                return getLatitude();
            case Fds_modelPackage.GROUND_STATION__LONGITUDE:
                return getLongitude();
            case Fds_modelPackage.GROUND_STATION__ALTITUDE:
                return getAltitude();
            case Fds_modelPackage.GROUND_STATION__MINIMUM_ELEVATION:
                return getMinimumElevation();
            case Fds_modelPackage.GROUND_STATION__LIST_MASK:
                return getListMask();
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
            case Fds_modelPackage.GROUND_STATION__IDENTIFIER:
                setIdentifier((Integer)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__NAME:
                setName((String)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__DESCRIPTION:
                setDescription((String)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__LATITUDE:
                setLatitude((Double)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__LONGITUDE:
                setLongitude((Double)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__ALTITUDE:
                setAltitude((Double)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__MINIMUM_ELEVATION:
                setMinimumElevation((Double)newValue);
                return;
            case Fds_modelPackage.GROUND_STATION__LIST_MASK:
                getListMask().clear();
                getListMask().addAll((Collection<? extends GroundStationMask>)newValue);
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
            case Fds_modelPackage.GROUND_STATION__IDENTIFIER:
                setIdentifier(IDENTIFIER_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__NAME:
                setName(NAME_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__DESCRIPTION:
                setDescription(DESCRIPTION_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__LATITUDE:
                setLatitude(LATITUDE_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__LONGITUDE:
                setLongitude(LONGITUDE_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__ALTITUDE:
                setAltitude(ALTITUDE_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__MINIMUM_ELEVATION:
                setMinimumElevation(MINIMUM_ELEVATION_EDEFAULT);
                return;
            case Fds_modelPackage.GROUND_STATION__LIST_MASK:
                getListMask().clear();
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
            case Fds_modelPackage.GROUND_STATION__IDENTIFIER:
                return identifier != IDENTIFIER_EDEFAULT;
            case Fds_modelPackage.GROUND_STATION__NAME:
                return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
            case Fds_modelPackage.GROUND_STATION__DESCRIPTION:
                return DESCRIPTION_EDEFAULT == null ? description != null : !DESCRIPTION_EDEFAULT.equals(description);
            case Fds_modelPackage.GROUND_STATION__LATITUDE:
                return latitude != LATITUDE_EDEFAULT;
            case Fds_modelPackage.GROUND_STATION__LONGITUDE:
                return longitude != LONGITUDE_EDEFAULT;
            case Fds_modelPackage.GROUND_STATION__ALTITUDE:
                return altitude != ALTITUDE_EDEFAULT;
            case Fds_modelPackage.GROUND_STATION__MINIMUM_ELEVATION:
                return minimumElevation != MINIMUM_ELEVATION_EDEFAULT;
            case Fds_modelPackage.GROUND_STATION__LIST_MASK:
                return listMask != null && !listMask.isEmpty();
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
        result.append(", description: ");
        result.append(description);
        result.append(", latitude: ");
        result.append(latitude);
        result.append(", longitude: ");
        result.append(longitude);
        result.append(", altitude: ");
        result.append(altitude);
        result.append(", minimumElevation: ");
        result.append(minimumElevation);
        result.append(')');
        return result.toString();
    }

} //GroundStationImpl
