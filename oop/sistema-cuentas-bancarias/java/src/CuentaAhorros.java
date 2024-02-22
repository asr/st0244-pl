// La subclase `CuentaAhorros`.

// La clase `CuentaAhorros` es una subclase de la clase `Cuenta`. Ésta
// guarda dinero tal como lo hace la clase `Cuenta`, y además ésta paga
// intereses con base en el saldo.

public class CuentaAhorros extends Cuenta {
  private float intereses;  // Atributo

  // Constructor.
  public CuentaAhorros() { intereses = 0.0f; }

  // Impresión.
  public void imprimir() {

    // LLama el método `imprimir` de la clase padre.
    //
    // La palabra reservada `super` se utiliza para llamar métodos de
    // la clase padre.
    super.imprimir();

    System.out.print(" y los intereses son " + intereses);
  }

  // Nuevos intereses.
  public void nuevosIntereses(float cantidad) {

    intereses = intereses + cantidad;

    // Usa el método `depositar` de la clase padre.
    depositar(cantidad);
  }

  // Borrar los intereses.
  public float borrarIntereses() {

    float interesesAnteriores = intereses;
    intereses = 0.0f;

    return interesesAnteriores;
  }
}
