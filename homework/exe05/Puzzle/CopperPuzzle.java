import java.awt.Color;

public class CopperPuzzle {
  public static void main (String[] args) {
    Picture p0 = new Picture( args[0]);
    System.out.printf( "Original image %d-by-%d\n", p0.width(), p0.height());
    p0.show();
    
    System.out.println( "Start to solve..." );
    Picture p1 = new Picture( p0);
    solveCopperPuzzle( p1);
    System.out.printf( "Result image %d-by-%d\n", p1.width(), p1.height());
    p1.show();
  }

  public static void solveCopperPuzzle (Picture p) {
    for (int x = 0; x < p.width(); x++) {
      for (int y = 0; y < p.height(); y++) {
        Color cPuzzle = p.get( x, y);
        int g = cPuzzle.getGreen();
        int b = cPuzzle.getBlue();
        Color cSolution = new Color( 0, g*10, b*10 );  // Color(R,G,B)
        p.set( x, y, cSolution);
      }
    }
  }
}

