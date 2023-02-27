class Student
{
    char nume[50];
    float notaMate;
    float notaEngleza;
    float notaIstorie;

public:
    void setNume(const char* name);
    const char* getNume() const;

    void setNotaMate(float nota);
    float getNotaMate() const;

    void setNotaEngleza(float nota);
    float getNotaEngleza() const;

    void setNotaIstorie(float nota);
    float getNotaIstorie() const;

    float getNotaFinala() const;
};
