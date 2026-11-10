#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 50 // Number of alumni

int main() {
    FILE *file;
    char filename[50];
    char line[256];
    int choice;

    // Data arrays (assuming columns are: Income, Expenditure, Savings)
    double income[N], expenditure[N], savings[N];

    // Sum variables
    double sum_x = 0, sum_y = 0, sum_z = 0;
    double sum_x2 = 0, sum_y2 = 0, sum_z2 = 0;
    double sum_xy = 0, sum_xz = 0;

    // Ask user which file to load based on roll number
    printf("Enter 1 for inc2_data1.csv (Odd Roll)\n");
    printf("Enter 2 for inc2_data2.csv (Even Roll)\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        strcpy(filename, "inc2_data1.csv");
    } else if (choice == 2) {
        strcpy(filename, "inc2_data2.csv");
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    // Open the CSV file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s. Make sure it is in the same folder.\n", filename);
        return 1;
    }

    // Read the header row and discard it
    fgets(line, sizeof(line), file);

    // Read the data
    int i = 0;
    while (fgets(line, sizeof(line), file) && i < N) {
        // Assuming CSV format is: Income,Expenditure,Savings
        // If your CSV uses a different order, change the variables below
        sscanf(line, "%lf,%lf,%lf", &income[i], &expenditure[i], &savings[i]);

        // Accumulate sums for parts (a), (b), (c)
        sum_x += income[i];      // x = Income
        sum_y += expenditure[i]; // y = Expenditure
        sum_z += savings[i];     // z = Savings

        sum_x2 += (income[i] * income[i]);
        sum_y2 += (expenditure[i] * expenditure[i]);
        sum_z2 += (savings[i] * savings[i]);

        sum_xy += (income[i] * expenditure[i]);
        sum_xz += (income[i] * savings[i]);

        i++;
    }
    fclose(file);

    if (i < N) {
        printf("Warning: Only read %d rows. Expected %d.\n", i, N);
    }

    // Calculate Means
    double mean_x = sum_x / N;
    double mean_y = sum_y / N;
    double mean_z = sum_z / N;

    // (a) Average Income, Expenditure, Savings

    printf("\n--- (a) Averages ---\n");
    printf("Average Income: %.4f\n", mean_x);
    printf("Average Expenditure: %.4f\n", mean_y);
    printf("Average Savings: %.4f\n", mean_z);

    // (b) Standard Deviation and Coefficient of Variation
    // Formula: SD = sqrt( (Sum(x^2) - n*mean^2) / n )

    double var_x = (sum_x2 / N) - (mean_x * mean_x);
    double var_y = (sum_y2 / N) - (mean_y * mean_y);

    double sd_x = sqrt(var_x);
    double sd_y = sqrt(var_y);
    double cv_x = (sd_x / mean_x) * 100;
    double cv_y = (sd_y / mean_y) * 100;
    printf("\n--- (b) Standard Deviation & Coefficient of Variation ---\n");
    printf("Income SD: %.4f, CV: %.4f%%\n", sd_x, cv_x);
    printf("Expenditure SD: %.4f, CV: %.4f%%\n", sd_y, cv_y);

    if (cv_x > cv_y) {
        printf("Interpretation: Income has more variability (higher CV).\n");
    } else {
        printf("Interpretation: Expenditure has more variability (higher CV).\n");
    }


    // (c) Correlation
    // Formula: r = (n*Sum(xy) - Sum(x)*Sum(y)) / sqrt([n*Sum(x^2)-Sum(x)^2] * [n*Sum(y^2)-Sum(y)^2])

    double numerator_xy = (N * sum_xy) - (sum_x * sum_y);
    double denom_xy = sqrt( ((N * sum_x2) - (sum_x * sum_x)) * ((N * sum_y2) - (sum_y * sum_y)) );
    double r_xy = numerator_xy / denom_xy;

    double numerator_xz = (N * sum_xz) - (sum_x * sum_z);
    double denom_xz = sqrt( ((N * sum_x2) - (sum_x * sum_x)) * ((N * sum_z2) - (sum_z * sum_z)) );
    double r_xz = numerator_xz / denom_xz;

    printf("\n--- (c) Correlation ---\n");
    printf("Correlation between Income and Expenditure: %.4f\n", r_xy);
    printf("Correlation between Income and Savings: %.4f\n", r_xz);


    // (d) Simple Linear Regression
    // Fitting Regression between Income (x) and the strongly correlated variable.
    // We will compare absolute values of r_xy and r_xz to find the stronger one.

    printf("\n--- (d) Simple Linear Regression ---\n");

    // Determine which variable is strongly correlated
    if (fabs(r_xy) > fabs(r_xz)) {
        printf("Strongest correlation is between Income (x) and Expenditure (y).\n");

        // Beta 1 (Slope)
        double beta1 = numerator_xy / ((N * sum_x2) - (sum_x * sum_x));
        // Beta 0 (Intercept)
        double beta0 = mean_y - (beta1 * mean_x);

        printf("Regression Equation: Expenditure = %.4f + %.4f * Income\n", beta0, beta1);
        printf("Interpretation: For every 1 unit (thousand) increase in income, expenditure increases by %.4f units.\n", beta1);
    } else {
        printf("Strongest correlation is between Income (x) and Savings (z).\n");

        // Beta 1 (Slope)
        double beta1 = numerator_xz / ((N * sum_x2) - (sum_x * sum_x));
        // Beta 0 (Intercept)
        double beta0 = mean_z - (beta1 * mean_x);

        printf("Regression Equation: Savings = %.4f + %.4f * Income\n", beta0, beta1);
        printf("Interpretation: For every 1 unit (thousand) increase in income, savings increases by %.4f units.\n", beta1);
    }

    return 0;
}
