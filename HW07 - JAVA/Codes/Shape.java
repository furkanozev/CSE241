import java.awt.Graphics;
/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * Shape interface implements the Comparable interface.
 */
public interface Shape extends Comparable<Shape>
{	
	/**
	 * area that returns the area of the shape.
	 * @return double area of shape.
	 */
	public double area();
	/**
	 * perimeter that returns the perimeter.
	 * @return double area of shape.
	 */
	public double perimeter();
	/**
	 * Functions increment for incrementing the shape positions by 1.0.
	 */
	public void increment();
	/**
	 * Functions decrement for decrementing the shape positions by 1.0.
	 */
	public void decrement();
	/*
	 * This interface implements the Comparable interface to compare shapes with respect to their areas.
	 * if area big return 1, small return -1, equal return 0
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	public int compareTo( final Shape o);	
			
	/**
	 * Draw takes a Graphics object as parameter and draws the shape. 
	 * This method will be called from the paintComponent method of a JPanel object.
	 * @param o Graphics object
	 */
	public void Draw(Graphics o);
}