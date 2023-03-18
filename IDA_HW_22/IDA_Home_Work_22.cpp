#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

// Service functions prototypes ------------------------------------
int Get_Int_SA();				// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();			// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();				// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
//template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min=-999, ANY Range_max=999);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Homework 19 -----------------------------------------------------	

//Task 1
template <typename ANY> void Swap_even_and_odd_in_array(ANY arr[], int Size)
{
	ANY* _pointer_arr = arr;
	for (int i = 0; i < Size / 2; i++)
		std::swap(*(_pointer_arr + i * 2), *(_pointer_arr + 1 + i * 2));
}
void Swap_even_and_odd_in_array()
{
	int const Size = 10;
	static int programm_variants = {};
	if (programm_variants % 2 == 0)
	{
		double Test_Array[Size] = {};
		Fill_Array_with_Random(Test_Array, Size, -999.0, 999.0);
		std::cout << "\nRandom double array:";
		Array_Console_Out(Test_Array, Size);
		Swap_even_and_odd_in_array(Test_Array, Size);
		std::cout << "\nRandom array after swaping even and odd elements:";
		Array_Console_Out(Test_Array, Size);
	}
	else
	{
		int Test_Array[Size] = {};
		Fill_Array_with_Random(Test_Array, Size, -999, 999);
		std::cout << "\nRandom integer array:";
		Array_Console_Out(Test_Array, Size);
		Swap_even_and_odd_in_array(Test_Array, Size);
		std::cout << "\nRandom array after swaping even and odd elements:";
		Array_Console_Out(Test_Array, Size);
	}
	programm_variants++;
}
//Task 2
template <typename any> void Power_of_number_through_pointer(any* _pointer, int power)
{
	//if (power == 0) {*_pointer = 1; return;}
	any _temporary = 1;
	for (int i = 0; i < power; i++)
		_temporary *= *_pointer;
		//*_pointer *= *_pointer;
	*_pointer = _temporary;
}
void Power_of_number_through_pointer_demo()
{
	std::cout << "\n" << "Enter a number to raise -> ";
	double User_Number = Get_Dbl_SA();
	std::cout << "\n" << "Enter a power to raise in -> ";
	int User_Power = Get_Int_SA();
	std::cout << "\n" << "Power_of_number_through_pointer(" << User_Number << ", " << User_Power << ")\n";
	Power_of_number_through_pointer(&User_Number, User_Power);
	std::cout << "\n" << "User_Number = " << User_Number;
}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("mode con cols=110 lines=40"); // ??? текст основного меню не входит в окно консоли по умолчанию. При небольшом увеличении окна (lines < 85) пропадает полоса прокрутки, что не здорово. Как ee оставить и не делать (lines > 85)?
	std::string Name_of_Work = { "Home Work 22: Pointers in arrays and functions" };
	std::string Menu_Element_1 = { "Random array [10]: changing places of even and odd elements" };
	std::string Menu_Element_2 = { "Power of number through pointer" };
	//std::string Menu_Element_3 = { "Sort_Array_from_N(arr[], Size, N): Search first encaunter of N in array, then sort from this position" };
	//std::string Menu_Element_4 = { "Search_First_Ordinary_in_Array(arr[], Size): Returns first ordinary number in an array" };

	do {		
		system("cls");
		std::cout << "\n\t***\t" << Name_of_Work << "\t***\n\n\t\n\nChoose an opion: \n";
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		//std::cout << "\n 3. " << Menu_Element_3;
		//std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n\n 0. Exit\n";
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) Swap_even_and_odd_in_array();
		else if (choice == 2) Power_of_number_through_pointer_demo();
		//else if (choice == 3) Sort_Array_from_N_demo();
		//else if (choice == 4) Search_First_Ordinary_in_Array_demo();
			
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
		} while (true);
		
	//system("pause");
	return 0;
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); // заклинание средней силы против неудачного чтения getline
	std::cin.clear(); // заклинание малой силы против неудачного чтения getline
	getline(std::cin, a);
	//std::cout << "\nFunction: working with " << a << "\n"; для отладки
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	//std::cin.ignore(1024, '\n');
	getline(std::cin, a);
	if (a != "") // оказывается getline считывает пустую строку которую stoi уже не берет
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Incorrect input: INTEGER overflow. Decrease input\n";
			}
		}
		else
		{
			std::cout << "Incorrect symbols: positive INTEGER expected. Try again...\n";
			return Get_Int_Positive();
		}
		//return Get_Int_Positive();
	}
	else
		std::cout << "Input Error: NULL input\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Data type overflow\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: REAL expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = "."; // = "";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{
				//std::cout << "\na[" << i << "] ->" << a[i]<< " == " <<dot[0];
				//std::cout << "\nflag -> " << One_Dot_already;
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "dot placement error\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{
				//std::cout << "trying stod: " << a;
				//system("pause");
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Incorrect input: Data type [DOUBLE] overflow. Decrease input\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: positive REAL expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min=-999.0, ANY Range_max=999.0)
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
