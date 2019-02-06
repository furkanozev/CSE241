#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iterator>
#include <vector>
#include <list>
#include <set>

using namespace std;

namespace mySTL
{
	template<class E, class container = vector<E>>
	class Iterator
	{
		public:
			
			Iterator(container* temp)
			{
				mycont=temp;
				myiterator = mycont->begin();
			}
			
			bool hasNext()
			{
				if(myiterator != prev(mycont->end()) ) return true;
				else return false;
			}
			E next()
			{
				if(hasNext())
				{
	            	advance(myiterator,1);
	            	return (*myiterator);
		        }
		        else
		        {
		        	return 0;

				}
			}
			void remove()
			{
				myiterator = mycont->erase(myiterator);
			}
			
	private:
		container* mycont;
		typename container::iterator myiterator;
			
	};
}

#endif
