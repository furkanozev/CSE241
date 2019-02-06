/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * This is a generic class with one generic parameters,
 * @param <E> Generic type (Integer or String)
 * A collection that contains no duplicate elements. There is no order for this collection.
 * In other words, you dont have to keep the insertion order of the elements.
 */
public interface Set<E> extends Collection<E> {
	/*
	 * @see Collection#iterator()
	 */
	Iterator<E> iterator();
	/* 
	 * @see Collection#add(java.lang.Object)
	 */
	void add(E e);
	/* 
	 * @see Collection#addAll(Collection)
	 */
	void addAll(Collection<E> c);
	/* 
	 * @see Collection#clear()
	 */
	void clear(); 
	/* 
	 * @see Collection#contains(java.lang.Object)
	 */
	boolean contains(E e); 
	/* 
	 * @see Collection#containsAll(Collection)
	 */
	boolean containsAll(Collection<E> c); 
	/* 
	 * @see Collection#isEmpty()
	 */
	boolean isEmpty(); 
	/* 
	 * @see Collection#remove(java.lang.Object)
	 */
	void remove(E e); 
	/*
	 * @see Collection#removeAll(Collection)
	 */
	void removeAll(Collection<E> c); 
	/*
	 * @see Collection#retainAll(Collection)
	 */
	void retainAll(Collection<E> c); 
	/* 
	 * @see Collection#size()
	 */
	int size();
}
