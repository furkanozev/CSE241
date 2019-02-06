import java.util.Arrays;

/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * @param <E> Generic type (Integer or String)
 */
public class LinkedList<E> implements List<E>, Queue<E> {
	
	/**
	 * Java arrays in the concrete classes to implement all the methods.
	 */
	private E[] mycont;
	
	/**
	 * Constructor of LinkedList that taken Arrays.
	 * Copy elements from parameter array to array in LinkedList.
	 * @param temp Arrays of E (Generic variable)
	 */
	@SuppressWarnings("unchecked")
	public LinkedList(E[] temp)
	{
		mycont = (E[])new Object[temp.length];
		for(int i=0 ; i<temp.length ; i++)
		{
			mycont[i] = temp[i]; 
		}
	}
	/*
	 * Return this LinkedList object's iterator object.
	 * @see List#iterator()
	 * @see Queue#iterator()
	 */
	public Iterator<E> iterator()
	{
		Iterator<E> myiter = new Iterator<E>(mycont);
		return myiter;
	}
	/*
	 * Add elements end of Array.
	 * @see List#addAll(Collection)
	 * @see Queue#addAll(Collection)
	 */
	public void addAll(Collection<E> c)
	{
		E keep;
		Iterator<E> it = c.iterator();
		while(it.hasNext())
		{
			keep = it.next();
			add(keep);
		}
	}
	/* 
	 * Clear all elements of Array.
	 * @see  List#clear()
	 * @see  Queue#clear()
	 */
	public void clear()
	{
		Arrays.fill( mycont, null );
	}
	/* Check element contains in Array.
	 * @see  List#contains(java.lang.Object)
	 * @see  Queue#contains(java.lang.Object)
	 */
	public boolean contains(E e)
	{
		boolean flag = false;
		E x;
		Iterator<E> iter = iterator();
		while(iter.hasNext() && flag == false)
		{
			x = iter.next();
			if(x == e) flag = true;
		}
		return flag;
	}
	/* 
	 * Check elements contains in Array.
	 * @see  List#containsAll(Collection)
	 * @see  Queue#containsAll(Collection)
	 */
	public boolean containsAll(Collection<E> c)
	{
		boolean flag = true;
		E temp;
		Iterator<E> citer = c.iterator();
		while(citer.hasNext() && flag == true)
		{
			temp = citer.next();
			if(!contains(temp)) flag = false;
		}
		return flag;
	} 
	/* Check no element in Array.
	 * @see  List#isEmpty()
	 * @see  Queue#isEmpty()
	 */
	public boolean isEmpty()
	{
		boolean flag = true;
		if(mycont.length == 0) return true;
		else
		{
			E temp;
			Iterator<E> iter = iterator();
			while(iter.hasNext() && flag == true)
			{
				temp = iter.next();
				if(temp != null) flag = false;
			}
			return flag;
		}
	} 
	/* 
	 * Remove element(parameter) from Array. 
	 * If there is more than one of the same element, it removes all of them.
	 * @see  List#remove(java.lang.Object)
	 * @see  Queue#remove(java.lang.Object)
	 */
	public void remove(E e)
	{
		try
		{
			if(contains(e))
			{
				int i = 0, j;
				E temp;
				Iterator<E> iter = iterator();
				while(iter.hasNext())
				{
					temp = iter.next();
					if(temp == e)
					{
						j = i;
						while(j != iter.get_arr().length-1)
						{
							mycont[j] = mycont[j+1];
							j++;
						}
						iter.remove();
					}
					else i++;
				}
				@SuppressWarnings("unchecked")
				E[] new_arr = (E[])new Object[iter.get_arr().length];
				for(i=0 ; i<iter.get_arr().length; i++)
				{
					new_arr[i] = iter.get_arr()[i];
				}
				mycont = new_arr;
				System.gc();
			}
		}
		catch(MyException err)
		{
			System.out.println(err.getMessage());
		}
	}
	/* 
	 * Remove elements(parameter) from Array. For each element call remove function.
	 * @see  List#removeAll(Collection)
	 * @see  Queue#removeAll(Collection)
	 */
	public void removeAll(Collection<E> c)
	{
		E keep;
		Iterator<E> it = c.iterator();
		while(it.hasNext())
		{
			keep = it.next();
			remove(keep);
		}
	}
	/* 
	 * If 2 LinkedList does not contain that element, it remove that element with remove function.
	 * @see List#retainAll(Collection)
	 * @see Queue#retainAll(Collection)
	 */
	public void retainAll(Collection<E> c)
	{
		int i = 0;
		while(i < mycont.length)
		{
			if(!c.contains(mycont[i]))
			{
				remove(mycont[i]);
			}
			else i++;
		}
	} 
	/* 
	 * Return amount of element or size of array.
	 * @see List#size()
	 * @see Queue#size()
	 */
	public int size()
	{
		return mycont.length;
	}
	/* Add element end of Array with call offer(e)
	 * @see List#add(java.lang.Object)
	 * @see Queue#add(java.lang.Object)
	 */
	public void add(E e)
	{
		offer(e);
	}
	/* return head element of queue.
	 * @see Queue#element()
	 */
	public E element()
	{
		Iterator<E> it = iterator();
		return it.next();
	}
	/* Add element end of Array.
	 * @see Queue#offer(java.lang.Object)
	 */
	public void offer(E e)
	{
		int i;
		@SuppressWarnings("unchecked")
		E[] new_arr = (E[])new Object[mycont.length+1];
		for(i=0 ; i<mycont.length; i++)
		{
			new_arr[i] = mycont[i];
		}
		new_arr[i] = e;
		mycont = new_arr;
		System.gc();
	}
	/* remove head element of queue then return it.
	 * @see Queue#poll()
	 */
	public E poll() throws MyException
	{
		Iterator<E> it = iterator();
		if(it.hasNext())
		{
			E temp;
			temp = mycont[0];
			@SuppressWarnings("unchecked")
			E[] new_arr = (E[])new Object[mycont.length-1];
			for(int i=1; i < mycont.length; i++)
			{
				new_arr[i-1] = mycont[i];
			}
			mycont = new_arr;
			System.gc();
			return temp;
		}
		else throw new MyException("Queue is empty");
	}
	/* 
	 * Return all elements of LinkedList object with toString function.
	 * @see java.lang.Object#toString()
	 */
	public String toString()
	{
		return Arrays.toString(mycont);
	}
}
