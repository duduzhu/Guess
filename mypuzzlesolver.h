#ifndef _MY_PUZZLE_SOLVER_
#define _MY_PUZZLE_SOLVER_

#include "puzzlesolver.h"

class MyPuzzleSolver : public PuzzleSolver
{
public:
  virtual Guess & next_guess();
  virtual void answer_is(Result a_result);
  virtual int report();
  MyPuzzleSolver();
  ~MyPuzzleSolver();
  virtual void show_matrix();  
  virtual void show_possibility();  
private:
  void init();
  void add_possibility(Guess *);
  void remove_possibility(Guess *);
  int _times[SLOTS][RANGE];
  std::set<Guess *> _guessSet;
  Guess * _last;
  int _guess_times;
};

#endif
