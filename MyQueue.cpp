#include "MyQueue.h"
#include <iostream>
#include <assert.h>

template <class T>
MyQueue<T>::MyQueue()
{
	size = 5;
	count = 0;
	front = back = -1;
	arr = new T[size];
}

template <class T>
int MyQueue<T>::length()
{
	return count;
}

template <class T>
void MyQueue<T>::enqueue(T val)
{
	assert(!full());
	if (count == 0)
		front = 0;
	back = (back + 1) % size;
	arr[back] = val;
	count++;
}

template <class T>
void MyQueue<T>::dequeue()
{
	assert(!empty());
	if (count == 1)
		front = back = -1;
	else
		front = (front + 1) % size;
	count--;
}

template <class T>
T MyQueue<T>::Front()
{
	assert(!empty());
	return arr[front];
}

template <class T>
bool MyQueue<T>::full()
{
	return (count == size);
}

template <class T>
bool MyQueue<T>::empty()
{
	return (count == 0);
}


template <class T>
MyQueue<T>::~MyQueue(void)
{
	delete[] arr;
}
