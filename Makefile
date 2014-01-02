CC = g++
LIBS = -lcppunit -ldl
OBJS = PayStationImpl.o main.o ReceiptImpl.o

testPS: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

%.o : %.cc
	$(CC) -c -o $@ $<
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d

.PHONY : clean
clean :
	rm -f *.o *~ *.d

## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJS)))
