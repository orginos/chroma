// -*- C++ -*-
// $Id: gaugebc.h,v 2.3 2006-03-13 05:16:20 edwards Exp $
/*! @file
 * @brief Gauge boundary conditions
 */

#ifndef __gaugebc_h__
#define __gaugebc_h__

#include "chromabase.h"
#include "io/enum_io/enum_gaugebc_io.h"


namespace Chroma
{
  //! Base class for all gauge action boundary conditions
  /*! @ingroup gaugebc
   *
   *  NOTE: this class is specifically using LatticeColorMatrix, but
   *  probably should generalized to a template. The point is that coordinates
   *  and momenta within HMC are general. The FermAct classes have a param
   *  type  (T,P) = (type of fermion, type of conjugate momenta) the latter
   *  part used in the deriv stuff. Here, the "zero" could be on any conjugate
   *  momenta. The modify, however, is usually on the coordinates which
   *  is often the LatticeColorMatrx. The FermBC has a template param
   *  for the fermion type that is used in the "modifyF", but is fixed 
   *  for a LatticeColorMatrix in the "modifyU".
   */
  class GaugeBC
  {
  public:
    //! Virtual destructor to help with cleanup;
    virtual ~GaugeBC() {}

    //! Apply the BC onto the U fields in place
    virtual void modify(multi1d<LatticeColorMatrix>& u) const = 0;

    //! Zero some gauge-like field in place on the masked links
    /*! 
     * This routine may be dropped in favor of zero of a template type,
     * namely the conjugate momenta.
     */
    virtual void zero(multi1d<LatticeColorMatrix>& p) const = 0;

    //! Says if there are fixed links within the lattice
    virtual bool nontrivialP() const = 0;
  };


}

#endif
