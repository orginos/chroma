// -*- C++ -*-
// $Id: overlap_fermact_base_w.h,v 1.1 2003-12-04 02:56:53 edwards Exp $
/*! \file
 *  \brief Base class for unpreconditioned overlap-like fermion actions
 */

#ifndef __overlap_fermact_base_w_h__
#define __overlap_fermact_base_w_h__

#include "fermact.h"

using namespace QDP;

//! Base class for unpreconditioned overlap-like fermion actions
/*! \ingroup fermact
 *
 * Unpreconditioned overlap-like fermion action. 
 * The conventions used here are specified in some Nucl.Phys.B. article
 * by Edwards,Heller, Narayanan
 *
 * NOTE: for now we assume the kernel is a fund. rep. fermion type,
 * but that is not necessary
 */

class OverlapFermActBase : public UnprecWilsonTypeFermAct<LatticeFermion>
{
public:
  //! Return the quark mass
  virtual Real quark_mass() const = 0;

  //! Does this object really satisfy the Ginsparg-Wilson relation?
  virtual bool isChiral() const = 0;

  //! Redefine quark propagator routine for 4D fermions
  /*! 
   * NOTE: the arg ConectState MUST be in the original base because C++ 
   * requires it for a virtual func!
   * The function will have to downcast to get the correct state
   */
  void qprop(LatticeFermion& psi, 
	     const ConnectState& state, 
	     const LatticeFermion& chi, 
	     enum InvType invType,
	     const Real& RsdCG, 
	     int MaxCG, int& ncg_had) const;
};

#endif
