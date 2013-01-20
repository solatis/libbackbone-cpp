/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../../../collection.hpp"

namespace backbone { namespace proxy {

template <typename Derived, typename Value, typename Signals>
struct jitfetch <Derived, backbone::collection <Value, Signals> > : public Derived
{
   bool fetched_;
   /*!
     \brief Constructor
    */
   jitfetch ()
      : fetched_ (false)
      {
         this->signals ().read_all.connect (
            [this] ()
            {
               if (this->fetched_ == false)
               {
                  this->fetched_ = true;
                  (*this)();
               }
            });
      }
};

}; };
