# makefile
# Defines tasks to run that help with speedy development.

GCC = g++
SOURCE = source/stone-paper-scissors.cpp
OUTFILE = build/stone-paper-scissors
INCLUDE = source/

.PHONY: run

run: stone-paper-scissors
	@./build/stone-paper-scissors

stone-paper-scissors:
	@$(GCC) $(SOURCE) -o $(OUTFILE) -I $(INCLUDE)
