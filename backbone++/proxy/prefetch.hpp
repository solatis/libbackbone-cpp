/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

namespace backbone { namespace proxy {

/*!
  \brief Provides a proxy interface to prefetch model data as soon as an object is created


  \par Concepts
  \e Base: a specialization of either a backbone::model, backbone::map or backbone::collection, and
           requires operator() to be defined and to fetch all member data.

  \par Examples

  Initialize a model and let its members be fetched as soon as the get () function is called.


  
 */
template <typename Base, typename Type = typename Base::base_type>
struct prefetch
{
};

}; };

#include "../detail/proxy/prefetch/model.hpp"
#include "../detail/proxy/prefetch/map.hpp"
#include "../detail/proxy/prefetch/collection.hpp"
