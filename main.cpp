//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

#include "Environnement.h"
#include "Case.h"
#include "Cell.h"
#include "CellA.h"
#include "CellB.h"

#define couleur(param) printf("\033[%sm",param)


//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{   
	Environnement env = Environnement(30,20,0.05);
	env.run(1000);
	
	
  return 0;
}
