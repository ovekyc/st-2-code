#include <iostream>
using namespace std;

// 모든 함수의 주소를 담을 수 있는 도구
// C, C++		: 문법적으로는 없다!
// C#			: delegate 라는 문법
// Objective-C	: Selector 라는 문법

// C++11 : fucntion<> 모든 함수의 주소를 담을 수 있다.

class Dialog {

public:
	void Close() {
		cout << "Dialog Close" << endl;
	}

};

void foo() {
	cout << "foo" << endl;
}

void goo(int a) {
	cout << "goo  : " << a << endl;
}

void hoo(int a, int b) {
	cout << "hoo : " << a << ", " << b << endl;
}

void koo(int a, int b, int c, int d) {
	printf("%d %d %d %d\n", a, b, c, d);
}

// fuction<ReturnType(Parameter)>
#include <functional>
using namespace std::placeholders; // _1, _2 .. 사용하기 위해 사용하는 것.
int main() {
	function<void(int)> f = &goo;
	f(5); // goo(5)

	// Parameter 첫번째 인지 두번째 인지 알 수 없다.
	// bind 를 사용하는 방법 인자 개수 만큼 반드시 넣어주어야 한다. 
	f = bind(&hoo, _1, 3); // hoo(5, 3);
	f(5); 

	// _1, _2 는 내가 보내는 f2()에서의 파라미터 순서이다.
	function<void(int, int)> f2;
	f2 = bind(&koo, _2, 2, 9, _1);
	f2(6, 3); // 3 2 9 6 

}

// Placeholders _1, _2, _3; 로 객체 형식 이다.. 가변인자 템플릿이라는 것도 들어간다.
// 함수인자에 못넣는 경우가 생기면 안된다.