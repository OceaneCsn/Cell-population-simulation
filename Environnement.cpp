//==============================
//    INCLUDES
//==============================

#include "Environnement.h"
#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//==============================
//    CONSTRUCTORS
//==============================

/**
 * Default Constructor
 */
Environnement::Environnement(){
	Ainit_ = 5;
	W_ = 5; 
	H_ = 5; 
	T_ = 700;
	D_ = 0.001;
	P_mut_ = 0.001;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
}

/**
 * Constructor with parameters
 */
Environnement::Environnement(float Ainit,int T,float D){
	Ainit_ = Ainit;
	W_ = 32; 
	H_ = 32; 
	T_ = T;
	D_ = D;
	P_mut_=0.2;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
	
}

//==============================
//    GETTERS
//==============================

/**
 * grid getter
 */
Case Environnement::get_case(int i, int j){
	return grille[i][j];
}

//==============================
//    PUBLIC METHODS
//==============================

/**
 * sets the organites concentration to Ainit for glucose, and 0 for the others
 */
void Environnement::reset(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].reset(Ainit_);
		}
	}
}

/**
 * randomly fills the grid with W*H/2 cells A and W*H/2 cells B.
 */
void Environnement::filling(){
	int cptA=0;
	//counts the number of created cells with genotype A
	int cptB=0;
	//idem with cells with genotype B
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(cptA<W_*H_/2 && cptB<W_*H_/2){
				//Randomly fills the grid with either A or B cells, until one of the counts reaches his maximum
				int random = rand() % 2;
				if(random==0){
					grille[i][j].set_cell('a');
					cptA++;
				}
				else{
					grille[i][j].set_cell('b');
					cptB++;
				}
			}
			//fills the remaning cases with cells with the remaining genotype
			if(cptA==W_*H_/2){
				grille[i][j].set_cell('b');
			}
			if(cptB==W_*H_/2){
				grille[i][j].set_cell('a');
			}
		}
	}
}

/**
 * display the grid
 */
void Environnement::show(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(grille[i][j].containsA() == 1){
				cout << 'a';
			}
			else if(grille[i][j].containsA() == 0){
				cout << 'b';
			}
			else{
				cout << ' ';
			}
		}
		cout << endl;
	}
}

/**
 * applies a random death method to all the cells in the grid
 */
void Environnement::death(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].death();
		}
	}
}

/**
 * ask all the cells of each case to execute their metabolism functions, between their intern organites and the extern concentrations
 */
void Environnement::metabolism(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].metabolism();
		}
	}
}

/**
 * computes the diffusion of the organites through the grid
 */
void Environnement::diffusion(){
	//grid browse
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			//vector of organites at time t
			vector <float> oldvec = grille[i][j].organites();
			//browsing neighbourhood
			for (int k=-1; k<2; k++){
				for(int l=-1; l<2; l++){
					int v=0;
					int h=0;
					//computing edge conditions to obtain a toric grid
					if(i+k>H_-1){
						v=0;
					}
					else if(i+k<0){
						v=H_-1;
					}
					else{
						v=i+k;
					}
					if(j+l>W_-1){
						h=0;
					}
					else if(j+l<0){
						h=W_-1;
					}
					else{
						h=j+l;
					}
					//acquiring organites from neighbouring cells in a new vector 
					vector <float> newvec = grille[i][j].organites();
					for(int m=0; m<3; m++){
						newvec[m]+=D_*(grille[v][h].organites()[m]);
					}
					grille[i][j].set_organites(newvec);
				}
			}
			//losing organites to neighbouring cells
			vector <float> newvec2 = grille[i][j].organites();
			for(int m=0; m<3; m++){
				newvec2[m]-=9*D_*oldvec[m];
			}
			//final vector at time t+1
			grille[i][j].set_organites(newvec2);
		}
	}
}

/**
 * browses the grid. For each empty case, looks for the neighbouring cell with the
 * highest fitness, and proceeds to division
 */
void Environnement::competition(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			//borwses the grid looking for empty cases
			if(grille[i][j].isEmpty()==1){
				int fitness_max = 0;
				int v_max = 0;
				int h_max=0;
				//browsing neighbourhood
				for (int k=-1; k<2; k++){
					for(int l=-1; l<2; l++){
						if( k!=0 && l!=0 ) {
							int v=0;
							int h=0;
							//computing edge conditions
							if(i+k>H_-1){
								v=0;
							}
							else if(i+k<0){
								v=H_-1;
							}
							else{
								v=i+k;
							}
							
							if(j+l>W_-1){
								h=0;
							}
							else if(j+l<0){
								h=W_-1;
							}
							else{
								h=j+l;
							}
							//checks if the neighbouring case contains a cell
							if(grille[h][v].isEmpty()==0){
								//looks for the neighbouring cell with highest fitness and stores its coordonates
								if(grille[h][v].fitness()>fitness_max){
									fitness_max=grille[h][v].fitness();
									h_max=h;
									v_max=v;
								}
							}
						}
					}
				}
				cout << fitness_max << endl;
				
				if(fitness_max>0){
					//randomly determines if the dividing cell will mutate
					float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					if(random<P_mut_){
						cout << "mutation" << endl;
					}
					else{
						cout << "pas mutation" << endl;
					}
					//fills the empty case with an adequate cell
					if((grille[h_max][v_max].containsA()==1 && random >= P_mut_) || (grille[h_max][v_max].containsA()==0 && random<P_mut_)){
						grille[i][j].set_cell('a',grille[h_max][v_max].division());
					}
					else{
						grille[i][j].set_cell('b',grille[h_max][v_max].division());
					}
				}
			}
		}
	}
}

/**
 * general simulation, with a given number of iterations
 */
void Environnement::run(int t){
	show();
	for (int i=0; i<t*10; i++){
		if(i%(T_*10) == 0){
			reset();
		}
		//diffusion();
		death();
		competition();
		metabolism();
		show();
		cout << grille[1][1].organites()[0] << ' ' << grille[1][1].organites()[1]  << ' ' << grille[1][1].organites()[2]  << endl;
		cout << grille[1][1].phen()[0] << ' ' << grille[1][1].phen()[1]  << ' ' << grille[1][1].phen()[2]  << endl;
		
		float sum = 0;
		for (int i=0; i<H_; i++){
			for(int j=0; j<W_; j++){
				sum+=grille[1][1].organites()[0];
			}
		}
		cout << "somme de A : " << sum << endl;
		cout << ' ' << endl;
	}
	//show();
}
	
			
			
			
			
	
