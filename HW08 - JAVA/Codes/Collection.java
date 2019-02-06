
/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * This is a generic class with one generic parameters,
 * @param <E> Generic type (Integer or String)
 */
public interface Collection<E> {
	
	/**
	 * Returns an iterator over the collection
	 * @return MyIterator object.
	 */
	Iterator<E> iterator();
	/**
	 * Ensures that this collection contains the specified element.
	 * @param e Generic variable (Integer or String)
	 */
	void add(E e);
	/**
	 * Adds all of the elements in the specified collection to this collection.
	 * @param c Object of Collection
	 */
	void addAll(Collection<E> c);
	
	/**
	 * Removes all of the elements from this collection.
	 */
	void clear(); 
	/**
	 * Returns true if this collection contains the specified element.
	 * @param e   Generic variable (Integer or String)
	 * @return boolean   true or false
	 */
	boolean contains(E e); 
	/**
	 * Returns true if this collection contains all of the elements in the	specified collection.
	 * @param c   Object of Collection
	 * @return boolean   true or false
	 */
	boolean containsAll(Collection<E> c); 
	/**
	 * Returns true if this collection contains no elements.
	 * @return boolean   true or false
	 */
	boolean isEmpty(); 
	/**
	 * Removes a single instance of the specified element from this collection, if it is present.
	 * @param e   Generic variable (Integer or String)
	 */
	void remove(E e); 
	/**
	 * Removes all of this collection's elements that are also contained in the specified collection.
	 * @param c   Object of Collection
	 */
	void removeAll(Collection<E> c); 
	/**
	 * Retains only the elements in this collection that are contained in the specified collection.
	 * @param c   Object of Collection
	 */
	void retainAll(Collection<E> c); 
	/**
	 * Returns the number of elements in this collection.
	 * @return integer   size
	 */
	int size(); 
}
