LDADD = -lboost_system -lboost_serialization -lboost_thread -lciere_json

if HAVE_DEBUG
LDADD += -llog4cxx
endif

check_PROGRAMS = \
	basic \
	nested \
	json

basic_SOURCES      	  = basic.cpp
nested_SOURCES      	  = nested.cpp
json_SOURCES      	  = json.cpp

TESTS= \
	basic \
	nested \
	json
