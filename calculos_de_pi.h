#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

const long double pi = 3.141592653589793;

/*
 * A função para aproximar o número de pi utilizando do cálculo de Leibniz
 * pode ser implementada com um for loop, que coloca o resultado anterior
 * num vetor, depois utiliza como condição quantos termos quer ser utilizado,
 * depois é somado 2 ao divisor um conjunto if/else que verifica se i,
 * o número do termo atual é par ou ímpar, para alternar entre
 * somar ou subtrair 1/divisor multiplicado por 4 pelo último resultado.
 * Então, coloca o resultado atual no vetor e feita uma média entre
 * o menor e maior mais próximos de pi encontrados até agora.
 */
long double leibniz(int n_termos) {
   long double resultado = 4.0, divisor = 1.0, media;
    vector<long double> vals_proximos;
    for(int i = 1; i <= n_termos; i++) {
        divisor += 2.0;
        vals_proximos.push_back(resultado);

        i % 2 != 0 ? (resultado -= (1.0 / divisor) * 4.0)
        : (resultado += (1.0 / divisor) * 4.0);

        vals_proximos.push_back(resultado);

        media = (vals_proximos[0] + vals_proximos[1]) / 2;
        vals_proximos.clear();
    }
    return media;
}

/*
 * O cálculo de pi pela série infinita de Wellis é feita em pares,
 * e cada par pode ser formado pela fórmula: (2n/2n-1) * (2n/2n+1).
 * Logo, podemos fazer um for loop que incrementa o valor de n à cada
 * interação e multiplicar o par pelo resultado do par anterior,
 * obtendo a cada termo o valor aproximado de pi/2.
 */
double wallis(int n_termos) {
    double resultado = 1.0, n = 1.0;

    for(int i = 1; i <= n_termos; i++) {
        resultado *= (n*2 / (n*2 - 1)) * (n*2 / (n*2 + 1));
        n++;
    }
    return resultado;
}

/*
 * O cálculo de pi pela série infinita de Euler pode ser implementada
 * por um for loop até que sejam calculados o tanto de termos passado,
 * e a cada termo é feito pela divisão de 1 pelo quadrado de n, que aumenta
 * em 1 a cada execução do loop. O resultado é próximo de pi²/6.
 */
long double euler(int n_termos) {
    long double resultado = 1.0, n = 2.0;

    for(int i = 1; i <= n_termos; i++) {
        resultado += (1 / pow(n,2));
        n++;
    }
    return resultado;
}

/*
 * O cálculo de pi pela série infinita de Viète pode ser implementada
 * calculando a raiz quadrada de 2 dividida por 2, e então como é preciso
 * somar outra raiz quadrada de 2 a cada termo, é guardado o cálculo da raiz
 * anterior e somado com a próxima raiz, obtendo assim a aproximação de 2/pi.
 */
long double viete(int n_termos) {
    long double resultado = 1.0, raiz = sqrt(2);

    for(int i = 1; i <= n_termos; i++) {
        resultado *= raiz/2;
        raiz = sqrt(2+raiz);
    }
    return resultado;
}
