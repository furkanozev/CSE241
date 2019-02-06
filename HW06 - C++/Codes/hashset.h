#ifndef HASHSET_H_
#define HASHSET_H_

#include "set.h"

using namespace std;

namespace mySTL
{
	template<class E, class container = vector<E>>
	class HashSet : public Set <E, container>
	{
		public:
			HashSet(container temp)
			{
				//Set<E, container>();
				mycont=temp;
			}
			virtual ~HashSet()
			{
				mycont.clear();	
			}
			virtual Iterator<E,container> iterator() override
			{
				Iterator<E, container> myiter(&mycont);
				return myiter;
			}
			virtual void add(E e) override
			{
				int flag = 0;
				for (auto& x: mycont)
				{
					if(x == e) flag = -1;
				}
				if (flag == 0)
				{
					mycont.insert (mycont.end(),e);
				}
			}
			virtual void addAll(Collection<E, container>& c) override
			{
				int flag;
				for (auto& e: c.get_cont())
				{
					flag = 0;
					for (auto& x: mycont)
					{
						if(x == e) flag = -1;
					}
					if (flag == 0)
					{
						mycont.insert (mycont.end(),e);
					}
				}
			}
			virtual void clear() override
			{
				mycont.clear();	
			} 
			virtual bool contains(E e) override
			{
				bool flag = false;
				for (auto& x: mycont)
				{
					if(x == e) flag = true;
				}
				return flag;
			}
			virtual bool containsAll(Collection<E, container>& c) override
			{
				bool flag;
				for (auto& e: c.get_cont())
				{
					flag = false;
					for (auto& x: mycont)
					{
						if(x == e) flag = true;
					}
					if (flag == false)
					{
						return flag;
					}
				}
				return true;
			} 
			virtual bool isEmpty() override
			{
				return (mycont.size() == 0);
			} 
			virtual void remove(E e) override
			{
				int flag = 0;
				for (auto it=mycont.begin(); it!=mycont.end() && flag == 0; it++)
				{
					if(*it == e)
					{
						it = mycont.erase(it);
						flag = -1;
					}
				}
			}
			virtual void removeAll(Collection<E, container>& c) override
			{
				int flag;
				for (auto& e: c.get_cont())
				{
					flag = 0;
					for (auto it=mycont.begin(); it!=mycont.end() && flag == 0; it++)
					{
						if(*it == e)
						{
							it = mycont.erase(it);
							flag = -1;
						}
					}
				}
			} 
			virtual void retainAll(Collection<E, container>& c) override
			{
				bool flag;
				container temp;
				for (auto& e: c.get_cont())
				{
					flag = false;
					for (auto& x: mycont)
					{
						if(x == e) flag = true;
					}
					if (flag == true)
					{
						temp.insert(temp.end(),e);
					}
				}
				mycont.clear();
				mycont = temp;
			} 
			virtual int size() override
			{
				return mycont.size();	
			} 
			container get_cont()
			{
				return mycont;
			}
		
		private:
			container mycont;
	};
}

#endif
