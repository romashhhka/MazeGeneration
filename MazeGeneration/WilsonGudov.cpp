#include "Algorithms.h"

//������� ��� ��������, �������� �� ������
bool isCellVisited(const std::vector<std::vector<bool>>& visited, int x, int y)
{
    return visited[y][x];
}

//������� ��� ������ ��������� ������������ ������
std::pair<int, int> chooseRandomUnvisitedCell(const Maze& maze, const std::vector<std::vector<bool>>& visited)
{
    int x, y;
    do
    {
        x = rand() % maze.width;
        y = rand() % maze.height;
    } while (isCellVisited(visited, x, y));

    return { x, y };
}

//������� ��� ������ ���������� �����������
int chooseRandomDirection()
{
    return rand() % 4;
}

//������� ��� ����������� � ������������ �����������
void moveInDirection(int& x, int& y, int direction)
{
    switch (direction)
    {
    case 0:
        x--;
        break;
    case 1:
        x++;
        break;
    case 2:
        y--;
        break;
    case 3:
        y++;
        break;
    }
}

void WilsonAlgorithm(Maze& maze)
{
    // ��������� ������ visited ��� ������������ ���������� ����� �.�. ����� ������ �� �������� �� .visited
    std::vector<std::vector<bool>> visited(maze.height, std::vector<bool>(maze.width, false));

    // �������������
    for (int i = 0; i < maze.height; ++i)
    {
        for (int j = 0; j < maze.width; ++j)
        {
            visited[i][j] = false;
        }
    }

    while (true)
    {
        // �������� ��������� ��������� ������
        int startX, startY;
        std::tie(startX, startY) = chooseRandomUnvisitedCell(maze, visited);

        visited[startY][startX] = true;

        int currentX = startX;
        int currentY = startY;

        while (true)
        {
            int direction = chooseRandomDirection();
            int nextX = currentX;
            int nextY = currentY;

            moveInDirection(nextX, nextY, direction);

            if (nextX >= 0 && nextX < maze.width && nextY >= 0 && nextY < maze.height && !isCellVisited(visited, nextX, nextY))
            {
                // ��������� ������
                maze.cell(currentX, currentY).visited = true;
                switch (direction)
                {
                case 0:
                    maze.cell(currentX, currentY).Right = Open;
                    maze.cell(nextX, nextY).Left = Open;
                    break;
                case 1:
                    maze.cell(currentX, currentY).Left = Open;
                    maze.cell(nextX, nextY).Right = Open;
                    break;
                case 2:
                    maze.cell(currentX, currentY).Bottom = Open;
                    maze.cell(nextX, nextY).Top = Open;
                    break;
                case 3:
                    maze.cell(currentX, currentY).Top = Open;
                    maze.cell(nextX, nextY).Bottom = Open;
                    break;
                }

                currentX = nextX;
                currentY = nextY;
            }
            else
            {
                // ���� �� ����� ��������� � ��������� �����������, ��������� ������� ����
                break;
            }
        }

        // ���������, ��� �� ������ ��������
        bool allVisited = true;
        for (int i = 0; i < maze.height; ++i)
        {
            for (int j = 0; j < maze.width; ++j)
            {
                if (!visited[i][j])
                {
                    allVisited = false;
                    break;
                }
            }
            if (!allVisited)
                std::cout << 2 << std::endl;
                break;
        }

        //
    }
}