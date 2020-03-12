
CFLAGS=-O1 -fno-slp-vectorize -g -std=c11  -lm  -lstdc++ 
CAMLFLAGs=
CSRC = $(wildcard *.c)
COUT = $(patsubst %.c,%.o,$(CSRC))



CC = clang -pg -Xclang -load -Xclang $(SOFTBOUNDCETS_HOME)/softboundcets_pass/build/sbcets/libSoftBoundCETS.so

all: $(COUT) $(CAMLOUT)

%.o: %.c
	$(CC) -o $@ $< $(CFLAGS)
	chmod u+x $@

%.sout: %.s
	$(CC) -o $@ $< $(CFLAGS)
	chmod u+x $@

%.s: %.c
	$(CC) $(CFLAGS) -S -o $@ $<


clean:
	rm -rf *.o *.sout *.dSYM *~ *.log functions.txt  *.out *.ll *.bc
