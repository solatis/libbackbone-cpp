/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../../../model.hpp"

namespace backbone { namespace proxy {

template <typename Base, typename Derived, typename Signals>
struct prefetch <Base, backbone::model <Derived, Signals> > : public Base
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
