LDADD = -lboost_system -lboost_serialization -lboost_thread -lciere_json

if HAVE_DEBUG
LDADD += -llog4cxx
endif

check_PROGRAMS = \
	basic1 

basic1_SOURCES      	  = basic1.cpp

TESTS= \
	basic1 
