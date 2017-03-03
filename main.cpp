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
//    FUNCTIONS
//==============================
void diagram(int Tmin, int Tmax, int Amin, int Amax, int Pt, int Pa){
	int** diagram;
	diagram  = new int* [(Tmax-Tmin)/Pt+1];
	for(int i=0; i<(Tmax-Tmin)/Pt+1;i++){
		diagram[i] = new int[(Amax-Amin)/Pa];
	}
	
	for(int T=Tmin; T<=Tmax; T+=Pt){
		for (int A=Amin; A<=Amax; A+=Pa){
			Environnement env = Environnement(A,T,0.1);
			diagram[(T-Tmin)/Pt][(A-Amin)/Pa]=env.run_diagram(1000);
			cout << "******************************************Changement de paramètres" << endl;
		}
		
	}
	//display
	for (int i=0; i<(Tmax-Tmin)/Pt+1; i++){
		for(int j=0; j<(Amax-Amin)/Pa+1; j++){
			cout << diagram[i][j] << " ";
		}
		cout << endl;
	}	
}

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{   
	//Environnement env = Environnement(20,1000,0.1);
	//env.run(100);
	diagram(1,1501,0,50,300, 5);
	
	
	
	
	


	
	
  return 0;
}
