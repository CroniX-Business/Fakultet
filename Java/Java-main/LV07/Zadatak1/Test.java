package Zadatak1;

public class Test {
    public static void main(String[] args) {
       LansirnaRampa ramp = new LansirnaRampa();
       Raketa t1=new Raketa("Sputnik", ramp);
       Raketa t2=new Raketa("Apollo 9", ramp);
       Raketa t3=new Raketa("Enterprise", ramp);             
       t1.start();
       t2.start();
       t3.start(); 
    }
}
    
    
    
    
    

