#ifndef LIST_H_
#define LIST_H_
#include "collection.h"

using namespace std;

namespace mySTL
{
	template<class E, class container = vector<E>>
	class List : virtual public Collection <E, container>
	{
		public:
			List()
			{
//				Collection<E, container>();
			}
			virtual ~List()
			{	}
	};
}

#endif
