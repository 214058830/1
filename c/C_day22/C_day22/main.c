//1.模拟实现strncpy 
//2.模拟实现strncat 
//3.模拟实现strncmp
#include<stdio.h>
#include<assert.h>
#include<string.h>

char* my_strncpy(char *dest, const char *src, size_t len)
{
	char *res = dest;
	int offset = 0;
	assert(dest != NULL && src != NULL);
	if (strlen(src) < len)
	{
		offset = len - strlen(src);
		len = strlen(src);
	}
 
	while (len--)
	{
		*dest++ = *src++;
	}
	while (offset--)
	{
		*dest++ = '\0';
	}
	return res;
}

char * my_strncat(char * dest, const char * src,int count)
{
	char * ret = dest;
	assert(dest);
	assert(src);
	while (*dest++ != '\0')
	{
		;
	}
	dest--;
	while ((count--) && (*dest++ = *src++))
	{
		;
	}
	*dest = '\0';
	return ret;
}


int my_strncmp(const char *s1,const char *s2,int n)
{
	assert((s1!=NULL)&&(s2!=NULL));

	while(*s1 != '\0' && *s2 != '\0' && n)//字符串前面部分都同样
	{
		if(*s1 - *s2 > 0)
			return 1;
		else if(*s1 - *s2 < 0)
			return -1;
		s1++;
		s2++;
		n--;
	}
	if(*s1 == '\0' && *s2 != '\0')//谁先为'\0',谁就小
		return -1;
	if(*s2 == '\0' && *s1 != '\0')
		return 1;
	return 0;
}

int main(){
	char arr1[] = "abcde";
	char arr2[] = "defg";
	//printf("%s\n", my_strncpy(arr1, arr2, 2));
	//printf("%s\n", my_strncat(arr1, arr2, 2));
	//printf("%d\n", my_strncmp(arr1, arr2, 2));
	return 0;
}