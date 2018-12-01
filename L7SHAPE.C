#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
class shape
{
		int x ;
		int y ;

	public :
	   shape()
	   {
		   x = y = 1;
	   }
	   shape(int _xy)
	   {
		   x = y = _xy;
	   }
	   shape(int _x , int _y)
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
	virtual void draw() = 0;
	   
};





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

class Circle : public shape
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


};

class Rectangle : public shape
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
class picture : public shape
{
	  Circle* c;
	  int nc;
	  Rectangle* r ;
	  int nr;

	public :
	   picture(  Circle* _c ,  int _nc, Rectangle* _r , int _nr)
	   {
			 c = _c ;
			 nc = _nc;
			 r = _r;
			 nr = _nr;
	   }
	   void draw()
	   {
			  for( int i = 0 ; i < nc ; i++ )
			  {
					c[i].draw();
			  }
			  for( int j = 0 ; j < nr ; j++ )
			  {
					r[j].draw();
			  }
	   }

};

  void drawfun(shape** p , int n)
	   {
			  for( int i = 0 ; i < n ; i++ )
			  {
					p[i] -> draw();
			  }
	   }


	void drawfun2(shape** p , int n , int m)
	   {
			  for( int i = 0 ; i < n ; i++ )
			  {
				 for( int i = 0 ; i < m ; i++ )
				 {
					p[i] -> draw();
				 }
			  }
	   }

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
   Circle carr[3] = { Circle(100 , 100 , 50 ) ,  Circle(10 , 10 , 50 ),
						 Circle(200 , 200 , 50 )};



   Rectangle rarr[3] = { Rectangle( 150 , 105 , 200 ,50 ) , Rectangle( 100 , 100 , 200 ,50 )
							, Rectangle( 10 , 10 , 20 ,50 ) } ;


   picture p1( carr,3,rarr,3 );
   shape* ptrp = &p1;
   ptrp -> draw();


   Circle c2(200,200,30);
   Rectangle r2(200 , 200 , 300 , 350);
   shape* ptrs[2] = { &c2 , &r2};
   drawfun( ptrs , 2 );





   shape* ptrs2[2] = { carr , rarr};
   drawfun2( ptrs2 , 2 , 3 );


   /* clean up */
   getch();
   closegraph();
   return 0;
}
