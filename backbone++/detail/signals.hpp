/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/signals.hpp>

namespace backbone { namespace detail { 

struct signals
{
   boost::signal <void ()>  all;
};

}; };
