#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Product
{
	std::string ShopName, Address, VendorCode, ProductName, enter;

	int quantity, price, amount;

	void Print()
	{
		std::cout << "Name of the shop: ";
		std::cout << ShopName;
		std::cout << "\n";

		std::cout << "Address: ";
		std::cout << Address;
		std::cout << "\n";

		std::cout << "Vendor Code: ";
		std::cout << VendorCode;
		std::cout << "\n";

		std::cout << "Name of product: ";
		std::cout << ProductName;
		std::cout << "\n";

		std::cout << "Quantity: ";
		std::cout << quantity;
		std::cout << "\n";

		std::cout << "Price: ";
		std::cout << price;
		std::cout << "\n";

		std::cout << "Amount: ";
		std::cout << amount;
		std::cout << "\n";
	};
};

int Check_Number();
void menu(vector<Product> &product, int number, int password);
void Save(vector<Product> &product, int number, int password);
void Data_Read(vector<Product> &product, int number, int password);
void Data_product(vector<Product> &product, int number, int password);
void Amount_price(vector<Product> &product, int number, int password);
void Show_store(vector<Product> &product, int number, int password);
void Show_shop(vector<Product> &product, int number, int password);
void Show_address(vector<Product> &product, int number, int password);
void Show_price(vector<Product> &product, int number, int password);
void Add_Information(vector<Product> &product, int number, int password);
void Save_new_data(vector<Product> &product, vector<Product> &product2, int final_size, int number, int password);
void New_Data_Input(vector<Product> &product, int number, int password);

int Check_Number()
{
	int choice = 0;

	while (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		std::cout << "Не верный ввод!!! Введите число : ";
	}
	return choice;
}

void Data_Input(vector<Product> &product, int number, int password)
{
	std::cout << "Запишите данные..." << "\n";
	std::cout << "\n";
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "Name of the Shop:" << "\n";
		std::cin >> product[i].ShopName;
		std::cout << "\n";

		std::cout << "Address:" << "\n";
		std::cin >> product[i].Address;
		std::cout << "\n";

		std::cout << "Vendor Code:" << "\n";
		std::cin >> product[i].VendorCode;
		std::cout << "\n";

		std::cout << "Name of product:" << "\n";
		std::cin >> product[i].ProductName;
		std::cout << "\n";

		std::cout << "Quantity:" << "\n";
		product[i].quantity = Check_Number();
		std::cout << "\n";

		std::cout << "Cost:" << "\n";
		product[i].price = Check_Number();
		std::cout << "\n";

		std::cout << "Amount:" << "\n";
		product[i].amount = Check_Number();
		std::cout << "\n";
		system("cls");
	}

	std::cout << "Вы хотите записать информацию в файл?" << "\n";
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		Save(product, number, password);
	}
	else if (choice == 2)
	{
		std::cout << "Продолжение работы..." << "\n";
	}
}

void New_Data_Input(vector<Product> &product2, int number, int password)
{
	std::cout << "Запишите данные..." << "\n";
	std::cout << "\n";
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "Name of the Shop:" << "\n";
		std::cin >> product2[i].ShopName;
		std::cout << "\n";

		std::cout << "Address:" << "\n";
		std::cin >> product2[i].Address;
		std::cout << "\n";

		std::cout << "Vendor Code:" << "\n";
		std::cin >> product2[i].VendorCode;
		std::cout << "\n";

		std::cout << "Name of product:" << "\n";
		std::cin >> product2[i].ProductName;
		std::cout << "\n";

		std::cout << "Quantity:" << "\n";
		product2[i].quantity = Check_Number();
		std::cout << "\n";

		std::cout << "Cost:" << "\n";
		product2[i].price = Check_Number();
		std::cout << "\n";

		std::cout << "Amount:" << "\n";
		product2[i].amount = Check_Number();
		std::cout << "\n";
	}
}

void Save(vector<Product> &product, int number, int password)
{
	std::cout << "Сохранение в файл. Введите имя существующего или будущего файла..." << "\n";
	std::string name;
	std::cin >> name;
	ofstream database;
	database.open(name);
	if (!database.is_open())
	{
		std::cout << "Ошибка создания/октрытия файла!" << "\n";
	}
	else
	{
		system("cls");
		std::cout << "Успешное создание/открытие файла!" << "\n";
	}

	std::cout << "Запись информации в файл..." << "\n";
	for (size_t i = 0; i < number; i++)
	{
		database << product[i].ShopName << " ";

		database << product[i].Address << " ";

		database << product[i].VendorCode << " " << "\n";

		database << product[i].ProductName << " ";

		database << product[i].quantity << " ";

		database << product[i].price << " ";

		database << product[i].amount << " ";

		database << "========================" << "\n";
	}
	std::cout << "Успешная запись в файл!" << "\n";
	std::cout << "Закрытие файла" << "\n";
	database.close();
	menu(product, number, password);
}

void Data_Read(vector<Product> &product, int number, int password)
{

	std::cout << "Введите название файла." << "\n" << "\n";
	std::string name;
	std::cin >> name;
	ifstream database;
	database.open(name);
	if (!database.is_open())
	{
		system("cls");
		std::cout << "Ошибка создания/октрытия файла!" << "\n";
	}
	else
	{
		system("cls");
		std::cout << "Успешное создание/открытие файла!" << "\n";
	}
	std::cout << "Происходит считывание информации из файла..." << "\n";

	for (size_t i = 0; i < number; i++)
	{
		database >> product[i].ShopName;

		database >> product[i].Address;

		database >> product[i].VendorCode;

		database >> product[i].ProductName;

		database >> product[i].quantity;

		database >> product[i].price;

		database >> product[i].amount;

		database >> product[i].enter;
	}
	std::cout << "Успешное считывание из файла информации" << "\n" << "\n";
	std::cout << "Выведенная информация: " << "\n";
	for (size_t i = 0; i < number; i++)
	{
		product[i].Print();
	}
	database.close();
	menu(product, number, password);
}

void Delete_Information(vector<Product> &product, int number, int password)
{
	std::cout << "Введите стоимость товаров, которые будут удалены:" << "\n";

	int itemcost = 0;
	itemcost = Check_Number();

	for (size_t i = 0; i < number; i++)
	{
		if (product[i].price == itemcost)
		{
			std::cout << "Удаление найденного товара из списка..." << "\n";
			product.erase(product.begin() + i);
			std::cout << "Готово!" << "\n";
			break;
		}
	}

pointer2:
	std::cout << "Записи удалены. Продолжить?" << "\n";
	std::cout << "1. Да" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		system("cls");
		std::cout << "Обновленная информация: " << "\n";
		for (int i = 0; i < product.size(); i++)
		{
			product[i].Print();
		}
	}
	else
	{
		system("cls");
		std::cout << "Некорректный ввод! Сделайте выбор еще раз" << "\n";
		goto pointer2;
	}
	int number1 = product.size();
	Save(product, number1, password);
}

void Data_product(vector<Product> &product, int number, int password)
{
	system("cls");
	std::cout << "Введите название продукта, данные о котором вы хотите получить:" << "\n";

	string str;
	std::cin >> str;
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < product.size(); i++)
	{
		if (product[i].ProductName == str)
		{
			product[i].Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Информация не найдена" << "\n";
	}

	menu(product, number, password);
}

void Amount_price(vector<Product> &product, int number, int password)
{
	system("cls");
	std::cout << "Введите название продукта, суммарную стоимость которого вы хотите знать:" << "\n";

	string str;
	std::cin >> str;
	int count = 0;
	int amount_price = 0;
	std::cout << "Выведенная информация: ";
	for (int i = 0; i < product.size(); i++)
	{
		if (product[i].ProductName == str)
		{
			count++;
			amount_price = amount_price + (product[i].price * product[i].quantity);
		}
	}
	if (count == 0)
	{
		cout << "Информация не найдена" << "\n";
	}
	std::cout << amount_price << "\n";
	menu(product, number, password);
}

void Show_store(vector<Product> &product, int number, int password)
{
	system("cls");
	std::cout << "Адрес магазина, в котором товар самый дешёвый: ";

	int max = product[0].price;
	int count = 0;
	for (int i = 0; i < number; ++i)
	{
		if (product[i].price < max)
		{
			max = product[i].price;
			count = i;
		}
	}

	std::cout << product[count].Address << "\n";
	menu(product, number, password);
}

void Show_shop(vector<Product> &product, int number, int password)
{
	system("cls");
	std::cout << "Введите название магазина:" << "\n";

	string str;
	std::cin >> str;
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < product.size(); i++)
	{
		if (product[i].ShopName == str)
		{
			product[i].Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Информация не найдена" << "\n";
	}

	menu(product, number, password);
}

void Show_address(vector<Product> &product, int number, int password)
{
	system("cls");
	std::cout << "Введите адрес магазина:" << "\n";

	string str;
	std::cin >> str;
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < product.size(); i++)
	{
		if (product[i].Address == str)
		{
			product[i].Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Информация не найдена" << "\n";
	}

	menu(product, number, password);
}

void Show_price(vector<Product> &product, int number, int password)
{
	system("cls");
	std::cout << "Введите адрес магазина:" << "\n";

	int price = Check_Number();
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < product.size(); i++)
	{
		if (product[i].price == price)
		{
			product[i].Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Информация не найдена" << "\n";
	}

	menu(product, number, password);
}

void Add_Information(vector<Product> &product, int number, int password)
{
	std::cout << "Сколько нужно добавить?" << "\n";
	int choice = Check_Number();
	vector<Product> product2(choice);
	New_Data_Input(product2, choice, password);
	Save_new_data(product, product2, choice, number, password);
}

void Save_new_data(vector<Product> &product, vector<Product> &product2, int final_size, int number, int password)
{
	system("cls");
	std::cout << "final size = " << final_size;
	std::cout << "Добавление новых записей..." << "\n";
	for (size_t i = 0; i < final_size; i++)
	{
		product.push_back(product2[i]);
	}
	std::cout << "Записи добавлены!" << "\n";
	for (size_t i = 0; i < final_size + number; i++)
	{
		product[i].Print();
	}

	std::cout << "Вы хотите записать информацию в файл?" << "\n";
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		std::cout << "Сохранение в файл. Введите имя существующего или будущего файла..." << "\n";
		std::string name;
		std::cin >> name;
		ofstream database;
		database.open(name, ios::app);
		if (!database.is_open())
		{
			std::cout << "Ошибка создания/октрытия файла!" << "\n";
		}
		else
		{
			system("cls");
			std::cout << "Успешное создание/открытие файла!" << "\n";
		}

		std::cout << "Запись информации в файл..." << "\n";

		for (size_t i = 0; i < final_size + number; i++)
		{
			database << product[i].ShopName << " ";

			database << product[i].Address << " ";

			database << product[i].VendorCode << " " << "\n";

			database << product[i].ProductName << " ";

			database << product[i].quantity << " ";

			database << product[i].price << " ";

			database << product[i].amount << " ";

			database << "========================" << "\n";
		}
		std::cout << "Успешная запись в файл!" << "\n";
		std::cout << "Закрытие файла" << "\n";
		database.close();
		final_size = final_size + number;

		menu(product, final_size, password);
	}
	else if (choice == 2)
	{
		std::cout << "Продолжение работы..." << "\n";
	}
}

void menu(vector<Product> &product, int number, int password)
{
	std::cout << "Что вы хотите сделать?" << "\n";
	std::cout << "1. Внести данные." << "\n";
	std::cout << "2. Считать данные." << "\n";
	std::cout << "======================================" << "\n";
	std::cout << "Возможно только после выполнения либо 1, либо 2 пункта." << "\n";
	std::cout << "3. Удалить данные о товарах со стоимостью 1." << "\n";
	std::cout << "4. Вывести данные о товаре в различных магазинах." << "\n";
	std::cout << "5. Вывести суммарную стоимость заданного товара." << "\n";
	std::cout << "6. Вывести информацию о магазине, где заданный товар самый дешёвый." << "\n";
	std::cout << "7. Вывести информацию о конкретном магазине." << "\n";
	std::cout << "8. Вывести информацию по адресу." << "\n";
	std::cout << "9. Вывести информацию по цене." << "\n";
	std::cout << "10. Добавить новые данные и сохранить их." << "\n";

	int num = Check_Number();
	if (num == 1)
	{
		system("cls");
		Data_Input(product, number, password);
	}
	else if (num == 2)
	{
		system("cls");
		Data_Read(product, number, password);
	}
	else if (num == 3)
	{
		system("cls");

	pointer:
		std::cout << "Введите указанный ранее пароль для редактирования записей." << "\n";
		int password1 = Check_Number();
		if (password1 == password)
		{
			system("cls");
			std::cout << "Вы ввели верный пароль. Продолжение работы..." << "\n";
			Delete_Information(product, number, password);
		}
		else
		{
			system("cls");
			std::cout << "Неверный пароль. Повторите попытку еще раз." << "\n";
			goto pointer;
		}
	}
	else if (num == 4)
	{
		system("cls");
		Data_product(product, number, password);
	}
	else if (num == 5)
	{
		system("cls");
		Amount_price(product, number, password);
	}
	else if (num == 6)
	{
		system("cls");
		Show_store(product, number, password);
	}
	else if (num == 7)
	{
		system("cls");
		Show_shop(product, number, password);
	}
	else if (num == 8)
	{
		system("cls");
		Show_address(product, number, password);
	}
	else if (num == 9)
	{
		system("cls");
		Show_price(product, number, password);
	}
	else if (num == 10)
	{
		system("cls");

	pointer2:
		std::cout << "Введите указанный ранее пароль для редактирования записей." << "\n";
		int password1 = Check_Number();
		if (password1 == password)
		{
			system("cls");
			std::cout << "Вы ввели верный пароль. Продолжение работы..." << "\n";
			Add_Information(product, number, password);
		}
		else
		{
			system("cls");
			std::cout << "Неверный пароль. Повторите попытку еще раз." << "\n";
			goto pointer2;
		}

	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Начало работы." << "\n" << "\n";

	std::cout << "!СПРАВКА ПО РАБОТЕ С ПРОГРАММОЙ!" << "\n";
	std::cout << "1. После запуска программы, выберите количество пациентов, которое вы хотите занести в базу и нажмите Enter." << "\n";
	std::cout << "2. Запомните пароль, который сгенерирует программа после ввода количества пациентов." << "\n";
	std::cout << "3. При переносе в главное меню Вы можете сделать выбор: записать данные в файл или считать данные из файла." << "\n" << "Пока один из этих пунктов не будет выбран и информация не будет считана в программе - НЕ ВЫБИРАТЬ пункты 3-9." << "\n";
	std::cout << "4. После считывания или внесения данных в базу данных, открывается доступ к редактированию, а так же поиску информации в базе данных." << "\n";
	std::cout << "5. Файл, в который будет записываться или же считываться информация, находится в папке CORSEWORK." << "\n";
	std::cout << "6. Убедительная просьба указывать формат файла в его названии. На пример, final.txt." << "\n";
	std::cout << "Вполне допускается ввод названия файла и без его формата, но в таком случае, при попытке открыть файл, нужно вручную открыть его, нажав ОТКРЫТЬ С ПОМОЩЬЮ -> БЛОКНОТ" << "\n";
	std::cout << "Выполнил курсовую работу студент группы (ВВЕДИ ТУТ СВОЁ ИМЯ, ДРУГ!) Преподователь: Сперанский В.А." << "\n";

	std::cout << "Вы хотите начать работу с программой?" << "\n";
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		std::cout << "Продолжение работы..." << "\n";
	}
	else if (choice == 2)
	{
		std::cout << "Конец работы..." << "\n";
		system("pause");
		return 0;
	}

	std::cout << "Введите колличество РАЗЛИЧНЫХ товаров:" << "\n";

	int number = Check_Number();
	vector<Product> product(number);

	srand(time(0)); // автоматическая рандомизация

	int password = rand();
	cout << endl << "Код для изменения данных: " << password << endl;


	menu(product, number, password);
}