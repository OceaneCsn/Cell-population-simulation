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
//    GETTERS
//==============================

Case get_case(int i, int j);
  
//==============================
//    PUBLIC METHODS
//==============================
 void reset();
 void filling();
 void show();
 void death();
 void metabolism();
 void diffusion();
 void competition();
 void run(int t);

protected:

//==============================
//    ATTRIBUTES
//==============================

float Ainit_; //glucose initial concentration
int W_; //width
int H_; //height
int T_ ; //frequence of grid cleaning
float D_; //diffusion
float P_mut_;
Case** grille;
};

#endif // ENVIRONNEMENT_H

