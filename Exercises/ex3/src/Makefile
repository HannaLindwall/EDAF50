# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -g -O2 -Wall -W -pedantic-errors
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g
#CPPFLAGS =  -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = countobj svectortest cryptotest bitbuffertest

all: $(PROGS)

t1: countobj
	./countobj
t2: svectortest
	./svectortest
t3: cryptotest
	./cryptotest
t4: bitbuffertest
	./bitbuffertest

# Targets rely on implicit rules for compiling and linking
countobj: countobj.o
svectortest: svectortest.o svector.o
cryptotest: cryptotest.o crypto.o
bitbuffertest: bitbuffertest.o bitbuffer.o

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
