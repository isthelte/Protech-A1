CC=gcc
CFLAGS=-Wall -std=c99 #-g -pg
SOURCES = pt_utils.c pt_sorting.c test_pt_sorting.c
OBJS = $(patsubst %.c,%.o,$(SOURCES))
HEADERS = pt_utils.h pt_sorting.h

test_pt_sorting: $(OBJS) 
	$(CC) $(CFLAGS) -o test_pt_sorting $(OBJS)

$(OBJS): $(HEADERS)

.PHONY: clean
clean:
	rm *.o 
	
.PHONY: cleanall
cleanall:
	rm *.o *~ $(EXECS)
