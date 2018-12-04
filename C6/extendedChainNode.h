#ifndef extendedChainNode_
#define extendedChainNode_
template<typename T>
struct extendedChainNode
{
	T element;
	extendedChainNode<T> *next;
	extendedChainNode<T> *previous;

	extendedChainNode() {}
	extendedChainNode(const T& element)
	{
		this->element = element;
	}
	extendedChainNode(const T& element, extendedChainNode<T> *next)
	{
		this->element = element;
		this->next = next;
		this->previous = previous;
	}
};
#endif