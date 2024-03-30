#ifndef CALCULATION_H_ // Проверка на наличие определения CALCULATION_H_, чтобы избежать повторного включения
#define CALCULATION_H_ // Определение CALCULATION_H_, чтобы предотвратить повторное включение

typedef struct OPERATIONS { // Определение структуры OPERATIONS
 double oper; // Переменная для хранения операции (например, числа или результат операции)
 struct OPERATIONS *point; // Указатель на следующую операцию в списке
} OPERATIONS; // Завершение определения структуры OPERATIONS

typedef struct HEAD { // Определение структуры HEAD
 struct OPERATIONS *point; // Указатель на первую операцию в списке
} HEAD; // Завершение определения структуры HEAD

double counter(char *output_str, HEAD *head, double x); // Функция для обработки выражения и вычисления результата
void init(HEAD *head); // Функция для инициализации структуры HEAD
void pushing(double sym, HEAD *head); // Функция для добавления новой операции в список
double pop(HEAD *head); // Функция для извлечения и возврата последней операции из списка
void add_func_for_graph(char **graph, int height, int width, char *out, HEAD *head); // Функция для добавления графика в вывод

#endif // CALCULATION_H_ // Завершение блока защиты от повторного включения
