// -*- C++ -*-
// $Id: rot_colvec.h,v 1.2 2003-12-06 21:59:22 edwards Exp $
/*! \file
 *  \brief Rotate a color vector
 */

#ifndef __rot_colvec_h__
#define __rot_colvec_h__

//! Rotate a color vector
/*!
 * \ingroup gfix
 *
 * Rotate a color vector into the form where the component with index
 * s_index is real and the component with larger index are zero.
 * We do this by a series of SU(2) gauge rotations.
 *
 * \param g          Gauge transformation                              (Write)
 * \param psi        Input color vector field                          (Read)
 * \param chi        Output color vector field                         (Write)
 * \param s_index    color index                                       (Read)
 */

void rot_colvec(LatticeColorMatrix& g, 
		const LatticeColorVector& psi,
		LatticeColorVector& chi,
		int s_index);

#endif
