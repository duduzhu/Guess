#include <iostream>
#include <cstdlib>
#include <ctime>
#include "puzzle.h"
/*****
BasicArray means a basic guess, like 1 2 3 4
*****/
bool Guess::isMAX()
{
    for(int i=0;i<SLOTS;i++)
    {
        if(_array[i]!=RANGE-1)
            return 0;
    }
    return 1;
}
bool Guess::isValid()
{
    for(int i=0;i<SLOTS;i++)
    {
        if(i<0 && i>=RANGE)
            return 0;
        for(int j=i+1;j<SLOTS;j++)
            {
                if(_array[i]==_array[j])
                    {
                        return 0;
                    }
            }
    }
     return 1;
}
void Guess::next()
{
    int i=0;
    bool next;
    do
    {
        _array[i]++;
        next=0;
        if(_array[i] == RANGE)
        {
            _array[i] = 0;
            next = 1;
        }
        i++;
    }while(next);
}
void Guess::nextValid()
{
    next();
    while(!isValid() && !isMAX())
    {
        next();
    }
}
Guess::Guess()
{
  reset();
}
Guess::Guess(Guess & src)
{
  for(int i=0;i<SLOTS;i++)
  {
    _array[i]=src[i];
  }
}
void Guess::reset()
{
      for(int i=0;i<SLOTS;i++)
      {  _array[i]=0;}
      nextValid();
}
int & Guess::operator[](int index)
{
    return _array[index];
}
void Guess::print()
{
      for(int i=0;i<SLOTS;i++)
        std::cout<<_array[i]<<" ";
      std::cout<<std::endl;
}
Result  Guess::get_result(Guess &guess)
{
       int A=0,B=0;
       for(int i=0;i<SLOTS;i++)
       {
           if(guess[i] == _array[i])
           {
             A++;
           }
           else
           {
               for(int j=0;j<SLOTS;j++)
               {
                 if(j == i) continue;
                 else
                 {
                     if(guess[i] == _array[j])
                     {
                       B++;
                       break;
                     }
                 }
               }
           }
       }
       return Result(A,B);
}



/*****
Result means the return of the puzzle, like 1A2B
*****/
Result::Result()
{
    A=0;B=0;
}
Result::Result(int & _A, int & _B)
{
  A=_A;
  B=_B;
}
bool Result::operator==(Result & another)
{
     return A==another.A && B==another.B;
}
void Result::print()
{
     std::cout<<A<<"A"<<B<<"B"<<std::endl;
}
bool Result::isValid()
{
    return A!=-1 && B!=-1;
}



/*****
*****/
Puzzle::Puzzle()
{
    //srand (time(NULL) );
    do{
        for(int i=0;i <SLOTS ;i++)
        {
          _answer[i]=rand() % RANGE;
        }
    }while(!_answer.isValid());
    _isSolved=0;
}
bool  Puzzle::isSolved()
{
      return _isSolved;
}

Result  Puzzle::guess(Guess & guess)
{
       if(!guess.isValid())
       {
          std::cerr<<"Guess not Valid!";
          Result tmp;
          tmp.A=-1;tmp.B=-1;
          return tmp;
       }
       Result result=_answer.get_result(guess);
       if(result.A==SLOTS && result.B==0)
       {
         _isSolved = 1;
       }
       return result;
}
