//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Cell.h"

using namespace std;

//==============================
//    CONSTRUCTOR
//==============================

/**
 * Default Constructor
 */
Cell::Cell(){
	P_death_=0.03;
	W_min_=0.001;
	phen_={0.0,0.0,0.0};
}

//==============================
//    PUBLIC METHODS
//==============================

/**
 * divides the concentration in organites by 2 when a cell divides and 
 * returns phenotype of the newly created cell
 */
vector <float> Cell::division(){
	for (int i=0; i<3; i++){
		phen_[i]/=2;
	}
	return phen_;
}	

//==============================
//    GETTERS
//==============================

/**
 * phenotype getter
 */
vector<float> Cell::phen(){
	return phen_;
}

//==============================
//    SETTERS
//==============================

/**
 * phenotype setter
 */
void Cell::set_phen(vector<float> conc){
	for (int i=0; i<3; i++){
		phen_[i]=conc[i];
	}
}
