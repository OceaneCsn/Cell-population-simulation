#ifndef CELLA_H
#define CELLA_H 

//==============================
//    INCLUDES
//==============================


#include <vector>
#include "Cell.h"
#include "CellB.h"

using namespace std; 

/**
 * @class CellA
 * @brief Creates a CellA, Cell
 */

class CellA : public Cell{
	
public:

//==============================
//    CONSTRUCTORS
//==============================
  
  
	CellA(): Cell(){
		Raa_=0.1;
		Rab_=0.1;
	}

//==============================
//    DESTRUCTOR
//==============================
  //virtual ~CellA();

//==============================
//    GETTERS
//==============================

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

int isA();
float metabolism(float a_out);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

float Raa_;
float Rab_;
float w_; //fitness of the cell
};

//==============================
//    GETTER DEFINITION
//==============================

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // CELLA_H

