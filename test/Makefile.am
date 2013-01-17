LDADD = -lboost_system -lboost_serialization -lboost_thread -lciere_json -lboost_signals

if HAVE_DEBUG
LDADD += -llog4cxx
endif

check_PROGRAMS = \
	basic \
	nested \
	map_ \
	json \
	events

basic_SOURCES      	  = basic.cpp
nested_SOURCES      	  = nested.cpp
map__SOURCES      	  = map_.cpp
json_SOURCES      	  = json.cpp
events_SOURCES      	  = events.cpp

TESTS= \
	basic \
	nested \
	map_ \
	json \
	events
