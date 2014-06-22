#include <stdio.h>

// 배열 ar에서 fist ~ last의 인덱스에서 target 값이 있는지 확인한다.
// 성공: 해당 target의 인덱스
// 실패: -1
int BSearch(int ar[], int first, int last, int target)
{
	if ( first <= last ) {
		int half = (first+last)/2;
		if ( target > ar[half] )
			BSearch(ar, half+1, last, target);
		else if ( target < ar[half] )
			BSearch(ar, first, half-1, target);
		else
			return half;
	} else 
		return -1;
}

// BSearch 테스트 셋을 검사
// 성공: 1
// 실패: -1
int TDD()
{
	int arr[] = {1, 3, 5, 7, 9};
	int testSetInput[]  = {1,  2, 3,  4, 5,  6, 7,  8, 9, 10};
	int testSetOutput[] = {0, -1, 1, -1, 2, -1, 3, -1, 4, -1};
	
	for(int i=0; i < sizeof(testSetInput)/sizeof(int); i++) {
		int result = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, testSetInput[i]);
		if ( result == testSetOutput[i] )
			printf("테스트 케이스 %d 성공\n", i);
		else
			return -1;
	}
	return 1;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9};
	if ( TDD() == -1 )
		printf("함수가 잘못 작성되었습니다.\n");
	printf("배열 {1, 3, 5, 7, 9}에서 입력값의 인덱스를 찾아줍니다. 못찾으면 -1을 리턴합니다.\n");
	int input;
	printf("찾고자 하는 입력값을 입력하세요. ");
	scanf("%d", &input);
	int result = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, input);
	if ( result == -1 )
		printf("실패! 배열에서 %d에 해당하는 값을 못 찾았습니다.\n", input);
	else
		printf("성공! 배열에서 %d에 해당하는 인덱스는 %d입니다.\n", input, result);

}
