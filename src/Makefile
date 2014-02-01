CC = g++
LIBS = -lcppunit -ldl
THEOBJECTS = PayStationImpl.o main.o ReceiptImpl.o
HEADERDIRS = ../include
OBJDIR = ../obj
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))

$(OBJDIR)/testPS: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d


.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ $(OBJDIR)/*.d $(OBJDIR)/testPS

## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJS)))
