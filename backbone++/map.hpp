/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <map>

namespace backbone { 


/*!
  \brief Provides interface to a model
 */

template <typename Key, typename Value>
struct map
{

   Value &
   get (
      Key const &       key);

   void
   set (
      Key const &       key,
      Value &&          value);



   std::map <Key, Value>        map_;

};

};

#include "map.inl"

