CXX = g++

SRC = source/hello.cc
OBJ = $(SRC:.cc=.o)

PREFIX = /usr/local

all: libhello.so

libhello.so: $(OBJ)
	$(CXX) -shared -o $@ $<

%.o:%.cc
	$(CXX) -fpic -o $@ -c $< -Iinclude

source/hello.o: include/hello.h

install:libhello.so
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include
	cp libhello.so $(DESTDIR)$(PREFIX)/lib/libhello.so
#with -p the command will create all the directories necessary
#to fulfill the request
#no error if the directory already exists

#cp means copy
uninstall:
	rm -f libhello.so $(DESTDIR)$(PREFIX)/lib/libhello.so
	rm -rf hello.h  $(DESTDIR)$(PREFIX)/include

clean:
	rm -rf *.so source/*.o

.PHONY: clean uninstall all install
