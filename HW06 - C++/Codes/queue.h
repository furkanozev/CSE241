#ifndef QUEUE_H_
#define QUEUE_H_
#include "collection.h"

using namespace std;

namespace mySTL
{
	template<class E, class container = vector<E>>
	class Queue : virtual public Collection <E, container>
	{
		public:
			Queue()
			{
//				Collection<E, container>();
			}
			virtual ~Queue()
			{	}
			
			virtual void add(E e) = 0;
			virtual E element() = 0;
			virtual void offer(E e) = 0;
			virtual E poll() = 0;
			
	};
}

#endif
