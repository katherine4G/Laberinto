#include "Menu.h"

Menu::Menu()
{
	exitKey = 'a';
}

Menu::~Menu()
{
}
void Menu::print_welcome_message()
{
    std::cout << "=======================================" << std::endl;
    std::cout << "         Bienvenido al Laberinto       " << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "Este programa encuentra un camino entre dos\npuntosen un laberinto de un matrix 7x7." << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
}
void Menu::print_matrix_layout()
{
    std::cout << "\t Laberinto:" << std::endl;
    std::cout << "     Y: 0 1 2 3 4 5 6\n X" << std::endl;
    std::cout << " 0\t1 1 0 0 0 0 1" << std::endl;
    std::cout << " 1\t0 1 0 0 0 1 0" << std::endl;
    std::cout << " 2\t1 1 1 1 1 1 0" << std::endl;
    std::cout << " 3\t1 0 1 0 1 0 0" << std::endl;
    std::cout << " 4\t1 0 1 0 1 0 0" << std::endl;
    std::cout << " 5\t1 0 1 0 1 1 0" << std::endl;
    std::cout << " 6\t1 0 1 0 0 0 1\n" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
}

void Menu::get_user_input(int& startX, int& startY, int& endX, int& endY)
{
    do {
        std::cout << "Ingrese las coordenadas de inicio (x ,y)\n";
        std::cout << "x = "; std::cin >> startX;
        std::cout << "y = "; std::cin >> startY;
    } while (startX < 0 || startX >= 7 || startY < 0 || startY >= 7 || matrix.get_value(startX, startY) == 0);

    do {
        std::cout << "Ingrese las coordenadas de destino (x ,y)\n";
        std::cout << "x = "; std::cin >> endX;
        std::cout << "y = "; std::cin >> endY;
    } while (endX < 0 || endX >= 7 || endY < 0 || endY >= 7 || matrix.get_value(endX, endY) == 0);

    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
}

void Menu::print_result_message(bool result, const std::string& method)
{
    std::cout << method << ": ";
    if (result) {
        std::cout << "Se encontró un camino." << std::endl;
    }
    else {
        std::cout << "No se encontró un camino." << std::endl;
    }
    std::cout << std::endl;
}

void Menu::run_menu()
{
    setlocale(LC_CTYPE, "Spanish");

    do {
        print_welcome_message();
        print_matrix_layout();

        int startX, startY, endX, endY;
        get_user_input(startX, startY, endX, endY);

        bool iterativeResult = matrix.iterative_path_exists(startX, startY, endX, endY);
        print_result_message(iterativeResult, "Método Iterativo");

        bool recursiveResult = matrix.recursive_path_exists(startX, startY, endX, endY);
        print_result_message(recursiveResult, "Método Recursivo");

        std::cout << "¿Desea ingresar otro par de coordenadas?\n(Presione 'x' para salir o cualquier otra tecla para continuar): ";
        std::cin >> exitKey;
        std::cout << std::endl;

    } while (exitKey != 'x' && exitKey != 'X');

    std::cout << "Hasta luego!" << std::endl;
    std::cout << "=======================================" << std::endl;
}