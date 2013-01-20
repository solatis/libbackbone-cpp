/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <set>

#include "../../../map.hpp"

namespace backbone { namespace proxy {

template <typename Derived, typename Key, typename Value, typename Signals>
struct jitfetch <Derived, backbone::map <Key, Value, Signals> > : public Derived
{
   bool fetched_all_;
   std::set <Key> fetched_;

   /*!
     \brief Constructor
    */
   jitfetch ()
      : fetched_all_ ()
      {
         this->signals ().read_all.connect (
            [this] ()
            {
               if (this->fetched_all_ == false)
               {
                  this->fetched_all_ = true;
                  (*this)();
               }
            });

         this->signals ().read_one.connect (
            [this] (Key const & key)
            {
               if (fetched_all_ == false
                   && fetched_.find (key) == fetched_.end ())
               {
                  fetched_.insert (key);
                  (*this)(key);
               }
            });
      }

};


}; };
