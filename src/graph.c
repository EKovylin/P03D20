#include <math.h> // Включает математические функции
#include <stdio.h> // Включает функции ввода-вывода
#include <stdlib.h> // Включает функции для работы с памятью

#include "calculation.h" // Включает заголовочный файл с функциями для расчетов
#include "draw.h" // Включает заголовочный файл с функциями для рисования
#include "mystack.h" // Включает заголовочный файл с функциями для работы со стеком

int main() {
 char **graph = calloc_matrix(HEIGHT, WIDTH + 1); // Выделяет память под двумерный массив символов для графика
 struct st *operations = NULL; // Инициализирует указатель на структуру для операций как NULL
 char input_string[80], output_string[80]; // Объявляет массивы символов для входной и выходной строк
 fflush(stdin); // Очищает буфер ввода
 fgets(input_string, 80, stdin); // Читает строку из стандартного ввода
 parsing_in_polish_notation(operations, input_string, output_string); // Парсит входную строку в обратную польскую нотацию
 printf("\n%s\n", output_string); // Выводит результат парсинга
 fflush(stdin); // Очищает буфер ввода
 HEAD head; // Объявляет переменную для работы со стеком
 init(&head); // Инициализирует стек
 init_graph(graph, HEIGHT, WIDTH); // Инициализирует график
 add_func_for_graph(graph, HEIGHT, WIDTH, output_string, &head); // Добавляет функции для графика
 draw_graph(graph, HEIGHT); // Рисует график
 free_matrix(graph, HEIGHT); // Освобождает память, выделенную под график
 return 0; // Возвращает 0, указывая на успешное завершение программы
}
