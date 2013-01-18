/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once


#include "../signals.hpp"

namespace backbone { namespace detail {  namespace collection {

template <typename Type>
struct signals : public detail::signals
{

   boost::signal <void (Type &)>        add;
   boost::signal <void (Type &)>        erase;
   boost::signal <void ()>              read_all;

};

}; }; };
