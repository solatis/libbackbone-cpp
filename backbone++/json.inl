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
//   to_json <Value> (data);
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
