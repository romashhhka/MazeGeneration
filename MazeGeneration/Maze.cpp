#include "Maze.h"

using namespace std;

Cell::Cell()
{
    Left = Close;
    Right = Close;
    Top = Close;
    Bottom = Close;
}

void Maze::Output()
{

    //system("cls");
    for (int row = 0; row < (height_for_output); ++row)
    {
        for (int col = 0; col < (width_for_output); ++col)
            cout << mas_for_output[row][col];
        cout << endl;
    }
}

void Maze::CreateMasForOutput()
{
    vector<char> mas_row(width_for_output);

    for (int row = 0; row < (height_for_output); ++row)
    {
        for (int col = 0; col < (width_for_output); ++col)
            mas_row[col] = '#';
        mas_for_output[row] = mas_row;
    }

    for (auto& cells_row : cells)
    {
        for (auto& cell : cells_row)
        {
            if (cell.Right == Open) {
                mas_for_output[1 + cell.y * 2][1 + cell.x * 2] = ' ';
                mas_for_output[1 + cell.y * 2][2 + cell.x * 2] = ' ';
            }
            else
                mas_for_output[1 + cell.y * 2][1 + cell.x * 2] = ' ';

            if (cell.Bottom == Open)
                mas_for_output[2 + cell.y * 2][1 + cell.x * 2] = ' ';
        }
    }
}

void Maze::Clear()
{
    for (int row = 0; row < (height_for_output); ++row)
    {
        for (int col = 0; col < (width_for_output); ++col)
            mas_for_output[row][col] = '#';
    }

    for (auto& cells_row : cells)
    {
        for (auto& cell : cells_row)
        {
            cell.Bottom = Close;
            cell.Top = Close;
            cell.Left = Close;
            cell.Right = Close;
            cell.visited = false;
        }
    }

}

Cell& Maze::cell(int x, int y)
{
    return cells[y][x];
}

Maze::Maze(int Width, int Height)
{
    width = Width;
    height = Height;
    height_for_output = Height * 2 + 1;
    width_for_output = Width * 2 + 1;
    mas_for_output.resize(height_for_output);
    cells.resize(height);

    vector<Cell> maze_row(width);
    Cell cell;
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            cell.y = row;
            cell.x = column;
            cell.visited = false;
            maze_row[column] = cell;
        }
        cells[row] = maze_row;
    }
}

