/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../../../collection.hpp"

namespace backbone { namespace proxy {

template <typename Derived, typename Value, typename Signals>
struct prefetch <Derived, backbone::collection <Value, Signals> > : public Derived
{
   /*!
     \brief Constructor
    */
   prefetch ()
      {
         static_cast <Derived &> (*this)();
      }
};

}; };
