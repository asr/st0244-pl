// Adaptado de un tutorial de Smalltalk disponible en
// https://www.gnu.org/software/smalltalk/manual/html_node/Tutorial.html.

// La clase `Main`.

class Main {
  public static void main(String[] args) {

    // Cuenta
    System.out.println("Clase `Cuenta`");

    Cuenta a = new Cuenta();

    a.depositar(125);
    a.depositar(20);
    a.retirar(10);

    a.imprimir();
    System.out.println();
    System.out.println();

    // Cuenta de ahorros
    System.out.println("Clase `CuentaAhorros`");

    CuentaAhorros s = new CuentaAhorros();

    s.depositar(125);
    s.depositar(20);
    s.retirar(10);
    s.nuevosIntereses(5);

    s.imprimir();
    System.out.println();
    System.out.println();

    // Cuenta corriente
    System.out.println("Clase `CuentaCorriente`");

    CuentaCorriente c = new CuentaCorriente();

    c.depositar(250);
    c.chequesNuevos(1,50);
    c.escribirCheque(32);
    c.escribirCheque(50);

    c.imprimir();
    System.out.println();
    System.out.println();

    System.out.println("Histórico cheques");
    c.imprimirHistóricoCheques();
    System.out.println();
  }
}
