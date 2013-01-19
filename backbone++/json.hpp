/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/lexical_cast.hpp>
#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>

#include <ciere/json/value.hpp>

#include "map.hpp"
#include "collection.hpp"

#include "detail/support/fusion/for_each_struct.hpp"
#include "detail/json/writer.hpp"

namespace backbone {

template <typename Model>
static ciere::json::value
to_json (
   Model const & m);

template <typename Key, typename Value, typename Signals>
static ciere::json::value
to_json (
   backbone::map <Key, Value, Signals> const & m);

template <typename Value, typename Signals>
static ciere::json::value
to_json (
   backbone::collection <Value, Signals> const & c);


/*!
  \brief Redirects to our detail::json::writer::type_deduction framework
         to convert a certain fusion key/value to json.
 */
struct json_writer
{   
   ciere::json::value json_;

   template <typename Key, typename Value>
   void
   operator () (
      Key const & key, 
      Value & data);
};

};

#include "json.inl"
