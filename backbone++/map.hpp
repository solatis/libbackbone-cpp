/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <map>

#include "detail/observable.hpp"
#include "detail/map/signals.hpp"

namespace backbone {

/*!
  \brief Provides interface to a map
 */

template <typename Key, typename Value, typename Signals = detail::map::signals <Key, Value> >
struct map : public detail::observable <Signals>
{
   typedef map <Key, Value, Signals>            base_type;
   typedef std::map <Key, Value>                map_type;
   typedef typename map_type::iterator          iterator;

   /*!
     \brief Adds new key/value pair to the map
     \param key   The key to add
     \param value The value to add
     \returns Reference to the added value inside the map
    */
   Value &
   add (
      Key const &       key,
      Value &&          value)
      {
         map_[key] = std::move (value);

         this->trigger (
            this->signals ().add, 
            map_[key]);

         return map_.at (key);
      }

   /*!
     \brief Erases a key from the map
     \param key The key to erase
    */
   void
   erase (
      Key const &       key)
      {
         this->trigger (
            this->signals ().erase,
            map_.at (key));

         map_.erase (key);
      }

   /*!
     \brief Provides access to a value by key
     \param key The key to look up
     \returns Reference to the
    */
   Value &
   get (
      Key const &       key)
      {
         this->trigger (
            this->signals ().read_one,
            key);

         return map_.at(key);         
      }

   /*!
     \brief Provides iterator access to map
    */
   iterator
   begin ()
      {
         this->trigger (
            this->signals ().read_all);

         return map_.begin ();         
      }

   /*!
     \brief Provides iterator access to map
    */
   iterator
   end ()
      {
         this->trigger (
            this->signals ().read_all);

         return map_.end ();
      }

   map_type     map_;
};

};

