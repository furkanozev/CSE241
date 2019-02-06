#include <iostream>
#include "collection.h"
#include "set.h"
#include "list.h"
#include "queue.h"
#include "hashset.h"
#include "arraylist.h"
#include "linkedlist.h"
#include <string>

// Getter yerine kendi iteratorumuzu kullanýyoruz ve iteratorumuzu geliþtirelim. 
//sonra removelarda son elemaný silmek sýkýntý o problem. 
//Sonra diðer 2 classý yapýyoruz. sonra throwlar.  sonra driver. sonra test.
using namespace std;
using namespace mySTL;


int main()
{
	cout<<"---------------------- TEST ----------------------\n";
	cout<<"-----> HashSet Test : <-----\n";
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	
	{
		cout<<"*** 1. int and vector: *** \n";
		vector<int> vec1 = {3,7,4,9,2};
		vector<int> vec2 = {7,1,4,6,3};
		vector<int> vec3 = {2,7,11,8,3};
		HashSet<int,vector<int>> hset1(vec1);
		HashSet<int,vector<int>> hset2(vec2);
		HashSet<int,vector<int>> hset3(vec3);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to HashSet1 and add 12 to HashSet2: \n";
		hset1.add(12);
		hset2.add(12);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add HashSet2 to HashSet1: \n";
		hset1.addAll(hset2);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: HashSet1 contains 9 and HashSet2 contains 9: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		if(hset1.contains(9)) cout<<"\nFor HashSet1 true";
		else cout<<"\nFor HashSet1 false";
		if(hset2.contains(9)) cout<<"\tFor HashSet2 true";
		else cout<<"\tFor HashSet2 false";
		
		cout<<"\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		if(hset1.containsAll(hset2)) cout<<"\nHashSet1 containsAll HashSet2 true";
		else cout<<"\nHashSet1 containsAll HashSet2 false";
		if(hset1.containsAll(hset3)) cout<<"\tHashSet1 containsAll HashSet3 true";
		else cout<<"\tHashSet1 containsAll HashSet3 false";
		
		cout<<"\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\t HashSet2 size = "<<hset2.size()<<"\t HashSet3 size = "<<hset3.size();
		
		cout<<"\n\nf) remove function: remove 1 to HashSet1, HashSet2 and HashSet3: \n";
		hset1.remove(1);
		hset2.remove(1);
		hset3.remove(1);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size()<<"\tHashSet3 size = "<<hset3.size();
		
		cout<<"\n\ng) retainAll function: Base HashSet1 Parameter HashSet2: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		hset1.retainAll(hset2);
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n";
		cout<<"HashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		hset2.removeAll(hset3);
		cout<<"\nHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: HashSet1 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		hset1.clear();
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: HashSet1, HashSet2 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size();
		if(hset1.isEmpty()) cout<<"\nHashSet1 is empty";
		else cout<<"\nHashSet1 is not empty";
		if(hset2.isEmpty()) cout<<"\tHashSet2 is empty";
		else cout<<"\tHashSet2 is not empty";
		
		cout<<"\n\nk) iterator function: HashSet3 : \n";
		cout<<"HashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		auto myiter = hset3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation HashSet3: \n";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n HashSet int vector<int> test successfully completed. \n";
	}
	
	cout<<"\n\n----------------------------------------------------------\n";
		
	{
		cout<<"*** 2. string and vector: *** \n";
		vector<string> vec1 = {"mert","ali","murat","yusuf","selim"};
		vector<string> vec2 = {"ali","mehmet","murat","fatih","mert"};
		vector<string> vec3 = {"selim","ali","omer","metin","mert"};
		HashSet<string,vector<string>> hset1(vec1);
		HashSet<string,vector<string>> hset2(vec2);
		HashSet<string,vector<string>> hset3(vec3);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"serkan\" to HashSet1 and HashSet2: \n";
		hset1.add("serkan");
		hset2.add("serkan");
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add HashSet2 to HashSet1: \n";
		hset1.addAll(hset2);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: HashSet1 contains \"yusuf\" and HashSet2 contains \"yusuf\": \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		if(hset1.contains("yusuf")) cout<<"\nFor HashSet1 true";
		else cout<<"\nFor HashSet1 false";
		if(hset2.contains("yusuf")) cout<<"\tFor HashSet2 true";
		else cout<<"\tFor HashSet2 false";
		
		cout<<"\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		if(hset1.containsAll(hset2)) cout<<"\nHashSet1 containsAll HashSet2 true";
		else cout<<"\nHashSet1 containsAll HashSet2 false";
		if(hset1.containsAll(hset3)) cout<<"\tHashSet1 containsAll HashSet3 true";
		else cout<<"\tHashSet1 containsAll HashSet3 false";
		
		cout<<"\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\t HashSet2 size = "<<hset2.size()<<"\t HashSet3 size = "<<hset3.size();
		
		cout<<"\n\nf) remove function: remove \"mehmet\" to HashSet1, HashSet2 and HashSet3: \n";
		hset1.remove("mehmet");
		hset2.remove("mehmet");
		hset3.remove("mehmet");
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size()<<"\tHashSet3 size = "<<hset3.size();
		
		cout<<"\n\ng) retainAll function: Base HashSet1 Parameter HashSet2: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		hset1.retainAll(hset2);
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n";
		cout<<"HashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		hset2.removeAll(hset3);
		cout<<"\nHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: HashSet1 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		hset1.clear();
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: HashSet1, HashSet2 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size();
		if(hset1.isEmpty()) cout<<"\nHashSet1 is empty";
		else cout<<"\nHashSet1 is not empty";
		if(hset2.isEmpty()) cout<<"\tHashSet2 is empty";
		else cout<<"\tHashSet2 is not empty";
		
		cout<<"\n\nk) iterator function: HashSet3 : \n";
		cout<<"HashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		auto myiter = hset3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation HashSet3: \n";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n HashSet string vector<string> test successfully completed. \n";
	}
	
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 3. int and list: *** \n";
		list<int> list1 = {3,7,4,9,2};
		list<int> list2 = {7,1,4,6,3};
		list<int> list3 = {2,7,11,8,3};
		HashSet<int,list<int>> hset1(list1);
		HashSet<int,list<int>> hset2(list2);
		HashSet<int,list<int>> hset3(list3);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to HashSet1 and add 12 to HashSet2: \n";
		hset1.add(12);
		hset2.add(12);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add HashSet2 to HashSet1: \n";
		hset1.addAll(hset2);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: HashSet1 contains 9 and HashSet2 contains 9: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		if(hset1.contains(9)) cout<<"\nFor HashSet1 true";
		else cout<<"\nFor HashSet1 false";
		if(hset2.contains(9)) cout<<"\tFor HashSet2 true";
		else cout<<"\tFor HashSet2 false";
		
		cout<<"\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		if(hset1.containsAll(hset2)) cout<<"\nHashSet1 containsAll HashSet2 true";
		else cout<<"\nHashSet1 containsAll HashSet2 false";
		if(hset1.containsAll(hset3)) cout<<"\tHashSet1 containsAll HashSet3 true";
		else cout<<"\tHashSet1 containsAll HashSet3 false";
		
		cout<<"\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\t HashSet2 size = "<<hset2.size()<<"\t HashSet3 size = "<<hset3.size();
		
		cout<<"\n\nf) remove function: remove 1 to HashSet1, HashSet2 and HashSet3: \n";
		hset1.remove(1);
		hset2.remove(1);
		hset3.remove(1);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size()<<"\tHashSet3 size = "<<hset3.size();
		
		cout<<"\n\ng) retainAll function: Base HashSet1 Parameter HashSet2: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		hset1.retainAll(hset2);
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n";
		cout<<"HashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		hset2.removeAll(hset3);
		cout<<"\nHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: HashSet1 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		hset1.clear();
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: HashSet1, HashSet2 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size();
		if(hset1.isEmpty()) cout<<"\nHashSet1 is empty";
		else cout<<"\nHashSet1 is not empty";
		if(hset2.isEmpty()) cout<<"\tHashSet2 is empty";
		else cout<<"\tHashSet2 is not empty";
		
		cout<<"\n\nk) iterator function: HashSet3 : \n";
		cout<<"HashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		auto myiter = hset3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation HashSet3: \n";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n HashSet int list<int> test successfully completed. \n";
	}
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 4. string and list: *** \n";
		list<string> list1 = {"mert","ali","murat","yusuf","selim"};
		list<string> list2 = {"ali","mehmet","murat","fatih","mert"};
		list<string> list3 = {"selim","ali","omer","metin","mert"};
		HashSet<string,list<string>> hset1(list1);
		HashSet<string,list<string>> hset2(list2);
		HashSet<string,list<string>> hset3(list3);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"serkan\" to HashSet1 and HashSet2: \n";
		hset1.add("serkan");
		hset2.add("serkan");
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add HashSet2 to HashSet1: \n";
		hset1.addAll(hset2);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: HashSet1 contains \"yusuf\" and HashSet2 contains \"yusuf\": \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		if(hset1.contains("yusuf")) cout<<"\nFor HashSet1 true";
		else cout<<"\nFor HashSet1 false";
		if(hset2.contains("yusuf")) cout<<"\tFor HashSet2 true";
		else cout<<"\tFor HashSet2 false";
		
		cout<<"\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		if(hset1.containsAll(hset2)) cout<<"\nHashSet1 containsAll HashSet2 true";
		else cout<<"\nHashSet1 containsAll HashSet2 false";
		if(hset1.containsAll(hset3)) cout<<"\tHashSet1 containsAll HashSet3 true";
		else cout<<"\tHashSet1 containsAll HashSet3 false";
		
		cout<<"\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\t HashSet2 size = "<<hset2.size()<<"\t HashSet3 size = "<<hset3.size();
		
		cout<<"\n\nf) remove function: remove \"mehmet\" to HashSet1, HashSet2 and HashSet3: \n";
		hset1.remove("mehmet");
		hset2.remove("mehmet");
		hset3.remove("mehmet");
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size()<<"\tHashSet3 size = "<<hset3.size();
		
		cout<<"\n\ng) retainAll function: Base HashSet1 Parameter HashSet2: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		hset1.retainAll(hset2);
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n";
		cout<<"HashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		hset2.removeAll(hset3);
		cout<<"\nHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: HashSet1 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		hset1.clear();
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: HashSet1, HashSet2 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size();
		if(hset1.isEmpty()) cout<<"\nHashSet1 is empty";
		else cout<<"\nHashSet1 is not empty";
		if(hset2.isEmpty()) cout<<"\tHashSet2 is empty";
		else cout<<"\tHashSet2 is not empty";
		
		cout<<"\n\nk) iterator function: HashSet3 : \n";
		cout<<"HashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		auto myiter = hset3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation HashSet3: \n";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n HashSet string list<string> test successfully completed. \n";
	}
			
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 5. int and set: *** \n";
		set<int> set1 = {3,7,4,9,2};
		set<int> set2 = {7,1,4,6,3};
		set<int> set3 = {2,7,11,8,3};
		HashSet<int,set<int>> hset1(set1);
		HashSet<int,set<int>> hset2(set2);
		HashSet<int,set<int>> hset3(set3);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to HashSet1 and add 12 to HashSet2: \n";
		hset1.add(12);
		hset2.add(12);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add HashSet2 to HashSet1: \n";
		hset1.addAll(hset2);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: HashSet1 contains 9 and HashSet2 contains 9: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		if(hset1.contains(9)) cout<<"\nFor HashSet1 true";
		else cout<<"\nFor HashSet1 false";
		if(hset2.contains(9)) cout<<"\tFor HashSet2 true";
		else cout<<"\tFor HashSet2 false";
		
		cout<<"\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		if(hset1.containsAll(hset2)) cout<<"\nHashSet1 containsAll HashSet2 true";
		else cout<<"\nHashSet1 containsAll HashSet2 false";
		if(hset1.containsAll(hset3)) cout<<"\tHashSet1 containsAll HashSet3 true";
		else cout<<"\tHashSet1 containsAll HashSet3 false";
		
		cout<<"\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\t HashSet2 size = "<<hset2.size()<<"\t HashSet3 size = "<<hset3.size();
		
		cout<<"\n\nf) remove function: remove 1 to HashSet1, HashSet2 and HashSet3: \n";
		hset1.remove(1);
		hset2.remove(1);
		hset3.remove(1);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size()<<"\tHashSet3 size = "<<hset3.size();
		
		cout<<"\n\ng) retainAll function: Base HashSet1 Parameter HashSet2: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		hset1.retainAll(hset2);
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n";
		cout<<"HashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		hset2.removeAll(hset3);
		cout<<"\nHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: HashSet1 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		hset1.clear();
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: HashSet1, HashSet2 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size();
		if(hset1.isEmpty()) cout<<"\nHashSet1 is empty";
		else cout<<"\nHashSet1 is not empty";
		if(hset2.isEmpty()) cout<<"\tHashSet2 is empty";
		else cout<<"\tHashSet2 is not empty";
		
		cout<<"\n\nk) iterator function: HashSet3 : \n";
		cout<<"HashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		auto myiter = hset3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation HashSet3: \n";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n HashSet int set<int> test successfully completed. \n";
	}
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 6. string and set: *** \n";
		set<string> set1 = {"mert","ali","murat","yusuf","selim"};
		set<string> set2 = {"ali","mehmet","murat","fatih","mert"};
		set<string> set3 = {"selim","ali","omer","metin","mert"};
		HashSet<string,set<string>> hset1(set1);
		HashSet<string,set<string>> hset2(set2);
		HashSet<string,set<string>> hset3(set3);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"serkan\" to HashSet1 and HashSet2: \n";
		hset1.add("serkan");
		hset2.add("serkan");
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add HashSet2 to HashSet1: \n";
		hset1.addAll(hset2);
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: HashSet1 contains \"yusuf\" and HashSet2 contains \"yusuf\": \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		if(hset1.contains("yusuf")) cout<<"\nFor HashSet1 true";
		else cout<<"\nFor HashSet1 false";
		if(hset2.contains("yusuf")) cout<<"\tFor HashSet2 true";
		else cout<<"\tFor HashSet2 false";
		
		cout<<"\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		if(hset1.containsAll(hset2)) cout<<"\nHashSet1 containsAll HashSet2 true";
		else cout<<"\nHashSet1 containsAll HashSet2 false";
		if(hset1.containsAll(hset3)) cout<<"\tHashSet1 containsAll HashSet3 true";
		else cout<<"\tHashSet1 containsAll HashSet3 false";
		
		cout<<"\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\t HashSet2 size = "<<hset2.size()<<"\t HashSet3 size = "<<hset3.size();
		
		cout<<"\n\nf) remove function: remove \"mehmet\" to HashSet1, HashSet2 and HashSet3: \n";
		hset1.remove("mehmet");
		hset2.remove("mehmet");
		hset3.remove("mehmet");
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size()<<"\tHashSet3 size = "<<hset3.size();
		
		cout<<"\n\ng) retainAll function: Base HashSet1 Parameter HashSet2: \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		hset1.retainAll(hset2);
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n";
		cout<<"HashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		hset2.removeAll(hset3);
		cout<<"\nHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\t\tHashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: HashSet1 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		hset1.clear();
		cout<<"\nHashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: HashSet1, HashSet2 : \n";
		cout<<"HashSet1: ";
		for(auto x : hset1.get_cont()) cout<<x<<" ";
		cout<<"\tHashSet2: ";
		for(auto x : hset2.get_cont()) cout<<x<<" ";
		cout<<"\nHashSet1 size = "<<hset1.size()<<"\tHashSet2 size = "<<hset2.size();
		if(hset1.isEmpty()) cout<<"\nHashSet1 is empty";
		else cout<<"\nHashSet1 is not empty";
		if(hset2.isEmpty()) cout<<"\tHashSet2 is empty";
		else cout<<"\tHashSet2 is not empty";
		
		cout<<"\n\nk) iterator function: HashSet3 : \n";
		cout<<"HashSet3: ";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		auto myiter = hset3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation HashSet3: \n";
		for(auto x : hset3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n HashSet string set<string> test successfully completed. \n";
	}
	
	cout<<"-----> ArrayList Test : <-----\n";
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 1. int and vector: *** \n";
		vector<int> vec1 = {3,7,4,9,2};
		vector<int> vec2 = {7,1,4,6,3};
		vector<int> vec3 = {2,7,11,8,3};
		ArrayList<int,vector<int>> alist1(vec1);
		ArrayList<int,vector<int>> alist2(vec2);
		ArrayList<int,vector<int>> alist3(vec3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to ArrayList1 and add 12 to ArrayList2: \n";
		alist1.add(12);
		alist2.add(12);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n";
		alist1.addAll(alist2);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: ArrayList1 contains 9 and ArrayList2 contains 9: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		if(alist1.contains(9)) cout<<"\nFor ArrayList1 true";
		else cout<<"\nFor ArrayList1 false";
		if(alist2.contains(9)) cout<<"\tFor ArrayList2 true";
		else cout<<"\tFor ArrayList2 false";
		
		cout<<"\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		if(alist1.containsAll(alist2)) cout<<"\nArrayList1 containsAll ArrayList2 true";
		else cout<<"\nArrayList1 containsAll ArrayList2 false";
		if(alist1.containsAll(alist3)) cout<<"\tArrayList1 containsAll ArrayList3 true";
		else cout<<"\tArrayList1 containsAll ArrayList3 false";
		
		cout<<"\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\t ArrayList2 size = "<<alist2.size()<<"\t ArrayList3 size = "<<alist3.size();
		
		cout<<"\n\nf) remove function: remove 3 to ArrayList1, ArrayList2 and ArrayList3: \n";
		alist1.remove(3);
		alist2.remove(3);
		alist3.remove(3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size()<<"\tArrayList3 size = "<<alist3.size();
		
		cout<<"\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList2: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		alist1.retainAll(alist2);
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n";
		cout<<"ArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		alist2.removeAll(alist3);
		cout<<"\nArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: ArrayList1 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		alist1.clear();
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size();
		if(alist1.isEmpty()) cout<<"\nArrayList1 is empty";
		else cout<<"\nArrayList1 is not empty";
		if(alist2.isEmpty()) cout<<"\tArrayList2 is empty";
		else cout<<"\tArrayList2 is not empty";
		
		cout<<"\n\nk) iterator function: ArrayList3 : \n";
		cout<<"ArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		auto myiter = alist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation ArrayList3: \n";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n ArrayList int vector<int> test successfully completed. \n";
	}

	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 2. string and vector: *** \n";
		vector<string> vec1 = {"ali","mert","serkan","kerem","murat"};
		vector<string> vec2 = {"mert","hakan","serkan","yusuf","ali"};
		vector<string> vec3 = {"murat","mert","cihat","ahmet","ali"};
		ArrayList<string,vector<string>> alist1(vec1);
		ArrayList<string,vector<string>> alist2(vec2);
		ArrayList<string,vector<string>> alist3(vec3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"omer\" to ArrayList1 and add \"omer\" to ArrayList2: \n";
		alist1.add("omer");
		alist2.add("omer");
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n";
		alist1.addAll(alist2);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: ArrayList1 contains \"kerem\" and ArrayList2 contains \"kerem\": \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		if(alist1.contains("kerem")) cout<<"\nFor ArrayList1 true";
		else cout<<"\nFor ArrayList1 false";
		if(alist2.contains("kerem")) cout<<"\tFor ArrayList2 true";
		else cout<<"\tFor ArrayList2 false";
		
		cout<<"\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		if(alist1.containsAll(alist2)) cout<<"\nArrayList1 containsAll ArrayList2 true";
		else cout<<"\nArrayList1 containsAll ArrayList2 false";
		if(alist1.containsAll(alist3)) cout<<"\tArrayList1 containsAll ArrayList3 true";
		else cout<<"\tArrayList1 containsAll ArrayList3 false";
		
		cout<<"\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\t ArrayList2 size = "<<alist2.size()<<"\t ArrayList3 size = "<<alist3.size();
		
		cout<<"\n\nf) remove function: remove \"ali\" to ArrayList1, ArrayList2 and ArrayList3: \n";
		alist1.remove("ali");
		alist2.remove("ali");
		alist3.remove("ali");
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size()<<"\tArrayList3 size = "<<alist3.size();
		
		cout<<"\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList2: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		alist1.retainAll(alist2);
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n";
		cout<<"ArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		alist2.removeAll(alist3);
		cout<<"\nArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: ArrayList1 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		alist1.clear();
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size();
		if(alist1.isEmpty()) cout<<"\nArrayList1 is empty";
		else cout<<"\nArrayList1 is not empty";
		if(alist2.isEmpty()) cout<<"\tArrayList2 is empty";
		else cout<<"\tArrayList2 is not empty";
		
		cout<<"\n\nk) iterator function: ArrayList3 : \n";
		cout<<"ArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		auto myiter = alist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation ArrayList3: \n";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n ArrayList string vector<string> test successfully completed. \n";
	}
	
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 3. int and list: *** \n";
		list<int> list1 = {3,7,4,9,2};
		list<int> list2 = {7,1,4,6,3};
		list<int> list3 = {2,7,11,8,3};
		ArrayList<int,list<int>> alist1(list1);
		ArrayList<int,list<int>> alist2(list2);
		ArrayList<int,list<int>> alist3(list3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to ArrayList1 and add 12 to ArrayList2: \n";
		alist1.add(12);
		alist2.add(12);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n";
		alist1.addAll(alist2);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: ArrayList1 contains 9 and ArrayList2 contains 9: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		if(alist1.contains(9)) cout<<"\nFor ArrayList1 true";
		else cout<<"\nFor ArrayList1 false";
		if(alist2.contains(9)) cout<<"\tFor ArrayList2 true";
		else cout<<"\tFor ArrayList2 false";
		
		cout<<"\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		if(alist1.containsAll(alist2)) cout<<"\nArrayList1 containsAll ArrayList2 true";
		else cout<<"\nArrayList1 containsAll ArrayList2 false";
		if(alist1.containsAll(alist3)) cout<<"\tArrayList1 containsAll ArrayList3 true";
		else cout<<"\tArrayList1 containsAll ArrayList3 false";
		
		cout<<"\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\t ArrayList2 size = "<<alist2.size()<<"\t ArrayList3 size = "<<alist3.size();
		
		cout<<"\n\nf) remove function: remove 3 to ArrayList1, ArrayList2 and ArrayList3: \n";
		alist1.remove(3);
		alist2.remove(3);
		alist3.remove(3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size()<<"\tArrayList3 size = "<<alist3.size();
		
		cout<<"\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList2: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		alist1.retainAll(alist2);
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n";
		cout<<"ArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		alist2.removeAll(alist3);
		cout<<"\nArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: ArrayList1 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		alist1.clear();
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size();
		if(alist1.isEmpty()) cout<<"\nArrayList1 is empty";
		else cout<<"\nArrayList1 is not empty";
		if(alist2.isEmpty()) cout<<"\tArrayList2 is empty";
		else cout<<"\tArrayList2 is not empty";
		
		cout<<"\n\nk) iterator function: ArrayList3 : \n";
		cout<<"ArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		auto myiter = alist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation ArrayList3: \n";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n ArrayList int list<int> test successfully completed. \n";
	}

	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 4. string and vector: *** \n";
		list<string> list1 = {"ali","mert","serkan","kerem","murat"};
		list<string> list2 = {"mert","hakan","serkan","yusuf","ali"};
		list<string> list3 = {"murat","mert","cihat","ahmet","ali"};
		ArrayList<string,list<string>> alist1(list1);
		ArrayList<string,list<string>> alist2(list2);
		ArrayList<string,list<string>> alist3(list3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"omer\" to ArrayList1 and add \"omer\" to ArrayList2: \n";
		alist1.add("omer");
		alist2.add("omer");
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n";
		alist1.addAll(alist2);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: ArrayList1 contains \"kerem\" and ArrayList2 contains \"kerem\": \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		if(alist1.contains("kerem")) cout<<"\nFor ArrayList1 true";
		else cout<<"\nFor ArrayList1 false";
		if(alist2.contains("kerem")) cout<<"\tFor ArrayList2 true";
		else cout<<"\tFor ArrayList2 false";
		
		cout<<"\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		if(alist1.containsAll(alist2)) cout<<"\nArrayList1 containsAll ArrayList2 true";
		else cout<<"\nArrayList1 containsAll ArrayList2 false";
		if(alist1.containsAll(alist3)) cout<<"\tArrayList1 containsAll ArrayList3 true";
		else cout<<"\tArrayList1 containsAll ArrayList3 false";
		
		cout<<"\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\t ArrayList2 size = "<<alist2.size()<<"\t ArrayList3 size = "<<alist3.size();
		
		cout<<"\n\nf) remove function: remove \"ali\" to ArrayList1, ArrayList2 and ArrayList3: \n";
		alist1.remove("ali");
		alist2.remove("ali");
		alist3.remove("ali");
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size()<<"\tArrayList3 size = "<<alist3.size();
		
		cout<<"\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList2: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		alist1.retainAll(alist2);
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n";
		cout<<"ArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		alist2.removeAll(alist3);
		cout<<"\nArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: ArrayList1 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		alist1.clear();
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size();
		if(alist1.isEmpty()) cout<<"\nArrayList1 is empty";
		else cout<<"\nArrayList1 is not empty";
		if(alist2.isEmpty()) cout<<"\tArrayList2 is empty";
		else cout<<"\tArrayList2 is not empty";
		
		cout<<"\n\nk) iterator function: ArrayList3 : \n";
		cout<<"ArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		auto myiter = alist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation ArrayList3: \n";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n ArrayList string list<string> test successfully completed. \n";
	}
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 5. int and set: *** \n";
		set<int> set1 = {3,7,4,9,2};
		set<int> set2 = {7,1,4,6,3};
		set<int> set3 = {2,7,11,8,3};
		ArrayList<int,set<int>> alist1(set1);
		ArrayList<int,set<int>> alist2(set2);
		ArrayList<int,set<int>> alist3(set3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to ArrayList1 and add 12 to ArrayList2: \n";
		alist1.add(12);
		alist2.add(12);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n";
		alist1.addAll(alist2);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: ArrayList1 contains 9 and ArrayList2 contains 9: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		if(alist1.contains(9)) cout<<"\nFor ArrayList1 true";
		else cout<<"\nFor ArrayList1 false";
		if(alist2.contains(9)) cout<<"\tFor ArrayList2 true";
		else cout<<"\tFor ArrayList2 false";
		
		cout<<"\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		if(alist1.containsAll(alist2)) cout<<"\nArrayList1 containsAll ArrayList2 true";
		else cout<<"\nArrayList1 containsAll ArrayList2 false";
		if(alist1.containsAll(alist3)) cout<<"\tArrayList1 containsAll ArrayList3 true";
		else cout<<"\tArrayList1 containsAll ArrayList3 false";
		
		cout<<"\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\t ArrayList2 size = "<<alist2.size()<<"\t ArrayList3 size = "<<alist3.size();
		
		cout<<"\n\nf) remove function: remove 3 to ArrayList1, ArrayList2 and ArrayList3: \n";
		alist1.remove(3);
		alist2.remove(3);
		alist3.remove(3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size()<<"\tArrayList3 size = "<<alist3.size();
		
		cout<<"\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList2: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		alist1.retainAll(alist2);
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n";
		cout<<"ArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		alist2.removeAll(alist3);
		cout<<"\nArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: ArrayList1 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		alist1.clear();
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size();
		if(alist1.isEmpty()) cout<<"\nArrayList1 is empty";
		else cout<<"\nArrayList1 is not empty";
		if(alist2.isEmpty()) cout<<"\tArrayList2 is empty";
		else cout<<"\tArrayList2 is not empty";
		
		cout<<"\n\nk) iterator function: ArrayList3 : \n";
		cout<<"ArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		auto myiter = alist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation ArrayList3: \n";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n ArrayList int set<int> test successfully completed. \n";
	}

	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 6. string and set: *** \n";
		set<string> set1 = {"ali","mert","serkan","kerem","murat"};
		set<string> set2 = {"mert","hakan","serkan","yusuf","ali"};
		set<string> set3 = {"murat","mert","cihat","ahmet","ali"};
		ArrayList<string,set<string>> alist1(set1);
		ArrayList<string,set<string>> alist2(set2);
		ArrayList<string,set<string>> alist3(set3);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"omer\" to ArrayList1 and add \"omer\" to ArrayList2: \n";
		alist1.add("omer");
		alist2.add("omer");
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n";
		alist1.addAll(alist2);
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: ArrayList1 contains \"kerem\" and ArrayList2 contains \"kerem\": \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		if(alist1.contains("kerem")) cout<<"\nFor ArrayList1 true";
		else cout<<"\nFor ArrayList1 false";
		if(alist2.contains("kerem")) cout<<"\tFor ArrayList2 true";
		else cout<<"\tFor ArrayList2 false";
		
		cout<<"\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		if(alist1.containsAll(alist2)) cout<<"\nArrayList1 containsAll ArrayList2 true";
		else cout<<"\nArrayList1 containsAll ArrayList2 false";
		if(alist1.containsAll(alist3)) cout<<"\tArrayList1 containsAll ArrayList3 true";
		else cout<<"\tArrayList1 containsAll ArrayList3 false";
		
		cout<<"\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\t ArrayList2 size = "<<alist2.size()<<"\t ArrayList3 size = "<<alist3.size();
		
		cout<<"\n\nf) remove function: remove \"ali\" to ArrayList1, ArrayList2 and ArrayList3: \n";
		alist1.remove("ali");
		alist2.remove("ali");
		alist3.remove("ali");
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size()<<"\tArrayList3 size = "<<alist3.size();
		
		cout<<"\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList2: \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		alist1.retainAll(alist2);
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n";
		cout<<"ArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		alist2.removeAll(alist3);
		cout<<"\nArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: ArrayList1 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		alist1.clear();
		cout<<"\nArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n";
		cout<<"ArrayList1: ";
		for(auto x : alist1.get_cont()) cout<<x<<" ";
		cout<<"\tArrayList2: ";
		for(auto x : alist2.get_cont()) cout<<x<<" ";
		cout<<"\nArrayList1 size = "<<alist1.size()<<"\tArrayList2 size = "<<alist2.size();
		if(alist1.isEmpty()) cout<<"\nArrayList1 is empty";
		else cout<<"\nArrayList1 is not empty";
		if(alist2.isEmpty()) cout<<"\tArrayList2 is empty";
		else cout<<"\tArrayList2 is not empty";
		
		cout<<"\n\nk) iterator function: ArrayList3 : \n";
		cout<<"ArrayList3: ";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		auto myiter = alist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation ArrayList3: \n";
		for(auto x : alist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n ArrayList string set<string> test successfully completed. \n";
	}
		
	cout<<"-----> LinkedList Test : <-----\n";
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 1. int and vector: *** \n";
		vector<int> vec1 = {3,7,4,9,2};
		vector<int> vec2 = {7,1,4,6,3};
		vector<int> vec3 = {2,7,11,8,3};
		LinkedList<int,vector<int>> llist1(vec1);
		LinkedList<int,vector<int>> llist2(vec2);
		LinkedList<int,vector<int>> llist3(vec3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to LinkedList1 and add 12 to LinkedList2: \n";
		llist1.add(12);
		llist2.add(12);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n";
		llist1.addAll(llist2);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: LinkedList1 contains 9 and LinkedList2 contains 9: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		if(llist1.contains(9)) cout<<"\nFor LinkedList1 true";
		else cout<<"\nFor LinkedList1 false";
		if(llist2.contains(9)) cout<<"\tFor LinkedList2 true";
		else cout<<"\tFor LinkedList2 false";
		
		cout<<"\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		if(llist1.containsAll(llist2)) cout<<"\nLinkedList1 containsAll LinkedList2 true";
		else cout<<"\nLinkedList1 containsAll LinkedList2 false";
		if(llist1.containsAll(llist3)) cout<<"\tLinkedList1 containsAll LinkedList3 true";
		else cout<<"\tLinkedList1 containsAll LinkedList3 false";
		
		cout<<"\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\t LinkedList2 size = "<<llist2.size()<<"\t LinkedList3 size = "<<llist3.size();
		
		cout<<"\n\nf) remove function: remove 3 to LinkedList1, LinkedList2 and LinkedList3: \n";
		llist1.remove(3);
		llist2.remove(3);
		llist3.remove(3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size()<<"\tLinkedList3 size = "<<llist3.size();
		
		cout<<"\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList2: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		llist1.retainAll(llist2);
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n";
		cout<<"LinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		llist2.removeAll(llist3);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: LinkedList1 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		llist1.clear();
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size();
		if(llist1.isEmpty()) cout<<"\nLinkedList1 is empty";
		else cout<<"\nLinkedList1 is not empty";
		if(llist2.isEmpty()) cout<<"\tLinkedList2 is empty";
		else cout<<"\tLinkedList2 is not empty";
		
		cout<<"\n\nk) element function: LinkedList2 : \n";
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<llist2.element();
		
		cout<<"\n\nl) offer function: insert 5 to LinkedList3 \n";
		llist2.offer(5);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nm) pool function: LinkedList2 : \n";
		auto temp = llist2.poll();
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<temp;
		
		cout<<"\n\nn) iterator function: LinkedList3 : \n";
		cout<<"LinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		auto myiter = llist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation LinkedList3: \n";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n LinkedList int vector<int> test successfully completed. \n";
	}

	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 2. string and vector: *** \n";
		vector<string> vec1 = {"ahmet","selim","kemal","ali","idris"};
		vector<string> vec2 = {"selim","salih","kemal","murat","ahmet"};
		vector<string> vec3 = {"idris","selim","metin","medet","ahmet"};
		LinkedList<string,vector<string>> llist1(vec1);
		LinkedList<string,vector<string>> llist2(vec2);
		LinkedList<string,vector<string>> llist3(vec3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"fatih\" to LinkedList1 and add 12 to LinkedList2: \n";
		llist1.add("fatih");
		llist2.add("fatih");
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n";
		llist1.addAll(llist2);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: LinkedList1 contains \"ali\" and LinkedList2 contains \"ali\": \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		if(llist1.contains("ali")) cout<<"\nFor LinkedList1 true";
		else cout<<"\nFor LinkedList1 false";
		if(llist2.contains("ali")) cout<<"\tFor LinkedList2 true";
		else cout<<"\tFor LinkedList2 false";
		
		cout<<"\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		if(llist1.containsAll(llist2)) cout<<"\nLinkedList1 containsAll LinkedList2 true";
		else cout<<"\nLinkedList1 containsAll LinkedList2 false";
		if(llist1.containsAll(llist3)) cout<<"\tLinkedList1 containsAll LinkedList3 true";
		else cout<<"\tLinkedList1 containsAll LinkedList3 false";
		
		cout<<"\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\t LinkedList2 size = "<<llist2.size()<<"\t LinkedList3 size = "<<llist3.size();
		
		cout<<"\n\nf) remove function: remove \"ahmet\" to LinkedList1, LinkedList2 and LinkedList3: \n";
		llist1.remove("ahmet");
		llist2.remove("ahmet");
		llist3.remove("ahmet");
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size()<<"\tLinkedList3 size = "<<llist3.size();
		
		cout<<"\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList2: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		llist1.retainAll(llist2);
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n";
		cout<<"LinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		llist2.removeAll(llist3);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: LinkedList1 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		llist1.clear();
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size();
		if(llist1.isEmpty()) cout<<"\nLinkedList1 is empty";
		else cout<<"\nLinkedList1 is not empty";
		if(llist2.isEmpty()) cout<<"\tLinkedList2 is empty";
		else cout<<"\tLinkedList2 is not empty";
		
		cout<<"\n\nk) element function: LinkedList2 : \n";
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<llist2.element();
		
		cout<<"\n\nl) offer function: insert \"omer\" to LinkedList3 \n";
		llist2.offer("omer");
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nm) pool function: LinkedList2 : \n";
		auto temp = llist2.poll();
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<temp;
		
		cout<<"\n\nn) iterator function: LinkedList3 : \n";
		cout<<"LinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		auto myiter = llist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation LinkedList3: \n";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n LinkedList string vector<string> test successfully completed. \n";
	}
	
		
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 3. int and list: *** \n";
		list<int> list1 = {3,7,4,9,2};
		list<int> list2 = {7,1,4,6,3};
		list<int> list3 = {2,7,11,8,3};
		LinkedList<int,list<int>> llist1(list1);
		LinkedList<int,list<int>> llist2(list2);
		LinkedList<int,list<int>> llist3(list3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to LinkedList1 and add 12 to LinkedList2: \n";
		llist1.add(12);
		llist2.add(12);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n";
		llist1.addAll(llist2);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: LinkedList1 contains 9 and LinkedList2 contains 9: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		if(llist1.contains(9)) cout<<"\nFor LinkedList1 true";
		else cout<<"\nFor LinkedList1 false";
		if(llist2.contains(9)) cout<<"\tFor LinkedList2 true";
		else cout<<"\tFor LinkedList2 false";
		
		cout<<"\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		if(llist1.containsAll(llist2)) cout<<"\nLinkedList1 containsAll LinkedList2 true";
		else cout<<"\nLinkedList1 containsAll LinkedList2 false";
		if(llist1.containsAll(llist3)) cout<<"\tLinkedList1 containsAll LinkedList3 true";
		else cout<<"\tLinkedList1 containsAll LinkedList3 false";
		
		cout<<"\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\t LinkedList2 size = "<<llist2.size()<<"\t LinkedList3 size = "<<llist3.size();
		
		cout<<"\n\nf) remove function: remove 3 to LinkedList1, LinkedList2 and LinkedList3: \n";
		llist1.remove(3);
		llist2.remove(3);
		llist3.remove(3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size()<<"\tLinkedList3 size = "<<llist3.size();
		
		cout<<"\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList2: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		llist1.retainAll(llist2);
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n";
		cout<<"LinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		llist2.removeAll(llist3);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: LinkedList1 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		llist1.clear();
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size();
		if(llist1.isEmpty()) cout<<"\nLinkedList1 is empty";
		else cout<<"\nLinkedList1 is not empty";
		if(llist2.isEmpty()) cout<<"\tLinkedList2 is empty";
		else cout<<"\tLinkedList2 is not empty";
		
		cout<<"\n\nk) element function: LinkedList2 : \n";
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<llist2.element();
		
		cout<<"\n\nl) offer function: insert 5 to LinkedList3 \n";
		llist2.offer(5);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nm) pool function: LinkedList2 : \n";
		auto temp = llist2.poll();
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<temp;
		
		cout<<"\n\nn) iterator function: LinkedList3 : \n";
		cout<<"LinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		auto myiter = llist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation LinkedList3: \n";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n LinkedList int list<int> test successfully completed. \n";
	}

	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 4. string and list: *** \n";
		list<string> list1 = {"ahmet","selim","kemal","ali","idris"};
		list<string> list2 = {"selim","salih","kemal","murat","ahmet"};
		list<string> list3 = {"idris","selim","metin","medet","ahmet"};
		LinkedList<string,list<string>> llist1(list1);
		LinkedList<string,list<string>> llist2(list2);
		LinkedList<string,list<string>> llist3(list3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"fatih\" to LinkedList1 and add 12 to LinkedList2: \n";
		llist1.add("fatih");
		llist2.add("fatih");
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n";
		llist1.addAll(llist2);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: LinkedList1 contains \"ali\" and LinkedList2 contains \"ali\": \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		if(llist1.contains("ali")) cout<<"\nFor LinkedList1 true";
		else cout<<"\nFor LinkedList1 false";
		if(llist2.contains("ali")) cout<<"\tFor LinkedList2 true";
		else cout<<"\tFor LinkedList2 false";
		
		cout<<"\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		if(llist1.containsAll(llist2)) cout<<"\nLinkedList1 containsAll LinkedList2 true";
		else cout<<"\nLinkedList1 containsAll LinkedList2 false";
		if(llist1.containsAll(llist3)) cout<<"\tLinkedList1 containsAll LinkedList3 true";
		else cout<<"\tLinkedList1 containsAll LinkedList3 false";
		
		cout<<"\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\t LinkedList2 size = "<<llist2.size()<<"\t LinkedList3 size = "<<llist3.size();
		
		cout<<"\n\nf) remove function: remove \"ahmet\" to LinkedList1, LinkedList2 and LinkedList3: \n";
		llist1.remove("ahmet");
		llist2.remove("ahmet");
		llist3.remove("ahmet");
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size()<<"\tLinkedList3 size = "<<llist3.size();
		
		cout<<"\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList2: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		llist1.retainAll(llist2);
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n";
		cout<<"LinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		llist2.removeAll(llist3);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: LinkedList1 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		llist1.clear();
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size();
		if(llist1.isEmpty()) cout<<"\nLinkedList1 is empty";
		else cout<<"\nLinkedList1 is not empty";
		if(llist2.isEmpty()) cout<<"\tLinkedList2 is empty";
		else cout<<"\tLinkedList2 is not empty";
		
		cout<<"\n\nk) element function: LinkedList2 : \n";
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<llist2.element();
		
		cout<<"\n\nl) offer function: insert \"omer\" to LinkedList3 \n";
		llist2.offer("omer");
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nm) pool function: LinkedList2 : \n";
		auto temp = llist2.poll();
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<temp;
		
		cout<<"\n\nn) iterator function: LinkedList3 : \n";
		cout<<"LinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		auto myiter = llist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation LinkedList3: \n";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n LinkedList string list<string> test successfully completed. \n";
	}
	
	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 5. int and set: *** \n";
		set<int> set1 = {3,7,4,9,2};
		set<int> set2 = {7,1,4,6,3};
		set<int> set3 = {2,7,11,8,3};
		LinkedList<int,set<int>> llist1(set1);
		LinkedList<int,set<int>> llist2(set2);
		LinkedList<int,set<int>> llist3(set3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add 12 to LinkedList1 and add 12 to LinkedList2: \n";
		llist1.add(12);
		llist2.add(12);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n";
		llist1.addAll(llist2);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: LinkedList1 contains 9 and LinkedList2 contains 9: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		if(llist1.contains(9)) cout<<"\nFor LinkedList1 true";
		else cout<<"\nFor LinkedList1 false";
		if(llist2.contains(9)) cout<<"\tFor LinkedList2 true";
		else cout<<"\tFor LinkedList2 false";
		
		cout<<"\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		if(llist1.containsAll(llist2)) cout<<"\nLinkedList1 containsAll LinkedList2 true";
		else cout<<"\nLinkedList1 containsAll LinkedList2 false";
		if(llist1.containsAll(llist3)) cout<<"\tLinkedList1 containsAll LinkedList3 true";
		else cout<<"\tLinkedList1 containsAll LinkedList3 false";
		
		cout<<"\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\t LinkedList2 size = "<<llist2.size()<<"\t LinkedList3 size = "<<llist3.size();
		
		cout<<"\n\nf) remove function: remove 3 to LinkedList1, LinkedList2 and LinkedList3: \n";
		llist1.remove(3);
		llist2.remove(3);
		llist3.remove(3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size()<<"\tLinkedList3 size = "<<llist3.size();
		
		cout<<"\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList2: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		llist1.retainAll(llist2);
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n";
		cout<<"LinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		llist2.removeAll(llist3);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: LinkedList1 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		llist1.clear();
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size();
		if(llist1.isEmpty()) cout<<"\nLinkedList1 is empty";
		else cout<<"\nLinkedList1 is not empty";
		if(llist2.isEmpty()) cout<<"\tLinkedList2 is empty";
		else cout<<"\tLinkedList2 is not empty";
		
		cout<<"\n\nk) element function: LinkedList2 : \n";
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<llist2.element();
		
		cout<<"\n\nl) offer function: insert 5 to LinkedList3 \n";
		llist2.offer(5);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nm) pool function: LinkedList2 : \n";
		auto temp = llist2.poll();
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<temp;
		
		cout<<"\n\nn) iterator function: LinkedList3 : \n";
		cout<<"LinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		auto myiter = llist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation LinkedList3: \n";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n LinkedList int set<int> test successfully completed. \n";
	}

	cout<<"\n\n----------------------------------------------------------\n";
	
	{
		cout<<"*** 6. string and set: *** \n";
		set<string> set1 = {"ahmet","selim","kemal","ali","idris"};
		set<string> set2 = {"selim","salih","kemal","murat","ahmet"};
		set<string> set3 = {"idris","selim","metin","medet","ahmet"};
		LinkedList<string,set<string>> llist1(set1);
		LinkedList<string,set<string>> llist2(set2);
		LinkedList<string,set<string>> llist3(set3);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\na) add function: add \"fatih\" to LinkedList1 and add 12 to LinkedList2: \n";
		llist1.add("fatih");
		llist2.add("fatih");
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n";
		llist1.addAll(llist2);
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nc) contains function: LinkedList1 contains \"ali\" and LinkedList2 contains \"ali\": \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		if(llist1.contains("ali")) cout<<"\nFor LinkedList1 true";
		else cout<<"\nFor LinkedList1 false";
		if(llist2.contains("ali")) cout<<"\tFor LinkedList2 true";
		else cout<<"\tFor LinkedList2 false";
		
		cout<<"\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		if(llist1.containsAll(llist2)) cout<<"\nLinkedList1 containsAll LinkedList2 true";
		else cout<<"\nLinkedList1 containsAll LinkedList2 false";
		if(llist1.containsAll(llist3)) cout<<"\tLinkedList1 containsAll LinkedList3 true";
		else cout<<"\tLinkedList1 containsAll LinkedList3 false";
		
		cout<<"\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\t LinkedList2 size = "<<llist2.size()<<"\t LinkedList3 size = "<<llist3.size();
		
		cout<<"\n\nf) remove function: remove \"ahmet\" to LinkedList1, LinkedList2 and LinkedList3: \n";
		llist1.remove("ahmet");
		llist2.remove("ahmet");
		llist3.remove("ahmet");
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size()<<"\tLinkedList3 size = "<<llist3.size();
		
		cout<<"\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList2: \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		llist1.retainAll(llist2);
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n";
		cout<<"LinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		llist2.removeAll(llist3);
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\t\tLinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\ni) clear function: LinkedList1 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		llist1.clear();
		cout<<"\nLinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n";
		cout<<"LinkedList1: ";
		for(auto x : llist1.get_cont()) cout<<x<<" ";
		cout<<"\tLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\nLinkedList1 size = "<<llist1.size()<<"\tLinkedList2 size = "<<llist2.size();
		if(llist1.isEmpty()) cout<<"\nLinkedList1 is empty";
		else cout<<"\nLinkedList1 is not empty";
		if(llist2.isEmpty()) cout<<"\tLinkedList2 is empty";
		else cout<<"\tLinkedList2 is not empty";
		
		cout<<"\n\nk) element function: LinkedList2 : \n";
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<llist2.element();
		
		cout<<"\n\nl) offer function: insert \"omer\" to LinkedList3 \n";
		llist2.offer("omer");
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		
		cout<<"\n\nm) pool function: LinkedList2 : \n";
		auto temp = llist2.poll();
		cout<<"\nLinkedList2: ";
		for(auto x : llist2.get_cont()) cout<<x<<" ";
		cout<<"\n head value: "<<temp;
		
		cout<<"\n\nn) iterator function: LinkedList3 : \n";
		cout<<"LinkedList3: ";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		auto myiter = llist3.iterator();
		cout<<"\n iterator function call and return an object. ";
		
		cout<<"\n\n\t hasNext function: ";
		if(myiter.hasNext()) cout<<"\n\t hasNext function returned true. ";
		else cout<<"\n\t hasNext function returned false. ";
		
		cout<<"\n\n\t next function: ";
		auto keep = myiter.next();
		cout<<"\n\t Next variable is : "<<keep;
		
		cout<<"\n\n\t remove function: ";
		myiter.remove();
		cout<<"\n\t remove this variable : "<<keep;
		
		cout<<"\n\nFinal Situation LinkedList3: \n";
		for(auto x : llist3.get_cont()) cout<<x<<" ";
		
		cout<<"\n\n LinkedList string set<string> test successfully completed. \n";
	}
	
	cout<<"\n\n----------------------------------------------------------\n";
	
	return 0;
}
