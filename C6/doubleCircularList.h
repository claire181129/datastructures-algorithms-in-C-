#include<iostream>
#include<sstream>
#include"extendedChainNode.h"
#include"myExceptions.h"
#include"arrayList.h"
using namespace std;
template<typename T>
class doubleCircularList {
public:
	doubleCircularList(int initialCapacity);
	doubleCircularList(const doubleCircularList<T>& theLsit);
	~doubleCircularList();

	//ADT method
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	class iterator;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(NULL); }
	class iterator {
	public:
		iterator(extendedChainNode<T>* theNode = NULL) { node = theNode; }

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
	void setSize(int theSize);
	void set(int theIndex, const T& theElement);
	void removeRange(int fromIndex, int toIndex);
	int lastIndexOf(const T& theElement)const;
	T& operator[](int theIndex)const;
	bool operator==(const doubleCircularList<T>& b)const;
	bool operator!=(const doubleCircularList<T>& b)const;
	bool operator<(const doubleCircularList<T>& b)const;
	bool operator>(const doubleCircularList<T>& b)const;
	bool operator<=(const doubleCircularList<T>& b)const;
	bool operator>=(const doubleCircularList<T>& b)const;
	void swap(doubleCircularList<T>& theChain);
	void fromList(const arrayList<T>& theList);
	void toList(arrayList<T>& theList)const;
	void leftShift(const int& i);
	void reverse();
	void merge(doubleCircularList<T>& chainA, doubleCircularList<T>& chainB);
	void meld(doubleCircularList<T>& chainA, doubleCircularList<T>& chainB);
	void split(doubleCircularList<T>& chainA, doubleCircularList<T>& chainB);
	void insertSort();
	void circularShift(const int& i);
	void zero() {
		firstNode = lastNode = NULL;
		listSize = 0;
	}
	//

	//
	void push_back(const T& theElement);
	void clear()
	{
		auto size = listSize;
		for (int i = 0; i < size; i++)
		{
			this->erase(0);
		}
	}
	chainNode<T>* nodeOf(const int& theIndex);
protected:
	void checkIndex(int theIndex)const;
	extendedChainNode<T>* firstNode;
	extendedChainNode<T>* lastNode;
	int listSize;
};
template<typename T>
doubleCircularList<T>::doubleCircularList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = lastNode = NULL;
	listSize = 0;
}
template<typename T>
doubleCircularList<T>::doubleCircularList(const doubleCircularList<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = lastNode = NULL;
		return;
	}
	extendedChainNode<T>* sourceNode = theList.firstNode;
	firstNode = new extendedChainNode<T>(sourceNode->element,NULL,NULL);

	sourceNode = sourceNode->next;
	extendedChainNode<T>* targetNode = firstNode;
	while (sourceNode != firstNode)
	{
		targetNode->next = new extendedChainNode<T>(sourceNode->element,NULL,targetNode);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = firstNode;
	lastNode = targetNode;
}
template<typename T>
doubleCircularList<T>::~doubleCircularList()
{
	while (firstNode != NULL)
	{
		extendedChainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
template<typename T>
void doubleCircularList<T>::checkIndex(int theIndex)const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		cout << "checkIndex fail" << endl;
		ostringstream s;
		s << "index: " << theIndex << " size: " << listSize;
		throw illegalIndex(s.str());
	}
}
template<typename T>
T& doubleCircularList<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	extendedChainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		currentNode = currentNode->next;
	return currentNode->element;
}
template<typename T>
int doubleCircularList<T>::indexOf(const T& theElement)const
{
	extendedChainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode->next != firstNode&&currentNode->element != theElement)
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
void doubleCircularList<T>::erase(int theIndex) {
	checkIndex(theIndex);
	extendedChainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		if (listSize == 1)
			firstNode = lastNode = NULL;
		else
		{
			firstNode = firstNode->next;
			firstNode->previous = NULL;
			lastNode->next = firstNode;
		}
	}
	else if (theIndex == listSize - 1)
	{
		deleteNode = lastNode;
		lastNode = lastNode->previous;
		lastNode->next = firstNode;
	}
	else
	{
		extendedChainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex-1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
		p->next->previous = p;
	} 
	listSize--;
	delete deleteNode;
}
template<typename T>
void doubleCircularList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
	if (theIndex == 0)
	{
		firstNode = new extendedChainNode<T>(theElement, firstNode, NULL);
		firstNode->next->previous = firstNode;
		lastNode->next = firstNode;
	}
	else
	{
		extendedChainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		p->next = new extendedChainNode<T>(theElement, p->next, p);
		p->next->next->previous = p->next;
	}
	if (theIndex == listSize)
	{
		lastNode = lastNode->next;
	}
	listSize++;
}
template<typename T>
void doubleCircularList<T>::output(ostream& out)const
{
	extendedChainNode<T>* currentNode;
	for (currentNode = firstNode; currentNode != NULL&&currentNode->next!=firstNode; currentNode = currentNode->next)
		out << currentNode->element << " ";
	if(currentNode)
		out << currentNode->element << " ";
}
template<typename T>
ostream& operator<<(ostream& out, const doubleCircularList<T>& theList)
{
	theList.output(out);
	return out;
}
template<typename T>
void doubleCircularList<T>::setSize(int theSize)
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
void doubleCircularList<T>::set(int theIndex, const T& theElement)
{
	checkIndex(theIndex);
	extendedChainNode<T>* theNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		theNode = theNode->next;
	theNode->element = theElement;
}
template<typename T>
void doubleCircularList<T>::removeRange(int fromIndex, int toIndex)
{
	checkIndex(fromIndex);
	checkIndex(toIndex);
	for (int i = fromIndex; i <= toIndex; i++)
		erase(fromIndex);
}
template<typename T>
int doubleCircularList<T>::lastIndexOf(const T& theElement)const
{
	extendedChainNode<T>* theNode = firstNode;
	int theIndex = 0;
	for (int i = 0; i < listSize; i++)
	{
		if (theNode->element == theElement)
			theIndex = i;
		theNode = theNode->next;
	}
	return theIndex;
}
template<typename T>
T& doubleCircularList<T>::operator[](int theIndex)const
{
	return get(theIndex);
}
template<typename T>
bool doubleCircularList<T>::operator==(const doubleCircularList<T>& b)const
{
	if (listSize != b.size())
		return false;
	for (int i = 0; i < listSize; i++)
		if (this->get(i) != b.get(i))
			return false;
	return true;
}
template<typename T>
bool doubleCircularList<T>::operator!=(const doubleCircularList<T>& b)const
{
	if (*this == b)
		return false;
	else
		return true;
}
template<typename T>
bool doubleCircularList<T>::operator<(const doubleCircularList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) < b.get(i))
			return true;
		else if (this->get(i) > b.get(i))
			return false;
	if (listSize < b.size())
		return true;
	else
		return false;
}
template<typename T>
bool doubleCircularList<T>::operator>(const doubleCircularList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) > b.get(i))
			return true;
		else if (this->get(i) < b.get(i))
			return false;
	if (listSize > b.size())
		return true;
	else
		return false;
}
template<typename T>
bool doubleCircularList<T>::operator<=(const doubleCircularList<T>& b)const
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
bool doubleCircularList<T>::operator>=(const doubleCircularList<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
		if (this->get(i) > b.get(i))
			return true;
		else if (this->get(i) < b.get(i))
			return false;
	if (listSize > b.size())
		return true;
	else
		return false;
}
template<typename T>
void doubleCircularList<T>::swap(doubleCircularList<T>& theList)
{
	extendedChainNode<T>* tmpNode = theList.firstNode;
	theList.firstNode = firstNode;
	firstNode = tmpNode;

	tmpNode = theList.lastNode;
	theList.lastNode = lastNode;
	lastNode = tmpNode;

	int tmpSize = theList.size();
	theList.listSize = listSize;
	listSize = tmpSize;
}

template<typename T>
void doubleCircularList<T>::fromList(const arrayList<T>& theList)
{
	this->clear();
	for (int i = 0; i < theList.size(); i++)
		this->push_back(theList.get(i));
}
template<typename T>
void doubleCircularList<T>::toList(arrayList<T>& theList)const
{
	theList.clear();
	for (int i = 0; i < this->size(); i++)
		theList.push_back(this->get(i));
}
template<typename T>
void doubleCircularList<T>::leftShift(const int& i)
{
	for (int j = 0; j < i; j++)
		this->erase(0);
}
template<typename T>
void doubleCircularList<T>::reverse()
{
	auto size = listSize;
	for (int i = 0; i < size / 2; i++)
	{
		auto tmp = this->get(i);
		this->set(i, this->get(size - 1 - i));
		this->set(size - 1 - i, tmp);
	}
}
template<typename T>
void doubleCircularList<T>::merge(doubleCircularList<T>& listA, doubleCircularList<T>& listB)
{
	this->clear();
	auto sizeA = listA.size();
	auto sizeB = listB.size();
	for (int i = 0; i < sizeA; i++)
		this->push_back(listA.get(i));
	for (int i = 0; i < sizeB; i++)
		this->push_back(listB.get(i));
	listA.clear();
	listB.clear();
}
template<typename T>
void doubleCircularList<T>::meld(doubleCircularList<T>& listA, doubleCircularList<T>& listB)
{
	this->clear();
	auto size = listA.size() + listB.size();
	auto meldSize = min(listA.size(), listB.size());
	auto leftPart = max(listA.size(), listB.size()) - meldSize;
	firstNode = new extendedChainNode<T>(listA.get(0), NULL, NULL);
	firstNode->next = new extendedChainNode<T>(listB.get(0), NULL, firstNode);
	listSize += 2;
	extendedChainNode<T>* theNode = firstNode->next;
	for (int i = 1; i < meldSize; i++)
	{
		theNode->next = new extendedChainNode<T>(listA.get(i), NULL, theNode);
		theNode = theNode->next;
		theNode->next = new extendedChainNode<T>(listB.get(i), NULL, theNode);
		theNode = theNode->next;
		listSize += 2;
	}
	if(listA.size()>listB.size())
		for (int i = meldSize; i < listA.size(); i++)
		{
			theNode->next = new extendedChainNode<T>(listA.get(i), NULL, theNode);
			theNode = theNode->next;
			listSize++;
		}
	if(listB.size()>listA.size())
		for (int i = meldSize; i < listB.size(); i++)
		{
			theNode->next = new extendedChainNode<T>(listB.get(i), NULL, theNode);
			theNode = theNode->next;
			listSize++;
		}
	theNode->next = firstNode;
	lastNode = theNode;
	listA.clear();
	listB.clear();
}
template<typename T>
void doubleCircularList<T>::split(doubleCircularList<T>& listA, doubleCircularList<T>& listB)
{
	auto sizeC = this->size();
	listA.clear();
	listB.clear();
	for (int i = 0; i < sizeC / 2; i++)
	{
		listA.push_back(this->get(i * 2));
		listB.push_back(this->get(i * 2 + 1));
	}
	if (sizeC % 2)
		listA.push_back(this->get(sizeC - 1));
}
template<typename T>
void doubleCircularList<T>::insertSort()
{
	
	for (int i = 0; i < listSize; i++)
	{
		T t = this->get(i);
		int j;
		for (j = i - 1; j >= 0 && t < this->get(j); j--)
		{
			this->get(j + 1) = this->get(j);
		}
		this->get(j + 1) = t;
	}
	
	
	//bubble
	/*
	for (int i = 0; i < listSize; i++)
	{
	for (int j = 0; j < listSize - 1 - i; j++)
	{
	if (this->get(j) > this->get(j + 1))
	{
	T t = this->get(j);
	this->get(j) = this->get(j + 1);
	this->get(j + 1) = t;
	}
	}
	}
	*/

	//selectionSort
	/*
	for (int i = 0; i < listSize; i++)
	{
	T max = this->get(i);
	for (int j = 0; j < listSize - i; j++)
	{
	if (this->get(j) > max)
	max = this->get(j);
	}
	for (int j = 0; j < listSize - i; j++)
	{
	if (this->get(j) == max)
	{
	T t = this->get(listSize - 1 - i);
	this->get(listSize - 1 - i) = this->get(j);
	this->get(j) = t;
	}
	}
	}
	*/

	//rankingSort 
	/*
	
	int* num = new int[listSize];
	for (int i = 0; i < listSize; i++)
	{
		num[i] = 0;
		for (int j = 0; j < listSize; j++)
		{
			if (this->get(j) < this->get(i))
				num[i]++;
			else if (this->get(j) == this->get(i) && j < i)
				num[i]++;
		}
	}
	doubleCircularList<T> tList(*this);
	for (int i = 0; i < listSize; i++)
		this->set(num[i], tList.get(i));
	delete num;
	*/
}
template<typename T>
void doubleCircularList<T>::circularShift(const int& i)
{
	for (int j = 0; j < i; j++)
	{
		extendedChainNode<T>* theNode = firstNode;
		auto tmp = theNode->element;
		for (int m = 0; m < listSize - 1; m++)
		{
			theNode->element = theNode->next->element;
			theNode = theNode->next;
		}
		theNode->element = tmp;
	}
}
template<typename T>
void doubleCircularList<T>::push_back(const T& theElement)
{
	if (this->size() == 0)
	{
		lastNode = firstNode = new extendedChainNode<T>(theElement, firstNode, NULL);
		firstNode->next = firstNode;
		listSize++;
		return;
	}
	extendedChainNode<T>* theNode = firstNode;
	for (int i = 0; i < listSize - 1; i++)
		theNode = theNode->next;
	theNode->next = new extendedChainNode<T>(theElement, firstNode, theNode);
	lastNode = theNode->next;
	listSize++;
}
