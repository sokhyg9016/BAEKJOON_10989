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

- ���� ������ ����� `buf`���� �� ���� �Է��� �ߴٸ� �� ��� ���� ó���� �ʿ��ϴ�.
- ���� ������� ���ĵ� ����Ҹ� ���� ������ �߻��� �κ��� �����ϰ� ����Ѵ�.
- ���� ���� ������ p�� �ٽ� ������� ó�� �ּҷ� �̵��Ѵ�.

```c
check_1:
	memcpy(p, STR_INFO[num], j);
	s = p;
	p += j;
	CNT_INFO[num]--;
	f = 1;
```

- �̶� ���� ��`STR_INFO[num]`�� ó�� �ּҷ� �ű��.
- �׸��� ���� ������ p�� ���� �ּҷ� �ű��.



## Reference
[My source #1](https://www.acmicpc.net/source/17694817)
[My source #2](https://www.acmicpc.net/source/17694757)