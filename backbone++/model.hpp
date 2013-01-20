/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/signal.hpp>
#include <boost/fusion/include/at_key.hpp>

#include "detail/model/signals.hpp"
#include "detail/observable.hpp"

namespace backbone { 


/*!
  \brief Provides interface to a model
 */

template <typename Derived, typename Signals = detail::model::signals>
struct model : public detail::observable <Signals>
{
   typedef model <Derived, Signals>     base_type;

   model ()
      {
         this->trigger (this->signals ().construct);
      }

   template <typename Key, typename Value> 
   void set (Value && value)
      {
         boost::fusion::at_key <Key> (static_cast <Derived &> (*this)) = std::move (value);

         this->trigger (this->signals ().change);
      }

   template <typename Key>
   typename boost::fusion::result_of::at_key <Derived, Key>::type &
   get ()
      {
         this->trigger (this->signals ().read);

         return boost::fusion::at_key <Key> (static_cast <Derived &> (*this));
      }
};

};
