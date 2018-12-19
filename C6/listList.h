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
	~listList() { delete element };

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
	element->reserve(initialCapacity);
}
template<typename T>
listList<T>::listList(const listList<T>& theList)
{
	element = new list<T>(*theList.element);
}
template<typename T>
listList<T>::T& get(int theIndex)const
{

}
template<typename T>
int listList<T>::indexOf(const T& theElement)const
{

}
template<typename T>
void listList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	element->erase(begin()+theIndex);
}
template<typename T>
void listList<T>::insert(int theIndex, const T& theElement)
{
	element->insert(begin() + theIndex, theElement);
}
template<typename T>
void listList<T>::output(ostream& out)const
{
	copy(element->begin(), element->end(), ostream_iterator<T>(out, " "));
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
	*(element->begin() + theIndex) = theElement;
}
template<typename T>
void listList<T>::removeRange(int fromIndex, int toIndex)
{
	for (int i = fromIndex; i <= toIndex; i++)
		element->erase(fromIndex);
}
template<typename T>
int listList<T>::lastIndexOf(const T& theElement)const
{
	int theIndex = -1;
	for (int i = 0; i < element->size(); i++)
		if (*(element->begin() + i) == theElement)
			theIndex = i;
	return theIndex;
}
template<typename T>
T& listList<T>::operator[](int theIndex)const
{
	return (element->begin() + theIndex);
}
template<typename T>
bool listList<T>::operator==(const listList<T>& theList)
{
	if (element->size() != theList.element->size())
		return false;
	for (int i = 0; i < element->size(); i++)
		if (*(element->begin() + i) != *(theList.element->begin() + i))
			return false;
	return true;
}
template<typename T>
bool listList<T>::operator!=(const listList<T>& theList)
{
	for (int i = 0; i < min(element->size(), theList.element->size()); i++)
		if (*(element->begin() + i) != *(theList.element->begin() + i))
			return true;
	if (theList.element->size() != element->size())
		return true;
	return false;
}
template<typename T>
bool listList<T>::operator<(const listList<T>& theList)
{
	int i = 0;
	for (i = 0; i < min(element->size(),theList.element->size()); i++)
		if (*(element->begin() + i) > *(theList.element->begin() + i))
			return false;
	if (element->size() >= theList.element->size())
		return false;
	return true;
}
//next
template<typename T>
bool listList<T>::operator>(const listList<T>& theList)
{
	int i = 0;
	for (i = 0; i < element->size(); i++)
		if (*(element->begin() + i) < *(theList.element->begin() + i))
			return false;
	if (i == element->size() - 1)
		return false;
	return true;
}
template<typename T>
bool listList<T>::operator<=(const listList<T>& theList)
{
	for (int i = 0; i < element->size(); i++)
		if (*(element->begin() + i) > *(theList.element->begin() + i))
			return false;
	if()
	return true;
}
template<typename T>
bool listList<T>::operator>=(const listList<T>& theList)
{

}
template<typename T>
void listList<T>::swap(listList<T>& theList)
{

}
template<typename T>
void listList<T>::fromList(const arrayList<T>& theList)
{

}
template<typename T>
void listList<T>::toList(arrayList<T>& theList)
{

}
template<typename T>
void listList<T>::leftShift(const int& i)
{

}
template<typename T>
void listList<T>::reverse()
{

}
template<typename T>
void listList<T>::merge(listList<T>& listA, listList<T>& listB)
{

}
template<typename T>
void listList<T>::meld(listList<T>& listA, listList<T>& listB)
{

}
template<typename T>
void listList<T>::split(listList<T>& listA, listList<T>& listB)
{

}
template<typename T>
void listList<T>::insertSort()
{

}
template<typename T>
void listList<T>::circularShift(const int& i)
{

}
template<typename T>
void listList<T>::zero()
{

}
template<typename T>
void listList<T>::push_back(const T& theElement)
{

}
template<typename T>
void listList<T>::clear()
{

}
template<typename T>
void listList<T>::checkIndex(int theIndex)const
{

}