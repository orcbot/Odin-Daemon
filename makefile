#@todo make a proper makefile
# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

make: main.cpp lib/helper/config.o lib/variables/variable.o lib/varList/varlist.o lib/calculations/add.o
	g++ main.cpp lib/helper/config.o lib/variables/variable.o  lib/varList/varlist.o lib/calculations/add.o -std=c++11 -o Odin.out

config.o: lib/helper/config.h lib/helper/config.cpp
	g++ lib/helper/config.h -o lib/helper/config.o

variable.o: lib/variables/variable.h lib/variables/variable.cpp
	g++ lib/variables/variable.h -o lib/variables/variable.o

varlist.o: lib/varList/varlist.h lib/varList/varlist.cpp
	g++ lib/varList/varlist.h -o lib/varList/varlist.o

add.o: lib/calculations/add.h lib/calculations/calc.h lib/calculations/add.cpp
	g++ lib/calculations/add.h -o lib/calculations/add.o

run: Odin.out
	./Odin.out $(RUN_ARGS)

clean:
	rm Odin.out
