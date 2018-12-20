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
//#include"doublyLinkedList.h"
#include"doubleCircularListWithHeader.h"
#include"listList.h"
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
//E43-48 test class doubltLinkedList
/*
	doublyLinkedList<int> listA(10),listB(5),listC(10),listD(10);
	arrayList<int> listM(10),listN(10);
	cout << "empty? " << listA.empty() << endl;
	cout << "size: " << listA.size() << endl;
	cout << "push back 0-9" << endl;
	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	cout << "operator <<: " << listA << endl;
	cout << "output: " << endl;
	listA.output(cout);
	cout << endl;
	cout << "empty? " << listA.empty() << endl;
	cout << "size: " << listA.size() << endl;
	cout << "get 3: " << listA.get(3) << endl;
	cout << "index of 3: " << listA.indexOf(3) << endl;
	cout << "operator[2]:" << listA[2] << endl;
	for (int i = 0; i < 5; i++)
		listB.push_back(i);
	cout << "listB:" << listB << endl;
	cout << "operator ==: " << (listA == listB) << endl;
	//cout << "operator !=: " << (listA != listB) << endl;
	cout << "operator >:" << (listA > listB) << endl;
	cout << "operator <: " << (listA < listB) << endl;
	cout << "operator<=: " << (listA <= listB) << endl;
	cout << "operator>=: " << (listA >= listB) << endl;

	cout << "listC: " << listC << endl;
	cout << "listD: " << listD << endl;
	listA.split(listC, listD);
	cout << "split listC: " << listC << endl;
	cout << "split listD: " << listD << endl;



	cout << "listA: " << listA << endl;
	listA.merge(listC, listD);
	cout << "merge:" << listA << endl;

	for (int i = 0; i < 5; i++)
		listC.push_back(2*i+1);
	for (int i = 0; i < 5; i++)
		listD.push_back(2 * i);
	listA.meld(listC, listD);
	cout << "meld: " << listA << endl;

	listA.reverse();
	cout << "reverse: " << listA << endl;

	cout << "listM: " << listM << endl;
	listA.toList(listM);
	cout << "toList: " << listM << endl;

	for (int i = 0; i < 10; i++)
		listN.push_back(i);
	cout << "listN: " << listN << endl;
	listA.fromList(listN);
	cout << "fromList: " << listA << endl;

	listA.leftShift(2);
	cout << "leftShift 2: " << listA << endl;

	listA.clear();
	cout << "clear: " << listA << endl;

	listB.zero();
	cout << "zero: " << listB << endl;

	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	cout << "listA:" << listA << endl;
	listA.erase(2);
	cout << "erase 2: " << listA << endl;

	listA.insert(3, 12);
	cout << "insert(3,12): " << listA << endl;

	listA.set(0, 12);
	cout << "set(0,12): " << listA << endl;

	listA.push_back(34);
	cout << "pushback 34:" << listA << endl;

	listA.insertSort();
	cout << "insertSort: " << listA << endl;

	listA.setSize(4);
	cout << "setSize 4: " << listA << endl;

	listA.removeRange(0, 3);
	cout << "removeRange(0,3): " << listA << endl;

	cout << "lastIndexOf(3): " << listA.lastIndexOf(3) << endl;

	listA.clear();
	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	doublyLinkedList<int>::iterator it = listA.begin();
	cout << "it:" << *it << endl;
	it++;
	cout << "it++:" << *it << endl;
	cout << "++it:" << *(++it) << endl;
	cout << "begin==end:" << (listA.begin() == listA.end()) << endl;
	cout << "begin!=end:" << (listA.begin() != listA.end()) << endl;	
*/
	
//E49-54 test class doubleCircularList
/*
	doubleCircularList<int> listA(10), listB(10), listC(10), listD(10);
	arrayList<int> listM(10), listN(10);

	cout << "empty: " << listA.empty() << endl;
	cout << "size: " << listA.size() << endl;
	cout << "output: ";
	listA.output(cout);
	cout << endl;
	cout << "operator<<: " << listA << endl;

	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	for (int i = 10; i < 20; i++)
		listB.push_back(i);
	for (int i = 20; i < 30; i++)
		listC.push_back(i);
	for (int i = 0; i < 10; i++)
		listM.push_back(i);
	for (int i = 10; i < 20; i++)
		listN.push_back(i);
	cout << "empty: " << listA.empty() << endl;
	cout << "size: " << listA.size() << endl;
	cout << "operator<<: " << listA << endl;
	cout << "output: ";
	listA.output(cout);
	cout << endl;
	cout << "get[2]: " << listA.get(2) << endl;
	cout << "operator[3]: " << listA[3] << endl;
	cout << "index of 3: " << listA.indexOf(3) << endl;
	listA.set(6, 22);
	cout << "set(6,22): " << listA << endl;
	cout << "lastIndexOf2: " << listA.lastIndexOf(2) << endl;
	cout << "listB: " << listB << endl;
	cout << "listC: " << listC << endl;
	cout << "listA==listB:" << (listA == listB) << endl;
	cout << "listA!=listB: " << (listA != listB) << endl;
	cout << "listB==listC: " << (listB == listC) << endl;
	cout << "listA>listB: " << (listA > listB) << endl;
	cout << "listA<listB: " << (listA < listB) << endl;
	cout << "listA<=listB: " << (listA <= listB) << endl;
	cout << "listA>=listB: " << (listA >= listB) << endl;
	listA.reverse();
	cout << "reverse: " << listA << endl;
	listA.circularShift(3);
	cout << "circularShift 3: " << listA << endl;

	listA.leftShift(2);
	cout << "leftShift 2: " << listA << endl;
	listA.insertSort();
	cout << "insertSort: " << listA << endl;
	listA.removeRange(4, 7);
	cout << "removerange(4,7): " << listA << endl;

	listA.insert(3, 11);
	cout << "insert(3,11): " << listA << endl;
	listA.erase(2);
	cout << "erase 2: " << listA << endl;
	listA.setSize(4);
	cout << "setSize4: " << listA << endl;

	cout << "listM: " << listM << endl;
	listA.toList(listM);
	cout << "toListM: " << listM << endl;

	cout << "listN: " << listN << endl;
	listA.fromList(listN);
	cout << "fromlistN: " << listA << endl;

	cout << "listA: " << listA << endl;
	cout << "listB: " << listB << endl;
	listA.swap(listB);
	cout << "swap listA: " << listA << endl;
	cout << "listB: " << listB << endl;

	cout << "listC: " << listC << endl;
	cout << "listD: " << listD << endl;
	cout << "listA: " << listA << endl;
	listA.merge(listC, listD);
	cout << "merge listA: " << listA << endl;
	cout << "listC: " << listC << endl;
	cout << "listD: " << listD << endl;

	cout << "listB: " << listB << endl;
	listC.meld(listA, listB);
	cout << "merge listC: " << listC << endl;
	cout << "listA: " << listA << endl;
	cout << "listB: " << listB << endl;

	listC.split(listA, listB);
	cout << "split listA: " << listA << endl;
	cout << "listB: " << listB << endl;
	cout << "listC: " << listC << endl;

	listA.zero();
	cout << "zero listA: " << listA << endl;

	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	doubleCircularList<int>::iterator it = listA.begin();
	cout << "*it: " << *it << endl;
	cout << "++it: " << *(++it) << endl;
	it++;
	cout << "it++: " << *it << endl;
	cout << "begin==end: " << (listA.begin() == listA.end()) << endl;
	cout << "begin!=end: " << (listA.begin() != listA.end()) << endl;
*/
	
//E55-60 test class doubleCircularListWithHeader
	/*
	doubleCircularListWithHeader<int> listA(10);
	cout << "listA empty? " << listA.empty() << endl;
	cout << "listA's size: " << listA.size() << endl;
	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	cout << "listA: " << listA << endl;
	listA.output(cout);
	cout << endl;
	cout << "listA empty? " << listA.empty() << endl;
	cout << "listA's size: " << listA.size() << endl;
	cout << "get(3): " << listA.get(3) << endl;
	cout << "listA[3]: " << listA[3] << endl;
	cout << "indexOf(3): " << listA.indexOf(3) << endl;
	listA.erase(2);
	cout << "erase(2): " << listA << endl;
	listA.insert(2, 2);
	cout << "insert(2,2): " << listA << endl;
	listA.set(5, 2);
	cout << "set(5,2): " << listA << endl;
	cout << "lastIndexOf(2): " << listA.lastIndexOf(2) << endl;
	listA.reverse();
	cout << "reverse: " << listA << endl;
	listA.insertSort();
	cout << "insertSort: " << listA << endl;

	doubleCircularListWithHeader<int> listB(10), listC(5);
	for (int i = 0; i < 10; i++)
		listB.push_back(i);
	for (int i = 0; i < 5; i++)
		listC.push_back(i);
	cout << "listB: " << listB << endl;
	cout << "listC: " << listC << endl;

	cout << "listA=listB: " << (listA == listB) << endl;
	cout << "listA!=listC: " << (listA != listC) << endl;
	cout << "listA==listA: " << (listA == listA) << endl;

	cout << "listA<listB: " << (listA < listB) << endl;
	cout << "listA>listB: "<<(listA > listB) << endl;
	cout << "listA<=lsitB: " << (listA <= listB) << endl;
	cout << "listA>=listB: " << (listA >= listB) << endl;
	listA.clear();
	cout << "clear listA: " << listA << endl;
	listA.swap(listC);
	cout << "swap listA: " << listA << endl;
	cout << "swap listC: " << listC << endl;
	arrayList<int> listM(10),listN(10);
	listA.toList(listM);
	cout << "toList listA: " << listA << endl;
	cout << "toList listM: " << listM << endl;

	for (int i = 10; i < 20; i++)
		listN.push_back(i);
	cout << "listN: " << listN << endl;
	listA.fromList(listN);
	cout << "fromList listA: " << listA << endl;
	cout << "fromList listN: " << listN << endl;

	listA.split(listB, listC);
	cout << "split listA: " << listA << endl;
	cout << "split listB: " << listB << endl;
	cout << "split listC: " << listC << endl;

	listA.merge(listB, listC);
	cout << "merge listA: " << listA << endl;
	cout << "merge listB: " << listB << endl;
	cout << "merge listC: " << listC << endl;

	for (int i = 0; i < 10; i++)
		listB.push_back(i);
	for (int i = 0; i < 5; i++)
		listC.push_back(i);
	listA.meld(listB, listC);
	cout << "meld listA: " << listA << endl;
	cout << "meld listB: " << listB << endl;
	cout << "meld listC: " << listC << endl;

	listA.circularShift(4);
	cout << "circularShift(4): " << listA << endl;
	listA.leftShift(3);
	cout << "leftShift(3): " << listA << endl;
	listA.removeRange(0, 2);
	cout << "removeRange(0,2): " << listA << endl;
	listA.setSize(5);
	cout << "setSize(5): " << listA << endl;
	listA.zero();
	cout << "zero: " << listA << endl;


	doubleCircularListWithHeader<int>::iterator it = listA.begin();
	cout << "*it: " << *it << endl;
	cout << "++it: " << *(++it) << endl;
	it++;
	cout << "it++: " << *(it++) << endl;
	cout << "begin==end: " << (listA.begin() == listA.end()) << endl;
	cout << "begin!=end: " << (listA.begin() != listA.end()) << endl;

	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	it = listA.begin();
	cout << "*it: " << *it << endl;
	cout << "++it: " << *(++it) << endl;
	it++;
	cout << "it++: " << *(it++) << endl;
	cout << "begin==end: " << (listA.begin() == listA.end()) << endl;
	cout << "begin!=end: " << (listA.begin() != listA.end()) << endl;
	*/
	//test class listList
	listList<int> listA(10),listB(10);
	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	for (int i = 0; i < 10; i++)
		listB.push_back(i*2);
	cout << "listA.output(): ";
	listA.output(cout);
	cout << endl;
	cout << "size: " << listA.size() << endl;
	cout << "empty: " << listA.empty() << endl;
	cout << "indexOf(2): " << listA.indexOf(2) << endl;
	cout << "get(2): " << listA.get(2) << endl;
	listA.erase(2);
	cout << "erase(2): " << listA << endl;
	listA.insert(2, 2);
	cout << "insert(2,2): " << listA << endl;

	cout << "listA: " << listA << endl;
	cout << "listB: " << listB << endl;
	cout << "listA==listB: " << (listA == listB) << endl;
	cout << "listA!=lsitB: " << (listA != listB) << endl;
	cout << "listA>listB: " << (listA > listB) << endl;
	cout << "listA<listB: " << (listA < listB) << endl;
	cout << "listA>=listB: " << (listA >= listB) << endl;
	cout << "lsitA<=listB: " << (listA <= listB) << endl;
	listA.swap(listB);
	cout << "swap listA: " << listA << endl;
	cout << "swap listB: " << listB << endl;
	listA.set(0, 4);
	cout << "set(0,4): " << listA << endl;
	cout << "lastIndexOf(4): " << listA.lastIndexOf(4) << endl;
	listA.insertSort();
	cout << "insertSort: " << listA << endl;
	listA.circularShift(2);
	cout << "circularShift(2): " << listA << endl;
	listA.leftShift(2);
	cout << "leftShift(2): " << listA << endl;

	listA.setSize(7);
	cout << "setSize(7): " << listA << endl;
	listA.removeRange(0, 3);
	cout << "removeRange(0,3): " << listA << endl;
	cout << "[0]: " << listA[0] << endl;

	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	arrayList<int> listM(10);

	cout << "listM: " << listM << endl;
	cout << "listA: " << listA << endl;
	listA.toList(listM);
	cout << "tolist listM: " << listM << endl;
	cout << "tolist listA: " << listA << endl;

	for (int i = 10; i < 20; i++)
		listM.push_back(i);

	cout << "listM: " << listM << endl;
	cout << "listA: " << listA << endl;
	listA.fromList(listM);
	cout << "fromList listM: " << listM << endl;
	cout << "fromList listA: " << listA << endl;

	listA.clear();
	for (int i = 0; i < 10; i++)
		listA.push_back(i);
	listList<int> listC(10);
	cout << "listA: " << listA << endl;
	cout << "listB: " << listB << endl;
	cout << "listC: " << listC << endl;
	listA.split(listB, listC);
	cout << "split listA: " << listA << endl;
	cout << "split listB: " << listB << endl;
	cout << "split listC: " << listC << endl;

	listB.clear();
	listC.clear();
	for (int i = 1; i < 5; i++)
	{
		listB.push_back(i * 2);
		listC.push_back(i * 2 + 1);
	}
	cout << "listA: " << listA << endl;
	cout << "listB: " << listB << endl;
	cout << "listC: " << listC << endl;
	listA.merge(listB, listC);
	cout << "merge listA: " << listA << endl;
	cout << "merge listB: " << listB << endl;
	cout << "merge listC: " << listC << endl;

	listB.clear();
	listC.clear();
	for (int i = 1; i < 5; i++)
	{
		listB.push_back(i * 2);
		listC.push_back(i * 2 + 1);
	}
	cout << "listA: " << listA << endl;
	cout << "listB: " << listB << endl;
	cout << "listC: " << listC << endl;
	listA.meld(listB, listC);
	cout << "meld listA: " << listA << endl;
	cout << "meld listB: " << listB << endl;
	cout << "meld listC: " << listC << endl;

	//test bidirectional iterator
	doubleCircularListWithHeader<int> listX(10);
	for (int i = 0; i < 10; i++)
		listX.push_back(i);
	doubleCircularListWithHeader<int>::iterator it(listX.begin());
	cout << "*it: " << *it << endl;
	it++;
	it++;
	it++;
	cout << "*it: " << *it << endl;
	cout << "--it: " << *(--it) << endl;
	it--;
	cout << "it--: " << *it << endl;
	//bug?
	/*
	it = listX.end();
	it--;
	cout<<"it--: "<<*it<<endl;//cause list.end() = NULL, it-- will output break;
	*/
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

