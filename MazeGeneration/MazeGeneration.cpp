#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "Algorithms.h"
#include "Maze.h"

using namespace std;

int GetCorrectNumber(int min, int max)
{
    int x;
    while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please, enter correct number: ";
    }
    return x;
}

void Run(Algorithm a, Maze& maze, string author)
{
    auto start = chrono::system_clock::now();
    a(maze);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    maze.CreateMasForOutput();
    maze.Output();
    maze.Clear();
    cout << "Время генерации алгоритма: " << time << " mcs.\n";
    cout << "Программу написал: " << author << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    /*cout << "Введите ширину лабиринту: ";
    int width = GetCorrectNumber(5, 50);
    cout << "Введите высоту лабиринту: ";
    int height = GetCorrectNumber(5, 50);*/
    int width = 15;
    int height = 15;

    Maze maze(width, height);
    Run(RecursiveBacktracker, maze, "Ильичев Роман АС-22-05");

    //RecursiveBacktracker(maze);
}

