#include<iostream>
#include<sstream>
#include"myExceptions.h"
#include"extendedChainNode.h"
#include"arrayList.h"
using namespace std;
template<typename T>
class doubleLinkedList {
public:
	doubleLinkedList(const int& initialCapacity);
	doubleLinkedList(const doubleLinkedList<T>& theList);

	//ADT method
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	//iterator
	class iterator;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(firstNode->previous); }
	class iterator {
	public:
		iterator(chainNode<T>* theNode = NULL) { node = theNode; }

		T& operator*()const { return node->element; }
		T* operator->()const { return &node->element; }

		iterator& operator++() {
			node = node->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			node = node->next;
			return old;
		}
		bool operator!=(const iterator right)const
		{
			return node != right.node;
		}
		bool operator==(const iterator right)const
		{
			return node == right.node;
		}
	protected:
		extendedChainNode<T>* node;
	};
	//my method
	void push_back(const T& theElement);
	//exercise or other
	void setSize(int theSize);
	void set(int theIndex, const T& theElement);
	void removeRange(int fromIndex, int toIndex);
	int lastIndexOf(const T& theElement);
	T& operator[](int theIndex)const;
	bool operator==(const doubleLinkedList<T> &b);
	bool operator!=(const doubleLinkedList<T>& b)const;
	bool operator<(const doubleLinkedList<T>& b)const;
	bool operator>(const doubleLinkedList<T>& b)const;
	bool operator<=(const doubleLinkedList<T>& b)const;
	bool operator>=(const doubleLinkedList<T>& b)const;
	void swap(doubleLinkedList<T>& theChain);
	void fromList(const arrayList<T>& theList);
	void toList(arrayList<T>& theList);
	void leftShift(const int& i);
	void reverse();
	void merge(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB);
	void meld(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB);
	void split(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB);
	void insertSort();
protected:
	void checkIndex(int theIndex)const;
	extendedChainNode<T>* firstNode;
	extendedChainNode<T>* lastNode;
	int listSize;
};
template<typename T>
doubleLinkedList<T>::doubleLinkedList(const int& initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = lastNode = NULL;
	listSize = 0;
}
template<typename T>
doubleLinkedList<T>::doubleLinkedList(const doubleLinkedList<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = lastNode = NULL;
		return;
	}
	extendedChainNode<T>* sourceNode = theList.firstNode;
	firstNode = new extendedChainNode<T>(sourceNode->element);

	sourceNode = sourceNode->next;
	extendedChainNode<T>* targetNode = firstNode;
	while (sourceNode != NULL)
	{
		targetNode->next = new extendedChainNode<T>(sourceNode->element,NULL,targetNode);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
	lastNode = taegetNode;
}
template<typename T>
T& doubleLinkedList<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	if (theIndex < listSize / 2)
	{
		extendedChainNode<T>* currentNode = firstNode;
		for (int i = 0; i < theIndex; i++)
			currentNode = currentNode->next;
		return currentNode->element;
	}
	else
	{
		extendedChainNode<T>* currentNode = lastNode;
		for (int i = listSize-1; i > theIndex; i--)
			currentNode = currentNode->previous;
		return currentNode->element;
	}
}
template<typename T>
int doubleLinkedList<T>::indexOf(const T& theElement)const
{
	extendedChainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != NULL&&currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == NULL)
		return -1;
	else
		return index;
}
template<typename T>
void doubleLinkedList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	extendedChainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
		firstNode->previous = NULL;
	}
	else if (theIndex == listSize - 1)
	{
		deleteNode = lastNode;
		lastNode = lastNode->previous;
		lastNode->next = NULL;
	}
	else
	{
		extendedChainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
		p->next->previous = p;
	}
	listSize--;
	delete deleteNode;
}
template<typename T>
void doubleLinkedList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
	if (theIndex == 0)
	{
		if (listSize == 0)
		{
			firstNode = new extendedChainNode<T>(theElement, firstNode,firstNode);
			lastNode = firstNode;
		}
		else
		{
			firstNode = new extendedChainNode<T>(theElement, firstNode, NULL);
			firstNode->next->previous = firstNode;
		}	
	}
	else if (theIndex == listSize - 1)
	{
		lastNode = new extendedChainNode<T>(theElement, NULL, lastNode);
		lastNode->previous->next = lastNode;
	}
	else
	{
		extendedChainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		p->next = new extendedChainNode<T>(theElement, p->next,p);
		p->next->next->previous = p->next;
	}
	listSize++;
}
template<typename T>
void doubleLinkedList<T>::output(ostream& out)const
{

}
template<typename T>
void doubleLinkedList<T>::push_back(const T& theElement)
{
	for (extendedChainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
		out << currentNode->element << " ";
}
template<typename T>
//exercise or other
void doubleLinkedList<T>::setSize(int theSize)
{
	if (listSize < theSize)
		return;
	else if (listSize > theSize)
	{
		int theIndex = theSize;
		int num = listSize;
		for (int i = theSize; i < num; i++)
			erase(theIndex);
	}
}
template<typename T>
void doubleLinkedList<T>::set(int theIndex, const T& theElement)
{
	checkIndex(theIndex);
	extendedChainNode<T>* theNode = firstNode;
	if (theIndex < listSize / 2)
	{
		for (int i = 0; i < theIndex; i++)
			theNode = theNode->next;
	}
	else
	{
		theNode = lastNode;
		for (int i = listSize - 1; i > theIndex; i--)
			theNode = theNode->previous;
	}
	theNode->element = theElement;
}
template<typename T>
void doubleLinkedList<T>::removeRange(int fromIndex, int toIndex)
{
	checkIndex(fromIndex);
	checkIndex(toIndex);
	auto theIndex = fromIndex;
	for (int i = fromIndex; i <= toIndex; i++)
		erase(theIndex);
}
template<typename T>
int doubleLinkedList<T>::lastIndexOf(const T& theElement)
{
	extendedChainNode<T>* theNode = firstNode;
	int theIndex = 0;
	for (int i = 0; i < listSize; i++)
	{
		if (theNode->element == theElement)
			theIndex = i;
		theNode = theNode->next;
	}
	return theInde;
}
template<typename T>
ostream& operator<<(ostream& out, const extendedChainNode<T>& x)
{
	x.output(out);
	return out;
}
template<typename T>
T& doubleLinkedList<T>::operator[](int theIndex)const
{
	return get(theIndex);
}
template<typename T>
bool doubleLinkedList<T>::operator==(const doubleLinkedList<T> &b)
{
	if (listSize != b.size())
		return false;
	for (int i = 0; i < listSize; i++)
		if (this->get(i) != b.get(i))
			return false;
	return true;
}
template<typename T>
bool doubleLinkedList<T>::operator!=(const doubleLinkedList<T>& b)const
{
	if (*this == b)
		return false;
	else
		return true;
}
template<typename T>
bool doubleLinkedList<T>::operator<(const doubleLinkedList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) < b.get())
			return true;
		else if (this->get(i) > b.get(i))
			return false;
	if (listSize < b.size())
		return true;
	else
		return false;
}
template<typename T>
bool doubleLinkedList<T>::operator>(const doubleLinkedList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) > b.get(i))
			return true;
		else if (this->get(i) < b.get(i))
			return fales;
	if (listSize > b.size())
		return true;
	else
		return false;
}
template<typename T>
bool doubleLinkedList<T>::operator<=(const doubleLinkedList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) < b.get(i))
			return true;
		else if (this->get(i) > b.get(i))
			return false;
	if (listSize > b.size())
		return false;
	else
		return true;
}
template<typename T>
bool doubleLinkedList<T>::operator>=(const doubleLinkedList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) > b.get(i))
			return true;
		else if (this->get(i) > b.get(i))
			return false;
	if (listSize > b.size())
		return true;
	else
		return false;
}
template<typename T>
void doubleLinkedList<T>::swap(doubleLinkedList<T>& theChain)
{
	extendedChainNode<T>* tmpNode = theChain.firstNode;
	theChain.firstNode = firstNode;
	firstNode = tmpNode;

	int tmpSize = theChain.size();
	theChain.listSize = listSize;
	listSize = tmpSize;
}
template<typename T>
void doubleLinkedList<T>::fromList(const arrayList<T>& theList)
{
	this->setSize(theList.size())
		for (int i = 0; i < theList.size(); i++)
			this->insert(i, theList.get(i));
}
template<typename T>
void doubleLinkedList<T>::toList(arrayList<T>& theList)
{
	theList.setSize(this->size());
	for (int i = 0; i < this->size(); i++)
		theList.insert(i, this->get(i));
}
template<typename T>
void doubleLinkedList<T>::leftShift(const int& i)
{
	for (int j = 0; j < i; j++)
		this->erase(0);
}
template<typename T>
void doubleLinkedList<T>::reverse()
{
	auto size = listSize;
	for (int i = 0; i < size / 2; i++)
	{
		auto tmp = this->get(i);
		this->set(i, this->get(size - 1 - i));
		this->set(size - 1 - i,tmp);
	}
}
template<typename T>
void doubleLinkedList<T>::merge(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB)
{
	auto size = listSize;
	for (int i = 0; i < size; i++)
		this->erase(0);
	auto sizeA = chainA.size();
	auto sizeB = chainB.size();
	for (int i = 0; i < sizeA; i++)
		this->push_back(chainA.get(i));
	for (int i = 0; i < chainB.size(); i++)
		this->push_back(chainB.get(i));
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	for (int i = 0; i < sizeB; i++)
		chainB.erase(0);
}
template<typename T>
void doubleLinkedList<T>::meld(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB)
{
	auto oldSize = listSize;
	for (int i = 0; i < listSize; i++)
		this->erase(0);
	auto size = chainA.size() + chainB.size();
	auto meldSize = min(chainA.size(), chainB.size());
	auto leftPart = max(chainA.size(), chainB.size()) - meldSize;
	firstNode = new extendedChainNode<T>(chainA.get(0), NULL,NULL);
	lastNode = firstNode;
	firstNode->next = new extendedChainNode<T>(chainB.get(0), NULL);
	lastNode = firstNode->next;
	listSize += 2;
	extendedChainNode<T>* theNode = firstNode->next;
	for (int i = 1; i < meldSize; i++)
	{
		theNode->next = new extendedChainNode<T>(chainA.get(i), NULL,theNode);
		theNode = theNode->next;
		theNode->next = new extendedChainNode<T>(chainB.get(i), NULL, theNode);
		theNode = theNode->next;
		listSize += 2;
	}
	if(chainA.size()>chainB.size())
		for (int i = meldSize; i < chainA.size(); i++)
		{
			theNode->next = new extendedChainNode<T>(chainA.get(i), NULL, theNode);
			theNode = theNode->next;
		}
	if(chainA.size()<chainB.size())
		for (int i = meldSize; i < chainB.size(); i++)
		{
			theNode->next = new extendedChainNode<T>(chainB.get(i), NULL, theNode);
			theNode = theNode->next;
		}
	auto sizeA = chainA.size();
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	auto sizeB = chainB.size();
	for (int i = 0; i < sizeB; i++)
		chainB.erase(0);
}
template<typename T>
void doubleLinkedList<T>::split(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB)
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
void doubleLinkedList<T>::insertSort()
{

}
template<typename T>
void doubleLinkedList<T>::checkIndex(int theIndex)const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		cout << "checkIndex fail" << endl;
		ostringstream s;
		s << "index: " << theIndex << " size: " << listSize;
		throw illegalIndex(s.str());
	}
}