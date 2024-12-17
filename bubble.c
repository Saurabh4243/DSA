#include <stdio.h>
#include <string.h>

struct student {
    int rollNo;
    char name[50];
    float percentage;
};

void bubble(struct student stud[], int n) {
    int i, j;
    struct student temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(stud[i].percentage > stud[j].percentage) {
                temp = stud[i];
                stud[i] = stud[j];
                stud[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student students[n];

    printf("Enter details of students:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        getchar(); // To consume newline character
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    // Sort students by percentage
    bubble(students, n);

    printf("\nStudent details are:\n");
    for(int i = 0; i < n; i++) {
        printf("Student name: %s\n", students[i].name);
        printf("Student roll number: %d\n", students[i].rollNo);
        printf("Student percentage: %.2f\n", students[i].percentage);
    }

    return 0;
}
