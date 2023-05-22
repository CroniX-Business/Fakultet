package Zadatak3;

public class Raketa implements Runnable {
    private String ime;
    LansirnaRampa rampa;
    
    Raketa( String ime, LansirnaRampa rampa) {
        this.ime = ime;
        this.rampa = rampa;
    }
    
    public void run() {
        synchronized(rampa){
            rampa.lansiraj();
            System.out.println("Raketa " + ime + " lansirana!");
        }
    }
}


