
#include <stdint.h>
#include <string>
#include <assert.h>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>

struct my_model : public backbone::model <my_model>
{
   std::string  v;
   int16_t      w;
   int32_t      x;
   
   struct keys 
   {
      struct v;
      struct w;
      struct x;
   };
   
};

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   my_model,
   (std::string,  v, my_model::keys::v)
   (int16_t,      w, my_model::keys::w)
   (int32_t,      x, my_model::keys::x))

int main ()
{
   my_model     model;

   model.set <my_model::keys::v> ("foo");
   model.set <my_model::keys::w> (1);
   model.set <my_model::keys::x> (2);

   assert (model.get <my_model::keys::v> () == "foo");
   assert (model.get <my_model::keys::w> () == 1);
   assert (model.get <my_model::keys::x> () == 2);
}
