#include "header.h"

void Exit(mainclass MC)
{
	MC.pushDataToFile();
	delete []MC.Vbook;
	delete []MC.Vstudent;
	exit(0);
}

void howToUse(void)
{
	int c = 0;

	cout << "본 프로그램은 MySQL과 같은 DB를 사용하는 대신 일반적인 text 파일을 DB화시켜 제작한 프로그램입니다." << endl;
	cout << "만약 귀하가 본 프로그램을 처음으로 사용하신다면, 프로그램 파일과 동일한 폴더에 \"" << DBFILE << "\"라는 이름의 파일이 생성됩니다." << endl;
	cout << "해당 파일은 절대로 삭제하지 마시길 권고드립니다. 본 프로그램에서 사용하는 모든 데이터가 정해진 양식대로 해당 파일에 저장되어 있습니다." << endl;
	cout << "또한 본 프로그램을 사용하는 중 콘솔 창의 우측 상단에 있는 X 버튼을 클릭하시거나 프로세스 강제 종료 등 비정상적인 방법으로 프로그램을 종료할 경우, 진행사항이 저장되지 않을 수 있습니다." << endl;
	cout << "프로그램의 대부분의 영역에는 \"상위 메뉴로 이동\" 메뉴와 \"프로그램 종료\" 메뉴가 별도로 마련되어 있습니다." << endl;
	cout << "프로그램을 종료하실 경우에는 해당 메뉴를 꼭 이용해서 저장 후 종료하시기 바랍니다." << endl;
	cout << "본 프로그램을 이용해 주셔서 대단히 감사합니다." << endl;
	cout << "본 프로그램을 사용하다가 문제가 생기거나, 프로그램의 기능에 대한 문의가 있을 경우 언제든 아래 연락처로 연락 주시기 바랍니다." << endl;
	cout << "제작자 H.P. 010-2374-0484" << endl;
	cout << "제작자 E-mail admin@llit.kr" << endl;
	getchar();
	getchar();
	CLS
}

void mainActivity(void)
{
	mainclass MC;

	MC.getDataFromFile();

	cout << "DB 파일 Input 완료." << endl;
	cout << "프로그램을 시작합니다." << endl;

	// 메뉴 출력

	string mainmenu = "========== 도서 관리 시스템 Ver 1.3 ===========\n1. 관리 모드\n2. 학생 모드\n3. 사용 시 주의사항(처음 이용 시 필독)\n0. 프로그램 종료\n";
	int c=0;

	while(1)
	{
		c = choice(mainmenu, 1, 2, 3, 0);
		switch(c)
		{
		case 1:
			mainmenu_1(MC);
			break;
		case 2:
			mainmenu_2(MC);
			break;
		case 3:
			howToUse();
			break;
		case 0:
			mainmenu_0(MC);
			break;
		default:
			CLS
			cout << "ERROR ! (선택 값이 " << c << " 입니다. )" << endl;
			Exit(MC);
			break;
		}
	}

	return;
}

void mainmenu_1(mainclass &MC)
{
	char c[30];

	int numberOfTeacher=0;

	int select;
	while(1)
	{
		string password;
		cout << "관리자의 교직원번호를 입력하세요 : ";

		getchar();
		cin >> c;

		getchar();

		int i=0;

		while(c[i])
		{
			numberOfTeacher*=10;
			numberOfTeacher+=c[i]-'0';
			i++;
		}
//		cin >> password;				// 프로토 타입에서는 관리자 패스워드 기능을 사용하지 않음.
//		if(MC.checkAdminPassword(password)
			break;
	}

	CLS

	string menu = "1. 학생 추가하기\n2. 도서 추가하기\n3. 학생 제거하기\n4. 도서 제거하기\n5. 전체 학생 정보 열람\n6. 전체 도서 정보 열람\n7. 학생 정보 수정\n9. 상위 메뉴로 돌아가기\n0. 프로그램 종료하기\n";

	do
	{
		select = choice(menu, 1, 2, 3, 4, 5, 6, 7, 9, 0);
		switch(select)
		{
		case 1:
			submenu_1_1(MC);
			break;
		case 2:
			submenu_1_2(MC);
			break;
		case 3:
			submenu_1_3(MC);
			break;
		case 4:
			submenu_1_4(MC);
			break;
		case 5:
			submenu_1_5(MC);
			break;
		case 6:
			submenu_1_6(MC);
			break;
		case 7:
			submenu_1_7(MC);
			break;
		case 9:
			submenu_1_9(MC);
			return;
			break;
		case 0:
			submenu_1_0(MC);
			break;
		default:
			CLS
			cout << "ERROR ! (선택 값이 " << c << " 입니다. )" << endl;
			Exit(MC);
			break;
		}
	}while(select!=9);

	return;
}

void mainmenu_2(mainclass MC)
{
	char c[30];
	
	int indexOfStudent=0;

	int i=0;

	for(i=0; i<3; i++)
	{	
		int studentNumber=0;
		cout << "9. 상위 메뉴로 이동" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "학생의 학번을 입력하세요 : ";

		cin >> c;

		int j=0;

		while(c[j])
		{
			studentNumber*=10;
			studentNumber+=c[j]-'0';
			j++;
		}

		if(studentNumber==9)
			return;
		if(studentNumber==0)
			Exit(MC);

		indexOfStudent=MC.searchStudentByStudentNumber(studentNumber);

		if(indexOfStudent!=-1)
			break;
		else
		{
			CLS
			cout << "존재하지 않는 학번이거나 잘못된 값을 입력하셨습니다. 저희 학교의 학번은 8자리의 숫자로 이루어져 있습니다." << endl;
		}
		
	}

	if(i>=3)
	{
		cout << "자신의 학번을 분실하셨다면, 관리자에게 문의하시기 바랍니다. 감사합니다." << endl;
		return;
	}

	if(!MC.Vstudent[indexOfStudent].checkPassword())
		return;

	cout << "로그인에 성공했습니다." << endl;
		
	CLS

	MC.studentMode(indexOfStudent);

	return;
}

void mainmenu_0(mainclass MC)
{
	CLS

	cout << "프로그램을 종료합니다." << endl;

	Exit(MC);

	return;
}

void submenu_1_1(mainclass &MC)			// 학생 추가하기
{
	CLS
		
	char c[30];

	int numberOfStudent;

	string studentName;

	int i;

	int count=3;

	while(count)
	{
		cout << "9. 상위 메뉴로 이동" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "학생의 학번을 입력하세요 : ";

		i=0;

		numberOfStudent=0;

		cin >> c;

		CLS

		while(c[i])
		{
			numberOfStudent*=10;
			numberOfStudent+=c[i]-'0';
			i++;
		}

		if(numberOfStudent==9)
			return;
		if(numberOfStudent==0)
			Exit(MC);

		cout << "학생의 이름을 입력하세요 : ";

		cin >> studentName;

		if(MC.addStudent(numberOfStudent, studentName))
			return;
		else
			cout << endl;
		count--;
	}

	CLS

	cout << "학번을 생성할 수 없습니다." << endl;

	return;
}

void submenu_1_2(mainclass &MC)
{
	CLS

	string bookName;

	int bookNumber;

	char c[30];

	cout << "추가할 도서명을 입력하세요(띄어쓰기 불가) : ";

	cin >> bookName;

	getchar();

	int i;

	while(1)
	{
		bookNumber=0;

		CLS

		cout << "추가할 도서의 도서번호를 입력하세요. 자동으로 부여되길 원하신다면 \"-1\"을 입력하세요 : ";

		cin >> c;

		if(!strcmp(c, "-1"))
		{
			bookNumber=MC.lastNumberOfBook+1;
			MC.lastNumberOfBook++;
			MC.addBook(bookNumber, bookName);
			return;
		}

		i=0;
		bookNumber=0;

		while(c[i])
		{
			bookNumber*=10;
			if(c[i]-'0'<0 || c[i]>9)
			{
				cout << "잘못된 번호입니다." << endl;
				strcpy(c, "ERROR");
				break;
			}
			bookNumber+=c[i]-'0';
			i++;
		}
		if(!strcmp(c, "ERROR"))
			continue;
		if(bookNumber>MC.lastNumberOfBook)
			MC.lastNumberOfBook=bookNumber+1;

		MC.addBook(bookNumber, bookName);
		return;
	}

	return;
}

void submenu_1_3(mainclass &MC)		// 학생 삭제하기
{
	
	CLS

	int i=0;

	char c[30];

	int select;

	int t=0;

	while(1)
	{
		t=0;
		for(i=0; (i>8 &&i<=MC.totalStudent) || (i>=0 && i<MC.totalStudent); i++)
		{
			if(i==8)
			{
				t=1;
				cout << "9. ****** 아래 참조 ******" << endl;
				continue;
			}
			cout << i+1 << ". " << MC.Vstudent[i-t].getName() << endl;
			cout << "    " << MC.Vstudent[i-t].getNumber() << endl;
		}
		cout << "9. 상위 메뉴로 이동" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "삭제할 학생의 번호를 입력하세요 : ";

		cin >> c;

		CLS

		i=0;
		select=0;
		while(c[i])
		{
			select*=10;
			select+=c[i]-'0';
			i++;
		}

		if(select==9)
			return;
		if(select==0)
			Exit(MC);

		if(select-1>=0 && select-1<MC.totalStudent && select<9)
		{
			string check="정말로 삭제하시겠습니까 ? \n1. 예\n2. 아니오\n";
			getchar();
			int selectChoice=choice(check, 1, 2);
			if(selectChoice==1)
				MC.deleteStudent(select-1);
			break;
		}
		if(select>9 && select-1<=MC.totalStudent)
		{
			string check="정말로 삭제하시겠습니까 ? \n1. 예\n2. 아니오\n";
			getchar();
			int selectChoice=choice(check, 1, 2);
			if(selectChoice==1)
				MC.deleteStudent(select-1-t);
			break;
		}

		cout << "잘못된 선택입니다." << endl;
	}

	return;
}

void submenu_1_4(mainclass &MC)				// 도서 삭제 함수
{
	CLS

	int i=0;

	char c[30];

	int select;

	int t=0;

	while(1)
	{
		t=0;
		for(i=0; (i>8 &&i<=MC.totalBook) || (i>=0 && i<MC.totalBook); i++)
		{
			if(i==8)
			{
				t=1;
				cout << "9. ****** 아래 참조 ******" << endl;
				continue;
			}
			cout << i+1 << ". " << MC.Vbook[i-t].getName() << endl;
			cout << "    ";
			if(MC.Vbook[i-t].checkBorrowFlag()==-1)
				cout << "대출 없음" << endl;
			else
				cout << MC.Vstudent[MC.Vbook[i-t].checkBorrowFlag()].getName() << "학생이 대출" << endl;
		}
		cout << "9. 상위 메뉴로 이동" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "삭제할 도서의 번호를 입력하세요 : ";

		cin >> c;

		CLS

		i=0;
		select=0;
		while(c[i])
		{
			select*=10;
			select+=c[i]-'0';
			i++;
		}

		if(select==9)
			return;
		if(select==0)
			Exit(MC);

		if(select-1>=0 && select-1<MC.totalBook && select<9)
		{
			string check="정말로 삭제하시겠습니까 ? \n1. 예\n2. 아니오\n";
			getchar();
			int selectChoice=choice(check, 1, 2);
			if(selectChoice==1)
				MC.deleteBook(select-1);
			break;
		}
		if(select>9 && select-1<=MC.totalBook)
		{
			string check="정말로 삭제하시겠습니까 ? \n1. 예\n2. 아니오\n";
			getchar();
			int selectChlice=choice(check, 1, 2);
			if(selectChlice==1)
				MC.deleteBook(select-1-t);
			break;
		}

		cout << "잘못된 선택입니다." << endl;
	}

	return;
}

void submenu_1_5(mainclass MC)
{
	CLS

	cout << "학생 수 : " << MC.totalStudent << endl;
	
	int i=0;

	for(i=0; i<MC.totalStudent; i++)
	{
		cout << "학생명 : " << MC.Vstudent[i].getName() << endl;
		cout << "학번 : " << MC.Vstudent[i].getNumber() << endl;
		cout << "블럭 여부 : ";
		if(MC.Vstudent[i].getBlock()==true)
			cout << "BLOCKED" << endl;
		else
			cout << "UNBLOCKED" << endl;
		cout << "빌린 도서 수 : " << MC.Vstudent[i].getNumberOfBorrowedBook() << endl;
		for(int j=0; j<MC.Vstudent[i].getNumberOfBorrowedBook(); j++)
			cout << "\t" << MC.Vbook[MC.Vstudent[i].indexOfBorrowedBook[j]].getName() << endl;
		cout << endl;
	}

	return;
}

void submenu_1_6(mainclass MC)
{
	CLS

	cout << "전체 도서 수 : " << MC.totalBook << endl;

	int i=0;

	for(i=0; i<MC.totalBook; i++)
	{
		cout << "도서 번호 : " << MC.Vbook[i].getNumber() << endl;
		cout << "도서명 : " << MC.Vbook[i].getName() << endl;
		cout << "\t";

		if(MC.Vbook[i].checkBorrowFlag()==-1)
			cout << "대출 없음";
		else
			cout << MC.Vstudent[MC.Vbook[i].checkBorrowFlag()].getName() << " 학생이 대출";

		cout << endl;
		cout << endl;
	}

	return;
}

void submenu_1_7(mainclass &MC)
{
	CLS

	int t=0;
	char c[30];
	int i;
	int select;

	string name;

	bool block;

	while(1)
	{
		t=0;
		for(i=0; (i>8 &&i<=MC.totalStudent) || (i>=0 && i<MC.totalStudent); i++)
		{
			if(i==9)
			{
				t=1;
				cout << "9. ****** 아래 참조 ******" << endl;
				continue;
			}
			cout << i+1 << ". " << MC.Vstudent[i-t].getName() << endl;
			cout << "    " << MC.Vstudent[i-t].getNumber() << endl;
		}
		cout << "9. 상위 메뉴로 이동" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "정보를 수정할 학생의 번호를 입력하세요 : ";

		cin >> c;

		CLS

		i=0;
		select=0;
		while(c[i])
		{
			select*=10;
			select+=c[i]-'0';
			i++;
		}

		if(select==9)
			return;
		if(select==0)
			Exit(MC);

		if(select-1>=0 && select-1<MC.totalStudent && select<9)
		{
			select--;
			break;
		}
		if(select>9 && select-1<=MC.totalStudent)
		{
			select-=1+t;
			break;
		}

		cout << "잘못된 선택입니다." << endl;
	}

	cout << MC.Vstudent[select].getName() << " 학생의 정보를 수정합니다." << endl;

	string modifyMenu = "1. 학생 이름 변경\n2. 학생 블럭 상태 변경\n9. 상위 메뉴로 이동\n0. 프로그램 종료\n";

	int selectChoice=choice(modifyMenu, 1, 2, 9, 0);

	switch(selectChoice)
	{
	case 0:
		Exit(MC);
		break;
	case 9:
		break;
	case 1:
		cout << "변경할 이름을 입력하세요 : ";
		cin >> name;
		CLS
		cout << MC.Vstudent[select].getName();
		MC.Vstudent[select].setName(name);
		cout << " 학생의 이름이 " << MC.Vstudent[select].getName() << " 으로 변경되었습니다." << endl;
		break;
	case 2:
		cout << "현재 " << MC.Vstudent[select].getName() << " 학생은 ";

		if(MC.Vstudent[select].getBlock())
		{
			cout << "블럭 상태입니다. ";
			string blockmenu = "블럭을 해제하시겠습니까 ? \n1. 예. 해제합니다.\n9. 상위 메뉴로 돌아가기.\n";
			selectChoice = choice(blockmenu, 1, 9);
			if(selectChoice==1)
			{
				MC.Vstudent[select].setBlock(false);
				return;
			}
			return;
		}
		else
		{
			cout << "블럭 상태가 아닙니다. ";
			string blockmenu = "블럭 상태로 전환하시겠습니까 ? \n1. 예. 블럭 상태로 전환합니다.\n9. 상위 메뉴로 돌아가기.\n";
			selectChoice = choice(blockmenu, 1, 9);
			if(selectChoice==1)
			{
				MC.Vstudent[select].setBlock(true);
				return;
			}
			return;
		}
	}

	return;
}

void submenu_1_9(mainclass MC)
{
	CLS

	cout << "상위 메뉴로 이동하였습니다." << endl;

	return;
}

void submenu_1_0(mainclass MC)
{
	CLS

	cout << "프로그램을 종료합니다." << endl;

	Exit(MC);

	return;
}


int choice(string menu, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n)
{
	int select;
	char selectChar[30];
	int count;
	while(1)
	{
		select=0;
		cout << menu;
		cout << "원하는 번호를 선택하세요 : ";
		cin >> selectChar;
		count=0;

		while(selectChar[count])
		{
			select*=10;
			select+=selectChar[count]-'0';
			count++;
		}
		if( select==a || (select==b && b!=-1) || (select==c && c!=-1) || (select==d && d!=-1) || (select==e && e!=-1) || (select==f && f!=-1) || (select==g && g!=-1) || (select==h && h!=-1) || (select==i && i!=-1) || (select==j && j!=-1) || (select==k && k!=-1) || (select==l && l!=-1) || (select==m && m!=-1) || (select==n && n!=-1) )
		{
			CLS
			return select;
		}
		else
		{
			CLS
			cout << "잘못된 선택입니다." << endl;
		}
	}
}

ifstream openInputFile(const string fileName)
{
	ifstream fin;
	cout << "Input 파일 연결 중 . . ." << endl;
	fin.open(fileName);
	cout << "Input 파일 생성 완료. 파일 명 " << fileName << endl;
	return fin;
}

void closeInputFile(ifstream& fin)
{
	cout << "Input 파일 닫는 중 . . ." << endl;
	fin.close();
	cout << "Input 파일 닫기 완료" << endl;
	return;
}

ofstream openOutputFile(const string fileName)
{
	ofstream fout;
	cout << "Output 파일 생성 중 . . ." << endl;
	fout.open(fileName);
	cout << "Output 파일 생성 완료. 파일 명 " << fileName << endl;
	return fout;
}

void closeOutputFile(ofstream& fout)
{
	cout << "Output 파일 닫는 중 . . ." << endl;
	fout.close();
	cout << "Output 파일 닫기 완료" << endl;
	return;
}

void pushIntArray(int* arr, const int index, const int arrSize)		// (배열, 지점, 배열 크기)를 인자로 받아 배열의 해당 지점에 있는 값을 삭제하고 그 뒤의 모든 값을 한 칸씩 당긴 후 마지막 칸에 -1을 채워넣기
{
	int i=0;
	for(i=index; i<arrSize-1; i++)
		arr[i]=arr[i+1];
	arr[arrSize-1] = -1;
}

void mainclass::getDataFromFile()
{
	ifstream fin = openInputFile(DBFILE);
	int TotalStudent;
	int TotalBook;
	string tempName;
	int tempNumber;
	int tempNumberOfBorrowedBook;
	int tempIndexOfBorrowedBook;
	int tempPassword;
	bool tempBlock;
	int tempBorrowFlag;
	fin >> TotalStudent;
	totalStudent=TotalStudent;
	lastNumberOfBook=-1;
	Vstudent = new student[TotalStudent];

	cout << "필요 변수 선언 완료" << endl;
	/*
	데이터 파일 저장 양식
		N(학생 수)
		i번째 학생	이름
					학번
					빌린 책 수
					암호화된 비밀번호
					블럭 여부(true/false)
					빌린 책 인덱스
						j번째 책
						j+1번째 책
						...

		M(도서 수)
		i번째 도서	이름
					도서 번호
					대출 플래그
					...
	*/
					
	for(int i=0; i<TotalStudent; i++)
	{
		fin >> tempName >> tempNumber >> tempNumberOfBorrowedBook >> tempPassword >> tempBlock;

		cout << i+1 << "번째 임시 변수로 파일로부터 입력 완료" << endl;

		Vstudent[i].indexOfBorrowedBook = new int[tempNumberOfBorrowedBook];

		Vstudent[i].setName(tempName);
		Vstudent[i].setNumber(tempNumber);
		Vstudent[i].setNumberOfBorrowedBook(tempNumberOfBorrowedBook);
		Vstudent[i].setSecurePassword(tempPassword);
		Vstudent[i].justSetBlock(tempBlock);
		for(int j=0; j<tempNumberOfBorrowedBook; j++)
		{
			fin >> tempIndexOfBorrowedBook;
			Vstudent[i].indexOfBorrowedBook[j] = tempIndexOfBorrowedBook;
		}
		cout << i+1 << "번째 학생 데이터 입력 완료" << endl;
	}

	fin >> TotalBook;

	totalBook = TotalBook;

	Vbook = new book[TotalBook];

	for(int i=0; i<TotalBook; i++)
	{
		fin >> tempName >> tempNumber >> tempBorrowFlag;
		if(lastNumberOfBook<tempNumber)
			lastNumberOfBook=tempNumber;
		cout << i+1 << "번째 임시 변수로 파일로부터 입력 완료" << endl;
		Vbook[i].setName(tempName);
		Vbook[i].setNumber(tempNumber);
		Vbook[i].setBorrowFlag(tempBorrowFlag);
		cout << i+1 << "번째 도서 데이터 입력 완료" << endl;
	}
	closeInputFile(fin);
	CLS
}

void mainclass::pushDataToFile()
{
	ofstream fout = openOutputFile(DBFILE);
	/*
	데이터 파일 저장 양식
		N(학생 수)
		i번째 학생	이름
					학번
					빌린 책 수
					암호화된 비밀번호
					블럭 여부(true/false)
					빌린 책 인덱스
						j번째 책
						j+1번째 책
						...

		M(도서 수)
		i번째 도서	이름
					도서 번호
					대출 플래그
					...
	*/

	fout << totalStudent << endl;

	for(int i=0; i<totalStudent; i++)
	{
		fout << Vstudent[i].getName() << endl;
		fout << Vstudent[i].getNumber() << endl;
		fout << Vstudent[i].getNumberOfBorrowedBook() << endl;
		fout << Vstudent[i].getPassword() << endl;
		fout << Vstudent[i].getBlock() << endl;
		for(int j=0; j<Vstudent[i].getNumberOfBorrowedBook(); j++)
			fout << Vstudent[i].indexOfBorrowedBook[j] << endl;
	}

	fout << totalBook << endl;

	for(int i=0; i<totalBook; i++)
	{
		fout << Vbook[i].getName() << endl;
		fout << Vbook[i].getNumber() << endl;
		fout << Vbook[i].checkBorrowFlag() << endl;
	}

	closeOutputFile(fout);
}

int mainclass::borrowBook(const int indexOfBorrowBook, const int indexOfBorrowStudent)		// 미완성*********
{
	CLS
	if(Vbook[indexOfBorrowBook].checkBorrowFlag()==-1)		// 대출 가능
	{
		Vbook[indexOfBorrowBook].setBorrowFlag(indexOfBorrowStudent);
		int* tempArray = new int[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()+1];
		for(int i = 0; i < Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook(); i++)
			tempArray[i] = Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i];
		if(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()!=0)
		{
//			cout << "본 학생의 빌린 책 수가 " << Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() << "개이므로 if문 진입 성공" << endl;
			delete []Vstudent[indexOfBorrowStudent].indexOfBorrowedBook;
		}
		Vstudent[indexOfBorrowStudent].setNumberOfBorrowedBook(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()+1);
		Vstudent[indexOfBorrowStudent].indexOfBorrowedBook = new int[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()];
		for(int i = 0; i < Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook(); i++)
			Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i] = tempArray[i];
		delete []tempArray;
		Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()-1]=indexOfBorrowBook;
		cout << Vbook[indexOfBorrowBook].getName() << " 도서를 성공적으로 대출하였습니다. 반납일은 (미구현)까지입니다." << endl;
		return 1;
	}
	else if(Vbook[indexOfBorrowBook].checkBorrowFlag()==indexOfBorrowStudent)
	{
		cout << "이미 \"" << Vbook[indexOfBorrowBook].getName() << "\" 도서를 대출하셨습니다. 저희 도서관에서 같은 도서를 두 권 대출하실 수 없습니다." << endl;
		return 0;
	}
	else
	{
		cout << "\"" <<Vbook[indexOfBorrowBook].getName() << "\" 도서는 다른 회원이 이미 대출하셨습니다. (미구현) 이후에 다시 방문해 주세요." << endl;
		return 0;
	}
}

void mainclass::borrowMenu(const int indexOfBorrowStudent)
{
	CLS
	int i=0;

	char c[30];

	int t=0;
	
	while(1)
	{
		for(i=0; i<totalBook || (i>8 && i<=totalBook); i++)
		{
			if(i==8)
			{
				cout << "9. ****** 아래 참조 ******" << endl;
				t=1;
				continue;
			}
			cout << i+1 << ". " << Vbook[i-t].getName() << " - ";
			if(Vbook[i-t].checkBorrowFlag()==-1)
				cout << "대출 가능" << endl;
			else
				cout << "대출 불가" << endl;
		}

		cout << "0. 프로그램 종료\n9. 상위 메뉴로 이동" << endl;
		cout << "대출을 원하는 도서의 번호를 입력하세요 : ";

		cin >> c;

		getchar();

		i=0;

		int r=0;

		while(c[i])
		{
			r*=10;
			r+=c[i]-'0';
			i++;
		}

		CLS

		if(r==0)
			Exit(*this);

		if(r==9)
			return;

		if(r>0 && r<=8)
		{
			if(borrowBook(r-1, indexOfBorrowStudent))
				break;
			t=0;
		}
		else if(r>8 && r<=totalBook+1)
		{
			if(borrowBook(r-1-t, indexOfBorrowStudent))
				break;
			t=0;
		}
		else
		{
			cout << "잘못된 선택입니다." << endl;
			t=0;
			break;
		}
	}
	return;
}

int mainclass::returnBook(const int indexOfBorrowBook, const int indexOfBorrowStudent)
{
	if(Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].checkBorrowFlag()!=indexOfBorrowStudent)
	{
		cout << Vstudent[indexOfBorrowStudent].getName() << " 학생은 \"" << Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].getName() << "\" 도서를 대출하지 않으셨습니다. 반납할 수 없습니다." << endl;
		return 0;
	}
	else
	{
		cout << "\"" << Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].getName() << "\" 도서를 성공적으로 반납하였습니다." << endl;
		Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].setBorrowFlag(-1);
		pushIntArray(Vstudent[indexOfBorrowStudent].indexOfBorrowedBook, indexOfBorrowBook, Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook());
			// 빌린 학생 객체의 빌린 책 인덱스로부터 빌릴 책 인덱스를 삭제하고 뒤에 있는 모든 값들을 앞으로 한 칸씩 당기기
		int* tempArray = new int[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()];
		for(int i=0; i<Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook(); i++)
			tempArray[i] = Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i];
		delete []Vstudent[indexOfBorrowStudent].indexOfBorrowedBook;
		Vstudent[indexOfBorrowStudent].indexOfBorrowedBook = new int[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()];
		for(int i=0; i<Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook(); i++)
			Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i] = tempArray[i];

		delete []tempArray;
		Vstudent[indexOfBorrowStudent].setNumberOfBorrowedBook(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()-1);
		return 1;
	}
}

void mainclass::returnMenu(const int indexOfBorrowStudent)
{
	int t=0;
	CLS
	if(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()==0)
	{
		cout << Vstudent[indexOfBorrowStudent].getName() << " 학생은 현재 대출한 도서가 없습니다." << endl;
		return;
	}
	else if(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()<0)
	{
		cout << "오류가 발생했습니다. 해당 학생이 대출한 도서의 갯수 값이 음수입니다. 프로그램 소스를 참조하세요." << endl;
		return;
	}

	char c[30];

	while(1)
	{
		cout << "대출 도서 갯수 : " << Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() << endl;

		for(int i = 0; i < Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() || (i>8 && i<=Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()); i++)		// 에러
		{
			if(i==8)
			{
				cout << "9. ****** 아래 참조 ******" << endl;
				t=1;
				continue;
			}
			cout << i+1 << ". " << Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i-t]].getName() << endl;
		}

		cout << "0. 프로그램 종료\n9. 상위 메뉴로 이동" << endl;

		cout << "반납을 원하는 도서의 번호를 선택하세요 : ";

		cin >> c;

		getchar();

		int i=0;

		int r=0;

		while(c[i])
		{
			r*=10;
			r+=c[i]-'0';
			i++;
		}

		CLS

		if(r==9)
			return;
		else if(r==0)
			Exit(*this);
		else if(r>0 && r<=Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() && r<9)
		{
			if(returnBook(r-1, indexOfBorrowStudent))
				break;
		}
		else if(r>8 && r<=Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()+1)
		{
			if(returnBook(r-1-t, indexOfBorrowStudent))
				break;
		}
		CLS
		cout << "잘못된 선택을 하셨습니다." << endl;
	}
}

void mainclass::modifyInformation(int indexOfStudent)
{
	string modifyMenu = "1. 이름 변경\n2. 암호 변경\n9. 상위 메뉴로 이동\n0. 프로그램 종료\n";

	int select = choice(modifyMenu, 1, 2, 9, 0);

	string name;

	string password;

	switch(select)
	{
	case 1:
		cout << "원하는 이름을 입력하세요 : ";
		cin >> name;
		CLS
		Vstudent[indexOfStudent].setName(name);
		cout << "학생의 이름이 성공적으로 변경되었습니다." << endl;
		break;
	case 2:
		cout << "현재 ";
		if(Vstudent[indexOfStudent].checkPassword())
		{
			while(1)
			{
				string passwordForCheck;
				cout << "변경하고싶은 암호를 입력하세요 : ";
				cin >> password;
				CLS
				cout << "다시 한 번 입력하세요 : ";
				cin >> passwordForCheck;
				CLS
				if(password==passwordForCheck)
				{
					Vstudent[indexOfStudent].setPassword(password);
					cout << "암호가 성공적으로 변경되었습니다." << endl;
					return;
				}
				cout << "잘못되었습니다." << endl;
			}
			return;
		}
		break;
	case 9:
		break;
	case 0:
		Exit(*this);
	}
}

int mainclass::gettotalBook(void)
{
	return totalBook;
}
int mainclass::gettotalStudent(void)
{
	return totalStudent;
}

int mainclass::searchStudentByStudentNumber(int studentNumber)
{
	for(int i=0; i<totalStudent; i++)
		if(Vstudent[i].getNumber()==studentNumber)
			return i;
	return -1;
}

void mainclass::studentMode(int indexOfStudent)
{
	string menu = "1. 도서 대출\n2. 도서 반납\n3. 개인정보 수정\n9. 상위 메뉴로 이동\n0. 프로그램 종료\n";

	int c = 0;
	
	while(1)
	{
		c = choice(menu, 1, 2, 3, 9, 0);
		switch(c)
		{
		case 1:			// 도서 대출
			borrowMenu(indexOfStudent);
			break;
		case 2:			// 도서 반납
			returnMenu(indexOfStudent);
			break;
		case 3:			// 개인정보 수정
			modifyInformation(indexOfStudent);
			break;
		case 9:			// 상위 메뉴로 이동
			return;
			break;
		case 0:			// 프로그램 종료
			CLS

			cout << "프로그램을 종료합니다." << endl;

			Exit(*this);
			break;
		}
	}
}

bool mainclass::addStudent(int numberOfStudent, string studentName)
{
	int i=0;

	if(numberOfStudent>99999999 || 10000000>numberOfStudent)
	{
		CLS
		cout << "학번은 8자리의 숫자들로 이루어져야 합니다. 학생 생성에 실패하였습니다." << endl;
		return false;
	}

	student *temp = new student[totalStudent+1];

	for(i=0; i<totalStudent; i++)
	{
		temp[i] = Vstudent[i];
		if(numberOfStudent==Vstudent[i].getNumber())
		{
			CLS
			cout << "해당 학번은 이미 등록되어 있습니다. 암호를 분실하셨다면, 관리자에게 문의하시기 바랍니다." << endl;
			delete[] temp;
			return false;
		}
	}

	temp[totalStudent].setBlock(false);
	temp[totalStudent].setName(studentName);
	temp[totalStudent].setNumber(numberOfStudent);
	temp[totalStudent].setNumberOfBorrowedBook(0);

	string password;

	CLS

	while(1)
	{
		string passwordForCheck;

		cout << "암호를 입력해 주세요 : ";

		cin >> password;

		CLS

		cout << "암호를 한 번 더 입력해 주세요 : ";

		cin >> passwordForCheck;

		if(password==passwordForCheck)
			break;

		CLS

		cout << "암호를 잘못 입력하셨습니다." << endl;
	}

	CLS

	temp[totalStudent].setPassword(password);

	totalStudent++;

	delete[] Vstudent;

	Vstudent = new student[totalStudent];

	for(i=0; i<totalStudent; i++)
		Vstudent[i] = temp[i];

	delete[] temp;

	cout << "성공적으로 학생을 생성하였습니다." << endl;

	return true;
}

void mainclass::deleteStudent(int indexOfStudent)
{
	student *temp = new student[totalStudent];
	
	int i=0;

	for(i=0; i<Vstudent[indexOfStudent].getNumberOfBorrowedBook(); i++)
		Vbook[Vstudent[indexOfStudent].indexOfBorrowedBook[i]].setBorrowFlag(-1);

	for(i=indexOfStudent; i<totalStudent-1; i++)
		Vstudent[i] = Vstudent[i+1];

	for(i=0; i<totalStudent-1; i++)
		temp[i]=Vstudent[i];

	delete[] Vstudent;
	Vstudent = new student[totalStudent-1];

	totalStudent--;

	for(i=0; i<totalStudent; i++)
		Vstudent[i] = temp[i];

	delete[] temp;

	cout << "성공적으로 학생을 제거하였습니다." << endl;
}

void mainclass::addBook(int numberOfBook, string bookName)
{
	book *temp = new book[totalBook+1];

	int i;

	for(i=0; i<totalBook; i++)
		temp[i] = Vbook[i];

	temp[totalBook].setBorrowFlag(-1);
	temp[totalBook].setName(bookName);
	temp[totalBook].setNumber(numberOfBook);

	delete[] Vbook;

	Vbook = new book[totalBook+1];

	for(i=0; i<totalBook+1; i++)
		Vbook[i] = temp[i];

	delete[] temp;

	totalBook++;

	CLS

	cout << "도서가 성공적으로 등록되었습니다." << endl;

	return;
}

void mainclass::deleteBook(int indexOfBook)
{
	book *temp = new book[totalBook];

	int i=0;

	if(Vbook[indexOfBook].checkBorrowFlag()!=-1)
	{
		returnBook(indexOfBook, Vbook[indexOfBook].checkBorrowFlag());
	}

	for(i=indexOfBook; i<totalBook-1; i++)
		Vbook[i]=Vbook[i+1];

	for(i=0; i<totalBook-1; i++)
		temp[i] = Vbook[i];

	delete[] Vbook;

	Vbook = new book[totalBook-1];

	for(i=0; i<totalBook-1; i++)
		Vbook[i]=temp[i];

	delete[] temp;
}
	
void book::setName(const string name)
{
	this->name = name;
}

void book::setNumber(const int number)
{
	this->number = number;
}

void book::setBorrowFlag(const int borrowFlag)
{
	this->borrowFlag = borrowFlag;
}

int book::checkBorrowFlag(void)
{
	return borrowFlag;
}

string book::getName(void)
{
	return name;
}

int book::getNumber(void)
{
	return number;
}

void student::setName(const string name)
{
	this->name=name;
}

void student::setNumber(const int number)
{
	studentNumber = number;
}

string student::getName(void)
{
	return name;
}

int student::getNumber(void)
{
	return studentNumber;
}

int student::checkPassword(void)
{
	if(!block)
	{
		for(int i=0; i<3; i++)
		{
			cout << name << " 학생의 암호를 입력하세요 : ";
			string password;
			cin >> password;
			CLS
			if(encrypt(password)==this->password)
				return 1;
			else
				cout << "암호가 틀렸습니다. ";
		}
		cout << "암호가 3회 이상 틀렸습니다.";
		setBlock(true);
		cout << "계정의 블럭 상태를 해제하기 위해서 관리자에게 문의하시기 바랍니다." << endl;

		return 0;
	}
	else if(block==1)
	{
		CLS
		cout << "현재 해당 계정은 블럭 상태입니다. 계정의 블럭 상태를 해제하기 위해서 관리자에게 문의하시기 바랍니다." << endl;
		return 0;
	}
	else
	{
		cout << "존재하지 않는 학번입니다." << endl;
		return 0;
	}
}

int student::getNumberOfBorrowedBook(void)
{
	return numberOfBorrowedBook;
}

void student::setNumberOfBorrowedBook(const int number)
{
	numberOfBorrowedBook=number;
}

int student::getPassword(void)
{
	return password;
}

bool student::getBlock(void)
{
	return block;
}

void student::setPassword(const string password)
{
	this->password = encrypt(password);
}

void student::setSecurePassword(const int password)
{
	this->password = password;
}

void student::justSetBlock(const bool boolish)
{
	block=boolish;
}

void student::setBlock(const bool boolish)
{
	if(boolish==false)
		if(block==true)
			cout << "계정의 블럭 상태가 해제되었습니다." << endl;
		else
			cout << "계정이 블럭 상태가 아닙니다." << endl;
	else
		if(block==false)
			cout << "계정이 블럭 상태로 전환되었습니다." << endl;
		else
			cout << "계정이 이미 블럭 상태입니다." << endl;
	block=boolish;
}