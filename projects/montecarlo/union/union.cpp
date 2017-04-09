#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //To enable optimizations in Codingame
#include <bits/stdc++.h> //All main STD libraries
#include <fstream>
using namespace std;

//Declaring area limits, shapes must be inside (0,0) and (Max_X,Max_Y) box.
const double Max_X = 200.00;
const double Max_Y = 200.00;
const double Reference_Area = Max_X * Max_Y;

/** 
 @brief Operation types between shapes.
*/
enum UnionType { UNION , INTERSECTION , SUBTRACTION};

/** 
 @brief Shape class, holds the shape that will be measured
*/
class Shape{
public:
  double x,y; //Position
  Shape(){x=0.0;y=0.0;}
  Shape(double _x, double _y){ x=_x;y=_y;}
  virtual string getName() {return "Shape";} 
  virtual string getJavascript(){return "";}
/** 
 @brief Checks if a point it's inside the shape or not
 @param p_x p_y Coordinates of the point to be tested
 @return boolean, true if the point it's inside the shape.
*/    
  virtual inline const bool isInsideShape (const double& p_x,const double& p_y)
  {
	 return x == p_x && y == p_y;
  }  
/** 
 @brief The Area of the shape calculated in a mathematical way.
        It's used to measure the deviation of Monte Carlo area vs the real area.
 @return double, the Area.
*/    
  virtual double ReferenceArea() {  return 0.00; }  
};



/** 
 @brief A Rectangle, derived class from Shape base class.
*/    
class Rectangle:public Shape{
public:
 double w,h; //Size
 Rectangle(int _x, int _y,int _w, int _h):Shape(_x,_y){ w=_w;h=_h; }
 
 string getName() {
     string s = "Rectangle X:";
     return s+to_string(x)+" Y:"+to_string(y)+" W:"+to_string(w)+" H:"+to_string(h);
  } 
 string getJavascript()
 { return "figuras.push(new Rectangle("+to_string(x)+","+to_string(y)+","+to_string(w)+","+to_string(h)+"));";}     
 inline const bool isInsideShape (const double& p_x,const double& p_y)
 { 
   return (p_x >= x && p_y >= y && p_x < (x+w) && p_y < (y+h)); 
 }  

  double ReferenceArea() { return (w*h); }   
};

/** 
 @brief A Circle, derived class from Shape base class.
*/    
class Circle:public Shape{
public:
  double radius; //Size
  double radius2; //Squared Radius, for preformance purposes
  Circle(double _x, double _y,double _r):Shape(_x,_y){ x=_x;y=_y;radius = _r; radius2 = radius*radius; }
 
  string getName() {return "Circle";} 
  string getJavascript() 
  { return "figuras.push(new Circle("+to_string(x)+","+to_string(y)+","+to_string(radius)+"));";}  
  inline const bool isInsideShape (const double& p_x,const double& p_y)
  {
	 double squared_dist = (p_x - x)*(p_x - x)+(p_y - y)*(p_y - y); 
	 return squared_dist <= radius2;
  }  
  double ReferenceArea() {  return (M_PI * radius2); }   
};


/** 
 @brief Calculates the area by checking if <NoSimulations> random points are inside the shape or not.
        This will give a percentage of points that are inside the shape, so the area calculated 
        will be that percentage * ReferenceArea
 @param NoSimulations Number of Monte Carlo tests, each one is a random Point between (0,0) and (Max_X,Max_Y)
 @param rect Shape object to be measured.
 @return double. Area calculated via Monte Carlo method.
*/
double MonteCarlo_CalcArea(const int& NoSimulations,vector<Shape*>& shapes, const UnionType& uniontype)
{
    if (shapes.size() == 0 || NoSimulations <= 0) return 0.0; //Sanitize inputs
    std::random_device rd;  //Seeding
    std::mt19937 seed(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> gen_randx(0, Max_X); //Random X generator
    std::uniform_real_distribution<> gen_randy(0, Max_Y); //Random Y generator
    
	int areaCount = 0;
	for (int i=0;i < NoSimulations;++i)
	{
	    double rand_x = gen_randx(seed);
	    double rand_y = gen_randy(seed);
	    bool isInside = shapes[0]->isInsideShape( rand_x, rand_y );
	    int n; //for loops inside switch
	    //If we have more than 1 shape, check Union Type for operations between shapes
	    if (shapes.size() > 1)
	      switch (uniontype)
	      {
	       case UnionType::UNION:         //Adding shapes
	       	   for (n=1; n < shapes.size();++n)
	             isInside = isInside || shapes[n]->isInsideShape( rand_x, rand_y );
	       break;
	       case UnionType::INTERSECTION: //Intersection of all shapes
	           for (n=1; n < shapes.size();++n)
	            isInside &= shapes[n]->isInsideShape( rand_x, rand_y );
	       break;	        
	       case UnionType::SUBTRACTION: //Any other shape can't be inside
	           for (n=1; n < shapes.size();++n)
	            isInside &= !shapes[n]->isInsideShape( rand_x, rand_y );
	       break;
	       default: 
	        cerr << "Unexpected Union Type"<<endl;
	        abort();
	     }
		if (isInside) ++areaCount; //Add 1 to the area count
	}
	double PercentageFilled = ((double)areaCount/(double)NoSimulations); //Percent coverage on all MC Tests
	return Reference_Area*PercentageFilled; //Then the area will be a % of the Reference Area
}

void SendToJavascript(vector<Shape*>& shapes, const UnionType& uniontype){
 ofstream loadshapes;
 loadshapes.open("/project/target/loadshapes.js");
 loadshapes << "Max_X = "<<Max_X<<";"<<endl;
 loadshapes << "Max_Y = "<<Max_Y<<";"<<endl;
 loadshapes << "UnionType = "<<(int)uniontype<<"; //UNION=0 , INTERSECTION=1, SUBTRACTION=2"<<endl;
 for (auto& shape:shapes)
  loadshapes << shape->getJavascript() <<endl;
 loadshapes.close();
 cout << "CG> open --static-dir /project/target /visor.html"<<endl;
}

int main()
{
  UnionType unionOperation = UnionType::UNION;
  bool isDisjoint = true; //true; Set only to true when you are sure shapes are disjoint, and using the UNION type
  //Creating different shapes. All them must be inside limits [0..Max_X] and [0..Max_Y]    
  vector<Shape*> shapes;
  shapes.push_back(new Circle(60,60,50));
  shapes.push_back(new Circle(115,60,50));
  shapes.push_back(new Rectangle(120,120,70,35));
  shapes.push_back(new Rectangle(1,1,20,35));
  shapes.push_back(new Rectangle(10,150,120,25));
  
  //Send data to Javascript, for visualization
  SendToJavascript(shapes, unionOperation);
  
  int Simcount = 10;
  cout << "Calculating the area:"<<endl;
  for (int i=0;i < 7;++i){
	  double MC_Area = MonteCarlo_CalcArea( Simcount,shapes,unionOperation);
      cout << "Simulations:"<< std::setw(10)<< Simcount<<fixed<<std::setprecision(4)<<" : Monte Carlo Area:"<<MC_Area;
      if ( isDisjoint && unionOperation == UnionType::UNION) //In other cases and operations it just outputs invalid values
       {
	    double Ref_Area = 0.0;
	    for (auto& shape:shapes)
	      {  Ref_Area += shape->ReferenceArea();  } //That's only true on disjoint UNIONS!!!!
	    double Accuracy = 100.0-100.0*abs(Ref_Area-MC_Area)/Ref_Area;
        cout<<" Reference Area:"<<Ref_Area<<" Accuracy:"<<Accuracy<<"%";
       }
       cout<<endl;
	Simcount *=10;
  }
  cout <<"Tests finished"<<endl;
  return 0;
}
