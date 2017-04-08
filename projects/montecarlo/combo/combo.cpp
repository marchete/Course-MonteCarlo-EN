#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //To enable optimizations in Codingame
#include <bits/stdc++.h> //All main STD libraries
using namespace std;

//{Timer struct
#define TIMEOUT 95000 //95 ms timeout
#define Now() chrono::high_resolution_clock::now()
static struct Stopwatch {
	chrono::high_resolution_clock::time_point c_time,c_timeout;
	void setTimeout(int us){c_timeout=c_time+chrono::microseconds(us);}
	void Start() {c_time=Now(); setTimeout(TIMEOUT);}	
	inline bool Timeout(){return Now()>c_timeout;}
	long long EllapsedMicroseconds(){return chrono::duration_cast<chrono::microseconds>(Now()-c_time).count();}
	long long EllapsedMilliseconds(){return chrono::duration_cast<chrono::milliseconds>(Now()-c_time).count();}
} stopwatch;//} Stopwatch

const int MOVE_SIZE = 9;

/** 
 @brief Evaluate the Score of a given move
 @param move Array of letters
 @return int Resulting Score of that move
*/    
int eval(const string& move){
//Base Score 
 int BaseScore = 0;
 const string vowels = "aeiou";
 if (vowels.find(move[0]) != std::string::npos) BaseScore+=6;
 for (int i=0; i < MOVE_SIZE; ++i)
 {
  if ((uint8_t)(move[i])<=(uint8_t)('c')) BaseScore+=1;
   else if ((uint8_t)(move[i])<=(uint8_t)('o')) BaseScore+=2;
    else BaseScore +=3;
 }
 const string ending = "pqrwz";
 if (ending.find(move[MOVE_SIZE-1]) != std::string::npos) BaseScore+=3;
//Multipliers
 int Multiplier = 1; 
 for (int i=1; i < MOVE_SIZE; ++i)
 {
   if (move[i-1] == 'm' && move[i] == 'a') Multiplier *= 2;
   if (move[i-1] == 'o' && move[i] == 'r') Multiplier *= 2;
   if (move[i-1] == 'e' && move[i] == 'd') Multiplier *= 2;
 }
 for (int i=2; i < MOVE_SIZE; ++i)
 {
   if (move[i-2] == 'n' && move[i-1] == 'o' && move[i] == 'm') Multiplier *= 3;
   if (move[i-2] == 'l' && move[i-1] == 'o' && move[i] == 'l') Multiplier *= 3;
   if (move[i-2] == 'o' && move[i-1] == 'm' && move[i] == 'g') Multiplier *= 3;
   if (move[i-2] == 'a' && move[i-1] == 'f' && move[i] == 'k') Multiplier *= 3;
 }
//SuperCombo
 string super = "codingame";
 bool SuperCombo = (super.compare(move) ==0);
 return BaseScore * Multiplier + (SuperCombo?500:0);
}

int main()
{
  srand (time(NULL)); //Initialize random numbers      
  const char* a_to_z = "abcdefghijklmnoqrstuvwxyz";
  for (int attempt = 0; attempt < 10; ++attempt)
  {
   int bestScore = -999999;
   string bestMove = "";
   stopwatch.Start(); 				   //Init timer
   int iterations = 0;
   while (!stopwatch.Timeout())
   {
    string tmpMove;
	for (int j=0;j < MOVE_SIZE;++j)
	  tmpMove += (char)((uint8_t)('a')+rand() % 26);//a_to_z[rand() % 26];//Generate random move
	//if (attempt == 9 && iterations == 1)  tmpMove = "codingame"; //Forcing codingame to appear
	int tmpScore = eval(tmpMove);      //Evaluate move
	if (tmpScore > bestScore)          //Keep best
	{
	 bestScore = tmpScore;
	 bestMove = tmpMove;
	}
	++iterations;
   }
   cout <<"Attempt:"<<attempt<< " Monte Carlo ended. Best Move was:'"<<bestMove;
   cout<<"'. Best Score:"<<bestScore<<" N° of tests:"<<iterations<<endl;
  }
  return 0;
}