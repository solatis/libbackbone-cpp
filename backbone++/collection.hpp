/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <map>

#include "detail/observable.hpp"
#include "detail/collection/signals.hpp"

namespace backbone { 


/*!
  \brief Provides interface to a model
 */

template <typename Value, typename Signals = detail::collection::signals <Value> >
struct collection : public detail::observable <Signals>
{
   typedef collection <Value, Signals>                  base_type;

   typedef std::vector <Value>                          collection_type;
   typedef typename collection_type::iterator           iterator;
   typedef typename collection_type::const_iterator     const_iterator;

   Value &
   add (
      Value &&          value);

   void
   erase (
      iterator          pos);

   typename collection_type::iterator
   begin ();

   typename collection_type::iterator
   end ();

   collection_type     collection_;
};

};

#include "collection.inl"

