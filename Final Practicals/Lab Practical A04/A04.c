
#include<stdio.h>
#include<stdlib.h>
void permutation(char *a,char *pwd,int k,int m);

int main()
{
	char a[7]={'1','3','a','s','t','i','\0'};
	char pwd[6];
	int m=4;
	printf("List of password");
	permutation(a,pwd,0,m);
return 0;
}

void permutation(char *a,char *pwd,int k,int m)
{
	int i;
	if(k==m)
	{
		pwd[k]='\0';
		printf("\t%s",pwd);
	}
	else
	{
		for(i=0;a[i]!='\0';i++)
		{
			pwd[k]=a[i];
			permutation(a,pwd,k+1,m);
		}
	}
}

/*
	OUTPUT :
	List of password        1111    1113    111a    111s    111t    111i    1131    1133    113a    113s    113t    113i    11a1    11a3    11aa    11as    11at    11ai
11s1    11s3    11sa    11ss    11st    11si    11t1    11t3    11ta    11ts    11tt    11ti    11i1    11i3    11ia    11is    11it    11ii    1311    1313    131a
131s    131t    131i    1331    1333    133a    133s    133t    133i    13a1    13a3    13aa    13as    13at    13ai    13s1    13s3    13sa    13ss    13st    13si
13t1    13t3    13ta    13ts    13tt    13ti    13i1    13i3    13ia    13is    13it    13ii    1a11    1a13    1a1a    1a1s    1a1t    1a1i    1a31    1a33    1a3a
1a3s    1a3t    1a3i    1aa1    1aa3    1aaa    1aas    1aat    1aai    1as1    1as3    1asa    1ass    1ast    1asi    1at1    1at3    1ata    1ats    1att    1ati
1ai1    1ai3    1aia    1ais    1ait    1aii    1s11    1s13    1s1a    1s1s    1s1t    1s1i    1s31    1s33    1s3a    1s3s    1s3t    1s3i    1sa1    1sa3    1saa 
*/
