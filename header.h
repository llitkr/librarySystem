#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define CLS system("cls");
#define DBFILE "DB.txt"
#define MC System

class mainclass;
class book;
class student;

void Exit(mainclass MC);

void howToUse(void);

void mainActivity(void);

void mainmenu_1(mainclass &MC);		// ���� ���

void mainmenu_2(mainclass MC);		// �л� ���

void mainmenu_0(mainclass MC);

void submenu_1_1(mainclass &MC);	// �л� �߰��ϱ�

void submenu_1_2(mainclass &MC);	// ���� �߰��ϱ�

void submenu_1_3(mainclass &MC);	// �л� �����ϱ�

void submenu_1_4(mainclass &MC);	// ���� �����ϱ�

void submenu_1_5(mainclass MC);		// ��ü �л� ���� ����

void submenu_1_6(mainclass MC);		// ��ü ���� ���� ����

void submenu_1_7(mainclass &MC);	// �л� ���� ����

void submenu_1_9(mainclass MC);		// ���� �޴��� �̵�

void submenu_1_0(mainclass MC);		// ���α׷� ����

int choice(string menu, int a, int b=-1, int c=-1, int d=-1, int e=-1, int f=-1, int g=-1, int h=-1, int i=-1, int j=-1, int k=-1, int l=-1, int m=-1, int n=-1);

ifstream openInputFile(const string fileName);								// �Է� ���� ����
void closeInputFile(ifstream& fin);											// �Է� ���� �ݱ�

ofstream openOutputFile(const string fileName);								// ��� ���� ����
void closeOutputFile(ofstream& fout);										// ��� ���� �ݱ�

void pushIntArray(int* arr, const int index, const int arrSize);			// (�迭, ����, �迭 ũ��)�� ���ڷ� �޾� �迭�� �ش� ������ �ִ� ���� �����ϰ� �� ���� ��� ���� �� ĭ�� ��� �� ������ ĭ�� -1�� ä���ֱ�

int encrypt(const string word);

class mainclass
{
public:				/****** �ܺ� ���� ���� ******/
	book* Vbook;				// ���� Ŭ������ �迭
	student* Vstudent;			// �л� Ŭ������ �迭

	int totalBook;				// �� ���� ��
	int totalStudent;			// �� �л� ��

	int lastNumberOfBook;

	void getDataFromFile();
	void pushDataToFile();
	int borrowBook(const int indexOfBorrowBook, const int indexOfBorrowStudent);		// ���� ���� �Լ�(������ ������ �ε����� ���ڷ� ����)
	void borrowMenu(const int indexOfBorrowStudent);
	int returnBook(const int indexOfBorrowBook, const int indexOfBorrowStudent);		// ���� �ݳ� �Լ�(�ݳ��� ������ �ε����� ���ڷ� ����)
	void returnMenu(const int indexOfBorrowStudent);
	void modifyInformation(int indexOfStudent);											// �л� ���� ���� �Լ�
	int gettotalBook(void);
	int gettotalStudent(void);
	int searchStudentByStudentNumber(int studentNumber);
	void studentMode(int indexOfStudent);
	bool addStudent(int numberOfStudent, string studentName);
	void deleteStudent(int indexOfStudent);
	void addBook(int numberOfBook, string bookName);
	void deleteBook(int indexOfBook);
};

class book
{
private:			/* �ܺ� ���� �Ұ� */
	string name;				// ������
	int number;					// ���� ��ȣ
	int borrowFlag;				// ���� ���� ����(���� ������� ���� ���¶�� -1��, ����� ���¶�� ������ ȸ���� �ε����� ������ ����.

public:				/****** �ܺ� ���� ���� ******/
	void setName(const string name);			// ������ ���� �Լ�
	void setNumber(const int number);			// ���� ��ȣ ���� �Լ�
	void setBorrowFlag(const int borrowFlag);
	int checkBorrowFlag(void);			// ���� ���� ���� Ȯ�� �Լ�(borrowFlag�� ��ȯ)
	string getName(void);				// ������ ��ȯ �Լ�
	int getNumber(void);				// ���� ��ȣ ��ȯ �Լ�
};

class student
{
private:			/* �ܺ� ���� �Ұ� */
	string name;					// �л� �̸�
	int studentNumber;				// �л� �й�
	int numberOfBorrowedBook;		// �л��� ������ ���� ��
	int password;					// ��ȣȭ�� �н�����
	bool block;						// ���� ������ ����

public:				/****** �ܺ� ���� ���� ******/
	int* indexOfBorrowedBook;		// �л��� ������ ������ �ε����� �����ϴ� �������� �迭
	void setName(const string name);					// �л� �̸� ���� �Լ�
	void setNumber(const int number);					// �л� �й� ���� �Լ�
	string getName(void);						// �л� �̸� ��ȯ �Լ�
	int getNumber(void);						// �л� �й� ��ȯ �Լ�
	int checkPassword(void);			// ��ȣȭ�� �н����� Ȯ�� �Լ�
	int getNumberOfBorrowedBook(void);
	int getPassword(void);
	bool getBlock(void);
	void setNumberOfBorrowedBook(const int number);
	void setPassword(const string password);
	void setSecurePassword(const int password);
	void justSetBlock(const bool boolish);
	void setBlock(const bool boolish);
};