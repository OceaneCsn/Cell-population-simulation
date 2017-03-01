//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "CellB.h"
#include <vector>


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
CellB::CellB() : Cell(){
	Rbb_=0.1;
	Rbc_=0.1;
}
	
//==============================
//    DESTRUCTOR
//==============================


//==============================
//    PUBLIC METHODS
//==============================

int CellB::isA(){
	return 0;
}

float CellB::metabolism(float b_out){

	phen_[1]=phen_[1]*(1-0.1*Rbc_)+b_out*Rbb_*0.1;
	phen_[2]=phen_[2]+0.1*phen_[2]*Rbc_;
	return b_out*(1-0.1*Rbb_);

}
