#include "puzzlesolver.h"

#include <iostream>

void PuzzleSolver::show_possibility()
{
    for(std::set<Guess *>::iterator it=_guessSet.begin();it!=_guessSet.end();++it)
	(*it)->print();	
}
void PuzzleSolver::show_matrix()
{
     std::cout<<_guessSet.size()<<" possibilities remain."<<std::endl;
     for(int i=0;i<SLOTS;i++)
     {
	std::cout<<i<<std::endl;
        for(int j=0;j<RANGE;j++)
        {
          std::cout<<j<<"=>"<<_times[i][j]<<" ";
        }
	std::cout<<std::endl;
     }
}
void PuzzleSolver::init()
{
     _last=NULL;
     _guess_times = 0;
     _guessSet.clear();
     Guess tempGuess;
     tempGuess.reset();
     for(int i=0;i<SLOTS;i++)
	for(int j=0;j<RANGE;j++)
	{
	  _times[i][j]=0;
	}
     while(!tempGuess.isMAX())
     {
        Guess * pNewGuess = new Guess(tempGuess);
        //Make sure to call remove_possibility to delete;
        add_possibility(pNewGuess);
        tempGuess.nextValid();
     }
}

void PuzzleSolver::add_possibility(Guess * pGuess) //Done
{
     if(!pGuess->isValid())
       return;
        
     for(int i=0;i<SLOTS;i++)
     {
       _times[i][(*pGuess)[i]] += 1;
     }
     _guessSet.insert(pGuess);
}
void PuzzleSolver::remove_possibility(Guess * pGuess) //Done
{
     if(!pGuess->isValid())
       return;
        
     for(int i=0;i<SLOTS;i++)
     {
       _times[i][(*pGuess)[i]] -= 1;
     }
     delete pGuess;
     _guessSet.erase(pGuess);
}
PuzzleSolver::~PuzzleSolver()
{
    for(std::set<Guess *>::iterator it=_guessSet.begin();it!=_guessSet.end();++it)
    {
        delete *it;
    }
    _guessSet.clear();
}
PuzzleSolver::PuzzleSolver() //Done
{
  this->~PuzzleSolver();
  init();
}

Guess & PuzzleSolver::next_guess()
{
    _guess_times++;
    _last=*_guessSet.begin();
    unsigned long long total_times=1;
    for(std::set<Guess *>::iterator it=_guessSet.begin();it!=_guessSet.end();++it)
    {
	unsigned long long times_of_current=1;
	for(int i=0;i<SLOTS;i++)
	{
	  times_of_current *= _times[i][(**it)[i]];
	}
	// find the most possible guess
	if(times_of_current > total_times)
	{
	  total_times = times_of_current;
	  _last = *it;
	}
    }
    return *_last;
}

void PuzzleSolver::answer_is(Result a_result) //Done
{
    std::set<Guess *> toBeRemoved;
    for(std::set<Guess *>::iterator it=_guessSet.begin();it!=_guessSet.end();++it)
    {
        if(!((*it)->get_result(*_last)==a_result))
        {
            toBeRemoved.insert(*it);
        }
    }
    
    for(std::set<Guess *>::iterator it=toBeRemoved.begin();it!=toBeRemoved.end();++it)
    {
        remove_possibility(*it);
    }
    
    toBeRemoved.clear();
}

int PuzzleSolver::report()
{
    return _guess_times;
}
