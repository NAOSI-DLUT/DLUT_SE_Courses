#include<iostream>
#include<string>
using namespace std;

//¡¾Àı2.21¡¿Çó×Ö·û´®µÄµ±Ç°³¤¶È¡£

int strlen(char s[])
{
	int count = 0;
	while(s[count] != '\0')
		count++;
	return count;
}

//¡¾Àı2.22¡¿×Ö·û´®µÄ¸´ÖÆº¯Êı¡£

char * strcpy(char * s1, char * s2)
{
	int count = 0;
	if (s2 == NULL)//Ê×ÏÈÅĞ¶Ïstr2ÊÇ·ñÎª¿Õ
	{
		return NULL;
	}
	int nleg=strlen(s2);
	s1=new char[nleg];
	while(s2[count] != '\0')
	{
		s1[count] = s2[count];
		count++;
	}
	s1[count] = '\0';
	return s1;
}


//¡¾Àı2.23¡¿×Ö·û´®µÄ±È½Ïº¯Êı¡£

int strcmp(char * s1, char * s2)
{
	int count = 0;
	while(s1[count] != '\0' && s2[count] != '\0')
	{
		if(s1[count] > s2[count])
			return 1;
		else if(s1[count] < s2[count])
			return -1;
		count++;
	}
	if(s1[count] == '\0' && s2[count] != '\0')
		return -1;
	else if(s1[count] != '\0' && s2[count] == '\0')
		return 1;
	return 0;
}

//¡¾Àı2.24¡¿ÕıÏòÑ°ÕÒ×Ö·ûº¯Êı¡£
 char * strchr(char * s, char c)
{
	int count = 0;
	while(s[count] != '\0' && s[count] != c)
		count++;
	if(s[count] == '\0')
		return '\0';
	else 
		return &s[count];
}

//¡¾Àı2.25¡¿ÄæÏòÑ°ÕÒ×Ö·ûº¯Êı¡£

char * strrchr(char * s, char c)
{
	int count = 0;
	while(s[count] != '\0')
		count++;
	while(count >= 0 && s[count] != c)
		count--;
	if(count < 0)
		return '\0';
	else 
		return &s[count];
}
int main()
{
	char *str1 = "Hello ";
	char *str2 = "World !!!!";
	//²âÊÔ2.21
	cout<<strlen(str1)<<endl;
	//²âÊÔ2.22 
	str1 = strcpy(str1,str2);
	cout<<str1<<endl;
	//²âÊÔ2.23
    cout<<strcmp(str1,str2)<<endl;
    //²âÊÔ2.24
    char *c=strchr(str1,'l');
    cout<<c<<endl;
     //²âÊÔ2.25
    char *cc=strrchr(str1,'l');
    cout<<cc<<endl;
	return 0;
	
}

