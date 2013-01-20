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


   /*!
     \brief Constructor
    */
   collection ()
      {
         this->trigger (
            this->signals ().construct);
      }

   Value &
   add (
      Value &&          value)
      {
         collection_.push_back (std::move (value));

         this->trigger (
            this->signals ().add, 
            *collection_.rbegin ());

         return *collection_.rbegin ();
      }

   void
   erase (
      iterator          pos)
      {
         this->trigger (
            this->signals ().erase,
            *pos);

         collection_.erase (pos);
      }

   typename collection_type::iterator
   begin ()
      {
         this->trigger (
            this->signals ().read_all);

         return collection_.begin ();         
      }

   typename collection_type::iterator
   end ()
      {
         this->trigger (
            this->signals ().read_all);

         return collection_.end ();
      }

   collection_type     collection_;
};

};

