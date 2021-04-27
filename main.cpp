#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
#include "Maze.h"
#include "Point.h"

using std::cout;
using std::endl;

bool solveMaze(Maze& m) {
  Stack<Point> s;
  Point currPos = Point(1, 1), dest(m.rows - 2, m.cols - 2);

  s.push(currPos);
  m.at(currPos) = 2;

  while(currPos != dest && !s.empty()) {
    vector<Point> validNeightbours;
    currPos = s.top();
    s.pop();

    validNeightbours = m.validNeighbours(currPos);
    
    if(validNeightbours.size() > 0) {
      s.push(currPos);
      currPos = validNeightbours[rand() % validNeightbours.size()];
      m.at(currPos) = 2;
      s.push(currPos);
    } else {
      m.at(currPos) = -1;
    }
  }
  
  if(s.empty())
    return false;
  
  return true;
}

int main(int argc, char *argv[]) {
  Maze m;
  
  if(argc > 1)
    m.readFromFile(argv[1]);
  else
    m.readFromFile("maze1.txt");

  srand (time(NULL));

  system("clear");

  cout << "Labirinto: " << endl;
  m.print();

  if(solveMaze(m)) {
    cout << endl << "Solucao: " << endl;
    m.print();
  } else {
    cout << endl << "Nao tem solucao!" << endl;
  }

  return 0;
}
