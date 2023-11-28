#pragma once
#include <vector>
#include <iostream>

// ������������ ����� ��� ����, ����� � ������ ������ �� ����� �������, 
// � ����� ������� � ��� ������, � � ����� ���
enum CellState
{
    Close,
    Open
};

// ��������� ������
// x, y - ���������� � ���������.
// Left, Right, Top, Bottom - ������� ������ � ������.
// visited - �������� �� �� ������.
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

// cells -  ��������� ������ �����
// maz_for_output - ��������� ������, ������� ��������, ��� ����,
// ����� �������� �������� �� �������
// width - ������ ��������� � ������
// height - ������ ��������� � �����
// cell - ����� ���������� � ������ ���������
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