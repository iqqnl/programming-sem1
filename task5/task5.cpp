#define ROW_MAX_LENGTH_CHARACTERS 100
#define GROUP_LENGTH ROW_MAX_LENGTH_CHARACTERS / 5
#define NAME_LENGTH ROW_MAX_LENGTH_CHARACTERS / 5 * 3
#define GRADES_LENGTH ROW_MAX_LENGTH_CHARACTERS / 5
#define NUMBER_OF_GRADES 5

#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::setw;

struct Student {
    string name;
    string groupNumber;
    short grades[NUMBER_OF_GRADES]; 
};

template <class T>
struct Array {
    T *values;
    int length;
};

struct AggregatedGroupInfo {
    string groupNumber;
    int numberOfStudents;
    int numberOfLowgraders;
};

Student readStudent(bool isHuman) {
    Student student;

    if (isHuman) {
        cout << "Введите ФИО студента: ";
    }

    cin.ignore(); 
    getline(cin, student.name);

    if (isHuman) {
        cout << "Введите номер группы студента: ";
    }
    cin >> student.groupNumber;

    if (isHuman) {
        cout << "Введите оценки студента: ";
    }

    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        cin >> student.grades[i];
    }

    cout << endl;

    return student;
}

int centeredPrint(string valueToPrint, int sizeOfField) {
    int actualSize = 2;

    int actualSizeOfField = sizeOfField - 2;
    int difference = actualSizeOfField - valueToPrint.length();
    int spacesOnSide = difference / 2;

    cout << "|";
    for (int i = 0; i < spacesOnSide; i++) {
        cout << " ";
        actualSize++;
    }
    cout << valueToPrint;
    actualSize += valueToPrint.length();
    for (int i = 0; i < spacesOnSide; i++) {
        cout << " ";
        actualSize++;
    }
    if (difference % 2) {
        cout << " ";
        actualSize++;
    }
    cout << "|";

    return actualSize;
}

int centeredPrint(int valueToPrint, int sizeOfField) {
    return centeredPrint(std::to_string(valueToPrint), sizeOfField);
}

int centeredPrint(float valueToPrint, int sizeOfField) {
    return centeredPrint(std::to_string(valueToPrint), sizeOfField);
}

float getAverageGrade(short grades[]) {
    float average = 0;

    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        average += grades[i];
    }

    return average / NUMBER_OF_GRADES;
}

int printGrades(short grades[], bool averageOnly, bool isHuman) {
    if (!isHuman) {
        if (averageOnly) {
            float averageGrade = getAverageGrade(grades);
            cout << " - " << averageGrade;

            return 0;
        }

        cout << ": ";
        for (int i = 0; i < NUMBER_OF_GRADES; i++) {
            if (i < NUMBER_OF_GRADES - 1) {
                cout << grades[i] << ", ";
            }
        }

        return 0;
    }

    if (averageOnly) {
        return centeredPrint(getAverageGrade(grades), GRADES_LENGTH);
    }

    int rowActualSize = 0;
    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        rowActualSize += centeredPrint(grades[i], GRADES_LENGTH / NUMBER_OF_GRADES);
    }

    return rowActualSize;
}

void printStudent(Student* student, bool averageOnly, bool isHuman) {
    if (!isHuman) {
        cout << student->groupNumber << " - " << student->name << ": ";
        printGrades(student->grades, averageOnly, isHuman);
        cout << endl;

        return;
    }

    int rowActualSize = 0;

    rowActualSize += centeredPrint(student->groupNumber, GROUP_LENGTH);
    rowActualSize += centeredPrint(student->name, NAME_LENGTH);
    rowActualSize += printGrades(student->grades, averageOnly, isHuman);

    cout << endl << setw(rowActualSize) << std::setfill('-') << '-' << endl;
}

void printTableHeader(string firstCol, string secondCol, string thirdCol) {
    int rowActualSize = 0;

    rowActualSize += centeredPrint(firstCol, GROUP_LENGTH);
    rowActualSize += centeredPrint(secondCol, NAME_LENGTH);
    rowActualSize += centeredPrint(thirdCol, GRADES_LENGTH);

    cout << endl << setw(rowActualSize) << std::setfill('-') << '-' << endl;

}

void printAllStudents(Array<Student> students, bool averageGrades, bool isHuman) {
    if (isHuman) {
        printTableHeader("Группа", "ФИО", "Результат");
    }

    for (int i = 0; i < students.length; i++) {
        printStudent(&students.values[i], averageGrades, isHuman);
    }

    if (isHuman) {
        cout << endl << endl << endl;
    }
}

void printGroupInfo(AggregatedGroupInfo* info, bool isHuman) {
    if (!isHuman) {
        cout << info->groupNumber << " - " << info->numberOfStudents << " - " << info->numberOfLowgraders << endl;
        return;
    }
    int rowActualSize = 0;

    rowActualSize += centeredPrint(info->groupNumber, GROUP_LENGTH);
    rowActualSize += centeredPrint(info->numberOfStudents, NAME_LENGTH);
    rowActualSize += centeredPrint(info->numberOfLowgraders, GRADES_LENGTH);

    cout << endl << setw(rowActualSize) << std::setfill('-') << '-' << endl;
}

void printAllGroupsInfo(Array<AggregatedGroupInfo> groups, bool isHuman) {
    if (isHuman) {
        printTableHeader("Группа", "Число студентов", "Число двоечников");
    }

    for (int i = 0; i < groups.length; i++) {
        printGroupInfo(&groups.values[i], isHuman);
    }

    if (isHuman) {
        cout << endl << endl << endl;
    }
}

Array<Student> filterStudents(Array<Student> set, bool (*predicate)(Student)) {
    Array<Student> result;
    result.length = 0;
    result.values = new Student[set.length];
    
    for (int i = 0; i < set.length; i++) {
        if (predicate(set.values[i])) {
            result.values[result.length++] = set.values[i];
        }
    }

    return result;
}

bool isAverageGradeGreaterThenFour(Student student) {
    return getAverageGrade(student.grades) > 4.0;
}

bool isGroupNumberBigger(Student* first, Student* second) {
    return first->groupNumber > second->groupNumber;
}

bool isGroupHavingMoreLowgraders(AggregatedGroupInfo* first, AggregatedGroupInfo* second) {
    return first->numberOfLowgraders > second->numberOfLowgraders;
}

bool isLowgrader(Student* student) {
    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        if (student->grades[i] == 2) {
            return true;
        }
    }

    return false;
}

template <class T>
void bubbleSort(Array<T> arr, bool (*comparator)(T*, T*)) {
     for (int i = 0; i < arr.length - 1; i++) {
        for (int j = 0; j < arr.length - i - 1; j++) {
            if (comparator(&arr.values[j], &arr.values[j + 1])) {
                T tmp = arr.values[j];
                arr.values[j] = arr.values[j + 1];
                arr.values[j + 1] = tmp;
            }
        }
    }
}

Array<AggregatedGroupInfo> aggregate(Array<Student> students) {
    Array<AggregatedGroupInfo> result;
    result.values = new AggregatedGroupInfo[students.length];
    result.length = 0;

    for (int i = 0; i < students.length; i++) {
        Student* student = &students.values[i];

        AggregatedGroupInfo* currentGroup = &result.values[0];
        int j = 0;
        while (j < result.length && result.values[j].groupNumber != student->groupNumber) {
            currentGroup = &result.values[++j];
        }
        if (j == result.length) {
            result.length++;
            currentGroup->groupNumber = student->groupNumber;
            currentGroup->numberOfLowgraders = 0;
            currentGroup->numberOfStudents = 0;
        }

        currentGroup->numberOfStudents++;
        if (isLowgrader(student)) {
            currentGroup->numberOfLowgraders++;
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    bool isHuman = false;
	if (argc <= 1 || strcmp(argv[1], "false") != 0)
	{
		isHuman = true;
	}

    // to delete
    isHuman = true;
    //

    Array<Student> students;
    cin >> students.length;

    students.values = new Student[students.length];
    for (int i = 0; i < students.length; i++) {
        students.values[i] = readStudent(isHuman);
    }

    bubbleSort(students, isGroupNumberBigger);
    printAllStudents(students, false, isHuman);

    Array<Student> filteredStudents = filterStudents(students, isAverageGradeGreaterThenFour);
    printAllStudents(filteredStudents, true, isHuman);

    Array<AggregatedGroupInfo> groups = aggregate(students);
    bubbleSort(groups, isGroupHavingMoreLowgraders);
    printAllGroupsInfo(groups, isHuman);

    delete[] groups.values;
    delete[] filteredStudents.values;
    delete[] students.values;
}