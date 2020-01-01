#pragma once
#include"Solver.h"
class QueueSolver : public Solver
{
public:
	QueueSolver(void);
	~QueueSolver(void);
//	void readInput(char* inputfile); // 상위 클래스로 이동
//	void printOutput(char* outputfile);
	virtual void solve();
};

