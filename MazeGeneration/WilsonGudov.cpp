#include "Algorithms.h"

//������� ��� ��������, �������� �� ������
bool isCellVisited(Maze& maze, int x, int y)
{
    return  maze.cell(x, y).visited;
}

//����� ����������� ����������
int Min(std::vector<Cell>& path,char par)
{
    int ans = 100000;
    if (par=='x')
    {
        if (path[path.size()-1].x < ans)
            ans = path[path.size()-1].x;
        if (path[path.size()-2].x < ans)
            ans = path[path.size()-2].x;
        if (path[path.size()-3].x < ans)
            ans = path[path.size()-3].x;
        if (path[path.size()-4].x < ans)
            ans = path[path.size()-4].x;
    }
    else if(par == 'y')
    {
        if (path[path.size()-1].y < ans)
            ans = path[path.size()-1].y;
        if (path[path.size() - 2].y < ans)
            ans = path[path.size()-2].y;
        if (path[path.size() - 3].y < ans)
            ans = path[path.size()-3].y;
        if (path[path.size() - 4].y < ans)
            ans = path[path.size()-4].y;
    }
    return ans;
}

//����� ������������ ����������
int Max(std::vector<Cell>& path, char par)
{
    int ans = -1;
    if (par == 'x')
    {
        if (path[path.size()-1].x > ans)
            ans = path[path.size()-1].x;
        if (path[path.size() - 2].x > ans)
            ans = path[path.size()-2].x;
        if (path[path.size() - 3].x > ans)
            ans = path[path.size()-3].x;
        if (path[path.size() - 4].x > ans)
            ans = path[path.size()-4].x;
    }
    else if (par == 'y')
    {
        if (path[path.size()-1].y > ans)
            ans = path[path.size()-1].y;
        if (path[path.size() - 2].y > ans)
            ans = path[path.size()-2].y;
        if (path[path.size() - 3].y > ans)
            ans = path[path.size()-3].y;
        if (path[path.size() - 4].y > ans)
            ans = path[path.size()-4].y;
    }
    return ans;
}

void BuildPath(std::vector<Cell>& path, Maze& maze)// ��������� ���� � ��������
{
    int x = 0, y = 0, nx = 0, ny = 0;
    for (int i = 0; i < path.size()-2; i++)
    {
        x = path[i].x;
        y = path[i].y;
        nx = path[i+1].x;
        ny = path[i+1].y;
        if (path[i + 1].x - path[i].x == 1 && path[i + 1].y - path[i].y == 0)//�����
        {
            maze.cell(x, y).Top = Open;
            maze.cell(nx, ny).Bottom = Open;
        }
        if (path[i + 1].x - path[i].x == -1 && path[i + 1].y - path[i].y == 0)//����
        {
            maze.cell(x, y).Bottom = Open;
            maze.cell(nx, ny).Top = Open;
        }
        if (path[i + 1].x - path[i].x == 0 && path[i + 1].y - path[i].y == 1)//������
        {
            maze.cell(x, y).Right = Open;
            maze.cell(nx, ny).Left = Open;
        }
        if (path[i + 1].x - path[i].x == 0 && path[i + 1].y - path[i].y == -1)//�����
        {
            maze.cell(x, y).Left = Open;
            maze.cell(nx, ny).Right = Open;
        }
    }


}

bool NotLightCercle(std::vector<Cell>& path)//�������� ��������� �� ����������
{
    int size = path.size();
    if (size < 4)
        return 1;
    else
        //������ ������� ����� ������� �������� ����� 4 ��������� ������ � 
        //������� ����� ����������� � ������������ ���������� ����� ��������� 4 ������ 
        //��������� ���� �� x � y � ���� ��������������� �������� ��������� �� ����� 
        //����������� �� ���������� ���� �� 4 ������
        if ((Min(path, 'x') + Max(path, 'x') / 2 == (path[path.size()-1].x + path[path.size() - 2].x + path[path.size() - 3].x + path[path.size() - 4].x) / 4) && (Min(path, 'y') + Max(path, 'y') / 2 == (path[path.size()-1].y + path[path.size() - 2].y + path[path.size() - 3].y + path[path.size() - 4].y) / 4))
        {
            return 0;
        }
        else
            return 1;
}

bool ThereAreUnvisitedCells(Maze& maze)
{
    bool isit=1;
    for (int i = 0; i < maze.width; i++)
    {
        for (int j = 0; j < maze.height; j++)
        {
            if (!maze.cell(i, j).visited)
                return 1;
            else
                return 0;
        }
    }
}

//������� ��� ������ ��������� ������������ ������
std::pair<int, int> chooseRandomUnvisitedCell(Maze& maze)
{
    int x, y;
    do
    {
        x = rand() % maze.width;
        y = rand() % maze.height;
    } while (isCellVisited(maze, x, y));

    return { x, y };
}

//������� ��� ������ ���������� �����������
int chooseRandomDirection()
{
    return rand() % 4;
}

//������� ��� ����������� � ������������ ����������� � �������� ��� �� �� ������� �� ������� ���������
void moveInDirection(int& x, int& y, int direction, Maze& maze)
{
    switch (direction)
    {
    case 0:
        if (x>0)
            x -= 1;//�����
        else
            moveInDirection(x, y, chooseRandomDirection(), maze);
        break;
    case 1:
        if (x<maze.width-1)
            x += 1;//������
        else
            moveInDirection(x, y, chooseRandomDirection(), maze);
        break;
    case 2:
        if (y>0)
            y -= 1;//����
        else
            moveInDirection(x, y, chooseRandomDirection(), maze);
        break;
    case 3:
        if (y<maze.height-1)
            y += 1;//�����
        else
            moveInDirection(x, y, chooseRandomDirection(), maze);
        break;
    }
}

void WilsonAlgorithm(Maze& maze)//����� �������� �� �� ��� ������ �������� ��� ���������� �������� � ������ ����
{
        // �������� ��������� ��������� ������
        int startX, startY;
        std::tie(startX, startY) = chooseRandomUnvisitedCell(maze);
        maze.cell(startX, startY).visited = true;

        // �������� ��������� ��������� ������ c ������� �������� ���������� ������� ��������� �����
        int currentX, currentY;
        std::tie(currentX, currentY) = chooseRandomUnvisitedCell(maze);

        int nextX;
        int nextY;

        std::vector<Cell> path;//���� ��������� ������
        path.push_back(maze.cell(currentX, currentY));
        bool alreadyIs;
        int count = 0;
        int last_size;

        while (ThereAreUnvisitedCells(maze))//������� ���� �� ����� ������� ��� ���� � ���������
        {
            last_size = path.size();
            nextX = currentX;//����� �������� �� ����� 
            nextY = currentY;
            alreadyIs = 0;
            moveInDirection(nextX, nextY, chooseRandomDirection(), maze);
            for (int i = 0; i < path.size(); i++)//��������� ��� �� �� ���� �� ��� ����������� � ���� ������� ����� �� ��������� �����
            {
                if (path[i].x == nextX && path[i].y == nextY)
                    alreadyIs = 1;
            }
           
            if (NotLightCercle(path)) //�������� �� ���� �����
            {
                if (!alreadyIs)
                {
                    path.push_back(maze.cell(nextX, nextY));
                    currentX = nextX;
                    currentY = nextY;
                }
                if (maze.cell(nextX, nextY).visited)
                    BuildPath(path, maze);
            }            

            if (last_size==path.size())
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count == 15)
            {
                for (int i = 1; i < path.size()-1; i++)
                {
                    path.pop_back();
                }
            }
        }
}