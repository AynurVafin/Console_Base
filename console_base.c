#include <stdio.h>
#include <conio.h>
#include<malloc.h>
#include<windows.h>
#include<string.h>

//Структура, описывающая объект рассматриваемой предметной области
struct computer{
char company[200];
char model[200];
char processor[200];
int RAM;
int price;
};

//Добавление в конец базы данных
void add(computer *new_add, int* n) {
char sym;
system("cls");
gotoxy(1, 1);
	textcolor(6);
cputs("Введите данные компьютера в формате (После каждого пункта нажмите \"Enter\"):");
gotoxy(1, 2);
cputs("Компания   Mодель   Процессор   ОЗУ(в ГБ)   Цену(в руб.)");
printf("\n");
fgets(new_add[*n].company, 200, stdin);
fgets(new_add[*n].model, 200, stdin);
fgets(new_add[*n].processor, 200, stdin);
while(scanf("%i%c", &new_add[*n].RAM, &sym) != 2 || sym != '\n' || new_add[*n].RAM<=0){
system("cls");
	textcolor(6); gotoxy(1, 1);
cputs("Вы ввели ОЗУ неверно, пожалуйста, повторите"); // color
gotoxy(1, 3);
cputs("Введите данные компьютера в формате (После каждого пункта нажмите \"Enter\"):");
gotoxy(1, 4);
cputs("Компания   Mодель   Процессор   ОЗУ(в ГБ)   Цену(в руб.)");
printf("\n%s %s %s ", new_add[*n].company, new_add[*n].model,new_add[*n].processor);
}
while(scanf("%i%c", &new_add[*n].price, &sym)!= 2 || new_add[*n].price<0 ||(sym != '\n' && sym != EOF)){
 system("cls");
	textcolor(6); gotoxy(1, 1);
cputs("Вы ввели Цену неверно, пожалуйста, повторите"); // color
gotoxy(1, 3);
cputs("Введите данные компьютера в формате (После каждого пункта нажмите \"Enter\"):");
gotoxy(1, 4);
cputs("Компания   Mодель   Процессор   ОЗУ(в ГБ)   Цену(в руб.)");
printf("\n%s %s %s %i ", new_add[*n].company, new_add[*n].model,new_add[*n].processor, new_add[*n].RAM);
}
(*n)+= 1;
}

// Вывод данных по передающейся базы данных
void output(computer *output_data, int n) {
system("cls");
if (n == 0) {
	textcolor(6);
	   gotoxy(1, 1);
		cputs("База данных пуста!");
			textcolor(3);
	   gotoxy(1, 3);
 cputs("(Для продолжения нажмите на любую клавишу)");
 getch();
	return;
}
textcolor(6);
gotoxy(1, 1);
cprintf("База данных содержит:");
gotoxy(1, 3);
for(int i = 0; i<100;i++)printf("-");
printf("\n");
for (int i = 0; i < n; i++) {
printf("\nЗапись № %i\n\nКомпания: %s\nМодель: %s\nПроцессор: %s\nОЗУ: %i ГБ\n\nЦена: %i руб.\n\n", i+1,output_data[i].company,
output_data[i].model, output_data[i].processor, output_data[i].RAM, output_data[i].price);
for(int i = 0; i<100;i++)printf("-");
printf("\n");
}
textcolor(6);
puts("\n(Для продолжения нажмите на любую клавишу)");
getch();
}

//Функция удаления одного элемента
void delete_function(computer * delete_pc, int*n, int index) {
	 for (int i = index; i < *n-1 ;i++) {
		 delete_pc[i] = delete_pc[i+1];
	 }
	 *n = *n - 1;
}

// меню по удалению данных
void menu_delete(computer * delete_pc, int * n) {
int line = 0, index; char sym;
	char men_del[][100] = {{"Удалить запись"}, {"Удалить всё"}, {"Вернуться в меню"}};
	while(1) {
	line = ((line%3)+3)%3;
	system("cls");
	gotoxy(1, 1);
	textcolor(6);
	cputs("Выберите удаление");
	gotoxy(1, 3);
	textcolor(3);
	cputs("-----------------");
	for (int i = 0; i < 3; i++) {
		if (i == line) textcolor(7);
		else textcolor(2);
		gotoxy(1, 5+i);
		cputs(men_del[i]);
	}
    	textcolor(3);
	gotoxy(1, 13);
	cprintf("---------------------------");
	gotoxy(1, 15);
   cputs("\"Используй для передвижения стрелки вниз или верх\"");
   gotoxy(1, 16);
   cputs("\"Для выбора нажмите \"Enter\"\"");
	int key = getch();
	if (key == 0) {
		key = getch();
		switch(key) {
			case 72: line--;  break;
			case 80: line++; break;
		}
	} else if (key == 13) {
		if (line != 2 &&*n == 0) {system("cls");
		textcolor(6);
	   gotoxy(1, 1);
		cputs("База данных пуста!");
			textcolor(3);
	   gotoxy(1, 3);
 cputs("(Для продолжения нажмите на любую клавишу)");
 getch();
	return;
	}
		switch(line) {
			case 0: system("cls"); gotoxy(1, 1);
				textcolor(6); cprintf("Какую запись хотите удалить? (Всего %i записей)", *n); gotoxy(1, 2);
				 while(scanf("%i%c", &index, &sym)!= 2 || index<1 || index>*n ||(sym != ' ' && sym != '\n' && sym != EOF)) {
				   system("cls");   gotoxy(1, 1); textcolor(1);
					cprintf("Вы ввели Запись неверно, пожалуйста, повторите.(Всего %i записей)", *n);
					gotoxy(1, 3);
				textcolor(6); cputs("Номер записи, который хотите удалить: ");
				 }  delete_function(delete_pc, n, index -1);
				break;
			case 1: *n = 0; break;
			case 2: return;
		}
	}
	}
}

//Просмотр содержимое бин. файла
void base_computer_output() {
computer time[100];
int n = 0;
	FILE *file = fopen("base_computer", "rb");
	if(file != NULL)
	n = fread(time, sizeof(computer), 100, file);
	fclose(file);
	output(time, n);
}

//Сохранения в бин. файл
void base_computer_save(computer *save_out, int n) {
	FILE *file = fopen("base_computer", "wb");
	fwrite(save_out, sizeof(computer), n, file);
	fclose(file);
}

// Сброс изменения(загрузка данных из бин. файла)
 void base_computer_reset(computer *save_out, int * n) {
	FILE *file = fopen("base_computer", "rb");
	if (file != NULL)
	*n = fread(save_out, sizeof(computer), 100, file);
	else *n = 0;
	fclose(file);
}

//Функция сравнения для сортировки
int comparison(computer first_element, computer second_element, int flag) {
	switch(flag) {
	  case(0): if(strcmp(first_element.company, second_element.company) != 0)
		return strcmp(first_element.company, second_element.company) > 0;
		else
		return comparison(first_element, second_element, flag+1);
	  case(1):
		if(strcmp(first_element.model, second_element.model) != 0)
		return strcmp(first_element.model, second_element.model) > 0;
		else
		return comparison(first_element, second_element, flag+1);
	  case(2):
	  if (strcmp(first_element.processor, second_element.processor) != 0)
		return strcmp(first_element.processor, second_element.processor) > 0;
        else
		return comparison(first_element, second_element, flag+1);
	  case(3):
	  if (first_element.RAM != second_element.RAM)
		return first_element.RAM > second_element.RAM;
		else
		return comparison(first_element, second_element, flag+1);
	  case(4):
		return first_element.price > second_element.price;
	}
}

//Обмен двух элементов( для сотрировки)
void swap(computer *a, computer* b) {
computer t = *(a);
*a = *b;
*b = t;
}

//Быстрая сортировка
void quick_sorting(int L, int R, computer * data, int flag) {
int l = L;
int r = R;
computer mid = data[(L+R)/2];
while (l <= r) {
while(comparison(mid, data[l], flag)) l++;
while(comparison(data[r], mid, flag)) r--;
if(l<=r){ swap(&data[l], &data[r]);
l++; r--;}
}
if (L < r)
quick_sorting(L, (L+R)/2, data, flag);
if (l < R)
quick_sorting((L+R)/2, R, data, flag);
}

// Меню вывода сотировки
void menu_sorting_output(int line) {
	char select_sort[][100] ={"Сортировать по названию компании", "Сортировать по названию модели",
	 "Сортировать по названию процессора", "Сортировать по ОЗУ", "Сортировать по цене", "Вернуться в меню"};
	 textcolor(6);
	cputs("Выберите, пожалуйста сортировку");
	for (int i = 0; i < 6; i++) {
	gotoxy(1, i+5);
		if (line == i) {
			textcolor(7);
		} else textcolor(2);
		cputs(select_sort[i]);
	}
	textcolor(3);
	gotoxy(1, 13);
	cprintf("---------------------------");
	gotoxy(1, 15);

   cputs("\"Используй для передвижения стрелки вниз или верх\"");
   gotoxy(1, 16);
   cputs("\"Для выбора нажмите \"Enter\"\"");
}

//Меню сортировки
void menu_sorting(computer * data, int n) {
int line = 0;
   while(1) {
	   line = (line % 6 + 6) % 6;
	   system("cls");
	   menu_sorting_output(line);
		int key = getch();
		if (key == 0) { key = getch();
		switch(key) {
			case 72: line--; break;
			case 80: line++; break;
		}
		} else {

			if(key == 13)
			switch(line) {
			case 5: return;
			default:  quick_sorting(0, n - 1, data, line);
			 output(data, n);
			break;
		} }
		}
}

// Сравнение для поиска
int comparison_find(computer first_element, computer second_element, int flag) {
	switch(flag) {
	  case(0):
		return strcmp(first_element.company, second_element.company) == 0;
	  case(1):
		return strcmp(first_element.model, second_element.model) == 0;
	  case(2):
		return strcmp(first_element.processor, second_element.processor) == 0;
	  case(3):
		return first_element.RAM == second_element.RAM;
	  case(4):
		return first_element.price == second_element.price;
	}
}

//Поиск элемента
void finding(computer * data, int  n, int flag, computer find_el) {
  computer data_find[100];
  int m = 0;
  for (int i = 0; i < n; i++) {
	  if(comparison_find(data[i], find_el, flag)) {
		  data_find[m++] = data[i];
	  }
  }
output(data_find, m);
}

//Добавочное меню для меню поиска
void mini_menu_finding(computer * data, int  n, int flag) {
	 system("cls"); int past_el; computer data_el;
textcolor(6);  gotoxy(1, 1); char sym;
	 switch(flag) {
		case 0:
		cputs("По какому названию компании хотите найти?");
		gotoxy(1, 3);
		fgets(data_el.company, 200, stdin);
		break;
		case 1:
		cputs("По какому названию модели хотите найти?");
		gotoxy(1, 3);
		fgets(data_el.model, 200, stdin);
		break;
		case 2:
		cputs("По какому названию процессора хотите найти?");
		gotoxy(1, 3);
		fgets(data_el.processor, 200, stdin);
		break;
		case 3:
		cputs("По какому ОЗУ хотите найти?");
		gotoxy(1, 3);
		while(scanf("%i%c", &data_el.RAM, &sym) != 2 || sym != '\n' || data_el.RAM<=0){
system("cls");
	textcolor(6); gotoxy(1, 1);
cputs("Вы ввели ОЗУ неверно, пожалуйста, повторите");
gotoxy(1, 3);
cputs("По какому ОЗУ хотите найти?");
gotoxy(1, 5);
}
		break;
		case 4:
		cputs("По какой цене хотите найти?");
		gotoxy(1, 3);
		while(scanf("%i%c", &data_el.price, &sym) != 2 || sym != '\n' || data_el.price<0){
system("cls");
	textcolor(6); gotoxy(1, 1);
cputs("Вы ввели цену неверно, пожалуйста, повторите"); // color
gotoxy(1, 3);
cputs("По какому ОЗУ хотите найти?");
gotoxy(1, 5);
		}
		break;
	 }
	 finding(data, n, flag, data_el);
}

// Вывод меню поиска
void menu_finding_output(int line) {
	char select_find[][100] ={"Искать по названию компании", "Искать по названию модели",
	 "Искать по названию процессора", "Искать по ОЗУ", "Искать по цене", "Вернуться в меню"};
	 textcolor(6);
	cputs("Выберите, пожалуйста поиск");
	for (int i = 0; i < 6; i++) {
	gotoxy(1, i+5);
		if (line == i) {
			textcolor(7);
		} else textcolor(2);
		cputs(select_find[i]);
	}
	textcolor(3);
	gotoxy(1, 13);
	cprintf("---------------------------");
	gotoxy(1, 15);

   cputs("\"Используй для передвижения стрелки вниз или верх\"");
   gotoxy(1, 16);
   cputs("\"Для выбора нажмите \"Enter\"\"");
}

// Меню поиска
void menu_finding(computer * data, int n) {
int line = 0;
   while(1) {
	   line = (line % 6 + 6) % 6;
	   system("cls");
	   menu_finding_output(line);
		int key = getch();
		if (key == 0) { key = getch();
		switch(key) {
			case 72: line--; break;
			case 80: line++; break;
		}
		} else {

			if(key == 13)
			switch(line) {
			case 5: return;
			default:  mini_menu_finding(data, n, line);
			break;
		} }
		}
}

// Изменение
void change(computer * data, int index, int flag) {
	system("cls"); int past_el;
textcolor(6);  gotoxy(1, 1); char sym;
	 switch(flag) {
		case 0:
		cputs("Название комании на данный момент");
		gotoxy(1, 3);
		printf("%s", data[index].company);
		gotoxy(1, 5);
		cputs("На что хотите поменять?\n");
		gotoxy(1, 7);
		fgets(data[index].company, 200, stdin);
		break;
		case 1:
		cputs("Название модели на данный момент");
		gotoxy(1, 3);
		printf("%s", data[index].model);
		gotoxy(1, 5);
		cputs("На что хотите поменять?\n");
		gotoxy(1, 7);
		fgets(data[index].model, 200, stdin);
		break;
		case 2:
		cputs("Название процессора на данный момент");
		gotoxy(1, 3);
		printf("%s", data[index].processor);
		gotoxy(1, 5);
		cputs("На что хотите поменять?\n");
		gotoxy(1, 7);
		fgets(data[index].processor, 200, stdin);
		break;
		case 3:
		cputs("ОЗУ на данный момент");
		gotoxy(1, 3);
		past_el = data[index].RAM;
		printf("%i", data[index].RAM);
		gotoxy(1, 5);
		cputs("На что хотите поменять?\n");gotoxy(1, 7);
		while(scanf("%i%c", &data[index].RAM, &sym) != 2 || sym != '\n' || data[index].RAM<=0){
system("cls");
	textcolor(6); gotoxy(1, 1);
cputs("Вы ввели ОЗУ неверно, пожалуйста, повторите");
gotoxy(1, 3);
cputs("Название ОЗУ на данный момент");
gotoxy(1, 5);
	printf("%i", past_el);
		gotoxy(1, 7);
		cputs("На что хотите поменять?\n");gotoxy(1, 9);
}
		break;
		case 4:
		cputs("Цена на данный момент");
		gotoxy(1, 3);
		past_el = data[index].price;
		printf("%i", data[index].price);
		gotoxy(1, 5);
		cputs("На что хотите поменять?\n"); gotoxy(1, 7);
		while(scanf("%i%c", &data[index].price, &sym) != 2 || sym != '\n' || data[index].price<0){
system("cls");
	textcolor(6); gotoxy(1, 1);
cputs("Вы ввели Цену неверно, пожалуйста, повторите"); // color
gotoxy(1, 3);
cputs("Название Цену на данный момент");
gotoxy(1, 5);
	printf("%i", past_el);
		gotoxy(1, 7);
		cputs("На что хотите поменять?\n");gotoxy(1, 9);
		}
		break;
	 }
}

// Меню изменения
void output_menu_change(int line) {
	char select_sort[][100] ={"Изменить название компании", "Изменить название модели",
	 "Изменить название процессора", "Изменить ОЗУ", "Изменить цену", "Вернуться в меню"};
	 textcolor(6);
	cputs("Выберите, пожалуйста сортировку");
	for (int i = 0; i < 6; i++) {
	gotoxy(1, i+5);
		if (line == i) {
			textcolor(7);
		} else textcolor(2);
		cputs(select_sort[i]);
	}
	textcolor(3);
	gotoxy(1, 13);
	cprintf("---------------------------");
	gotoxy(1, 15);

   cputs("\"Используй для передвижения стрелки вниз или верх\"");
   gotoxy(1, 16);
   cputs("\"Для выбора нажмите \"Enter\"\"");
}

// Добавочное меню для меню изменения
void mini_menu_change(computer * data, int index) {
    int line = 0;
   while(1) {
	   line = (line % 6 + 6) % 6;
	   system("cls");
	   output_menu_change(line);
		int key = getch();
		if (key == 0) { key = getch();
		switch(key) {
			case 72: line--; break;
			case 80: line++; break;
		}
		} else {

			if(key == 13)
			switch(line) {
			case 5: return;
			default:  change( data, index, line);
			break;
		} }
		}
}

//Меню изменения
void menu_change(computer * data, int n) {
	system("cls");
	if (n == 0) {
		textcolor(6);
		gotoxy(1, 1);
		cputs("База данных пуста!");
		textcolor(3);
		gotoxy(1, 3);
		cputs("(Для продолжения нажмите на любую клавишу)");
		getch();
		return;
	}
	int index;   char sym;
	gotoxy(1, 1);
	textcolor(6);
	cprintf("Какую Запись хотите изменить? (Всего %i)", n);
	printf("\n\n");
	while (scanf("%i%c", &index, &sym) != 2 || sym!= '\n' || index < 1 || index > n) {
		system("cls");
		textcolor(6); gotoxy(1, 1);
		cputs("Вы ввели Запись неверно или её нет, потворите, пожалуйста");
		gotoxy(1, 3);
		cprintf("Какую Запись хотите изменить? (Всего %i)", n);
		gotoxy(1, 5);
	}
	mini_menu_change(data, index - 1);
}

// Главное меню
void out_menu(int y) {
   char s[][100] = { {"Добавление в базу данных"}, {"Удаление данных"},
   {"Изменение данных"}, {"Вывод текущих данных"},
   {"Сортировка"}, {"Поиск по базе"}, {"Сохранение в файл"},
   {"Вывод данных из файла"}, {"Сбросить текущие изменения"}, {"Выход из базы данных"}};
   gotoxy(1, 1);
	textcolor(6);
   cputs("Что хотите сделать?");
	textcolor(3);
	gotoxy(1, 3);
	cputs("---------------------------");
	 gotoxy(1, 19);
	 cputs("---------------------------");
	 gotoxy(1, 21);
	 cputs("\"Используй для передвижения стрелки вниз или верх\"");
	 gotoxy(1, 22);
	 cputs("\"Для выбора нажмите \"Enter\"\"");
   for(int i = 1; i <= 10; i++) {
   gotoxy(1, i+5);
  if(i == y) textcolor(7);
  else  textcolor(2);
  cputs(s[i-1]);
   }
}

// Функция для проверки окачательного выхода
void pozz_die_or_life(int *die_or_life){
	if (*die_or_life >1) *die_or_life = 1;
	 if (*die_or_life < 0) *die_or_life = 0;
}

// Функция выхода
int the_end_or_begin(){

	int key , die_or_life = 0;
	while(1) {
	system("cls");
	gotoxy(30, 17);
	textcolor(3);
	cputs("\"Используй для передвижения стрелки влево или вправо\"");
	gotoxy(30, 18);
	cputs("\"Для выбора нажмите \"Enter\"\"");
	gotoxy(40, 10);
	textcolor(6);
	cputs("Вы точно хотите выйти?");
	gotoxy(43, 12);
	 textcolor( ((die_or_life*5-1)+8)%8);
	  cputs("Да");
	 gotoxy(56, 12);
	 textcolor(((((die_or_life+1)%2)*5-1)+8)%8);
	  cputs("Нет");
	key = getch();
	if (key == 13) return die_or_life;
	if (key == 0) {
	  key = getch();
	 switch(key){
		case 75: die_or_life++; break;
		case 77: die_or_life--; break;
	 }
	 die_or_life = ((die_or_life%2)+2)%2;
	}
	}
}

// Меню главное
int main() {
int n = 0, line = 0;
computer PC[100];
 base_computer_reset(PC, &n);
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
 gotoxy(35, 10);
	textcolor(1);
cputs("Привет! Ты в базе данных компьютеров! ");
gotoxy(33, 17);
	textcolor(3);
 puts("(Для продолжения нажмите на любую клавишу)");
getch();
while(1) {
system("cls");
line = ((line%10)+10)%10;

 out_menu(line+1);
 int k = getch();
 if (k == 0) {k = getch();

 switch(k) {
 case 72: line--;  break;
 case 80: line++; break;
 }
 }  else
  if(k == 13) {
  system("cls");
 switch(line) {
	case 0: add(PC, &n); break;
	case 1: menu_delete(PC, &n); break;
	case 2:  menu_change(PC, n); break;
	case 3:  output(PC, n); break;
	case 4:  menu_sorting(PC, n); break;
	case 5:  menu_finding(PC, n); break;
	case 6:  base_computer_save(PC, n);break;
	case 7:  base_computer_output(); break;
	case 8: base_computer_reset(PC, &n); break;
	case 9: if (the_end_or_begin()) return 0; break;
 }
 }
}
}