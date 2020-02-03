/*
암호화 코드 해시함수
ver.1.3
*/

#include "header.h"

int encrypt(const string word)
{
	int N = 5000000;
	int len = word.length();

	for(int i=0; i<len; i++)
		N+=word[i]*(i+1)*15987;

	while(1)
	{
		if(N<10000000)
			break;
		N/=10;
	}

	for( ; N<10000000; N*=7);

	return N;
}