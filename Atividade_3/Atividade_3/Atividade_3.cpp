#include <iostream>
#include "FileResource.h"

using namespace std;

int main()
{
    FileResource<string> *file = new FileResource<string>("C:/Users/luans/OneDrive/Documentos/Luan_email.txt");

    //auto teste = file->MoveTo();

    //cout << teste;
}