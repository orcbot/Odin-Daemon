#@todo make a proper makefile
# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

make: main.cpp lib/helper/config.o
	g++ main.cpp lib/helper/config.o -std=c++11 -o Odin.out

config.o: lib/helper/config.h lib/helper/config.cpp
	g++ lib/helper/config.h -o lib/helper/config.o

run: Odin.out
	./Odin.out $(RUN_ARGS)

clean:
	rm Odin.out
