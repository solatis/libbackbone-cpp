/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/fusion/include/at_key.hpp>

namespace backbone { 


/*!
  \brief Provides interface to a model
 */

template <typename Derived>
struct model
{

   template <typename Key, typename Value> 
   void set (Value const & value);

   template <typename Key>
   typename boost::fusion::result_of::at_key <Derived, Key>::type &
   get ();

};

};

#include "model.inl"