#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "chipping.h"
using namespace std;

int main()
{
	int mode, inputKey;
	std::locale::global( std::locale("") );
	wcout << L"Введите количество столбцов: ";
	// ОБРАБОТКА КОРЕКТНОСТИ ВВОДИМОГО КЛЮЧА (КОЛИЧЕСТВО СТОЛБЦОВ)
	try{
		wcin >> inputKey;
		if(inputKey < 1)
			throw inputKey;
	}catch(int &inputKey){
		wcerr << L"Неверный формат ключа:";
		wcerr << L"Выбирете целое число от 1"<<endl;
		exit(EXIT_FAILURE);
	}
	// ОБРАБОТКА КОРЕКТНОСТИ ВВОДИМОГО КЛЮЧА (КОЛИЧЕСТВО СТОЛБЦОВ)
	// ОБРАБОТКА КОРЕСТНОСТИ ВЫБРАННОГО РЕЖИМА
	wcin.ignore(32767,'\n');
	wcout << L"0-шифрует\n1-расшифровываем\nВыберете режим: ";
	Chiper chiper(inputKey);
	try{
		if(!(wcin >> mode))
			throw mode;
		if(mode == 0){
			chiper.chipping();
			wcout << chiper.getChiperedMessage() << endl;
		}else if (mode == 1){
			chiper.deChipping();
			wcout << chiper.getMessage() << endl;
		}
		if(mode != 0 and mode != 1)
			throw mode;
		}catch(int &mode){
			wcerr << L"Выбран неверный режим!!!" << endl;
			wcerr << L"Выбранный режим: " << mode << endl;
			exit(EXIT_FAILURE);
		}
	// ОБРАБОТКА КОРЕСТНОСТИ ВЫБРАННОГО РЕЖИМА
	return 0;
}