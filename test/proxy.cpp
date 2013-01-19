
#include <functional>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/collection.hpp>
#include <backbone++/model.hpp>
#include <backbone++/map.hpp>
#include <backbone++/proxy.hpp>


struct model_impl 
   : public backbone::model <model_impl>
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
   model_impl,
   (std::string,  v, model_impl::keys::v))

struct map_impl 
   : public backbone::map <int64_t
                           , struct model_impl>
{
   void
   operator() ()
      {
         struct model_impl model;
         model.set <model_impl::keys::v> ("foo");

         this->add (1, std::move (model));
      }
};

struct collection_impl
   : public backbone::collection <struct model_impl>
{
   void
   operator() ()
      {
         struct model_impl model;
         model.set <model_impl::keys::v> ("foo");

         this->add (std::move (model));
      }
};


struct model 
   : public backbone::proxy::prefetch <model_impl>
{
};


struct map 
   : public backbone::proxy::prefetch <map_impl>
{
};

struct collection 
   : public backbone::proxy::prefetch <collection_impl>
{
};


void
test_prefetch ()
{
   map proxy_map;
   model proxy_model;
   collection proxy_collection;

   assert (proxy_model.v == "foo");
   assert (proxy_map.map_.at (1).v == "foo");
   assert (proxy_collection.collection_.begin ()->v == "foo");
}




int main ()
{
   test_prefetch ();
}
