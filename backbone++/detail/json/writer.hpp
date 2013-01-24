/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <ciere/json/value.hpp>

namespace backbone { namespace detail { namespace json { namespace writer {



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
      Value const & data);
};



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
         detail::json::writer::json_writer w;

         /*!
           When an error occurs by the following call, it means you are trying to convert
           a class to JSON that is not properly fusion-adapted and is not a native JSON data
           type.
          */
         boost::fusion::for_each_struct (data, w);

         return w.json_;
      }
};

/*!
  \brief Specialization for collection types
 */
template <typename Collection>
struct type_deduce <Collection, typename std::enable_if <std::is_base_of <backbone::collection <typename Collection::value_type, typename Collection::signals_type>, Collection>::value>::type>
{
   static ciere::json::value
   call (
      Collection const & data)
      {
         ciere::json::array_t ret;
         for (auto const & i : data.collection_)
         {
            ret.push_back (type_deduce <typename Collection::value_type>::call (i));
         }

         return ret;
      }
};



/*!
  \brief Specialization for map types
 */
template <typename Map>
struct type_deduce <Map, typename std::enable_if <std::is_base_of <backbone::map <typename Map::key_type, typename Map::value_type, typename Map::signals_type>, Map>::value>::type>
{
   static ciere::json::value
   call (
      Map const & data)
      {
         ciere::json::object_t ret;
         for (auto const & i : data.map_)
         {
            ret[boost::lexical_cast <std::string> (i.first)] = 
               type_deduce <typename Map::value_type>::call (i.second);
         }

         return ret;
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
  \brief Specialization for string types
 */
template <>
struct type_deduce <std::string>
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
  \brief Specialization for boolean types
 */
template <>
struct type_deduce <bool>
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

template <typename Key, typename Value>
inline void
json_writer::operator() (
   Key const & key,     
   Value const & data)
{
   json_[key] = 
      type_deduce <Value const>::call (data);
}



}; }; }; };
