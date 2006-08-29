CXXFLAGS+=-Wall -fsigned-char `wx-config --cppflags`
CFLAGS+=-Wall -fsigned-char `wx-config --cppflags`
# -ansi -pedantic cause warnings from some compilers [wx uses long long]
LDFLAGS+=`wx-config --ldflags`
# STATICFLAGS=-Wl,-Bstatic
STATICFLAGS=-static
LIBS+=`wx-config --libs std,stc`
BINARY=torque-ide
INSTALL=install

ifeq ($(DEBUG), 1)
CXXFLAGS+=-g -Werror
endif


OBJ=../src/torqueideabout.o ../src/torqueideapp.o ../src/torqueideframe.o ../src/torqueideprefs.o ../src/torqueidestc.o

all: torqueide

torqueide: $(OBJ)
	$(CXX) $(LDFLAGS) -o ../$(BINARY) $(OBJ) $(LIBS)

clean:
	rm -f ../src/*.o core $(BINARY)

v: clean all
	valgrind ../$(BINARY)

a: all
	../$(BINARY)
