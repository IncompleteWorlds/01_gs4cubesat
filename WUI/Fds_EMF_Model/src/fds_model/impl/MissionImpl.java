/**
 */
package fds_model.impl;

import fds_model.Fds_modelPackage;
import fds_model.Mission;
import fds_model.Satellite;

import java.util.Collection;
import java.util.Date;

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
 * An implementation of the model object '<em><b>Mission</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link fds_model.impl.MissionImpl#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getDescription <em>Description</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getCountry <em>Country</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getOwner <em>Owner</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getCreationDate <em>Creation Date</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getPhoneNumber <em>Phone Number</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getEmail <em>Email</em>}</li>
 *   <li>{@link fds_model.impl.MissionImpl#getListSatellite <em>List Satellite</em>}</li>
 * </ul>
 *
 * @generated
 */
public class MissionImpl extends MinimalEObjectImpl.Container implements Mission {
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
     * The default value of the '{@link #getCountry() <em>Country</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getCountry()
     * @generated
     * @ordered
     */
    protected static final String COUNTRY_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getCountry() <em>Country</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getCountry()
     * @generated
     * @ordered
     */
    protected String country = COUNTRY_EDEFAULT;

    /**
     * The default value of the '{@link #getOwner() <em>Owner</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getOwner()
     * @generated
     * @ordered
     */
    protected static final String OWNER_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getOwner() <em>Owner</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getOwner()
     * @generated
     * @ordered
     */
    protected String owner = OWNER_EDEFAULT;

    /**
     * The default value of the '{@link #getCreationDate() <em>Creation Date</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getCreationDate()
     * @generated
     * @ordered
     */
    protected static final Date CREATION_DATE_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getCreationDate() <em>Creation Date</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getCreationDate()
     * @generated
     * @ordered
     */
    protected Date creationDate = CREATION_DATE_EDEFAULT;

    /**
     * The default value of the '{@link #getPhoneNumber() <em>Phone Number</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getPhoneNumber()
     * @generated
     * @ordered
     */
    protected static final String PHONE_NUMBER_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getPhoneNumber() <em>Phone Number</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getPhoneNumber()
     * @generated
     * @ordered
     */
    protected String phoneNumber = PHONE_NUMBER_EDEFAULT;

    /**
     * The default value of the '{@link #getEmail() <em>Email</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getEmail()
     * @generated
     * @ordered
     */
    protected static final String EMAIL_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getEmail() <em>Email</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getEmail()
     * @generated
     * @ordered
     */
    protected String email = EMAIL_EDEFAULT;

    /**
     * The cached value of the '{@link #getListSatellite() <em>List Satellite</em>}' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getListSatellite()
     * @generated
     * @ordered
     */
    protected EList<Satellite> listSatellite;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected MissionImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return Fds_modelPackage.Literals.MISSION;
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__IDENTIFIER, oldIdentifier, identifier));
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__NAME, oldName, name));
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__DESCRIPTION, oldDescription, description));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getCountry() {
        return country;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setCountry(String newCountry) {
        String oldCountry = country;
        country = newCountry;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__COUNTRY, oldCountry, country));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getOwner() {
        return owner;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setOwner(String newOwner) {
        String oldOwner = owner;
        owner = newOwner;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__OWNER, oldOwner, owner));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Date getCreationDate() {
        return creationDate;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setCreationDate(Date newCreationDate) {
        Date oldCreationDate = creationDate;
        creationDate = newCreationDate;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__CREATION_DATE, oldCreationDate, creationDate));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getPhoneNumber() {
        return phoneNumber;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setPhoneNumber(String newPhoneNumber) {
        String oldPhoneNumber = phoneNumber;
        phoneNumber = newPhoneNumber;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__PHONE_NUMBER, oldPhoneNumber, phoneNumber));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getEmail() {
        return email;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setEmail(String newEmail) {
        String oldEmail = email;
        email = newEmail;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.MISSION__EMAIL, oldEmail, email));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EList<Satellite> getListSatellite() {
        if (listSatellite == null) {
            listSatellite = new EObjectContainmentEList<Satellite>(Satellite.class, this, Fds_modelPackage.MISSION__LIST_SATELLITE);
        }
        return listSatellite;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
        switch (featureID) {
            case Fds_modelPackage.MISSION__LIST_SATELLITE:
                return ((InternalEList<?>)getListSatellite()).basicRemove(otherEnd, msgs);
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
            case Fds_modelPackage.MISSION__IDENTIFIER:
                return getIdentifier();
            case Fds_modelPackage.MISSION__NAME:
                return getName();
            case Fds_modelPackage.MISSION__DESCRIPTION:
                return getDescription();
            case Fds_modelPackage.MISSION__COUNTRY:
                return getCountry();
            case Fds_modelPackage.MISSION__OWNER:
                return getOwner();
            case Fds_modelPackage.MISSION__CREATION_DATE:
                return getCreationDate();
            case Fds_modelPackage.MISSION__PHONE_NUMBER:
                return getPhoneNumber();
            case Fds_modelPackage.MISSION__EMAIL:
                return getEmail();
            case Fds_modelPackage.MISSION__LIST_SATELLITE:
                return getListSatellite();
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
            case Fds_modelPackage.MISSION__IDENTIFIER:
                setIdentifier((Integer)newValue);
                return;
            case Fds_modelPackage.MISSION__NAME:
                setName((String)newValue);
                return;
            case Fds_modelPackage.MISSION__DESCRIPTION:
                setDescription((String)newValue);
                return;
            case Fds_modelPackage.MISSION__COUNTRY:
                setCountry((String)newValue);
                return;
            case Fds_modelPackage.MISSION__OWNER:
                setOwner((String)newValue);
                return;
            case Fds_modelPackage.MISSION__CREATION_DATE:
                setCreationDate((Date)newValue);
                return;
            case Fds_modelPackage.MISSION__PHONE_NUMBER:
                setPhoneNumber((String)newValue);
                return;
            case Fds_modelPackage.MISSION__EMAIL:
                setEmail((String)newValue);
                return;
            case Fds_modelPackage.MISSION__LIST_SATELLITE:
                getListSatellite().clear();
                getListSatellite().addAll((Collection<? extends Satellite>)newValue);
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
            case Fds_modelPackage.MISSION__IDENTIFIER:
                setIdentifier(IDENTIFIER_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__NAME:
                setName(NAME_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__DESCRIPTION:
                setDescription(DESCRIPTION_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__COUNTRY:
                setCountry(COUNTRY_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__OWNER:
                setOwner(OWNER_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__CREATION_DATE:
                setCreationDate(CREATION_DATE_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__PHONE_NUMBER:
                setPhoneNumber(PHONE_NUMBER_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__EMAIL:
                setEmail(EMAIL_EDEFAULT);
                return;
            case Fds_modelPackage.MISSION__LIST_SATELLITE:
                getListSatellite().clear();
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
            case Fds_modelPackage.MISSION__IDENTIFIER:
                return identifier != IDENTIFIER_EDEFAULT;
            case Fds_modelPackage.MISSION__NAME:
                return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
            case Fds_modelPackage.MISSION__DESCRIPTION:
                return DESCRIPTION_EDEFAULT == null ? description != null : !DESCRIPTION_EDEFAULT.equals(description);
            case Fds_modelPackage.MISSION__COUNTRY:
                return COUNTRY_EDEFAULT == null ? country != null : !COUNTRY_EDEFAULT.equals(country);
            case Fds_modelPackage.MISSION__OWNER:
                return OWNER_EDEFAULT == null ? owner != null : !OWNER_EDEFAULT.equals(owner);
            case Fds_modelPackage.MISSION__CREATION_DATE:
                return CREATION_DATE_EDEFAULT == null ? creationDate != null : !CREATION_DATE_EDEFAULT.equals(creationDate);
            case Fds_modelPackage.MISSION__PHONE_NUMBER:
                return PHONE_NUMBER_EDEFAULT == null ? phoneNumber != null : !PHONE_NUMBER_EDEFAULT.equals(phoneNumber);
            case Fds_modelPackage.MISSION__EMAIL:
                return EMAIL_EDEFAULT == null ? email != null : !EMAIL_EDEFAULT.equals(email);
            case Fds_modelPackage.MISSION__LIST_SATELLITE:
                return listSatellite != null && !listSatellite.isEmpty();
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
        result.append(", country: ");
        result.append(country);
        result.append(", owner: ");
        result.append(owner);
        result.append(", creationDate: ");
        result.append(creationDate);
        result.append(", phoneNumber: ");
        result.append(phoneNumber);
        result.append(", email: ");
        result.append(email);
        result.append(')');
        return result.toString();
    }

} //MissionImpl
