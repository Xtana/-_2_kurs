
class Stack {
	int top;
	int size;
	int* arr = new int[size];

public: 

	Stack() {
		arr = new int[0];
		size = 0;
		top = 0;
	}

	Stack(const int init) {
		arr = new int[init];
		size = init;
		top = 0;
	}

	~Stack() {
		delete[] arr;
	}

	void reset() {
		delete[] arr;         // ������ 
		arr = new int[size];
		top = 0;
	}

	void changeSize(int size) {
		this->size = size;
	}

	bool push(int item) {
		if (size <= top) return false;
		else
			top++;
			arr[top] = item;
			return true;
	}

	int pop() {
		if (top == 0) return 0;
		int tmp = arr[top];
		top--;
		return tmp;
	}

	void print() {
		if (top == 0) cout << "���� ���";
		for (int i = 1; i <= top; i++)
			printf("%d\t", arr[i]);
		cout << "\n" << endl;
	}
};

void HW_2() {

	setlocale(LC_ALL, "ru");

	Stack a(10);
	cout << "������� � ���� ��������:\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.print();
	cout << "������ � ����� ��������� ��������:\n";
	a.pop();
	a.print();
	a.reset();
	cout << "������� ����:\n";
	a.print();
	cout << "������� � ���� ��������:\n";
	a.push(1);
	a.push(1);
	a.push(1);
	a.print();
}

/*
�������� �����, ������� ��������� ���������� �����. ����� Stack ������ �����:
�	�������� ������������� ������ ��������� �������;
�	�������� ������������� �������� ��� ������������ ����� �����;
�	�������� ����� � ������ reset(), ������� ����� ���������������� ��������� 0 ����� � ��� �������� ���������;
�	�������� ����� � ������ push(), ������� ����� ��������� �������� � ����. ����� push() ������ ���������� �������� false, ���� ������ ��� ��������, � ��������� ������ � true;
�	�������� ����� � ������ pop() ��� �������� �������� �� �����. ���� � ����� ��� ��������, �� ������ ������������ �������� false;
�	�������� ����� � ������ print(), ������� ����� �������� ��� �������� �����.
*/