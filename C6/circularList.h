
#include<iostream>
#include<sstream>
#include<algorithm>
#include"chainNode.h"
#include"myExceptions.h"
#include"linearList.h"
#include"chain.h"
#include"extendedChain.h"
#include"arrayList.h"
using namespace std;
template<typename T>
class circularList: public chain<T>
{
public:
	circularList(int initialCapacity) :chain<T>(initialCapacity) {}
	circularList(const circularList<T>& theList);
	~circularList();
	//ADL method
	void erase(int theIndex);
	int indexOf(const T& theElement)const;
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	iterator end();
	//exercise
	void meld(circularList<T>& chainA, circularList<T>& chainB);
	void merge(circularList<T>& chainA, circularList<T>& chainB);
	void split(circularList<T>& chainA, circularList<T>& chainB);
	//my method
	void push_back(const T& theElement);
protected:
};

template<typename T>
circularList<T>::circularList(const circularList<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);

	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while (sourceNode->next != theList.firstNode)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = new chainNode<T>(sourceNode->element);
	targetNode = targetNode->next;
	targetNode->next = firstNode;
}
template<typename T>
circularList<T>::~circularList()
{
	if (firstNode)
	{
		while (firstNode->next != firstNode)
		{
			chainNode<T> *nextNode = firstNode->next;
			chainNode<T>* theNode = firstNode;
			while (theNode->next != firstNode)
			{
				theNode = theNode->next;
			}
			delete firstNode;
			theNode->next = firstNode = nextNode;
		}
		delete firstNode;
		firstNode = NULL;
	}
}
template<typename T>
void circularList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
		firstNode->next = firstNode;
	}
	else
	{
		chainNode<T> *p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}
template<typename T>
void circularList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	
	chainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		chainNode<T>* theNode = firstNode;
		for (int i = 0; i < listSize - 1; i++)
			theNode = theNode->next;
		theNode->next = firstNode;

		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
	if (listSize == 0)
		firstNode = NULL;
}
template<typename T>
int circularList<T>::indexOf(const T& theElement)const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode->next != firstNode && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode->element == theElement)
		index++;
	if (currentNode == NULL)
		return -1;
	else
		return index;
}
template<typename T>
void circularList<T>::output(ostream& out)const
{
	if (listSize != 0)
	{
		chainNode<T>* currentNode;
		for (currentNode = firstNode; currentNode->next != firstNode; currentNode = currentNode->next)
			out << currentNode->element << " ";
		out << currentNode->element;
	}
}
template<typename T>
ostream& operator<<(ostream& out, const circularList<T>& x)
{
	x.output(out);
	return out;
}
template<typename T>
void circularList<T>::meld(circularList<T>& chainA, circularList<T>& chainB)
{
	auto oldSize = listSize;
	for (int i = 0; i < oldSize; i++)
		this->erase(0);
	auto meldSize = min(chainA.size(), chainB.size());
	firstNode = new chainNode<T>(chainA.get(0), NULL);
	firstNode->next = new chainNode<T>(chainB.get(0), NULL);
	listSize += 2;
	chainNode<T>* theNode = firstNode->next;
	for (int i = 1; i < meldSize; i++)
	{
		theNode->next = new chainNode<T>(chainA.get(i), NULL);
		theNode = theNode->next;
		theNode->next = new chainNode<T>(chainB.get(i), NULL);
		theNode = theNode->next;
		listSize += 2;
	}
	if (chainA.size()>chainB.size())
		for (int i = meldSize; i < chainA.size(); i++)
		{
			theNode->next = new chainNode<T>(chainA.get(i), NULL);
			theNode = theNode->next;
			listSize++;
		}
	if (chainA.size()<chainB.size())
	{
		for (int i = meldSize; i < chainB.size(); i++)
		{
			theNode->next = new chainNode<T>(chainB.get(i), NULL);
			theNode = theNode->next;
			listSize++;
		}
	}
	theNode->next = firstNode;
	auto sizeA = chainA.size();
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	auto sizeB = chainB.size();
	for (int i = 0; i < sizeB; i++)
		chainB.erase(0);
}
template<typename T>
void circularList<T>::merge(circularList<T>& chainA, circularList<T>& chainB)
{
	auto size = this->size();
	for (int i = 0; i<size; i++)
		this->erase(0);

	auto sizeA = chainA.size();
	auto sizeB = chainB.size();
	for (int i = 0; i < sizeA; i++)
	{
		this->push_back(chainA.get(i));
	}
	for (int i = 0; i < sizeB; i++)
	{
		this->push_back(chainB.get(i));
	}
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	for (int i = 0; i < sizeB; i++)
		chainB.erase(0);
}
template<typename T>
void circularList<T>::split(circularList<T>& chainA, circularList<T>& chainB)
{
	auto sizeA = chainA.size();
	auto sizeB = chainB.size();
	auto sizeC = this->size();
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	for (int i = 0; i < sizeB; i++)
		chainB.erase(0);
	for (int i = 0; i < sizeC / 2; i++)
	{
		chainA.push_back(this->get(i * 2));
		chainB.push_back(this->get(i * 2 + 1));
	}
	if (sizeC % 2)
		chainA.push_back(this->get(sizeC - 1));
}
template<typename T>
void circularList<T>::push_back(const T& theElement)
{
	if (this->size() == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
		firstNode->next = firstNode;
		listSize++;
		return;
	}
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < listSize - 1; i++)
		theNode = theNode->next;
	theNode->next = new chainNode<T>(theElement, firstNode);
	listSize++;
}