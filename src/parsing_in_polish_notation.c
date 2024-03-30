#include <stdio.h> // Подключение стандартной библиотеки ввода-вывода

#include "mystack.h" // Подключение заголовочного файла с определением структуры стека

void parsing_in_polish_notation(struct st *operations, char *input_str, char *output_str) {
 int point; // Индекс для записи в output_str
 point = 0; // Инициализация индекса
 for (int i = 0; input_str[i] != '\0'; i++) { // Цикл по символам входной строки
    if (input_str[i] == ')') { // Если встречается закрывающая скобка
      while ((operations->c) != '(') // Пока верхний элемент стека не открывающая скобка
        output_str[point++] = delete (&operations); // Выводим операторы из стека в output_str
      delete (&operations); // Удаляем открывающую скобку из стека
    }
    if ((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == 'x') // Если символ - число или 'x'
      output_str[point++] = input_str[i]; // Добавляем его в output_str
    // Обработка операторов 'sin', 'cos', 'tg', 'ctg', 'sqrt', 'ln'
    // Пример для 'sin':
    if (input_str[i] == 's' && input_str[i + 1] == 'i' && input_str[i + 2] == 'n') {
      // Проверка приоритета и добавление оператора в стек
      if (operations == NULL) {
        operations = push(operations, 's');
      } else if (priority(operations->c) < priority('s'))
        operations = push(operations, 's');
      else {
        while ((operations != NULL) && (priority(operations->c) >= priority('s')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 's');
      }
      i += 3; // Пропускаем обработанные символы
    }
    // Аналогично обрабатываются остальные операторы
    if (input_str[i] == 'c' && input_str[i + 1] == 'o' &&
        input_str[i + 2] == 's') {
      if (operations == NULL)
        operations = push(operations, 'c');
      else if (priority(operations->c) < priority('c'))
        operations = push(operations, 'c');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('c')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'c');
      }
      i += 3;
    }
    if (input_str[i] == 't' && input_str[i + 1] == 'g') {
      if (operations == NULL)
        operations = push(operations, 't');
      else if (priority(operations->c) < priority('t'))
        operations = push(operations, 't');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('t')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 't');
      }
      i += 2;
    }
    if (input_str[i] == 'c' && input_str[i + 1] == 't' &&
        input_str[i + 2] == 'g') {
      if (operations == NULL)
        operations = push(operations, 'g');
      else if (priority(operations->c) < priority('g'))
        operations = push(operations, 'g');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('g')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'g');
      }
      i += 3;
    }
    if (input_str[i] == 's' && input_str[i + 1] == 'q' &&
        input_str[i + 2] == 'r' && input_str[i + 3] == 't') {
      if (operations == NULL)
        operations = push(operations, 'q');
      else if (priority(operations->c) < priority('q'))
        operations = push(operations, 'q');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('q')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'q');
      }
      i += 4;
    }
    if (input_str[i] == 'l' && input_str[i + 1] == 'n') {
      if (operations == NULL)
        operations = push(operations, 'l');
      else if (priority(operations->c) < priority('l'))
        operations = push(operations, 'l');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('l')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'l');
      }
      i += 2;
    }
    if (input_str[i] == '(') operations = push(operations, '('); // Добавление открывающей скобки в стек
    // Обработка арифметических операторов '+', '-', '*', '/'
    if (input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '/' || input_str[i] == '*') {
      // Проверка приоритета и добавление оператора в стек
      if (operations == NULL)
        operations = push(operations, input_str[i]);
      else if (priority(operations->c) < priority(input_str[i]))
        operations = push(operations, input_str[i]);
      else {
        while ((operations != NULL) && (priority(operations->c) >= priority(input_str[i])))
          output_str[point++] = delete (&operations);
        operations = push(operations, input_str[i]);
      }
    }
 }

 while (operations != NULL) output_str[point++] = delete (&operations); // Вывод оставшихся операторов из стека
 output_str[point] = '\0'; // Добавление нулевого символа в конец output_str
}
