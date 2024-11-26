#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist {PHYSICS, MATHEMATICS, ENGINEERING };

string specialnistStr[] = {"Physics", "Mathematics", "Engineering" };

struct Student {
    string prizv;
    int kurs;
    Specialnist spec;
    int fizyka;
    int matematika;
    int informatyka;
};

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void PrintExcellentStudents(const Student* students, const int N);
double PercentHighAverage(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];

    Create(students, N);
    Print(students, N);
    PrintExcellentStudents(students, N);

    double percent = PercentHighAverage(students, N);
    cout << "Процент студентів із середнім балом більше за 4.5: "
        << fixed << setprecision(2) << percent << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.ignore();
        cout << "    Прізвище: ";
        getline(cin, students[i].prizv);

        cout << "    Курс (1-4): ";
        cin >> students[i].kurs;

        cout << "    Спеціальність (1 - Physics, 2 - Mathematics, 3 - Engineering): ";
        cin >> spec;
        students[i].spec = (Specialnist)spec;

        cout << "    Оцінка з фізики: ";
        cin >> students[i].fizyka;

        cout << "    Оцінка з математики: ";
        cin >> students[i].matematika;

        cout << "    Оцінка з інформатики: ";
        cin >> students[i].informatyka;

        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "===================================================================================" << endl;
    cout << "| № | Прізвище       | Курс  |  Спеціальність | Фізика | Математика | Інформатика |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(15) << left << students[i].prizv
            << "| " << setw(4) << right << students[i].kurs << " "
            << "| " << setw(13) << left << specialnistStr[students[i].spec]
            << "| " << setw(7) << right << students[i].fizyka
            << "| " << setw(11) << right << students[i].matematika
            << "| " << setw(13) << right << students[i].informatyka << " |" << endl;
    }

    cout << "===================================================================================" << endl;
}

void PrintExcellentStudents(const Student* students, const int N) {
    cout << "\nСтуденти, які навчаються на \"відмінно\" (середній бал >= 4.5):" << endl;
    bool found = false;

    for (int i = 0; i < N; i++) {
        double avg = (students[i].fizyka + students[i].matematika + students[i].informatyka) / 3.0;
        if (avg >= 4.5) {
            cout << " - " << students[i].prizv << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає студентів з середнім балом >= 4.5." << endl;
    }
}

double PercentHighAverage(const Student* students, const int N) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        double avg = (students[i].fizyka + students[i].matematika + students[i].informatyka) / 3.0;
        if (avg > 4.5) {
            count++;
        }
    }

    return (N > 0) ? (100.0 * count / N) : 0.0;
}
