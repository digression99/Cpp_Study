/*
 2016 기말고사 B반
 클래스 설계
 
 class Product
 변수 : protected
 - int id // 식변 번호.
 - int type // 제품 종류.
 - int price // 소비자가격.
 
 class Snack : public Product
 변수 : protected
 - string name // 과자 이름.
 - string company // 제과회사.
 
 class Meat : public Product
 변수 : protected
 - string name // 육류명.
 - string source // 원산지.
 - string level // 등급 : 1++, 1+ 등.
 
 class Customer
 변수 : protected
 - string name // 고객명.
 - int point // 포인트 점수.
 - Product * boughtProducts // 구매 제품, 제품별 구매 개수는 동적할당으로 생성.
 - int * nums // 구매 개수.
 
 class MartManager
 변수 : protected
 - Product * productList[5] // 판매제품 리스트, 총 5개.
 - Customer * customerList[3] // 고객 리스트, 총 3명.
 - int revenue // 총 판매 금액.
 
 함수
 -  start()
 -> 메뉴 구성. 총 메뉴는 4개,
 1. 제품 구매 2. 제품 결제 3. 판매 현황 4. 종료
 --> interface 구성.
 
 1. 제품 구매
 -> 고객명 있는지 체크.
 -> 있을 경우, 총 제품 구매 개수 입력 받음.
 해당 수 만큼, 제품 식별 번호와 구매 개수 입력 받아서 구매 정보 저장.
 제품 식별 번호가 같은 경우, 구매 개수만큼 증가.

 2. 제품 결제
 결제하시겠습니까? (Y / N)
 Y 시 결제를 완료, 구매한 정보를 삭제.
 구매한 금액의 10%를 포인트로 적립.
 N 입력시 해당 메뉴를 종료.
 육류의 제품 가격은 100g 당 가격.
 단 고객의 구매 정보 출력시 cout객체를 이용.

 3. 판매 현황
 마트의 총 판매금액을 출력.
 
 
 
 
 
 
 
 */



#include <iostream>
using namespace std;

int main()
{
    return 0;
}

