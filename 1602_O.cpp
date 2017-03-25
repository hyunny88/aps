#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
using namespace std;


map<int, string> dictA2;
map<string, int> dictB2;

int N, M;

struct node {
	int num;
	char name[21];
};

node dictA[100005];

//node dictB[500001];

bool isNum(char *t) {
	if (t[0] > '9') {
		return false;
	}
	return true;
}

int mylen(char *t) {
	int idx = 0;
	while (t[idx] != '\0') {
		idx++;
	}
	return idx;
}
int myatoi(char *t) {
	int idx = 0;
	int result = 0;
	int len = strlen(t);
	for (int i = len-1; i >= 0; i--) {
		int pre = 1;
		result += (t[len-1 - i] - '0')*( pre*pow(10,i));
	}
	
	return result;
	
}
unsigned int myhash(char *s, int length)
{
	unsigned hashval;

	unsigned int hash = 0;
	for (int i = 0; i < length; ++i)
	{
		hash = 65599 * hash + s[i];
	}
	return hash ^ (hash >> 16);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		node temp;
		temp.num = i;
		scanf("%s", &temp.name);
		dictA[i] = temp;
		
		//unsigned val = myhash(temp.name, strlen(temp.name));
		string name = temp.name;
		dictA2[i + 1] = name;
		dictB2[name] = i;
		/*
		for (int k = val % 5000001; ; k++) {
			if (k >= 5000001) {
				k = 0;
			}
			if (dictB[k].name != '\0') {
				dictB[k] = temp;
				break;
			}
		}
		*/
		
	}
	for (int j =0 ; j < M; j++) {
		char tt[21];
		scanf("%s", &tt);
		if (isNum(tt)) {
			int num = atoi(tt);
			//printf("%s\n", dictA2[atoi(tt)]);
			printf("%s\n", dictA[num - 1].name);
		}
		else {
			string name = tt;
			printf("%d\n", dictB2[name]+1);

			/*unsigned a = myhash(tt, strlen(tt));

			for (int k = a % 5000001; k < 5000001; k++) {
				if (k >= 5000001) {
					k = 0;
				}
				if (!strcmp(dictB[k].name,tt) ) {
					printf("%d\n", dictB[k].num + 1);
					break;
				}
			}
			*/
		}
	}
	return 0;
}