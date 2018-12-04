// C6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"chain.h"
#include<iostream>
#include<algorithm>//max min sort  rand
//#include"arrayList.h"
//#include"extendedChain.h"
//#include"moveLeftAndRightOnChain.h"
#include"circularList.h"
//#include"circularListWithHeader.h"
using namespace std;
int main()
{
	/*
	chain<int> c(10);
	chain<int>::iterator it = c.begin();
	chain<int> c2(10);
	chain<int> c3(10);
	arrayList<int> al(10);

	cout << "c: " << c << endl;
	cout << "empty? " << c.empty() << endl;

	for (int i = 0; i < 10; i++)
	c.insert(0, i);
	cout << "insert 9-0 c: " << c << endl;
	cout << "size: " << c.size() << endl;
	cout << "get 4: " << c.get(4) << endl;
	c.erase(0);
	cout << "erase 0: " << c << endl;
	c.insert(0, 9);
	cout << "insert(0,9): " << c << endl;

	it = c.begin();
	cout << "begin: " << *(c.begin()) << endl;
	//cout << "end: " << *(c.end()) << endl;


	cout << "++it: " << *(++it) << endl;
	//cout << "--it: " << *(--it) << endl;
	it++;
	cout << "it++: " << *it << endl;
	//it--;
	//cout << "it--: " << *it << endl;
	cout << "c.begin == c.end: " << (c.begin() == c.end()) << endl;
	cout << "c.begin!=c.end: " << (c.begin() != c.end()) << endl;

	c.set(5, 9);
	cout << "set 5 9: " << c << endl;
	cout << "last index of 9: " << c.lastIndexOf(9) << endl;

	c.removeRange(6, 8);
	cout << "removeRange 6-8: " << c << endl;

	c.setSize(4);
	cout << "set size 4: " << c << endl;

	cout << "c[3]: " << c[3] << endl;


	for (int i = 0; i < 10; i++)
	c2.insert(0,i);
	cout << "c2: " << c2 << endl;
	cout << "c==c2: " << (c == c2) << endl;
	cout << "c!=c2: " << (c != c2) << endl;
	cout << "c<c2: " << (c < c2) << endl;

	c.swap(c2);
	cout << "swap c: " << c << endl;
	cout << "c2: " << c2 << endl;

	for(int i=22;i<30;i++)
	c.push_back(i);
	cout << "pushback 22-29: " << c << endl;

	::reverse(c);
	cout << "reverse: " << c << endl;

	cout << "c to list: " << ::chainToList(c) << endl;

	for (int i = 0; i < 10; i++)
	al.push_back(i);
	cout << "list to chain: " << ::listToChain(al) << endl;

	cout << "c:" << c << endl;
	cout << "c2:" << c2 << endl;
	cout << "global meld: " << ::meld(c, c2) << endl;
	cout << "global merge: " << ::merge(c, c2) << endl;

	c.leftShift(4);
	cout << "leftShift 4: " << c << endl;



	for (int i = 22; i < 32; i++)
	c3.push_back(i);
	cout << "c: " << c <<"  size: "<<c.size()<< endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;

	c.meld(c2, c3);
	cout << "meld: " << c << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	*/
	//test class chain

	//test class extendedChain

	//e19
	/*
	extendedChain<int> chainA(10);
	extendedChain<int> chainB(10);
	for (int i = 0; i < 10; i++)
	chainA.push_back(i);
	for (int i = 20; i < 30; i++)
	chainB.push_back(i);
	cout << "chainA:" << chainA << endl;
	cout << "chainB:" << chainB << endl;
	cout << "merge(extendedChain): " << ::merge(chainA, chainB) << endl;
	*/
	//e20
	/*
	chain<int> chainA(10), chainB(10), chainC(10);
	for (int i = 0; i < 10; i++)
	{
	chainA.push_back(1);
	chainB.push_back(2);
	chainC.push_back(3);
	}
	cout << "chainA:" << chainA << endl;
	cout << "chainB:" << chainB << endl;
	cout << "chainC:" << chainC << endl;
	chainC.merge(chainA, chainB);
	cout << "chainC:" << chainC << endl;

	*/
	//e21
	/*
	extendedChain<int> eChainA(10), eChainB(10), eChainC(10);
	for (int i = 0; i < 10; i++)
	eChainA.push_back(i);
	for (int i = 20; i < 30; i++)
	eChainB.push_back(i);
	for (int i = 0; i < 10; i++)
	eChainC.push_back(i);

	cout << "chainA:" << eChainA << endl;
	cout << "chainB:" << eChainB << endl;
	cout << "chainC:" << eChainC << endl;

	split(eChainA, eChainB, eChainC);
	cout << "chainA:" << eChainA << endl;
	cout << "chainB:" << eChainB << endl;
	cout << "chainC:" << eChainC << endl;
	*/

	//e22
	/*
	chain<int> chainA(10), chainB(10), chainC(10);
	for (int i = 0; i < 10; i++)
	chainC.push_back(i);
	chainC.split(chainA, chainB);
	cout << "chainA:" << chainA << endl;
	cout << "chainB:" << chainB << endl;
	cout << "chainC:" << chainC << endl;
	*/
	//e23
	/*
	extendedChain<int> eChainA(10);
	for (int i = 0; i < 10; i++)
	eChainA.push_back(i);
	cout << "eChainA:" << eChainA << endl;
	eChainA.circularShift(2);
	cout << "eChainA:" << eChainA << endl;
	*/
	//e25
	/*
	moveLeftAndRightOnChain<int> mChainA(10);
	for (int i = 0; i < 10; i++)
	mChainA.push_back(i);
	cout << "mchainA:" << mChainA << endl;
	cout << "current element:" << mChainA.currentElement() << endl;
	mChainA.moveRight();
	mChainA.moveRight();
	cout << "current element:" << mChainA.currentElement() << endl;
	cout << "previous element:" << mChainA.previousElement() << endl;
	mChainA.moveLeft();
	cout << "current element:" << mChainA.currentElement() << endl;
	cout << "previous element:" << mChainA.previousElement() << endl;
	mChainA.moveRight();
	cout << "current element:" << mChainA.currentElement() << endl;
	cout << "previous element:" << mChainA.previousElement() << endl;
	*/
	//e26
	/*
	chain<int> chainA(8);
	for (int i = 0; i < 8; i++)
	chainA.push_back(rand());
	cout << "chainA:" << chainA << endl;
	chainA.insertSort();
	cout << "chainA:" << chainA << endl;
	*/
	//e29
	/*
	circularList<int> listA(10);
	for (int i = 0; i < 10; i++)
	listA.push_back(i);
	cout << "listA:" << listA << endl;
	cout << "size:" << listA.size() << endl;
	//reverse
	listA.reverse();
	cout << "after reverse listA:" << listA << endl;
	*/


//E30-36
	/*
	circularList<int> listA(10);
	for (int i = 0; i < 10; i++)
	listA.push_back(i);
	circularList<int> listB(10), listC(10);
	for (int i = 0; i < 4; i++)
	listB.push_back(3 * i);
	for (int i = 0; i < 6; i++)
	listC.push_back(i * 2);
	cout << "listA:" << listA << endl;
	cout << "listB:" << listB << endl;
	cout << "listC:" << listC << endl;
	listA.meld(listB, listC);
	cout << "--meld--" << endl;
	cout << "listA:" << listA << endl;
	cout << "listB:" << listB << endl;
	cout << "listC:" << listC << endl;
	cout << "listB size:" << listB.size() << endl;
	cout << "listC size:" << listC.size() << endl;
	//merge
	for (int i = 0; i < 4; i++)
	listB.push_back(3 * i);
	for (int i = 0; i < 6; i++)
	listC.push_back(i * 2);
	cout << "listA:" << listA << endl;
	cout << "listB:" << listB << endl;
	cout << "listC:" << listC << endl;
	cout << "--merge--" << endl;
	listA.merge(listB, listC);
	cout << "listA:" << listA << endl;
	//meld
	cout << "listA size:" << listA.size() << endl;
	cout << "listB size:" << listB.size() << endl;
	cout << "listC size:" << listC.size() << endl;

	//split
	cout << "--split--" << endl;
	listA.split(listB, listC);
	cout << "listA size:" << listA.size() << endl;
	cout << "listB size:" << listB.size() << endl;
	cout << "listC size:" << listC.size() << endl;
	cout << "listA:" << listA << endl;
	cout << "listB:" << listB << endl;
	cout << "listC:" << listC << endl;
	*/
	
	

	//e37
/*
circularList<int> listA(10);
for (int i = 0; i < 10; i++)
listA.push_back(i);
cout << "listA:" << listA << endl;
listA.remove(3);
cout << "listA:" << listA << endl;
*/
	

	//e38
/*

*/



//E43

//E44
//E45
//E46
//E47
//E48
//E49
//E50
//E51
//E52

//E53
//E54
//E55
//E56
//E57
//E58
//E59
//E60
//E61
//E62
//E63
//E64
//E65
//E66
//E67
//E68
//E69
//E70
//E71
//E72


//E73
//E74
//E75
//E76
//E77
//E
//E
//E
//E
//E








	return 0;
}

