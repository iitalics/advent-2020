CC ?= gcc
CURL ?= curl
CFLAGS = --std=c89

DAYS = 1

all: $(DAYS:%=day%)
	@$(DAYS:%=d=%;echo -n "Day $$d: ";./run.sh $$d)

clean:
	rm -f $(shell find . -type f -name 'day?' -or -name '.input*')
