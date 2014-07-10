VERSION=1.0

include config.mk

DIRS=library

.PHONY : all clean install

all :
	for d in ${DIRS}; do $(MAKE) -C $${d}; done

clean :
	for d in ${DIRS}; do $(MAKE) -C $${d} clean; done

install : all
	for d in ${DIRS}; do $(MAKE) -C $${d} install; done

dist : distclean
	mkdir parport_i13n-$(VERSION)
	cp -pr library parport_i13n-$(VERSION)/
	cp -p Makefile CHANGELOG.txt README.txt GNU_General_Public_License.txt parport_i13n-$(VERSION)/
	tar -zcf parport_i13n-$(VERSION).tar.gz parport_i13n-$(VERSION)

distclean : 
	rm -rf parport_i13n-$(VERSION)
	rm -f parport_i13n-$(VERSION).tar.gz
