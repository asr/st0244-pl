// Adaptado de un tutorial de Smalltalk disponible en
// https://www.gnu.org/software/smalltalk/manual/html_node/Tutorial.html.

#include <cstdlib>
#include <iostream>
#include <map>

// using namespace std;

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

//////////////////////////////////////////////////////////////////////////////
// La clase `Cuenta`.

class Cuenta {
private:
  float saldo;

public:
  // Constructor.
  Cuenta() { saldo = 0.0; }

  // Impresión
  void imprimir() {
    cout << "El saldo es " << saldo;
  }

  // Depositar dinero.
  void depositar(float cantidad) {
    saldo = saldo + cantidad;
  }

  // Retirar dinero.
  void retirar(float cantidad) {
    saldo = saldo - cantidad;
  }
};

//////////////////////////////////////////////////////////////////////////////
// La subclase `CuentaAhorros`.

// La clase `CuentaAhorros` es una subclase de la clase `Cuenta`. Ésta
// guarda dinero tal como lo hace la clase `Cuenta`, y además ésta paga
// intereses con base en el saldo.

class CuentaAhorros : public Cuenta {
private:
  float intereses;

public:
  // Constructor.
  CuentaAhorros() { intereses = 0.0; }

  // Impresión.
  void imprimir() {
    // LLama el método `imprimir` de la clase padre.
    //
    // El método se cualifica con el nombre de la clase padre.
    Cuenta::imprimir();

    cout << " y los intereses son " << intereses;
  }

  // Nuevos intereses.
  void nuevosIntereses(float cantidad) {
    intereses = intereses + cantidad;

    // Usa el método `depositar` de la clase padre.
    depositar(cantidad);
  }

  // Borrar los intereses.
  float borrarIntereses()
  {
    float interesesAnteriores = intereses;
    intereses = 0.0;

    return interesesAnteriores;
  }
};

//////////////////////////////////////////////////////////////////////////////
// La subclase `CuentaCorriente`.

// En esta subclase se lleva registro del número del siguiente cheque
// y cuantos cheques quedan en la chequera.

class CuentaCorriente : public Cuenta {
private:
  int chequeNumero;                // El número del siguiente cheque.
  int chequesRestantes;            // Cheques restantes en la chequera
  std::map<int, float> historico;  // Histórico cheques

public:
  // Constructor.
  CuentaCorriente() { chequesRestantes = 0; }

  // Impresión.
  void imprimir()
  {
    // LLama el método `imprimir` de la clase padre.
    Cuenta::imprimir();

    cout << ", la cantidad de cheques restantes es " << chequesRestantes
         << " y el número de cheques escritos es " << historico.size();
  }

  // El método `chequesNuevos' adiciona nuevos cheques a la
  // chequera. Se almacena el número del primer cheque y el número de
  // nuevos cheques.
  void chequesNuevos(int num, int cantidadCheques)
  {
    chequeNumero = num;
    chequesRestantes = cantidadCheques;
  }

  void escribirCheque(float cantidad);

  void imprimirHistoricoCheques();
};

// Este método usa el número del siguiente cheque, incrementa este
// número y reduce la cantidad de cheques disponibles.
void CuentaCorriente::escribirCheque(float cantidad)
{
  // Verificación de disponibilidad de cheques.
  if (chequesRestantes < 1) {

    // Se escribe un error al standard error.
    cerr << "Error: No hay cheques" << endl;

    // Salida del programa retornando un error.
    exit(1);
  }

  // Verificación que el número del cheque no haya sido usado con
  // anterioridad.
  if ( historico.find(chequeNumero) != historico.end() ) {

    // Se escribe un error al standard error.
    cerr << "Error: Número de cheque duplicado" << endl;

    // Salida del programa retornando un error.
    exit(1);
  }

  // Se almacena el número del cheque y la cantidad.
  historico.insert({chequeNumero, cantidad});

  // Se actualizan el número del cheque, la cantidad de cheques y el saldo.
  chequeNumero = chequeNumero + 1;
  chequesRestantes = chequesRestantes - 1;

  retirar(cantidad);
}

// Impresión del historico de cheques.
void CuentaCorriente::imprimirHistoricoCheques()
{
  for (auto elem : historico) {
    cout << "Cheque número: "
         << elem.first
         << " valor: "
         << elem.second
         << endl;
  }
}

//////////////////////////////////////////////////////////////////////////////
// El `main`.

int main()
{
  ////////////////////////////////////////////////////////////////////////////
  cout << "Clase `Cuenta`" << endl;

  Cuenta a;

  a.depositar(125);
  a.depositar(20);
  a.retirar(10);

  a.imprimir();
  cout << endl;
  cout << endl;

  ////////////////////////////////////////////////////////////////////////////
  cout << "Clase `CuentaAhorros`" << endl;

  CuentaAhorros s;

  s.depositar(125);
  s.depositar(20);
  s.retirar(10);
  s.nuevosIntereses(5);

  s.imprimir();
  cout << endl;
  cout << endl;

  ////////////////////////////////////////////////////////////////////////////
  cout << "Clase `CuentaCorriente`" << endl;

  CuentaCorriente c;

  c.depositar(250);
  c.chequesNuevos(100,50);
  c.escribirCheque(32);
  c.escribirCheque(50);

  c.imprimir();
  cout << endl;
  cout << endl;

  cout << "Histórico cheques" << endl;
  c.imprimirHistoricoCheques();
  cout << endl;

  ////////////////////////////////////////////////////////////////////////////
  return 0;
}
