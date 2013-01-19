
#include <functional>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/collection.hpp>
#include <backbone++/model.hpp>
#include <backbone++/map.hpp>
#include <backbone++/proxy.hpp>


struct my_model 
   : public backbone::model <my_model>
{
   std::string  v;   

   struct keys 
   {
      struct v;
   };   

   void
   operator() ()
      {
         this->set <keys::v> ("foo");
      }

};

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   my_model,
   (std::string,  v, my_model::keys::v))

struct my_map 
   : public backbone::map <int64_t
                           , struct my_model>
{
   void
   operator() ()
      {
         struct my_model model;
         model.set <my_model::keys::v> ("foo");

         this->add (1, std::move (model));
      }
};

struct my_collection 
   : public backbone::collection <struct my_model>
{
   void
   operator() ()
      {
         struct my_model model;
         model.set <my_model::keys::v> ("foo");

         this->add (std::move (model));
      }
};


struct prefetch_model 
   : public backbone::proxy::prefetch <my_model>
{
};


struct prefetch_map 
   : public backbone::proxy::prefetch <my_map>
{
};

struct prefetch_collection 
   : public backbone::proxy::prefetch <my_collection>
{
};


void
test_prefetch ()
{
   prefetch_map proxy_map;
   prefetch_model proxy_model;
   prefetch_collection proxy_collection;

   assert (proxy_model.v == "foo");
   assert (proxy_map.map_.at (1).v == "foo");
   assert (proxy_collection.collection_.begin ()->v == "foo");
}




int main ()
{
   test_prefetch ();
}
