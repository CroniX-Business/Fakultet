package zad1;
import java.util.Scanner;
import java.util.Random;

public class GuessTheNumber {
    int n, tries = 1, granica = 5;

    Random rand = new Random();
    Scanner in = new Scanner(System.in);

    private int number = rand.nextInt(granica);
    public void guess() {
        int n = in.nextInt();

        if(n != number) {
            tries++;
            guess();
        } else {
            System.out.println("Bravo! Pogodio/la si broj zadan u programu: " + number + ", trebalo ti je " + tries + " pokušaja.");
        }
    }

    public static void main(String args []){
        GuessTheNumber number = new GuessTheNumber();
        number.guess();
    }
}
