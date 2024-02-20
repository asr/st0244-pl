// La clase `Cuenta`.

public class Cuenta {
  private float saldo;

  // Constructor.
  public Cuenta() { saldo = 0.0f; }

  // Impresión
  public void imprimir() {
    System.out.print("El saldo es " + saldo);
  }

  // Depositar dinero.
  public void depositar(float cantidad) {
    saldo = saldo + cantidad;
  }

  // Retirar dinero.
  public void retirar(float cantidad) {
    saldo = saldo - cantidad;
  }
}
