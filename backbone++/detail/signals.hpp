/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/signals.hpp>

namespace backbone { namespace detail { 

struct signals
{
   boost::signal <void ()>  all;
   boost::signal <void ()>  construct;
   boost::signal <void ()>  read;
   boost::signal <void ()>  change;
};

}; };
