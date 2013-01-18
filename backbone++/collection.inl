namespace backbone {



template <typename Value, typename Signals>
inline Value &
collection <Value, Signals>::add (
   Value &&     value)
{
   collection_.push_back (std::move (value));

   this->trigger (
      this->signals ().add, 
      *collection_.rbegin ());

   return *collection_.rbegin ();
}


template <typename Value, typename Signals>
inline void
collection <Value, Signals>::erase (
   iterator     pos)
{
   this->trigger (
      this->signals ().erase,
      *pos);

   collection_.erase (pos);
}

template <typename Value, typename Signals>
inline typename collection <Value, Signals>::iterator
collection <Value, Signals>::begin ()
{
   this->trigger (
      this->signals ().read_all);

   return collection_.begin ();
}

template <typename Value, typename Signals>
inline typename collection <Value, Signals>::iterator
collection <Value, Signals>::end ()
{
   this->trigger (
      this->signals ().read_all);

   return collection_.end ();
}


};
