#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int base_init(void);
int* num_init(int, int&);
int conv_to_dec(int, int*, int&);
int res_base_init(void);
void dec_to_any(int, int&, int, int*);
string output_init(int, int*);

int main() {
    setlocale(LC_ALL, "Russian");
    int base = base_init();
    int len = 0;
    int* number = num_init(base, len);
    int dec = conv_to_dec(base, number, len);
    int res_base = res_base_init();
    if (res_base == 10)
        cout << dec;
    else
    {
        int result[100];
        int* ptr = result;
        int number_length = 0;
        dec_to_any(dec, number_length, res_base, ptr);
        for (int i = 0; i < number_length / 2; ++i) {
            int tmp = result[i];
            result[i] = result[number_length - i - 1];
            result[number_length - i - 1] = tmp;
        }
        string output = output_init(number_length, ptr);
        cout << "Число в " << res_base << "-ой системе счисления = " << output;
    }
    system("pause>>void");
    return 0;
}

int base_init() {
    int base;
    cout << "Введите систему исчисления: "; cin >> base;
    if (base < 2 or base > 16) {
        cout << "INCORRECT INPUT" << endl;
        return base_init();
    }
    else
        return base;
}

int res_base_init() {
    int res_base;
    cout << "Введите результирующую систему исчисления: "; cin >> res_base;
    if (res_base < 2 or res_base > 16) {
        cout << "INCORRECT INPUT" << endl;
        return res_base_init();
    }
    else
        return res_base;
}

int* num_init(int num_base, int& len) {
    string init_num;
    cout << "Введите число: "; cin >> init_num;
    len = init_num.length();
    int letter_to_digit(char, int);
    int* arr = new int[len];
    for (int i = 0; i < len; i++)
    {
        int tmp = letter_to_digit(init_num[i], num_base);
        if (tmp >= num_base)
            return num_init(num_base, len);
        else
            arr[i] = tmp;;
    }
    return arr;
}

int letter_to_digit(char digit, int base) {
    int result;
    switch (digit) {
    case '0': result = 0; break;
    case '1': result = 1; break;
    case '2': result = 2; break;
    case '3': result = 3; break;
    case '4': result = 4; break;
    case '5': result = 5; break;
    case '6': result = 6; break;
    case '7': result = 7; break;
    case '8': result = 8; break;
    case '9': result = 9; break;
    case 'A': result = 10; break;
    case 'B': result = 11; break;
    case 'C': result = 12; break;
    case 'D': result = 13; break;
    case 'E': result = 14; break;
    case 'F': result = 15; break;
    default: {cout << "INCORRECT INPUT" << endl;
        exit(0); }
    }
    return result;
}

int conv_to_dec(int base, int* number, int& len) {
    int dec = 0;
    int counter = 0;
    for (int i = len - 1; i >= 0; i--) {
        dec += *(number + i) * pow(base, counter);
        counter++;
    }
    cout << "dec: " << dec << endl;
    return dec;
}

char digit_to_letter(int result) {
    char digit;
    switch (result) {
    case 0: digit = '0'; break;
    case 1: digit = '1'; break;
    case 2: digit = '2'; break;
    case 3: digit = '3'; break;
    case 4: digit = '4'; break;
    case 5: digit = '5'; break;
    case 6: digit = '6'; break;
    case 7: digit = '7'; break;
    case 8: digit = '8'; break;
    case 9: digit = '9'; break;
    case 10: digit = 'A'; break;
    case 11: digit = 'B'; break;
    case 12: digit = 'C'; break;
    case 13: digit = 'D'; break;
    case 14: digit = 'E'; break;
    case 15: digit = 'F'; break;
    }
    return digit;
}

void dec_to_any(int dec, int& number_length, int res_base, int* ptr) {
    do
    {
        *ptr = dec % res_base;
        dec /= res_base;
        ptr++;
        number_length++;
    } while (dec != 0);
}

string output_init(int number_length, int* ptr) {
    string output;
    char digit_to_letter(int);
    for (int i = 0; i < number_length; i++) {
        output += digit_to_letter(*(ptr + i));
    }
    return output;
}

