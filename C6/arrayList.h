// array implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
// USES STL ALGORITHMS TO SIMPLIFY CODE

#ifndef arrayList_
#define arrayList_

#include<iostream>//cout,
#include<sstream>//ostringstream
#include<string>//string class,
#include<algorithm>//std::copy,
#include <iterator>//iterator class,
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"
using namespace std;
template<typename> class alit;
template<class T>
class arrayList : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
      //arrayList(int initialCapacity = 10);
	  arrayList(int initialCapacity = 10, int length = 0);//length is for auto expand array length when there is not enough capacity
      arrayList(const arrayList<T>&);
      ~arrayList() {delete [] element;}

      // ADT methods
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;
	  void trimToSize();//
	  void setSize(int);
	  T& operator[]( int i) const;
	  bool operator==(const arrayList<T> &x)const;
	  bool operator<(const arrayList<T> &x)const;
      // additional method
      int capacity() const {return arrayLength;}
	  void push_back(const T &theElement);
	  void pop_back();
	  void swap(arrayList<T> &x);
	  T set(const int &theIndex, const T &theElement);
	  void clear();
	  void removeRange(int beginIndx, int endIndx);
	  int lastIndexof(const T &x)const;
	  int shrinkCapacity();
	  void reverse();
	  void leftShift(int i);
	  void circularShift(int i);
	  int half();
	  void meld(const arrayList<T> &a, const arrayList<T> &b);
	  void merge(const arrayList<T> &a, const arrayList<T> &b);
	  void split(arrayList<T> &a, arrayList<T> &b);

	  friend class alit<T>;//
	  alit<T> begin() { return alit<T>(element); }
	  alit<T> end() { return alit<T>(element + listSize); }
	  
   protected:
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      T* element;            // 1D array to hold list elements
      int arrayLength;       // capacity of the 1D array
      int listSize;          // number of elements in list
	  int changeLength;
	  int initialCapacity;
};
template<typename T>
class alit //: public std::iterator<std::random_access_iterator_tag, T>
{
public:
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	alit(T* thePosition = 0) { position = thePosition; }
	alit(const alit<T> &a) { this->position = a.position; }

	//overload operator
	T& operator*() const { return *position; }
	T* operator->() const { return position; }

	alit& operator++() { position++; return *this; }//prefix ++  associativity:R
													//use cl compiler,the right operands will be evaluated first
													//for type int,the order that operands were evaluated is unknown
	alit operator++(int) {//postfix ++ associativity:R
		alit old = *this;
		++position;
		return old;
	}

	alit& operator--() { --position; return *this; }//prefix --
	alit operator--(int) {//postfix --
		alit old = *this;
		--position;
		return old;
	}

	alit& operator+ (int n) { position += n; return *this; }

	alit& operator- (int n) { position -= n; return *this; }
	

	int operator-(alit it) { return position - it.position; }

	bool operator!=(const alit right)const { return position != right.position; }
	bool operator==(const alit right)const
	{
		return position == right.position;
	}

	bool operator < (alit it) { if (position<it.position) return true; else return false; }
	bool operator >(alit it) { if (position>it.position) return false; else return true; }

	bool operator <=(alit it) { if (position <= it.position) return true; else return false; }
	bool operator >=(alit it) { if (position >= it.position) return false; else return true; }

	alit& operator+=(int n) { position = position + n; return *this; }
	alit& operator-=(int n) { position = position - n; return *this; }

	T& operator[](int n) { auto temp = position + n; return *temp; }
protected:
	T* position;
};

//e4
template <class T>
arrayList<T>::arrayList(int initialCapacity,int length)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	this->initialCapacity = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;

	if (length)
		changeLength = length;
	else
		changeLength = 2 * arrayLength;
}
/*
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{// Constructor.
if (initialCapacity < 1)
{ostringstream s;
s << "Initial capacity = " << initialCapacity << " Must be > 0";
throw illegalParameterValue(s.str());
}
arrayLength = initialCapacity;
this->initialCapacity = initialCapacity;
element = new T[arrayLength];
listSize = 0;
}
*/

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{// Copy constructor.
   arrayLength = theList.arrayLength;
   this->initialCapacity = theList.arrayLength;
   listSize = theList.listSize;
   element = new T[arrayLength];
   copy(theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search for theElement
   int theIndex = (int) (find(element, element + listSize, theElement)
                         - element);

   // check if theElement was found
   if (theIndex == listSize)
     // not found
     return -1;
   else return theIndex;
 }

template<class T>
void arrayList<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // valid index, shift elements with higher index
   copy(element + theIndex + 1, element + listSize,
                                element + theIndex);

   element[--listSize].~T(); // invoke destructor
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   // valid index, make sure we have space
   if (listSize == arrayLength)
      {// no space, double capacity
         changeLength1D(element, arrayLength, changeLength);
         arrayLength  = changeLength;
      }

   // shift elements right one position
   copy_backward(element + theIndex, element + listSize,
                 element + listSize + 1);

   element[theIndex] = theElement;

   listSize++;
}
template<class T>
void arrayList<T>::trimToSize()
{
	auto newSize = max(listSize, 1);
	if (newSize == 1)
	{
		T newelement;
		insert(0, newelement);
		listSize = 1;
	}
}
template<class T>
void arrayList<T>::setSize(int newsize)
{
	if (newsize > listSize)
		for (int i = listSize-1; i < newsize; i++)
		{
			T newelement;
			insert(i, newelement);
		}
	else if(newsize<listSize)
		for (int i = newsize; i < listSize; )
			erase(i);
}
template<class T>
void arrayList<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}
template<class T>
void arrayList<T>::push_back(const T &theElement)
{
	if (this->capacity() < this->size() + 1)
	{
		changeLength1D(element, arrayLength, arrayLength + 1);
		arrayLength += 1;
	}
	element[this->size()] = theElement;
	listSize += 1;
}
template<class T>
void arrayList<T>::pop_back()
{
	element[--listSize].~T();
}
template<class T>
void arrayList<T>::swap(arrayList<T> &x)
{
	arrayList<T> temp(x);
	//this->x
	if (this->capacity() != x.capacity())
	{
		changeLength1D(x.element, x.capacity(), this->capacity());
		x.arrayLength = this->capacity();
	}
	copy(element, element + this->size(), x.element);
	if (this->size() < x.size())
	{
		for (int i = this->size(); i < x.size(); i++)
		{
			x.element[i].~T();
			x.listSize--;
		}
	}
	else if (this->size() > x.size())
		x.listSize = this->size();

	//x->this
	if (this->capacity() != temp.capacity())
	{
		changeLength1D(element, this->capacity(), temp.capacity());
		this->arrayLength = temp.capacity();
	}
	copy(temp.element, temp.element + temp.size(), this->element);
	if (temp.size() < this->size())
	{
		for (int i = temp.size(); i < this->size(); i++)
		{
			this->element[i].~T();
			this->listSize--;
		}	
	}
	else if(temp.size()>this->size())
		this->listSize = temp.size();
}
template<class T>
T arrayList<T>::set(const int &theIndex, const T &theElement)
{
	//if (theIndex > this->size() - 1)
		//illegalIndex("index larger than listSize");
	const T originalElement = this->get(theIndex);
	this->element[theIndex] = theElement;
	return originalElement;
}
template<class T>
void arrayList<T>::clear()
{
	for (int i = 0; i < this->size(); i++)
		this->element[i].~T();
	this->listSize = 0;
}
template<class T>
void arrayList<T>::removeRange(int beginIndx, int endIndx)
{
	//if (beginIndx<0 || endIndx>this->size() - 1 || beginIndx > endIndx)
		//illegal;
	for (int i = beginIndx; i <= endIndx; i++)
		this->erase(beginIndx);
}
template<class T>
int arrayList<T>::lastIndexof(const T &x)const
{
	int appearIndx = -1;
	for (int i = 0; i < this->size(); i++)
		if(x==this->get(i))
			appearIndx = i;
	return appearIndx;
}
template<class T>
int arrayList<T>::shrinkCapacity()
{
	if (listSize < arrayLength / 4)
	{
		auto newCapacity = max( arrayLength / 2,initialCapacity );
		T* newelement = new T[newCapacity];
		copy(element, element + listSize, newelement);
		delete[] element;
		element = newelement;
		arrayLength = newCapacity;
	}
	return arrayLength;
}
template<class T>
void arrayList<T>::reverse()
{
	for (int i = 0; i < listSize / 2; i++)
	{
		auto temp = element[i];
		element[i] = element[listSize - 1 - i];
		element[listSize - 1 - i] = temp;
	}
}
template<class T>
void newreverse(arrayList<T> &x)
{
	for (int i = 0; i < x.size()/2; i++)
	{
		auto size = x.size();
		auto temp = x.get(i);
		x[i] = x[size - 1 - i];
		x[size - 1 - i] = temp;
	}
}
template<class T>
void arrayList<T>::leftShift(int i)
{
	if (i < listSize)
	{
		copy(element + i, element + listSize, element);
		listSize = listSize - i;
	}
	else
	{
		this->clear();
	}	
}
template<class T>
void arrayList<T>::circularShift(int i)
{//left cycle
	T* temp = new T[i];
	copy(element, element + i, temp);
	copy(element + i, element + listSize, element);
	copy(temp, temp + i , element + i+1);
}
template<class T>
int arrayList<T>::half()
{
	auto num = listSize / 2;
	for (int i = 0; i < num; i++)
	{
		copy(element + i + 2, element + listSize, element + 1 + i);
		element[listSize-1].~T();
		listSize--;
	}
	return listSize;
}
template<class T>
int newhalf(arrayList<T> &x)
{
	auto num = x.size()/2;
	for (int i = 0; i < num; i++)
	{
		x.erase(i + 1);
	}
	return x.size();
}
template<typename T>
void arrayList<T>::meld(const arrayList<T> &a, const arrayList<T> &b)
{
	int minlength = min(a.listSize, b.listSize);
	int meldlength = minlength*2;
	int newlength = meldlength + max(a.listSize, b.listSize)-min(a.listSize, b.listSize);
	if(arrayLength<newlength)
		changeLength1D(element, this->capacity(), newlength);
	arrayLength = newlength;
	listSize = newlength;
	unsigned int j = 0;
	for (unsigned i = 0; i < meldlength; i+=2)
	{
		element[i] = a[j];
		element[i + 1] = b[j];
		j++;
	}
	if (a.listSize > minlength)
	{
		for (unsigned i = 0; i < a.listSize-minlength; i++)
			element[i+meldlength] = a[i + minlength];
	}
	if (b.listSize > minlength)
	{
		for (unsigned i = 0; i < b.listSize - minlength; i++)
			element[i + meldlength] = b[i + minlength];
	}
}
// overload <<
template<typename T>
void arrayList<T>::merge(const arrayList<T> &a, const arrayList<T> &b)
{
	if (arrayLength < a.listSize + b.listSize)
	{
		changeLength1D(element, this->capacity(), a.listSize + b.listSize);
		arrayLength = a.listSize + b.listSize;
	}
	listSize = a.listSize + b.listSize;
	copy(a.element, a.element + a.listSize, element);
	copy(b.element, b.element + b.listSize, element + a.listSize);
	sort(this->begin(), this->end());
}
template<typename T>
void arrayList<T>::split(arrayList<T> &a, arrayList<T> &b)
{
	unsigned j = 0;
	for (unsigned i = 0; i < listSize; i += 2)
	{
		b.insert(j, element[i]);
		if(i+1<listSize)
			a.insert(j,element[i+1]);
		j++;
	}
}
//overload operator of arrayList
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
   {x.output(out); return out;}
// overload []
template <class T>
T& arrayList<T>::operator[](int i ) const
{
	return this->get(i);
}
template<class T>
bool arrayList<T>::operator==(const arrayList<T> &x)const
{
	if (this->size() != x.size())
		return false;
	for (int i = 0; i < x.size(); i++)
	{
		if (this->get(i) != x[i])
			return false;
	}
	return true;
}
template<class T>
bool arrayList<T>::operator<(const arrayList<T> &x)const
{
	if (this->size() > x.size())
		return false;
	else if (this->size() < x.size())
		return true;
	else
	{
		for (int i = 0; i < x.size(); i++)
			if (this->get(i) < x[i])
				return true;
		return false;
	}
}

//overload operator of alit
template<class T>
alit<T> operator+(const int &n, const alit<T> &it)
{
	alit<T> temp = it;
	for (unsigned i = 0; i < n; i++)
		temp++;
	return it;
}
template<typename T>
int operator-(const alit<T> &a,const alit<T> &b)
{ return (a.position - b.position) / sizeof(*b); }

#endif
