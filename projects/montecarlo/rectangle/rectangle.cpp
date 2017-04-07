#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#include <bits/stdc++.h> //All main STD libraries
using namespace std;

//Search limits for random numbers, shapes must be inside (0,0) and (Max_X,Max_Y) box.
const int Max_X = 5000;
const int Max_Y = 5000;

class Rectangle{
public:
  int x,y; //Position
  int w,h; //Size
  Rectangle(int _x, int _y,int _w, int _h){ x=_x;y=_y;w=_w;h=_h; }
  inline const bool isInsideShape (const int& p_x,const int& p_y)
   {
	 return (p_x >= x && p_y >= y && p_x <= (x+w) && p_y <= (y+h));
   }  
   double ReferenceArea()
   {
     return (double)(w*h);	
   }   
};


double MonteCarlo_CalcArea(const int& NoSimulations,Rectangle rect)
{
	srand (time(NULL));//Initialize random numbers
	int areaCount = 0;
	for (int i=0;i < NoSimulations;++i)
	{
		if ( rect.isInsideShape(rand()%Max_X,rand()%Max_Y )) //Each time we are inside the shape
			++areaCount; //Add 1 to the area count
	}
	return ((double)Max_X*(double)Max_Y*(double)areaCount)/(double)(NoSimulations); //Then the area should be a % of the Max Area
}


int main()
{
  Rectangle rect(10,10,4600,3600);
  int Simcount = 10;
  cout << "Calculating the area of a Rectangle:"<<endl;
  for (int i=0;i < 7;++i){
	  double MC_Area = MonteCarlo_CalcArea( Simcount,rect);
	  double Ref_Area = rect.ReferenceArea();
	  double Accuracy = 100.0-100.0*abs(Ref_Area-MC_Area)/Ref_Area;
      cout << "Simulations:"<< std::setw(10)<< Simcount<<" : Monte Carlo Area:"<<(int)MC_Area<<" Reference Area:"<<(int)Ref_Area<<" Accuracy:"<<fixed<<std::setprecision(4)<<Accuracy<<"%"<<endl;
	Simcount *=10;
  }
  cout <<"Tests finished"<<endl;
  return 0;
}