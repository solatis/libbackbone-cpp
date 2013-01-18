/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include "../../model.hpp"

namespace backbone {

/*!
  \brief Provides interface to a model
 */

template <typename Derived, typename Signals = detail::signals>
struct model : public detail::observable <Signals>
{

   template <typename Key, typename Value> 
   void set (Value && value);

   template <typename Key>
   typename boost::fusion::result_of::at_key <Derived, Key>::type &
   get ();

};

};

#include "model.inl"
