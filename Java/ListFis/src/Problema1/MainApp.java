package Problema1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.time.Month;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Predicate;

public class MainApp {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner Tastatura=new Scanner(System.in);
        BufferedReader Tast=new BufferedReader(new InputStreamReader(System.in));
        File file=new File("in.txt");
        Scanner flux_in=new Scanner(file);
        List<Angajat> Angajati=new ArrayList<Angajat>();
        byte optiune=0;
        do {
            System.out.println("1.Citire din fisier");
            System.out.println("2.Afisare");
            System.out.println("3.Afisare lista agajati din aprilie cu post de conducere");
            System.out.println("4.Afisare angajti fara post de conducere in ordine desc a salariilor");
            System.out.println("5.Afisare angajati cu salariul mai mare de 2500");
            System.out.println("6.Lista cu numele angajatilor scrise cu litere mari");
            System.out.println("7.Afisare salari mai mici de 3000");
            System.out.println("0.IESIRE");
            System.out.println("Selectati optiunea:");
            optiune=Tastatura.nextByte();
            switch (optiune)
            {
                case 1:
                    citire(Angajati);
                    break;
                case 2:
                    Afisare(Angajati);
                    break;
                case 3:
                    Afisare_aprilie(Angajati);
                    break;
                case 4:
                    break;
                case 5:
                    Afisare_salriu_2500(Angajati);
                    break;
            }
        }while(optiune!=0);
    }

    public static void citire(List<Angajat> lista) throws FileNotFoundException {
        File file=new File("in.txt");
        Scanner flux_in=new Scanner(file);
        String Nume;
        byte contor;
        flux_in.useDelimiter(";");
        while(flux_in.hasNext())
        {
            Angajat A=new Angajat();
            A.setNume(flux_in.next());
            A.setPost(flux_in.next());
            A.setData(LocalDate.parse(flux_in.next()));
            A.setSalariu(flux_in.nextInt());
            lista.add(A);
        }
        System.out.println("-----Data read succefuly-----");
    }
    public static void Afisare(List<Angajat> lista)
    {
        lista.forEach(System.out::println);
    }
    public static void Afisare_aprilie(List<Angajat> lista)
    {
        Predicate<Angajat> P=(a)->a.getPost().contains("sef") && a.getData().getMonth()== Month.APRIL;
        lista.stream().filter(P).forEach(System.out::println);
    }
    public static void Afisare_salriu_2500(List<Angajat> lista)
    {
        Predicate<Angajat> P=(a)->a.getSalariu()<2500;
        lista.stream().filter(P).forEach(a->System.out.println(a));
    }


}
