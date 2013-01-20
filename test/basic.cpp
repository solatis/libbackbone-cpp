
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

struct person : public backbone::model <person>
{
   std::string  name;
   int16_t      age;

   struct keys
   {
      struct name;
      struct age;
   };
};


BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   person,
   (std::string,  name, person::keys::name)
   (int16_t,      age,  person::keys::age))

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   my_model,
   (std::string,  v, my_model::keys::v)
   (int16_t,      w, my_model::keys::w)
   (int32_t,      x, my_model::keys::x))

int main ()
{
   person     person;

   assert (person.get <person::keys::name> ().empty () == true);
   
   person.set <person::keys::name> ("Bill Gates");
   person.set <person::keys::age> (57);

   assert (person.get <person::keys::name> () == "Bill Gates");
   assert (person.get <person::keys::age> () == 57);

   person.set <person::keys::name> (123); //! Fails, backbone is strongly typed

   model.set <my_model::keys::v> ("foo");
   model.set <my_model::keys::w> (1);
   model.set <my_model::keys::x> (2);

   assert (model.get <my_model::keys::v> () == "foo");
   assert (model.get <my_model::keys::w> () == 1);
   assert (model.get <my_model::keys::x> () == 2);
}
