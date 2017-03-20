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
//    GETTER DEFINITION
//==============================

float fitness();

//==============================
//    PUBLIC METHODS
//==============================

int isA();  
float metabolism(float b_out);

protected:

//==============================
//    ATTRIBUTES
//==============================

float Rbb_;
float Rbc_;
};

#endif // CELLB_H

