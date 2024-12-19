#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

struct STUDENT {
    string surname;
    string name;
    string patronymic;
    string group_number;
    int grades[5]{};
};

double average_grade(const STUDENT& student) {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += student.grades[i];
    }
    return sum / 5;
}

bool has_bad_grade(const STUDENT& student) {
    for (int i = 0; i < 5; ++i) {
        if (student.grades[i] == 2) return true;
    }
    return false;
}

void stable_sort_by_group(STUDENT students[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (students[j].group_number > students[j + 1].group_number) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void stable_sort_by_average(STUDENT students[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (average_grade(students[j]) < average_grade(students[j + 1])) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void dynamic_string(double size, string name)
{
    for (int i = 0; i < size; i++)
        cout << name;
}

int main(int argc, char* argv[])
{
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N{}, K{};
    if (isHuman)
        cout << "Введите количество студентов: ";
    cin >> N;

    struct STUDENT* students = new struct STUDENT[N];

    for (int i = 0; i < N; ++i) {
        if (isHuman)
            cout << "Введите ФИО студента: ";
        cin >> students[i].surname >> students[i].name >> students[i].patronymic;
        if (K < size(students[i].surname + students[i].name + students[i].patronymic) + 2)
            K = size(students[i].surname + students[i].name + students[i].patronymic) + 2;
        if (isHuman)
            cout << "Введите номер группы: ";
        cin >> students[i].group_number;
        if (isHuman)
            cout << "Введите успеваемость студента: ";
        for (int j = 0; j < 5; ++j) {
            cin >> students[i].grades[j];
        }
    }

    stable_sort_by_group(students, N);

    if (isHuman) {
        cout << "___________";
        dynamic_string(K, "_");
        cout << "__________________" << endl;
        cout << "| Группа | ";
        dynamic_string((K - 3) / 2, " ");
        cout << "ФИО";
        if ((K - 3) % 2 == 0)
            dynamic_string((K - 3) / 2, " ");
        else
            dynamic_string((K - 3) / 2 + 1, " ");
        cout << " |    Оценки     |" << endl;
        cout << "|________|_";
        dynamic_string(K, "_");
        cout << "_|_______________|" << endl;
        for (int i = 0; i < N; ++i) {
            string name = students[i].surname + " " + students[i].name + " " + students[i].patronymic;
            cout << "|  " << students[i].group_number << "  | ";
            dynamic_string((K - size(name)) / 2, " ");
            cout << name;
            if ((K - size(name)) % 2 == 0)
                dynamic_string((K - size(name)) / 2, " ");
            else
                dynamic_string((K - size(name)) / 2 + 1, " ");
            cout << " | ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].grades[j];
                if (j < 4) cout << ", ";
            }
            cout << " |" << endl;
        }
        cout << "|________|_";
        dynamic_string(K, "_");
        cout << "_|_______________|" << endl;
    }
    else
        for (int i = 0; i < N; ++i) {
            cout << students[i].group_number << " - " << students[i].surname << " " << students[i].name << " " << students[i].patronymic << ": ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].grades[j];
                if (j < 4) cout << ", ";
            }
            cout << endl;
        }

    struct STUDENT* filtered_students = new struct STUDENT[N];
    int filtered_count = 0;

    for (int i = 0; i < N; ++i) {
        if (average_grade(students[i]) > 4.0) {
            filtered_students[filtered_count++] = students[i];
        }
    }

    if (filtered_count > 0) {
        if (isHuman) {
            stable_sort_by_average(filtered_students, filtered_count);
            cout << "___________";
            dynamic_string(K, "_");
            cout << "______________" << endl;
            cout << "| Группа | ";
            dynamic_string((K - 3) / 2, " ");
            cout << "ФИО";
            if ((K - 3) % 2 == 0)
                dynamic_string((K - 3) / 2, " ");
            else
                dynamic_string((K - 3) / 2 + 1, " ");
            cout << " |  Ср.балл  |" << endl;
            cout << "|________|_";
            dynamic_string(K, "_");
            cout << "_|___________|" << endl;
            for (int i = 0; i < filtered_count; ++i) {
                string name = filtered_students[i].surname + " " + filtered_students[i].name + " " + filtered_students[i].patronymic;
                cout << "|  " << filtered_students[i].group_number << "  | ";
                dynamic_string((K - size(name)) / 2, " ");
                cout << name;
                if ((K - size(name)) % 2 == 0)
                    dynamic_string((K - size(name)) / 2, " ");
                else
                    dynamic_string((K - size(name)) / 2 + 1, " ");
                cout << " |";
                if (average_grade(filtered_students[i]) == 5)
                    cout << "     " << setprecision(0) << average_grade(filtered_students[i]) << "     |" << endl;
                else
                    cout << "    " << setprecision(2) << average_grade(filtered_students[i]) << "    |" << endl;
            }
            cout << "|________|_";
            dynamic_string(K, "_");
            cout << "_|___________|" << endl;
        }
        else {
            stable_sort_by_average(filtered_students, filtered_count);
            for (int i = 0; i < filtered_count; ++i) {
                if (average_grade(filtered_students[i]) == 5)
                    cout << filtered_students[i].group_number << ", " << filtered_students[i].surname << " " << filtered_students[i].name << " " << filtered_students[i].patronymic << " - " << fixed << setprecision(0) << average_grade(filtered_students[i]) << endl;
                else
                    cout << filtered_students[i].group_number << ", " << filtered_students[i].surname << " " << filtered_students[i].name << " " << filtered_students[i].patronymic << " - " << fixed << setprecision(1) << average_grade(filtered_students[i]) << endl;
            }
        }
    }
    else {
        cout << "NO" << endl;
    }

    struct GroupInfo {
        int count;
        int bad_count;
    };

    struct GroupInfo* group_stats = new struct GroupInfo[N]{ {0, 0} };
    string* group_numbers = new string[N];
    int group_count = 0;

    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int j = 0; j < group_count; ++j) {
            if (group_numbers[j] == students[i].group_number) {
                group_stats[j].count++;
                if (has_bad_grade(students[i])) {
                    group_stats[j].bad_count++;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            group_numbers[group_count] = students[i].group_number;
            group_stats[group_count].count = 1;
            group_stats[group_count].bad_count = has_bad_grade(students[i]) ? 1 : 0;
            group_count++;
        }
    }

    for (int i = 0; i < group_count - 1; ++i) {
        for (int j = 0; j < group_count - i - 1; ++j) {
            if (group_stats[j].bad_count < group_stats[j + 1].bad_count) {
                swap(group_stats[j], group_stats[j + 1]);
                swap(group_numbers[j], group_numbers[j + 1]);
            }
        }
    }

    if (isHuman) {
        cout << "_________________________________" << endl;
        cout << "| Группа | Студенты | Двоечники |" << endl;
        cout << "|________|__________|___________|" << endl;
        for (int i = 0; i < group_count; ++i) {
            string name = to_string(group_stats[i].count);
            cout << "|  " << group_numbers[i] << "  | ";
            dynamic_string((8 - size(name)) / 2, " ");
            cout << name;
            if ((8 - size(name)) % 2 == 0)
                dynamic_string((8 - size(name)) / 2, " ");
            else
                dynamic_string((8 - size(name)) / 2 + 1, " ");
            cout << " | ";
            name = to_string(group_stats[i].bad_count);
            dynamic_string((9 - size(name)) / 2, " ");
            cout << name;
            if ((9 - size(name)) % 2 == 0)
                dynamic_string((9 - size(name)) / 2, " ");
            else
                dynamic_string((9 - size(name)) / 2 + 1, " ");
            cout << " |" << endl;;
        }
        cout << "|________|__________|___________|" << endl;
    }
    else {
        for (int i = 0; i < group_count; ++i) {
            cout << group_numbers[i] << " - " << group_stats[i].count << " - " << group_stats[i].bad_count << endl;
        }
    }

    return 0;
}