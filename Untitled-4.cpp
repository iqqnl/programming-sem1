#include <iostream>
#include <cstring>
using namespace std;

struct STUDENT
{
    char FIO[100];
    int ngr;
    int usp[5];
    double sum;
};

struct Itog
{
    int ngrs;
    int studs;
    int twostuds;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    STUDENT* Stud = new STUDENT[n];

    for (int i = 0; i < n; i++)
    {
        Stud[i].sum = 0;
        cout << "Введите ФИО студента " << i + 1 << ": ";
        cin.ignore();
        cin.getline(Stud[i].FIO, 100);

        cout << "Введите номер группы: ";
        cin >> Stud[i].ngr;

        cout << "Введите оценки: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> Stud[i].usp[j];
            Stud[i].sum += Stud[i].usp[j];
        }
        Stud[i].sum /= 5.0;
    }

    STUDENT buffer;
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (Stud[i].ngr > Stud[i + 1].ngr)
            {
                buffer = Stud[i];
                Stud[i] = Stud[i + 1];
                Stud[i + 1] = buffer;
                swapped = true;
            }
        }
    } while (swapped);

    cout << "Упорядоченный список студентов по номеру группы:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Stud[i].ngr << " - " << Stud[i].FIO << ": ";
        for (int j = 0; j < 5; j++)
        {
            cout << Stud[i].usp[j] << " ";
        }
        cout << endl;
    }

    int M = 0;
    cout << "Студенты с средним баллом больше 4.0:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (Stud[i].sum > 4.0)
        {
            cout << Stud[i].ngr << " - " << Stud[i].FIO << ": " << Stud[i].sum << endl;
            M++;
        }
    }
    if (M == 0)
    {
        cout << "NO" << endl;
    }

    Itog* GRUP = new Itog[n];
    int g = 0;
    bool groupFound;

    for (int i = 0; i < n; i++)
    {
        groupFound = false;
        for (int j = 0; j < g; j++)
        {
            if (GRUP[j].ngrs == Stud[i].ngr)
            {
                groupFound = true;
                break;
            }
        }
        if (!groupFound)
        {
            GRUP[g].ngrs = Stud[i].ngr;
            GRUP[g].studs = 0;
            GRUP[g].twostuds = 0;
            g++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g; j++)
        {
            if (Stud[i].ngr == GRUP[j].ngrs)
            {
                GRUP[j].studs++;
                for (int k = 0; k < 5; k++)
                {
                    if (Stud[i].usp[k] == 2)
                    {
                        GRUP[j].twostuds++;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < g - 1; i++)
    {
        for (int j = 0; j < g - 1 - i; j++)
        {
            if (GRUP[j].twostuds < GRUP[j + 1].twostuds)
            {
                Itog temp = GRUP[j];
                GRUP[j] = GRUP[j + 1];
                GRUP[j + 1] = temp;
            }
        }
    }

    cout << "Группы и количество студентов с двоечниками:" << endl;
    for (int i = 0; i < g; i++)
    {
        cout << GRUP[i].ngrs << " - " << GRUP[i].studs << " студентов, " << GRUP[i].twostuds << " двоечников" << endl;
    }

    delete[] Stud;
    delete[] GRUP;

    return 0;
}
