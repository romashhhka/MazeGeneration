#pragma once
#include <vector>
#include <iostream>

// ѕеречисление нужно дл€ того, чтобы о каждой €чейки мы могли сказать, 
// с какой стороны у нее стенка, а с какой нет
enum CellState
{
    Close,
    Open
};

// —труктура €чейка
// x, y - координаты в лабиринте.
// Left, Right, Top, Bottom - наличие стенки у €чейки.
// visited - посетили ли мы €чейку.
struct Cell
{
    int x;
    int y;
    int set;
    bool visited;
    CellState Left;
    CellState Right;
    CellState Top;
    CellState Bottom;
    Cell();
};

// cells -  двумерный массив €чеек
// maz_for_output - двумерный массив, который создаЄтс€, дл€ того,
// чтобы выводить лабиринт на консоль
// width - размер лабиринта в ширину
// height - размер лабиринта в длину
// cell - можем обратитьс€ к €чейке лабиринта
class Maze
{
public:
    int width;
    int height;

    void Output();
    void CreateMasForOutput();
    void Clear();

    Cell& cell(int X, int Y);

    Maze(int Width, int Height);

private:
    std::vector<std::vector<Cell>> cells;
    std::vector<std::vector<char>> mas_for_output;
    int height_for_output;
    int width_for_output;
};