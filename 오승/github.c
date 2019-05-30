#include <stdio.h>

void encrypt(char buf[], int shift);

int main(void)
{
	FILE *fp;
	fp = fopen("abc.txt","w+");
	char buf[100];
	char a[100] = { "Hello World" };
	fputs(a, fp);
	fclose(fp);
	fopen("abc.txt", "r");
	fgets(buf, 100, fp);
	fclose(fp);
	
	fp = fopen("s.enc.txt", "w+");
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