#ifndef CELLB_H
#define CELLB_H 

//==============================
//    INCLUDES
//==============================


#include <vector>
#include "Cell.h"
#include "CellA.h"

using namespace std;

/**
 * @class CellB
 * @brief Creates a CellB, Cell
 */

class CellB : public Cell
{
public:

//==============================
//    CONSTRUCTORS
//==============================
  
  CellB();
  

//==============================
//    DESTRUCTOR
//==============================
  //virtual ~CellB();

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
float metabolism(float b_out);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================

float Rbb_;
float Rbc_;
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


#endif // CELLB_H

