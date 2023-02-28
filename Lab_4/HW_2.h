
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
		delete[] arr;         // ошибка 
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
		if (top == 0) cout << "Стек пут";
		for (int i = 1; i <= top; i++)
			printf("%d\t", arr[i]);
		cout << "\n" << endl;
	}
};

void HW_2() {

	setlocale(LC_ALL, "ru");

	Stack a(10);
	cout << "Добавим в стек значения:\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.print();
	cout << "Удалим в стеке последнее значение:\n";
	a.pop();
	a.print();
	a.reset();
	cout << "Очистим стек:\n";
	a.print();
	cout << "Добавим в стек значения:\n";
	a.push(1);
	a.push(1);
	a.push(1);
	a.print();
}

/*
Создайте класс, который реализует функционал стека. Класс Stack должен иметь:
•	закрытый целочисленный массив заданного размера;
•	закрытое целочисленное значение для отслеживания длины стека;
•	открытый метод с именем reset(), который будет инициализировать значением 0 длину и все значения элементов;
•	открытый метод с именем push(), который будет добавлять значение в стек. Метод push() должен возвращать значение false, если массив уже заполнен, в противном случае — true;
•	открытый метод с именем pop() для возврата значений из стека. Если в стеке нет значений, то должно возвращаться значение false;
•	открытый метод с именем print(), который будет выводить все значения стека.
*/