#include<iostream>
#include<fstream>
#include"Stack.h"
#include "StackSolver.h"

using namespace std;

StackSolver::StackSolver(void)
{
}


StackSolver::~StackSolver(void)
{
}

// Solver class로 이동함
// void StackSolver::readInput(char* inputfile){

// Solver class로 이동함
// void StackSolver::printOutput(char* outputfile){

void StackSolver::solve()
{
	Stack *pStack = new Stack(size * size); // 가상 최대 크기로 스택을 만든다.
	// 방분여부 표시
	// maze의 형태가 정방형이라고 가정한다
	int **visited = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		visited[i] = (int*)malloc(sizeof(int)*size);
		for (int j = 0; j < size; j++) {
			visited[i][j] = 0;
		}
	}

	stackxy start = { 1, 1 };
	stackxy current = start;
	stackxy goal = { size - 2, size - 2 };

	pStack->push(start);
	while (!pStack->IsEmpty()) {
		current = pStack->getTop();
		if (current.row == goal.row && current.col == goal.col) {
			break;
		}
		visited[current.row][current.col] = 1;

		stackxy left, top, right, bottom;
		left = current; left.col -= 1;
		top = current; top.row -= 1;
		right = current; right.col += 1;
		bottom = current; bottom.row += 1;

		if (maze[left.row][left.col] == 0 && !visited[left.row][left.col]) {
			pStack->push(left);
		}
		else if (maze[top.row][top.col] == 0 && !visited[top.row][top.col]) {
			pStack->push(top);
		}
		else if (maze[right.row][right.col] == 0 && !visited[right.row][right.col]) {
			pStack->push(right);
		}
		else if (maze[bottom.row][bottom.col] == 0 && !visited[bottom.row][bottom.col]) {
			pStack->push(bottom);
		}
		else {
			pStack->pop();
		}
	}

	while (!pStack->IsEmpty()) {
		stackxy at = pStack->pop();
		maze[at.row][at.col] = 2;
	}

	delete pStack;
}