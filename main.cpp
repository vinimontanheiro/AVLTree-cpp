#include <iostream>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

#include "Utility.h"

Utility util;

#include "AVLTree.h"
#include "App.h"

int main() {
    App app;
    int choice;

    cout << "\n------------------------" << endl;
    cout << "      Árvore AVL";
    cout << "\n------------------------" << endl;
    cout<<"Escolher: "<< endl;;
    cout << "\t\t1.Buscar por CPF" << endl;
    cout << "\t\t2.Buscar por NOME" << endl;
    cout << "\t\t3.Buscar por DATA" << endl;
    cout << ":";
    cin>>choice;

    //Dando inicio à aplicação
    app.init(choice);
    return 0;
}



