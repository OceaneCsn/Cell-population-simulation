#ifndef CELL_H
#define CELL_H 

//==============================
//    INCLUDES
//==============================

#include <vector>

using namespace std;

/**
 * @class Cell
 * @brief Creates a Cell
 */

class Cell
{

public:

//==============================
//    CONSTRUCTORS
//==============================
  
Cell();

//==============================
//    DESTRUCTOR
//==============================

virtual ~Cell(){};

//==============================
//    GETTER DEFINITION
//==============================

virtual float fitness()=0;
vector<float> phen();

//==============================
//    SETTERS
//==============================

void set_phen(vector<float> conc);

//==============================
//    PUBLIC METHODS
//==============================

virtual int isA() = 0;
virtual float metabolism(float out) = 0;
vector <float> division();

//==============================
//    ATTRIBUTE
//==============================

float P_death_; //probability of death at each step of time

protected:

//==============================
//    ATTRIBUTES
//==============================
  
float W_min_; //minimal fitness
float P_mut_; //probability of mutation when the cell is dividing
vector<float> phen_; //phenotype : concentration in organites A, B and C
};


#endif // CELL_H

