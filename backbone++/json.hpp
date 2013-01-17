/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>

#include <ciere/json/value.hpp>

#include "detail/support/fusion/for_each_struct.hpp"

namespace backbone { 


/*!
  \brief Implements to_json conversion of Backbone models
 */

struct json_writer
{   

   ciere::json::value json_;

   template <typename Key, typename Value = bool>
   void
   operator () (Key const & key, bool data);

   template <typename Key, typename Value = int16_t>
   void
   operator () (Key const & key, int16_t data);

   template <typename Key, typename Value = int32_t>
   void
   operator () (Key const & key, int32_t data);

   template <typename Key, typename Value = int64_t>
   void
   operator () (Key const & key, int64_t data);


   template <typename Key, typename Value = float>
   void
   operator () (Key const & key, float data);


   template <typename Key, typename Value = double>
   void
   operator () (Key const & key, double data);


   template <typename Key, typename Value = std::string>
   void
   operator () (Key const & key, std::string const & data);


   template <typename Key, typename Value>
   void
   operator () (Key const & key, Value & data);

};


template <typename Model>
static ciere::json::value
to_json (
   Model const & m);

};

#include "json.inl"
