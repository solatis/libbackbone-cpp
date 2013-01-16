
namespace backbone {

template <typename Derived>
template <typename Key, typename Value>
inline void 
model <Derived>::set (
   Value const & value)
{
   boost::fusion::at_key <Key> (static_cast <Derived &> (*this)) = value;
}

template <typename Derived> 
template <typename Key>
inline typename boost::fusion::result_of::at_key <Derived, Key>::type &
model <Derived>::get ()
{
   return boost::fusion::at_key <Key> (static_cast <Derived &> (*this));
}   

};
