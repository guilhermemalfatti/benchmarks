/*
Changed on: April, 2016
       Author: Guilherme Malfatti - guimalfatti76@gmail.com
Util:
build arm gem5:

build x86 gem5:
g++ -static list.cpp program.cpp -o linkedList
exec x86 in gem5
../build/X86/gem5.fast configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/git/class/list/linkedList
or
./build/X86/gem5.fast configs/myScripts/MySimulation.py -c "/home/malfatti/git/class/list/linkedList"
exec arm in gem5
 ./build/ARM/gem5.debug configs/example/se.py  --cpu-type=detailed --caches --l2cache --l1d_size='32kB' --l1i_size='32kB' --l2_size='1MB' --cmd /home/malfatti/git/class/list/linkedList
*/
#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	//Sample Code
	List mylist;
	mylist.pushToHead('k');
	mylist.pushToHead('e');
	mylist.pushToHead('n');
	mylist.pushToHead('a');
	mylist.pushToHead('b');
	mylist.pushToHead('b');
	mylist.pushToHead('c');
	mylist.pushToHead('d');
	mylist.pushToHead('e');
	mylist.pushToHead('f');
	mylist.pushToHead('g');
	mylist.pushToHead('h');
	mylist.pushToHead('i');
	mylist.pushToHead('j');
	mylist.print();

	cout<<endl;
	//TO DO! Write a program that tests your list library - the code should take characters, push them onto a list,
	//- then reverse the list to see if it is a palindrome!
	return 0;
}