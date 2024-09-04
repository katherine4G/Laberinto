#pragma once

#include "Matrix.h"
#include "Matrix.h"

class Menu
{
private:
    char exitKey;
    Matrix matrix;
public:
    Menu();
    ~Menu();
    void print_welcome_message();
    void print_matrix_layout();
    void get_user_input(int& startX, int& startY, int& endX, int& endY);
    void print_result_message(bool result, const std::string& method);
    void run_menu();
};

