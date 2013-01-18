/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <ciere/json/value.hpp>

#include "map.hpp"
#include "collection.hpp"

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

};
