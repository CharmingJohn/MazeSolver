#pragma once
#include"Solver.h"
class StackSolver : public Solver
{
public:
	StackSolver(void);
	~StackSolver(void);
//	void readInput(char* inputfile); // 상위 클래스로 이동
//	void printOutput(char* outpuffile);
	virtual void solve();
};

