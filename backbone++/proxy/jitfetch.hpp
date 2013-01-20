/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

namespace backbone { namespace proxy {

/*!
  \brief Provides proxy interface to fetch model data Just-In-Time

  \par Concepts
  Base
 */
template <typename Base, typename Type = typename Base::base_type>
struct jitfetch
{
};

}; };

#include "../detail/proxy/jitfetch/model.hpp"
#include "../detail/proxy/jitfetch/map.hpp"
#include "../detail/proxy/jitfetch/collection.hpp"
