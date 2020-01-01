#include<iostream>
#include<fstream>
#include "Solver.h"
#include"StackSolver.h"
#include"QueueSolver.h"

using namespace std;

int main ( int argc, char* argv[] ){
	if ( argc < 4 ){
		return 1;
	}

	Solver* ss = new StackSolver();
	ss->readInput(argv[1]);
	ss->solve();
	ss->printOutput(argv[2]);
	
	Solver* qs = new QueueSolver();
	qs->readInput(argv[1]);
	qs->solve();
	qs->printOutput(argv[3]);

	delete ss;
	delete qs;

	return 0;
}
