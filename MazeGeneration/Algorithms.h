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

// Герш Алексей АС-22-05
// АЛГОРИМТ ОЛДОСА-БРОДЕРА - ALDOUS-BRODER
void AldousBroder(Maze& maze);