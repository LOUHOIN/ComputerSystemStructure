import java.awt.*;

public class WestPuzzle {
    public static void main (String[] args) {
        Picture p0 = new Picture( args[0]);
        System.out.printf( "Original image %d-by-%d\n", p0.width(), p0.height());
        p0.show();

        System.out.println( "Start to solve..." );
        Picture p1 = new Picture( p0);
        solveWestPuzzle( p1);
        System.out.printf( "Result image %d-by-%d\n", p1.width(), p1.height());
        p1.show();
    }
    public static void solveWestPuzzle (Picture p) {
        for (int x = 0; x < p.width(); x++) {
            for (int y = 0; y < p.height(); y++) {
                Color cPuzzle = p.get( x, y);
                int b = cPuzzle.getBlue();
                if(b < 16) b *= 16;
                else b = 0;
                Color cSolution = new Color( b, 0, 0 );  // Color(R,G,B)
                p.set( x, y, cSolution);
            }
        }
    }
}
