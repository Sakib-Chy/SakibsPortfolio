#include <stdio.h>

// Function to assign grade
char getGrade(int marks) {
    if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int id[n], phy[n], math[n];
    float avg[n];

    int maxPhy = -1, minPhy = 101;
    int maxMath = -1, minMath = 101;

    // Input section (formatted like your sample)
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &id[i]);

        printf("Physics: ");
        scanf("%d", &phy[i]);

        printf("Mathematics: ");
        scanf("%d", &math[i]);

        avg[i] = (phy[i] + math[i]) / 2.0;

        // Max/Min calculation
        if (phy[i] > maxPhy) maxPhy = phy[i];
        if (phy[i] < minPhy) minPhy = phy[i];

        if (math[i] > maxMath) maxMath = math[i];
        if (math[i] < minMath) minMath = math[i];
    }

    // Output table
    printf("\nSample Output:\n\n");
    printf("ID   Phy   Math   Avg   Grades(P/M)\n");

    for (int i = 0; i < n; i++) {
        printf("%d   %d    %d    %.2f   %c %c\n",
               id[i], phy[i], math[i], avg[i],
               getGrade(phy[i]), getGrade(math[i]));
    }

    // Statistics
    printf("\nSubject Statistics:\n\n");

    printf("Max Physics Marks: %d\n\n", maxPhy);
    printf("Min Physics Marks: %d\n\n", minPhy);

    printf("Max Mathematics Marks: %d\n\n", maxMath);
    printf("Min Mathematics Marks: %d\n\n", minMath);

    // Top performers
    printf("Top Performers:\n\n");

    printf("Physics Topper(s): ");
    for (int i = 0; i < n; i++) {
        if (phy[i] == maxPhy)
            printf("%d", id[i]);
        if (i < n - 1 && phy[i] == maxPhy)
            printf(", ");
    }

    printf("\n\nMathematics Topper(s): ");
    for (int i = 0; i < n; i++) {
        if (math[i] == maxMath)
            printf("%d", id[i]);
        if (i < n - 1 && math[i] == maxMath)
            printf(", ");
    }

    printf("\n");

    return 0;
}