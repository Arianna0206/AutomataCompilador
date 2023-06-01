#include <iostream>  
// Incluye la biblioteca iostream, que proporciona funciones de entrada y salida básicas.

#include <fstream>
// Incluye la biblioteca fstream, que proporciona funciones para trabajar con archivos.

#include <cctype>
// Incluye la biblioteca cctype, que proporciona funciones para trabajar con caracteres.

#include <iomanip>
// Incluye la biblioteca iomanip, que proporciona funciones para formatear la salida.

using namespace std;
// Usa el espacio de nombres std, lo cual evita tener que escribir "std::" antes de las funciones de la biblioteca estándar.

// Define una función llamada isSeparador0case0 que verifica si un carácter es un separador en el caso 0.
bool isSeparador0case0(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"' || c == ',' || c == '.' ;
}
// Define una función llamada isSeparador1case1 que verifica si un carácter es un separador en el caso 1.
bool isSeparador1case1(char c) {
        return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"' || c == ',' || c == '.' ;
}
// Define una función llamada isSeparador2case2 que verifica si un carácter es un separador en el caso 2.
bool isSeparador2case2(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"' || c == ',';
}
// Define una función llamada isSeparador3case4 que verifica si un carácter es un separador en el caso 4.
bool isSeparador3case4(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"';
}
// Define una función llamada isSeparador4case5 que verifica si un carácter es un separador en el caso 5.
bool isSeparador4case5(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '<' || c == '>' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"' || c == ',' || c == '.' || c == '*'|| c == '/';
}
// Define una función llamada isSeparador5case6 que verifica si un carácter es un separador en el caso 6.
bool isSeparador5case6(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"' || isalpha(c);
}
// Define una función llamada isSeparador6case7 que verifica si un carácter es un separador en el caso 7.
bool isSeparador6case7(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == '"' || c == '.';
}
// Define una función llamada isSeparador7case8 que verifica si un carácter es un separador en el caso 8.
bool isSeparador7case8(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '.' || c == ',' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"';
}
// Define una función llamada isSeparador8case9 que verifica si un carácter es un separador en el caso 9.
bool isSeparador8case9(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"';
}
// Define una función llamada isSeparador9case10 que verifica si un carácter es un separador en el caso 10.
bool isSeparador9case10(char c) {
    return c == ' ' || c == '=' || c == ')' || c == '/' || c == '*' || c == '<' || c == '>' || c == '+' || c == '-' || c == '!' || c == '}' || c == '\n' || c == '\t' || c == '{' || c == '(' || c == ';' || c == '"' || c == '.' || c == ',';
}
// Define un arreglo de palabras reservadas en el lenguaje.
bool isKeyword(const std::string& currentToken) {
    std::string reservadas[] = {
        "inicio",
        "if",
        "else",
        "while",
        "int",
        "double",
        "string",
        "imprimir"
    };
    // Verifica si el token actual coincide con alguna palabra reservada.
    for (size_t i = 0; i < sizeof(reservadas) / sizeof(reservadas[0]); ++i) {
        if (currentToken == reservadas[i]) {
            return true;
        }
    }
    // Retorna falso si el token no es una palabra reservada.
    return false;
}
// Define una función llamada isNumero que verifica si un carácter es un dígito numérico.
bool isNumero(char c) {
    return isdigit(c);
}
// Define una función llamada isIdentificador que verifica si un carácter es un identificador alfabético.
bool isIdentificador(char c) {
    return isalpha(c);
}

int main() {
    // Abre el archivo "archivo.txt" ubicado en la ruta especificada para lectura.
    ifstream archivo("/Users/macbook/Desktop/automataCompilador/archivo.txt");
    // Declara variables para almacenar el carácter actual, el estado actual del autómata, la posición y el token actual.
    char c;
    int e = 0;
    int i = 1;
    string currentToken;
    // Verifica si no se pudo abrir el archivo y muestra un mensaje de error.
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    // Lee cada carácter del archivo.
    while (archivo.get(c)) {
        // Inicia una serie de casos para diferentes estados del autómata.
        switch (e) {
            /* El caso case 0 maneja los caracteres que no se ajustan a ninguna de las 
            categorías anteriores y realiza diferentes acciones dependiendo del tipo de carácter encontrado. */
            case 0:
                if (isalpha(c)) {
                    e = 1;
                    currentToken = c;
                } else if (isdigit(c)) {
                    e = 2;
                    currentToken = c;
                } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                    e = 5;
                    currentToken = c;
                } else if (c == '(' || c == ')' || c == '{' || c == '}') {
                    e = 6;
                    currentToken = c;
                } else if (c == ';' || c == ',') {
                    e = 7;
                    currentToken = c;
                } else if (c == '>' || c == '<') {
                    e = 8;
                    currentToken = c;
                } else if (c == '=') {
                    e = 9;
                    currentToken = c;
                } else if (isSeparador0case0(c)) {
                    e = 0;
                } else {
                    cout << "Error: caracter inesperado " << c << " en la posición " << i << endl;
                    return 1;
                }
                break;
            /* El caso case 1 se encarga de construir identificadores o palabras clave concatenando 
            caracteres hasta encontrar un separador o un espacio en blanco. Cuando se encuentra un 
            separador o espacio en blanco, se verifica si el token construido es una palabra clave 
            o un identificador y se imprimen los mensajes correspondientes. Luego, se reinicia currentToken 
            y se cambia al estado 0 para esperar el próximo token.*/
            case 1:
                if (isalpha(c) || isdigit(c)) {
                    currentToken += c;
                } else if (isSeparador1case1(c) || c == ' ') {
                    if (isKeyword(currentToken)) {
                        cout << "Palabra clave 1:  " << currentToken << " en la posición " << i << endl;
                    } else {
                        cout << "Identificador 1:  " << currentToken << " en la posición " << i << endl;
                    }
                    currentToken.clear();
                    cout << "Separador 1 " << " en la posición " << i << endl;
                    e = 0;
                } else {
                    cout << "Error 1 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 2 se encarga de construir números enteros concatenando dígitos hasta 
            encontrar un separador específico. Cuando se encuentra el separador, se imprime el número 
            entero construido, se reinicia currentToken y se cambia al estado 0 para esperar el próximo 
            token. Si se encuentra un punto, se cambia al estado 3 para construir un número decimal. Si 
            se encuentra un carácter inesperado, se muestra un mensaje de error y se devuelve 1.*/
            case 2:
                if (isdigit(c)) {
                    currentToken += c;
                } else if (isSeparador2case2(c)) {
                    cout << "Número 2: " << currentToken << " en la posición " << i << endl;
                    currentToken.clear();
                    cout << "Separador 2" << c << " en la posición " << i << endl;
                    e = 0;
                } else if (c == '.') {
                    e = 3;
                    currentToken += c;
                    cout << "Caracter de puntuación 2: " << c << " en la posición " << i << endl;
                } else {
                    cout << "Error 2 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 3 se encarga de construir números decimales concatenando dígitos después de encontrar 
            un punto. Si se encuentran dígitos, se cambia al estado 4 y se agrega el dígito al currentToken. Además, 
            se imprime un mensaje indicando que se encontró un número decimal en la posición actual. Si se encuentra
            un carácter inesperado, se muestra un mensaje de error y se devuelve 1.*/
            case 3:
                if (isdigit(c)) {
                    e = 4;
                    currentToken += c;
                    cout << "Número 3: " << currentToken << " en la posición " << i << endl;
                } else {
                    cout << "Error 3 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 4 se encarga de completar la construcción de un número decimal agregando dígitos 
            después de la parte decimal. Si se encuentran dígitos, se agregan a currentToken. Si se encuentra 
            un separador válido, se imprime el número decimal construido hasta el momento, se limpia currentToken 
            y se imprime el separador encontrado. Si se encuentra un carácter inesperado, se muestra un mensaje 
            de error y se devuelve 1.*/
            case 4:
                if (isdigit(c)) {
                    currentToken += c;
                } else if (isSeparador3case4(c)) {
                    cout << "Número 4: " << currentToken << " en la posición " << i-1 << endl;
                    currentToken.clear();
                    cout << "Separador 4: " << c << " en la posición " << i << endl;
                    e = 0;
                } else {
                    cout << "Error 4 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 5 se encarga de reconocer y manejar operadores aritméticos. Si se encuentra un separador 
            válido (por ejemplo, +, -, *, /), se imprime un mensaje indicando que se encontró un operador aritmético 
            en la posición actual y se limpia currentToken. Luego, se cambia al estado 0 para reiniciar el análisis 
            en busca de nuevos tokens. Si se encuentra un carácter inesperado, se muestra un mensaje de error y se devuelve 1.*/
            case 5:
                if (isSeparador4case5(c)) {
                    cout << "Operador aritmético 5: " << currentToken << " en la posición " << i << endl;
                    currentToken.clear();
                    e = 0;
                } else {
                    cout << "Error 5 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 6 se encarga de reconocer y manejar delimitadores. Si se encuentra un delimitador válido
            (por ejemplo, (, ), {, }), se imprime un mensaje indicando que se encontró un delimitador en la posición 
            actual y se limpia currentToken. Luego, se cambia al estado 0 para reiniciar el análisis en busca de nuevos 
            tokens. Si se encuentra un carácter inesperado, se muestra un mensaje de error y se devuelve 1.*/
            case 6:
                if (isSeparador5case6(c)) {
                    cout << "Delimitador 6: " << currentToken << " en la posición " << i << endl;
                    currentToken.clear();
                    e = 0;
                } else {
                    cout << "Error 6 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 7 se encarga de reconocer y manejar caracteres de puntuación, como punto y coma (;) y coma (,). 
            Si se encuentra un caracter de puntuación válido, se imprime un mensaje indicando que se encontró un caracter 
            de puntuación en la posición actual y se limpia currentToken. Luego, se cambia al estado 0 para reiniciar el 
            análisis en busca de nuevos tokens. Si se encuentra un carácter inesperado, se muestra un mensaje de error y 
            se devuelve 1.*/
            case 7:
                if (isSeparador6case7(c)) {
                    cout << "Caracter de puntuación 7: " << currentToken << " en la posición " << i << endl;
                    currentToken.clear();
                    e = 0;
                } else {
                    cout << "Error 7 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 8 se encarga de reconocer y manejar operadores relacionales, como menor que (<) y mayor que (>). 
            Si se encuentra un operador relacional válido, se imprime un mensaje indicando que se encontró un operador relacional 
            en la posición actual y se limpia currentToken. Luego, se cambia al estado 0 para reiniciar el análisis en busca de 
            nuevos tokens. Si se encuentra un carácter inesperado, se muestra un mensaje de error y se devuelve 1.*/
            case 8:
                if (isSeparador7case8(c)) {
                    cout << "Operador relacional 8: " << currentToken << " en la posición " << i << endl;
                    currentToken.clear();
                    e = 0;
                } else {
                    cout << "Error 8 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                    return 1;
                }
                break;
            /* El caso case 9 se encarga de reconocer y manejar el operador de igualdad (==). Si se encuentra un signo de 
            igual (=), se cambia al estado 10 y se imprime un mensaje indicando que se encontró un operador relacional en 
            la posición actual. Si se encuentra un separador válido, se imprime un mensaje indicando que se encontró un 
            separador en la posición actual y se cambia al estado 0. Si se encuentra un carácter inesperado, se muestra un 
            mensaje de error y se devuelve 1.*/
            case 9:
                if (c == '=') {
                    e = 10;
                    cout << "Operador relacional 9: " << currentToken << " en la posición " << i << endl;
                } else if (isSeparador8case9(c)) {
                    currentToken.clear();
                    cout << "Separador 9: " << c << " en la posición " << i << endl;
                    e = 0;
                } else {
                    cout << "Error 9 in character " << c << " at position " << i << ": unexpected character." << endl;
                    return 1;
                }
                break;
        /* El caso case 10 se encarga de reconocer y manejar la finalización del operador relacional de igualdad (==). 
        Si se encuentra un separador válido, se imprime un mensaje indicando que se encontró un separador en la posición actual 
        y se cambia al estado 0. Si se encuentra un carácter inesperado, se muestra un mensaje de error y se devuelve 1.*/
        case 10:
            if (isSeparador9case10(c)) {
                currentToken.clear();
                cout << "Separador - 10: " << c << " en la posición " << i << endl;
                e = 0;
            } else {
                cout << "Error 10 en el carácter " << c << " en la posición " << i << ": caracter inesperado." << endl;
                return 1;
            }
            break;
        }
        /* Incrementa el valor de la variable i en 1. La variable i se utiliza como contador en un bucle, 
        por lo que este incremento significa que el bucle avanzará a la siguiente iteración, procesando 
        el siguiente carácter del archivo de entrada.*/
        i++;
    }
    /* Cierra el archivo que se abrió previamente con la función open()*/
    archivo.close();
    /* Esta línea indica que la función main() ha finalizado correctamente y devuelve un valor de salida igual a 0. */
    return 0;
}
