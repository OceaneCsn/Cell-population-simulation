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

