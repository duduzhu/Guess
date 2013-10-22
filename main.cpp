#include <cstdlib>
#include <iostream>
#include "mypuzzlesolver.h"
#define TOTAL_TIMES 1000
using namespace std;

int play()
{
    MyPuzzleSolver * pSolver = new MyPuzzleSolver;
    Puzzle puzzle;
    
    while(!puzzle.isSolved())
    {
	//pSolver->show_matrix();
	//pSolver->show_possibility();
	Guess myguess=pSolver->next_guess();
        Result thisanswer = puzzle.guess(myguess);
        pSolver->answer_is(thisanswer);
        //cout<<"Guess: "; myguess.print();
        //cout<<"Answer: "; thisanswer.print();
    }
    int result =  pSolver->report();
    delete pSolver;
    return result;
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
     MyPuzzleSolver * pSolver = new MyPuzzleSolver;
     Result theResult;
     do{
            pSolver->next_guess().print();
            cout<<"A:";
            cin>>theResult.A;
            cout<<"B:";
            cin>>theResult.B;
            pSolver->answer_is(theResult);
     }while(theResult.A!=SLOTS);
    delete pSolver;
}
int main(int argc, char *argv[])
{
    statistic(TOTAL_TIMES);
    //solve_for_human();
    return EXIT_SUCCESS;
}
