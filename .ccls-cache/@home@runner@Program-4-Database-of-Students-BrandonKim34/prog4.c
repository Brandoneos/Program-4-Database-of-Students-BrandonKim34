#include <ctype.h>
#include <math.h>
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

void printStudent(StudentNode *student) {
  printf("%s:\n", student->pStudent->name);
  printf("\tID - %s\n", student->pStudent->id);
  printf("\tGPA - %.2f\n", student->pStudent->gpa);
  printf("\tCredit Hours - %d\n", student->pStudent->creditHours);
}
void searchStudent(StudentNode *head, char *ID) {
  StudentNode *curr = head;
  while (curr != NULL) {
    if (strcmp(curr->pStudent->id, ID) == 0) {
      printStudent(curr);
      printf("\n\n");
      return;
    }
    curr = curr->pNext;
  }
  printf("Sorry, there is no student in the database with the id %s.\n", ID);
}
void option2_8(Database *database, int i) {
  if (i == 2) {
    StudentNode *curr = (database->pHonorRollList);
    if (curr == NULL) {
      printf("There are no students matching that criteria.\n\n");
      printf("\n");
      return;
    }
    while (curr != NULL) {
      printStudent(curr);
      curr = curr->pNext;
    }
  } else if (i == 3) {
    StudentNode *curr = (database->pAcademicProbationList);
    if (curr == NULL) {
      printf("There are no students matching that criteria.\n\n");
      printf("\n");
      return;
    }
    while (curr != NULL) {
      printStudent(curr);
      curr = curr->pNext;
    }
  } else if (i == 4) {
    StudentNode *curr = (database->pFreshmanList);
    if (curr == NULL) {
      printf("There are no students matching that criteria.\n\n");
      printf("\n");
      return;
    }
    while (curr != NULL) {
      printStudent(curr);
      curr = curr->pNext;
    }
  } else if (i == 5) {
    StudentNode *curr = (database->pSophomoreList);
    if (curr == NULL) {
      printf("There are no students matching that criteria.\n\n");
      printf("\n");
      return;
    }
    while (curr != NULL) {
      printStudent(curr);
      curr = curr->pNext;
    }
  } else if (i == 6) {
    StudentNode *curr = (database->pJuniorList);
    if (curr == NULL) {
      printf("There are no students matching that criteria.\n\n");
      printf("\n");
      return;
    }
    while (curr != NULL) {
      printStudent(curr);
      curr = curr->pNext;
    }
  } else if (i == 7) {
    StudentNode *curr = (database->pSeniorList);
    if (curr == NULL) {
      printf("There are no students matching that criteria.\n\n");
      printf("\n");
      return;
    }
    while (curr != NULL) {
      printStudent(curr);
      curr = curr->pNext;
    }
  } else {
    // error
  }
}

void option1(Database *database) {
  int i;

  StudentNode *curr = (database->pIDList);
  if (curr == NULL) {
    printf("There are no students matching that criteria.\n\n");
    return;
  }
  for (i = 0; i < 10; i++) {
    printStudent(curr);
    if (curr->pNext == NULL) {
      break;
    }
    curr = curr->pNext;
  }
}

void deleteStudent(Database *database) {
  printf("Enter the id of the student to be removed: ");
  char id1[20];
  scanf("%s", id1);
  StudentNode *curr = database->pIDList;
  StudentNode *prev = NULL;
  int i = 0;
  while (curr != NULL) {
    if (strcmp(curr->pStudent->id, id1) == 0) {
      
      // free(curr->pStudent->name);
      // free(curr->pStudent->id);
      // free(curr->pStudent);
      // free(curr);
      i = 1;
      break;
    }
    prev = curr;
    curr = curr->pNext;
  }
  if (i == 0) {
    printf("Sorry, there is no student in the database with the id %s.\n", id1);
    return;
  }

  StudentNode *curr1 = database->pHonorRollList;
  StudentNode *prev1 = NULL;
  while (curr1 != NULL) {
    if (strcmp(curr1->pStudent->id, id1) == 0) {
      if (prev1 == NULL) {
        database->pHonorRollList = curr1->pNext;
      } else {
        prev1->pNext = curr1->pNext;
      }
      // printf("Freeing honor roll node\n");
      free(curr1);
      break;
    }
    prev1 = curr1;
    curr1 = curr1->pNext;
  }

  StudentNode *curr2 = database->pAcademicProbationList;
  StudentNode *prev2 = NULL;
  while (curr2 != NULL) {
    if (strcmp(curr2->pStudent->id, id1) == 0) {
      if (prev2 == NULL) {
        database->pAcademicProbationList = curr2->pNext;
      } else {
        prev2->pNext = curr2->pNext;
      }
      free(curr2);
      break;
    }
    prev2 = curr2;
    curr2 = curr2->pNext;
  }
  StudentNode *curr3 = database->pFreshmanList;
  StudentNode *prev3 = NULL;
  while (curr3 != NULL) {
    if (strcmp(curr3->pStudent->id, id1) == 0) {
      if (prev3 == NULL) {
        database->pFreshmanList = curr3->pNext;
      } else {
        prev3->pNext = curr3->pNext;
      }
      // printf("Freeing freshman node\n");
      free(curr3);
      break;
    }
    prev3 = curr3;
    curr3 = curr3->pNext;
  }
  StudentNode *curr4 = database->pSophomoreList;
  StudentNode *prev4 = NULL;
  while (curr4 != NULL) {
    if (strcmp(curr4->pStudent->id, id1) == 0) {
      if (prev4 == NULL) {
        database->pSophomoreList = curr4->pNext;
      } else {
        prev4->pNext = curr4->pNext;
      }
      free(curr4);
      break;
    }
    prev4 = curr4;
    curr4 = curr4->pNext;
  }
  StudentNode *curr5 = database->pJuniorList;
  StudentNode *prev5 = NULL;
  while (curr5 != NULL) {
    if (strcmp(curr5->pStudent->id, id1) == 0) {
      if (prev5 == NULL) {
        database->pJuniorList = curr5->pNext;
      } else {
        prev5->pNext = curr5->pNext;
      }
      free(curr5);
      break;
    }
    prev5 = curr5;
    curr5 = curr5->pNext;
  }
  StudentNode *curr6 = database->pSeniorList;
  StudentNode *prev6 = NULL;
  while (curr6 != NULL) {
    if (strcmp(curr6->pStudent->id, id1) == 0) {
      if (prev6 == NULL) {
        database->pSeniorList = curr6->pNext;
      } else {
        prev6->pNext = curr6->pNext;
      }
      free(curr6);
      break;
    }
    prev6 = curr6;
    curr6 = curr6->pNext;
  }
  StudentNode *curr7 = database->pIDList;
  StudentNode *prev7 = NULL;

  while (curr7 != NULL) {
    if (strcmp(curr7->pStudent->id, id1) == 0) {
      if (prev7 == NULL) {
        database->pIDList = curr7->pNext;
      } else {
        prev7->pNext = curr7->pNext;
      }
      free(curr7->pStudent->name);
      free(curr7->pStudent->id);
      free(curr7->pStudent);
      free(curr7);
      // printf("Freeing name\n");
      // printf("Freeing id\n");
      // printf("Freeing student\n");
      // printf("Freeing node id list\n");
      break;
    }
    prev7 = curr7;
    curr7 = curr7->pNext;
  }
}

void readStudent(Database *database) {
  char userChoice[20];
  int intU = 0;
  // scanf(" %c", &userChoice);
  printf("Select one of the following: \n");
  printf("\t1) Display the head (first 10 rows) of the database\n");
  printf("\t2) Display students on the honor roll, in order of their GPA\n");
  printf(
      "\t3) Display students on academic probation, in order of their GPA\n");
  printf("\t4) Display freshmen students, in order of their name\n");
  printf("\t5) Display sophomore students, in order of their name\n");
  printf("\t6) Display junior students, in order of their name\n");
  printf("\t7) Display senior students, in order of their name\n");
  printf("\t8) Display the information of a particular student\n");
  char id1[20];
  while (!(intU >= 1 && intU <= 8)) {

    printf("Your choice --> ");
    scanf(" %s", userChoice);
    int isDigit1 = 0;
    if(strlen(userChoice) == 1) {
      intU = atoi(userChoice);
    } else {
      intU = 0;
    }


    switch (intU) {
    case 1:
      option1(database);
      break;
    case 2:
      option2_8(database, intU);
      break;
    case 3:
      option2_8(database, intU);
      break;
    case 4:
      option2_8(database, intU);
      break;
    case 5:
      option2_8(database, intU);
      break;
    case 6:
      option2_8(database, intU);
      break;
    case 7:
      option2_8(database, intU);

      break;
    case 8:

      printf("Enter the id of the student to find: ");

      scanf(" %s", id1);
      searchStudent(database->pIDList, id1);
      // printf("StudentId:%s\n", id1);
      break;
    default:
      printf("Sorry, that input was invalid. Please try again.\n");
      break;
    }
  }
}

void addStudentToList(StudentNode **head, StudentNode *newStudent, int i) {
  StudentNode *curr = (*head);
  if (curr == NULL) {
    // printf("Test1\n");
    *head = newStudent;
    return;
  }
  // 1). insert by id, 5,6,7,8
  // 2). insert by gpa, 1.2,1.3,1.4
  // 3). insert by Name a,b,c,
  if (i == 1) {
    if (strcmp(curr->pStudent->id, newStudent->pStudent->id) >= 0) {
      // printf("Test3\n");
      // printf("details:%s\n", newStudent->pStudent->id);
      newStudent->pNext = curr;
      *head = newStudent;
      return;
    } else {
      // printf("test4\n");
      while (curr->pNext != NULL &&
             (strcmp(curr->pStudent->id, newStudent->pStudent->id) < 0)) {
        if (strcmp(curr->pNext->pStudent->id, newStudent->pStudent->id) >= 0) {
          break;
        }
        curr = curr->pNext; // go to end
      }
      newStudent->pNext = curr->pNext;
      curr->pNext = newStudent;
      return;
    }

  } else if (i == 2) {
    if (curr->pStudent->gpa > newStudent->pStudent->gpa || fabs(curr->pStudent->gpa - newStudent->pStudent->gpa) < 0.00001) {
      newStudent->pNext = curr;
      *head = newStudent;
      return;
    } else {
      while (curr->pNext != NULL &&
             (curr->pStudent->gpa < newStudent->pStudent->gpa)) {
        if (curr->pNext->pStudent->gpa >= newStudent->pStudent->gpa) {
          break;
        }
        curr = curr->pNext; // go to end
      }
      newStudent->pNext = curr->pNext;
      curr->pNext = newStudent;
      return;
    }
  } else if (i == 3) {
    if (strcmp(curr->pStudent->name, newStudent->pStudent->name) >= 0) {
      newStudent->pNext = curr;
      *head = newStudent;
      return;
    } else {
      while (curr->pNext != NULL &&
             (strcmp(curr->pStudent->name, newStudent->pStudent->name) < 0)) {
        if (strcmp(curr->pNext->pStudent->name, newStudent->pStudent->name) >=
            0) {
          break;
        }
        curr = curr->pNext; // go to end
      }
      newStudent->pNext = curr->pNext;
      curr->pNext = newStudent;
      return;
    }
  } else {
    printf("Error, shouldn't print when adding student to list\n");
    return;
  }
}

void createStudent(Database **database) {
  char name[81];
  char id[81];
  double gpa;
  int ch;
  getchar();
  printf("Enter the name of the new student: ");
  fgets(name, 81, stdin);
  name[strcspn(name, "\n")] = 0;
  printf("Enter the ID of the new student: ");
  // scanf("%s", id);
  fgets(id, 81, stdin);
  id[strcspn(id, "\n")] = 0;
  printf("Enter the GPA of the new student: ");
  scanf("%lf", &gpa);
  // fgets(gpa,81,stdin);
  printf("Enter the credit hours of the new student: ");
  scanf("%d", &ch);
  // fgets(name,81,stdin);
  StudentNode *IDlistStudent = (*database)->pIDList;
  StudentNode *HonorRollStudent = (*database)->pHonorRollList;
  StudentNode *probationStudent = (*database)->pAcademicProbationList;
  StudentNode *freshman = (*database)->pFreshmanList;
  StudentNode *sophomore = (*database)->pSophomoreList;
  StudentNode *junior = (*database)->pJuniorList;
  StudentNode *senior = (*database)->pSeniorList;

  StudentNode *newStudent = (StudentNode *)malloc(sizeof(StudentNode));
  newStudent->pNext = NULL;
  newStudent->pStudent = malloc(sizeof(Student));

  newStudent->pStudent->name = malloc(strlen(name) + 1);
  strcpy(newStudent->pStudent->name, name);
  newStudent->pStudent->id = malloc(strlen(id) + 1);
  strcpy(newStudent->pStudent->id, id);
  newStudent->pStudent->gpa = gpa;
  newStudent->pStudent->creditHours = ch;

  if ((*database)->pIDList == NULL) {
    (*database)->pIDList = newStudent;
    IDlistStudent = (*database)->pIDList;
  } else {
    // printf("Test\n");
    addStudentToList(&((*database)->pIDList), newStudent, 1);
    // printf("Head:%s\n", IDlistStudent->pStudent->name);
    // printf("Head2:%s\n", (*database)->pIDList->pStudent->name);
  }

  // After splitting string and initlizing to new student
  // Add to the correct lists

  if (fabs(newStudent->pStudent->gpa) >=
      3.5) { // checks if student is honor roll student
    StudentNode *newHonorStudent = (StudentNode *)malloc(sizeof(StudentNode));
    newHonorStudent->pNext = NULL;
    newHonorStudent->pStudent = newStudent->pStudent;

    if ((*database)->pHonorRollList == NULL) {
      (*database)->pHonorRollList = newHonorStudent;
      HonorRollStudent = (*database)->pHonorRollList;
    } else {
      addStudentToList(&((*database)->pHonorRollList), newHonorStudent, 2);
    }
  }

  if (fabs(newStudent->pStudent->gpa) <
      2.0) { // check if student is on probation
    StudentNode *newProb = (StudentNode *)malloc(sizeof(StudentNode));
    newProb->pNext = NULL;
    newProb->pStudent = newStudent->pStudent;

    if ((*database)->pAcademicProbationList == NULL) {
      (*database)->pAcademicProbationList = newProb;
      probationStudent = (*database)->pAcademicProbationList;
    } else {
      addStudentToList(&((*database)->pAcademicProbationList), newProb, 2);
    }
  }

  if (newStudent->pStudent->creditHours >= 0 &&
      newStudent->pStudent->creditHours <=
          29) { // check which year the student is in
    // freshman
    StudentNode *newFresh = (StudentNode *)malloc(sizeof(StudentNode));
    newFresh->pNext = NULL;
    newFresh->pStudent = newStudent->pStudent;

    if ((*database)->pFreshmanList == NULL) {
      (*database)->pFreshmanList = newFresh;
      freshman = (*database)->pFreshmanList;
    } else {
      addStudentToList(&((*database)->pFreshmanList), newFresh, 3);
    }

  } else if (newStudent->pStudent->creditHours >= 30 &&
             newStudent->pStudent->creditHours <= 59) {
    // sophomore
    StudentNode *newSoph = (StudentNode *)malloc(sizeof(StudentNode));
    newSoph->pNext = NULL;
    newSoph->pStudent = newStudent->pStudent;

    if ((*database)->pSophomoreList == NULL) {
      (*database)->pSophomoreList = newSoph;
      sophomore = (*database)->pSophomoreList;
    } else {
      addStudentToList(&((*database)->pSophomoreList), newSoph, 3);
    }

  } else if (newStudent->pStudent->creditHours >= 60 &&
             newStudent->pStudent->creditHours <= 89) {
    // junior
    StudentNode *newJun = (StudentNode *)malloc(sizeof(StudentNode));
    newJun->pNext = NULL;
    newJun->pStudent = newStudent->pStudent;

    if ((*database)->pJuniorList == NULL) {
      (*database)->pJuniorList = newJun;
      junior = (*database)->pJuniorList;
    } else {
      addStudentToList(&((*database)->pJuniorList), newJun, 3);
    }

  } else if (newStudent->pStudent->creditHours >= 90) {
    // senior
    StudentNode *newSen = (StudentNode *)malloc(sizeof(StudentNode));
    newSen->pNext = NULL;
    newSen->pStudent = newStudent->pStudent;

    if ((*database)->pSeniorList == NULL) {
      (*database)->pSeniorList = newSen;
      senior = (*database)->pSeniorList;
    } else {
      addStudentToList(&((*database)->pSeniorList), newSen, 3);
    }
  } else {
    printf("Error, no class?\n");
    // shouldn't print
  }

  printf("Successfully added the following student to the database!\n");
  printStudent(newStudent);
  printf("\n");
  printf("\n");
}

void action() {
  char userChoice = ' ';
  scanf(" %c", &userChoice);
  while (userChoice != 'X') {
    printf(
        "\nEnter: \tC to create a new student and add them to the database,\n");
    printf("\tR to read from the database,\n");
    printf("\tD to delete a student from the database, or\n");
    printf("\tX to exit the program.\n");
    printf("Your choice --> ");
    scanf(" %c", &userChoice);

    // TODO: Finish filling in the code for these menu options
    switch (userChoice) {
    case 'C':
      break;
    case 'R':
      break;
    case 'D':
      break;
    case 'X':
      break;
    default:
      printf("Invalid option. Try again.\n");
    }
  }
}

void allocateDatabase(Database **database) {
  (*database) = (Database *)malloc(sizeof(Database));

  (*database)->pIDList = NULL;
  (*database)->pHonorRollList = NULL;
  (*database)->pAcademicProbationList = NULL;
  (*database)->pFreshmanList = NULL;
  (*database)->pSophomoreList = NULL;
  (*database)->pJuniorList = NULL;
  (*database)->pSeniorList = NULL;
  // database->pIDList->pStudent = not initialized yet
}
void printpIDList(Database *database) {
  if (database->pIDList == NULL) {
    printf("No students\n");
    return;
  }
  printf("Printing ID List:\n");

  StudentNode *s1 = database->pIDList;
  while (s1 != NULL) {
    printf("%s\n", s1->pStudent->name);
    s1 = s1->pNext;
  }

  // while (s1 != NULL) {
  //   printf("%s\n", s1->pStudent->name);
  //   s1 = s1->pNext;
  // }
}

void readFile(char *fileName, Database **database) {
  // printf("FileName:%s\n", fileName);
  FILE *filePtr = fopen(fileName, "r");
  char inputString[81];
  if (filePtr == NULL) {
    printf("Error: could not open %s for reading\n", fileName);
    exit(-1);
  }
  int firstline = 0;
  StudentNode *IDlistStudent = (*database)->pIDList;
  StudentNode *HonorRollStudent = (*database)->pHonorRollList;
  StudentNode *probationStudent = (*database)->pAcademicProbationList;

  StudentNode *freshman = (*database)->pFreshmanList;
  StudentNode *sophomore = (*database)->pSophomoreList;
  StudentNode *junior = (*database)->pJuniorList;
  StudentNode *senior = (*database)->pSeniorList;

  while (fgets(inputString, 81, filePtr) != NULL) {
    if (firstline == 0) {
      firstline++;
    } else {
      StudentNode *newStudent = (StudentNode *)malloc(sizeof(StudentNode));
      newStudent->pNext = NULL;
      newStudent->pStudent = malloc(sizeof(Student));

      // split up string from fgets
      char *modifiedString;
      modifiedString = inputString;
      if (modifiedString[strlen(inputString) - 1] == '\n') {
        modifiedString[strlen(inputString) - 1] = 0;
      }
      char delim[] = ",";

      char *ptr = strtok(modifiedString, delim);
      int i = 0;
      while (ptr != NULL) {

        i = i % 4;
        if (i == 0) {
          newStudent->pStudent->name = malloc(strlen(ptr) + 1);
          strcpy(newStudent->pStudent->name, ptr);
          // printf("'%s' ", ptr);
        } else if (i == 1) {
          newStudent->pStudent->id = malloc(strlen(ptr) + 1);
          strcpy(newStudent->pStudent->id, ptr);
          // printf("'%s' ", ptr);
        } else if (i == 2) {
          char *p;
          newStudent->pStudent->gpa = strtod(ptr, &p);
          // printf("'%lf' ", strtod(ptr, &p));
        } else if (i == 3) {
          newStudent->pStudent->creditHours = atoi(ptr);
          // printf("'%d' ", atoi(ptr));
        } else {
          printf("error\n");
        }
        i++;
        // string,string,double, int
        ptr = strtok(NULL, delim);
      }

      if ((*database)->pIDList == NULL) {
        (*database)->pIDList = newStudent;
        IDlistStudent = (*database)->pIDList;
      } else {
        // printf("Test\n");
        addStudentToList(&((*database)->pIDList), newStudent, 1);
        // printf("Head:%s\n", IDlistStudent->pStudent->name);
        // printf("Head2:%s\n", (*database)->pIDList->pStudent->name);
      }

      // After splitting string and initlizing to new student
      // Add to the correct lists

      if (fabs(newStudent->pStudent->gpa) >=
          3.5) { // checks if student is honor roll student
        StudentNode *newHonorStudent =
            (StudentNode *)malloc(sizeof(StudentNode));
        newHonorStudent->pNext = NULL;
        newHonorStudent->pStudent = newStudent->pStudent;

        if ((*database)->pHonorRollList == NULL) {
          (*database)->pHonorRollList = newHonorStudent;
          HonorRollStudent = (*database)->pHonorRollList;
        } else {
          addStudentToList(&((*database)->pHonorRollList), newHonorStudent, 2);
        }
      }

      if (fabs(newStudent->pStudent->gpa) <
          2.0) { // check if student is on probation
        StudentNode *newProb = (StudentNode *)malloc(sizeof(StudentNode));
        newProb->pNext = NULL;
        newProb->pStudent = newStudent->pStudent;

        if ((*database)->pAcademicProbationList == NULL) {
          (*database)->pAcademicProbationList = newProb;
          probationStudent = (*database)->pAcademicProbationList;
        } else {
          addStudentToList(&((*database)->pAcademicProbationList), newProb, 2);
        }
      }

      if (newStudent->pStudent->creditHours >= 0 &&
          newStudent->pStudent->creditHours <=
              29) { // check which year the student is in
        // freshman
        StudentNode *newFresh = (StudentNode *)malloc(sizeof(StudentNode));
        newFresh->pNext = NULL;
        newFresh->pStudent = newStudent->pStudent;

        if ((*database)->pFreshmanList == NULL) {
          (*database)->pFreshmanList = newFresh;
          freshman = (*database)->pFreshmanList;
        } else {
          addStudentToList(&((*database)->pFreshmanList), newFresh, 3);
        }

      } else if (newStudent->pStudent->creditHours >= 30 &&
                 newStudent->pStudent->creditHours <= 59) {
        // sophomore
        StudentNode *newSoph = (StudentNode *)malloc(sizeof(StudentNode));
        newSoph->pNext = NULL;
        newSoph->pStudent = newStudent->pStudent;

        if ((*database)->pSophomoreList == NULL) {
          (*database)->pSophomoreList = newSoph;
          sophomore = (*database)->pSophomoreList;
        } else {
          addStudentToList(&((*database)->pSophomoreList), newSoph, 3);
        }

      } else if (newStudent->pStudent->creditHours >= 60 &&
                 newStudent->pStudent->creditHours <= 89) {
        // junior
        StudentNode *newJun = (StudentNode *)malloc(sizeof(StudentNode));
        newJun->pNext = NULL;
        newJun->pStudent = newStudent->pStudent;

        if ((*database)->pJuniorList == NULL) {
          (*database)->pJuniorList = newJun;
          junior = (*database)->pJuniorList;
        } else {
          addStudentToList(&((*database)->pJuniorList), newJun, 3);
        }

      } else if (newStudent->pStudent->creditHours >= 90) {
        // senior
        StudentNode *newSen = (StudentNode *)malloc(sizeof(StudentNode));
        newSen->pNext = NULL;
        newSen->pStudent = newStudent->pStudent;

        if ((*database)->pSeniorList == NULL) {
          (*database)->pSeniorList = newSen;
          senior = (*database)->pSeniorList;
        } else {
          addStudentToList(&((*database)->pSeniorList), newSen, 3);
        }
      } else {
        printf("Error, no class?\n");
        // shouldn't print
      }
      // IDlistStudent->pNext = NULL;
      // printf("\n");
    }
  }

  fclose(filePtr);
}

void getFile(char **input) {
  printf("Enter the name of the file you would like to use: ");
  char input2[20];
  scanf("%s", input2);
  *input = malloc(strlen(input2) + 1);
  strcpy(*input, input2); // need to free the filename later
  // Might need to check if file exists
  // getchar();
}

void printGreeting(char *input1) {
  printf("CS 211, Spring 2023\n");
  printf("Program 4: Database of Students\n\n");

  printf("Enter E to start with an empty database, \n");
  printf("or F to start with a database that has information on students from "
         "a file.\n");
  printf("Your choice --> ");
  char input2[20];
  scanf(" %s", input2);
  getchar();
  char choice2 = ' ';
    if(strlen(input2) == 1) {
      choice2 = input2[0];
    } else {
      choice2 = 'f';
    }
  
  while (choice2 != 'E' && choice2 != 'F') {
    printf("Sorry, that input was invalid. Please try again.\n");
    printf("Your choice --> ");
    scanf(" %s", input2);
    getchar();
    if(strlen(input2) == 1) {
      choice2 = input2[0];
    } else {
      choice2 = 'f';
    }
  }
  *input1 = choice2;
  
}

void freeDatabase(Database *database) {
  StudentNode *curr;

  curr = database->pIDList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp->pStudent->name);
    free(temp->pStudent->id);
    free(temp->pStudent);
    free(temp);
  }
  curr = database->pHonorRollList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp);
  }
  curr = database->pAcademicProbationList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp);
  }
  curr = database->pFreshmanList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp);
  }
  curr = database->pSophomoreList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp);
  }
  curr = database->pJuniorList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp);
  }
  curr = database->pSeniorList;
  while (curr != NULL) {
    StudentNode *temp = curr;
    curr = curr->pNext;
    free(temp);
  }

  free(database);
}

int main() {
  Database *database;
  allocateDatabase(
      &database); // database allocated, lists allocated for first StudentNode,
                  // students not allocated yet until reading file.

  // database->pAcademicProbationList = NULL;

  // if( database->pAcademicProbationList == NULL) {
  //   printf("Test\n");
  // }

  char input = 'E';
  char *fileName;
  printGreeting(&input);
  
  if (input == 'F') {
    getFile(&fileName);
    readFile(fileName, &database);
  }
  // printpIDList(database);

  // Replace with action()
  char userChoice[20] = " ";
  // scanf(" %c", &userChoice);
  while (strcmp(userChoice, "X") != 0) {
    printf(
        "\nEnter: \tC to create a new student and add them to the database,\n");
    printf("\tR to read from the database,\n");
    printf("\tD to delete a student from the database, or\n");
    printf("\tX to exit the program.\n");
    printf("Your choice --> ");
    scanf(" %s", userChoice);
    char choice2 = ' ';
    if(strlen(userChoice) == 1) {
      choice2 = userChoice[0];
    } else {
      choice2 = 'f';
    }
    switch (choice2) {
    case 'C':
      createStudent(&database);
      break;
    case 'R':
      readStudent(database);
      break;
    case 'D':
      deleteStudent(database);
      break;
    case 'X':
      break;
    default:
      printf("Invalid option. Try again.\n");
      break;
    }
  }

  // To here
  printf("\n");
  printf("Thanks for playing!\n");
  printf("Exiting...\n");
  freeDatabase(database);
  free(fileName);
  return 0;
}