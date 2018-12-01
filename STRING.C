#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>


class string
{
	char* arr ;
	int size , tos ;


	public :
		string(int _s = 0 )
		{
		   //	cout << "cons 1 " << endl;
		   size = _s;
		   arr = new char[size];
		   tos = 0 ;
		}
		string(string& s)
		{
		   tos = s.tos ;
		   size = s.size ;
		   arr = new char[size];
		   for ( int i = 0 ; i < tos  ; i ++ )
			{
				arr[i] = s.arr[i] ;
			}
		 }
	

		// push
		void gets(char* _arr)
		{
			 for ( int i = 0 ; i < size ; i++ )
			 {

				if(_arr[i] != '\0' )
				{
				   arr[i] = _arr[i] ;
				   ++tos;
				  // cout << tos <<endl ;
				}
				else
				{
				   // cout << "tos" << i << endl ;
					  break;
				}
			 }
		}

		// pint
		void print()
			{

			  for (int  i = 0 ; i < tos  ; i++  )
	          {
				   cout << arr[i] ;
			  }
			}

		// string functions
		int strlen()
		{
			int w = 0;
			while(arr[w] != '\0')
				w++;
			return w;
		}
                
		string strcpy( string& wor )
		{
			wor.tos = tos ;
			wor.size = size ;
			delete[] wor.arr;
			wor.arr = new char[size];
			int w = 0 ;
			while(arr[w] != '\0')
			{
				wor.arr[w] = arr[w];
                w++;
			}
				wor.arr[w] = '\0';
				return wor;
		}

		int strcmp(string& wor)
		 {
			int i = 0;
			while( arr[i] != '\0' && wor.arr[i] != '\0')
			{
					if(arr[i] - wor.arr[i] > 0)
						  return arr[i] - wor.arr[i];
					else if(arr[i] - wor.arr[i] < 0)
						  return arr[i] - wor.arr[i];
					else if(arr[i] - wor.arr[i] == 0)
							i++;

			}
			return arr[i-1] - wor.arr[i-1];
		}

		string strcat( string& wor)
		{
		  string sf ;
		  this -> strcpy(sf);


		tos = sf.tos + wor.tos + 1 ;
		size = sf.size + wor.size +1  ;

		delete[] arr ;
		arr = new char[size];

			for ( int i = 0 ; i <= tos  ; i++ )
			{
				if ( i <= sf.tos  )
				 arr[i] = sf.arr[i] ;
				else if ( i > sf.tos  )
				 arr[i] = wor.arr[ i -  sf.tos - 1 ] ;
			}
			  arr[++i] = '\0' ;
			return *this ;
		}

		~string( )
		{
		  //	cout << "desstructor * " << endl  ;
			delete[] arr;
		}

};


int main()
{
	   clrscr();
	   string s1(10) ;
	   s1.gets("mohamed");
       s1.print();
	   cout <<endl <<"world length is : " << s1.strlen() << endl ;
	   string s2 ;
	   s1.strcpy(s2);
       cout << "string copy is: " ;
	   s2.print();
	   string s3(50) ;
	   s3.gets("Botsha");
	  // s3.print();
	   int x = s3.strcmp(s2) ;
	   cout <<"string compare res :   " << x << endl ;
	   s1.strcat(s3);
	   cout << endl << "string concate :   " << endl ;
	   s1.print();

	getch();
    return 0;
}