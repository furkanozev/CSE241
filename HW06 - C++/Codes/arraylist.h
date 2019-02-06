#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "list.h"

using namespace std;

namespace mySTL
{
	template<class E, class container = vector<E>>
	class ArrayList : public List <E, container>
	{
		public:
			ArrayList(container temp)
			{
//				List<E, container>();
				mycont=temp;
			}
			virtual ~ArrayList()
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
				mycont.insert (mycont.end(),e);
			}
			virtual void addAll(Collection<E, container>& c) override
			{
				for (auto& e: c.get_cont())
				{
					mycont.insert (mycont.end(),e);
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
				auto tempit = mycont.begin();
				for (auto it=mycont.begin(); it!=mycont.end(); it++)
				{
					if(*it == e)
					{
						tempit = prev(it);
						it = mycont.erase(it);
						it = tempit;
					}
				}
			}
			virtual void removeAll(Collection<E, container>& c) override
			{
				for (auto e: c.get_cont())
				{
					for (auto it=mycont.begin(); it!=mycont.end(); it++)
					{
						if(*it == e)
						{
							it = mycont.erase(it);
						}
					}
				}
			} 
			virtual void retainAll(Collection<E, container>& c) override
			{
				int count=0;
				container temp;
				for (auto& e: c.get_cont())
				{
					count=0;
					for (auto& x: mycont)
					{
						if(x == e) count++;
					}
					while(count>0)
					{
						temp.insert(temp.end(),e);
						count--;
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
			E& operator [](int index)
			{
				auto it = mycont.begin();
				E temp;
				auto myit = iterator();
				
				if(!(index < 0 || index > mycont.size()-1))
				{
					for(int i = 0; i < index; i++)
					{
						temp = myit.next();
					}
					return temp;
				}
			}
			const E& operator [](int index) const
			{
				auto it = mycont.begin();
				E temp;
				auto myit = iterator();
				
				if(!(index < 0 || index > mycont.size()-1))
				{
					for(int i = 0; i < index; i++)
					{
						temp = myit.next();
					}
					return temp;
				}
			}
		
		private:
			container mycont;
	};
}

#endif
