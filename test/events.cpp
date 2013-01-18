
#include <stdint.h>
#include <string>
#include <assert.h>

#include <boost/bind.hpp>
#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

#include <backbone++/model.hpp>
#include <backbone++/map.hpp>

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



void
test_model ()
{
   my_model     model;

   bool change_fired = false;
   bool read_fired = false;

   model.signals ().change.connect (
      [& change_fired] ()
      {
         change_fired = true;
      });

   model.signals ().read.connect (
      [& read_fired] ()
      {
         read_fired = true;
      });

   assert (change_fired == false);
   assert (read_fired == false);

   model.set <my_model::keys::v> ("foo");

   assert (change_fired == true);
   assert (read_fired == false);

   assert (model.get <my_model::keys::v> () == "foo");

   assert (change_fired == true);
   assert (read_fired == true);   
}

void
test_map ()
{
   my_model model;
   model.set <my_model::keys::v> ("foo");

   backbone::map <std::string, struct my_model> map;


   bool add_fired      = false;
   bool erase_fired   = false;
   bool read_all_fired = false;
   bool read_one_fired = false;

   map.signals ().add.connect (
      [& add_fired] (
         struct my_model & model)
      {
         add_fired = true;
      });

   map.signals ().erase.connect (
      [& erase_fired] (
         struct my_model & model)
      {
         erase_fired = true;
      });

   map.signals ().read_all.connect (
      [& read_all_fired] ()
      {
         read_all_fired = true;
      });

   map.signals ().read_one.connect (
      [& read_one_fired] (
         std::string const &    key)
      {
         read_one_fired = true;
      });

   assert (add_fired == false);
   assert (erase_fired == false);
   assert (read_all_fired == false);
   assert (read_one_fired == false);

   map.add ("wombat", std::move (model));

   assert (add_fired == true);
   assert (erase_fired == false);
   assert (read_all_fired == false);
   assert (read_one_fired == false);

   assert (map.get ("wombat").get <my_model::keys::v> () == "foo");

   assert (add_fired == true);
   assert (erase_fired == false);
   assert (read_all_fired == false);
   assert (read_one_fired == true);

   assert (std::distance (map.begin (), map.end ()) == 1);

   assert (add_fired == true);
   assert (erase_fired == false);
   assert (read_all_fired == true);
   assert (read_one_fired == true);

   map.erase ("wombat");
   assert (std::distance (map.begin (), map.end ()) == 0);

   assert (add_fired == true);
   assert (erase_fired == true);
   assert (read_all_fired == true);
   assert (read_one_fired == true);

}


int main ()
{
   test_model ();
   test_map ();

}
 
