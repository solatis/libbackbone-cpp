/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <map>

#include "detail/observable.hpp"
#include "detail/map/signals.hpp"

namespace backbone { 


/*!
  \brief Provides interface to a model
 */

template <typename Key, typename Value, typename Signals = detail::map::signals <Key, Value> >
struct map : public detail::observable <Signals>
{
   typedef std::map <Key, Value>                map_type;
   typedef typename map_type::iterator          iterator;
   typedef typename map_type::const_iterator    const_iterator;

   Value &
   add (
      Key const &       key,
      Value &&          value);

   void
   erase (
      Key const &       key);

   Value &
   get (
      Key const &       key);


   typename map_type::iterator
   begin ();

   typename map_type::iterator
   end ();

   map_type     map_;
};

};

#include "map.inl"

