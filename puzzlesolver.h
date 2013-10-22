#ifndef _PUZZLE_SOLVER_
#define _PUZZLE_SOLVER_

#include <set>
#include "puzzle.h"

class PuzzleSolver
{
public:
  virtual Guess & next_guess()=0;
  virtual void answer_is(Result a_result)=0;
  virtual int report()=0;
  virtual void show_matrix()=0;  
  virtual void show_possibility()=0;  
};
#endif
