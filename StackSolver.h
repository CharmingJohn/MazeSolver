#pragma once
#include"Solver.h"
class StackSolver : public Solver
{
public:
	StackSolver(void);
	~StackSolver(void);
//	void readInput(char* inputfile); // ���� Ŭ������ �̵�
//	void printOutput(char* outpuffile);
	virtual void solve();
};

