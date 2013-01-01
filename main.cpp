#include <cstdlib>
#include <iostream>
#include "puzzlesolver.h"
#define TOTAL_TIMES 10000
using namespace std;

int play()
{
    PuzzleSolver solver;
    Puzzle puzzle;
    
    while(!puzzle.isSolved())
    {
	//solver.show_matrix();
	//solver.show_possibility();
	Guess myguess=solver.next_guess();
        Result thisanswer = puzzle.guess(myguess);
        solver.answer_is(thisanswer);
        //cout<<"Guess: "; myguess.print();
        //cout<<"Answer: "; thisanswer.print();
    }
    return solver.report();
}
void statistic(int times)
{
    int guesses=0;
    int count=0;
    int remain;
    for(remain=times;remain>0;remain--)
    {
      guesses+=play();
      count++;
      cout<<"\r"<<count<<" games, "<<(double)guesses/count<<" guesses each game in average.";
    }
    cout<<endl;
}
void solve_for_human()
{
     PuzzleSolver solver;
     Result theResult;
     do{
            solver.next_guess().print();
            cout<<"A:";
            cin>>theResult.A;
            cout<<"B:";
            cin>>theResult.B;
            solver.answer_is(theResult);
     }while(theResult.A!=SLOTS);
}
int main(int argc, char *argv[])
{
    statistic(TOTAL_TIMES);
    //solve_for_human();
    return EXIT_SUCCESS;
}
