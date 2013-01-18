namespace backbone {

template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, bool data) 
{
   json_[key] = ciere::json::bool_t (data);
}


template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, int16_t data) 
{
   json_[key] = ciere::json::int_t (data);
}

template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, int32_t data) 
{
   json_[key] = ciere::json::int_t (data);
}

template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, int64_t data) 
{
   json_[key] = ciere::json::int_t (data);
}

template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, float data) 
{
   json_[key] = ciere::json::float_t (data);
}

template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, double data) 
{
   json_[key] = ciere::json::double_t (data);
}


template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, std::string const & data) 
{
   json_[key] = data;
}

template <typename Key, typename Value>
inline void
json_writer::operator () (Key const & key, Value & data) 
{
   json_[key] = to_json (data);
}


template <typename Key, typename Value, typename Signals>
static inline ciere::json::value
to_json (
   backbone::map <Key, Value, Signals> const & m)
{
   ciere::json::object_t ret;

   for (auto const & i : m.map_)
   {
      ret[boost::lexical_cast <std::string> (i.first)] = to_json (i.second);
   }

   return ret;
}

template <typename Value, typename Signals>
static inline ciere::json::value
to_json (
   backbone::collection <Value, Signals> const & c)
{
   ciere::json::array_t ret;

   for (auto const & i : c.collection_)
   {
      ret.push_back (to_json (i));
   }

   return ret;
}


template <typename Model>
static inline ciere::json::value
to_json (
   Model const & m)
{
   json_writer w;
   boost::fusion::for_each_struct (m, w);

   return w.json_;
}

};
