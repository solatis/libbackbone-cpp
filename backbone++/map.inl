namespace backbone {

template <typename Key, typename Value, typename Signals>
inline Value &
map <Key, Value, Signals>::add (
   Key const &  key,
   Value &&     value)
{
   map_[key] = std::move (value);

   this->trigger (
      this->signals ().add, 
      map_[key]);

   return map_.at (key);
}

template <typename Key, typename Value, typename Signals>
inline Value &
map <Key, Value, Signals>::get (
   Key const &     key)
{
   this->trigger (
      this->signals ().read_one,
      key);

   return map_.at(key);
}

template <typename Key, typename Value, typename Signals>
inline void
map <Key, Value, Signals>::erase (
   Key const &     key)
{
   this->trigger (
      this->signals ().erase,
      map_.at (key));

   map_.erase (key);
}



template <typename Key, typename Value, typename Signals>
inline typename map <Key, Value, Signals>::map_type::iterator
map <Key, Value, Signals>::begin ()
{
   this->trigger (
      this->signals ().read_all);

   return map_.begin ();
}

template <typename Key, typename Value, typename Signals>
inline typename map <Key, Value, Signals>::map_type::iterator
map <Key, Value, Signals>::end ()
{
   this->trigger (
      this->signals ().read_all);

   return map_.end ();
}

};
