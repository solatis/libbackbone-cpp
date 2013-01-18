/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once


#include "../collection/signals.hpp"

namespace backbone { namespace detail {  namespace map {

template <typename Key, typename Value>
struct signals : public detail::collection::signals <Value>
{
   boost::signal <void (Key const &)>   read_one;
};

}; }; };
