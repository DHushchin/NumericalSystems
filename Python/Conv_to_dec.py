def max_system():
    """Инициалищируем значения максимально возможной системы счисления"""

    system = []  # создаем список 0-9, A-Z
    for i in range(0, 10):  # номера символов в ASCII
        system.append(str(i))
    for i in range(65, 91):
        system.append(chr(i))
    return system


def letter_to_digit(initial_num):
    """Функция преобразует буквенные значения в числовые"""

    system = max_system()
    for i in range(len(initial_num)):
        for j in range(len(system)):
            if initial_num[i] == system[j]:
                initial_num[i] = int(j)
    return initial_num


def number_init():
    """Проверка корректности введенного числа"""

    init_num = [value for value in input("\nВведите число: ")]  # вводим число и поэлементно разбиваем
    digit_init_num = letter_to_digit(init_num)

    for digit in digit_init_num:
        if not str(digit).isdigit() or int(digit) >= base:
            return number_init()

    print("Введенное число корректно")
    return digit_init_num


def conv_to_dec(digital_initial_num, initial_base):
    """Функция перевода числа в десятичную систему счисления"""

    counter = 0
    decimal_num = 0
    for i in range(len(digital_initial_num) - 1, -1, -1):
        decimal_num += digital_initial_num[i] * (initial_base ** counter)
        counter += 1  # увеличиваем разряд числа(единицы, десятки, сотни и т.д.)
    print("\nЧисло в десятичной системе: ", decimal_num)
    return decimal_num


def dec_to_any(decimal_num, result_base):
    """Функция перевода числа в заданную систему счисления"""

    res = []  # создаем результирующий список
    while decimal_num > 0:
        res.append(decimal_num % result_base)  # заполняем список числами нужной нам системы счисления
        decimal_num //= res_base
    res.reverse()  # переворачиваем список
    return res


def digit_to_letter(res):
    """Функция преобразует числовые значения в буквенные"""

    system = max_system()
    for i in range(len(res)):
        for j in range(len(system)):
            if res[i] == j:
                res[i] = system[j]
    return res


base = int(input("Введите систему исчисления: "))  # ввод системы счисления
while (base < 2) or (base > 36):  # проверка корректности введенной системы счисления
    base = int(input("Введите корректную систему счисления: "))

digit_init_num = number_init()

res_base = int(input("\nВведите результирующую систему счисления: "))  # ввод результирующей системы счисления
while (res_base < 2) or (res_base > 36):  # проверка корректности введенной системы счисления
    res_base = int(input("Введите корректную систему счисления: "))

dec_num = conv_to_dec(digit_init_num, base)

if res_base == 10:
    print(f"\nЧисло в {res_base}-ой системе счисления: {dec_num}")
else:
    result = dec_to_any(dec_num, res_base)
    result = digit_to_letter(result)
    print(f"\nЧисло в {res_base}-ой системе счисления: ", ''.join(result))

input("Press any key to continue")
