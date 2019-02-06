import java.util.ArrayList;
import java.awt.Color;
import java.awt.Graphics;
import java.lang.Math;

/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * PolygonVect is a concrete classes that derive from Polygon class. 
 * PolygonVect uses Collection class ArrayList vectors to keep the 2D points.
 */
public class PolygonVect extends Polygon
{
	private int size;
	private String color;
	private double area_, perimeter_;
	/**
	 *  PI final double to represent PI.
	 *  ArrayList<Integer> Keepx : Keep position x of points.
	 *  ArrayList<Integer> Keepy : Keep position y of points.
	 */
	private final double PI = 3.14159265;
	private ArrayList<Integer> Keepx = new ArrayList<>();
	private ArrayList<Integer> Keepy = new ArrayList<>();
	
	/**
	 * Default constructor
	 */
	PolygonVect()
	{
		size = 0;
		area_ = 0;
		perimeter_ = 0;
		color = "blue";
	}
	
	/**
	 * A conversion constructor that converts from a 2D Point.
	 * @param x position x of 2D Point (double)
	 * @param y position y of 2D Point (double)
	 */
	PolygonVect(double x, double y)
	{
		// Allocate memory to 1 Point2D object then copy in array
		size = 1;		// size will be 1.
		Keepx.add((int)x);
		Keepy.add((int)y);
		area_ = 0;
		perimeter_ = 0;

	}
	
	/**
	 * Conversion constructors that convert from Rectangle object.
	 * @param shape Rectangle object
	 */
	PolygonVect(Rectangle shape)
	{
		int tempx, tempy;
		size = 4;		// size will be 4.
		// Allocate memory to 4 Point2D object then copy in array
		tempx = (int)(shape.getposx());
		tempy = (int)(shape.getposy());
		Keepx.add(tempx);
		Keepy.add(tempy);
		
		tempx = (int)(shape.getposx() + shape.getwidth());
		tempy = (int)(shape.getposy());
		Keepx.add(tempx);
		Keepy.add(tempy);
		
		tempx = (int)(shape.getposx() + shape.getwidth());
		tempy = (int)(shape.getposy() + shape.getheight());
		Keepx.add(tempx);
		Keepy.add(tempy);

		tempx = (int)(shape.getposx());
		tempy = (int)(shape.getposy() + shape.getheight());
		Keepx.add(tempx);
		Keepy.add(tempy);
		
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * Conversion constructors that convert from Circle object.
	 * @param shape Circle object
	 */
	PolygonVect(Circle shape)
	{
		size = 100;		// size will be 100.
		int tempx, tempy;
		double angle = 0;

		for(int i=0; i<100; i++)
		{
			// Circle parametric equation
			//	x = cx + r * cos(a)
			//	y = cy + r * sin(a)	
			angle = (360.0/100) * i;
			tempx = (int)(shape.getcenterx() + shape.getradius() * Math.cos(angle * PI / 180.0));
			tempy = (int)(shape.getcentery() + shape.getradius() * Math.sin(angle * PI / 180.0));
			Keepx.add(tempx);
			Keepy.add(tempy);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * Conversion constructors that convert from Triangle object.
	 * @param shape Triangle object.
	 */
	PolygonVect(Triangle shape)
	{
		size = 3;	// size will be 3.
		int tempx, tempy;
		
		tempx = (int)(shape.getposx1());
		tempy = (int)(shape.getposy1());
		Keepx.add(tempx);
		Keepy.add(tempy);
		
		tempx = (int)(shape.getposx2());
		tempy = (int)(shape.getposy2());
		Keepx.add(tempx);
		Keepy.add(tempy);
		
		tempx = (int)(shape.getposx3());
		tempy = (int)(shape.getposy3());
		Keepx.add(tempx);
		Keepy.add(tempy);
	
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * constructor to copy PolygonVect objects' points.
	 * @param shape PolygonVect object
	 */
	PolygonVect(PolygonVect shape)
	{
		int tempx, tempy;
		size = shape.get_size();
		for(int i=0; i<size; i++)
		{
			tempx = (int)(shape.getx().get(i));
			tempy = (int)(shape.gety().get(i));
			Keepx.add(tempx);
			Keepy.add(tempy);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * constructor to copy PolygonDyn objects' points.
	 * @param shape PolygonDyn object
	 */
	PolygonVect(PolygonDyn shape)
	{
		int tempx, tempy;
		size = shape.get_size();
		for(int i=0; i<size; i++)
		{
			tempx = (int)(shape.getx()[i]);
			tempy = (int)(shape.gety()[i]);
			Keepx.add(tempx);
			Keepy.add(tempy);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * Set size of PolygonVect.
	 * @param number size (integer)
	 */
	public void set_size(int number)
	{
		size = number;
	}
	/**
	 * Get amount of points or size of PolygonVect.
	 * @return integer size
	 */
	public int get_size()
	{
		return size;
	}
	
	/**
	 * Set area of PolygonVect.
	 * @param x area (double)
	 */
	public void set_area(double x)
	{
		area_ = x;
	}
	/**
	 * Set perimeter of PolygonVect.
	 * @param x perimeter (double)
	 */
	public void set_perimeter(double x)
	{
		perimeter_ = x;
	}
	/**
	 * Get color of PolygonVect.
	 * @return color (String)
	 */
	public String getcolor()
	{
		return color;
	}
	/**
	 * Get ArrayList that keep position x of Point2D objects.
	 * @return Keepx that keep position x (ArrayList Integer).
	 */
	public ArrayList<Integer> getx()
	{
		return Keepx;
	}
	/**
	 * Get ArrayList that keep position y of Point2D objects.
	 * @return Keepy that keep position y (ArrayList Integer).
	 */
	public ArrayList<Integer> gety()
	{
		return Keepy;
	}
	
	/* 
	 * @see Shape#area()
	 */
	public double area()
	{
		return area_;
	}
	/* 
	 * @see Shape#perimeter()
	 */
	public double perimeter()
	{
		return perimeter_;
	}
	/* 
	 * @see Shape#increment()
	 */
	public void increment()
	{
		for(int i=0 ; i<size ; i++)
        {
            Keepx.set(i,Keepx.get(i)+1);
            Keepy.set(i,Keepy.get(i)+1);
        }
	}
	/* 
	 * @see Shape#decrement()
	 */
	public void decrement()
	{
		int flag = 1;
		for(int i=0; i<size; i++)
		{
			// position can not be negative.
			if(!(Keepx.get(i)-1>= 0 && Keepy.get(i)-1>= 0))
			{
				flag = -1;
			}
		}
		if(flag == 1)
		{
			for(int i=0; i<size; i++)
			{
				Keepx.set(i,Keepx.get(i)-1);
	            Keepy.set(i,Keepy.get(i)-1);
			}
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
