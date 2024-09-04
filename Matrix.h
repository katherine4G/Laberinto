#pragma once
#include <iostream>
using namespace std;

#define N 7

class Matrix
{

private:


    int matrix[N][N] = {
        {1,1,0,0,0,0,1},
        {0,1,0,0,0,1,0},
        {1,1,1,1,1,1,0},
        {1,0,1,0,1,0,0},
        {1,0,1,0,1,0,0},
        {1,0,1,0,1,1,0},
        {1,0,1,0,0,0,1}
    };

    const int directions[4][2] = {
        {-1,  0},  // Arriba
        { 1,  0},  // Abajo
        { 0, -1},  // Izquierda
        { 0,  1}   // Derecha
    };
public:
    Matrix();
    bool iterative_path_exists(int startX, int startY, int endX, int endY);
    bool recursive_path_exists(int startX, int startY, int endX, int endY);
    int get_value(int row, int col) const;

    void print_result(bool result);


private:
    bool is_valid_move(int row, int col, bool visited[N][N]);
    bool recursive_path_exists(int startX, int startY, int endX, int endY, bool visited[N][N]);
    int maze[N][N];

};

