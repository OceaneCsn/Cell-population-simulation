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
Environnement(float Ainit,int T,float D,float P_mut);
   
//==============================
//    GETTERS
//==============================

Case get_case(int i, int j);
  
//==============================
//    PUBLIC METHODS
//==============================
 void reset();
 void filling();
 int show();
 void showA();
 void showB();
 void death();
 void metabolism();
 void diffusion();
 void competition();
 int run(int t);
 int state();
 float Bpercentage();
 float run_diagram(int t);

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
int cA;
int cB;
};

#endif // ENVIRONNEMENT_H
