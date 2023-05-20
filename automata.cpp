#include <iostream>
#include <fstream>
#include <cctype>


using namespace std;

bool ifSeparador1(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n'|| c == '=' || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == ';' || c == '"';
}

bool ifSeparador2(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n'|| c == '=' || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == ';' || c == '"';
}

bool ifSeparador3(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n'|| c == '=' || c == '(' || c == ')' || c == '+' || c == ';' || c == '(' || c == '"';
}

bool ifSeparador4(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n'|| c == ';' || c == ':' || c == '"'|| c == '(' || c == ')';
}

bool ifSeparador5(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n' || c == ';'|| c == '(' || c == ')' || c == '"';
}

bool ifSeparador6(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n' || c == '=' || c == ';'|| c == '(' || c == ')' || c == '"';
}

bool ifSeparador7(char c) {
    // Define aquí la función ifSeparador1() que verifica si el carácter c es un separador válido.
    // Por ejemplo:
    return c == ' ' || c == '\t' || c == '\n' || c == '<' || c == '>' || c == ';'|| c == '(' || c == ')' || c == '"' || c == ':';
}


int main() {
    ifstream archivo("/Users/macbook/Desktop/automataCompilador/archivo.txt");
    char c;
    int e = 0;
    int i = 1; 

    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    while (archivo.get(c)) {
        switch (e) {
            case 0:
                if (isalpha(c)) {
                    e = 1;
                } else if (isdigit(c)) {
                    e = 2;
                } else if (c == '+' || c == '-' || c == '*' || c == '/'){
                    e = 5;
                } else if (c == '(' || c == ')' || c == '{' || c == '}') {
                    e = 6;
                } else if (c == ';' || c == '.' || c == ',') {
                    e = 7;
                } else if (c == '>' || c == '<') {
                    e = 8;
                } else if (c == '=') {
                    e = 9;
                } else {
                    cout << "Error: caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 1:
                if (isalpha(c) || isdigit(c)) {
                    e = 1;
                    cout << "Token OK. 1" << endl;
                } else if (ifSeparador1(c)) {
                    e = 0;
                    cout << "Token OK. 1" << endl;
                } else {
                    cout << "Error 1 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 2:
                if (isdigit(c)) {
                    e = 2;
                    cout << "Token OK. 2" << endl;
                }else if (ifSeparador2(c)){
                    e = 0;
                    cout << "Token OK. 2" << endl;
                }else if (c == '.') {
                    e = 3;
                    cout << "Token OK. 2" << endl;
                } else {
                    cout << "Error 2 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 3: 
                if (isdigit(c)) {
                    e = 4;
                    cout << "Token OK. 3" << endl;
                } else {
                    cout << "Error 3 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 4:
                if (ifSeparador3(c)) {
                    e = 0;
                    cout << "Token OK. 4" << endl;
                } else {
                    cout << "Error 4 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 5:
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    e = 6;
                    cout << "Token OK. 5" << endl;
                } else if (ifSeparador3(c)) {
                    e = 0;
                    cout << "Token OK. 5" << endl;
                } else {
                    cout << "Error 5 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 6:
                if (c == '(' || c == ')' || c == '{' || c == '}') {
                    e = 7;
                    cout << "Token OK. 6" << endl;
                } else if (ifSeparador4(c)) {
                    e = 0;
                    cout << "Token OK. 6" << endl;
                } else {
                    cout << "Error 6 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 7:
                if (c == ';' || c == '.' || c == ',') {
                    e = 8;
                    cout << "Token OK. 7" << endl;
                } else if (ifSeparador5(c)) {
                    e = 0;
                    cout << "Token OK. 7" << endl;
                } else {
                    cout << "Error 7 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
             case 8:
                if (c == '>' || c == '<') {
                    e = 9;
                    cout << "Token OK. 8" << endl;
                } else if (ifSeparador6(c)) {
                    e = 0;
                    cout << "Token OK. 8" << endl;
                } else {
                    cout << "Error 8 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 9:
                if (c == '=') {
                    e = 10;
                    cout << "Token OK. 9" << endl;
                 } else if (ifSeparador7(c)) {
                    e = 0;
                    cout << "Token OK. 9" << endl;
                } else {
                    cout << "Error 9 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            case 10:
                if (c == '=') {
                    e = 0;
                    cout << "Token OK. 10" << endl;
                } else if (ifSeparador7(c)) {
                    e = 0;
                    cout << "Token OK. 10" << endl;
                } else {
                    cout << "Error 10 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;

        }
         i++;
    }

    archivo.close();

    return 0;
}
