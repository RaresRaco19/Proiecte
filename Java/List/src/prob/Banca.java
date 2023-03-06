package prob;

import java.util.ArrayList;
import java.util.List;

public class Banca {
    private String Denumire;
    private List<Client> Clienti=new ArrayList<Client>();
    public Banca()
    {}
    public Banca(String D)
    {
        Denumire=D;
    }
    public Banca(String D,List<Client> C)
    {
        Denumire=D;
        Clienti=C;
    }
    public String toString()
    {
        String S="Banca:"+Denumire+'\n'+"Clienti:";
        for (Client C:Clienti)
        {
         S+=C.getNume()+'\n';
        }
        return S;
    }

    public String getDenumire() {
        return Denumire;
    }

    public void setDenumire(String denumire) {
        Denumire = denumire;
    }

    public List<Client> getClienti() {
        return Clienti;
    }

    public void setClienti(List<Client> clienti) {
        Clienti = clienti;
    }
}
