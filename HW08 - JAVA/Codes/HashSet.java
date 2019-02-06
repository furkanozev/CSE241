import java.util.Arrays;

/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * @param <E> Generic type (Integer or String)
 */
public class HashSet<E> implements Set<E> {
	/**
	 * Java arrays in the concrete classes to implement all the methods.
	 */
	private E[] mycont;
	
	/**
	 * Constructor of HashSet that taken Arrays.
	 * Copy elements from parameter array to array in HashSet.
	 * @param temp Arrays of E (Generic variable)
	 */
	@SuppressWarnings("unchecked")
	public HashSet(E[] temp)
	{
		mycont = (E[])new Object[temp.length];
		for(int i=0 ; i<temp.length ; i++)
		{
			mycont[i] = temp[i]; 
		}
	}
	/*
	 * Return this HashSet object's iterator object.
	 * @see Set#iterator()
	 */
	public Iterator<E> iterator()
	{
		Iterator<E> myiter = new Iterator<E>(mycont);
		return myiter;
	}
	/* 
	 * Add element end of Array but Firstly check whether the element is in array.
	 * If the element is not in the array, will add,(if any) cannot be added again.
	 * @see Set#add(java.lang.Object)
	 */
	public void add(E e)
	{
		if (!contains(e))
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
	}
	/* 
	 * Add all element end of Array. For each element call add function.
	 * @see Set#addAll(Collection)
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
	 * @see Set#clear()
	 */
	public void clear()
	{
		Arrays.fill( mycont, null );
	}
	/* Check element contains in Array.
	 * @see Set#contains(java.lang.Object)
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
	 * @see Set#containsAll(Collection)
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
	 * @see Set#isEmpty()
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
	 * Remove element(parameter) from Array but Firstly check whether the element is in array. After remove it.
	 * @see Set#remove(java.lang.Object)
	 */
	public void remove(E e)
	{
		try
		{
			if(contains(e))
			{
				int i = 0;
				E temp;
				Iterator<E> iter = iterator();
				while(iter.hasNext())
				{
					temp = iter.next();
					if(temp == e)
					{
						mycont[i] = mycont[mycont.length-1];
						iter.remove();
					}
					i++;
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
	 * @see Set#removeAll(Collection)
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
	 * If 2 Hashset does not contain that element, it remove that element with remove function.
	 * @see Set#retainAll(Collection)
	 */
	public void retainAll(Collection<E> c)
	{
		E keep;
		Iterator<E> it = iterator();
		while(it.hasNext())
		{
			keep = it.next();
			if(!c.contains(keep))
				remove(keep);
		}
	}
	/* 
	 * Return amount of element or size of array.
	 * @see Set#size()
	 */
	public int size()
	{
		return mycont.length;
	}
	/* 
	 * Return all elements of HashSet object with toString function.
	 * @see java.lang.Object#toString()
	 */
	public String toString()
	{
		return Arrays.toString(mycont);
	}
}
