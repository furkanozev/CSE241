import java.awt.Color;
import java.awt.Graphics;
import java.lang.Math;
/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * Class Triangle all implement the Shape interface.
 */
public class Triangle implements Shape
{
	private double edge;
	private double posx1;
	private double posy1;
	private double posx2;
	private double posy2;
	private double posx3;
	private double posy3;
	private String color="green";
	/*** 
	 * Total area and Total perimeter of Rectangles.
	 */
	private static double total_area=0;
	private static double total_perimeter=0;
	
	/**
	 * Default constructor
	 */
	Triangle()
	{	
		
	}
	/**
	 * Constructor that take edge.
	 * @param edge_val edge of Triangle (double)
	 */
	Triangle(double edge_val)
	{
		edge = edge_val;
		add_total_area();
		add_total_perimeter();	
		posx1 = edge / 2;
		posy1 = 0;
		posx2 = 0;
		posy2 = (edge / 2) * Math.sqrt(3);
		posx3 = edge;
		posy3 = (edge / 2) * Math.sqrt(3);
		color = "red";
	}
	
	/**
	 * Constructor that take edge, positions of 3 points and color.
	 * @param edge_val edge of Triangle (double)
	 * @param posx1_val point1 position x of Triangle (double)
	 * @param posy1_val point1 position y of Triangle (double)
	 * @param posx2_val point2 position x of Triangle (double)
	 * @param posy2_val point2 position y of Triangle (double)
	 * @param posx3_val point3 position x of Triangle (double)
	 * @param posy3_val point3 position y of Triangle (double)
	 * @param color_ color of Triangle (String)
	 */
	Triangle(double edge_val, double posx1_val, double posy1_val, double posx2_val, double posy2_val, double posx3_val, double posy3_val, String color_)
	{
		edge = edge_val;
		add_total_area();
		add_total_perimeter();	
		posx1 = posx1_val;
		posy1 = posy1_val;
		posx2 = posx2_val;
		posy2 = posy2_val;
		posx3 = posx3_val;
		posy3 = posy3_val;
		color = color_;
	}
	
	/**
	 * Set edge of Triangle.
	 * @param edge_val edge of Triangle (double)
	 */
	public void setedge(double edge_val)
	{
		edge = edge_val;
	}
	/**
	 * Set point1 position x of Triangle.
	 * @param posx_val point1 position x of Triangle (double)
	 */
	public void setposx1(double posx_val)
	{
		posx1 = posx_val;
	}
	/**
	 * Set point1 position y of Triangle.
	 * @param posy_val point1 position y of Triangle (double)
	 */
	public void setposy1(double posy_val)
	{
		posy1 = posy_val;
	}
	/**
	 * Set point2 position x of Triangle.
	 * @param posx_val point2 position x of Triangle (double)
	 */
	public void setposx2(double posx_val)
	{
		posx2 = posx_val;
	}
	/**
	 * Set point2 position y of Triangle.
	 * @param posy_val point2 position y of Triangle (double)
	 */
	public void setposy2(double posy_val)
	{
		posy2 = posy_val;
	}
	/**
	 * Set point3 position x of Triangle.
	 * @param posx_val point3 position x of Triangle (double)
	 */
	public void setposx3(double posx_val)
	{
		posx3 = posx_val;
	}
	/**
	 * Set point3 position y of Triangle.
	 * @param posy_val point3 position y of Triangle (double)
	 */
	public void setposy3(double posy_val)
	{
		posy3 = posy_val;
	}
	/**
	 * Set color of Triangle.
	 * @param color_val color of Triangle (String)
	 */
	public void setcolor(String color_val)
	{
		color = color_val;
	}
	
	/**
	 * Get edge of Triangle.
	 * @return double edge of Triangle.
	 */
	public double getedge()
	{
		return edge;
	}
	/**
	 * Get point1 position x of Triangle.
	 * @return double position x of point1.
	 */
	public double getposx1()
	{
		return posx1;
	}
	/**
	 * Get point1 position y of Triangle.
	 * @return double position y of point1.
	 */
	public double getposy1()
	{
		return posy1;
	}
	/**
	 * Get point2 position x of Triangle.
	 * @return double position x of point2.
	 */
	public double getposx2()
	{
		return posx2;
	}
	/**
	 * Get point2 position y of Triangle.
	 * @return double position y of point2.
	 */
	public double getposy2()
	{ 
		return posy2;
	}
	/**
	 * Get point3 position x of Triangle.
	 * @return double position x of point3.
	 */
	public double getposx3()
	{
		return posx3;
	}
	/**
	 * Get point3 position y of Triangle.
	 * @return double position y of point3.
	 */
	public double getposy3()
	{	
		return posy3;
	}
	/**
	 * Get color of Triangle.
	 * @return String color of Triangle.
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
		total_area += (edge*edge*Math.sqrt(3)/4);
	}
	/**
	 * Add shape perimeter to total perimeter.
	 */
	public void add_total_perimeter()
	{
		total_perimeter += (3*edge);
	}
	/**
	 * Static function.
	 * @return double total area of Triangles
	 */
	public static double get_total_area()
	{
		return total_area;
	}
	/**
	 * Static function.
	 * @return double total perimeter of Triangles
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
		return (Math.pow(edge,2)*Math.sqrt(3)/4);
	}
	/* 
	 * @see Shape#perimeter()
	 */
	public double perimeter()
	{
		return (3*edge);
	}
	/* 
	 * @see Shape#increment()
	 */
	public void increment()
	{
		posx1++;
		posy1++;
		posx2++;
		posy2++;
		posx3++;
		posy3++;
	}
	/* 
	 * @see Shape#decrement()
	 */
	public void decrement()
	{
		if(posx1-1>= 0 && posy1-1>= 0 && posx2-1>= 0 && posy2-1>= 0 && posx3-1>= 0 && posy3-1>= 0)
		{
			posx1--;
			posy1--;
			posx2--;
			posy2--;
			posx3--;
			posy3--;
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
