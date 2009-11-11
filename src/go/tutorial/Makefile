DIRS = \
  echo \
  types

all: $(addsuffix .all, $(DIRS))

%.all:
	+cd $* && make
