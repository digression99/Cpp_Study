/*
 2016 기말고사 B반
 클래스 설계
 
 class Product
 변수
 - int id // 식변 번호
 - int type // 제품 종류.
 - int price // 소비자가격
 
 class Snack : public Product
 변수
 - string name // 과자 이름
 - string company // 생산회사
 
 class Meat : public Product
 변수
 - string name // 육류 이름
 - string source // 원산지
 - int level // 등급
 
 class Customer
 변수
 - string name // 고객 이름
 - int point // 포인트 점수
 - Product * boughtProducts // 구매 제품들.
 - int len // 얼마나 구매했는지
 
 class MartManager
 변수
 - Product * productList[5] // 제품 리스트, 총 5개.
 - Customer * customerList[3] // 고객 리스트, 총 3명
 - int revenue // 총 판매 금액
 
 함수
 -  start()
 -> 메뉴 구성. 총 메뉴는 4개,
 1. 제품 구매 2. 제품 결제 3. 판매 현황 4. 종료
 
 1. 제품 구매
 -> 고객명 있는지 체크.
 -> 있을 경우, 총 제품 구매 개수 입력 받음.
 해당 수 만큼, 제품 식별 번호와 구매 개수 입력 받아서 구매 정보 저장.
 제품 식별 번호가 같은 경우, 구매 개수만큼 증가.
 
 
 
 
 
 
 
 */



#include <iostream>
using namespace std;

int main()
{
    return 0;
}

