## right now there is no production code apart from the libraries...
## Call recursively on the libraries

CC = g++
LIBS = -lcppunit -ldl
THEOBJECTS = 
HEADERDIRS = ../include
OBJDIR = ../obj
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS)) 

.PHONY: all
all:
	$(MAKE) -C paystation
# generate the production code by linking here ...

$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~
	$(MAKE) -C paystation clean

