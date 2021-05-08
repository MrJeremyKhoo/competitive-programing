#include <bits/stdc++.h>
#include "mergesort.h"

using namespace std;

int main(){
	int size, caseno;
	if(scanf("%d %d", &size, &caseno) == 0) 
		return 0;
	
	
	int c[size];
	for(int i = 0; i < size; i++) {
		if(scanf("%d", &c[i]) == 0) 
			return 0;
	}
	
	mergeSort(c, 0, size - 1);

	switch(caseno) {
		case 1:
			{
			int l = 0;
			int r = size - 1;
			while(l < r) {
				if(c[l] + c[r] == 7777) {
					cout<<"Yes"<<endl;
					return 0;
				}else if(c[l] + c[r] < 7777) {
					l++;
				}else {
					r--;
				}
			}
			cout<<"No"<<endl;
			return 0;
			}
		case 2:
			for(int i = 1; i < size; i++) {
				if(c[i] - c[i - 1] == 0) {
					printf("%s", "Contains Duplicate");
					goto skip;

				}
			} //worst case O(n) 

			printf("%s", "Unique");
			skip: break;
		case 3:
			{
			int count = 1;
			int lim = size / 2;
			
			for(int i = 0; i < size; i++) {
				if(c[i] == c[i + 1]) {
					count++;
					if(count > lim) {
						printf("%d",c[i]);
						goto done;
					}
				} else if(c[i] != c[i+1]) {
					count = 1;
				}	
			}	//worst case O(n)
			
			printf("%d", -1);
			done: break;
			}
		case 4:
			{
			if(size % 2 == 0) {
				printf("%d %d",c[(size-1)/2], c[(size-1)/2 + 1]);
			} else {
				printf("%d", c[size/2]);
			}
			break;
			}
		case 5:
			{
				int i = 0;
				int j = 0;

				while(c[i] < 100) {
					i++;
				}

				while(c[size - 1 - j] > 999) {
					j++;
				}

				for(int k = i; k < size - j; k++) {
					printf("%d ", c[k]);
				}

			break;
			}
		default:
				return 0;


	}
}
