//1.实现strcpy 
//2.实现strcat 
//3.实现strstr 
//4.实现strchr 
//5.实现strcmp 
//6.实现memcpy 
//7.实现memmove
#include<stdio.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* src){
	char* p = dest;
	assert(src != NULL);
	assert(dest != NULL);
	while(*p++ = *src++)
		;
	return dest;
}
char* my_strcat(char* dest, const char* src){
	char* p = dest;
	assert(src != NULL);
	assert(dest != NULL);
	while(*p != NULL)
		p++;
	while(*p++ = *src++)
		;
	return dest;
}
char* my_strstr(const char* str1, const* str2){
	char* cp = (char* )str1;
	char* substr = (char* )str2;
	char *s1 = NULL;

	assert(str1 != NULL);
	assert(str2 != NULL);
	
	if(*str2 == '\0')
		return str1;

	while(*cp){
		s1 = cp;
		substr = str2;
		while(*s1 && *substr && (*s1 == *substr)){
			s1++;
			substr++;
		}
		if(*substr == '\0')
			return cp;
		cp++;
	}
}

char* my_strchr(const char *s, char c)
{
	assert(s != NULL);
    while(*s != '\0' && *s != c)
    {
        s++;
    }
    return *s==c ? s : NULL;
}
char* my_strrchr(const char *s, char c)
{
	assert(s != NULL);
	while(*s)
		s++;
	s--;
    while(*s != '\0' && *s != c)
    {
        s--;
    }
    return *s==c ? s : NULL;
}
char* my_strcmp(const char* dest, const char* src){
	int ret = 0;
	assert(dest != NULL);
	assert(src != NULL);

	while(!(ret = *(unsigned char*)dest - *(unsigned char*)src) && *src)
		dest++,src++;
	if(ret > 0)
		return 1;
	else if(ret < 0)
		return -1;
	return ret;
}
void* my_memcpy(void* dst, const void* src, size_t count){
	void* ret = dst;
	assert(dst != NULL);
	assert(src != NULL);
	
	while(count--){
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void* my_memmove(void* dst, const void* src, size_t count){
	void* ret = dst;
	if(dst <= src || (char*)dst >= ((char*)src + count)){
		while(count--){
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else{
		dst = (char *)dst + count -1;
		src = (char *)src + count -1;
		while(count--){
			dst = (char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}
int main(){
	char arr1[] = "abcdee";
	char arr2[] = "de";

	//printf("%s\n", my_strcpy(arr1, arr2));
	//printf("%s\n", my_strcat(arr1, arr2));
	//printf("%s\n", my_strstr(arr1, arr2));
	//printf("%s\n", my_strchr(arr1, 'd'));
	//printf("%s\n", my_strrchr(arr1, 'e'));
	//printf("%d\n", my_strcmp(arr1, arr2));
	//printf("%s\n", my_memcpy(arr1, arr2, 2));
	/*printf("%s\n", my_memmove(arr1, arr2, 2));*/
	return 0;
}