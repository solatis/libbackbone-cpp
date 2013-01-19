LDADD = -lboost_system -lboost_serialization -lboost_thread -lciere_json -lboost_signals

if HAVE_DEBUG
LDADD += -llog4cxx
endif

check_PROGRAMS = \
	basic \
	nested \
	map_ \
	json \
	events \
	collection \
	proxy

basic_SOURCES      	  = basic.cpp
nested_SOURCES      	  = nested.cpp
map__SOURCES      	  = map_.cpp
json_SOURCES      	  = json.cpp
events_SOURCES      	  = events.cpp
collection_SOURCES        = collection.cpp
proxy_SOURCES    	  = proxy.cpp

TESTS= \
	basic \
	nested \
	map_ \
	json \
	events \
	collection \
	proxy
