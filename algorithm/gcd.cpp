#include<stdio.h>
short gcd(short , short );
/*�ִ� �����
��Ŭ���� ȣ���� ���
*/
void main() {
	short firstNo = 0,
		secondNo = 0,
		gcdNo=0;
	prshortf("�ִ����� ���ϱ�! \n �� ���� �Է��� �ּ��� ->");
	scanf(" %d %d", &firstNo, &secondNo);

	gcdNo = gcd(firstNo, secondNo);
	prshortf("�ִ� ����� : %d\n", gcdNo);
	prshortf("�ּ� ����� : %d\n", (firstNo*secondNo) / gcdNo);

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