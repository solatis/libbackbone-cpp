
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

struct prefetch_model 
   : public backbone::proxy::prefetch <model_impl>
{
};


struct map_impl 
   : public backbone::map <int64_t
                           , struct prefetch_model>
{
   void
   operator() ()
      {
         struct prefetch_model model;
         model.set <prefetch_model::keys::v> ("foo");

         this->add (1, std::move (model));
      }
};

struct prefetch_map 
   : public backbone::proxy::prefetch <map_impl>
{
};

struct collection_impl
   : public backbone::collection <struct prefetch_model>
{
   void
   operator() ()
      {
         struct prefetch_model model;
         model.set <prefetch_model::keys::v> ("foo");

         this->add (std::move (model));
      }
};

struct prefetch_collection 
   : public backbone::proxy::prefetch <collection_impl>
{
};


void
test_prefetch ()
{
   prefetch_map        map;
   prefetch_model      model;
   prefetch_collection collection;

   assert (model.v == "foo");
   assert (map.map_.at (1).v == "foo");
   assert (collection.collection_.begin ()->v == "foo");
}




int main ()
{
   test_prefetch ();
}
