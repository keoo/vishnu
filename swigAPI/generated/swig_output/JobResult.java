/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.sysfera.vishnu.api.vishnu.internal;

public class JobResult extends EObject {
  private long swigCPtr;

  public JobResult(long cPtr, boolean cMemoryOwn) {
    super(VISHNUJNI.JobResult_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  public static long getCPtr(JobResult obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        VISHNUJNI.delete_JobResult(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public JobResult() {
    this(VISHNUJNI.new_JobResult(), true);
  }

  public void _initialize() {
    VISHNUJNI.JobResult__initialize(swigCPtr, this);
  }

  public String getJobId() {
    return VISHNUJNI.JobResult_getJobId(swigCPtr, this);
  }

  public void setJobId(String _jobId) {
    VISHNUJNI.JobResult_setJobId(swigCPtr, this, _jobId);
  }

  public String getOutputPath() {
    return VISHNUJNI.JobResult_getOutputPath(swigCPtr, this);
  }

  public void setOutputPath(String _outputPath) {
    VISHNUJNI.JobResult_setOutputPath(swigCPtr, this, _outputPath);
  }

  public String getErrorPath() {
    return VISHNUJNI.JobResult_getErrorPath(swigCPtr, this);
  }

  public void setErrorPath(String _errorPath) {
    VISHNUJNI.JobResult_setErrorPath(swigCPtr, this, _errorPath);
  }

  public String getOutputDir() {
    return VISHNUJNI.JobResult_getOutputDir(swigCPtr, this);
  }

  public void setOutputDir(String _outputDir) {
    VISHNUJNI.JobResult_setOutputDir(swigCPtr, this, _outputDir);
  }

  public SWIGTYPE_p_ecorecpp__mapping__any eGet(int _featureID, boolean _resolve) {
    return new SWIGTYPE_p_ecorecpp__mapping__any(VISHNUJNI.JobResult_eGet(swigCPtr, this, _featureID, _resolve), true);
  }

  public void eSet(int _featureID, SWIGTYPE_p_ecorecpp__mapping__any _newValue) {
    VISHNUJNI.JobResult_eSet(swigCPtr, this, _featureID, SWIGTYPE_p_ecorecpp__mapping__any.getCPtr(_newValue));
  }

  public boolean eIsSet(int _featureID) {
    return VISHNUJNI.JobResult_eIsSet(swigCPtr, this, _featureID);
  }

  public void eUnset(int _featureID) {
    VISHNUJNI.JobResult_eUnset(swigCPtr, this, _featureID);
  }

  public SWIGTYPE_p_ecore__EClass _eClass() {
    long cPtr = VISHNUJNI.JobResult__eClass(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_ecore__EClass(cPtr, false);
  }

}
