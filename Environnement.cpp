//==============================
//    INCLUDES
//==============================
#include "Environnement.h"
#include "Case.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Environnement::Environnement(){
	Ainit_ = 30;
	W_ = 32; 
	H_ = 32; 
	T_ = 1000;
	D_ = 0.1;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
}

Environnement::Environnement(float Ainit,int T,float D){
	Ainit_ = Ainit;
	W_ = 32; 
	H_ = 32; 
	T_ = T;
	D_ = D;
	grille  = new Case* [H_];
	for(int i=0; i<H_;i++){
		grille[i] = new Case[W_];
	}
	reset();	
	filling();
	
}
//==============================
//    DESTRUCTOR
//==============================


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
 * randomly fills the grid with W*H/2 cells A and W*H/2 B.
 */
void Environnement::filling(){
	int cptA=0;
	int cptB=0;
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if(cptA<W_*H_/2 && cptB<W_*H_/2){
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
			if(cptA==W_*H_/2){
				grille[i][j].set_cell('b');
			}
			if(cptB==W_*H_/2){
				grille[i][j].set_cell('a');
			}
		}
	}
}

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

void Environnement::death(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].death();
		}
	}
}

void Environnement::metabolism(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			grille[i][j].metabolism();
		}
	}
}
			
	
