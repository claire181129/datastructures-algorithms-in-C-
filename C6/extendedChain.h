#include"extendedLinearList.h"
#include"chain.h"
template<typename> class extendedChain;
template<typename T>
extendedChain<T>& meld(const extendedChain<T>& chainA, const extendedChain<T>& chainB)
{
	auto size = chainA.size() + chainB.size();
	extendedChain<T> newChain(size);
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
	return newChain;
}
template<typename T>
void split(extendedChain<T>& chainA, extendedChain<T>& chainB, extendedChain<T>& chainC)
{
	auto sizeA = chainA.size();
	auto sizeB = chainB.size();
	auto sizeC = chainC.size();
	for (int i = 0; i < sizeA; i++)
		chainA.erase(0);
	for (int i = 0; i < sizeB; i++)
		chainB.erase(0);
	for (int i = 0; i < sizeC / 2; i++)
	{
		chainA.push_back(chainC.get(i * 2));
		chainB.push_back(chainC.get(i * 2 + 1));
	}
	if (sizeC % 2)
		chainA.push_back(chainC.get(sizeC - 1));
}
template<typename T>
class extendedChain :public extendedLinearList<T>, public chain<T>
{
public:
	extendedChain(int initialCapacity = 10) :chain<T>(initialCapacity) {}
	extendedChain(const extendedChain<T> &x) :chain<T>(x) {}

	//
	bool empty() const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex) const
	{
		return chain<T>::get(theIndex);
	}
	int indexOf(const T& theElement)const
	{
		return chain<T>::indexOf(theElement);
	}
	void erase( int theIndex)
	{
		checkIndex(theIndex);
		chainNode<T>* deleteNode;
		if (theIndex == 0)
		{// remove first node from chain
			deleteNode = firstNode;
			firstNode = firstNode->next;
		}
		else
		{  // use p to get to predecessor of desired node
			chainNode<T>* p = firstNode;
			for (int i = 0; i < theIndex - 1; i++)
				p = p->next;

			deleteNode = p->next;
			p->next = p->next->next; // remove deleteNode from chain
			if (deleteNode == lastNode)
				lastNode = p;
		}
		listSize--;
		delete deleteNode;
	}
	void insert( int theIndex, const T& theElement)
	{
		if (theIndex < 0 || theIndex > listSize)
		{// invalid index
			ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}

		if (theIndex == 0)
		{// insert at front
			firstNode = new chainNode<T>(theElement, firstNode);
			if (listSize == 0)
				lastNode = firstNode;
		}
		else
		{  // find predecessor of new element
			chainNode<T>* p = firstNode;
			for (int i = 0; i < theIndex - 1; i++)
				p = p->next;

			// insert after p
			p->next = new chainNode<T>(theElement, p->next);
			if (listSize == theIndex)
				lastNode = p->next;
		}
		listSize++;
	}
	void clear()
	{
		while (firstNode != NULL)
		{
			chainNode<T>* nextNode = firstNode->next;
			delete firstNode;
			firstNode = nextNode;
		}
		listSize = 0;
	}
	void push_back(const T& theElement)
	{
		chainNode<T>* theNode = new chainNode<T>(theElement, NULL);
		if (this->size() == 0)
		{
			firstNode = theNode;
			lastNode = firstNode;
			listSize++;
			return;
		}
		else
		{
			lastNode->next = theNode;
			lastNode = theNode;
			listSize++;
		}
	}
	void output(ostream& out)const
	{
		chain<T>::output(out);
	}
	void circularShift(const int& i);
	//additional method
	void zero()
	{
		firstNode = NULL;
		listSize = 0;
	}
protected:
	chainNode<T>* lastNode;
};
template<typename T>
void extendedChain<T>::circularShift(const int& i)
{
	for (int j = 0; j < i; j++)
	{
		chainNode<T>* theNode = firstNode;
		auto tmp = theNode->element;
		for (int m = 0; m < listSize - 1; m++)
		{
			theNode->element = theNode->next->element;
			theNode = theNode->next;
		}
		theNode->element = tmp;
	}
}
//template<typename T>
//void extendedChain<T>::erase(const int& theIndex)

//template<typename T>
//void extendedChain<T>::insert(const int& theIndex, const T& theElement)

//template<typename T>
//void extendedChain<T>::push_back(const T& theElement)
