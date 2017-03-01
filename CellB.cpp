//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "CellB.h"
#include <vector>

using namespace std;

//==============================
//    CONSTRUCTORS
//==============================

/**
 * default constructor
 */
CellB::CellB() : Cell(){
	Rbb_=0.1;
	Rbc_=0.1;
}

//==============================
//    PUBLIC METHODS
//==============================

/**
 * returns 0, meaning that the cell has genotype B
 */
int CellB::isA(){
	return 0;
}

/**
 * executes metabolic functions, and returns the new amount of A metabolites in the case
 * Takes the former amount of metabolites A in the case as parameter
 */
float CellB::metabolism(float b_out){
	phen_[1]=phen_[1]*(1-0.1*Rbc_)+b_out*Rbb_*0.1;
	phen_[2]=phen_[2]+0.1*phen_[2]*Rbc_;
	return b_out*(1-0.1*Rbb_);
}

/**
 * fitness getter, taking the minimum fitness in account
 */
float CellB::fitness(){
	return phen_[1];
}

