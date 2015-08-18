// Template_basic

// 함수 오버로딩
// 함수 사용자 : 하나의 함수 처럼 보인다.
// 함수 제작자 : 2개의 함수를 만들어야 한다.

//int square(int a) {
//	return a * a;
//}
//
//double square(double a) {
//	return a * a;
//}

// 유사한 코드가 반복되면 코드생성기를 사용하자.
// 1. 매크로에 의한 코드 생성 - 전처리기가 코드 생성
//    단점 : 전처리기는 타입을 알지 못한다.
//			어떤 타입의 함수가 필요한지를 미리 선언해야 한다.

//#define MAKE_SQUARE(T) T square(T a){return a * a;}
//
//MAKE_SQUARE(int)
//MAKE_SQUARE(double)


// 2. 컴파일러에 의한 코드 생성
//    컴파일러는 컴파일 중에 타입을 알 수 있다.
//    어떤 타입의 함수가 필요한지를 미리 알려줄 필요가 없다.
template<typename T> T square(T a){return a * a;}

// template instantiation : T의타입을 결정해서 실제 함수를 만드는 과정

// 암시적 instantiation : T의 타입을 컴파일러가 결정(추론, Deduction) 해서 함수 생성

// 명시적 instantiation : T의 타입을 사용자가 전달해서 함수 생성

// Code Bloat : 너무나 많은 함수/클래스가 생성되어 코드메모리가 증가하는것.

int main() {

	// ~ 암시적 추론
	square(3); // compile -> int square(int a){return a * a;}
	square(3.3); // compile -> double square(double a){return a * a;}

	short s = 3;
	square(s);	// 1. int 버전 사용 2. short 버전 생성.
				// 2. short 버전을 생성해준다.
				// -> Code Bloat 이다!!
	
	// ~ 명시적 추론
	square<int>(s); // 사용자가 T 의 타입을 전달 - int 버전을 사용해 달라.

}
