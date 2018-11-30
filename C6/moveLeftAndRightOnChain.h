#include"linearList.h"
#include"chainNode.h"
#include"chain.h"
#include<iostream>
using namespace std;
template<typename T>
class moveLeftAndRightOnChain : public chain<T>
{
public:
	moveLeftAndRightOnChain(int initialCapacity);
	void moveRight();
	void moveLeft();
	T& currentElement();
	T& previousElement();
	void push_back(const T& theElement);
private:
	chainNode<T>* p;
	chainNode<T>* l;
};
template<typename T>
void moveLeftAndRightOnChain<T>::push_back(const T& theElement)
{
	if (this->size() == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
		listSize++;
		p = firstNode;
		return;
	}
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < listSize - 1; i++)
		theNode = theNode->next;
	theNode->next = new chainNode<T>(theElement, NULL);
	listSize++;
}
template<typename T>
moveLeftAndRightOnChain<T>::moveLeftAndRightOnChain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
	p = firstNode;
	l = NULL;
}
template<typename T>
void moveLeftAndRightOnChain<T>::moveLeft()
{
	chainNode<T>* lastNode = NULL;
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < listSize; i++)
	{
		if (theNode == p)
			p = lastNode;
		lastNode = theNode;
		theNode = theNode->next;
	}
	lastNode = NULL;
	theNode = firstNode;
	for (int i = 0; i < listSize; i++)
	{
		if (theNode == l)
			l = lastNode;
		lastNode = theNode;
		theNode = theNode->next;
	}
}

template<typename T>
void moveLeftAndRightOnChain<T>::moveRight()
{
	if (p != NULL)
		p = p->next;
	else
		p = firstNode;
	if (l != NULL)
		l = l->next;
	else
		l = firstNode;
	
}

template<typename T>
T& moveLeftAndRightOnChain<T>::currentElement()
{
	return p->element;
}

template<typename T>
T& moveLeftAndRightOnChain<T>::previousElement()
{
	return l->element;
}
