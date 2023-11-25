#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <tuple>
#include "Maze.h"

using Algorithm = void(*)(Maze& maze);

// Èëüè÷åâ Ğîìàí ÀÑ-22-05
// ÀËÃÎĞÈÌÒ ÎÁĞÀÒÍÎÃÎ ÎÒÑËÅÆÈÂÀÍÈß - RECURSIVE BACKTRACKER
void RecursiveBacktracker(Maze& maze);
void WilsonAlgorithm(Maze& maze);