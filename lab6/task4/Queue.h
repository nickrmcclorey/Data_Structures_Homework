#pragma once
#include "Queue.h"
#include "EmptyQueueException.h"
#include <vector>
#include <string>
using namespace std;

template<class T>
class Queue
{
private:
	std::vector<T> queue;
	int numItems;
public:
	Queue();
	void enqueue(T);
    int length();
	T dequeue();
    T Peek();
	bool isEmpty() const;
	void clear();
};


template<class T>
Queue<T>::Queue() {
	numItems = 0;
}

template<class T>
void Queue<T>::enqueue(T item) 
{
	queue.push_back(item);
	numItems++;
}

template<class T>
T Queue<T>::dequeue()
{

	if (isEmpty()) {
		throw new EmptyQueueException;
	}
	else {
		T item = queue[0];
		queue.erase(queue.begin());
		numItems--;
        return item;
	}
}

template<class T>
T Queue<T>::Peek() {
    if (isEmpty()) {
        throw new EmptyQueueException;
    }
    return queue[0];
}

template<class T>
bool Queue<T>::isEmpty() const{
	bool status;

	if (numItems > 0) {
		status = false;
	}
	else {
		status = true;
	}
	
	return status;
}

template<class T>
void Queue<T>::clear() {
	queue.clear();
    numItems = 0;
}

template <class T>
int Queue<T>::length() {
    return queue.size();
}
