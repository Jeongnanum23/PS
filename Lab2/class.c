#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

char kname[2][10] = {"A+~F", "P/F"};

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.

    int ncode =0;


	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));

    while(1){
        int exit = 0;
        printf(">> code number > ");
        scanf("%d", &ncode);
        for(int i =0; i<csize; i++){
            if(c[i]->code == ncode){
                printf("Code duplicated! Retry.\n");
                exit = 1;
                break;
            }
        }
        if(exit == 0){
            break;
        }
    }

    p->code = ncode;
	
	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;

    while(1){
        printf(">> Enter a code of class > ");
        scanf("%d", &code);
        
        
        // You must complete this section.
    
        int check =0;
        for(int i = 0; i<csize; i++){
            if(c[i]->code == code){
            p = c[i];
            check =1;
            break;
            }
        }

        if(check ==0){
            printf("> No such class.\n");
        }else{
            break;
        }

    }


	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	printf("> Modified.\n");

}


// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
    int code =0;
    int flag=0;

    while(1){
        int found =0;
        int code_check =0;
        printf(">> Enter a class code > ");
        scanf("%d", &code);

        for(int i = 0; i<csize; i++){
            if(c[i]->code == code){
                code_check =1;
                for(int j =0; j<msize;j++){
                    if(my[j]==code){
                        printf("class already added\n");
                        found =1;
                        break;
                    }
                }
                if(found ==0){
                    printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
                    my[msize] = code;
                    msize++;
                    break;
                }
            
            }
        }
        if(code_check==0){
            printf("No such code of class.\n");
        }

        printf(">> Add more?( 1:Yes 2:No) > ");
        scanf("%d", &flag);
        if(flag == 2){
            break;
        }
    }
	
	return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){

    int total =0;

    for(int i =0;i<msize; i++){
        for(int j = 0; j<csize; j++){
            if(c[j]->code == my[i]){
                printf("[%d] %s [credit %d - %s]\n",c[j]->code, c[j]->name, c[j]->unit, kname[c[i]->grading-1]);
                total += c[j]->unit;
                break;
            }
        }
    }
	
    printf("All: %d credits\n", total);

}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){

    FILE* file;
        file = fopen("my_classes.txt", "w");
        for(int i =0;i<msize; i++){
            for(int j = 0; j<csize; j++){
                if(c[j]->code == my[i]){
                    fprintf(file, "%d %s %d %d\n",c[j]->code, c[j]->name, c[j]->unit, c[j]->grading);
                    break;
                }
            }
        }
        
        fclose(file);
	
}