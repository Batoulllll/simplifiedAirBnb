#pragma once
//#include "MyQueue.cpp"

template <class T>
class MyQueue
{
	T* arr;
	int count, size;
	int front, back;
public:
	MyQueue();
	int length();
	void enqueue(T);
	void dequeue();
	T Front();
	bool empty();
	bool full();
	~MyQueue();
};


