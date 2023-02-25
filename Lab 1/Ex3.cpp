#include <iostream>
#include <cstring>
using namespace std;

void swapp(char text1[], char text2[])
{
    char Aux[250];
    strcpy(Aux, text1);
    strcpy(text1, text2);
    strcpy(text2, Aux);
}

int main()
{
    char text[250], a[100][250];
    int n = 0;
    scanf("%[^\n]s", text);
    char* p = strtok(text, " ");

    while (p!= NULL)
    {
        strcpy(a[n++], p);
        p = strtok(NULL, " ");
    }

    for (int i = 0;i < n-1;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            if (strlen(a[i]) < strlen(a[j]))
                swapp(a[i], a[j]);
            else if (strlen(a[i]) == strlen(a[j])) {
                for (int k = 0; k < strlen(a[i]); k++)
                    if (a[i][k] < a[j][k]) break;
                    else if (a[i][k] > a[j][k])
                    {
                        swapp(a[i], a[j]);
                        break;
                    }
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%s \n", a[i]);
}
