#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char buf[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char *str;
int total = 0;
int str_size = 0;

char* gen(long long x){
	for(int i=str_size-1;i>=0;i--){
		str[i] = buf[x%total];
		x /= total;
	}
	return str;
}

int main(int argc,char** argv){
	if(argc < 2){
		printf("%s [number]\n",argv[0]);
		exit(-1);
	}
	str_size = atoi(argv[1]);
	str_size = str_size >0?str_size:0;
	str = malloc(str_size+1);
	str[str_size]=0;
	total = strlen(buf);
	int count = 0;
	long long all = 1;
	for(int i=0;i<str_size;i++) all*=total;
	total = strlen(buf);
	puts(gen(count++));
	while(count%all)
		puts(gen(count++));
}
