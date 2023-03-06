package Problema1;

import java.time.LocalDate;

public class Angajat {
    private String Nume,Post;
    private LocalDate Data;
    private int Salariu;

    Angajat()
    {

    }
    Angajat(String Nume,String Post,LocalDate Date,int Sala)
    {
        this.Nume=Nume;
        this.Post=Post;
        this.Data=Date;
        this.Salariu=Sala;
    }
    public String toString()
    {
        return  "Nume:" +Nume+'\n'+"Post:"+Post+'\n'+"Data angajari:"+Data+'\n'+"Salariu:"+Salariu+'\n';
    }
    public String getNume() {
        return Nume;
    }

    public void setNume(String nume) {
        Nume = nume;
    }

    public String getPost() {
        return Post;
    }

    public void setPost(String post) {
        Post = post;
    }

    public LocalDate getData() {
        return Data;
    }

    public void setData(LocalDate data) {
        Data = data;
    }

    public int getSalariu() {
        return Salariu;
    }

    public void setSalariu(int salariu) {
        Salariu = salariu;
    }
}
