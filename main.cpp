#include <UnitTest++/UnitTest++.h>
#include "chipping.h"
using namespace std;

struct KeyTestOneColumn{
	Chiper test_obj{1};
};
struct KeyTestThreeColumn{
	Chiper test_obj{3};
};
struct KeyTestSixColumn{
	Chiper test_obj{6};
};
struct KeyTestMoreColumn{
	Chiper test_obj{7};
};
SUITE(KeyTest)
{
	TEST_FIXTURE (KeyTestOneColumn,One_column) {
			wstring text = L"Привет";
			wstring res = L"Привет";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
	TEST_FIXTURE (KeyTestThreeColumn,Three_column) {
			wstring text = L"Привет";
			wstring res = L"Пвреит";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
	TEST_FIXTURE (KeyTestSixColumn,Six_column) {
			wstring text = L"Привет";
			wstring res = L"Привет";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
	TEST_FIXTURE (KeyTestMoreColumn,More_column) {
			wstring text = L"Привет";
			wstring res = L"Привет";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
	TEST(Zero_column) {
			CHECK_THROW(Chiper test(0) ,std::wstring);
	}
}

struct ThreeKey{
	Chiper test_obj{3};
};
SUITE(NotCipheredMessTest){
	TEST_FIXTURE (ThreeKey,Normall_mess) {
			wstring text = L"Привет";
			wstring res = L"Пвреит";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
	TEST_FIXTURE (ThreeKey,Zero_length_mess) {
			wstring text = L"";
			CHECK_THROW(test_obj.chipping(text), std::wstring);
	}
	TEST_FIXTURE (ThreeKey,Space_mess) {
			wstring text = L"Привет Андрей";
			wstring res = L"Пв дйреАр итне ";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
	TEST_FIXTURE (ThreeKey,More_sumb_mess) {
			wstring text = L"Андрей, привет, тебе уже 97 лет";
			wstring res = L"Ар,ре бу  тне иттеж9л дйпв,е е7е ";
			CHECK_EQUAL(true, res == test_obj.chipping(text));
	}
}
SUITE(CipheredMessTest){
		TEST_FIXTURE (ThreeKey,Normall_Chipered_mess) {
			wstring text = L"Пвреит";
			wstring res = L"Привет";
			CHECK_EQUAL(true, res == test_obj.deChipping(text));
	}
	TEST_FIXTURE (ThreeKey,Zero_length_Chipered_mess) {
			wstring text = L"";
			CHECK_THROW(test_obj.deChipping(text), std::wstring);
	}
	TEST_FIXTURE (ThreeKey,Space_Chipered_mess) {
			wstring text = L"Пв дйреАр итне ";
			wstring res = L"Привет Андрей";
			CHECK_EQUAL(true, res == test_obj.deChipping(text));
	}
	TEST_FIXTURE (ThreeKey,More_sumb_Chipered_mess) {
			wstring text = L"Ар,ре бу  тне иттеж9л дйпв,е е7е ";
			wstring res = L"Андрей, привет, тебе уже 97 лет";
			CHECK_EQUAL(true, res == test_obj.deChipping(text));
	}
}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
