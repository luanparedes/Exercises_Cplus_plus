#include "Item.h"

Item::Item(std::string tipo, int valor) : tipo(tipo), valor(valor) {}

std::string Item::getTipo() const {
    return tipo;
}

int Item::getValor() const {
    return valor;
}

void Item::setValor(int novoValor) {
    valor = novoValor;
}