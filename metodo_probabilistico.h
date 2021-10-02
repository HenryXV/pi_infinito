#include <iostream>
#include <random>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Utiliza o método uniform_real_distribution() da biblioteca "random"
 * para gerar 2 números flutuantes aleatório entre 0 e o raio do círculo.
 */
vector<double> n_aleatorios(int n) {
    vector<double> x_y;
    x_y.reserve(2);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, n);

    for(int i = 0; i < 2; i++) {
        x_y.push_back(dis(gen));
    }
    return x_y;
}

/*
 * O número de pi pode ser aproximado verificando se o par de
 * pontos x e y está dentro do círculo inscrito no quadrado.
 * Para fazer isso, utilizando de dois números aleatórios, podemos
 * calcular a distância desse ponto até o meio do círculo, considerando
 * o plano cartesiano, o meio seria o ponto (0,0). Assim, se a distância for
 * menor ou igual ao raio, o ponto está dentro do círculo. Depois, após somado
 * todos os pontos dentro do círculo, basta multiplicar por 4 a divisão:
 * (pontos dentro)/(total de pontos calculados) para obter o valor aproximado de pi.
 */
double metodo_probabilistico(int raio, int p_sorteados) {
    double probabilidade, p_dentro = 0;

    for(int i = 0; i <= p_sorteados; i++) {
        vector<double> x_y = n_aleatorios(raio);
        double x = x_y[0];
        double y = x_y[1];
        if(sqrt(pow(x, 2) + pow(y, 2)) <= raio) {
            p_dentro++;
        }
    }
    probabilidade = p_dentro / p_sorteados;

    return 4 * probabilidade;
}
