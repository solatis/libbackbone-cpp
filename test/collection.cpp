
#include <stdint.h>
#include <assert.h>
#include <string>
#include <vector>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>
#include <backbone++/collection.hpp>


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
test_collection ()
{
   my_model model;
   model.set <my_model::keys::v> ("foo");

   backbone::collection <my_model> collection;

   assert (collection.add (std::move (model)).get <my_model::keys::v> () == "foo");;

   assert (std::distance (collection.begin (),
                          collection.end ()) == 1);

   collection.erase (collection.begin ());

   assert (std::distance (collection.begin (),
                          collection.end ()) == 0);   
}

int main ()
{   
   test_collection ();
}
