#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *arr, *newarray;



int main() {
	FILE *f, *q;
	f = fopen("in.txt", "rt");
	int min = INT_MAX;
	int n, k, lastIndex, lastMin = -1;
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &k);
	arr = (int*)malloc(n * sizeof(int));
	newarray = (int*)malloc(n * sizeof(int));

	//Citirea sirului
	
	for (int i = 0; i < n; i++) {
		fscanf(f,"%d", &arr[i]);
	}
	fclose(f);

	//Cautarea punctelor de trecere la un alt subsir, adica cele k minime
	for (int j = 0; j < k; ++j) {
		for (int i = 0; i < n; ++i) {
			if (newarray[i] != 1) {
				newarray[i] = 0;
			}
			if (arr[i]<min && arr[i]>lastMin) {
				min = arr[i];
				lastIndex = i;
			}
		}
		newarray[lastIndex] = 1; //Plaseaza 1 pe indexul care s-a gasit minimum in newarray
		lastMin = min;
		min = INT_MAX;
	}

	//Afisarea subsirului
	q = fopen("out.txt", "wt");
	int find1 = 0;
	for (int i = 0; i < n; ++i) {
		if (newarray[i] == 1) {
			if (find1) {
				fprintf(q,"\n");
				fprintf(q,"%d ", arr[i]);
			}
			else {
				fprintf(q, "%d ", arr[i]);
				find1 = 1;
			}
		}
		else {
			fprintf(q, "%d ", arr[i]);
		}
	}
	fclose(q);
	return 0;
}