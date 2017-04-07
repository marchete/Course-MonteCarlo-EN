#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#include <bits/stdc++.h> //All main STD libraries
using namespace std;

//Search limits for random numbers, shapes must be inside (0,0) and (Max_X,Max_Y) box.
const int Max_X = 5000;
const int Max_Y = 5000;

class Circle{
public:
  int x,y; //Position
  int radius; //Size
  int radius2; //radius*radius, for speeding up calculations
  Circle(int _x, int _y,int _r){ x=_x;y=_y;radius=_r;radius2 = _r*_r; }
  inline const bool isInsideShape (const int& p_x,const int& p_y)
   {
	 int dist_2 = (p_x-x)*(p_x-x)+(p_y-y)*(p_y-y); //Squared distance, we won't use sqrt for performance reasons
	 return dist_2 <= radius2;
   }  
   double ReferenceArea()
   {
     return (double)(M_PI*radius2);	//PI * r * r
   }   
};


double MonteCarlo_CalcArea(const int& NoSimulations,Circle circle)
{
	srand (time(NULL));//Initialize random numbers
	int areaCount = 0;
	for (int i=0;i < NoSimulations;++i)
	{
		if ( circle.isInsideShape(rand()%Max_X,rand()%Max_Y )) //Each time we are inside the shape
			++areaCount; //Add 1 to the area count
	}
	return ((double)Max_X*(double)Max_Y*(double)areaCount)/(double)(NoSimulations); //Then the area should be a % of the Max Area
}


int main()
{
  Circle circle(2800,2400,2000);
  int Simcount = 10;
  cout << "Calculating the area of a Circle:"<<endl;
  for (int i=0;i < 7;++i){
	  double MC_Area = MonteCarlo_CalcArea( Simcount,circle);
	  double Ref_Area = circle.ReferenceArea();
	  double Accuracy = 100.0-100.0*abs(Ref_Area-MC_Area)/Ref_Area;
      cout << "Simulations:"<< std::setw(10)<< Simcount<<" : Monte Carlo Area:"<<(int)MC_Area<<" Reference Area:"<<(int)Ref_Area<<" Accuracy:"<<fixed<<std::setprecision(4)<<Accuracy<<"%"<<endl;
	Simcount *=10;
  }
  cout <<"Tests finished"<<endl;
  return 0;
}