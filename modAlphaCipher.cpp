#include "modAlphaCipher.h"
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool isValid(const wstring& s)
{	
	std::wstring for_search = L"ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	for(auto c:s)
		if((for_search.find(c))== -1)
			return false;
		return true;
}
modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{	if(skey.size()==0){
		throw std::wstring(L"Empty key");
	}
//	if(!isValid(skey)){
//		throw std::wstring(L"Used not allowed sumbols in key");
//	}
	for (unsigned i=0; i<numAlpha.size();i++){
		alphaNum[numAlpha[i]]=i;
	}
	key = convert(skey);
}
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
	std::wstring for_work = open_text;
//	if(!isValid(open_text)){
//		if(!isValid(getValidText(open_text))){
//			throw std::wstring(L"Not allowed format not_cipher_text");
//		}else{
//				for_work = getValidText(open_text);
//			}
//		}
	std::vector<int> work = convert(for_work);
	for(unsigned i=0; i< work.size();i++){
		work[i] = (work[i] + key[i%key.size()])% alphaNum.size();
	}
	return convert(work);
}
std::wstring modAlphaCipher::getValidText(const std::wstring& not_valid_open_text){
	std::wstring validText = not_valid_open_text;
		for(int i=0; i< validText.length(); i++){
		if((modAlphaCipher::list_of_alph_for_valid.find(validText[i])) != -1){
			validText[i] = modAlphaCipher::numAlpha[modAlphaCipher::list_of_alph_for_valid.find(validText[i])];
		}
		
	}
	return validText;
}
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
//	if(!isValid(cipher_text)){
//		throw std::wstring(L"Not allowed format cipher_text");
//	}
	std::vector<int> work = convert(cipher_text);
	for(unsigned i=0;i<work.size();i++){
		work[i] = (work[i]+alphaNum.size()- key[i%key.size()]) % alphaNum.size();
	}
	return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
	std::vector<int> result;
	for(auto c:s){
		result.push_back(alphaNum[c]);
	}
	return result;
}
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
	std::wstring result;
	for(auto i:v){
		result.push_back(numAlpha[i]);
	}
	return result;
}


