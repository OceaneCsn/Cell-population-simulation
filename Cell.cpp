//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Cell.h"

using std::cout;
using std::cin;
using std::endl;
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Cell::Cell(){
	P_death_=0.02;
	W_min_=0.001;
	P_mut_=0.001;
	phen_={0.0,0.0,0.0};
}

Cell::Cell(float pmut){
	P_death_=0.02;
	W_min_=0.001;
	P_mut_=pmut;
	phen_={0.0,0.0,0.0};
}
	
//==============================
//    DESTRUCTOR
//==============================

//==============================
//    PUBLIC METHODS
//==============================



//==============================
//    GETTERS
//==============================
vector<float> Cell::phen(){
	return phen_;
}
 
