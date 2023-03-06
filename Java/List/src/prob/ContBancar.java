package prob;


import java.time.Duration;
import java.time.LocalDate;
interface Operatiuni
{
    default float Calculeaza_dob()
    {
        return 0;
    }
    default float Actualizre_sum()
    {
        return 0;
    }
    void Depunere(float s);
    void Extragere(float s);
}


public class ContBancar implements  Operatiuni{
    private String NumarCont,Moneda;
    private float Suma;
    private LocalDate Data_deschideri,Data_ult_tran;
    ContBancar()
    {}
    ContBancar(String NrC,String Mon,float S,LocalDate data_d,LocalDate Data_u)
    {
        NumarCont=NrC;
        Moneda=Mon;
        Suma=S;
        Data_deschideri=data_d;
        Data_ult_tran=Data_u;
    }

    @Override
    public float Actualizre_sum() {
        Data_ult_tran=LocalDate.now();
        return  Suma+=Calculeaza_dob();
    }

    @Override
    public float Calculeaza_dob() {
        long timp;
        float Dobanda=0;
        timp= Duration.between(LocalDate.now().atStartOfDay(), Data_ult_tran.atStartOfDay()).toDays();
        if(Moneda.contains("RON"))
        {
            if(Suma<500)
                Dobanda+=timp*0.3;
            else
                Dobanda+=timp*0.8;
        }
        else
        {
            Dobanda+=timp+0.1;
        }

        return Dobanda;
    }

    public String toString()
    {
        return "----Detalii cont----"+'\n'+"Numar Cont:"+NumarCont+'\n'+
                "Moneda:"+Moneda+'\n'+"Suma:"+Suma+'\n'+"Data deschideri:"+Data_deschideri+'\n'+
                "Data ultimei operatiuni:"+Data_ult_tran+'\n';
    }

    public void Depunere(float s)
    {
        Actualizre_sum();
        Suma+=s;
        System.out.println("Succesfuly");
    }
    public void Extragere(float s)
    {
        Actualizre_sum();
        Suma-=s;
        System.out.println("Succesfuly");
    }

    public String getNumarCont() {
        return NumarCont;
    }

    public void setNumarCont(String numarCont) {
        NumarCont = numarCont;
    }

    public String getMoneda() {
        return Moneda;
    }

    public void setMoneda(String moneda) {
        Moneda = moneda;
    }

    public float getSuma() {
        return Suma;
    }

    public void setSuma(float suma) {
        Suma = suma;
    }

    public LocalDate getData_deschideri() {
        return Data_deschideri;
    }

    public void setData_deschideri(LocalDate data_deschideri) {
        Data_deschideri = data_deschideri;
    }

    public LocalDate getData_ult_tran() {
        return Data_ult_tran;
    }

    public void setData_ult_tran(LocalDate data_ult_tran) {
        Data_ult_tran = data_ult_tran;
    }
}
