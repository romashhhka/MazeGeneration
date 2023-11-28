#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <random>
#include <algorithm>
#include "Maze.h"

using Algorithm = void(*)(Maze& maze);

// Ильичев Роман АС-22-05
// АЛГОРИМТ ОБРАТНОГО ОТСЛЕЖИВАНИЯ - RECURSIVE BACKTRACKER
void RecursiveBacktracker(Maze& maze);


// Мазепа Александр АС-22-05

void Eller(Maze& maze);
