#include <stdio.h>
#include <memory.h>
#include "dataset.h" // include user-defind memory

#define _BUFSIZ 1020102
#define _LENG 10001 // 1 ~ 10,000

int CNT_INFO[_LENG]; // count of numbers 
char buf[_BUFSIZ]; //store & output area
int C;

/*
if 1, 2, 3, .. 10 --> '10\n' -> 3*10 + 3 = 33 ([data] + [size])
if 1, .... 100 --> '100\n' -> 4*100 + 4 = 404

an = (자릿수 + 1)*n + (자릿수 + 1)
[n = 10000] --> an = 6*10000 + 6 =>  [60006 * N] = 120012‬ , 240024, 1200120‬, 1140114‬, 1020098‬(Best), 960096‬, 900090, ...
*/

int main(void)
{
	char* p;
	int sz, remain;
	int num;

	fread(buf, sizeof(char), _BUFSIZ, stdin);
	p = buf;
	sz = sizeof(buf);

	// Read size
	for (C = 0; *p++ >= 48;) 
	{
		C = C * 10 + (p[-1] - 48);
	}

	// store the values in array
	while (C--) 
	{
		remain = buf + sz - p;
		//만약 저장 공간보다(buf) 많은 개수를 입력받았다면(C), 당연히 메모리에 다 저장하지 못할 것이다.
		//따라서 현재 공간이 6보다 작다면, (최고 "10000\n" 즉, 6자리이기 때문에) 현재 남은 데이터를
		//앞쪽에 remain 만큼 저장하고 (memcpy -> &buf[0]), 저장소의 크기에서 remain을 제외한 부분 만큼 다시 입력을 받는다.
		//입력이 끝난후 다시 p를 저장소의 처음부분으로 이동시킨다.
		//*이때, 결국 C 크기 만큼 반복하기 때문에 만약 더 입력을 받아도 에러는 발생하지 않는다.
		if (remain < 6) 
		{
			memcpy(buf, p, remain);
			fread(buf + remain, sizeof(char), sz - remain, stdin);
			p = buf;
		}
		for (num = 0; *p++ >= 48;) 
		{
			num = num * 10 + (p[-1] - 48);
		}
		CNT_INFO[num]++;
	}
	p = buf;

	for (num = 1; num < _LENG; num++)
	{
		int f, c, k, j; //f: 현재 남은 카운트
		char* s;

		// To get the length of number (j)
		for (k = num, j = 1; k > 0; k /= 10, j++);

		if (CNT_INFO[num]) 
		{
			//if current remain size is not enough to store the current number [만약 입력된 데이터가 저장된 데이터보다 크다면
			if (buf + sz - p - 1 < j) 
			{
				fwrite(buf, sizeof(char), p - buf, stdout);
				p = buf;
				goto check_1;
			}

		check_1:
			memcpy(p, STR_INFO[num], j);
			s = p;
			p += j;
			CNT_INFO[num]--;
			f = 1;

			// If still remain the count of number (it means, number > 1).
			while (CNT_INFO[num] > 0)
			{
				if (CNT_INFO[num] >= f) 
				{
					c = f;
				}
				else
				{
					c = CNT_INFO[num];
				}
				// if current remain size is not enough to store current sample numbers.
				// then print current output memory except current addr's value and p point &buf[0]
				// goto check 1 to store current value. 
				if (buf + sz - p - 1 < j * c) 
				{
					fwrite(buf, sizeof(char), p - buf, stdout);
					p = buf;
					goto check_1;
				}
				memcpy(p, s, j * c);
				p += j * c;
				CNT_INFO[num] -= c;
				f += c;
			}
		}
	}
	fwrite(buf, sizeof(char), p - buf, stdout);
	return 0;
}