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


/*!
  \brief Converts a backbone data structure to JSON
  \param model Properly Fusion-adapted backbone::model structure
 */
template <typename Model>
static ciere::json::value
to_json (
   Model const & model);

/*!
  \brief Converts a backbone data structure to JSON
  \param map backbone::map instance
 */
template <typename Key, typename Value, typename Signals>
static ciere::json::value
to_json (
   backbone::map <Key, Value, Signals> const & map);

/*!
  \brief Converts a backbone data structure to JSON
  \param collection backbone::collection instance
 */
template <typename Value, typename Signals>
static ciere::json::value
to_json (
   backbone::collection <Value, Signals> const & collection);

};

#include "json.inl"
