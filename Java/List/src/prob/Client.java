package prob;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Client {
    private String Nume,Adresa;
    private Set<ContBancar> Conturi=new HashSet<ContBancar>();
    public Client()
    {}
    public Client(String N,String A)
    {
        Nume=N;
        Adresa=A;
    }
    public Client(String N,String A,Set<ContBancar> C)
    {
        Nume=N;
        Adresa=A;
        Conturi=C;
    }
    public String toString()
    {
        String S="----Detalii Client----"+'\n'+"Nume:"+Nume+"Adresa:"+Adresa+'\n'+
                "Conturi:"+'\n';
        for (ContBancar C:Conturi) {
            S=S+C.getNumarCont()+'\n';
        }
        return S;
    }

    public String getNume() {
        return Nume;
    }

    public void setNume(String nume) {
        Nume = nume;
    }

    public Set<ContBancar> getConturi() {
        return Conturi;
    }

    public void setConturi(Set<ContBancar> conturi) {
        Conturi = conturi;
    }
}
