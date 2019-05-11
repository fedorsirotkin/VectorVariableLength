/* * * * * * * * * * *
 * * * main.cpp  * * *
 * * * * * * * * * * */ 
#include <iostream>
#include <string>
#include <cstdlib>
#include "vector.hpp"

using namespace std;

template <class T> void reverseVecor( Vect <T> v ) {
    std::cout << "Reversive output for " << v.mark() << ":" << endl;
    size_t n = v.size();
    for (int i = n - 1; i >= 0; --i) {
		std::cout << v[i] << " ";
	}
    std::cout << endl;
}

int main() {
	system("chcp 1251 >NULL");

	try {

		/* �������� ���������� ������� �� ����� ����� � 10-� ��������� */
		Vect <int> v1(10);

		/* ���������� ����� ������� v1 */
		v1.mark(string("v1"));
		
		/*
		 * ��������� ������� �������
		 *
		 * ��� size_t ������� ����������� ������������� ��� ��� ��������
		 * ������������� ������� ������������ ���������� ������� ������ ����
		 *
		 */
		size_t n = v1.size();

		/* ���������� ������� ������ ������� �� 1 �� 10 */
		for (size_t i = 0; i < n; ++i) {
			v1[i] = i + 1;
		}

		/* �������� ���������� ������� v1 */
		v1.show();

		/* ����� ���������������� ������� ��� ������� ������� */
		reverseVecor(v1);
	}
	catch (VectorDebug& vre)  {
		vre.ErrMsg();
	}

    try {

		/* �������� ������� initStr �� ���� ��������� ���� ������*/
		string initStr[5] = { "first", "second", "third", "fourth", "fifth" };

		/* �������� ���������� ������� �� 5-� ��������� ���� ������ */
        Vect <string> v2(5);

		/* ���������� ����� ������� v2 */
        v2.mark(string("v2"));

		/* ��������� ������� ������� */
        size_t n = v2.size();

		/* ���������� ���������� ������� v2 ���������� ������� initStr */
        for (size_t i = 0; i < n; ++i) {
			v2[i] = initStr[i];
		}

		/* ����� ����������� ������� v2 */
        v2.show();

		/* ������� �������� ��� �������� 4 */
        v2.insert(v2.begin() + 3, "After_third");

		/* ����� ����������� ������� v2 */
        v2.show();

		/* ������� ������� ������� ������� �������� � ���������� ���������� */
        // cout << v2[6] << endl;

		/* ���������� ���� ����� ��������� � ������ v2 */
        v2.push_back("Add_1"); v2.push_back("Add_2"); v2.push_back("Add_3");

		/* ����� ����������� ������� v2 */
        v2.show();


		/* �������� ���� ��������� �� ����� ������� v2 */
        v2.pop_back(); v2.pop_back();

		/* ����� ����������� ������� v2 */
        v2.show();
    }
    catch (VectorDebug& vre)  {
		vre.ErrMsg();
	}
		
    try {

		/* �������� ���������� ������� v3 �� ������������� ��������� */
        Vect <int> v3;

		/* ���������� ����� ������� v3 */
        v3.mark(string("v3"));

		/* ���������� ���� ����� ��������� � ������ v3 */
        v3.push_back(41); v3.push_back(42); v3.push_back(43);

		/* ����� ����������� ������� v3 */
        v3.show();

		/* �������� ���������� ������� v4 �� ������������� ��������� */
        Vect <int> v4;

		/* ���������� ����� ������� v4 */
        v4.mark(string("v4"));

		/* �������� ���������� ������� v4 �� ������������� ��������� */
        v4 = v3;
			
		/* ����� ����������� ������� v4 */
        v4.show();

		/*
		 * �������� �������� ����� ��������� ��� � ��� ����
		 * �� ����� ���� �������� � ������
		 */
        v3.pop_back(); v3.pop_back();
        v3.pop_back(); // v3.pop_back();

		/* ����� ����������� ������� v3 */
        v3.show();
    }
    catch (VectorDebug& vre)  {
		vre.ErrMsg();
	}

	system("pause >nul");
}
/* * * * * * * * * * */ 