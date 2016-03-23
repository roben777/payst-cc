########
# Build system for PayStation static library 
########
THEOBJECTS = main.o PSGui.o
GUIDIR = /home/lib2720/lect/fltk-1.3.0/
HEADERDIRS = -I ../../include -I $(GUIDIR)
OBJDIR = ../../obj/view
PSDIR = ../../obj/paystation
#######
CC = g++
AR = ar
ARFLAGS = -cr 
CCFLAGS = $(HEADERDIRS) -I/usr/local/include -I/usr/local/include/FL/images -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT

UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
LNFLAGS = -L$(PSDIR)/ -lpaystation -lfltk -lpthread -framework Cocoa
else
LNFLAGS = -L/usr/local/lib -L$(PSDIR)/ -L$(GUIDIR)/lib -lpaystation -lfltk -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
endif
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))
########

$(OBJDIR)/PSGui: $(OBJS) 
	$(CC) -o $@ $^ $(LNFLAGS) 


$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<
	$(CC) $(CCFLAGS) -MM -MP -MT $@ $< > $(basename $@).d


.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ $(OBJDIR)/PSGui $(OBJDIR)/*.d

# add the dependency info to make
-include $(addsuffix .d,$(basename $(OBJS)))
