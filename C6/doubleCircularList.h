#include<iostream>
#include<sstream>
#include"extendedChainNode.h"
#include"myExceptions.h"
using namespace std;
template<typename T>
class doubleCircularList {
public:
	doubleCircularList(int initialCapacity);
	doubleCircularList(const doubleCircularList<T>& theLsit);

	//ADT method

	//

	//
protected:
	extendedChainNode<T>* firstNode;
};
template<typename T>
doubleCircularList<T>::doubleCircularList(int initialCapacity)
{

}
template<typename T>
doubleCircularList<T>::doubleCircularList(const doubleCircularList<T>& theList)
{

}
