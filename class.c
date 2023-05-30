#include "main.h"

classPtr* initClass(void) {
    FILE* classFile = fopen("class.csv", "r");
    if (classFile == NULL) {
        printf("The file can't be opened.");
        exit(0);
    }

    classPtr* classArray = (classPtr*)malloc(MAX_CLASS * sizeof(classPtr));
    char line[MAX_CHAR];
    int idx = 0;
    int cnt;
    char* token;
    fgets(line, sizeof(line), classFile);
    while (fgets(line, sizeof(line), classFile) != NULL) {
        classArray[idx] = (classPtr)malloc(sizeof(Class));
         cnt = 0;
        for (token = strtok(line, ","); token != NULL; token = strtok(NULL, ",")) {
            if (cnt == 0) {
                classArray[idx]->classNum = atoi(token);
            }
            else if (cnt == 2) {
                classArray[idx]->className = strdup(token);
            }
            cnt += 1;
        }
        classArray[idx]->inAnimal = NULL; //일단 null포인터로 할당
        idx += 1;
    }

    for (idx; idx < MAX_CLASS; idx++) {
        classArray[idx] = NULL; //null포인터로 초기화
    }

    fclose(classFile);
    return classArray;
}

void freeClass(classPtr* classArray) {
    int idx;
    classPtr tempClass;

    for (idx = 0;idx <MAX_CLASS; idx++) {
        if (classArray[idx] != NULL) {
            tempClass = classArray[idx];
            free(tempClass->className);
            free(tempClass);
        }
    }
    free(classArray);
}