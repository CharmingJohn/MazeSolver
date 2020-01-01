#include "Solver.h"
#include<iostream>
#include<fstream>

using namespace std;

Solver::Solver(void)
{
	maze = NULL;
}


Solver::~Solver(void)
{
	FreeMem();
}

void Solver::FreeMem()
{
	if (maze != NULL) {
		for (int r = 0; r < size; r++)
			free(maze[r]); // �� ���� ������ ����
		free(maze); // ���� ����Ű�� ������ �迭 ����
	}
	maze = NULL;
}

void Solver::readInput(char* inputfile){
	ifstream file(inputfile);
	char ch;
	// size�� ���Ѵ�.
	size = 0; // �ʱ�ȭ
	while (true){
		file.get(ch);
		if(ch == ' ' || ch == '#') size++; // CR�� �ִ� ���ϴ�.
		if (ch == '\n') break;
	}
	file.seekg(0, file.beg); // ���� ó������

	// maze�� ���°� �������̶�� �����Ѵ�
	maze = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		maze[i] = (int*)malloc(sizeof(int)*size);
	}

	int row = 0;
	int col = 0;
	while (row < size && !file.eof()) // ������ ���� �ƴ� ����
	{
		file.get(ch);
		if (ch == '\n'){
			row++;
			col = 0;// ������ ����
		}
		else{
			switch (ch){
			case ' ':
				if(col < size) maze[row][col++] = 0;
				break;
			case '#':
				if(col < size) maze[row][col++] = 1;
				break;
			}
		}
	}
	file.close();
}

void Solver::printOutput(char* outputfile){
	ofstream file = ofstream(outputfile);
	for (int i = 0; i<size; i++){
		for (int j = 0; j<size; j++){
			if (maze[i][j] == 1) file.put('#');
			if (maze[i][j] == 0) file.put(' ');
			if (maze[i][j] == 2) file.put('@');
		}
		file.put('\n');
	}
	file.close();
}
