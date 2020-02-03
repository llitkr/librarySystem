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

void mainmenu_1(mainclass &MC);		// 관리 모드

void mainmenu_2(mainclass MC);		// 학생 모드

void mainmenu_0(mainclass MC);

void submenu_1_1(mainclass &MC);	// 학생 추가하기

void submenu_1_2(mainclass &MC);	// 도서 추가하기

void submenu_1_3(mainclass &MC);	// 학생 삭제하기

void submenu_1_4(mainclass &MC);	// 도서 삭제하기

void submenu_1_5(mainclass MC);		// 전체 학생 정보 열람

void submenu_1_6(mainclass MC);		// 전체 도서 정보 열람

void submenu_1_7(mainclass &MC);	// 학생 정보 수정

void submenu_1_9(mainclass MC);		// 상위 메뉴로 이동

void submenu_1_0(mainclass MC);		// 프로그램 종료

int choice(string menu, int a, int b=-1, int c=-1, int d=-1, int e=-1, int f=-1, int g=-1, int h=-1, int i=-1, int j=-1, int k=-1, int l=-1, int m=-1, int n=-1);

ifstream openInputFile(const string fileName);								// 입력 파일 지정
void closeInputFile(ifstream& fin);											// 입력 파일 닫기

ofstream openOutputFile(const string fileName);								// 출력 파일 지정
void closeOutputFile(ofstream& fout);										// 출력 파일 닫기

void pushIntArray(int* arr, const int index, const int arrSize);			// (배열, 지점, 배열 크기)를 인자로 받아 배열의 해당 지점에 있는 값을 삭제하고 그 뒤의 모든 값을 한 칸씩 당긴 후 마지막 칸에 -1을 채워넣기

int encrypt(const string word);

class mainclass
{
public:				/****** 외부 접근 가능 ******/
	book* Vbook;				// 도서 클래스형 배열
	student* Vstudent;			// 학생 클래스형 배열

	int totalBook;				// 총 도서 수
	int totalStudent;			// 총 학생 수

	int lastNumberOfBook;

	void getDataFromFile();
	void pushDataToFile();
	int borrowBook(const int indexOfBorrowBook, const int indexOfBorrowStudent);		// 도서 대출 함수(대출할 도서의 인덱스를 인자로 받음)
	void borrowMenu(const int indexOfBorrowStudent);
	int returnBook(const int indexOfBorrowBook, const int indexOfBorrowStudent);		// 도서 반납 함수(반납할 도서의 인덱스를 인자로 받음)
	void returnMenu(const int indexOfBorrowStudent);
	void modifyInformation(int indexOfStudent);											// 학생 정보 수정 함수
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
private:			/* 외부 접근 불가 */
	string name;				// 도서명
	int number;					// 도서 번호
	int borrowFlag;				// 도서 대출 여부(만약 대출되지 않은 상태라면 -1을, 대출된 상태라면 대출한 회원의 인덱스를 값으로 저장.

public:				/****** 외부 접근 가능 ******/
	void setName(const string name);			// 도서명 편집 함수
	void setNumber(const int number);			// 도서 번호 편집 함수
	void setBorrowFlag(const int borrowFlag);
	int checkBorrowFlag(void);			// 도서 대출 여부 확인 함수(borrowFlag를 반환)
	string getName(void);				// 도서명 반환 함수
	int getNumber(void);				// 도서 번호 반환 함수
};

class student
{
private:			/* 외부 접근 불가 */
	string name;					// 학생 이름
	int studentNumber;				// 학생 학번
	int numberOfBorrowedBook;		// 학생이 대출한 도서 수
	int password;					// 암호화된 패스워드
	bool block;						// 계정 블럭상태 여부

public:				/****** 외부 접근 가능 ******/
	int* indexOfBorrowedBook;		// 학생이 대출한 도서의 인덱스를 포함하는 포인터형 배열
	void setName(const string name);					// 학생 이름 편집 함수
	void setNumber(const int number);					// 학생 학번 편집 함수
	string getName(void);						// 학생 이름 반환 함수
	int getNumber(void);						// 학생 학번 반환 함수
	int checkPassword(void);			// 암호화된 패스워드 확인 함수
	int getNumberOfBorrowedBook(void);
	int getPassword(void);
	bool getBlock(void);
	void setNumberOfBorrowedBook(const int number);
	void setPassword(const string password);
	void setSecurePassword(const int password);
	void justSetBlock(const bool boolish);
	void setBlock(const bool boolish);
};