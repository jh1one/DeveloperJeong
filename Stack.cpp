//#include <stdio.h>
//
//template <typename T>
//class STACK{
//public:
//	STACK<T>(int theCapacity = 100) : capacity(theCapacity) {
//		capacity = theCapacity;
//		stack = new T[capacity];
//		count = 0;
//	}
//public:
//	T Top() {	
//		if(count > 0) return top; 
//		else return -1;
//	}
//
//	void pop() {
//		if (count > 0) {
//			printf("%d\n", top);
//			count--;
//			top = stack[count - 1];
//		}
//		else	printf("-1\n");
//	}
//
//	void push(T e) {
//		if (count + 1 < capacity) {
//			stack[count++] = e;
//			top = stack[count - 1];
//		}
//	}
//
//	int size() {	return this->count;	}
//
//	bool isEmpty() {
//		if (count == 0)	return true;
//		else if (count > 0) return false;
//	}
//private:
//	T* stack;
//	T top;
//	int capacity;
//	int count;
//};
//
//int main() {
//	int n, val;
//	scanf_s("%d", &n);
//	STACK<int> stack(n);
//	getchar();
//	char order[7];
//	for (int i = 0; i < n; i++) {
//		scanf_s("%s", order);
//		switch (order[0]) {
//		case 'p':
//			if (order[1] == 'u') {
//				scanf_s("%d", &val);
//				stack.push(val);
//			}
//			else if (order[1] == 'o') {
//				stack.pop();
//			}
//			break;
//		case 't': 
//			printf("%d\n", stack.Top());// << '\n';
//			break;
//		case 'e':
//			//cout << stack.isEmpty() << '\n';
//			printf("%d\n", stack.isEmpty());
//			break;
//		case 's':
//			//cout << stack.size() << '\n';
//			printf("%d\n", stack.size());
//			break;
//		}
//	}
//	return 0;
//}
