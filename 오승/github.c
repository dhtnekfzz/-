#include <stdio.h>
#include<string.h>

void encrypt(char buf[], int shift);

int main(void)
{
	char filename[100];
	char savefile[100];
	char buf[100];
	char b[100] = "";
	char a[100] = { "Hello World\nSecond Line" };
	printf("파일 이름을 입력:");
	scanf("%s", filename);
	FILE *fp;
	fp = fopen(filename,"w+");
	fputs(a, fp);
	fclose(fp);
	printf("저장할 파일 이름을 입력:");
	scanf("%s", &savefile);
	int shift;
	printf("shift=");
	scanf("%d", &shift);
	fp = fopen(filename, "r");
	while(!feof(fp))
	{
		fgets(buf, 100, fp);
		
		encrypt(buf, shift);
		strcat(b, buf);
	}
	fclose(fp);

	fp = fopen(savefile, "a+");
	fputs(b, fp);
	fclose(fp);
}
void encrypt(char buf[], int shift) {
	int i = 0;


	while (buf[i] !='\0') 
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