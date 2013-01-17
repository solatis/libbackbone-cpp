namespace backbone {

template <typename Key, typename Value>
inline void 
map <Key, Value>::set (
   Key const &  key,
   Value &&     value)
{
   map_[key] = std::move (value);
}

template <typename Key, typename Value>
inline Value &
map <Key, Value>::get (
   Key const &     key)
{
   return map_.at(key);
}   

};
