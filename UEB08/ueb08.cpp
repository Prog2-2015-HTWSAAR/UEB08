/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file ueb08.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 14.06.2015
*
* Main Funktion
*/
#include <iostream>
#include "ListenDialog.h"
using namespace std;

/**
* @brief Main Function
*/
int main(){
	ListenDialog listenDialog;
	listenDialog.initLanguage();
	return 0;
}
