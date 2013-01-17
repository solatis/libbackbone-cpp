
#include <stdint.h>
#include <string>
#include <assert.h>

#include <boost/bind.hpp>
#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>

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

int main ()
{
   my_model     model;

   bool set_fired = false;
   bool get_fired = false;

   model.signals ().set.connect (
      [& set_fired] ()
      {
         set_fired = true;
      });

   model.signals ().get.connect (
      [& get_fired] ()
      {
         get_fired = true;
      });

   assert (set_fired == false);
   assert (get_fired == false);

   model.set <my_model::keys::v> ("foo");

   assert (set_fired == true);
   assert (get_fired == false);

   assert (model.get <my_model::keys::v> () == "foo");

   assert (set_fired == true);
   assert (get_fired == true);
}
 
