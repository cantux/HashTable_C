CC=gcc
FLAGS:=
INCLUDES := .
DEBUG = -g

build_dir = build
$(shell mkdir -p $(build_dir)/strat)

strat_directory:=strat
strat_files := $(wildcard $(strat_directory)/*.c)
strat_objects := $(patsubst %.c, %.o, $(strat_files))

all: $(strat_objects)
	$(CC) ht.c test.c $(addprefix $(build_dir)/, $^) -lm -I$(INCLUDES) $(DEBUG) -o test 

$(strat_objects): %.o: %.c 
	$(CC) -c $^ -I$(INCLUDES) -o $(build_dir)/$@

clean:
	rm -rf $(build_dir)


