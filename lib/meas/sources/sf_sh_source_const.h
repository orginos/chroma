// -*- C++ -*-
// $Id: sf_sh_source_const.h,v 3.1 2007-08-27 20:04:04 uid3790 Exp $
/*! \file
 *  \brief Shell source construction for Schroedinger Functional
 */

#ifndef __sf_sh_source_const_h__
#define __sf_sh_source_const_h__

#include "meas/sources/source_construction.h"
#include "io/xml_group_reader.h"
#include "io/enum_io/enum_plusminus_io.h"

namespace Chroma
{

  //! Name and registration
  /*! @ingroup sources */
  namespace SFShellQuarkSourceConstEnv
  {
    extern const std::string name;
    bool registerAll();


    //! Point source parameters
    /*! @ingroup sources */
    struct Params
    {
      Params();
      Params(XMLReader& in, const std::string& path);
      void writeXML(XMLWriter& out, const std::string& path) const;
    
      GroupXML_t       quark_smearing;       /*!< xml string holding smearing params */
      GroupXML_t       quark_displacement;   /*!< displacement xml */
      GroupXML_t       link_smearing;        /*!< link smearing xml */

      PlusMinus        direction;            /*!< direction for decay */

      int              j_decay;              /*!< Decay direction */
      multi1d<int>     t_srce;               /*!< source location */
    };


    //! Shell source construction for Schroedinger Functional
    /*! @ingroup sources
     *
     * Create a shell quark source
     */
    template<typename T>
    class SourceConst : public QuarkSourceConstruction<T>
    {
    public:
      //! Full constructor
      SourceConst(const Params& p) : params(p) {}

      //! Construct the source
      T operator()(const multi1d<LatticeColorMatrix>& u) const;

    private:
      //! Hide partial constructor
      SourceConst() {}

    private:
      Params  params;   /*!< source params */
    };

  }  // end namespace SFShellQuarkSourceConstEnv

}  // end namespace Chroma


#endif
