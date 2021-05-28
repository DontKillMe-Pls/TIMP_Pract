#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
class Chiper{
private:
	wstring message, chiperedMessage;
	
	void setMessage(wstring inputString);
	void setChiperedMessage(wstring inputChiperedString);
	
public:
	int kolichestvoStolbcov;
	wstring getMessage();
	wstring getChiperedMessage();
	wstring chipping(const wstring message);
	wstring deChipping();
	Chiper() = delete;
	Chiper(const int inputKey);
};