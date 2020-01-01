#pragma once

typedef struct stackxy{
	int row;
	int col;
} stackxy;

class Stack
{
private:
	int top;
	stackxy *stack_n;
	int size;

public:
	bool IsEmpty() {
		return top == 0;
	};
	Stack(int s);
	~Stack(void);
	int push(stackxy data);
	stackxy pop();
	stackxy getTop();
};

