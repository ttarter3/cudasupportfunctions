# Makefile

all:
	module load cuda && cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./install
	cmake --build build -DCMAKE_INSTALL_PREFIX=./install  
	cd build; make install; cd ..;

build:	
	cmake --build build -DCMAKE_INSTALL_PREFIX=./install  
	cd build; make install; cd ..;
 
clean:
	rm -rf build lib/* install/*

.PHONY: all clean build