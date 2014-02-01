.PHONY  : all
all:
	$(MAKE) -C src

.PHONY : testcases
testcases:
	$(MAKE) -C src
	$(MAKE) -C test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean