IDIR =../include
CC=gcc-9 -std=c99
CFLAGS=-I$(IDIR)

ODIR=../obj
LIBS=-lm

_DEPS = dataStructures.h helper.h getters.h scheduler_helper.h scheduler.h runner.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = helper.o runner.o getters.o scheduler_helper.o scheduler.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f  $(ODIR)/*.o *~ core $(INCDIR)/*~ 
