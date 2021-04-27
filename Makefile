all:
	g++ -o maze main.cpp Stack.h Maze.h Point.h 

clean:
	rm maze