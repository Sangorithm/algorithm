#include<stdio.h>
short gcd(short , short );
/*최대 공약수
유클리드 호제법 사용
*/
void main() {
	short firstNo = 0,
		secondNo = 0,
		gcdNo=0;
	prshortf("최대공약수 구하기! \n 두 수를 입력해 주세요 ->");
	scanf(" %d %d", &firstNo, &secondNo);

	gcdNo = gcd(firstNo, secondNo);
	prshortf("최대 공약수 : %d\n", gcdNo);
	prshortf("최소 공배수 : %d\n", (firstNo*secondNo) / gcdNo);

}
short gcd(short firstNo, short secondNo) {
	if (firstNo > secondNo)
		firstNo -= secondNo;
	else if (firstNo < secondNo)
		secondNo -= firstNo;
	else
		return firstNo;
	gcd(firstNo, secondNo);
}