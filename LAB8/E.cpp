#include <iostream>
#include <limits>

long long hash_contrib(char ch, int i) {
    return (long long)(ch - 'a') * (1LL << i);
}

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    long long prev = 0;
    for (int i = 0; i < n; ++i) {
        long long hsh;
        std::cin >> hsh;

        long long diff = hsh - prev;
        prev = hsh;

        // если diff отрицательный или i слишком велик — ошибка входа
        if (diff < 0) {
            std::cerr << "Invalid input: decreasing prefix hash\n";
            return 0;
        }

        // извлекаем коэффициент k = diff / 2^i
        long long k = diff >> i;              // целочисленное деление на 2^i
        // проверяем точность: k * 2^i должно равняться diff
        if ((k << i) != diff) {
            std::cerr << "Hash not aligned with power of two at pos " << i << "\n";
            return 0;
        }

        // допустимый диапазон k: обычно 0..(alphabet_size-1)
        // у тебя используется 'a' + k, поэтому проверим разумную верхнюю границу, например 0..100
        if (k < 0 || k > 200) {
            std::cerr << "Recovered symbol index out of range: " << k << "\n";
            return 0;
        }

        char ch = (char)('a' + k);
        std::cout << ch;
    }
    std::cout << "\n";
    return 0;
}
