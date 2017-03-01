#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H 

//==============================
//    INCLUDES
//==============================

/**
 * @class Environnement
 * @brief Creates an environnement
 */
#include "Case.h"
class Environnement
{
public:
//==============================
//    CONSTRUCTORS
//==============================
 Environnement();
 Environnement(float Ainit,int T,float D);
 
//==============================
//    DESTRUCTOR
//==============================
  
//==============================
//    GETTERS
//==============================
Case get_case(int i, int j);
//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================
  
//==============================
//    PUBLIC METHODS
//==============================
 void reset();
 void filling();
 void show();
 void death();
 void metabolism();
 void diffusion();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float Ainit_; //glucose initial concentration
int W_; //width
int H_; //height
int T_ ; //frequence of grid cleaning
float D_; //diffusion
Case** grille;
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


#endif // ENVIRONNEMENT_H

