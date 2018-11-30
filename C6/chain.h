#ifndef chain_
#define chain_
#include<iostream>
#include<sstream>//ostringstream
#include<algorithm>//min
#include "linearList.h"
#include"myExceptions.h"
#include"chainNode.h"
#include"arrayList.h"
template<typename> class chain;
template<typename T>
chain<T> listToChain(const arrayList<T>& theList)
{
	chain<T> theChain(theList.size());
	for (int i = 0; i < theList.size(); i++)
		theChain.insert(i, theList.get(i));
	return theChain;
}
template<typename T>
arrayList<T> chainToList(const chain<T>& theChain)
{
	arrayList<T> theList(theChain.size());
	for (int i = 0; i < theChain.size(); i++)
		theList.insert(i, theChain.get(i));
	cout << theList << endl;
	return theList;
}
template<typename T>
void reverse(chain<T> &theChain)
{
	auto size = theChain.size();
	for (int i = 0; i < size / 2; i++)
	{
		auto tmp = theChain.get(i);
		theChain.set(i, theChain.get(size - 1 - i));
		theChain.set(size - 1 - i, tmp);
	}
}
template<typename T>
chain<T> merge(const chain<T>& chainA, const chain<T>& chainB)
{
	chain<T> newChain(chainA.size() + chainB.size());
	for (int i = 0; i < chainA.size(); i++)
		newChain.push_back(chainA.get(i));
	for (int i = 0; i < chainB.size(); i++)
		newChain.push_back(chainB.get(i));
	//sort(newChain.begin(), newChain.end());
	return newChain;
}
template<typename T>
chain<T> meld(const chain<T>& chainA, const chain<T>& chainB)
{
	auto size = chainA.size() + chainB.size();
	chain<T> newChain(size);
	auto meldSize = min(chainA.size(), chainB.size());
	auto leftPart = max(chainA.size(), chainB.size()) - meldSize;
	for (int i = 0; i < meldSize; i++)
	{
		newChain.push_back(chainA.get(i));
		newChain.push_back(chainB.get(i));
	}
	if (chainA.size() > chainB.size())
		for (int i = meldSize; i < chainA.size(); i++)
			newChain.push_back(chainA.get(i));
	if (chainB.size() > chainB.size())
		for (int i = meldSize; i < chainB.size(); i++)
			newChain.push_back(chainB.get(i));
	cout << newChain << endl;
	return newChain;
}
template<typename T>
class chain :public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	//ADT
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase( int theIndex);
	void insert( int theIndex, const T& theElement);
	void output(ostream& out)const;
	class iterator;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(NULL); }
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
		chainNode<T>* node;
	};

	//excercise
	void setSize(int theSize);
	void set(int theIndex, const T& theElement);
	void removeRange(int fromIndex, int toIndex);
	int lastIndexOf(const T& theElement);
	T& operator[](int theIndex)const;
	bool operator==(const chain<T>& b)const;
	bool operator!=(const chain<T>& b)const;
	bool operator<(const chain<T>& b)const;
	bool operator>(const chain<T>& b)const;
	bool operator<=(const chain<T>& b)const;
	bool operator>=(const chain<T>& b)const;
	void swap(chain<T>& theChain);
	void fromList(const arrayList<T>& theList);
	void toList(arrayList<T>& theList);
	void leftShift(const int& i);
	void reverse();
	void merge(chain<T>& chainA, chain<T>& chainB);
	void meld(chain<T>& chainA, chain<T>& chainB);
	void split(chain<T>& chainA, chain<T>& chainB);
	void insertSort();

	//my method
	void push_back(const T& theElement);
	chainNode<T>* nodeOf(const int& theIndex);

public:
	void checkIndex(int theIndex)const;
	chainNode<T> *firstNode;
	int listSize;
};

template<typename T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}
template<typename T>
chain<T>::chain(const chain<T>& theList)
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

	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}
template<typename T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T> *nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
template<typename T>
void chain<T>::checkIndex(int theIndex)const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		cout << "checkIndex fail" << endl;
		ostringstream s;
		s << " index: " << theIndex << " size: " << listSize;
		throw illegalIndex(s.str());
	}
}
template<typename T>
T& chain<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		currentNode = currentNode->next;
	return currentNode->element;
}
template<typename T>
int chain<T>::indexOf(const T& theElement)const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != NULL && currentNode->element != theElement)
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
void chain<T>::erase( int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex-1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}
template<typename T>
void chain<T>::insert( int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
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
void chain<T>::output(ostream& out)const
{
	for (chainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
		out << currentNode->element << " ";
}
template<typename T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}
template<typename T>
void chain<T>::setSize(int theSize)
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
void chain<T>::set(int theIndex, const T& theElement)
{
	checkIndex(theIndex);
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		theNode = theNode->next;
	theNode->element = theElement;
}
template<typename T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
	checkIndex(fromIndex);
	checkIndex(toIndex);
	auto theIndex = fromIndex;
	for (int i = fromIndex; i <= toIndex; i++)
		erase(theIndex);
}
template<typename T>
int chain<T>::lastIndexOf(const T& theElement)
{
	chainNode<T>* theNode = firstNode;
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
T& chain<T>::operator[](int theIndex)const
{
	return get(theIndex);
}
template<typename T>
bool chain<T>::operator==(const chain<T>& b)const
{
	if (listSize != b.size())
		return false;
	for (int i = 0; i < listSize; i++)
	{
		if (this->get(i) != b.get(i))
			return false;
	}
	return true;
}
template<typename T>
bool chain<T>::operator!=(const chain<T>& b)const
{
	if (*this == b)
		return false;
	else
		return true;
}
template<typename T>
bool chain<T>::operator<(const chain<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
	{
		if (this->get(i) < b.get(i))
			return true;
		else if (this->get(i) > b.get(i))
			return false;
	}
	if (listSize < b.size())
		return true;
	else
		return false;
}
template<typename T>
bool chain<T>::operator>(const chain<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
	{
		if (this->get(i) > b.get(i))
			return true;
		else if (thie->get(i) < b.get(i))
			return false;
	}
	if (listSize > b.size())
		return true;
	else
		return false;
}
template<typename T>
bool chain<T>::operator<=(const chain<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
	{
		if (this->get(i) < b.get(i))
			return true;
		else if(this->get(i) > b.get(i))
			return false;
	}
	if (listSize > b.size())
		return false;
	else
		return true;
}
template<typename T>
bool chain<T>::operator>=(const chain<T>& b)const
{
	for (int i = 0; i < min(listSize, b.size()); i++)
	{
		if (this->get(i) > b.get(i))
			return true;
		else if (this->get(i) > b.get(i))
			return false;
	}
	if (listSize > b.size())
		return true;
	else
		return true;
}
template<typename T>
void chain<T>::swap(chain<T>& theChain)
{
	chainNode<T>* tmpNode = theChain.firstNode;
	theChain.firstNode = firstNode;
	firstNode = tmpNode;

	int tmpSize = theChain.size();
	theChain.listSize = listSize;
	listSize = tmpSize;
}

template<typename T>
void chain<T>::reverse()
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
void chain<T>::fromList(const arrayList<T>& theList) {
	this->setSize(theList.size());
	for (int i = 0; i < theList.size(); i++)
		this->insert(i, theList.get(i));
}
template<typename T>
void chain<T>::toList(arrayList<T>& theList) {
	theList.setSize(this->size());
	for (int i = 0; i < this->size(); i++)
		theList.insert(i, this->get(i));
}
template<typename T>
void chain<T>::leftShift(const int& i)
{
	for (int j = 0; j < i; j++)
		this->erase(0);
}
template<typename T>
chainNode<T>* chain<T>::nodeOf(const int& theIndex) {
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		theNode = theNode->next;
	return theNode;
}
template<typename T>
void chain<T>::meld(chain<T>& chainA, chain<T>& chainB)
{
	auto oldSize = listSize;
	for (int i = 0; i < oldSize; i++)
		this->erase(0);
	auto size = chainA.size() + chainB.size();
	auto meldSize = min(chainA.size(), chainB.size());
	auto leftPart = max(chainA.size(), chainB.size()) - meldSize;
	firstNode = new chainNode<T>(chainA.get(0), NULL);
	firstNode->next = new chainNode<T>(chainB.get(0), NULL);
	listSize += 2;
	chainNode<T>* theNode = firstNode->next;
	for (int i = 1; i < meldSize; i++)
	{
		theNode->next = new chainNode<T>(chainA.get(i),NULL);
		theNode = theNode->next;
		theNode->next = new chainNode<T>(chainB.get(i), NULL);
		theNode = theNode->next;
		listSize += 2;
	}
	if(chainA.size()>chainB.size())
		for (int i = meldSize; i < chainA.size(); i++)
		{
			theNode->next = new chainNode<T>(chainA.get(i), NULL);
			theNode = theNode->next;
		}
	if (chainA.size()<chainB.size())
	{
		for (int i = meldSize; i < chainB.size(); i++)
		{
			theNode->next = new chainNode<T>(chainB.get(i),NULL);
			theNode = theNode->next;
		}
	}
	auto sizeA = chainA.size();
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	auto sizeB = chainB.size();
	for (int i=0 ; i < sizeB; i++)
		chainB.erase(0);
}
template<typename T>
void chain<T>::merge(chain<T>& chainA, chain<T>& chainB)
{
	auto size = this->size();
	for(int i=0;i<size;i++)
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
void chain<T>::split(chain<T>& chainA, chain<T>& chainB)
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
void chain<T>::insertSort()
{
	/*
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
	*/
	
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
	///*
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
	chain<T> tChain(*this);
	for (int i = 0; i < listSize; i++)
		this->set(num[i], tChain.get(i));
	delete num;
	//*/
}
//my method
template<typename T>
void chain<T>::push_back(const T& theElement)
{
	if (this->size() == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
		listSize++;
		return;
	}
	chainNode<T>* theNode = firstNode;
	for (int i = 0; i < listSize-1; i++)
		theNode = theNode->next;
	theNode->next = new chainNode<T>(theElement, NULL);
	listSize++;
}

#endif // !chain_
