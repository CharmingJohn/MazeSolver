#include "stdlib.h"
#include "Stack.h"

Stack::Stack(int s)
{
	size = s;
	top = 0;
	stack_n = (stackxy*)malloc(sizeof(stackxy) * size);
}


Stack::~Stack(void)
{
	delete stack_n;
}

int Stack::push(stackxy data)
{
	if (top < size) {
		stack_n[top] = data;
		top++;

		return top;
	}

	return -1; // 크기 초과, 더 넣을수 없다고 알려준다.
}

stackxy Stack::pop()
{
	if (top > 0) {
		top--;
		return stack_n[top];
	}

	return{ -1, -1 }; // 꺼낼 게 없다.
}

stackxy Stack::getTop()
{
	if (top > 0) {
		return stack_n[top-1];
	}

	return{ -1, -1 }; // 꺼낼 게 없다.
}
