#include "calculos_de_pi.h"
#include "metodo_probabilistico.h"
using namespace std;

int main() {
    cout << fixed << setprecision(15) << "le: " << leibniz(1000000) << endl;
    cout << "wa: " << wallis(1000000)*2 << endl;
    cout << "eu: " << sqrt(euler(1000000)*6) << endl;
    cout << "vi: " << 2/viete(26) << endl;
    cout << "mp: " << metodo_probabilistico(200, 25000) << endl;
    cout << "pi: " << pi << endl;
    return 0;
}