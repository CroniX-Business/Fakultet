package zad2;

import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        Ptica ptica = new Ptica();
        Lastavica las = new Lastavica();

        ptica.setIme("Orao");
        System.out.println(ptica.getIme() + " se glasa:");
        ptica.glasajSe();

        las.setIme("Lastavica");
        System.out.println(las.getIme() + " se glasa:");
        las.glasajSe();

        Ptica ptica1 = new Ptica();
        Ptica ptica2 = new Ptica();
        Lastavica las1 = new Lastavica();
        Lastavica las2 = new Lastavica();

        List<Zivotinja> zivotinje= new ArrayList<Zivotinja>();

        ptica1.setIme("Orao1");
        ptica2.setIme("Orao2");
        las1.setIme("Lastavica1");
        las2.setIme("Lastavica2");

        zivotinje.add(ptica1);
        zivotinje.add(ptica2);
        zivotinje.add(las1);
        zivotinje.add(las2);

        for (int i = 0; i<4; i++) {
            System.out.println(zivotinje.get(i).getIme());
            zivotinje.get(i).glasajSe();
        }
    }
}
