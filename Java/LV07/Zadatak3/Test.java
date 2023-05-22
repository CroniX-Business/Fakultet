package Zadatak3;

public class Test {
    public static void main(String[] args) {
         LansirnaRampa ramp = new LansirnaRampa();
         (new Thread(new Raketa("Sputnik", ramp))).start();
         (new Thread(new Raketa("Apollo 9", ramp))).start();
         (new Thread(new Raketa("Enterprise", ramp))).start();
    }
    
}
