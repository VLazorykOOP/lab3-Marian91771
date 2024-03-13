// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include <iomanip>
using namespace std;

/*

class Time {

private:
    int hour;
    int minute;
    int second;

public:
    // Конструктор за замовчуванням
    Time() : hour(0), minute(0), second(0) {}

    // Конструктор з параметрами
    Time(int h, int m, int s) {
        setHour(h);
        setMinute(m);
        setSecond(s);
    }

    // Функція встановлення години
    void setHour(int h) {
        if (h >= 0 && h <= 23)
            hour = h;
        else
            cerr << "\nInvalid hour value!\n\n";
    }

    // Функція встановлення хвилини
    void setMinute(int m) {
        if (m >= 0 && m <= 59)
            minute = m;
        else
            cerr << "\nInvalid minute value!\n\n";
    }

    // Функція встановлення секунди
    void setSecond(int s) {
        if (s >= 0 && s <= 59)
            second = s;
        else
            cerr << "\nInvalid second value!\n\n";
    }

    // Функції отримання години, хвилини та секунди
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    // Функція друку за шаблоном "16 годин 18 хвилин 3 секунди"
    void printTime() const {
        cout << setw(2) << setfill('0') << hour << " годин "
            << setw(2) << setfill('0') << minute << " хвилин "
            << setw(2) << setfill('0') << second << " секунд ";
    }

    // Функція друку за шаблоном "4 p.m. 18 хвилин 3 секунди"
    void printTimeAMPM() const {
        int h = hour;
        string am_pm = "a.m.";
        if (h >= 12) {
            am_pm = "p.m.";
            if (h > 12)
                h -= 12;
        }
        if (h == 0) // 12 годин ночі вважаються 12 годинами p.m.
            h = 12;
        cout << setw(1) << h << " " << am_pm << " "
            << setw(2) << setfill('0') << minute << " хвилин "
            << setw(2) << setfill('0') << second << " секунд ";
    }
};

void main() {

    setlocale(LC_CTYPE, "Ukr");
    
    Time t1; // Створення об'єкта за замовчуванням
    Time t2(16, 18, 3); // Створення об'єкта з параметрами

    int h, m, s;

    cout << "setHour: "; cin >> h;
    cout << "setMinute: "; cin >> m;
    cout << "setSecond: "; cin >> s;

    t2.setHour(h);
    t2.setMinute(m);
    t2.setSecond(s);



    cout << "Час t1: ";
    t1.printTime();
    cout << endl;

    cout << "Час t2: ";
    t2.printTime();
    cout << endl;

    cout << "Час t1 (12-годинний формат): ";
    t1.printTimeAMPM();
    cout << endl;

    cout << "Час t2 (12-годинний формат): ";
    t2.printTimeAMPM();
    cout << endl;

}
/////////////////////////

*/


class Vector {
private:
    float* data;
    int size;
    int state; // 0 - ok, 1 - memory allocation error, 2 - out of bounds

public:
    // Конструктор без параметрів
    Vector() : size(1), state(0) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else
            data[0] = 0.0f;
    }

    // Конструктор з одним параметром - розміром вектора
    Vector(int s) : size(s), state(0) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = 0.0f;
        }
    }

    // Конструктор із двома параметрами - розміром вектора та значенням ініціалізації
    Vector(int s, float init_value) : size(s), state(0) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = init_value;
        }
    }

    // Конструктор копії
    Vector(const Vector& other) : size(other.size), state(other.state) {
        data = new float[size];
        if (data == nullptr)
            state = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            state = other.state;
            data = new float[size];
            if (data == nullptr)
                state = 1;
            else {
                for (int i = 0; i < size; ++i)
                    data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Функція, яка присвоює елементу масиву деяке значення
    void setElement(int index, float value = 0.0f) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            state = 2;
            throw std::out_of_range("Index out of bounds");
        }
    }

    // Функція, яка повертає деякий елемент масиву
    float getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            int state = 2;
            throw std::out_of_range("Index out of bounds");
        }
    }

    // Функція друку
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Функція додавання
    Vector operator+(const Vector& other) const {
        if (size != other.size) {
            int state = 2;
            throw std::invalid_argument("Vector sizes don't match");
        }
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Функція віднімання
    Vector operator-(const Vector& other) const {
        if (size != other.size) {
            int state = 2;
            throw std::invalid_argument("Vector sizes don't match");
        }
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Функція множення на ціле число
    Vector operator*(long scalar) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Функції порівняння
    bool operator==(const Vector& other) const {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Vector sizes don't match for comparison");
        for (int i = 0; i < size; ++i) {
            if (data[i] >= other.data[i])
                return false;
        }
        return true;
    }

    bool operator>(const Vector& other) const {
        if (size != other.size)
            throw std::invalid_argument("Vector sizes don't match for comparison");
        for (int i = 0; i < size; ++i) {
            if (data[i] <= other.data[i])
                return false;
        }
        return true;
    }

    bool operator<=(const Vector& other) const {
        return (*this == other || *this < other);
    }

    bool operator>=(const Vector& other) const {
        return (*this == other || *this > other);
    }

    // Функція для отримання стану вектора
    int getState() const {
        return state;
    }

    // Функція для отримання кількості об'єктів даного типу
    static int getCount() {
        // Реалізуйте потрібний код для підрахунку об'єктів
    }
};

int main() {
    try {
        Vector v1(3, 1.5f);
        Vector v2(3, 2.5f);

        // Перевірка функції додавання
        Vector sum = v1 + v2;
        sum.print();

        // Перевірка функції віднімання
        Vector diff = v1 - v2;
        diff.print();

        // Перевірка функції множення на ціле число
        Vector mult = v1 * 2;
        mult.print();

        // Перевірка функцій порівняння
        std::cout << (v1 == v2) << std::endl;
        std::cout << (v1 != v2) << std::endl;
        std::cout << (v1 < v2) << std::endl;
        std::cout << (v1 > v2) << std::endl;
        std::cout << (v1 <= v2) << std::endl;
        std::cout << (v1 >= v2) << std::endl;

        // Перевірка вибросу виключення при виході за межі масиву
        std::cout << v1.getElement(5) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

