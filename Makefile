#
#
#
#


VERS=1.0

DEBUG = -O2


FILES = wft.c

OFILES = wft.o

all: wft

wft: $(OFILES)
	$(CC) $(PROFILE) -o wft $(OFILES) 

wft.o:: 

clean:
	rm -f *.o
