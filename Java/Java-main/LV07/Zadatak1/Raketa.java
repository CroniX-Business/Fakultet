package Zadatak1;

public class Raketa extends Thread {
    private String ime;
    LansirnaRampa rampa;
    
    Raketa( String ime, LansirnaRampa rampa) {
        this.ime = ime;
        this.rampa = rampa;
    }
    
    public void run() {
        rampa.lansiraj();
        System.out.println("Raketa " + ime + " lansirana!");
    }
}
    
    
    
    
    

