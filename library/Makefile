include ../config.mk

.PHONY : all install clean dist distclean

all : $(full_libname)

$(full_libname) : parport_i13n.o
	$(CC) -shared -Wl,-soname,$(full_libname) $^ -o $@

parport_i13n.o: parport_i13n.c parport_i13n.h
	$(CC) -fPIC $(CFLAGS) -c $< -o $@

TAGS: $(wildcard *.c) $(wildcard *.h) $(wildcard *.c)
	etags $^

clean:
	rm -f *.o $(full_libname) TAGS

install: all
	$(INSTALL) -d $(DESTDIR)$(prefix)/lib${LIB_SUFFIX}/
	$(INSTALL) $(full_libname) $(DESTDIR)$(prefix)/lib${LIB_SUFFIX}/
	ln -sf $(full_libname) $(DESTDIR)$(prefix)/lib${LIB_SUFFIX}/$(libname)
	$(INSTALL) -d $(DESTDIR)$(prefix)/include/
	$(INSTALL) parport_i13n.h $(DESTDIR)$(prefix)/include/

