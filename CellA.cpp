//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "CellA.h"
#include <vector>
#include "Cell.h"

using namespace std;

//==============================
//    CONSTRUCTOR
//==============================

/**
 * default constructor
 */
CellA::CellA():Cell(){
	Raa_=0.1;
	Rab_=0.1;
}

//==============================
//    PUBLIC METHODS
//==============================

/**
 * returns 1, meaning that the cell has genotype A
 */
int CellA::isA(){
	return 1;
}

/**
 * executes metabolic functions, and returns the new amount of A metabolites in the case
 * Takes the former amount of metabolites A in the case as parameter
 */
float CellA::metabolism(float a_out){
	phen_[0]=phen_[0]*(1-0.1*Rab_)+a_out*Raa_*0.1;
	phen_[1]=phen_[1]+0.1*phen_[0]*Rab_;
	return a_out*(1-0.1*Raa_);
}

//==============================
//    GETTER
//==============================

/**
 * fitness getter, taking the minimum fitness in account
 */
float CellA::fitness(){
	if(phen_[1]>W_min_){
		return phen_[1];
	}
	return 0;
}

