CC = g++
AR = ar
ARFLAGS = -cr 
LIBS = -lcppunit -ldl
THEOBJECTS = PayStationImpl.o StandardReceipt.o LinearRateStrategy.o ProgressiveRateStrategy.o AlternatingRateStrategy.o ClockBasedDecisionStrategy.o
HEADERDIRS = ../../include
OBJDIR = ../../obj/paystation
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))

$(OBJDIR)/libpaystation.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ $(OBJDIR)/*.d $(OBJDIR)/*.a

# add the dependency info to make
-include $(addsuffix .d,$(basename $(OBJS)))
