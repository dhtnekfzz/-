#include <stdio.h>

void encrypt(char buf[], int shift);

int main(void)
{
	FILE *fp;
	fp = fopen("abc.txt","r");
	char buf[100];
	fgets(buf, 100, fp);
	fp = fopen("D:\\¿À½Â\\¿À½Â\\abc.txt", "w");
	int shift;
	printf("shift=");
	scanf("%d", &shift);
	encrypt(buf, shift);
	fputs(buf, fp);
	
	fclose(fp);
}
void encrypt(char buf[], int shift) {
	int i = 0;


	while (buf[i] != '\0') 
	{
		if (buf[i] >= 'A' && buf[i] <= 'z') 
		{

			buf[i] += shift;
			if (buf[i] > 'z')
				buf[i] -= 26;
		}
		i++;
	}
	
}