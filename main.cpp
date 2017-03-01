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

/*
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
*/
using namespace std;

#include "Environnement.h"
#include "Case.h"
#include "Cell.h"
#include "CellA.h"
#include "CellB.h"

//==============================
//    FUNCTION DeCLARATION
//==============================

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{   
	Environnement env = Environnement();
	/*CellA c = CellA();
	char d = 'a' ; 
	vector <float> organites = {0.3,1.2,2.5};
	Case cas2= Case();
	Case cas = Case(organites, d);*/
	//Cell* ce = new CellA();
	
	//cas2.reset(23);
	//cout << cas2.organites()[0] << endl;
	
	env.show();
	env.death();
	env.metabolism();
	
	cout << ' ' << endl;
	env.show();
	
	env.death();
	env.metabolism();
	
	cout << ' ' << endl;
	env.show();
	
	cout << "avant" << endl;
	cout << env.get_case(3,1).organites()[0] << endl;
	cout << env.get_case(3,1).organites()[1] << endl;
	cout << env.get_case(3,1).organites()[2] << endl;
	
	env.diffusion();
	env.metabolism();
	
	cout << "après" << endl;
	
	cout << env.get_case(3,1).organites()[0] << endl;
	cout << env.get_case(3,1).organites()[1]<< endl;
	cout << env.get_case(3,1).organites()[2]<< endl;
	
  return 0;
}
