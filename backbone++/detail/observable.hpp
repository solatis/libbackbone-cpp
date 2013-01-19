/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <memory>

#include <boost/fusion/include/at_key.hpp>

namespace backbone { namespace detail {


template <typename Signals>
struct observable
{

   observable ();

   template <typename Signal>
   void
   trigger (
      Signal &  sig);

   template <typename Signal, typename Value>
   void
   trigger (
      Signal &  sig,
      Value &   value);

   Signals &
   signals ();

   std::unique_ptr <Signals>    signals_;

};


}; };

#include "observable.inl"
