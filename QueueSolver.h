#pragma once
#include"Solver.h"
class QueueSolver : public Solver
{
public:
	QueueSolver(void);
	~QueueSolver(void);
//	void readInput(char* inputfile); // ���� Ŭ������ �̵�
//	void printOutput(char* outputfile);
	virtual void solve();
};

