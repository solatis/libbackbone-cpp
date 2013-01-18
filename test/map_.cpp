
#include <stdint.h>
#include <string>
#include <assert.h>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>
#include <backbone++/map.hpp>


struct my_model : public backbone::model <my_model>
{
   std::string  v;
   
   struct keys 
   {
      struct v;
   };   
};


BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   my_model,
   (std::string,  v, my_model::keys::v))


void
test_map ()
{
   my_model model;
   model.set <my_model::keys::v> ("foo");

   backbone::map <int64_t, my_model> map;

   map.add (1, std::move (model));
   assert (map.get (1).get <my_model::keys::v> () == "foo");
}

/*!
  Tests a map containing a map
 */
void
test_nested_map ()
{
   my_model model;
   model.set <my_model::keys::v> ("foo");

   backbone::map <int64_t, 
                  backbone::map <bool, my_model> > map;

   map.add (1, backbone::map <bool, my_model> ()).add (true, std::move (model));
   assert (map.get (1).get (true).get <my_model::keys::v> () == "foo");
}

int main ()
{   
   test_map ();
   test_nested_map ();
}
