/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <ciere/json/value.hpp>

#include "../../json_fwd.hpp"


namespace backbone { namespace detail { namespace json { namespace writer {

/*!
  \brief Fallback option for "the rest", which cannot be converted directly
  to json and whose json object must be recursively generated.
*/
template <typename Value, class Enable = void>
struct type_deduce
{
   static ciere::json::value
   call (
      Value const &  data)
      {
         return backbone::to_json (data);
      }
};

/*!
  \brief Specialization for string types
 */
template <>
struct type_deduce <std::string const>
{
   static ciere::json::value
   call (
      std::string const & data)
      {
         return ciere::json::string_t (data);
      }
};

/*!
  \brief Specialization for boolean types
 */
template <>
struct type_deduce <bool const>
{
   static ciere::json::value
   call (
      bool data)
      {
         return ciere::json::bool_t (data);
      }
};

/*!
  \brief Specialization for integer types
*/
template <typename Value>
struct type_deduce <Value, typename std::enable_if <std::is_integral <Value>::value>::type>
{
   static ciere::json::value
   call (
      Value const &  data)
      {
         return ciere::json::int_t (data);
      }
};


/*!
  \brief Specialization for floating point types
*/
template <typename Value>
struct type_deduce <Value, typename std::enable_if <std::is_floating_point <Value>::value>::type>
{
   static ciere::json::value
   call (
      Value const &  data)
      {
         return ciere::json::double_t (data);
      }
};






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
      Value & data)
      {
         json_[key] = 
            type_deduce <Value>::call (data);
      }
};



}; }; }; };
