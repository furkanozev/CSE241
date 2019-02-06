/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * This is a generic class with one generic parameters,
 * @param <E> Generic type (Integer or String)
 * Queues order elements in a FIFO (first-in-first-out) manner. 
 * There is no random access with this Collection. Some functions throw exceptions.
 */
public interface Queue<E> extends Collection<E> {
	/*
	 * @see Collection#iterator()
	 */
	Iterator<E> iterator();
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
	/* Inserts the specified element into this queue.
	 * @see Collection#add(java.lang.Object)
	 */
	void add(E e);
	/**
	 * Retrieves, but does not remove, the head of this queue.
	 * @return E  Generic variable (Integer or String)
	 */
	E element();
	/**
	 * Inserts the specified element into this queue.
	 * @param e  Generic variable (Integer or String)
	 */
	void offer(E e);
	/**
	 * Retrieves and removes the head of this queue, or throws if this queue is empty.
	 * @return E  Generic variable (Integer or String)
	 * @throws MyException object of Myexception
	 */
	E poll() throws MyException;
}
