
import java.awt.Color;
import java.awt.Graphics;
import java.lang.Math;

/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * PolygonDyn is a concrete classes that derive from Polygon class. 
 * PolygonDyn uses Java arrays to keep the 2D points.
 */
public class PolygonDyn  extends Polygon
{
	private int size;
	private String color;
	private double area_, perimeter_;
	/**
	 *  PI final double to represent PI.
	 *  int[] Keepx : Keep position x of points.
	 *  int[] Keepy : Keep position y of points.
	 */
	private int[] Keepx;
	private int[] Keepy;
	private final double PI = 3.14159265;
	
	/**
	 * Default constructor
	 */
	PolygonDyn()
	{
		// size will be 0 and pointer will be null
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
	PolygonDyn(double x, double y)
	{
		// Allocate memory to 1 Point2D object then copy in array
		size = 1;		// size will be 1.
		Keepx = new int[1];
		Keepy = new int[1];
		Keepx[0] = (int)x;
		Keepy[0] = (int)y;
		area_ = 0;
		perimeter_ = 0;
	}
	
	/**
	 * Conversion constructors that convert from Rectangle object.
	 * @param shape Rectangle object
	 */
	PolygonDyn(Rectangle shape)
	{
		size = 4;		// size will be 4.
		// Allocate memory to 4 Point2D object then copy in array
		Keepx = new int[4];
		Keepy = new int[4];

		Keepx[0] = (int) (shape.getposx());
		Keepy[0] = (int) (shape.getposy());

		Keepx[1] = (int) (shape.getposx() + shape.getwidth());
		Keepy[1] = (int) (shape.getposy());

		Keepx[2] = (int) (shape.getposx() + shape.getwidth());
		Keepy[2] = (int) (shape.getposy() + shape.getheight());

		Keepx[3] = (int) (shape.getposx());
		Keepy[3] = (int) (shape.getposy() + shape.getheight());
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * Conversion constructors that convert from Circle object.
	 * @param shape Circle object
	 */
	PolygonDyn(Circle shape)
	{
		size = 100;		// size will be 100.
		// Allocate memory to 100 Point2D object then copy in array
		int i;
		double angle = 0;
		Keepx = new int[100];
		Keepy = new int[100];
		for(i=0; i<100; i++)
		{
			// Circle parametric equation
			//	x = cx + r * cos(a)
			//	y = cy + r * sin(a)	
			angle = (360.0/100) * i;
			Keepx[i] = (int) (shape.getcenterx() + shape.getradius() * Math.cos(angle * PI / 180.0));
			Keepy[i] = (int) (shape.getcentery() + shape.getradius() * Math.sin(angle * PI / 180.0));
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * Conversion constructors that convert from Triangle object.
	 * @param shape Triangle object.
	 */
	PolygonDyn(Triangle shape)
	{
		size = 3;	// size will be 3.
		// Allocate memory to 3 Point2D object then copy in array
		Keepx = new int[3];
		Keepy = new int[3];

		Keepx[0] = (int) (shape.getposx1());
		Keepy[0] = (int) (shape.getposy1());

		Keepx[1] = (int) (shape.getposx2());
		Keepy[1] = (int) (shape.getposy2());

		Keepx[2] = (int) (shape.getposx3());
		Keepy[2] = (int) (shape.getposy3());
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	/**
	 * constructor to copy PolygonVect objects' points.
	 * @param shape PolygonVect object
	 */
	PolygonDyn(PolygonVect shape)
	{
		
		size = shape.get_size();
		Keepx = new int[size];
		Keepy = new int[size];
		for(int i=0; i<size; i++)
		{
			Keepx[i] = (int)(shape.getx().get(i));
			Keepy[i] = (int)(shape.gety().get(i));
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	/**
	 * constructor to copy PolygonDyn objects' points.
	 * @param shape PolygonDyn object
	 */
	PolygonDyn(PolygonDyn shape)
	{
		size = shape.get_size();
		Keepx = new int[size];
		Keepy = new int[size];
		for(int i=0; i<size; i++)
		{
			Keepx[i] = (int)(shape.getx()[i]);
			Keepy[i] = (int)(shape.gety()[i]);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/**
	 * Set size of PolygonDyn.
	 * @param number size (integer)
	 */
    public void set_size(int number)
	{
		size = number;
	}
    /**
	 * Get amount of points or size of PolygonDyn.
	 * @return integer size
	 */
	public int get_size()
	{
		return size;
	}
	
	/**
	 * Set area of PolygonDyn.
	 * @param x area (double)
	 */
	public void set_area(double x)
	{
		area_ = x;
	}
	/**
	 * Set perimeter of PolygonDyn.
	 * @param x perimeter (double)
	 */
	public void set_perimeter(double x)
	{
		perimeter_ = x;
	}
	/**
	 * Get color of PolygonDyn.
	 * @return color (String)
	 */
	public String getcolor()
	{
		return color;
	}
	/**
	 * Get Array that keep position x of Point2D objects.
	 * @return Keepx that keep position x (int[]).
	 */
	public int[] getx()
	{
		return Keepx;
	}
	/**
	 * Get Array that keep position y of Point2D objects.
	 * @return Keepx that keep position y (int[]).
	 */
	public int[] gety()
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
            Keepx[i]++;
            Keepy[i]++;
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
			if(!(Keepx[i]-1>= 0 && Keepy[i]-1>= 0))
			{
				flag = -1;
			}
		}
		if(flag == 1)
		{
			for(int i=0; i<size; i++)
			{
				Keepx[i]--;
	            Keepy[i]--;
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
		if(color == "green") o.setColor(Color.GREEN);
		else if(color == "red") o.setColor(Color.RED);
		else if(color == "blue") o.setColor(Color.BLUE);
		else if(color == "yellow") o.setColor(Color.YELLOW);
		else if(color == "pink") o.setColor(Color.PINK);
		o.fillPolygon(this.getx(), this.gety(), this.get_size());
	}
}
