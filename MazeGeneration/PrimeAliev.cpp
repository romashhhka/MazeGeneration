#include "Algorithms.h"

void Prime(Maze& maze) {
	srand(time(NULL));
	int start_x = rand() % maze.width;
	int start_y = rand() % maze.height;
	maze.cell(start_x, start_y).visited = true;

}