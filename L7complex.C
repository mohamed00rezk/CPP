#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class complex
{
  private :
	int real ;
	int img ;

	static int n ;

  public :
	complex(int _real = 0 , int _img=0)
	{
		 real = _real ;
		 img = _img ;
         n++ ;
	}

	void SetReal(int _real)
	{
		 real = _real ;
	}
	void SetImg(int _img)
	{
		 img = _img ;
	}
	int GetReal()
	{
	   return real ;
	}
	int GetImg()
	{
	   return real ;
	}
	static int getn()
	{
	   return n ;
	}

	void print()
	{
	   if (img > 0 )
			cout << real << "+" << img << "i" << endl ;
	   else if ( img < 0)
			cout << real << img << "i" << endl ;
	   else
			cout << real ;
	}

	complex add(complex c2 )
	{
		 complex res ;
		 res.real = real + c2.real ;
		 res.img = img + c2.img ;
         return res ;
	}
	complex operator + (complex c )
	{
		 complex res ;
		 res.real = real + c.real ;
		 res.img = img  + c.img ;
		 return res ;
	}
	complex operator + (int x )
	{
		 complex res ;
		 res.real = real + x ;
		 res.img = img  ;
		 return res ;
	}
   friend complex operator + (int x , complex c )  ;
	int operator == (complex c )
	{
		  return (real==c.real && img == c.img ) ;
	}

	complex operator ++ ( )
	{
	     real += real  ;
		 return *this ;
	}
	 operator float( )
	{
		 return real ;
	}

   friend 	ostream& operator << ( ostream& os, const complex& c );
};

	ostream& operator << ( ostream& os, const complex& c )
	{
		 os << c.real<< "+"<< c.img << "j" <<endl;
		 return os ;
	}

	complex operator + (int x , complex c )
	{
		 complex res ;
		 res.real = x + c.real ;
		 res.img = c.img  ;
		 return res ;
	}

int complex::n= 0 ;
int main ()
{
	clrscr();

	complex c1 ;
	c1.SetReal(10);
	c1.SetImg(10);
	c1.print() ;

	complex c2 ;
	c2.SetReal(25);
	c2.SetImg(25);
	c2.print() ;

	cout << " counter : " << complex::getn() << endl ;

	complex c3 ;
	c3 = c1.add(c2);
	c3.print();
	complex c4 ;
	cout <<" com + com :    "  ;
	c4 = c1 + c2 ;
	c4.print();
	cout <<" com + int :    "  ;
	c4 = c1 + 3 ;
	c4.print();
	cout <<" int + com :    "  ;
	c4 = 3 + c1 ;
	c4.print();
	cout <<" compare :    "  ;
	if ( c1 == c2 )
		cout << " equal " ;
	else
		cout << " not equal " ;

	cout <<" ++c :    "   ;
	c4.print();

	cout <<" castng :    "  ;
	float x ;
	x = float(c1) ;
	cout << x  ;
	complex c5(2 ,3 );
	cout <<endl <<"  over loading isotream    " << endl  ;
	cout << c5 ;

	getch();
	return 0 ;
}

