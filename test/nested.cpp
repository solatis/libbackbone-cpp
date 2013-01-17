
#include <stdint.h>
#include <string>
#include <assert.h>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>

struct nested_model : public backbone::model <nested_model>
{
   bool    a;
   double  b;
   float   c;
   int64_t d;
   
   struct keys 
   {
      struct a;
      struct b;
      struct c;
      struct d;
   };
   
};


BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   nested_model,
   (bool,    a, nested_model::keys::a)
   (double,  b, nested_model::keys::b)
   (float,   c, nested_model::keys::c)
   (int64_t, d, nested_model::keys::d))


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
   nested.set <decltype(nested)::keys::b> (1.5);
   nested.set <decltype(nested)::keys::c> (3.5);
   nested.set <decltype(nested)::keys::d> (4);

   model.set <my_model::keys::v> ("foo");
   model.set <my_model::keys::w> (1);
   model.set <my_model::keys::x> (2);
   model.set <my_model::keys::y> (nested);

   assert (model.get <my_model::keys::y> ().get <nested_model::keys::a> () == true);
   assert (model.get <my_model::keys::y> ().get <nested_model::keys::b> () == 1.5);
   assert (model.get <my_model::keys::y> ().get <nested_model::keys::c> () == 3.5);
   assert (model.get <my_model::keys::y> ().get <nested_model::keys::d> () == 4);
}
