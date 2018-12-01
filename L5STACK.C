#include<stdio.h>
#include<conio.h>
#include<iostream.h>


class typeA
{
	 int x , y ;

  public :
	typeA(int _x = 0 , int _y = 0)
	{
		 x = _x;
         y = _y;
	}
	int sum()
	{
		return x + y  ;
	}
	int mul()
	{
		return x * y  ;
	}


};



class typeB : public typeA
{
	 int z ;

  public :
	typeB(int _x = 0 , int _y = 0 , int _z = 0): typeA( _x , _y )
	{
		 z = _z;
	}
	int sum()
	{
	   return typeA::sum() + z ;
	}

};




int main ()
{
	clrscr();

	typeA a1(10,5);
	int x = a1.sum();
	cout << " sum typeA " << x << endl ;
	typeB b1( 2 ,3) ;
	int z = b1.mul() ;
    cout << "mul tybeB " << z ;

	getch();
	return 0 ;
}

