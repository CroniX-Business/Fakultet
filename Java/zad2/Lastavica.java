package zad2;

public class Lastavica extends Ptica{
    private String ime;

    @Override
    public String getIme() {
        return ime;
    }

    @Override
    public void setIme(String ime) {
        this.ime = ime;
    }

    @Override
    public void glasajSe() {
        System.out.println("zvuk lastavice");
    }
}
