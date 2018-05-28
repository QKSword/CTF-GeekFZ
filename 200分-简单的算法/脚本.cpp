#include "stdio.h"
#include "Windows.h"

int main()
{
	char key1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char key2[] = "+/abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char key3[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/";
	char key4[] = "0123456789+/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	char key[] = "QASWZXDECVFRBNGTHYJUMKIOLP";

	char flag_1[] = "tfoQ5ckkwhX51HYpxAjkMQYTAp5";

	int yushu = 0;

	for(int m=0; m<=26; m++)
	{
		for(int n=33; n<=126; n++)
		{
			yushu = n - int(key[m]);
			yushu %= 4;
			switch (yushu)
			{
				case 0:
					if(key1[n - int(key[m])] == flag_1[m])
					{
						printf("%c", n);
					}
					continue;
				case 1:
					if(key2[n - int(key[m])] == flag_1[m])
					{
						printf("%c", n);
					}
					continue;
				case 2:
					if(key3[n - int(key[m])] == flag_1[m])
					{
						printf("%c", n);
					}
					continue;
				case 3:
					if(key4[n - int(key[m])] == flag_1[m])
					{
						printf("%c", n);
					}
					continue;
				default:
					continue;
			}			
		}
		printf("\n");
	}
}