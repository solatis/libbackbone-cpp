/*!
  Copyright (c) 2012, Leon Mergen, all rights reserved.
 */

#pragma once

#include <boost/fusion/include/at_key.hpp>

namespace backbone { namespace detail {


template <typename Signals>
class observable
{
public:

   observable ();

   template <typename Signal>
   void
   trigger (
      Signal &  sig);

   Signals &
   signals ();

private:

private:

   std::unique_ptr <Signals>    signals_;


};


}; };

#include "observable.inl"
