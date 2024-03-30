#include "calculation.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"

double counter(char *output_str, HEAD *head, double x) {
 // Определение длины строки output_str
 int n = strlen(output_str);
 // Объявление переменных для хранения чисел
 double num1, num2;
 // Цикл по каждому символу в строке
 for (int i = 0; i < n; ++i) {
    // Если символ равен 'x', добавляем значение x в стек
    if (output_str[i] == 'x') {
      pushing(x, head);
    } 
    // Если символ является цифрой, добавляем его значение в стек
    else if (output_str[i] >= '0' && output_str[i] <= '9') {
      pushing((output_str[i] - '0'), head);
    } 
    // Если символ равен '+', выполняем операцию сложения
    else if (output_str[i] == '+') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 + num2, head);
    } 
    // Если символ равен '-', выполняем операцию вычитания
    else if (output_str[i] == '-') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 - num2, head);
    } 
    // Если символ равен '*', выполняем операцию умножения
    else if (output_str[i] == '*') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 * num2, head);
    } 
    // Если символ равен '/', выполняем операцию деления
    else if (output_str[i] == '/') {
      num2 = pop(head);
      num1 = pop(head);
      if (num2 != 0)
        pushing(num1 / num2, head);
      else
        pushing(1000, head); // Возвращаем 1000, если деление на ноль
    } 
    // Если символ равен '^', выполняем операцию возведения в степень
    else if (output_str[i] == '^') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(pow(num1, num2), head);
    } 
    // Если символ равен 's', применяем функцию синуса
    else if (output_str[i] == 's') {
      num1 = pop(head);
      pushing(sin(num1), head);
    } 
    // Если символ равен 'c', применяем функцию косинуса
    else if (output_str[i] == 'c') {
      num1 = pop(head);
      pushing(cos(num1), head);
    } 
    // Если символ равен 't', применяем функцию тангенса
    else if (output_str[i] == 't') {
      num1 = pop(head);
      pushing(tan(num1), head);
    } 
    // Если символ равен 'g', применяем функцию котангенса
    else if (output_str[i] == 'g') {
      num1 = pop(head);
      pushing(1 / tan(num1), head);
    } 
    // Если символ равен 'q', применяем функцию квадратного корня
    else if (output_str[i] == 'q') {
      num1 = pop(head);
      pushing(sqrt(num1), head);
    } 
    // Если символ равен 'l', применяем функцию логарифма
    else if (output_str[i] == 'l') {
      num1 = pop(head);
      pushing(log(num1), head);
    }
 }
 // Возвращаем результат вычислений из стека
 return pop(head);
}


// Инициализация головы стека
void init(HEAD *head) {
 head->point = NULL; // Устанавливаем указатель на следующий элемент в стеке как NULL, что означает пустой стек
}

// Добавление элемента в стек
void pushing(double sym, HEAD *head) {
 OPERATIONS *tmp; // Создаем временный указатель на элемент стека
 tmp = head->point; // Сохраняем текущий указатель на вершину стека
 OPERATIONS *new = (OPERATIONS *)malloc(sizeof(OPERATIONS)); // Выделяем память под новый элемент стека
 new->oper = sym; // Присваиваем значение символа новому элементу стека
 new->point = tmp; // Устанавливаем указатель на следующий элемент стека как текущий верхний элемент
 head->point = new; // Обновляем указатель на вершину стека, указывая на новый элемент
}

// Извлечение элемента из стека
double pop(HEAD *head) {
 double x; // Переменная для хранения извлеченного значения
 OPERATIONS *tmp = head->point; // Сохраняем текущий верхний элемент стека
 x = head->point->oper; // Извлекаем значение из верхнего элемента стека
 head->point = head->point->point; // Обновляем указатель на вершину стека, указывая на следующий элемент
 free(tmp); // Освобождаем память, выделенную под извлеченный элемент
 return x; // Возвращаем извлеченное значение
}

// Функция для добавления функции в граф
void add_func_for_graph(char **graph, int height, int width, char *out, HEAD *head) {
 for (int y = 0; y < height; y++) { // Проходим по всем строкам графа
    for (int x = 0; x < width; x++) { // Проходим по всем столбцам графа
      int y = 25; // Переопределение переменной y, что является ошибкой, так как переменная y уже определена в цикле
      if (x != 0) y = round(12 + 12 * counter(out, head, (M_PI * x) / 20)); // Вычисляем новое значение y, если x не равно 0
      if (y > 0 && y < 25) graph[y][x] = STAR; // Если y находится в диапазоне от 1 до 24, устанавливаем символ STAR в соответствующую ячейку графа
    }
 }
}
