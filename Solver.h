#pragma once
class Solver
{
protected: // �ڽ��� ���� �����ϵ���. �׼��� �Լ��� ���� ������ �׳� ����.
	int size;
	int** maze;

public:
	Solver(void);
	~Solver(void);
	virtual void readInput(char* inputfile); // �������� �Լ��� �����ش�.
	virtual void printOutput(char* outputfile);
	virtual void solve() = 0;

	void FreeMem();
};

