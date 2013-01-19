/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../../../map.hpp"

namespace backbone { namespace proxy {

template <typename Derived, typename Key, typename Value, typename Signals>
struct prefetch <Derived, backbone::map <Key, Value, Signals> > : public Derived
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
