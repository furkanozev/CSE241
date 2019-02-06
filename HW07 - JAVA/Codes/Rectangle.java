import java.awt.Color;
import java.awt.Graphics;

/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * Class Rectangle all implement the Shape interface.
 */
public class Rectangle implements Shape
{
	private double width;
	private double height;
	private double posx;
	private double posy;
	private String color;
	/*** 
	 * Total area and Total perimeter of Rectangles.
	 */
	private static double total_area=0;
	private static double total_perimeter=0;
	
	/**
	 * Default constructor
	 */
	Rectangle()
	{	
		
	}
	
	/**
	 * Constructor that take width and height.
	 * @param width_val width of Rectangle (double)
	 * @param height_val height of Rectangle (double)
	 */
	Rectangle(double width_val, double height_val)
	{
		width = width_val;
		height = height_val;
		add_total_area();
		add_total_perimeter();
		posx = 0;
		posy = 0;
		color = "red";
	}
	
	/**
	 * Constructor that take width, height, posx, posy and color.
	 * @param width_val width of Rectangle (double)
	 * @param height_val height of Rectangle (double)
	 * @param posx_val position x of Rectangle (double)
	 * @param posy_val position y of Rectangle (double)
	 * @param color_ color of Rectangle (String)
	 */
	Rectangle(double width_val, double height_val, double posx_val, double posy_val, String color_)
	{
		width = width_val;
		height = height_val;
		posx = posx_val;
		posy = posy_val;
		color = color_;
		add_total_area();
		add_total_perimeter();		
	}
	
	/**
	 * Set width of Rectangle.
	 * @param width_val width of Rectangle (double)
	 */
	public void setwidth(double width_val)
	{
		width = width_val;	
	}
	
	/**
	 * Set height of Rectangle.
	 * @param height_val height of Rectangle (double)
	 */
	public void setheight(double height_val)
	{
		height = height_val;	
	}	
	
	/**
	 * Set position x of Rectangle.
	 * @param posx_val posx of Rectangle (double)
	 */
	public void setposx(double posx_val)
	{
		posx = posx_val;	
	}
	
	/**
	 * Set position y of Rectangle.
	 * @param posy_val posy of Rectangle (double)
	 */
	public void setposy(double posy_val)
	{
		posy = posy_val;	
	}
	
	/**
	 * Set position color of Rectangle.
	 * @param color_val color of Rectangle (String)
	 */
	public void setcolor(String color_val)
	{ 
		color = color_val;
	}
	
	/**
	 * Get width of Rectangle.
	 * @return double width of Rectangle.
	 */
	public double getwidth()
	{
		return width;
	}
	
	/**
	 * Get height of Rectangle.
	 * @return double height of Rectangle
	 */
	public double getheight()
	{
		return height;
	}
	
	/**
	 * Get position x of Rectangle.
	 * @return double position x of Rectangle
	 */
	public double getposx()
	{
		return posx;
	}
	/**
	 * Get position y of Rectangle.
	 * @return double position y of Rectangle
	 */
	public double getposy()
	{
		return posy;
	}
	/**
	 * Get color of Rectangle.
	 * @return String color of Rectangle
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
		total_area += (width*height);	
	}
	/**
	 * Add shape perimeter to total perimeter.
	 */
	public void add_total_perimeter()
	{
		total_perimeter += (2*(width+height));
	}
	/**
	 * Static function.
	 * @return double total area of Rectangles
	 */
	public static double get_total_area()
	{
		return total_area;
	}
	/**
	 * Static function.
	 * @return double total perimeter of Rectangles
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
		return width*height;
	}
	/*
	 * @see Shape#perimeter()
	 */
	public double perimeter()
	{
		return (width+height)*2;
	}
	/*
	 * @see Shape#increment()
	 */
	public void increment()
	{
		posx++;
		posy++;
	}
	/*
	 * @see Shape#decrement()
	 */
	public void decrement()
	{
		if(posx-1>= 0 && posy-1>= 0)
		{
			posx--;
			posy--;
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
