# VARIABLES

FILES = $(wildcard ./*.py) # example wildcard w dirctory $(wildcard lib/*.cpp)
FILES += $(wildcard Game/*.py)
TARGET = matchTacToe.py



.PHONY: run
run:
	python3 $(TARGET)



.PHONY: vim
vim: 
	vim $(FILES)


