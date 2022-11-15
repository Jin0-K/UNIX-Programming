#include <stdio.h>
#include <stdlib.h>

#define STUDENT_NUM 5

void itoa(int num, char *buf); 


struct score {
	char name[10];
	int kor;
	int math;
	int eng;
	int sum;
	double ave;
};
	
int main(void) {
	FILE *file;
	struct score scores[STUDENT_NUM];
	double subj_ave[3];

	if ((file = fopen("6.dat", "r")) == NULL) {
		perror("fopen: 6.dat");
		exit(1);
	}

	// read data in 6.dat to put in scores structure
	for (int i=0; i < STUDENT_NUM; i++) {
		char buf[30];
		char numbuf[4];
		int c = 0;

		// read one line
		fgets(buf, 20, file);
		
		int j = 0;
		// put name in scores
		for (j = 0; buf[j] != ' '; j++) {
			*((scores+i)->name + j) = buf[j];
		}
		*((scores+i)->name + j) = '\0';
		//printf("%s\n", (scores+i)->name);

		// put kor in scores	
		for (++j; buf[j] != ' '; j++) {
			numbuf[c++] = buf[j];
		}
		numbuf[c] = '\0';
		c = 0;
		(scores+i)->kor = atoi(numbuf);
		
		// put math in scores	
		for (++j; buf[j] != ' '; j++) {
			numbuf[c++] = buf[j];
		}
		numbuf[c] = '\0';
		c = 0;
		(scores+i)->math = atoi(numbuf);
		
		// put eng in scores	
		for (++j; buf[j] != ' '; j++) {
			numbuf[c++] = buf[j];
		}
		numbuf[c] = '\0';
		(scores+i)->eng = atoi(numbuf);
	}
	fclose(file);

	// Do operation for sum and ave
	for (int i=0; i < STUDENT_NUM; i++) {
		(scores+i)->sum = 0; 
		(scores+i)->sum = (scores+i)->kor 
				+ (scores+i)->math 
				+ (scores+i)->eng;
		(scores+i)->ave = (scores+i)->sum / 3;
		//printf("sum: %d, ave: %lf\n", (scores+i)->sum, (scores+i)->ave);
	}

	// Initialization for subj_ave
	subj_ave[0] = 0;
	subj_ave[1] = 0;
	subj_ave[2] = 0;

	// Do operation for subj_ave
	for (int i=0; i < STUDENT_NUM; i++) {
		subj_ave[0] += (double)(scores+i)->kor / STUDENT_NUM;
		subj_ave[1] += (double)(scores+i)->math / STUDENT_NUM;
		subj_ave[2] += (double)(scores+i)->eng / STUDENT_NUM;
	}
	//printf("%lf %lf %lf\n", subj_ave[0], subj_ave[1], subj_ave[2]);

	// Open file 6.out in write mode
	if ((file = fopen("6.out", "w")) == NULL) {
		perror("fopen:6.out");
		exit(1);
	}
	
	char numbuf[10];
	// Write data
	fputs("\tKOR\tMATH\tENG\tsum\tave\n", file);
	for (int i = 0; i < STUDENT_NUM; i++) {
		fputs((scores+i)->name, file);
		fputs("\t", file);
		// Convert int to string
		itoa((scores+i)->kor, numbuf);
		fputs(numbuf, file);
		fputs("\t", file);
		itoa((scores+i)->math, numbuf);
		fputs(numbuf, file);
		fputs("\t", file);
		itoa((scores+i)->eng, numbuf);
		fputs(numbuf, file);
		fputs("\n", file);
	} 

	fclose(file);


	return 0;
}

		
// Convert integer to string and put it in buf
void itoa(int num, char *buf) {
	char fub[10];
	int i = 0;
	int j = 0;

	while (num > 0) {
		fub[i++] = num % 10;
		num /= 10;
	}
	while (--i >= 0) {
		buf[j++] = fub[i];
	}
	buf[j] = '\0';
}

