#ifndef _PUZZLE_
#define _PUZZLE_

#define SLOTS   4
#define RANGE   10

class Result{
public:
  int A;
  int B;
  Result();
  Result(int & _A, int & _B);
  bool operator==(Result &);
  bool isValid();
  void print();
};

class Guess
{
      int _array[SLOTS];
      void next();
public:
      void nextValid();	
      void reset();
      bool isValid();
      bool isMAX();
      int & operator[](int index);
      Guess(Guess &);
      Guess();
      void print();
      Result  get_result(Guess & guess);
};



class Puzzle{
private:
  Guess            _answer;
  bool             _isSolved;
public:
  Puzzle();
  bool              isSolved();
  Result            guess(Guess & guess);
  void              print_answer();
};


#endif
