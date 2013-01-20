/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <functional>

#include "../../../model.hpp"

namespace backbone { namespace proxy {

template <typename Base, typename Derived, typename Signals>
struct jitfetch <Base, backbone::model <Derived, Signals> > : public Base
{
   bool fetched_;

   /*!
     \brief Constructor
    */
   jitfetch ()
      : fetched_ (false)
      {
         this->signals ().read.connect (
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
