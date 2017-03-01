//==============================
//    INCLUDES
//==============================

#include "Case.h"
#include "Cell.h"
#include "CellA.h"
#include "CellB.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

//==============================
//    CONSTRUCTORS
//==============================

/**
 * default constructor
 */
Case::Case(){
	organites_= {0.,0.,0.};
	cell_= nullptr;
}

/**
 * constructor with genotype and phenotype
 */
Case::Case(vector <float> organites, char c){
  if (c=='a'){
    cell_ = new CellA();}
  if (c=='b'){
    cell_ = new CellB();}
  organites_ = {organites[0], organites[1], organites[2]};
}

//==============================
//    GETTERS
//==============================

/**
 * returns organites present in the case
 */
vector <float> Case::organites(){
	return organites_;
}

//==============================
//    SETTERS
//==============================

/**
 * adds a cell with given genotype in a case
 */
void Case::set_cell(char c){
	if (c=='a'){
		cell_ = new CellA();}
    if (c=='b'){
		cell_ = new CellB();}
}

/**
 * sets the organites present in the case
 */
void Case::set_organites(vector <float> org){
	for (int i=0; i<3; i++){
		organites_[i]=org[i];
	}
}

/**
 * sets the caracteristics of the cell in the case
 */
void Case::set_cell(char c, vector <float> conc){
	if(c=='a'){
		cell_=new CellA();
		cell_->set_phen(conc);
	}
	else{
		cell_=new CellB();
		cell_->set_phen(conc);
	}
}

	
//==============================
//    DESTRUCTOR
//==============================

Case::~Case(){
	if(cell_!= nullptr){
		//delete cell_;
	}
}

//==============================
//    PUBLIC METHODS
//==============================

/**
 * resets the metabolites to initial concentration
 */
void Case::reset(float Ainit){
	organites_={Ainit,0.,0.};
}

/**
 * returns 1 if the case contains a cell with genotype A, 0 for genotype B and -1 for lack of cell
 */
int Case::containsA(){
	if(cell_ != NULL){
		if(cell_->isA()==1){
			return 1;
		}
		else{ return 0; }
	}
	else{
		return -1;
		}
}

/**
 * Randomly kills cell in the case
 */
void Case::death(){
	if(cell_){
		float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		vector <float> conc = cell_->phen();
		if(random<=cell_->P_death_){
			for (int i=0; i<3; i++){
				organites_[i]+=conc[i];
			}
			cell_= nullptr;
		}
	}
}

/**
 * simulates metabolism of the cell in the case
 */		
void Case::metabolism(){
	if(cell_){
		if(containsA()==1){
			organites_[0] = cell_->metabolism(organites_[0]);
		}
		else{
			organites_[1] = cell_ ->metabolism(organites_[1]);
		}
	}
}

/**
 * returns 1 if the case is empty, 0 otherwise
 */
int Case::isEmpty(){
	if(cell_==nullptr){
		return 1;
	}
	return 0;
}

/**
 * returns the divided cell next to an empty case
 */
vector <float> Case::division(){
	return (*cell_).division();
}

/**
 * returns fitness of the cell in the case
 */
float Case::fitness(){
	return cell_->fitness();
}

/**
 * returns phenotype of the cell in the case
 */
vector <float> Case::phen(){
	return cell_->phen();
}

	
	
	
