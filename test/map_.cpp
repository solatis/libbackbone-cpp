
#include <stdint.h>
#include <string>
#include <assert.h>


#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>
#include <backbone++/map.hpp>
#include <backbone++/json.hpp>


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
   
   my_model model;
   model.set <my_model::keys::v> ("foo");

   backbone::map <int64_t, my_model> map;

   map.set (1, std::move (model));
   assert (map.get (1).get <my_model::keys::v> () == "foo");


   ciere::json::value json = 
      backbone::to_json (map);

   assert (json["1"]["v"] == "foo");

}
