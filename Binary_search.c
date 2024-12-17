#include <stdio.h>
#include <string.h>


struct Student {
    int rollNo;
    char name[50];
    float percentage;
};


int binarySearch(struct Student students[], int size, int rollNo) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (students[mid].rollNo == rollNo) {
            return mid;
        }
        else if (students[mid].rollNo < rollNo) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, rollNo, foundIndex;


    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];


    printf("Enter details of students:\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) 
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        getchar();
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }
    printf("\nEnter the roll number to search: ");
    scanf("%d", &rollNo);


    foundIndex = binarySearch(students, n, rollNo);

    if (foundIndex != -1) {
        printf("\nStudent found:\n");
        printf("Roll No: %d\n", students[foundIndex].rollNo);
        printf("Name: %s\n", students[foundIndex].name);
        printf("Percentage: %.2f%%\n", students[foundIndex].percentage);
    } else {
        printf("\nStudent with Roll No %d not found.\n", rollNo);
    }

    return 0;
}
