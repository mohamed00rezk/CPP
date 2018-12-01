#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


class shapearea
{    protected:
		int x , y ;
	public :
	   shapearea(int _x = 0 , int _y = 0)
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
	   virtual float area()
	   {
		   return 1;
	   }
};

class Circle : public shapearea
{

	public :
	   Circle(int _r = 0) : shapearea( _r)
	   {

	   }


	float area( )
	   {
		   return 3.14 * x * x ;
	   }

};

class Rectangle  : public shapearea
{

	public :
	   Rectangle(int _h , int _w)  : shapearea( _h , _w )
	   {

	   }
	   float area( )
	   {
		   return x * y ;
	   }

};

 float areafun(shapearea* p )
  {
	 return  p -> area();
  }



int main(void)
{
   clrscr();
   Circle c1(3) ;
   shapearea* ptrc = &c1;
   float y = ptrc -> area();
   cout << y << endl ;

   Rectangle r1(3 ,2) ;
   shapearea* ptrr = &r1;
   float x = ptrr -> area();
   cout << x << endl;
   float z = areafun(&c1) ;
   cout << "AREA Stand alone " << z;

   getch();
   return 0;
}
