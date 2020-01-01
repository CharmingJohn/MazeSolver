#include <iostream>
#include <fstream>
#include "Queue.h"
#include "QueueSolver.h"

using namespace std;

QueueSolver::QueueSolver(void)
{
}


QueueSolver::~QueueSolver(void)
{
}

#if 0 // 상위 클래스에서 상속해서 사용한다.
void QueueSolver::readInput(char* inputfile){
	ifstream file(inputfile);
	char ch;
	while (true){
		file.get(ch);
		size++;
		if (ch == '\n') break;
	}
	file.seekg(0, file.beg);

	maze = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		maze[i] = (int*)malloc(sizeof(int)*size);
	}

	int row = 0;
	int col = 0;
	while (!file.eof())
	{
		file.get(ch);
		if (ch == '\n'){
			//implement
		}
		else{
			//implement
		}
	}
	file.close();
}

void QueueSolver::printOutput(char* outputfile){
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
#endif

void QueueSolver::solve()
{
	Queue *pQueue = new Queue();

	// 방분여부 표시
	// maze의 형태가 정방형이라고 가정한다
	int **visited = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i<size; i++){
		visited[i] = (int*)malloc(sizeof(int)*size);
		for (int j = 0; j < size; j++) {
			visited[i][j] = 0;
		}
	}

	queuexy start;
	start.row = 1;
	start.col = 1;

	queuexy goal = { size - 2, size - 2, NULL };

	pQueue->enqueue(start);
	while (pQueue->peek() != NULL) {
		queuexy current;
		pQueue->dequeue(current);
		maze[current.row][current.col] = 2;

		if (current.row == goal.row && current.col == goal.col) {
			break;
		}
		visited[current.row][current.col] = 1;

		queuexy left, top, right, bottom;
		left = current; left.col -= 1;
		top = current; top.row -= 1;
		right = current; right.col += 1;
		bottom = current; bottom.row += 1;

		if (maze[left.row][left.col] == 0 && !visited[left.row][left.col]) {
			pQueue->enqueue(left);
		}
		if (maze[top.row][top.col] == 0 && !visited[top.row][top.col]) {
			pQueue->enqueue(top);
		}
		if (maze[right.row][right.col] == 0 && !visited[right.row][right.col]) {
			pQueue->enqueue(right);
		}
		if (maze[bottom.row][bottom.col] == 0 && !visited[bottom.row][bottom.col]) {
			pQueue->enqueue(bottom);
		}
	}

	delete pQueue;
}