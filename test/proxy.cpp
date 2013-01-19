
#include <functional>

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/collection.hpp>
#include <backbone++/model.hpp>
#include <backbone++/map.hpp>
#include <backbone++/proxy.hpp>


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

struct my_map : public backbone::map <int64_t, struct my_model>
{
};

struct my_collection : public backbone::collection <struct my_model>
{
};


struct prefetch_model : public backbone::proxy::prefetch <struct my_model>
{
   prefetch_model ()
      : backbone::proxy::prefetch <struct my_model> (
         std::bind (&prefetch_model::fetch_,
                    this))
      {
      }

   void
   fetch_ ()
      {
         this->set <keys::v> ("foo");
      }
};


struct prefetch_map : public backbone::proxy::prefetch <struct my_map>
{
   prefetch_map ()
      : backbone::proxy::prefetch <struct my_map> (
         std::bind (&prefetch_map::fetch_all_,
                    this))
      {
      }

   void
   fetch_all_ ()
      {
         struct my_model model;
         model.set <my_model::keys::v> ("foo");

         this->add (1, std::move (model));
      }


};

struct prefetch_collection : public backbone::proxy::prefetch <struct my_collection>
{
   prefetch_collection ()
      : backbone::proxy::prefetch <struct my_collection> (
         std::bind (&prefetch_collection::fetch_all_,
                    this))
      {
      }

   void
   fetch_all_ ()
      {
         struct my_model model;
         model.set <my_model::keys::v> ("foo");

         this->add (std::move (model));
      }


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
