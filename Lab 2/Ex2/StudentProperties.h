class Student
{
    char nume[50];
    float notaMate;
    float notaEngleza;
    float notaIstorie;

public:
    void setNume(const char* name);
    const char* getNume() const;

    void setNotaMate(float grade);
    float getNotaMate() const;

    void setNotaEngleza(float grade);
    float getNotaEngleza() const;

    void setNotaIstorie(float grade);
    float getNotaIstorie() const;

    float getNotaFinala() const;
};
