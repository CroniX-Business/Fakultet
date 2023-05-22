package zad2;

public class Ptica implements Zivotinja{
    private String ime;

    @Override
    public void setIme(String ime) {
        this.ime = ime;
    }

    @Override
    public String getIme() {
        return this.ime;
    }

    @Override
    public void glasajSe() {
        System.out.println("zvuk ptice");
    }
}
