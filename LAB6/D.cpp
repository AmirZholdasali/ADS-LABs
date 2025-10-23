#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

// Вспомогательная функция для сравнения дат
bool compareDates(const std::string& a, const std::string& b) {
    // Предполагаем формат DD--MM--YY
    try {
        int day_a = std::stoi(a.substr(0, 2));
        int month_a = std::stoi(a.substr(3, 2));
        int year_a = std::stoi(a.substr(6, 2));
        int day_b = std::stoi(b.substr(0, 2));
        int month_b = std::stoi(b.substr(3, 2));
        int year_b = std::stoi(b.substr(6, 2));
        
        if (year_a != year_b) return year_a < year_b;
        if (month_a != month_b) return month_a < month_b;
        return day_a < day_b;
    } catch (const std::exception& e) {
        // Если строка некорректна, можно обработать это по-другому
        return false; // или выбросить исключение
    }
}

void heapify(std::vector<std::string>& A, int n, int i) {
    int smallest = i; // Для min-heap
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    // Сравниваем левый потомок
    if (l < n && compareDates(A[l], A[smallest])) {
        smallest = l;
    }
    // Сравниваем правый потомок
    if (r < n && compareDates(A[r], A[smallest])) {
        smallest = r;
    }

    if (smallest != i) {
        std::swap(A[i], A[smallest]);
        heapify(A, n, smallest);
    }
}

void buildMinHeap(std::vector<std::string>& A) {
    int n = static_cast<int>(A.size());
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(A, n, i);
    }
}

void heapSort(std::vector<std::string>& A) {
    int n = static_cast<int>(A.size());
    if (n < 2) return;

    buildMinHeap(A);

    for (int i = n - 1; i > 0; --i) {
        std::swap(A[i], A[0]);
        heapify(A, i, 0);
    }
}

int main() {
    std::vector<std::string> A;
    int n;
    std::string date;
    cin >> n;
    
    // Проверка корректности ввода
    if (n < 0) {
        cout << "Некорректный размер\n";
        return 1;
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> date;
        // Проверка формата (должно быть ровно 8 символов, DD--MM--YY)
        if (date.size() == 8 && date[2] == '-' && date[5] == '-') {
            A.push_back(date);
        } else {
            cout << "Некорректный формат даты: " << date << "\n";
            return 1;
        }
    }

    heapSort(A);

    for (const std::string& s : A) {
        cout << s << endl;
    }
    return 0;
}