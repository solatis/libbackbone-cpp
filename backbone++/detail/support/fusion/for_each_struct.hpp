/*!
  Copyright (c) 2012, Jeroen Habraken, all rights reserved.
 */

#pragma once

#include <boost/fusion/include/at_c.hpp>
#include <boost/fusion/include/size.hpp>
#include <boost/fusion/adapted/struct/detail/extension.hpp>

namespace boost { namespace fusion
{
    namespace detail
    {
        template <int First, int Last>
        struct for_each_struct
        {
            template <typename Sequence, typename F>
            static inline void
            call(Sequence const & seq, F & f)
            {
                f(extension::struct_member_name<Sequence, First>::call(), at_c<First>(seq));
                for_each_struct<First + 1, Last>::call(seq, f);
            }
        };

        template <int Last>
        struct for_each_struct<Last, Last>
        {
            template <typename Sequence, typename F>
            static inline void
            call(Sequence const & seq, F  & f)
            {
            }
        };
    }

    namespace traits
    {

    }

    namespace result_of
    {
        template <typename Sequence, typename F>
        struct for_each_attribute
        {
            typedef void type;
        };
    }

    template <typename Sequence, typename F>
    inline
    typename
        enable_if<
            is_same<
                typename traits::tag_of<Sequence>::type
              , assoc_struct_tag
            >
          , void
        >::type
    for_each_struct(Sequence & seq, F & f)
    {
        detail::for_each_struct<
            0 // mpl::int_<0>
          , result_of::size<Sequence>::value
        >::call(seq, f);
    }
} }
