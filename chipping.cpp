#include "chipping.h"
using namespace std;

Chiper::Chiper(int key){
	Chiper::kolichestvoStolbcov = key;
}
void Chiper::setMessage(wstring inputString){
	message = inputString;
}
void Chiper::setChiperedMessage(wstring inputChiperedString){
	chiperedMessage = inputChiperedString;
}
wstring Chiper::getMessage(){
	return message;
}
wstring Chiper::getChiperedMessage(){
	return chiperedMessage;
}
wstring Chiper::chipping(const wstring message){
	int kolichestvoStrok;
//	wcout << L"Введите количество столбцов: ";
	int kolichestvoStolbcov = Chiper::kolichestvoStolbcov;
//	wcin.clear();
//	wcin.ignore(32767,'\n');
	wcout << L"Введите сообщение: ";
//	getline(wcin,message);
	if(message.length()%kolichestvoStolbcov!=0){
		kolichestvoStrok = message.length() / kolichestvoStolbcov +1;
	}else{
		kolichestvoStrok = message.length() / kolichestvoStolbcov;
	}
	while(((int)(message.length()) < kolichestvoStolbcov*kolichestvoStrok) == 1){
			message.push_back(' ');
		}
	chiperedMessage = message;
	int index_of_char = 0;
		for(int i=0; i < kolichestvoStolbcov; i++){
			for(int j=0; j < kolichestvoStrok; j++){
				chiperedMessage[index_of_char] = message[i+j*kolichestvoStolbcov];
				index_of_char++;
			}
		}
	return chiperedMessage;
}

wstring Chiper::deChipping(){
	int kolichestvoStrok;
//	wcout << L"Введите количество столбцов: ";
	int kolichestvoStolbcov = Chiper::kolichestvoStolbcov;
	wcin.clear();
	wcin.ignore(32767,'\n');
	wcout << L"Введите сообщение: ";
	getline(wcin,chiperedMessage);
	kolichestvoStrok = chiperedMessage.length()/kolichestvoStolbcov;
	message = chiperedMessage;
	int index_of_char = 0;
		for(int i=0; i < kolichestvoStolbcov; i++){
			for(int j=0; j < kolichestvoStrok; j++){
				message[i+j*kolichestvoStolbcov] = chiperedMessage[index_of_char];
				index_of_char++;
			}
		}
		while((char)(message[index_of_char-1])==' '){
			message.erase(index_of_char-1,1);
			index_of_char--;
		}
	return message;
}