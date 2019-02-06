#ifndef COLLECTION_H_
#define COLLECTION_H_
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include "iterator.h"

using namespace std;

namespace mySTL
{
	template<class E , class container = vector<E>>
	class Collection
	{
		public:
			Collection()
			{	}
			virtual ~Collection()
			{	}
			virtual Iterator<E,container> iterator() = 0;
			virtual void add(E e) = 0;
			virtual void addAll(Collection& c) = 0;
			virtual void clear() = 0; 
			virtual bool contains(E e) = 0; 
			virtual bool containsAll(Collection& c) = 0; 
			virtual bool isEmpty() = 0; 
			virtual void remove(E e) = 0; 
			virtual void removeAll(Collection& c) = 0; 
			virtual void retainAll(Collection& c) = 0; 
			virtual int size() = 0; 
			virtual container get_cont() = 0;
	};
}

#endif
