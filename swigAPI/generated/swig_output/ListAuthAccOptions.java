/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.sysfera.vishnu.api.vishnu.internal;

public class ListAuthAccOptions extends EObject {
  private long swigCPtr;

  public ListAuthAccOptions(long cPtr, boolean cMemoryOwn) {
    super(VISHNUJNI.ListAuthAccOptions_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  public static long getCPtr(ListAuthAccOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        VISHNUJNI.delete_ListAuthAccOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public ListAuthAccOptions() {
    this(VISHNUJNI.new_ListAuthAccOptions(), true);
  }

  public void _initialize() {
    VISHNUJNI.ListAuthAccOptions__initialize(swigCPtr, this);
  }

  public boolean isListAll() {
    return VISHNUJNI.ListAuthAccOptions_isListAll(swigCPtr, this);
  }

  public void setListAll(boolean _listAll) {
    VISHNUJNI.ListAuthAccOptions_setListAll(swigCPtr, this, _listAll);
  }

  public String getUserId() {
    return VISHNUJNI.ListAuthAccOptions_getUserId(swigCPtr, this);
  }

  public void setUserId(String _userId) {
    VISHNUJNI.ListAuthAccOptions_setUserId(swigCPtr, this, _userId);
  }

  public String getAuthSystemId() {
    return VISHNUJNI.ListAuthAccOptions_getAuthSystemId(swigCPtr, this);
  }

  public void setAuthSystemId(String _authSystemId) {
    VISHNUJNI.ListAuthAccOptions_setAuthSystemId(swigCPtr, this, _authSystemId);
  }

  public SWIGTYPE_p_ecorecpp__mapping__any eGet(int _featureID, boolean _resolve) {
    return new SWIGTYPE_p_ecorecpp__mapping__any(VISHNUJNI.ListAuthAccOptions_eGet(swigCPtr, this, _featureID, _resolve), true);
  }

  public void eSet(int _featureID, SWIGTYPE_p_ecorecpp__mapping__any _newValue) {
    VISHNUJNI.ListAuthAccOptions_eSet(swigCPtr, this, _featureID, SWIGTYPE_p_ecorecpp__mapping__any.getCPtr(_newValue));
  }

  public boolean eIsSet(int _featureID) {
    return VISHNUJNI.ListAuthAccOptions_eIsSet(swigCPtr, this, _featureID);
  }

  public void eUnset(int _featureID) {
    VISHNUJNI.ListAuthAccOptions_eUnset(swigCPtr, this, _featureID);
  }

  public SWIGTYPE_p_ecore__EClass _eClass() {
    long cPtr = VISHNUJNI.ListAuthAccOptions__eClass(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_ecore__EClass(cPtr, false);
  }

}
