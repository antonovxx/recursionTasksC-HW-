//Recursion
//I. Реализовать следующие рекурсивные функции для работы с одномерными динамическими массивами:
//    1. Поиск минимума
//    2. Поиск максимума
//    3. Поиск суммы элементов массива
//    4. Поиск произведения элементов массива
//    5. Проверка наличия элемента в массиве. Возвращает true, если элемент в массиве есть, false – нет.
//    6. Печать массива на экран
//    7. Подсчёт количества отрицательных элементов массива
//    8. Подсчёт количества вхождений элемента в массив
//    9. Подсчёт количества чётных элементов в массив
//    10. Подсчёт количества положительных элементов в массиве
//    11. Подсчёт количества нечётных элементов в массиве
//II. Реализовать следующие рекурсивные функции:
//     1. Функцию, которая вычисляет число a в степени n
//     2. Функцию, которая вычисляет факториал числа n
//     3. Функцию, которая вычисляет сумму цифр произвольного целого числа n
//III. Реализовать следующие рекурсивные функции для работы со строками:
//     1. Подсчитать длину строки
//     2. Подсчитать количество слов в строке
//     3. Перевести строку в верхний регистр
//     4. Перевести строку в нижний регистр
//     5. Проверить вхождение указанного символа в строку
//     6. Подсчитать количество вхождений указанного символа в строку
//IV. Для всех указанных выше функций написать проверки в main, то есть вызывать каждую из функций внутри main с какими-то данными введёнными с клавиатуры. main может содержать только вводы данных и вызовы функций, никакую логику main содержать не может.

#include <iostream>
#include <ctime>
//#define RECURSION_ARRAYS_PART_1
//#define RECURSION_NUMBERS_PART_2
#define RECURSION_STRINGS_PART_3

void fillingArray(int* array, int size);
void recursionPrintArray(int* array, int size);
int minValue(int* array, int size, int min);
int maxValue(int* array, int size, int max);
int sumElements(int* array, int size, int &sum);
int multiplicationElements(int* array, int size, int mul);
bool checkElement(int* array, int size, int element);
int countNegative(int* array, int size, int count);
int countEntries(int* array, int size, int element, int count);
int countEvens(int* array, int size, int count);
int countPositive(int* array, int size, int count);
int countNotEvens(int* array, int size, int count);
int Power(int number, int degree);
int Factorial(int number);
int SumDigitsInNumber(int number);
int StrLength(char* string, int size, int count);
int CountWords(char* string, int size, int count);
void StrUpper(char* string);
void StrLower(char* string);
bool checkElement(char* string, int element);
int countEntries(char* string, int count, int element);

int main()
{
    using namespace std;
    srand(time(NULL));
    
#ifdef RECURSION_ARRAYS_PART_1
    
    int size = 10;
    int array[size]; fillingArray(array, size);
    
    int min = array[0];
    int max = array[0];
    int sum = 0;
    int mul = 1;
    int element;
    int count = 0;
    
    cout << "Array: " << " "; recursionPrintArray(array, size);
    cout << "Enter element: "; cin >> element;


    cout << "Recursion min value: " << minValue(array, size, min) << endl;
    cout << "Recursion max value: " << maxValue(array, size, max) << endl;
    cout << "Sum of elements: " << sumElements(array, size, sum) << endl;
    cout << "Multiplication elements: " << multiplicationElements(array, size, mul) << endl;
    cout << "Checking element: " << checkElement(array, size, element) << endl;
    cout << "Count of negative: " << countNegative(array, size, count) << endl;
    cout << "Count of entries of element: " << countEntries(array, size, element, count) << endl;
    cout << "Count of even elements: " << countEvens(array, size, count) << endl;
    cout << "Count of positive numbers: " << countPositive(array, size, count) << endl;
    cout << "Count of not even elements: " << countNotEvens(array, size, count) << endl;
 
#endif
#ifdef RECURSION_NUMBERS_PART_2
    
    int number;
    int degree;
    cout << "Enter number and degree: "; cin >> number;
    cin >> degree;
    
    cout << "Exponentiation: " << Power(number, degree) << endl;
    cout << "Factorial: " << Factorial(number) << endl;
    cout << "Sum digits of the number: " << SumDigitsInNumber(number) << endl;
    
#endif
#ifdef RECURSION_STRINGS_PART_3
    
    const int size = 20;
    char string[size];
    
    cout << "Enter the string: "; cin.getline(string, size);
    cout << "The string: " << string << endl;
    
    int count = 0;
    cout << "Length of the string: " << StrLength(string, size, count) << endl;
    cout << "Number of words in the string: " << CountWords(string, size, count) << endl;
    StrUpper(string);
    cout << "Upper string: " << string << endl;
    StrLower(string);
    cout << "Lower string: " << string << endl;
    
    char element;
    cout << "Enter element: "; cin >> element;
    if(checkElement(string, element))
        cout << "This element is in the string" << endl;
    else
        cout << "This element is not in the string" << endl;
    
    cout << "Number of entries of this element: " << countEntries(string, count, element) << endl;
    
    
#endif
    
    return 0;
    
}
void fillingArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % (10 + 10) - 10;
    }
}

void recursionPrintArray(int* array, int size)
{
    
    while(size != 0)
    {
        std::cout << *(array) << " ";
        return recursionPrintArray(array + 1, size - 1);
    }
}


int minValue(int *array, int size, int min)
{
   if(size == 1)
       return min;
    if(min > array[size - 1])
        min = array[size - 1];
    return minValue(array, size - 1, min);
}


int maxValue(int *array, int size, int max)
{
    if(size == 1)
        return max;
    if(max < array[size - 1])
        max = array[size - 1];
    return maxValue(array, size - 1, max);
}

int sumElements(int* array, int size, int &sum)
{
    if(size == 0)
        return sum;
    sum += array[size - 1];
    return sumElements(array, size - 1, sum);
}

int multiplicationElements(int* array, int size, int mul)
{
    if(size == 0)
        return mul;
    mul *= array[size - 1];
    return multiplicationElements(array, size - 1, mul);
}

bool checkElement(int* array, int size, int element)
{
    if(element == array[size])
        return true;
    if(size == 0 && element != array[size])
        return false;
    return checkElement(array, size - 1, element);
}
int countNegative(int* array, int size, int count)
{
    while(size != 0)
    {
        if(array[size - 1] < 0)
            count ++;
        return countNegative(array, size - 1, count);
    }
    return count;
}
int countEntries(int* array, int size, int element, int count)
{
    while(size != 0)
    {
        if(element == array[size - 1])
            count ++;
        return countEntries(array, size - 1, element, count);
    }
    return count;
}
int countEvens(int* array, int size, int count)
{
    while(size != 0)
    {
        if(array[size - 1] % 2 == 0)
            count ++;
        return countEvens(array, size - 1, count);
    }
    return count;
}
int countPositive(int* array, int size, int count)
{
    while(size != 0)
    {
        if(array[size - 1] > 0)
            count++;
        return countPositive(array, size - 1, count);
    }
    return count;
}
int countNotEvens(int* array, int size, int count)
{
    while(size != 0)
    {
        if(array[size - 1] % 2 != 0)
            count ++;
        return countNotEvens(array, size - 1, count);
    }
    return count;
}
int Power(int number, int degree)
{
    if(degree == 0)
        return 1;
    return number * Power(number, degree - 1);
}

int Factorial(int number)
{
    if(number > 1)
        return number * Factorial(number - 1);
    return 1;
}

int SumDigitsInNumber(int number)
{
    if(number > 0)
        return (number % 10) + SumDigitsInNumber(number / 10);
    return 0;
}
int StrLength(char* string, int size, int count)
{
    while(*string != '\0')
    {
        count++;
        return StrLength(string + 1, size, count);
    }
    return count;
}
int CountWords(char* string, int size, int count)
{
    while(*string != '\0')
    {
        if(*string == ' ')
            count++;
        return CountWords(string + 1, size, count);
    }
    count ++;
    return count;
}
void StrUpper(char* string)
{
    while(*string != '\0')
    {
        if(*string >= 'a' && *string <= 'z')
            *string -= 32;
        return StrUpper(string + 1);
    }
}
void StrLower(char* string)
{
    while(*string != '\0')
    {
        if(*string >= 'A' && *string <= 'Z')
            *string += 32;
        return StrLower(string + 1);
    }
}
bool checkElement(char* string, int element)
{
    while(*string != '\0')
    {
        if (*string == element)
            return true;
        return checkElement(string + 1, element);
    }
    return false;
}
int countEntries(char* string, int count, int element)
{
    while(*string != '\0')
    {
        if(*string == element)
            count ++;
        return countEntries(string + 1, count, element);
    }
    return count;
}


