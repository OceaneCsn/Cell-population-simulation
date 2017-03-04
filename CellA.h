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
  
CellA();

//==============================
//    PUBLIC METHODS
//==============================

int isA();

//==============================
//    DESTRUCTOR
//==============================

//virtual ~CellA();

//==============================
//    GETTER DEFINITION
//==============================

float fitness();
float metabolism(float a_out);

protected:

//==============================
//    ATTRIBUTES
//==============================

float Raa_;
float Rab_;

};



//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // CELLA_H

