#include "Algorithms.h"
using namespace std;
void BinaryTree(Maze& maze) {
	srand(time(NULL));
	bool dir;
	for (y = 0;y < maze.height;y++) {
		for (x = 0;x < maze.width;x++) {
			dir = rand() % 2;
			if (dir and y != 0) {
				maze.cell(x, y).Top = open;
				maze.cell(x, y - 1).Bottom = open;
			}
			else if (x != maze.width + 1) {
				maze.cell(x, y).Rigth = open;
				maze.cell(x + 1, y).Left = open;
			};
		};
	};
}