CC = g++
LIBS = -lcppunit -ldl
OBJS = PayStationImpl.o main.o ReceiptImpl.o
HEADERDIRS = ../include
CCFLAGS = -I $(HEADERDIRS)

testPS: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c $<

.PHONY : clean
clean :
	rm -f *.o *~

## generate the prerequistes and append to the desired file 
.prereq : $(OBJS:.o=.cc) $(wildcard $(HEADERDIRS)/*.h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc) >> ./.prereq
## include the generated prerequisite file 
include .prereq