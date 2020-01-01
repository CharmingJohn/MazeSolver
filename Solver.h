#pragma once
class Solver
{
protected: // 자식이 접근 가능하도록. 액세스 함수를 만들어도 되지만 그냥 하자.
	int size;
	int** maze;

public:
	Solver(void);
	~Solver(void);
	virtual void readInput(char* inputfile); // 순수가상 함수를 막아준다.
	virtual void printOutput(char* outputfile);
	virtual void solve() = 0;

	void FreeMem();
};

