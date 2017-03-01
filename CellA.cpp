//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "CellA.h"
#include <vector>
#include "Cell.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std;
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================

//==============================
//    DESTRUCTOR
//==============================


//==============================
//    PUBLIC METHODS
//==============================

int CellA::isA(){
	return 1;
}

float CellA::metabolism(float a_out){
	phen_[0]=phen_[0]*(1-0.1*Rab_)+a_out*Raa_*0.1;
	phen_[1]=phen_[1]+0.1*phen_[0]*Rab_;
	return a_out*(1-0.1*Raa_);
}
