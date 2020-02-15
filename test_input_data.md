# Test1 (tests for if-statements)
given

**Test setting**

```c
int CNT_INFO[150]; // count of numbers 
char buf[30];      // store & output area
```

buf[30] (10 * 4 +  4 = 44) [if all data is stored once.]

```shell
+-----+----------+
| 10  |       [Size]
+-----+----------+
| 10  |          |
+-----+          |          
| 20  |          |          
+-----+          |
| 30  |          |
+-----+          |
| 40  |          |
+-----+          -
| 100 |          D
+-----+          A
| 100 |          T
+-----+          A
| 100 |          -
+-----+          |
| 120 |          |
+-----+          |
| 130 |          |         
+-----+          |         
| 140 |          |         
+-----+----------+
```

## If-statement

```c
if (buf + sz - p - 1 < j) 
{
	fwrite(buf, sizeof(char), p - buf, stdout);
	p = buf;
	goto check_1;
}
```

- 만약 현재의 저장소 `buf`보다 더 많은 입력을 했다면 이 경우 예외 처리가 필요하다.
- 따라서 현재까지 정렬된 저장소를 현재 문제가 발생된 부분을 제외하고 출력한다.
- 또한 현재 포인터 p를 다시 저장소의 처음 주소로 이동한다.

```c
check_1:
	memcpy(p, STR_INFO[num], j);
	s = p;
	p += j;
	CNT_INFO[num]--;
	f = 1;
```

- 이때 현재 값`STR_INFO[num]`을 처음 주소로 옮긴다.
- 그리고 현재 포인터 p를 다음 주소로 옮긴다.



## Reference
[My source #1](https://www.acmicpc.net/source/17694817)
[My source #2](https://www.acmicpc.net/source/17694757)