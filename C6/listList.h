#include<list>
#include<iostream>
#include<sstream>
#include<algorithm>
#include"myExceptions.h"
#include"arrayList.h"
using namespace std;
template<typename T>
class listList
{
public:
	listList(int initialCapacity);
	listList(const listList<T>& theList);
	~listList() { delete element; }

	//ADT method
	bool empty()const { return element->empty(); }
	int size()const { return (int)element->size(); }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	//additinoal method
	void setSize(int theSize);
	void set(int theIndex, const T& theElement);
	void removeRange(int fromIndex, int toIndex);
	int lastIndexOf(const T& theElement)const;
	T& operator[](int theIndex)const;
	bool operator==(const listList<T>& theList);
	bool operator!=(const listList<T>& theList);
	bool operator<(const listList<T>& theList);
	bool operator>(const listList<T>& theList);
	bool operator<=(const listList<T>& theList);
	bool operator>=(const listList<T>& theList);
	void swap(listList<T>& theList);
	void fromList(const arrayList<T>& theList);
	void toList(arrayList<T>& theList);
	void leftShift(const int& i);
	void reverse();
	void merge(listList<T>& listA, listList<T>& listB);
	void meld(listList<T>& listA, listList<T>& listB);
	void split(listList<T>& listA, listList<T>& listB);
	void insertSort();
	void circularShift(const int& i);
	void zero();
	void push_back(const T& theElement);
	void clear();

	//iterator
	typedef typename list<T>::iterator iterator;
	iterator begin() { return element->begin(); }
	iterator end() { return element->end(); }
protected:
	void checkIndex(int theIndex)const;
	list<T>* element;
};
template<typename T>
listList<T>::listList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterValue(s.str());
	}
	element = new list<T>;
	//element->reserve(initialCapacity);
}
template<typename T>
listList<T>::listList(const listList<T>& theList)
{
	element = new list<T>(*theList.element);
}
template<typename T>
T& listList<T>::get(int theIndex)const
{
	auto it = element->begin();
	for (int i = 0; i < theIndex; i++)
		it++;
	return *it;
}
template<typename T>
int listList<T>::indexOf(const T& theElement)const
{
	auto it = element->begin();
	for (int i = 0; i < element->size(); i++)
	{
		if (*it == theElement)
			return i;
		it++;
	}
}
template<typename T>
void listList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	auto it = begin();
	for (int i = 0; i < theIndex; i++)
		it++;
	element->erase(it);
}
template<typename T>
void listList<T>::insert(int theIndex, const T& theElement)
{
	auto it = begin();
	for (int i = 0; i < theIndex; i++)
		it++;
	element->insert(it, theElement);
}
template<typename T>
void listList<T>::output(ostream& out)const
{
	copy(element->begin(), element->end(), ostream_iterator<T>(out, " "));
}
template<typename T>
ostream& operator<<(ostream& out, const listList<T>& theList)
{
	theList.output(out);
	return out;
}
//additinoal method
template<typename T>
void listList<T>::setSize(int theSize)
{
	element->resize(theSize);
}
template<typename T>
void listList<T>::set(int theIndex, const T& theElement)
{
	auto it = element->begin();
	for (int i = 0; i < theIndex; i++)
		it++;
	*it = theElement;
}
template<typename T>
void listList<T>::removeRange(int fromIndex, int toIndex)
{
	
	for (int i = fromIndex; i <= toIndex; i++)
	{
		auto it = element->begin();
		for (int i = 0; i < fromIndex; i++)
			it++;
		element->erase(it);
	}
		
}
template<typename T>
int listList<T>::lastIndexOf(const T& theElement)const
{
	int theIndex = -1;
	auto it = element->begin();
	for (int i = 0; i < element->size(); i++)
	{
		if (*it == theElement)
			theIndex = i;
		it++;
	}
	return theIndex;
}
template<typename T>
T& listList<T>::operator[](int theIndex)const
{
	auto it = element->begin();
	for (int i = 0; i < theIndex; i++)
		it++;
	return *it;
}
template<typename T>
bool listList<T>::operator==(const listList<T>& theList)
{
	if (element->size() != theList.element->size())
		return false;
	auto it = element->begin();
	auto itt = theList.element->begin();
	for (int i = 0; i < element->size(); i++)
	{
		if (*it != *itt)
			return false;
		it++;
		itt++;
	}
	return true;
}
template<typename T>
bool listList<T>::operator!=(const listList<T>& theList)
{
	auto it = element->begin();
	auto itt = theList.element->begin();
	for (int i = 0; i < min(element->size(), theList.element->size()); i++)
	{
		if (*it != *itt)
			return true;
		it++;
		itt++;
	}
		
	if (theList.element->size() != element->size())
		return true;
	return false;
}
template<typename T>
bool listList<T>::operator<(const listList<T>& theList)
{
	int i = 0;
	auto it = element->begin();
	auto itt = theList.element->begin();
	for (i = 0; i < min(element->size(), theList.element->size()); i++)
	{
		if (*it < *itt)
			return true;
		else if (*it > *itt)
			return false;
		it++;
		itt++;
	}
	if (element->size() >= theList.element->size())
		return false;
	return true;
}
//next
template<typename T>
bool listList<T>::operator>(const listList<T>& theList)
{
	int i = 0;
	auto it = element->begin();
	auto itt = theList.element->begin();
	for (i = 0; i < min(element->size(),theList.element->size()); i++)
	{
		if (*it < *itt)
			return false;
		else if (*it > *itt)
			return true;
		it++;
		itt++;
	}
	if (theList.element->size()>element->size())
		return false;
	return true;
}
template<typename T>
bool listList<T>::operator<=(const listList<T>& theList)
{
	auto it = element->begin();
	auto itt = theList.element->begin();
	for (int i = 0; i < min(element->size(),theList.element->size()); i++)
	{
		if (*it > *itt)
			return false;
		else if (*it < *itt)
			return true;
		it++;
		itt++;
	}
		
	if(element->size()>theList.element->size())
		return false;
	return true;
}
template<typename T>
bool listList<T>::operator>=(const listList<T>& theList)
{
	auto it = element->begin();
	auto itt = theList.element->begin();
	for (int i = 0; i < min(element->size(), theList.element->size()); i++)
	{
		if (*it > *itt)
			return true;
		else if (*it < *itt)
			return false;
		it++;
		itt++;
	}
	if (element->size() < theList.element->size())
		return false;
	return true;
}
template<typename T>
void listList<T>::swap(listList<T>& theList)
{
	auto tmp = theList.element;
	theList.element = element;
	element = tmp;
}
template<typename T>
void listList<T>::fromList(const arrayList<T>& theList)
{
	element->clear();
	for (int i = 0; i < theList.size(); i++)
		element->push_back(theList[i]);
}
template<typename T>
void listList<T>::toList(arrayList<T>& theList)
{
	theList.clear();
	auto it = element->begin();
	for (int i = 0; i < element->size(); i++)
	{
		theList.push_back(*it);
		it++;
	}
}
template<typename T>
void listList<T>::leftShift(const int& i)
{
	for (int j = 0; j < i; j++)
		element->erase(element->begin());
}
template<typename T>
void listList<T>::reverse()
{
	element->reverse();
}
template<typename T>
void listList<T>::merge(listList<T>& listA, listList<T>& listB)
{
	this->clear();
	auto it = listA.element->begin();
	for (int i = 0; i < listA.size(); i++)
	{
		element->push_back(*it);
		it++;
	}
	it = listB.element->begin();
	for (int i = 0; i < listB.size(); i++)
	{
		element->push_back(*it);
		it++;
	}
	listA.clear();
	listB.clear();
}
template<typename T>
void listList<T>::meld(listList<T>& listA, listList<T>& listB)
{
	element->clear();
	auto it = listA.element->begin();
	auto itt = listB.element->begin();
	for (int i = 0; i < min(listA.element->size(), listB.element->size()); i++)
	{
		element->push_back(*it);
		element->push_back(*itt);
		it++;
		itt++;
	}
	if (listA.element->size() > listB.element->size())
	{
		for (int i = listB.element->size(); i < listA.element->size(); i++)
		{
			element->push_back(*it);
			it++;
		}
	}
	if (listB.element->size() > listA.element->size())
	{
		for (int i = listA.element->size(); i < listB.element->size(); i++)
		{
			element->push_back(*itt);
			itt++;
		}
	}
	listA.element->clear();
	listB.element->clear();
}
template<typename T>
void listList<T>::split(listList<T>& listA, listList<T>& listB)
{
	listA.element->clear();
	listB.element->clear();
	auto it = element->begin();
	for (int i = 0; i < element->size()/2; i++)
	{
		listA.element->push_back(*it);
		it++;
		if (i + 1 < element->size())
		{
			listB.element->push_back(*it);
			it++;
		}
	}
}
template<typename T>
void listList<T>::insertSort()
{
	element->sort();
}
template<typename T>
void listList<T>::circularShift(const int& i)
{
	for (int j = 0; j < i; j++)
	{
		auto it = element->begin();
		element->push_back(*it);
		element->erase(it);
	}
}
template<typename T>
void listList<T>::zero()
{
	element->clear();//?difference with clear();
}
template<typename T>
void listList<T>::push_back(const T& theElement)
{
	element->push_back(theElement);
}
template<typename T>
void listList<T>::clear()
{
	element->clear();
}
template<typename T>
void listList<T>::checkIndex(int theIndex)const
{
	if (theIndex < 0 || theIndex >= element->size())
	{
		ostringstream s;
		s << "index =  " << theIndex << " size =  " << element->size();
		throw illegalIndex(s.str());
	}
}