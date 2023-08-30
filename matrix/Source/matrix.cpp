/*
Anderson Barreto Furlan
Luan Lucas de Simas Paredes
*/
#include<iostream>

void create_matrix(char**& matrix, int *rows, int *columns);
void show_matrix(char**& matrix, int *rows, int *columns);
void draw_char(char**& matrix, char letter, int row, int column, int *rows, int *columns);
void resize_matrix(char**& matrix, int *rows, int *columns, int *newRows, int *newColumns);
void show_msg(std::string msg);

const std::string MENU_OPTION_ERROR_MSG = "Invalid option! Please choose a valid option!";
const std::string INPUT_ERROR_MSG = "Invalid option! Please choose a valid option!";

int main(){

    int menuOption;
    bool isQuit;
    int rows = 20;
    int columns = 40;
    int newRows = rows;
    int newColumns = columns;

    char** asciiArt;

    create_matrix(asciiArt, &rows, &columns);

    do{
        std::cout << "1 - Draw\n2 - Resize\n3 - View\n4 - Quit" << std::endl;
        std::cout << "\nType your option: ";
        std::cin >> menuOption;

        if(std::cin.fail()){
            show_msg(MENU_OPTION_ERROR_MSG);
            return 0;
        }

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
                if(std::cin.fail()){
                    show_msg(INPUT_ERROR_MSG);
                    break;
                }
                draw_char(asciiArt, typedChar, typedRow, typedColumn, &rows, &columns);

                break;
            case 2:
                std::cout << "New numbers of rows: ";
                std::cin >> newRows;

                std::cout << "New numbers of Columns: ";
                std::cin >> newColumns;
                if(std::cin.fail()){
                    show_msg(INPUT_ERROR_MSG);
                    break;
                }
                resize_matrix(asciiArt, &rows, &columns, &newRows, &newColumns);
                break;
            case 3:
                show_matrix(asciiArt, &rows, &columns);
                break;
            case 4:
                isQuit = true;
                break;
            default:
                std::cout << MENU_OPTION_ERROR_MSG << std::endl;
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

void resize_matrix(char**& matrix, int* rows, int* columns, int* newRows, int* newColumns){
    char** temp_matrix = new char*[*newRows];

    for(int i = 0; i < *newRows; ++i){
        temp_matrix[i] = new char[*newColumns];
    }

    for(int i = 0; i < *newRows; ++i){
       
        for(int j = 0; j < *newColumns; ++j){
    
            if(i < *newRows && j < *newColumns 
               && i < *rows && j < *columns){
                temp_matrix[i][j] = matrix[i][j];
            } else {
                temp_matrix[i][j] = '.';
            }
        }
    }

    *rows = *newRows;
    *columns = *newColumns;

    delete[] matrix;
    matrix = temp_matrix;
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

void draw_char(char**& matrix, char letter, int typedRow, int typedCol, int* rows, int *cols){
    
    if(typedRow <= *rows && typedCol <= *cols){
        matrix[typedRow - 1][typedCol - 1] = letter;
    }
    else {
        show_msg(INPUT_ERROR_MSG);
    }
    system("cls");
}

void show_msg(std::string msg){
    std::cout << msg << std::endl;
    system("pause");
}

