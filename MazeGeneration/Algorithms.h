#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Maze.h"

using Algorithm = void(*)(Maze& maze);

// Ильичев Роман АС-22-05
// АЛГОРИМТ ОБРАТНОГО ОТСЛЕЖИВАНИЯ - RECURSIVE BACKTRACKER
void RecursiveBacktracker(Maze& maze);

// Саклакова Валерия АС-22-05
// АЛГОРИТМ SIDEWINDER
void Sidewinder(Maze& maze);
