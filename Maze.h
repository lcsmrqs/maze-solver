#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <ios>
#include <vector>

#include "Point.h"

using std::vector;

class Maze
{
public:
  Maze();
  Maze(const std::string filename);
  ~Maze();

  int& at(Point p);
  int& at(int x, int y);
  vector<Point> validNeighbours(Point p);
  void readFromFile(const std::string filename);
  void print();

  int *maze;
  int rows, cols;
};

Maze::Maze() : maze(nullptr), rows(0), cols(0) {}

Maze::Maze(const std::string filename) : maze(nullptr), rows(0), cols(0) {
  readFromFile(filename);
}

Maze::~Maze() {
  if(maze)
    delete [] maze;  
}

int& Maze::at(Point p) {
  return maze[p.x * cols + p.y];
}

int& Maze::at(int x, int y) {
  return maze[x * cols + y];
}

vector<Point> Maze::validNeighbours(Point p) {
  vector<Point> n;

  if(this->at(p.x - 1, p.y) == 1)
    n.push_back(Point(p.x -1, p.y));

  if(this->at(p.x + 1, p.y) == 1)
    n.push_back(Point(p.x + 1, p.y));

  if(this->at(p.x, p.y - 1) == 1)
    n.push_back(Point(p.x, p.y - 1));

  if(this->at(p.x, p.y + 1) == 1)
    n.push_back(Point(p.x, p.y + 1));
  
  return n;
}

void Maze::readFromFile(const std::string filename) {
  std::ifstream file(filename);

  file >> rows >> cols;
  file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  maze = new int[rows * cols];

  int i=0, j=0;
  char c;
    
  while(file.get(c)) {
      if(c == '\n') {
          j = 0;
          i++;
          continue;
      } else if(c == '#')
        maze[i * cols + j++] = 0;
      else if(c == ' ')
        maze[i * cols + j++] = 1;
  }

  file.close();
}

void Maze::print() {
  int i, j;
    for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++) {
        switch(maze[i * cols + j]) {
        case 0:
          // std::cout << "#";
          std::cout << "\033[31m#";
          break;
        case 1:
          std::cout << " ";
          break;
        case 2:
          std::cout << "\033[1;34m." << "\033[24;m";
          break;
        default:
          // std::cout << " ";
          // std::cout << "~";
          std::cout << "\033[33m~";
        }
      }

      std::cout << "\033[0m" << std::endl;
    }
}

#endif
