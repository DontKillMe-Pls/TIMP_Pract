#include <iostream>
#include <cctype>
#include "modAlphaChiper.h"
using namespace std;

int main(int argc, char **argv)
{
	setlocale( LC_ALL, "" );
	std::locale loc("ru_RU.UTF-8"); 
	std::locale::global(loc);
	std::wstring key, mess;
	int mod;
	wcout << L"Введите ключ: ";
	wcin >> key;
	wcout << L"Введите сообщение: ";
	wcin >> mess;
	try{
		modAlphaChiper encrypted(key);
		encrypted.encrypt(mess);
		encrypted.decrypt(encrypted.encrypt(mess));
	}catch(std::wstring& e){
		wcerr << e << endl;
		exit(EXIT_FAILURE);
	}
//		modAlphaChiper test(L"testing_key");
//		wcout <<test.encrypt(L"testing_mess");
		modAlphaChiper encrypted(key);
		wcout << L"Зашифрованное сообщение: "<< encrypted.encrypt(mess) << endl;
		wcout << L"Расшифрованное сообщение: "<< encrypted.decrypt(encrypted.encrypt(mess))<< endl;
	
	return 0;
}

