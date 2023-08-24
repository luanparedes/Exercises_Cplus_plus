#include<iostream>

void create_matrix(char**& matrix, int *rows, int *columns);
void show_matrix(char**& matrix, int *rows, int *columns);
void draw_char(char**& matrix, char letter, int row, int column);


int main(){

    int menuOption;
    bool isQuit;
    int rows = 20;
    int columns = 40;

    char** asciiArt;

    create_matrix(asciiArt, &rows, &columns);

    do{
        std::cout << "1 - Draw\n2 - Resize\n3 - View\n4 - Quit" << std::endl;
        std::cout << "\nType your option: ";
        std::cin >> menuOption;

        switch (menuOption){
            case 1:
                char typedChar;
                int typedRow;
                int typedColumn;

                std::cout << "Type character: ";
                std::cin >> typedChar;

                std::cout << "Row: ";
                std::cin >> typedRow;

                std::cout << "Column: ";
                std::cin >> typedColumn;

                draw_char(asciiArt, typedChar, typedRow, typedColumn);
                system("clear||cls");

                break;
            case 2:
                break;
            case 3:
                show_matrix(asciiArt, &rows, &columns);
                break;
            case 4:
                isQuit = true;
                break;
        }
    } while (!isQuit);

    return 0;
}

void create_matrix(char**& matrix, int* rows, int* columns){
    matrix = new char*[*rows];

    for(int i = 0; i < *rows; ++i){
        matrix[i] = new char[*columns];
    }

    for(int i = 0; i < *rows; ++i){
        for(int j = 0; j < *columns; ++j){
            matrix[i][j] = '.';
        }
    }
}

void show_matrix(char**& matrix, int* rows, int* columns){
    for(int i = 0; i < *rows; ++i){
        for(int j = 0; j < *columns; ++j){
            if(matrix[i][j] != ' ')
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void draw_char(char**& matrix, char letter, int row, int column){
    matrix[row - 1][column - 1] = letter;
}