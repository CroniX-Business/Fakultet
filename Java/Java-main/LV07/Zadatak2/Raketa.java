package Zadatak2;

public class Raketa implements Runnable {
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
    
    
    
    
    

