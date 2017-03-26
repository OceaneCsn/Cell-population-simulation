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

void Rdiagram(int Tmin, int Tmax, float Amin, float Amax, int Pt, float Pa);
void diagram(int Tmin, int Tmax, int Amin, int Amax, int Pt, int Pa);
void simple_run(int t, int A, int T, float D);

//obliges de faire 10000?
//conditions d'approximation de l'etat?

//diagramme de classes : state, ordre des contructeurs, manque les constructeurs cellA et cellB

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{   
	//simple_run(1000, 15 , 1, 0.1);
	Rdiagram(1,801,0,50,50,2);
	system("Rscript Plot_heatmap.R Rdiagram.txt out.pdf");
	
  return 0;
}

//==============================
//    FUNCTIONS
//==============================
/**
 * Display a simulation with values of Ainit, T and D passed in parameters, that lasts the time t
 * We can see the time evolution of the grid, with the genotypes A in blue, and B in red.
 */
void simple_run(int t, float A, int T, float D){
	Environnement env = Environnement(A,T,D);
	env.run(t);
}

/*void RdiagramOptimized(int Amin, int Amax, int Tmin, int Tmax){
	ofstream file("RdiagramOptimized.txt", ios::out | ios::trunc);
	if(file){  
		file << "Ainit " << "T " << "val" << endl;
		int nb_it = (Tmax-Tmin+Pt)/Pt*(Amax-Amin+Pa)/Pa;
		int cpt = 0;
		for(int T=Tmin; T<=Tmax; T+=Pt){
			for (int A=Amin; A<=Amax; A+=Pa){
				cpt++;
				cout << " Simulation " << cpt << " sur " << nb_it << ", Ainit = " << A << " et T = " << T;
				Environnement env = Environnement(A,T,0.1);
				int result = env.run_diagram(1000);
				file << A << " " << T << " " << result << endl;
				if (result==0){
					cout << ":		Extinction" << endl;
				}
				else if (result==1){
					cout << ":		Selection" << endl;
				}
				else{
					cout << ":		Cohabitation" << endl;
				}
			}
		}
		file.close();
	}
	else{
		cerr << "Opening error !" << endl;
	}
}*/

void Rdiagram(int Tmin, int Tmax, float Amin, float Amax, int Pt, float Pa){
	ofstream file("Rdiagram.txt", ios::out | ios::trunc);
	if(file){  
		file << "Ainit " << "T " << "val" << endl;
		int nb_it = (Tmax-Tmin+Pt)/Pt*(Amax-Amin+Pa)/Pa;
		int cpt = 0;
		for(int T=Tmin; T<=Tmax; T+=Pt){
			for (float A=Amin; A<=Amax; A+=Pa){
				cpt++;
				cout << " Simulation " << cpt << " sur " << nb_it << ", Ainit = " << A << " et T = " << T;
				
				Environnement env = Environnement(A,T,0.1);
				int result = env.run_diagram(1000);
				file << A << " " << T << " " << result << endl;
				//A = A+Pa;
				if (result==0){
					cout << ":		Extinction" << endl;
				}
				else if (result==1){
					cout << ":		Selection" << endl;
				}
				else{
					cout << ":		Cohabitation" << endl;
				}
			}
		}
		file.close();
		
	}
	else{
		cerr << "File opening error !" << endl;
	}
}
	
/**
 * Computes several runs with differents values of Ainit and T to return a state diagram
 * in those 2 dimensions.
 * The output is an array wich axis (displayed in white) are the values taken by Ainit and T for the different runs.
 * This array is filled with the number of different genotypes (0,1 or 2) living after a simulation time (1000) 
 */
void diagram(int Tmin, int Tmax, int Amin, int Amax, int Pt, int Pa){
	int** diagram;
	//creation of the array, with an additionnal dimension to store the diagram axis
	diagram  = new int* [(Tmax-Tmin)/Pt+2];
	for(int i=0; i<(Tmax-Tmin)/Pt+2;i++){
		diagram[i] = new int[(Amax-Amin)/Pa+2];
	}
	
	//Filling of the axis with parameters values
	for(int i=0; i<(Tmax-Tmin)/Pt+1; i++){
		diagram[i][0]=Tmax-i*Pt;
		for(int j=0; j<(Amax-Amin)/Pa+1; j++){
			diagram[(Tmax-Tmin)/Pt+1][j+1]=Amin+j*Pa;
		}
	}
	
	int nb_it = (Tmax-Tmin+Pt)/Pt*(Amax-Amin+Pa)/Pa;
	//Points of the diagram
	int cpt = 0;
	for(int T=Tmin; T<=Tmax; T+=Pt){
		for (int A=Amin; A<=Amax; A+=Pa){
			cpt++;
			cout << " Simulation " << cpt << " sur " << nb_it << ", Ainit = " << A << " et T = " << T;
			Environnement env = Environnement(A,T,0.1);
			diagram[(Tmax-T)/Pt][(A-Amin)/Pa+1]=env.run_diagram(1000);
			if (diagram[(Tmax-T)/Pt][(A-Amin)/Pa+1]==0){
				cout << ":		Extinction" << endl;
			}
			else if (diagram[(Tmax-T)/Pt][(A-Amin)/Pa+1]==1){
				cout << ":		Selection" << endl;
			}
			else{
				cout << ":		Cohabitation" << endl;
			}
			
			//cout << "*************************************************************Changement de paramètres" << endl;
		}
	}
	//display
	for (int i=0; i<(Tmax-Tmin)/Pt+2; i++){
		for(int j=0; j<(Amax-Amin)/Pa+2; j++){
			if(j!=0 && i!=(Tmax-Tmin)/Pt+1){
				//changes the color of the value with the final state, for a better visualization
				if(diagram[i][j]==0){
					couleur("30");
					printf("0  ");
				}
				if(diagram[i][j]==1){
					couleur("31");
					printf("1  ");
				}
				if(diagram[i][j]==2){
					couleur("32");
					printf("2  ");
				}
				couleur("0");
			}
			//alignement
			else{
				cout << diagram[i][j] << " ";
				if(diagram[i][j]<10 && j==0){
					cout << " ";
				}
				if(diagram[i][j]<100 && j==0){
					cout << " ";
				}
				if(diagram[i][j]<1000 && j==0){
					cout << " ";
				}
				if(diagram[i][j]<10 && i==(Tmax-Tmin)/Pt+1){
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	delete[] diagram;	
}


