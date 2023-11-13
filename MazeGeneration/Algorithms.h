#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Maze.h"

using Algorithm = void(*)(Maze& maze);

// ������� ����� ��-22-05
// �������� ��������� ������������ - RECURSIVE BACKTRACKER
void RecursiveBacktracker(Maze& maze);
