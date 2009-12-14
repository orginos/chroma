// -*- C++ -*-
/*! \file
 * \brief Inline task to read an object from a named buffer
 *
 * Named object writing
 */

#ifndef __inline_read_subset_vectors_memory_h__
#define __inline_read_subset_vectors_memory_h__

#include "chromabase.h"
#include "meas/inline/abs_inline_measurement.h"
#include "util/ferm/map_obj/map_obj_disk.h"
#include "util/ferm/map_obj/map_obj_memory.h"
namespace Chroma 
{ 
  /*! \ingroup inlineio */
  namespace InlineReadSubsetVectorsMemoryEnv 
  {
    extern const std::string name;
    bool registerAll();
  }

  //! Parameter structure
  /*! \ingroup inlineio */
  struct InlineReadSubsetVectorsMemoryParams 
  {
    unsigned int frequency;

    struct File {
      std::string   file_name;
    } file;

    struct NamedObject_t {
      std::string   object_id;
    } named_obj;

    InlineReadSubsetVectorsMemoryParams(XMLReader& xml_in, const std::string& path);
    
  };

  void read(XMLReader& xml_in, const std::string& path, InlineReadSubsetVectorsMemoryParams& p) ;

  void write(XMLWriter& xml_out, const std::string& path, const InlineReadSubsetVectorsMemoryParams& p);


  //! Inline writing of memory objects
  /*! \ingroup inlineio */
  class InlineReadSubsetVectorsMemory : public AbsInlineMeasurement 
  {
  public:
    ~InlineReadSubsetVectorsMemory() {}
    InlineReadSubsetVectorsMemory(const InlineReadSubsetVectorsMemoryParams& p) : params(p) {}
    InlineReadSubsetVectorsMemory(const InlineReadSubsetVectorsMemory& p) : params(p.params) {}

    unsigned long getFrequency(void) const {return params.frequency;}

    //! Do the writing
    void operator()(const unsigned long update_no,
		    XMLWriter& xml_out); 

  private:
    InlineReadSubsetVectorsMemoryParams params;
  };

};

#endif