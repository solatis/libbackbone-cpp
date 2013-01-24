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
  \param obj A Backbone data structure, which can be a backbone::model, 
             backbone::collection or backbone::map
 */
template <typename Type>
static ciere::json::value
to_json (
   Type const & obj)
{
   return detail::json::writer::type_deduce <Type const>::call (obj);
}

};
