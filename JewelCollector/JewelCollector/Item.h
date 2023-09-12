#pragma once
#include <string>

class Item {
public:
    Item(std::string tipo, int valor);

    std::string getTipo() const;
    int getValor() const;
    void setValor(int novoValor);

private:
    std::string tipo;
    int valor;
};

