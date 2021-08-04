/*
1. https://modoocode.com/213 cin >> 와 cout << 등 입출력에 대한 설명이 있다.
2. C++에서의 string, C에서 메모리 할당을 통해 문자열을 사용했다면 C++에서는 string 헤더파일을
   include하여 사용 가능. 주의 사항- cin>> 을통해 입력받을때 문자열의 경우 공백에서 구분이 되므로
   getline(cin,문자열변수) 를 통해서 문자열 전체를 입력받을 수 있음
3. Windows.h 헤더파일을 가져온뒤 system("cls"); 를 사용하면 콘솔 화면을 초기화 할 수 있다.
4. Person a1(10); 와 Person *a2 = new Person(10); 의 객체 생성 차이는
   https://yoon90.tistory.com/13 해당 링크를 통해 공부했다
5. struct vs class =
6. 지역변수 , 전역변수 , static 변수 차이를 정리
7. 파일 입출력 https://jdm.kr/blog/170
8. c++ string split 하는 방법 https://www.acmicpc.net/board/view/25973 
9. c++ class 헤더 나눠서 구분하기 https://shiinachianti.tistory.com/18 
10. c++에서의 string 비교연산은 compare() 함수를 이용한다. 문자열이 같으면
	a.compare(b)==0 이면 a와 b 문자열이 같은것이고 결과값이 -1 이면 다른것이다.
11. 헤더파일을 구분해 놓은 이유 https://namoeye.tistory.com/entry/%EC%BB%B4%ED%8C%8C%EC%9D%BC%EA%B3%BC%EC%A0%95-%EC%A0%95%EB%A6%AC-cpp%EC%99%80-h%EB%A5%BC-%EB%82%98%EB%88%84%EB%8A%94-%EC%9D%B4%EC%9C%A0
*/