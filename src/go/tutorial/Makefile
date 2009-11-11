DIRS = \
  echo \
  types \
  primes

all: $(addsuffix .all, $(DIRS))

%.all:
	+cd $* && make
