
/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * Iterator of the collection.
 * @param <E> Generic type (Integer or String)
 */
public class Iterator<E> {
	/**
	 * Java arrays in the concrete classes to implement all the methods.
	 */
	private E[] mycont;
	/**
	 * Cursor to track elements.
	 */
	private int cursor = -1;
	
	/**
	 * Constructor of Iterator that taken Arrays.
	 * @param temp  Arrays of E (Generic variable) (Integer or String)
	 */
	public Iterator(E[] temp)
	{
		mycont=temp;
	}
	
	/**
	 * Returns true if the iteration has more elements.
	 * @return boolean  true or false
	 */
	public boolean hasNext()
	{
		if( cursor+1 < mycont.length ) return true;
		else return false;
	}
	/**
	 * Returns the next element in the iteration and advances the iterator.
	 * @return E  Generic variable (Integer or String) 
	 */
	public E next()
	{
		if(hasNext())
		{
        	cursor++;
        	return mycont[cursor];
        }
		else
		{
			E x = null;
			return x;
		}
	}
	/**
	 * Removes from the underlying collection the last element returned by this iterator.
	 * @throws MyException object of Myexception
	 */
	@SuppressWarnings("unchecked")
	public void remove() throws MyException
	{
		if(mycont.length > 0)
		{
			E[] new_arr = (E[])new Object[mycont.length-1];
			for(int i=0 ; i<mycont.length-1; i++)
			{
				new_arr[i] = mycont[i];
			}
			mycont = new_arr;
			System.gc();
		}
		else throw new MyException("There is no element to remove.");
	}
	
	/**
	 * To synchronize.
	 * @return E[]  Arrays of E (Generic variable) (Integer or String)
	 */
	public E[] get_arr()
	{
		return mycont;
	}
	
}
