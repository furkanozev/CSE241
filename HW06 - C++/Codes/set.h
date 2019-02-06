#ifndef SET_H_
#define SET_H_
#include "collection.h"

using namespace std;

namespace mySTL
{
	template<class E, class container = vector<E>>
	class Set : virtual public Collection <E, container>
	{
		public:
			Set() 
			{
//				Collection<E, container>();
			}
			virtual ~Set()
			{	}
	};
}

#endif
