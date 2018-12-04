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
	int listSize;
};
template<typename T>
doubleLinkedList<T>::doubleLinkedList(const int& initialCapacity)
{

}
template<typename T>
doubleLinkedList<T>::doubleLinkedList(const doubleLinkedList<T>& theList)
{

}
template<typename T>
T& doubleLinkedList<T>::get(int theIndex)const
{

}
template<typename T>
int doubleLinkedList<T>::indexOf(const T& theElement)const
{


}
template<typename T>
void doubleLinkedList<T>::erase(int theIndex)
{

}
template<typename T>
void doubleLinkedList<T>::insert(int theIndex, const T& theElement)
{

}
template<typename T>
void doubleLinkedList<T>::output(ostream& out)const
{

}
template<typename T>
void doubleLinkedList<T>::push_back(const T& theElement)
{

}
template<typename T>
//exercise or other
void doubleLinkedList<T>::setSize(int theSize)
{

}
template<typename T>
void doubleLinkedList<T>::set(int theIndex, const T& theElement)
{

}
template<typename T>
void doubleLinkedList<T>::removeRange(int fromIndex, int toIndex)
{

}
template<typename T>
int doubleLinkedList<T>::lastIndexOf(const T& theElement)
{

}
template<typename T>
T& doubleLinkedList<T>::operator[](int theIndex)const
{

}
template<typename T>
bool doubleLinkedList<T>::operator==(const doubleLinkedList<T> &b)
{

}
template<typename T>
bool doubleLinkedList<T>::operator!=(const doubleLinkedList<T>& b)const
{

}
template<typename T>
bool doubleLinkedList<T>::operator<(const doubleLinkedList<T>& b)const
{

}
template<typename T>
bool doubleLinkedList<T>::operator>(const doubleLinkedList<T>& b)const
{

}
template<typename T>
bool doubleLinkedList<T>::operator<=(const doubleLinkedList<T>& b)const
{

}
template<typename T>
bool doubleLinkedList<T>::operator>=(const doubleLinkedList<T>& b)const
{

}
template<typename T>
void doubleLinkedList<T>::swap(doubleLinkedList<T>& theChain)
{

}
template<typename T>
void doubleLinkedList<T>::fromList(const arrayList<T>& theList)
{

}
template<typename T>
void doubleLinkedList<T>::toList(arrayList<T>& theList)
{

}
template<typename T>
void doubleLinkedList<T>::leftShift(const int& i)
{

}
template<typename T>
void doubleLinkedList<T>::reverse()
{

}
template<typename T>
void doubleLinkedList<T>::merge(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB)
{

}
template<typename T>
void doubleLinkedList<T>::meld(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB)
{

}
template<typename T>
void doubleLinkedList<T>::split(doubleLinkedList<T>& chainA, doubleLinkedList<T>& chainB)
{

}
template<typename T>
void doubleLinkedList<T>::insertSort()
{

}
template<typename T>
void doubleLinkedList<T>::checkIndex(int theIndex)const
{

}