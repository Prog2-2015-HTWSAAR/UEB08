makefile:
DEL_LIST = *.o *.exe *stackdump

all: build doc
clean:
	rm -f $(DEL_LIST)
build: 
	g++ -c -Wall -pedantic *.cpp
	g++ -o ueb06 *.o
build11: 
	g++ -c -Wall -pedantic *.cpp -std=c++11
	g++ -o ueb06 *.o
doc: 
	/export/home_14/andschreiner/doxygen/bin/doxygen doxyfile
docmac: 
	/Applications/Doxygen/doxygen doxyfile
rebuild: clean all

testbuild: 
	g++ -c *.cpp 
	g++ -o ueb06 *.o
	
testbuild11: 
	g++ -c *.cpp -std=c++11
	g++ -o ueb06 *.o
