#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <tuple>
#include <cmath>
#include <random>
#include <algorithm>
#include "Maze.h"

using Algorithm = void(*)(Maze& maze);

// Èëüè÷åâ Ðîìàí ÀÑ-22-05
// ÀËÃÎÐÈÌÒ ÎÁÐÀÒÍÎÃÎ ÎÒÑËÅÆÈÂÀÍÈß - RECURSIVE BACKTRACKER
void RecursiveBacktracker(Maze& maze);
void WilsonAlgorithm(Maze& maze);
// ������ ��������� ��-22-05
void Eller(Maze& maze);
// ���� ������� ��-22-05
// �������� ������-������� - ALDOUS-BRODER
void AldousBroder(Maze& maze);
void Prime(Maze& maze);
//áåðåçêà
void BinaryTree(Maze& maze);
// Ñàêëàêîâà Âàëåðèÿ ÀÑ-22-05
// ÀËÃÎÐÈÒÌ SIDEWINDER
void Sidewinder(Maze& maze);