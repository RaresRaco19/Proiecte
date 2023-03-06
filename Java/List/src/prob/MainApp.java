package prob;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Exeptie_mon extends Exception
{
    private String s;
    Exeptie_mon(String in)
    {
        s=in;
    }
    public String toString()
    {
        return "Moneda:"+s+" nu exista va rugam reintroduceti(RON sau EUR)";
    }
}
class Exeptie_Num_Bank extends Exception
{
    private String s;
    Exeptie_Num_Bank(String in){s=in;}
    public String toString()
    {
        return "Denumirea acestei banci nu exista va rugam reintroduceti sau adaugati banca in sistem";
    }
}

public class MainApp {
    public static void main(String[] args) throws IOException {
        Vector<Banca> Banci=new Vector<Banca>(0);
        byte optiunea=0;
        Scanner TastautaN=new Scanner(System.in);

            do {
                System.out.println("1.Adaugare Banca");
                System.out.println("2.Adaugare client");
                System.out.println("3.Adaugare cont");
                System.out.println("4.Afisare tututor bancilor cu datele introduse");
                System.out.println("5.Afisarea bancilori si nr clienti");
                System.out.println("6.Afisarea clientilor unei banci");
                System.out.println("7.Afisarea conturilor unui client la o anumita banca");
                System.out.println("8.Afisarea conturilor unui client indiferent de banca");
                System.out.println("9.Depunerea unei sume intr-un cont");
                System.out.println("10.Extragerea unei suma dintr-un cont");
                System.out.println("11.Transfer de bani intre doua conturi");
                System.out.println("0.IESIRE");
                System.out.println("Introduceti optiunea:");
                optiunea = TastautaN.nextByte();
                switch (optiunea) {
                    case 1: {
                        Adaugare_banca(Banci);
                        break;
                    }
                    case 2: {
                        try {

                            Adaugare_client(Banci);
                        }
                        catch (Exeptie_Num_Bank e)
                        {
                            System.out.println(e);
                        }

                    }

                }
            } while (optiunea != 0);

    }
    public static void Adaugare_banca(Vector<Banca> B) throws IOException {
        BufferedReader Tast=new BufferedReader(new InputStreamReader(System.in));
       String denumire;
       System.out.println("Denumirea banci:");
       denumire= Tast.readLine();
       Banca Bank=new Banca(denumire);
       B.add(Bank);
       System.out.println("Bank add succefuly");
    }
    public static void Adaugare_client(Vector<Banca> Bank) throws IOException, Exeptie_Num_Bank {
        BufferedReader Tast= new BufferedReader(new InputStreamReader(System.in));
        String Nume,Adresa,DenBank;
        boolean gasit=false;
        List<Client> Clienti;
        System.out.println("Nume client:");
        Nume=Tast.readLine();
        System.out.println("Adresa:");
        Adresa=Tast.readLine();
        Client C=new Client(Nume,Adresa);
        System.out.println("In sistem se gasesc urmatoarele banci:");
        Bank.forEach(banca -> {System.out.println(banca.getDenumire());});
        System.out.println("Introduceti denumirea:");
        DenBank= Tast.readLine();
        for (Banca B:Bank)
        {
            if(B.getDenumire().equalsIgnoreCase(DenBank))
            {
                Clienti=B.getClienti();
                Clienti.add(C);
                B.setClienti(Clienti);
                gasit=true;
                break;
            }
        }
        if(!gasit)
        {
            throw new Exeptie_Num_Bank(DenBank);
        }

    }
    public static String Creat_nr(String Moneda,String Den)
    {
        Random rand=new Random();
        String rdoi=String.valueOf(rand.nextInt(99));
        String D=Den.substring(0,3);
        String rsase=String.valueOf(rand.nextLong(999999999999999L,9999999999999999L));
        return Moneda+rdoi+D+rsase;
    }

    public static void Adaugare_cont(Vector<Banca> Banci)
    {
        BufferedReader Tast=new BufferedReader(new InputStreamReader(System.in));
        ContBancar Cont=new ContBancar();

    }
}
