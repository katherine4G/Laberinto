#include "Matrix.h"

Matrix::Matrix()
{
}
bool Matrix::iterative_path_exists(int startX, int startY, int endX, int endY)
{
    bool visited[N][N] = { false };
    int stackX[N * N];  // Tamaño máximo posible de la pila
    int stackY[N * N];
    int top = -1;

    // Empujar el punto inicial
    top++;
    stackX[top] = startX;
    stackY[top] = startY;

    while (top >= 0) {
        int x = stackX[top];
        int y = stackY[top];
        top--;  // Desapilar

        if (x == endX && y == endY) {
            return true;
        }

        if (!visited[x][y]) {
            visited[x][y] = true;

            // Recorremos las posibles direcciones.
            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if (is_valid_move(nx, ny, visited)) {
                    top++;
                    stackX[top] = nx;
                    stackY[top] = ny;
                }
            }
        }
    }

    return false;
}

bool Matrix::recursive_path_exists(int startX, int startY, int endX, int endY)
{
    bool visited[N][N] = { false };
    return recursive_path_exists(startX, startY, endX, endY, visited);
}

int Matrix::get_value(int row, int col) const
{
    if (row >= 0 && row < N && col >= 0 && col < N)
    {
        return maze[row][col];
    }
    return -1; // Valor de error si está fuera de rango
}

bool Matrix::recursive_path_exists(int startX, int startY, int endX, int endY, bool visited[N][N])
{
    if (startX == endX && startY == endY) {
        return true;
    }

    visited[startX][startY] = true;

    for (int i = 0; i < 4; i++) {
        int nx = startX + directions[i][0];
        int ny = startY + directions[i][1];
        if (is_valid_move(nx, ny, visited)) {
            if (recursive_path_exists(nx, ny, endX, endY, visited)) {
                return true;
            }
        }
    }

    return false;
}

void Matrix::print_result(bool result)
{
    if (result) {
        std::cout << "¡Se encontró un camino!" << std::endl;
    }
    else {
        std::cout << "No se encontró un camino." << std::endl;
    }
}

bool Matrix::is_valid_move(int row, int col, bool visited[N][N])
{
    return row >= 0 && row < N && col >= 0 && col < N && matrix[row][col] == 1 && !visited[row][col];
}
//
//bool Matrix::iterative_path_exists(int startX, int startY, int endX, int endY)
//{
//    bool visited[7][7] = { false };
//    int stackX[49];  // 7x7 = 49 es el tamaño máximo posible del camino
//    int stackY[49];
//    int top = -1;
//
//    // Empujar el punto inicial
//    top++;
//    stackX[top] = startX;
//    stackY[top] = startY;
//
//    while (top >= 0) {
//        int x = stackX[top];
//        int y = stackY[top];
//        top--;  // Pop
//
//        if (x == endX && y == endY) {
//            return true;
//        }
//
//        if (!visited[x][y]) {
//            visited[x][y] = true;
//
//            // Recorremos las posibles direcciones.
//            for (int i = 0; i < 4; i++) {
//                int nx = x + directions[i][0];
//                int ny = y + directions[i][1];
//                if (is_valid_move(nx, ny, visited)) {
//                    top++;
//                    stackX[top] = nx;
//                    stackY[top] = ny;
//                }
//            }
//        }
//    }
//
//    return false;
//}
//
//bool Matrix::recursive_path_exists(int startX, int startY, int endX, int endY, bool visited[7][7])
//{
//    static bool visitedInternal[7][7] = { false };
//    if (visited == nullptr) {
//        visited = visitedInternal;
//    }
//
//    if (startX == endX && startY == endY) {
//        return true;
//    }
//
//    visited[startX][startY] = true;
//
//    for (int i = 0; i < 4; i++) {
//        int nx = startX + directions[i][0];
//        int ny = startY + directions[i][1];
//        if (is_valid_move(nx, ny, visited)) {
//            if (recursive_path_exists(nx, ny, endX, endY, visited)) {
//                return true;
//            }
//        }
//    }
//
//    return false;
//}
//
//void Matrix::print_result(bool result)
//{
//
//    if (result) {
//        std::cout << "Existe un camino." << std::endl;
//    }
//    else {
//        std::cout << "No existe un camino." << std::endl;
//    }
//}
//
//bool Matrix::is_valid_move(int row, int col, bool visited[7][7])
//{
//    return row >= 0 && row < 7 && col >= 0 && col < 7 && matrix[row][col] == 1 && !visited[row][col];
//}
