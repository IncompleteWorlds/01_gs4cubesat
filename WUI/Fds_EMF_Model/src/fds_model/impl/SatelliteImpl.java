/**
 */
package fds_model.impl;

import fds_model.Fds_modelPackage;
import fds_model.Satellite;
import fds_model.Subsystem;

import java.util.Collection;
import java.util.Date;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Satellite</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link fds_model.impl.SatelliteImpl#getIdentifier <em>Identifier</em>}</li>
 *   <li>{@link fds_model.impl.SatelliteImpl#getName <em>Name</em>}</li>
 *   <li>{@link fds_model.impl.SatelliteImpl#getDescription <em>Description</em>}</li>
 *   <li>{@link fds_model.impl.SatelliteImpl#getCode <em>Code</em>}</li>
 *   <li>{@link fds_model.impl.SatelliteImpl#getLaunchDate <em>Launch Date</em>}</li>
 *   <li>{@link fds_model.impl.SatelliteImpl#getAdmin <em>Admin</em>}</li>
 *   <li>{@link fds_model.impl.SatelliteImpl#getListSubsystem <em>List Subsystem</em>}</li>
 * </ul>
 *
 * @generated
 */
public class SatelliteImpl extends MinimalEObjectImpl.Container implements Satellite {
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
     * The default value of the '{@link #getCode() <em>Code</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getCode()
     * @generated
     * @ordered
     */
    protected static final String CODE_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getCode() <em>Code</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getCode()
     * @generated
     * @ordered
     */
    protected String code = CODE_EDEFAULT;

    /**
     * The default value of the '{@link #getLaunchDate() <em>Launch Date</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getLaunchDate()
     * @generated
     * @ordered
     */
    protected static final Date LAUNCH_DATE_EDEFAULT = null;

    /**
     * The cached value of the '{@link #getLaunchDate() <em>Launch Date</em>}' attribute.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getLaunchDate()
     * @generated
     * @ordered
     */
    protected Date launchDate = LAUNCH_DATE_EDEFAULT;

    /**
     * The cached value of the '{@link #getAdmin() <em>Admin</em>}' containment reference.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getAdmin()
     * @generated
     * @ordered
     */
    protected EObject admin;

    /**
     * The cached value of the '{@link #getListSubsystem() <em>List Subsystem</em>}' containment reference list.
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @see #getListSubsystem()
     * @generated
     * @ordered
     */
    protected EList<Subsystem> listSubsystem;

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    protected SatelliteImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return Fds_modelPackage.Literals.SATELLITE;
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__IDENTIFIER, oldIdentifier, identifier));
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__NAME, oldName, name));
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
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__DESCRIPTION, oldDescription, description));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public String getCode() {
        return code;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setCode(String newCode) {
        String oldCode = code;
        code = newCode;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__CODE, oldCode, code));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public Date getLaunchDate() {
        return launchDate;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setLaunchDate(Date newLaunchDate) {
        Date oldLaunchDate = launchDate;
        launchDate = newLaunchDate;
        if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__LAUNCH_DATE, oldLaunchDate, launchDate));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EObject getAdmin() {
        return admin;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public NotificationChain basicSetAdmin(EObject newAdmin, NotificationChain msgs) {
        EObject oldAdmin = admin;
        admin = newAdmin;
        if (eNotificationRequired()) {
            ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__ADMIN, oldAdmin, newAdmin);
            if (msgs == null) msgs = notification; else msgs.add(notification);
        }
        return msgs;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public void setAdmin(EObject newAdmin) {
        if (newAdmin != admin) {
            NotificationChain msgs = null;
            if (admin != null)
                msgs = ((InternalEObject)admin).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - Fds_modelPackage.SATELLITE__ADMIN, null, msgs);
            if (newAdmin != null)
                msgs = ((InternalEObject)newAdmin).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - Fds_modelPackage.SATELLITE__ADMIN, null, msgs);
            msgs = basicSetAdmin(newAdmin, msgs);
            if (msgs != null) msgs.dispatch();
        }
        else if (eNotificationRequired())
            eNotify(new ENotificationImpl(this, Notification.SET, Fds_modelPackage.SATELLITE__ADMIN, newAdmin, newAdmin));
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    public EList<Subsystem> getListSubsystem() {
        if (listSubsystem == null) {
            listSubsystem = new EObjectContainmentEList<Subsystem>(Subsystem.class, this, Fds_modelPackage.SATELLITE__LIST_SUBSYSTEM);
        }
        return listSubsystem;
    }

    /**
     * <!-- begin-user-doc -->
     * <!-- end-user-doc -->
     * @generated
     */
    @Override
    public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
        switch (featureID) {
            case Fds_modelPackage.SATELLITE__ADMIN:
                return basicSetAdmin(null, msgs);
            case Fds_modelPackage.SATELLITE__LIST_SUBSYSTEM:
                return ((InternalEList<?>)getListSubsystem()).basicRemove(otherEnd, msgs);
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
            case Fds_modelPackage.SATELLITE__IDENTIFIER:
                return getIdentifier();
            case Fds_modelPackage.SATELLITE__NAME:
                return getName();
            case Fds_modelPackage.SATELLITE__DESCRIPTION:
                return getDescription();
            case Fds_modelPackage.SATELLITE__CODE:
                return getCode();
            case Fds_modelPackage.SATELLITE__LAUNCH_DATE:
                return getLaunchDate();
            case Fds_modelPackage.SATELLITE__ADMIN:
                return getAdmin();
            case Fds_modelPackage.SATELLITE__LIST_SUBSYSTEM:
                return getListSubsystem();
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
            case Fds_modelPackage.SATELLITE__IDENTIFIER:
                setIdentifier((Integer)newValue);
                return;
            case Fds_modelPackage.SATELLITE__NAME:
                setName((String)newValue);
                return;
            case Fds_modelPackage.SATELLITE__DESCRIPTION:
                setDescription((String)newValue);
                return;
            case Fds_modelPackage.SATELLITE__CODE:
                setCode((String)newValue);
                return;
            case Fds_modelPackage.SATELLITE__LAUNCH_DATE:
                setLaunchDate((Date)newValue);
                return;
            case Fds_modelPackage.SATELLITE__ADMIN:
                setAdmin((EObject)newValue);
                return;
            case Fds_modelPackage.SATELLITE__LIST_SUBSYSTEM:
                getListSubsystem().clear();
                getListSubsystem().addAll((Collection<? extends Subsystem>)newValue);
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
            case Fds_modelPackage.SATELLITE__IDENTIFIER:
                setIdentifier(IDENTIFIER_EDEFAULT);
                return;
            case Fds_modelPackage.SATELLITE__NAME:
                setName(NAME_EDEFAULT);
                return;
            case Fds_modelPackage.SATELLITE__DESCRIPTION:
                setDescription(DESCRIPTION_EDEFAULT);
                return;
            case Fds_modelPackage.SATELLITE__CODE:
                setCode(CODE_EDEFAULT);
                return;
            case Fds_modelPackage.SATELLITE__LAUNCH_DATE:
                setLaunchDate(LAUNCH_DATE_EDEFAULT);
                return;
            case Fds_modelPackage.SATELLITE__ADMIN:
                setAdmin((EObject)null);
                return;
            case Fds_modelPackage.SATELLITE__LIST_SUBSYSTEM:
                getListSubsystem().clear();
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
            case Fds_modelPackage.SATELLITE__IDENTIFIER:
                return identifier != IDENTIFIER_EDEFAULT;
            case Fds_modelPackage.SATELLITE__NAME:
                return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
            case Fds_modelPackage.SATELLITE__DESCRIPTION:
                return DESCRIPTION_EDEFAULT == null ? description != null : !DESCRIPTION_EDEFAULT.equals(description);
            case Fds_modelPackage.SATELLITE__CODE:
                return CODE_EDEFAULT == null ? code != null : !CODE_EDEFAULT.equals(code);
            case Fds_modelPackage.SATELLITE__LAUNCH_DATE:
                return LAUNCH_DATE_EDEFAULT == null ? launchDate != null : !LAUNCH_DATE_EDEFAULT.equals(launchDate);
            case Fds_modelPackage.SATELLITE__ADMIN:
                return admin != null;
            case Fds_modelPackage.SATELLITE__LIST_SUBSYSTEM:
                return listSubsystem != null && !listSubsystem.isEmpty();
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
        result.append(", code: ");
        result.append(code);
        result.append(", launchDate: ");
        result.append(launchDate);
        result.append(')');
        return result.toString();
    }

} //SatelliteImpl
