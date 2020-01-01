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
			free(maze[r]); // 각 행의 데이터 삭제
		free(maze); // 행을 가르키는 포인터 배열 삭제
	}
	maze = NULL;
}

void Solver::readInput(char* inputfile){
	ifstream file(inputfile);
	char ch;
	// size를 구한다.
	size = 0; // 초기화
	while (true){
		file.get(ch);
		if(ch == ' ' || ch == '#') size++; // CR이 있는 듯하다.
		if (ch == '\n') break;
	}
	file.seekg(0, file.beg); // 파일 처음으로

	// maze의 형태가 정방형이라고 가정한다
	maze = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		maze[i] = (int*)malloc(sizeof(int)*size);
	}

	int row = 0;
	int col = 0;
	while (row < size && !file.eof()) // 파일의 끝이 아닌 동안
	{
		file.get(ch);
		if (ch == '\n'){
			row++;
			col = 0;// 다음줄 시작
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
