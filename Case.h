#ifndef CASE_H
#define CASE_H 

//==============================
//    INCLUDES
//==============================
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Cell.h"
#include "CellA.h"
#include "CellB.h" 
/**
 * @class Case
 * @brief Creates a Case
 */

class Case
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Case();
  Case(vector <float> organites, char c);
//==============================
//    DESTRUCTOR
//==============================
  ~Case();

//==============================
//    GETTERS
//==============================

vector <float> organites();
 
//==============================
//    SETTERS
//==============================
void set_cell(char c);
void set_organites( vector <float> org );
//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
  
  void reset(float Ainit);
  int containsA();
  void death();
  void metabolism();

  
protected:

//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
vector<float> organites_;
Cell * cell_;
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


#endif // CASE_H
