#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

class point
{
		int x ;
		int y ;

	public :
	   point()
	   {
		   x = y = 1;
	   }
	   point(int _xy)
	   {
		   x = y = _xy;
	   }
	   point(int _x , int _y)
	   {
		   x = _x;
		   y = _y;
	   }
   void  setx( int _x)
	   {
		   x = _x;
	   }
	void  sety( int _y)
	   {
		   y = _y;
	   }
	int getx( )
	   {
		   return x;
	   }
	int gety( )
	   {
		   return y;
	   }
};

class Circle
{
		point center ;
		int rad , shapcolor ;

	public :
	   Circle()
	   {
		   rad = 1;
		  shapcolor = 15 ;
	   }
	   Circle(int _x , int _y , int _rad)  : center(_x , _y )
	   {
		   rad = _rad;
		   shapcolor = 10 ;

	   }
	   Circle(point _p , int _rad) : center(_p.getx() , _p.gety() )
	   {
		   rad = _rad;
		   shapcolor = 10 ;

	   }


   void  setrad( int _rad)
	   {
		   rad = _rad;
	   }

	int getrad( )
	   {
		   return rad;
	   }
	void  setcol( int _col)
	   {
		   shapcolor = _col;
	   }

	int getcol( )
	   {
		   return shapcolor;
	   }
	void draw()
	   {
		   setcolor( shapcolor );
		   circle( center.getx() , center.gety() , rad );
	   }
		void draw2()
	   {
		   setcolor( shapcolor );
			fillellipse( center.getx() , center.gety() , rad , rad );
	   }

};

class Rectangle
{
		point ul , lr ;
		int  shapcolor ;

	public :
	   Rectangle()
	   {
		   shapcolor = 15 ;
	   }
	   Rectangle(int _x1 , int _y1 ,int _x2 , int _y2 ) : ul(_x1 , _y1 ),lr( _x2 , _y2 )
	   {
		   shapcolor = 15 ;
	   }

	void  setcol( int _col)
	   {
		   shapcolor = _col;
	   }

	int getcol( )
	   {
		   return shapcolor;
	   }
	void draw()
	   {
		   setcolor( shapcolor );
		   rectangle( ul.getx() , ul.gety(),lr.getx() , lr.gety() );
	   }
};
class Line
{
		point ul , lr ;
		int  shapcolor ;

	public :
	   Line()
	   {
		   shapcolor = 25 ;
	   }
	   Line(int _x1 , int _y1 ,int _x2 , int _y2 ) : ul(_x1 , _y1 ),lr( _x2 , _y2 )
	   {
		   shapcolor = 25 ;
	   }

	void  setcol( int _col)
	   {
		   shapcolor = _col;
	   }

	int getcol( )
	   {
		   return shapcolor;
	   }
	void draw()
	   {
		   setcolor( shapcolor );
		   line( ul.getx() , ul.gety(),lr.getx() , lr.gety() );
	   }
};
class tringle
{
		point p1 , p2 , p3  ;
		int  shapcolor ;

	public :
	  tringle ()
	   {
		   shapcolor = 20 ;
	   }
  tringle(int _x1 , int _y1 ,int _x2 , int _y2, int _x3 , int _y3 ) : p1(_x1 , _y1 ),p2( _x2 , _y2 ),p3( _x3 , _y3 )
	   {
		   shapcolor = 20 ;
	   }

	void  setcol( int _col)
	   {
		   shapcolor = _col;
	   }

	int getcol( )
	   {
		   return shapcolor;
	   }
	void draw()
	   {
		   setcolor( shapcolor );
		   line( p1.getx() , p1.gety() ,p2.getx() , p2.gety() );
		   line( p2.getx() , p2.gety() ,p3.getx() , p3.gety() );
		   line( p3.getx() , p3.gety() ,p1.getx() , p1.gety() );
	   }
};

int main(void)
{

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   clrscr();
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   /* draw the circle */
   Circle c1(100 , 100 , 50 );
   c1.draw();
   Circle c2(50 , 50 , 50 );
   c2.draw2();

   Rectangle r1( 100 , 100 , 200 ,50 );
   r1.draw();

   Line l1( 100 , 100 , 200 ,50 );
   l1.draw();

   tringle t1( 100 , 200 , 400 ,400 , 200 , 100 );
   t1.draw();
   /* clean up */
   getch();
   closegraph();
   return 0;
}
