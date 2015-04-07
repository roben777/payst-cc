## Production code consists of libpaystation.a and PSGui 
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
	$(MAKE) -C view

# generate the production code by linking here ...

$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~
	$(MAKE) -C paystation clean
	$(MAKE) -C view clean
