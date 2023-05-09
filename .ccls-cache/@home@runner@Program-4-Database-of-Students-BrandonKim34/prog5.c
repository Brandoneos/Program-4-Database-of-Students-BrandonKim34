#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *id;
  double gpa;
  int creditHours;
} Student;

typedef struct StudentNode {
  Student *pStudent;
  struct StudentNode *pNext;
} StudentNode;

typedef struct {
  StudentNode *pIDList;
  StudentNode *pHonorRollList;
  StudentNode *pAcademicProbationList;
  StudentNode *pFreshmanList;
  StudentNode *pSophomoreList;
  StudentNode *pJuniorList;
  StudentNode *pSeniorList;
} Database;

int main() {
  StudentNode *newStudent = malloc(sizeof(StudentNode);
  newStudent->pNext = NULL;
  newStudent->pStudent = malloc(sizeof(Student));
  char* path = "Brandon";
  char* id = "91209d1n";
  newStudent->pStudent->name = malloc(strlen(path)+1);
  newStudent->pStudent->name = path;
  newStudent->pStudent->id = malloc(strlen(path)+1);
  newStudent->pStudent->id = id;
  newStudent->pStudent->gpa = 1.2;
  newStudent->pStudent->creditHours = 100;

  printf("Printing:%s\n",newStudent->pStudent->name);
  return 0; 
}
