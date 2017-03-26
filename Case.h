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
vector <float> phen();

 
//==============================
//    SETTERS
//==============================
void set_cell(char c);
void set_cell(char c, vector <float> conc);
void set_organites( vector <float> org );

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
  
void reset(float Ainit);
int containsA();
int death();
void metabolism();
int isEmpty();
vector <float> division();
float fitness();
  
protected:

//==============================
//    ATTRIBUTES
//==============================

vector<float> organites_;
Cell * cell_;
};

#endif // CASE_H
