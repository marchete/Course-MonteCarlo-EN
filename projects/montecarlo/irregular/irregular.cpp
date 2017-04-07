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
class Circle{ //I know I know, without inheritance and that
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

double MonteCarlo_CalcArea(const int& NoSimulations,Rectangle rect,Circle circle, bool INTERSECTION)
{
	srand (time(NULL));//Initialize random numbers
	int areaCount = 0;
	if (INTERSECTION) //We move that conditional outside to reduce checks on the loop, to reduce CPU usage a bit
	{
  	 for (int i=0;i < NoSimulations;++i)
	 {
	     int randx = rand()%Max_X;
	     int randy = rand()%Max_Y;
		//Each time we are inside both shapes - INTERSECTION
		if ( rect.isInsideShape(randx,randy ) && circle.isInsideShape(randx,randy )) 
			++areaCount; //Add 1 to the area count
	  }
	}
	else 
	  for (int i=0;i < NoSimulations;++i)
	  {
	     int randx = rand()%Max_X;
	     int randy = rand()%Max_Y;	      
		//Each time we are inside any shape - UNION
		if ( rect.isInsideShape(randx,randy ) || circle.isInsideShape(randx,randy )) 
			++areaCount; //Add 1 to the area count
	  }
	return ((double)Max_X*(double)Max_Y*(double)areaCount)/(double)(NoSimulations); //Then the area should be a % of the Max Area
}


int main()
{
 {	 // Testing Circle inside Rectangle
  Rectangle rect(10,10,4600,3600);
  Circle circle(1800,1400,1000);
  for (int j = 0;j < 2;++j) //j==0 INTERSECTION , j==1 UNION
  {
   int Simcount = 10;
   cout << "Circle inside Rectangle - "<<(j==0?"INTERSECTION":"UNION")<<endl;
   for (int i=0;i < 7;++i){
	  double MC_Area = MonteCarlo_CalcArea( Simcount,rect,circle, (j==0));
	  double Ref_Area = (j==0? circle.ReferenceArea():rect.ReferenceArea());
	  double Accuracy = 100.0-100.0*abs(Ref_Area-MC_Area)/Ref_Area;
      cout << "Simulations:"<< std::setw(10)<< Simcount<<" : Monte Carlo Area:"<<(int)MC_Area<<" Reference Area:"<<(int)Ref_Area<<" Accuracy:"<<fixed<<std::setprecision(4)<<Accuracy<<"%"<<endl;
	Simcount *=10;
   }
  }
 }
 
 {	 // Testing Rectangle inside Circle 
  Rectangle rect(2300,1900,1000,1000);
  Circle circle(2800,2400,2000);
  for (int j = 0;j < 2;++j) //j==0 INTERSECTION , j==1 UNION
  {
   int Simcount = 10;
   cout << "Rectangle inside Circle - "<<(j==0?"INTERSECTION":"UNION")<<endl;
   for (int i=0;i < 7;++i){
	  double MC_Area = MonteCarlo_CalcArea( Simcount,rect,circle, (j==0));
	  double Ref_Area = (j==0? rect.ReferenceArea():circle.ReferenceArea());
	  double Accuracy = 100.0-100.0*abs(Ref_Area-MC_Area)/Ref_Area;
      cout << "Simulations:"<< std::setw(10)<< Simcount<<" : Monte Carlo Area:"<<(int)MC_Area<<" Reference Area:"<<(int)Ref_Area<<" Accuracy:"<<fixed<<std::setprecision(4)<<Accuracy<<"%"<<endl;
	Simcount *=10;
   }
  }
 }
 
 {	 // Testing irregular shape, not a shape inside another completely
  Rectangle rect(10,10,3000,4000);
  Circle circle(2800,2400,2000);
  for (int j = 0;j < 2;++j) //j==0 INTERSECTION , j==1 UNION
  {
   int Simcount = 10;
   cout << "Irregular Shape - "<<(j==0?"INTERSECTION":"UNION")<<endl;
   for (int i=0;i < 7;++i){
	  double MC_Area = MonteCarlo_CalcArea( Simcount,rect,circle, (j==0));
	  //double Ref_Area = (j==0? rect.ReferenceArea():circle.ReferenceArea()); //Who knows
	  //double Accuracy = 100.0-100.0*abs(Ref_Area-MC_Area)/Ref_Area;
      cout << "Simulations:"<< std::setw(10)<< Simcount<<" : Monte Carlo Area:"<<(int)MC_Area<<" Reference Area:"<<"???"<<" Accuracy:"<<"???%"<<endl;
	Simcount *=10;
   }
  }
 }
  
  
  cout <<"Tests finished"<<endl;
  return 0;
}