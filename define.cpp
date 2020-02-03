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

	cout << "�� ���α׷��� MySQL�� ���� DB�� ����ϴ� ��� �Ϲ����� text ������ DBȭ���� ������ ���α׷��Դϴ�." << endl;
	cout << "���� ���ϰ� �� ���α׷��� ó������ ����ϽŴٸ�, ���α׷� ���ϰ� ������ ������ \"" << DBFILE << "\"��� �̸��� ������ �����˴ϴ�." << endl;
	cout << "�ش� ������ ����� �������� ���ñ� �ǰ�帳�ϴ�. �� ���α׷����� ����ϴ� ��� �����Ͱ� ������ ��Ĵ�� �ش� ���Ͽ� ����Ǿ� �ֽ��ϴ�." << endl;
	cout << "���� �� ���α׷��� ����ϴ� �� �ܼ� â�� ���� ��ܿ� �ִ� X ��ư�� Ŭ���Ͻðų� ���μ��� ���� ���� �� ���������� ������� ���α׷��� ������ ���, ��������� ������� ���� �� �ֽ��ϴ�." << endl;
	cout << "���α׷��� ��κ��� �������� \"���� �޴��� �̵�\" �޴��� \"���α׷� ����\" �޴��� ������ ���õǾ� �ֽ��ϴ�." << endl;
	cout << "���α׷��� �����Ͻ� ��쿡�� �ش� �޴��� �� �̿��ؼ� ���� �� �����Ͻñ� �ٶ��ϴ�." << endl;
	cout << "�� ���α׷��� �̿��� �ּż� ����� �����մϴ�." << endl;
	cout << "�� ���α׷��� ����ϴٰ� ������ ����ų�, ���α׷��� ��ɿ� ���� ���ǰ� ���� ��� ������ �Ʒ� ����ó�� ���� �ֽñ� �ٶ��ϴ�." << endl;
	cout << "������ H.P. 010-2374-0484" << endl;
	cout << "������ E-mail admin@llit.kr" << endl;
	getchar();
	getchar();
	CLS
}

void mainActivity(void)
{
	mainclass MC;

	MC.getDataFromFile();

	cout << "DB ���� Input �Ϸ�." << endl;
	cout << "���α׷��� �����մϴ�." << endl;

	// �޴� ���

	string mainmenu = "========== ���� ���� �ý��� Ver 1.3 ===========\n1. ���� ���\n2. �л� ���\n3. ��� �� ���ǻ���(ó�� �̿� �� �ʵ�)\n0. ���α׷� ����\n";
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
			cout << "ERROR ! (���� ���� " << c << " �Դϴ�. )" << endl;
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
		cout << "�������� ��������ȣ�� �Է��ϼ��� : ";

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
//		cin >> password;				// ������ Ÿ�Կ����� ������ �н����� ����� ������� ����.
//		if(MC.checkAdminPassword(password)
			break;
	}

	CLS

	string menu = "1. �л� �߰��ϱ�\n2. ���� �߰��ϱ�\n3. �л� �����ϱ�\n4. ���� �����ϱ�\n5. ��ü �л� ���� ����\n6. ��ü ���� ���� ����\n7. �л� ���� ����\n9. ���� �޴��� ���ư���\n0. ���α׷� �����ϱ�\n";

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
			cout << "ERROR ! (���� ���� " << c << " �Դϴ�. )" << endl;
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
		cout << "9. ���� �޴��� �̵�" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "�л��� �й��� �Է��ϼ��� : ";

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
			cout << "�������� �ʴ� �й��̰ų� �߸��� ���� �Է��ϼ̽��ϴ�. ���� �б��� �й��� 8�ڸ��� ���ڷ� �̷���� �ֽ��ϴ�." << endl;
		}
		
	}

	if(i>=3)
	{
		cout << "�ڽ��� �й��� �н��ϼ̴ٸ�, �����ڿ��� �����Ͻñ� �ٶ��ϴ�. �����մϴ�." << endl;
		return;
	}

	if(!MC.Vstudent[indexOfStudent].checkPassword())
		return;

	cout << "�α��ο� �����߽��ϴ�." << endl;
		
	CLS

	MC.studentMode(indexOfStudent);

	return;
}

void mainmenu_0(mainclass MC)
{
	CLS

	cout << "���α׷��� �����մϴ�." << endl;

	Exit(MC);

	return;
}

void submenu_1_1(mainclass &MC)			// �л� �߰��ϱ�
{
	CLS
		
	char c[30];

	int numberOfStudent;

	string studentName;

	int i;

	int count=3;

	while(count)
	{
		cout << "9. ���� �޴��� �̵�" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "�л��� �й��� �Է��ϼ��� : ";

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

		cout << "�л��� �̸��� �Է��ϼ��� : ";

		cin >> studentName;

		if(MC.addStudent(numberOfStudent, studentName))
			return;
		else
			cout << endl;
		count--;
	}

	CLS

	cout << "�й��� ������ �� �����ϴ�." << endl;

	return;
}

void submenu_1_2(mainclass &MC)
{
	CLS

	string bookName;

	int bookNumber;

	char c[30];

	cout << "�߰��� �������� �Է��ϼ���(���� �Ұ�) : ";

	cin >> bookName;

	getchar();

	int i;

	while(1)
	{
		bookNumber=0;

		CLS

		cout << "�߰��� ������ ������ȣ�� �Է��ϼ���. �ڵ����� �ο��Ǳ� ���ϽŴٸ� \"-1\"�� �Է��ϼ��� : ";

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
				cout << "�߸��� ��ȣ�Դϴ�." << endl;
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

void submenu_1_3(mainclass &MC)		// �л� �����ϱ�
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
				cout << "9. ****** �Ʒ� ���� ******" << endl;
				continue;
			}
			cout << i+1 << ". " << MC.Vstudent[i-t].getName() << endl;
			cout << "    " << MC.Vstudent[i-t].getNumber() << endl;
		}
		cout << "9. ���� �޴��� �̵�" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "������ �л��� ��ȣ�� �Է��ϼ��� : ";

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
			string check="������ �����Ͻðڽ��ϱ� ? \n1. ��\n2. �ƴϿ�\n";
			getchar();
			int selectChoice=choice(check, 1, 2);
			if(selectChoice==1)
				MC.deleteStudent(select-1);
			break;
		}
		if(select>9 && select-1<=MC.totalStudent)
		{
			string check="������ �����Ͻðڽ��ϱ� ? \n1. ��\n2. �ƴϿ�\n";
			getchar();
			int selectChoice=choice(check, 1, 2);
			if(selectChoice==1)
				MC.deleteStudent(select-1-t);
			break;
		}

		cout << "�߸��� �����Դϴ�." << endl;
	}

	return;
}

void submenu_1_4(mainclass &MC)				// ���� ���� �Լ�
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
				cout << "9. ****** �Ʒ� ���� ******" << endl;
				continue;
			}
			cout << i+1 << ". " << MC.Vbook[i-t].getName() << endl;
			cout << "    ";
			if(MC.Vbook[i-t].checkBorrowFlag()==-1)
				cout << "���� ����" << endl;
			else
				cout << MC.Vstudent[MC.Vbook[i-t].checkBorrowFlag()].getName() << "�л��� ����" << endl;
		}
		cout << "9. ���� �޴��� �̵�" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "������ ������ ��ȣ�� �Է��ϼ��� : ";

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
			string check="������ �����Ͻðڽ��ϱ� ? \n1. ��\n2. �ƴϿ�\n";
			getchar();
			int selectChoice=choice(check, 1, 2);
			if(selectChoice==1)
				MC.deleteBook(select-1);
			break;
		}
		if(select>9 && select-1<=MC.totalBook)
		{
			string check="������ �����Ͻðڽ��ϱ� ? \n1. ��\n2. �ƴϿ�\n";
			getchar();
			int selectChlice=choice(check, 1, 2);
			if(selectChlice==1)
				MC.deleteBook(select-1-t);
			break;
		}

		cout << "�߸��� �����Դϴ�." << endl;
	}

	return;
}

void submenu_1_5(mainclass MC)
{
	CLS

	cout << "�л� �� : " << MC.totalStudent << endl;
	
	int i=0;

	for(i=0; i<MC.totalStudent; i++)
	{
		cout << "�л��� : " << MC.Vstudent[i].getName() << endl;
		cout << "�й� : " << MC.Vstudent[i].getNumber() << endl;
		cout << "�� ���� : ";
		if(MC.Vstudent[i].getBlock()==true)
			cout << "BLOCKED" << endl;
		else
			cout << "UNBLOCKED" << endl;
		cout << "���� ���� �� : " << MC.Vstudent[i].getNumberOfBorrowedBook() << endl;
		for(int j=0; j<MC.Vstudent[i].getNumberOfBorrowedBook(); j++)
			cout << "\t" << MC.Vbook[MC.Vstudent[i].indexOfBorrowedBook[j]].getName() << endl;
		cout << endl;
	}

	return;
}

void submenu_1_6(mainclass MC)
{
	CLS

	cout << "��ü ���� �� : " << MC.totalBook << endl;

	int i=0;

	for(i=0; i<MC.totalBook; i++)
	{
		cout << "���� ��ȣ : " << MC.Vbook[i].getNumber() << endl;
		cout << "������ : " << MC.Vbook[i].getName() << endl;
		cout << "\t";

		if(MC.Vbook[i].checkBorrowFlag()==-1)
			cout << "���� ����";
		else
			cout << MC.Vstudent[MC.Vbook[i].checkBorrowFlag()].getName() << " �л��� ����";

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
				cout << "9. ****** �Ʒ� ���� ******" << endl;
				continue;
			}
			cout << i+1 << ". " << MC.Vstudent[i-t].getName() << endl;
			cout << "    " << MC.Vstudent[i-t].getNumber() << endl;
		}
		cout << "9. ���� �޴��� �̵�" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "������ ������ �л��� ��ȣ�� �Է��ϼ��� : ";

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

		cout << "�߸��� �����Դϴ�." << endl;
	}

	cout << MC.Vstudent[select].getName() << " �л��� ������ �����մϴ�." << endl;

	string modifyMenu = "1. �л� �̸� ����\n2. �л� �� ���� ����\n9. ���� �޴��� �̵�\n0. ���α׷� ����\n";

	int selectChoice=choice(modifyMenu, 1, 2, 9, 0);

	switch(selectChoice)
	{
	case 0:
		Exit(MC);
		break;
	case 9:
		break;
	case 1:
		cout << "������ �̸��� �Է��ϼ��� : ";
		cin >> name;
		CLS
		cout << MC.Vstudent[select].getName();
		MC.Vstudent[select].setName(name);
		cout << " �л��� �̸��� " << MC.Vstudent[select].getName() << " ���� ����Ǿ����ϴ�." << endl;
		break;
	case 2:
		cout << "���� " << MC.Vstudent[select].getName() << " �л��� ";

		if(MC.Vstudent[select].getBlock())
		{
			cout << "�� �����Դϴ�. ";
			string blockmenu = "���� �����Ͻðڽ��ϱ� ? \n1. ��. �����մϴ�.\n9. ���� �޴��� ���ư���.\n";
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
			cout << "�� ���°� �ƴմϴ�. ";
			string blockmenu = "�� ���·� ��ȯ�Ͻðڽ��ϱ� ? \n1. ��. �� ���·� ��ȯ�մϴ�.\n9. ���� �޴��� ���ư���.\n";
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

	cout << "���� �޴��� �̵��Ͽ����ϴ�." << endl;

	return;
}

void submenu_1_0(mainclass MC)
{
	CLS

	cout << "���α׷��� �����մϴ�." << endl;

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
		cout << "���ϴ� ��ȣ�� �����ϼ��� : ";
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
			cout << "�߸��� �����Դϴ�." << endl;
		}
	}
}

ifstream openInputFile(const string fileName)
{
	ifstream fin;
	cout << "Input ���� ���� �� . . ." << endl;
	fin.open(fileName);
	cout << "Input ���� ���� �Ϸ�. ���� �� " << fileName << endl;
	return fin;
}

void closeInputFile(ifstream& fin)
{
	cout << "Input ���� �ݴ� �� . . ." << endl;
	fin.close();
	cout << "Input ���� �ݱ� �Ϸ�" << endl;
	return;
}

ofstream openOutputFile(const string fileName)
{
	ofstream fout;
	cout << "Output ���� ���� �� . . ." << endl;
	fout.open(fileName);
	cout << "Output ���� ���� �Ϸ�. ���� �� " << fileName << endl;
	return fout;
}

void closeOutputFile(ofstream& fout)
{
	cout << "Output ���� �ݴ� �� . . ." << endl;
	fout.close();
	cout << "Output ���� �ݱ� �Ϸ�" << endl;
	return;
}

void pushIntArray(int* arr, const int index, const int arrSize)		// (�迭, ����, �迭 ũ��)�� ���ڷ� �޾� �迭�� �ش� ������ �ִ� ���� �����ϰ� �� ���� ��� ���� �� ĭ�� ��� �� ������ ĭ�� -1�� ä���ֱ�
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

	cout << "�ʿ� ���� ���� �Ϸ�" << endl;
	/*
	������ ���� ���� ���
		N(�л� ��)
		i��° �л�	�̸�
					�й�
					���� å ��
					��ȣȭ�� ��й�ȣ
					�� ����(true/false)
					���� å �ε���
						j��° å
						j+1��° å
						...

		M(���� ��)
		i��° ����	�̸�
					���� ��ȣ
					���� �÷���
					...
	*/
					
	for(int i=0; i<TotalStudent; i++)
	{
		fin >> tempName >> tempNumber >> tempNumberOfBorrowedBook >> tempPassword >> tempBlock;

		cout << i+1 << "��° �ӽ� ������ ���Ϸκ��� �Է� �Ϸ�" << endl;

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
		cout << i+1 << "��° �л� ������ �Է� �Ϸ�" << endl;
	}

	fin >> TotalBook;

	totalBook = TotalBook;

	Vbook = new book[TotalBook];

	for(int i=0; i<TotalBook; i++)
	{
		fin >> tempName >> tempNumber >> tempBorrowFlag;
		if(lastNumberOfBook<tempNumber)
			lastNumberOfBook=tempNumber;
		cout << i+1 << "��° �ӽ� ������ ���Ϸκ��� �Է� �Ϸ�" << endl;
		Vbook[i].setName(tempName);
		Vbook[i].setNumber(tempNumber);
		Vbook[i].setBorrowFlag(tempBorrowFlag);
		cout << i+1 << "��° ���� ������ �Է� �Ϸ�" << endl;
	}
	closeInputFile(fin);
	CLS
}

void mainclass::pushDataToFile()
{
	ofstream fout = openOutputFile(DBFILE);
	/*
	������ ���� ���� ���
		N(�л� ��)
		i��° �л�	�̸�
					�й�
					���� å ��
					��ȣȭ�� ��й�ȣ
					�� ����(true/false)
					���� å �ε���
						j��° å
						j+1��° å
						...

		M(���� ��)
		i��° ����	�̸�
					���� ��ȣ
					���� �÷���
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

int mainclass::borrowBook(const int indexOfBorrowBook, const int indexOfBorrowStudent)		// �̿ϼ�*********
{
	CLS
	if(Vbook[indexOfBorrowBook].checkBorrowFlag()==-1)		// ���� ����
	{
		Vbook[indexOfBorrowBook].setBorrowFlag(indexOfBorrowStudent);
		int* tempArray = new int[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()+1];
		for(int i = 0; i < Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook(); i++)
			tempArray[i] = Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i];
		if(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()!=0)
		{
//			cout << "�� �л��� ���� å ���� " << Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() << "���̹Ƿ� if�� ���� ����" << endl;
			delete []Vstudent[indexOfBorrowStudent].indexOfBorrowedBook;
		}
		Vstudent[indexOfBorrowStudent].setNumberOfBorrowedBook(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()+1);
		Vstudent[indexOfBorrowStudent].indexOfBorrowedBook = new int[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()];
		for(int i = 0; i < Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook(); i++)
			Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i] = tempArray[i];
		delete []tempArray;
		Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()-1]=indexOfBorrowBook;
		cout << Vbook[indexOfBorrowBook].getName() << " ������ ���������� �����Ͽ����ϴ�. �ݳ����� (�̱���)�����Դϴ�." << endl;
		return 1;
	}
	else if(Vbook[indexOfBorrowBook].checkBorrowFlag()==indexOfBorrowStudent)
	{
		cout << "�̹� \"" << Vbook[indexOfBorrowBook].getName() << "\" ������ �����ϼ̽��ϴ�. ���� ���������� ���� ������ �� �� �����Ͻ� �� �����ϴ�." << endl;
		return 0;
	}
	else
	{
		cout << "\"" <<Vbook[indexOfBorrowBook].getName() << "\" ������ �ٸ� ȸ���� �̹� �����ϼ̽��ϴ�. (�̱���) ���Ŀ� �ٽ� �湮�� �ּ���." << endl;
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
				cout << "9. ****** �Ʒ� ���� ******" << endl;
				t=1;
				continue;
			}
			cout << i+1 << ". " << Vbook[i-t].getName() << " - ";
			if(Vbook[i-t].checkBorrowFlag()==-1)
				cout << "���� ����" << endl;
			else
				cout << "���� �Ұ�" << endl;
		}

		cout << "0. ���α׷� ����\n9. ���� �޴��� �̵�" << endl;
		cout << "������ ���ϴ� ������ ��ȣ�� �Է��ϼ��� : ";

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
			cout << "�߸��� �����Դϴ�." << endl;
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
		cout << Vstudent[indexOfBorrowStudent].getName() << " �л��� \"" << Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].getName() << "\" ������ �������� �����̽��ϴ�. �ݳ��� �� �����ϴ�." << endl;
		return 0;
	}
	else
	{
		cout << "\"" << Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].getName() << "\" ������ ���������� �ݳ��Ͽ����ϴ�." << endl;
		Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[indexOfBorrowBook]].setBorrowFlag(-1);
		pushIntArray(Vstudent[indexOfBorrowStudent].indexOfBorrowedBook, indexOfBorrowBook, Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook());
			// ���� �л� ��ü�� ���� å �ε����κ��� ���� å �ε����� �����ϰ� �ڿ� �ִ� ��� ������ ������ �� ĭ�� ����
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
		cout << Vstudent[indexOfBorrowStudent].getName() << " �л��� ���� ������ ������ �����ϴ�." << endl;
		return;
	}
	else if(Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()<0)
	{
		cout << "������ �߻��߽��ϴ�. �ش� �л��� ������ ������ ���� ���� �����Դϴ�. ���α׷� �ҽ��� �����ϼ���." << endl;
		return;
	}

	char c[30];

	while(1)
	{
		cout << "���� ���� ���� : " << Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() << endl;

		for(int i = 0; i < Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook() || (i>8 && i<=Vstudent[indexOfBorrowStudent].getNumberOfBorrowedBook()); i++)		// ����
		{
			if(i==8)
			{
				cout << "9. ****** �Ʒ� ���� ******" << endl;
				t=1;
				continue;
			}
			cout << i+1 << ". " << Vbook[Vstudent[indexOfBorrowStudent].indexOfBorrowedBook[i-t]].getName() << endl;
		}

		cout << "0. ���α׷� ����\n9. ���� �޴��� �̵�" << endl;

		cout << "�ݳ��� ���ϴ� ������ ��ȣ�� �����ϼ��� : ";

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
		cout << "�߸��� ������ �ϼ̽��ϴ�." << endl;
	}
}

void mainclass::modifyInformation(int indexOfStudent)
{
	string modifyMenu = "1. �̸� ����\n2. ��ȣ ����\n9. ���� �޴��� �̵�\n0. ���α׷� ����\n";

	int select = choice(modifyMenu, 1, 2, 9, 0);

	string name;

	string password;

	switch(select)
	{
	case 1:
		cout << "���ϴ� �̸��� �Է��ϼ��� : ";
		cin >> name;
		CLS
		Vstudent[indexOfStudent].setName(name);
		cout << "�л��� �̸��� ���������� ����Ǿ����ϴ�." << endl;
		break;
	case 2:
		cout << "���� ";
		if(Vstudent[indexOfStudent].checkPassword())
		{
			while(1)
			{
				string passwordForCheck;
				cout << "�����ϰ���� ��ȣ�� �Է��ϼ��� : ";
				cin >> password;
				CLS
				cout << "�ٽ� �� �� �Է��ϼ��� : ";
				cin >> passwordForCheck;
				CLS
				if(password==passwordForCheck)
				{
					Vstudent[indexOfStudent].setPassword(password);
					cout << "��ȣ�� ���������� ����Ǿ����ϴ�." << endl;
					return;
				}
				cout << "�߸��Ǿ����ϴ�." << endl;
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
	string menu = "1. ���� ����\n2. ���� �ݳ�\n3. �������� ����\n9. ���� �޴��� �̵�\n0. ���α׷� ����\n";

	int c = 0;
	
	while(1)
	{
		c = choice(menu, 1, 2, 3, 9, 0);
		switch(c)
		{
		case 1:			// ���� ����
			borrowMenu(indexOfStudent);
			break;
		case 2:			// ���� �ݳ�
			returnMenu(indexOfStudent);
			break;
		case 3:			// �������� ����
			modifyInformation(indexOfStudent);
			break;
		case 9:			// ���� �޴��� �̵�
			return;
			break;
		case 0:			// ���α׷� ����
			CLS

			cout << "���α׷��� �����մϴ�." << endl;

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
		cout << "�й��� 8�ڸ��� ���ڵ�� �̷������ �մϴ�. �л� ������ �����Ͽ����ϴ�." << endl;
		return false;
	}

	student *temp = new student[totalStudent+1];

	for(i=0; i<totalStudent; i++)
	{
		temp[i] = Vstudent[i];
		if(numberOfStudent==Vstudent[i].getNumber())
		{
			CLS
			cout << "�ش� �й��� �̹� ��ϵǾ� �ֽ��ϴ�. ��ȣ�� �н��ϼ̴ٸ�, �����ڿ��� �����Ͻñ� �ٶ��ϴ�." << endl;
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

		cout << "��ȣ�� �Է��� �ּ��� : ";

		cin >> password;

		CLS

		cout << "��ȣ�� �� �� �� �Է��� �ּ��� : ";

		cin >> passwordForCheck;

		if(password==passwordForCheck)
			break;

		CLS

		cout << "��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}

	CLS

	temp[totalStudent].setPassword(password);

	totalStudent++;

	delete[] Vstudent;

	Vstudent = new student[totalStudent];

	for(i=0; i<totalStudent; i++)
		Vstudent[i] = temp[i];

	delete[] temp;

	cout << "���������� �л��� �����Ͽ����ϴ�." << endl;

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

	cout << "���������� �л��� �����Ͽ����ϴ�." << endl;
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

	cout << "������ ���������� ��ϵǾ����ϴ�." << endl;

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
			cout << name << " �л��� ��ȣ�� �Է��ϼ��� : ";
			string password;
			cin >> password;
			CLS
			if(encrypt(password)==this->password)
				return 1;
			else
				cout << "��ȣ�� Ʋ�Ƚ��ϴ�. ";
		}
		cout << "��ȣ�� 3ȸ �̻� Ʋ�Ƚ��ϴ�.";
		setBlock(true);
		cout << "������ �� ���¸� �����ϱ� ���ؼ� �����ڿ��� �����Ͻñ� �ٶ��ϴ�." << endl;

		return 0;
	}
	else if(block==1)
	{
		CLS
		cout << "���� �ش� ������ �� �����Դϴ�. ������ �� ���¸� �����ϱ� ���ؼ� �����ڿ��� �����Ͻñ� �ٶ��ϴ�." << endl;
		return 0;
	}
	else
	{
		cout << "�������� �ʴ� �й��Դϴ�." << endl;
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
			cout << "������ �� ���°� �����Ǿ����ϴ�." << endl;
		else
			cout << "������ �� ���°� �ƴմϴ�." << endl;
	else
		if(block==false)
			cout << "������ �� ���·� ��ȯ�Ǿ����ϴ�." << endl;
		else
			cout << "������ �̹� �� �����Դϴ�." << endl;
	block=boolish;
}