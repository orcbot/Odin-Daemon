#@todo make a proper makefile
# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
	# use the rest as arguments for "run"
	RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
	# ...and turn them into do-nothing targets
	$(eval $(RUN_ARGS):;@:)
endif

make: main.cpp lib/helper/config.o lib/variables/variable.o lib/varList/varlist.o lib/calculations/add.o lib/calculations/dot.o lib/calculations/sub.o lib/calculations/mult.o
	g++ main.cpp lib/helper/config.o lib/variables/variable.o  lib/varList/varlist.o lib/calculations/add.o lib/calculations/dot.o lib/calculations/sub.o lib/calculations/mult.o -std=c++11 -o Odin.out

lib/helper/config.o: lib/helper/config.h lib/helper/config.cpp
	g++    -c -o dist/lib/helper/config.o lib/helper/config.cpp

lib/variables/variable.o: lib/variables/variable.h lib/variables/variable.cpp
	g++    -c -o dist/lib/variables/variable.o lib/variables/variable.cpp

lib/varList/varlist.o: lib/varList/varlist.h lib/varList/varlist.cpp
	g++    -c -o dist/lib/varList/varlist.o lib/varList/varlist.cpp

lib/calculations/add.o: lib/calculations/add.h lib/calculations/calc.h lib/calculations/add.cpp
	g++    -c -o dist/lib/calculations/add.o lib/calculations/add.cpp

lib/calculations/dot.o: lib/calculations/dot.h lib/calculations/calc.h lib/calculations/dot.cpp
	g++    -c -o dist/lib/calculations/dot.o lib/calculations/dot.cpp

lib/calculations/sub.o: lib/calculations/sub.h lib/calculations/calc.h lib/calculations/sub.cpp
	g++    -c -o dist/lib/calculations/sub.o lib/calculations/sub.cpp

lib/calculations/mult.o: lib/calculations/mult.h lib/calculations/calc.h lib/calculations/mult.cpp
	g++    -c -o dist/lib/calculations/mult.o lib/calculations/mult.cpp

run: Odin.out
	./Odin.out $(RUN_ARGS)

clean:
	rm lib/helper/config.o
	rm lib/variables/variable.o
	rm lib/varList/varlist.o
	rm lib/calculations/add.o
	rm lib/calculations/dot.o
	rm lib/calculations/sub.o
	rm lib/calculations/mult.o
	rm Odin.out
