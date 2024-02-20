import java.util.HashMap;

// La subclase `CuentaCorriente`.

// En esta subclase se lleva registro del número del siguiente cheque
// y cuantos cheques quedan en la chequera.

class CuentaCorriente extends Cuenta {
  private int chequeNúmero;          // El número del siguiente cheque.
  private int chequesRestantes;      // Cheques restantes en la chequera.
  HashMap<Integer, Float> histórico; // Histórico cheques

  // Constructor.
  public CuentaCorriente() {

    chequesRestantes = 0;
    histórico = new HashMap<Integer, Float>();
  }

  // Impresión.
  public void imprimir() {

    // LLama el método `imprimir` de la clase padre.
    super.imprimir();

    System.out.print(", la cantidad de cheques restantes es " + chequesRestantes);
    System.out.print(" y el número de cheques escritos es " + histórico.size());
  }

  // El método `chequesNuevos' adiciona nuevos cheques a la
  // chequera. Se almacena el número del primer cheque y el número de
  // nuevos cheques.
  public void chequesNuevos(int num, int cantidadCheques) {

    chequeNúmero = num;
    chequesRestantes = cantidadCheques;
  }

  // Este método usa el número del siguiente cheque, incrementa
  // este número y reduce la cantidad de cheques disponibles.
  public void escribirCheque(float cantidad)
  {
    // Verificación de disponibilidad de cheques.
    if (chequesRestantes < 1) {

      // Se escribe un error al standard error.
      System.err.println("Error: No hay cheques");

      // Salida del programa retornando un error.
      System.exit(1);
    }

    // Verificación que el número del cheque no haya sido usado con
    // anterioridad.
    if ( histórico.containsKey(chequeNúmero) ) {

      // Se escribe un error al standard error.
      System.err.println("Error: Número de cheque duplicado");

      // Salida del programa retornando un error.
      System.exit(1);
    }

    // Se almacena el número del cheque y la cantidad.
    histórico.put(chequeNúmero, cantidad);

    // Se actualizan el número del cheque, la cantidad de cheques y el saldo.
    chequeNúmero = chequeNúmero + 1;
    chequesRestantes = chequesRestantes - 1;
    retirar(cantidad);
  }

  // Impresión del histórico de cheques.
  public void imprimirHistóricoCheques() {

    for ( Integer i : histórico.keySet() )
      System.out.println("Cheque número: " + i + " valor: " + histórico.get(i));
  }
}
