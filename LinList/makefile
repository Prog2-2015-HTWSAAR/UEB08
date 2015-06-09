# makefile
# Created on: 21.05.2012
#     Author: folz

CFLAGS =  -g -std=c++0x -pedantic -Wall

all: LinListTst

LinListTst: LinListTst.cpp LinList.o ListElement.o

LinList.o: LinList.cpp LinList.h ListElement.h

ListElement.o: ListElement.cpp ListElement.h

-include ../make-rules
