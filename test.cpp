//#include <iostream>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//const int _BUFSIZ = 1020102;
//const int _LENG   = 10001; // 1 ~ 10,000
//
//char s[_BUFSIZ];
//int a[_LENG];
//
//int main(void) 
//{
//	char *p = s;
//	int i, t, n;
//
//	fread(s, sizeof(char), _BUFSIZ, stdin);
//	for (n = *p++ - 48; (t = *p++ - 48) >= 0; n = n * 10 + t);
//
//	while (n--) 
//	{
//		if ((t = s + sizeof(s) - p) < 6) 
//		{
//			memmove(s, p, t);
//			t += fread(s + t, sizeof(char), p - s, stdin);
//			if (t < sizeof(s)) s[t] = 0;
//			p = s;
//		}
//		for (t = *p++ - 48; (i = *p++ - 48) >= 0; t = t * 10 + i);
//		a[t]++;
//	}
//	p = s;
//
//	for (i = 0; i < 10; i++) while (a[i]--) 
//	{
//		if ((s + sizeof(s) - p) < 2) 
//		{
//			fwrite(s, sizeof(char), p - s, stdout);
//			p = s;
//		}
//		*p++ = i + 48;
//		*p++ = 10;
//	}
//	for (i = 10; i < 100; i++) while (a[i]--)
//	{
//		if ((s + sizeof(s) - p) < 3) 
//		{
//			fwrite(s, sizeof(char), p - s, stdout);
//			p = s;
//		}
//		*p++ = i / 10 + 48;
//		*p++ = i % 10 + 48;
//		*p++ = 10;
//	}
//	for (i = 100; i < 1000; i++) while (a[i]--) 
//	{
//		if ((s + sizeof(s) - p) < 4)
//		{
//			fwrite(s, sizeof(char), p - s, stdout);
//			p = s;
//		}
//		*p++ = i / 100 + 48;
//		*p++ = i / 10 % 10 + 48;
//		*p++ = i % 10 + 48;
//		*p++ = 10;
//	}
//	for (i = 1000; i < 10000; i++) while (a[i]--) 
//	{
//		if ((s + sizeof(s) - p) < 5) 
//		{
//			fwrite(s, sizeof(char), p - s, stdout);
//			p = s;
//		}
//		*p++ = i / 1000 + 48;
//		*p++ = i / 100 % 10 + 48;
//		*p++ = i / 10 % 10 + 48;
//		*p++ = i % 10 + 48;
//		*p++ = 10;
//	}
//	while (a[10000]--) 
//	{
//		if ((s + sizeof(s) - p) < 6) 
//		{
//			fwrite(s, sizeof(char), p - s, stdout);
//			//write(1, s, p - s);
//			p = s;
//		}
//		*p++ = 49;
//		*p++ = 48;
//		*p++ = 48;
//		*p++ = 48;
//		*p++ = 48;
//		*p++ = 10;
//	}
//	fwrite(s, sizeof(char), p - s, stdout);
//	//write(1, s, p - s);
//}