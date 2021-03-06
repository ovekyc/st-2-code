// 임시객체
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() {
		cout << "생성자" << endl;
	}

	~Point() {
		cout << "소멸자" << endl;
	}

	Point(const Point&) {
		cout << "복사생성자" << endl;
	}

};

// 함수 인자와 임시객체
void foo(Point p){}

int main() {
	Point p;
	foo(p);

	// 값 타입의 함수 인자로 전달하기 위한 객체라면 임시 객체가 좋다.
	foo(Point());

}