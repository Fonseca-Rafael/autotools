all: jupiter

CFLAGS ?= -g -O0

jupiter: main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ main.c

clean:
	-rm -f jupiter

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(DESTDIR)$(bindir)
	install -m 0755 jupiter $(DESTDIR)$(bindir)

uninstall:
	-rm $(DESTDIR)$(bindir)/jupiter

.PHONY: all clean check install uninstall
