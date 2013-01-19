/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../../../collection.hpp"

namespace backbone { namespace proxy {

template <typename Base, typename Value, typename Signals>
struct prefetch <Base, backbone::collection <Value, Signals> > : public Base
{
   /*!
     \brief Constructor
    */
   prefetch (
      std::function <void ()> callback)
      {
         callback ();
      }
};


}; };
