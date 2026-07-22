#include <stdio.h>
#include <string.h>

struct students
{
    char name[50];
    int age;
    int roll_number;
    float percentage;
    char grade;
};
int search_student(struct students *s, int count);

int breakable = 1;

int program_check(int breakable)
{
    if (breakable == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int exit_program()
{
    breakable = 0;
    return 0;
}
int add_student(struct students *s, int *count)
{
    // Check if array is full
    if (*count >= 100)
    {
        printf("Student list is full!\n");
        return 1;
    }

    // Clear the newline left by scanf() in main()
    while (getchar() != '\n') // adv
        ;

    printf("Enter student name: ");
    fgets(s[*count].name, sizeof(s[*count].name), stdin);

    // Remove the newline added by fgets()
    s[*count].name[strcspn(s[*count].name, "\n")] = '\0'; // adv

    // Check if the user entered an empty name
    if (strlen(s[*count].name) == 0)
    {
        printf("Student name cannot be empty!\n");
        return 1;
    }

    printf("Enter student age: ");
    scanf("%d", &s[*count].age);

    printf("Enter student roll number: ");
    scanf("%d", &s[*count].roll_number);

    // Check for duplicate roll number
    for (int i = 0; i < *count; i++)
    {
        if (s[i].roll_number == s[*count].roll_number)
        {
            printf("Roll number already exists!\n");
            return 1;
        }
    }

    printf("Enter student percentage: ");
    scanf("%f", &s[*count].percentage);

    printf("Enter student grade: ");
    scanf(" %c", &s[*count].grade);

    (*count)++;

    printf("\nStudent added successfully!\n");

    return 0;
}

void display_students(struct students s[], int count)
{
    if (count == 0)
    {
        printf("No students available!\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Name       : %s\n", s[i].name);
        printf("Age        : %d\n", s[i].age);
        printf("Roll No    : %d\n", s[i].roll_number);
        printf("Percentage : %.2f\n", s[i].percentage);
        printf("Grade      : %c\n", s[i].grade);
        printf("---------------------------------\n");
    }
}

int update_student(struct students *s, int *count)
{
    int index;
    printf("Enter the index of the student who you want to update \n");
    scanf("%d", &index);

    if (index < 0 || index >= *count)
    {
        printf("Invalid index!\n");
        return 0;
    }

    while (getchar() != '\n')
        ;

    printf("\nEnter new name: ");
    fgets(s[index].name, sizeof(s[index].name), stdin);
    s[index].name[strcspn(s[index].name, "\n")] = '\0'; // adv

    printf("Enter new age: ");
    scanf("%d", &s[index].age);

    printf("Enter new roll number: ");
    scanf("%d", &s[index].roll_number);

    for (int i = 0; i < *count; i++)
    {
        if (i != index && s[i].roll_number == s[index].roll_number)
        {
            printf("Roll number already exists!\n");
            return 1;
        }
    }

    printf("Enter new percentage: ");
    scanf("%f", &s[index].percentage);

    printf("Enter new grade: ");
    scanf(" %c", &s[index].grade);

    printf("\nStudent updated successfully!\n");

    return 0;
}

int delete_student(struct students *s, int *count)
{
    int index = search_student(s, *count);

    if (index == -1)
        return 0;

    for (int i = index; i < *count - 1; i++)
    {
        s[i] = s[i + 1];
    }

    (*count)--;

    printf("Student deleted successfully!\n");

    return 0;
}

int search_student(struct students *s, int count)
{
    int roll;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (s[i].roll_number == roll)
        {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", s[i].name);
            printf("Age: %d\n", s[i].age);
            printf("Roll Number: %d\n", s[i].roll_number);
            printf("Percentage: %.2f\n", s[i].percentage);
            printf("Grade: %c\n", s[i].grade);

            return i; // return the index
        }
    }

    printf("Student not found!\n");
    return -1;
}

int save_to_file(struct students *s, int count)
{
    FILE *ptr = fopen("datafile.txt", "w");

    if (ptr == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(ptr, "%s,%d,%d,%.2f,%c\n",
                s[i].name,
                s[i].age,
                s[i].roll_number,
                s[i].percentage,
                s[i].grade);
    }

    fclose(ptr);

    printf("Data saved successfully!\n");

    return 0;
}

int load_from_file(struct students *s, int *count)
{
    FILE *ptr;
    ptr = fopen("datafile.txt", "r");

    if (ptr == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    *count = 0;

    while (*count < 100 &&
           fscanf(ptr, "%49[^,],%d,%d,%f,%c\n",
                  s[*count].name,
                  &s[*count].age,
                  &s[*count].roll_number,
                  &s[*count].percentage,
                  &s[*count].grade) == 5)
    {
        (*count)++;
    }

    fclose(ptr);

    printf("Data loaded successfully!\n");

    return 0;
}

int main(void)
{
    int choice;
    struct students s[100];
    int count = 0;

    while (program_check(breakable))
    {
        printf("======================================================================================\n");
        printf("student Managment\n");
        printf("======================================================================================\n");
        printf("\n 1.add student\n 2.display student\n 3.search student\n 4. update student\n 5.delete student\n 6.save to file\n 7. load from file\n 8.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_student(s, &count);
            break;
        case 2:
            display_students(s, count);
            break;
        case 3:
            search_student(s, count);
            break;

        case 4:
            update_student(s, &count);
            break;

        case 5:
            delete_student(s, &count);
            break;
        case 6:
            save_to_file(s, count);
            break;
        case 7:
            load_from_file(s, &count);
            break;
        case 8:
            exit_program();
            printf("thank you for using the program!\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}