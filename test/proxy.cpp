
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

typedef backbone::proxy::prefetch <model_impl> prefetch_model;
typedef backbone::proxy::jitfetch <model_impl> jitfetch_model;

BOOST_FUSION_ADAPT_ASSOC_STRUCT(
   model_impl,
   (std::string,  v, model_impl::keys::v))

struct map_impl 
   : public backbone::map <int64_t
                           , prefetch_model>
{
   void
   operator() ()
      {
         prefetch_model model;
         model.set <model_impl::keys::v> ("foo");

         this->add (1, std::move (model));
      }

   void
   operator() (int64_t const & key)
      {
         prefetch_model model;
         model.set <model_impl::keys::v> ("foo");

         this->add (key, std::move (model));
      }

};

typedef backbone::proxy::prefetch <map_impl> prefetch_map;
typedef backbone::proxy::jitfetch <map_impl> jitfetch_map;

struct collection_impl
   : public backbone::collection <prefetch_model>
{
   void
   operator() ()
      {
         prefetch_model model;
         model.set <model_impl::keys::v> ("foo");

         this->add (std::move (model));
      }
};

typedef backbone::proxy::prefetch <collection_impl> prefetch_collection;
typedef backbone::proxy::jitfetch <collection_impl> jitfetch_collection;

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


void
test_jitfetch ()
{
   jitfetch_map proxy_map;
   jitfetch_model proxy_model;
   jitfetch_collection proxy_collection;

   assert (proxy_model.v.empty () == true);
   assert (proxy_map.map_.empty () == true);
   assert (proxy_collection.collection_.empty () == true);

   assert (proxy_model.get <jitfetch_model::keys::v> () == "foo");
   assert (proxy_map.get (1).get <jitfetch_model::keys::v> () == "foo");
   assert (proxy_collection.begin ()->get <jitfetch_model::keys::v> () == "foo");
}



int main ()
{
   test_prefetch ();
   test_jitfetch ();
}
