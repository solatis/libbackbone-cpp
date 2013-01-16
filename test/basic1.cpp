
#include <stdint.h>
#include <string>
#include <assert.h>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <ciere/json/io.hpp>

#include <backbone++/model.hpp>
#include <backbone++/json.hpp>


struct nested_model : public backbone::model <nested_model>
{
   bool    a;
   double  b;
   int64_t c;
   
   struct keys 
   {
      struct a;
      struct b;
      struct c;
   };
   
};


BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   nested_model,
   (bool,    a, nested_model::keys::a)
   (double,  b, nested_model::keys::b)
   (int64_t, c, nested_model::keys::c))


struct my_model : public backbone::model <my_model>
{
   std::string  v;
   int16_t      w;
   int32_t      x;
   nested_model y;
   
   struct keys 
   {
      struct v;
      struct w;
      struct x;
      struct y;
   };
   
};

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   my_model,
   (std::string,  v, my_model::keys::v)
   (int16_t,      w, my_model::keys::w)
   (int32_t,      x, my_model::keys::x)
   (nested_model, y, my_model::keys::y))

int main ()
{
   nested_model nested;
   my_model     model;

   nested.set <decltype(nested)::keys::a> (true);
   nested.set <decltype(nested)::keys::b> (1.3);
   nested.set <decltype(nested)::keys::c> (3);

   model.set <decltype(model)::keys::v> ("foo");
   model.set <decltype(model)::keys::w> (1);
   model.set <decltype(model)::keys::x> (2);
   model.set <decltype(model)::keys::y> (nested);

   assert (model.get <decltype(model)::keys::v> () == "foo");
   assert (model.get <decltype(model)::keys::w> () == 1);
   assert (model.get <decltype(model)::keys::x> () == 2);

   std::cout << backbone::to_json (model) << std::endl;
}
