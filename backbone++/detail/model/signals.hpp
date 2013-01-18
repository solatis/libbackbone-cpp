/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../signals.hpp"

namespace backbone { namespace detail { namespace model {

struct signals : public detail::signals
{
   boost::signal <void ()>  read;
   boost::signal <void ()>  change;
};

}; }; };
