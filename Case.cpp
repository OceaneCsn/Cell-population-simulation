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
//using namespace std;
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Case::Case(){
	organites_= {0.,0.,0.};
	cell_= nullptr;
}

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


vector <float> Case::organites(){
	
	return organites_;
}

//==============================
//    SETTERS
//==============================

void Case::set_cell(char c){
	if (c=='a'){
		cell_ = new CellA();}
    if (c=='b'){
		cell_ = new CellB();}
}

void Case::set_organites(vector <float> org){
	for (int i=0; i<3; i++){
		organites_[i]=org[i];
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
void Case::reset(float Ainit){
	organites_={Ainit,0.,0.};
}

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
		

	
	
	
