import java.awt.Color;
import java.awt.Graphics;
/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * Class Circle all implement the Shape interface.
 */
public class Circle implements Shape
{
	private double radius;
	private double centerx;
	private double centery;
	private String color;
	/*** 
	 * Total area and Total perimeter of Rectangles. M_PI final double to represent PI.
	 */
	private final double M_PI = 3.14159265358979323846;
	private static double total_area=0;
	private static double total_perimeter=0;
	
	/**
	 * Default constructor
	 */
	Circle()
	{	
		
	}
	
	/**
	 * Constructor that take radius.
	 * @param radius_val radius of Circle (double)
	 */
	Circle(double radius_val)
	{
		radius = radius_val;
		add_total_area();
		add_total_perimeter();
		centerx = radius;
		centery = radius;
		color = "red";
	}
	
	/**
	 * Constructor that take radius, position x and of center, position y of center, color.
	 * @param radius_val radius of Circle (double)
	 * @param centerx_val position x of center of Circle (double)
	 * @param centery_val position y of center of Circle (double)
	 * @param color_ color of Circle (String)
	 */
	Circle(double radius_val, double centerx_val, double centery_val, String color_)
	{
		radius = radius_val;
		centerx = centerx_val;
		centery = centery_val;
		color = color_;	
		add_total_area();
		add_total_perimeter();	
	}
	
	/**
	 * Set radius of Circle.
	 * @param radius_val radius of Circle (double)
	 */
	public void setradius(double radius_val)
	{
		radius = radius_val;
	}
	
	/**
	 * Set position x of Circle.
	 * @param centerx_val position x of center (double)
	 */
	public void setcenterx(double centerx_val)
	{
		centerx = centerx_val;	
	}	
	
	/**
	 * Set position y of Circle.
	 * @param centery_val position y of center (double)
	 */
	public void setcentery(double centery_val)
	{
		centery = centery_val;	
	}
	
	/**
	 * Set color of Circle.
	 * @param color_val color of Circle (String)
	 */
	public void setcolor(String color_val)
	{ 
		color = color_val;
	}
	
	/**
	 * Get radius of Circle.
	 * @return double radius of Circle.
	 */
	public double getradius()
	{
		return radius;
	}
	/**
	 * Get position x of Circle.
	 * @return double position x of center of Circle.
	 */
	public double getcenterx()
	{
		return centerx;
	}
	/**
	 * Get position y of Circle.
	 * @return double position y of center of Circle.
	 */
	public double getcentery()
	{
		return centery;
	}
	/**
	 * Get color of Circle.
	 * @return String color of Circle.
	 */
	public String getcolor()
	{
		return color;
	}
	/**
	 * Add shape area to total area.
	 */
	public void add_total_area()
	{
		total_area += (M_PI*radius*radius);	
	}
	/**
	 * Add shape perimeter to total perimeter.
	 */
	public void add_total_perimeter()
	{
		total_perimeter += (2*M_PI*radius);
	}
	/**
	 * Static function.
	 * @return double total area of Circles
	 */
	public static double get_total_area()
	{
		return total_area;
	}
	/**
	 * Static function.
	 * @return double total perimeter of Circles
	 */
	public static double get_total_perimeter()
	{
		return total_perimeter;
	}
	
	/* 
	 * @see Shape#area()
	 */
	public double area()
	{
		return (M_PI*radius*radius);
	}
	/* 
	 * @see Shape#perimeter()
	 */
	public double perimeter()
	{
		return (2*M_PI*radius);
	}
	/* 
	 * @see Shape#increment()
	 */
	public void increment()
	{
		centerx++;
		centery++;
	}
	/* 
	 * @see Shape#decrement()
	 */
	public void decrement()
	{
		if(centerx-1>= 0 && centery-1>= 0)
		{
			centerx--;
			centery--;
		}
	}
	/* 
	 * @see Shape#compareTo(Shape)
	 */
	public int compareTo( final Shape o)
	{
		if(area() > o.area()) return 1;
		else if(area() < o.area()) return -1; 
		else return 0;
	}
			
	/* 
	 * @see Shape#Draw(java.awt.Graphics)
	 */
	public void Draw(Graphics o)
	{
		PolygonDyn p = new PolygonDyn(this);
		if(color == "green") o.setColor(Color.GREEN);
		else if(color == "red") o.setColor(Color.RED);
		else if(color == "blue") o.setColor(Color.BLUE);
		else if(color == "yellow") o.setColor(Color.YELLOW);
		else if(color == "pink") o.setColor(Color.PINK);
		o.fillPolygon(p.getx(), p.gety(), p.get_size());
		
	}
	
}
