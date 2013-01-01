#ifndef _PUZZLE_SOLVER_
#define _PUZZLE_SOLVER_

#include <set>
#include "puzzle.h"

class PuzzleSolver
{
public:
  Guess & next_guess();
  void answer_is(Result a_result);
  int report();
  PuzzleSolver();
  ~PuzzleSolver();
  void show_matrix();  
  void show_possibility();  
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
