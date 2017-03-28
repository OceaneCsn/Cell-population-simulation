//==============================
//    INCLUDES
//==============================

#include "Environnement.h"
#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#define couleur(param) printf("\033[%sm",param)

using namespace std;

//==============================
//    CONSTRUCTORS
//==============================

/**
 * Default Constructor
 */
Environnement::Environnement(){
	Ainit_ = 5;
	W_ = 32; 
	H_ = 32; 
	T_ = 700;
	D_ = 0.001;
	P_mut_ = 0;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
	cA = W_*H_/2;
	cB = W_*H_/2;
}

/**
 * Constructor with parameters
 */
Environnement::Environnement(float Ainit,int T,float D, float P_mut){
	Ainit_ = Ainit;
	W_ = 32; 
	H_ = 32; 
	T_ = T;
	D_ = D;
	P_mut_=P_mut;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
	cA = W_*H_/2;
	cB = W_*H_/2;

}

Environnement::Environnement(float D){
	Ainit_ = 10;
	W_ = 5; 
	H_ = 5; 
	T_ = 200;
	D_ = D;
	P_mut_=0;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	grille[2][2].reset(10);
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
	char remaining = ' ';
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
				if(cptA==W_*H_/2){
					remaining = 'b';
				}
				if(cptB==W_*H_/2){
					remaining = 'a';
				}
				
			}
			else{
				grille[i][j].set_cell(remaining);
				if(remaining=='a'){
					cptA++;
				}
				else{
					cptB++;
				}
			}
		}
	}
}

/**
 * display the grid with two colors to visualize genotypes
 * also evaluates the state of the population, and return the number of different living genotypes
 */
int Environnement::show(){
	int cptA = 0;
	int cptB = 0;
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(grille[i][j].containsA() == 1){
				couleur("34");
				printf("a ");
				couleur("0");
				cptA++;
			}
			else if(grille[i][j].containsA() == 0){
				couleur("31");
				printf("b ");
				couleur("0");
				cptB++;
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
	if(cptB==0){
		if(cptA==0){
			cout << "Extinction" << endl;
			return 0;
		}
		else{
			cout << "Exclusion" << endl;
			return 1;
		}
	}
	else{
		if(cptA==0){
			cout << "Selection" << endl;
			return 1;
		}
		else{
			cout << "Cohabitation" << endl;
			return 2;
		}
	}
}

/**
 * returns 0 in case of extinction, 1 in case of exclusion and 2 in case of cohabitation
 **/
int Environnement::state(){
	
	//avec approximations
	/*if(cB+cA < H_*W_/300){
		return 0;
	}

	if(cB<cA*P_mut_ and cB!=0){
		return 1;
	}
	if(cA<cB/300 and cA!=0){
		return 1;
	}
	if(cB==0 and cA < 30){
		return 0;
	}
	if(cB ==0){
		return 1;
	}
	return 2;*/
	
	/*if(cB+cA < H_*W_/300){
		return 0;
	}

	if(cB<cA*0.01 and cB!=0){
		return 1;
	}
	if(cA<cB/1000 and cA!=0){
		return 1;
	}
	if(cB==0 and cA < 30){
		return 0;
	}
	if(cA==0 and cB <30){
		return 0;
	}
	if(cB ==0){
		return 1;
	}
	return 2; */
	
	//sans approximation
	
	if(cB == 0 and cA ==0){
		return 0;
	}
	if(cA == 0 or cB == 0){
		return 1;
	}		
	if(cB<cA*0.005 and cB!=0){
		return 1;
	}
	if(cA<cB*0.005 and cA!=0){
		return 1;
	}
	return 2;
}

float Environnement::Bpercentage(){
	
	if(cB+cA < H_*W_/300){
		return 0;
	}

	if(cB<cA*0.01 and cB!=0){
		return 1;
	}
	if(cA<cB/1000 and cA!=0){
		return 1;
	}
	if(cB==0 and cA < 30){
		return 0;
	}
	if(cB ==0){
		return 1;
	}
	return 2; 
	
	/*if(cB == 0 and cA ==0){
		return 0;
	}
	if(cB+cA<50){
		return 0;
	}
	else{
		float res = (float)(cB)/(float)(cA+cB);
		if(res<0.01 and cA+cB>100){
			return 1;
		}
		//cout << "ratio " << (float)(cB)/(float)(cA+cB) << " cB " << cB << " cA " << cA << endl;
		return 1.0+(float)(cB)/(float)(cA+cB);
	}*/
}

/**
 * Shows the concentrations of A organite in each case of the grid
 */
void Environnement::showA(){
	cout << "Concentration in glucose of the grid" << endl;
	float total = 0.0;
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			cout << grille[i][j].organites()[0] << " ";
			total+=grille[i][j].organites()[0];
		}
		cout << endl;
	}
	cout << "Glucose total : " << total << endl;
}

/**
 * Shows the concentrations of B organite in each case of the grid
 */
void Environnement::showB(){
	cout << "Concentration in Acetate of the grid" << endl;
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			cout << grille[i][j].organites()[1] << " ";
		}
		cout << endl;
	}
}

/**
 * Shows the concentrations of C organite in each case of the grid
 */
void Environnement::showC(){
	cout << "Concentration in Acetate of the grid" << endl;
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			cout << grille[i][j].organites()[2] << " ";
		}
		cout << endl;
	}
}


/**
 * applies a random death method to all the cells in the grid
 * and update the count of current living cells
 */
void Environnement::death(){
	int dead = 0;
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			dead = grille[i][j].death();
			if(dead==1){
				cA--;
				
			}
			if(dead==2){
				cB--;
			}	
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
	Case** grille_t;
	grille_t  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille_t[i] = new Case[W_];
	}
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille_t[i][j].set_organites(grille[i][j].organites());
		}
	}
	
	//showA();
	//cout << grille_t[1][1].organites()[0] << endl;
	//grid browse
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			
			//cout << " ####### diffusion sur case " << i << " " << j << endl;
			
	/*for (int i=1; i<4; i++){
		for(int j=1; j<4; j++){*/
			//vector of organites at time t
			vector <float> oldvec = grille_t[i][j].organites();
			vector <float> newvec = grille_t[i][j].organites();
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
					//cout << "Prends depuis la case " << v << " " << h << endl;
					//acquiring organites from neighbouring cells in a new vector 
					
					if(k==0 && l==0){
						for(int m=0; m<3; m++){
							newvec[m] = newvec[m] + D_*oldvec[m];
						}
					}
					else{
						//cout << "Ajout de A : " << D_*(grille_t[v][h].organites()[0]) << endl;
						//cout << "avant : " << newvec[0] << endl;
						for(int m=0; m<3; m++){
							
							newvec[m] = newvec[m] + D_*(grille_t[v][h].organites()[m]);
						}
					}
					//cout << "apres : " << newvec[0] << endl;
					//grille[i][j].set_organites(newvec);
				}
			}
			//cout << " grille_t : " << grille_t[i][j].organites()[0] <<endl;
			//losing organites to neighbouring cells
			//cout << "Je me retranche : " << 9*D_*oldvec[0] << endl;
			//vector <float> newvec2 = grille[i][j].organites();
			for(int m=0; m<3; m++){
				newvec[m] = newvec[m] - 9*D_*oldvec[m];
			}
			//final vector at time t+1
			//cout << " grille_t : " << grille_t[i][j].organites()[0] <<endl;
			grille[i][j].set_organites(newvec);
			//cout << " grille_t : " << grille_t[i][j].organites()[0] <<endl;
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
				//browsing neighbo	urhood
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
				if(fitness_max>0){
					//determines if the dividing cell will mutate
					float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					//fills the empty case with an adequate cell, changing its genotype if mutated
					char c = ' ';
					if((grille[h_max][v_max].containsA()==1)){
						if(random >= P_mut_){
							c='a';
						}
						else{
							c='b';
						}
					}
					else{
						if(random >= P_mut_){
							c='b';
						}
						else{
							c='a';
						}
					}
					vector <float> phen = grille[h_max][v_max].division();
					grille[i][j].set_cell(c,phen);
					if(c=='a'){
						cA++;
					}
					else{
						cB++;
					}
					if(random >= P_mut_){
						grille[h_max][v_max].set_cell(c,phen);
					}
				}
			}
		}
	}
}

/**
 * global simulation, from initial state to the state at a given time t
 * shows the state of the grid at aech step of time
 * ends the simulation if extinction or exclusion is detected before t to avoid useless computing
 * returns 0 in case of extinction, 1 in case of exclusion and 2 in case of cohabitation
 */
int Environnement::run(int t){
	show();
	int nb = 0;
	for (int i=0; i<t; i++){
		if(i%(T_) == 0){
			reset();
		}
		diffusion();
		death();
		competition();
		
		cout << "******************************************************* time " << i << endl;
		nb = show();
		for( int j=0; j<10; j++){
			metabolism();
		}
		if( nb == 0){
			break;
		}
	}
	return nb;
}

/**
 * similar as run, but does not display the grid for faster execution,
 * as it will be called repeatedly in the main function diagram
 */
float Environnement::run_diagram(int t){
	float nb = 0;
	int cpt = 0;
	for (int i=0; i<t; i++){
		if(i%(T_) == 0){
			reset();
		}
		diffusion();
		death();
		competition();
		for( int j=0; j<10; j++){
			metabolism();
		}
		
		nb = state();
		
		cpt++;
		//stops the run if the final state won't change anymore
		//(in case of extinction, or selection with no possible exctinction to come)
		if( nb == 0/* or (nb ==1 and Ainit_>0 and T_<400)*/){
			break;
		}
	}
	cout << "cA : " << cA << " cB : " << cB << " temps " << cpt << endl;
	return nb;
}



	
	
			

			
	
