
namespace backbone {


template <typename Derived, typename Signals>
template <typename Key, typename Value>
inline void 
model <Derived, Signals>::set (
   Value && value)
{
   boost::fusion::at_key <Key> (static_cast <Derived &> (*this)) = std::move (value);

   this->trigger (detail::observable <Signals>::signals ().set);
}

template <typename Derived, typename Signals> 
template <typename Key>
inline typename boost::fusion::result_of::at_key <Derived, Key>::type &
model <Derived, Signals>::get ()
{
   this->trigger (detail::observable <Signals>::signals ().get);

   return boost::fusion::at_key <Key> (static_cast <Derived &> (*this));
}   

};
