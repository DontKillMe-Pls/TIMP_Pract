#include <UnitTest++/UnitTest++.h>
#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;

struct KeyTestAAAA{
	modAlphaCipher test_obj{L"АААА"};
};
struct KeyTestLong{
	modAlphaCipher test_obj{L"АBCDEFGMNLP"};
};
struct KeyTestLow{
	modAlphaCipher test_obj{L"abcd"};
};
struct KeyTestNum{
	modAlphaCipher test_obj{L"A1"};
};
struct KeyTestSpace{
	modAlphaCipher test_obj{L"A B"};
};
struct KeyTestInvalidSumb{
	modAlphaCipher test_obj{L"A,"};
};

SUITE(KeyTest)
{
	TEST_FIXTURE (KeyTestAAAA,Test_Russian_sumbols) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"JKCЫЮM";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (KeyTestLong,Long_key) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"JСКЕИЧ";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (KeyTestLow,Low_register_key) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"ПСКЕЕУ";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}	
	TEST_FIXTURE (KeyTestNum,Num_in_key) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"Used not allowed sumbols in key";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
		TEST_FIXTURE (KeyTestSpace,Space_in_key) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"Used not allowed sumbols in key";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (KeyTestInvalidSumb,Invalid_Sumb_in_key) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"Used not allowed sumbols in key";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
}

struct Key_B{
	modAlphaCipher test_obj{L"B"};
};
struct MaxKey{
	modAlphaCipher test_obj{L"Z"};
};
SUITE(EncryptTest)
{
	TEST_FIXTURE (Key_B,High_cast) {
			wstring text = L"ПРИВЕТДРУГ";
			wstring res = L"РСЙГЁУЕСФД";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (Key_B,Low_cast) {
			wstring text = L"приветдруг";
			wstring res = L"РСЙГЁУЕСФД";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (Key_B,Space) {
			wstring text = L"ПРИВЕТ ДРУГ";
			wstring res = L"РСЙГЁУЕСФД";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (Key_B,Num) {
			wstring text = L"ПРИВЕТ2007";
			wstring res = L"Not allowed format not_cipher_text";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (Key_B,Void) {
			wstring text = L"";
			wstring res = L"Not allowed format not_cipher_text";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (Key_B,No_letters) {
			wstring text = L"1232+3142=435345";
			wstring res = L"Not allowed format not_cipher_text";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
	TEST_FIXTURE (MaxKey,Max_key) {
			wstring text = L"ПРИВЕТ";
			wstring res = L"IJBЪЭL";
			CHECK_EQUAL(true, res == test_obj.encrypt(text));
	}
}

struct MMaxKey{
	modAlphaCipher test_obj{L"Z"};
};

SUITE(DecryptTest)
{
	TEST_FIXTURE (Key_B,High_cast) {
			wstring text = L"РСЙГЁУЕСФД";
			wstring res = L"ПРИВЕТДРУГ";
			CHECK_EQUAL(true, res == test_obj.decrypt(text));
	}
	TEST_FIXTURE (Key_B,Low_cast) {
			wstring text = L"рсйгёуесфд";
			wstring res = L"Not allowed format cipher_text";
			CHECK_EQUAL(true, res == test_obj.decrypt(text));
	}
	TEST_FIXTURE (Key_B,Space) {
			wstring text = L"РСЙГЁУ ЕСФД";
			wstring res = L"Not allowed format cipher_text";
			CHECK_EQUAL(true, res == test_obj.decrypt(text));
	}
	TEST_FIXTURE (Key_B,Num) {
			wstring text = L"ПРИВЕТ2007";
			wstring res = L"Not allowed format cipher_text";
			CHECK_EQUAL(true, res == test_obj.decrypt(text));
	}
	TEST_FIXTURE (Key_B,Void) {
			wstring text = L"";
			wstring res = L"Not allowed format cipher_text";
			CHECK_EQUAL(true, res == test_obj.decrypt(text));
	}
	TEST_FIXTURE (MaxKey,Max_key) {
			wstring text = L"IJBЪЭL";
			wstring res = L"ПРИВЕТ";
			CHECK_EQUAL(true, res == test_obj.decrypt(text));
	}
	
}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
