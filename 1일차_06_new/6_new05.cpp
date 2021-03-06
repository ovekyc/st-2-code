#include <iostream>
#include <vector>
using namespace std;

// 생성자의 명시적 호출을 사용하는 경우 2. vector의 메모리 관리 기술


//		100 번째 - 10개 할당

//		* 100 번째
// V -	크기 10
int main() {
	
	vector<int> v(10, 3); // 10개를 3으로 초기화

	v.resize(7); // 이 코드의 알고리즘을 생각해 봅시다.
				// CASE 01. size 를 7로만 바꾸자 ( 실제로 이렇게 작동한다 )
				// CASE 02. 메모리 카피를 해서 7개를 복사하자		|	---------> 이렇게 짤 경우에는 성능에 대한 문제가 발생한다 ( 다 할당 및 복사 하면 )
				//												| 문제가 발생한다 크기가 10인데 7개만 사용하고 있다.
	cout << v.size() << endl; // 7
	cout << v.capacity() << endl; // 실제 메모리 크기 10

	v.push_back(5); // 끝에 하나를 추가하고 5로 초기화

	cout << v.size() << endl; // 8								| size는 증가하고 메모리 개수는 계속 유지된다.
	cout << v.capacity() << endl; // 실제 메모리 크기 10

	v.shrink_to_fit(); // 필요 없는 공간을 제거해달라. ---> CASE 02.를 실제로 부른다.( 할당 및 복사를 한다.)

	cout << v.size() << endl; // 8								
	cout << v.capacity() << endl; // 실제 메모리 크기 10

	// 커지는 경우
	vector<int> v2(10, 0);
	v2.push_back(1); // 끝에 하나 추가
					// 이 경우 기존 크기 * 1.5를 주소 사용
					// 컴파일러에 따라 다를 수 있다.
	cout << v2.capacity() << endl; // 실제 메모리 크기 10

	// vector 에 사용자 타입을 저장하는 경우를 생각해 봅시다.
	class DBConnect {};
	vector<DBConnect> v3(10); // DBConnect는 생성자에서 DB에 접속합니다.
	v3.resize(7); // 줄어든 3개의 객체는 메모리에 분명 남아 있습니다.
				// 하지만 소멸자를 호출해서 DB를 닫아야 합니다.
				// 소멸자의 명시적 호출이 필요 합니다.

	v3.resize(8); // 늘어난 한개의 객체는 메모리에 이미 있습니다.
				// 하지만 생성자를 호출해서 DB에 접속해야 합니다.
				// 생성자의 명시적 호출이 필요합니다.

}