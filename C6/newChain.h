#include<iostream>
#include<sstream>
#include"linearList.h"
#include"chainNode.h"
#include"myExceptions.h"
using namespace std;
template<typename T>
class newChain :public chain<T>
{
public:
	newChain(int initialCapacity);
	void reset();
	T& void current();
	bool attend();
	bool atFront();
	void moveToNext();
	void moveToPrevious();

	//reload
	void push_back();
	void insert(int& theIndex, const T& theElement);
	void erase(int& theInde);
	int indexOf(const T& theElement);
private:
	chainNode<T>* p;
	chainNode<T>* l;
	T& currentElement;
};
template<typename T>
newChain<T>::newChain(int initialCapacity)
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
	p = firstNode;
	l = NULL;
	currentElement = p->element;
}
template<typename T>
void newChain<T>::reset()
{
	p = firstNode;
	l = NULL;
	currentElement = p->element;
}
template<typename T>
T& newChain<T>::current()
{
	if (p == NULL)
	{
		ostringstream s;
		s << "p point to NULL";
		throw illegalParameterValue(s.str());
	}
	return p->element;
}
template<typename T>
bool newChain<T>::attend()
{
	if (p->next == NULL)
		return true;
	else
		return false;
}
template<typename T>
bool newChain<T>::atFront()
{
	if (p == firstNode)
		return true;
	else
		return false;
}
template<typename T>
void newChian<T>::moveToNext()
{
	if (p->next == NULL)
	{
		ostringstream s;
		s << "p point to the last node";
		throw illegalParameterValue(s.str());
	}
	else
		p = p->next;
	if (l = NULL)
		l = firstNode;
	else if(i->next != NULL)
		l = l->next;
	else
	{
		ostringstream s;
		s << "l point to the last node";
		throw illegalParameterValue(s.str());
	}
}
template<typename T>
void newChain<T>::moveToPrevious()
{
	chainNode<T>* lastNode= NULL;
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < listSize - 1; i++)
	{
		if (theNode = p)
			p = lastNode;
		if (theNode = l)
			l = lastNode;
		lastNode = theNode;
		theNode = theNode->next;
	}
	currentElement = p->element;
}
