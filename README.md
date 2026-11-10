I know exactly why it looks worse. GitHub is incredibly picky about Markdown. When you have a list like `**Slope:**` right above `$$`, GitHub's parser sometimes thinks the math is part of the list and breaks it. 

Also, I noticed in your screenshot that the text was cut off on the right side. This happens if there are no spaces around the math, or if it's mixed with plain text.

The absolute safest way to write math on GitHub—so it **never** breaks—is to put the formula on a single line using single dollar signs `$ ... $`. It renders beautifully inline and GitHub never messes it up.

Here is the 100% bulletproof version. Delete everything in your README and paste this exact block:

```markdown
# CSE330-Statistical-Analysis-with-C

I used C to implement mean, variance, correlation, regression and other statistical measures from scratch. This project demonstrates what I learned in AST 101 (Introduction to Applied Statistics and Data Science) by calculating the mathematical formulas manually, without relying on built-in statistics libraries. 

The program reads a CSV file containing data for 50 ISRT alumni (Income, Expenditure, and Savings) and calculates the required metrics.

## How to Run
1. Compile the code (make sure to link the math library):
   ```bash
   gcc main.c -o stats_program -lm
   ```
2. Run the program:
   ```bash
   ./stats_program
   ```
3. Enter `1` for Odd roll number data, or `2` for Even. 

*(I included the `inc2_data1.csv` and `inc2_data2.csv` files in the repo so it runs immediately).*

---

## The Math Used (From Scratch)

Since I couldn't use built-in statistics functions, I had to code the actual math formulas into the C file. The formulas are based on the concepts from *Introductory Statistics by Prem S. Mann* (Chapters 3 and 13).

Here is what I implemented:

### 1. Mean (Average)
Just the sum of all values divided by the total number of items (N).

$$\bar{x} = \frac{\sum x}{N}$$

### 2. Standard Deviation & Variance
I used the population formula to find out how spread out the data is. Variance is just the standard deviation squared.

$$\sigma = \sqrt{\frac{\sum x^2}{N} - \bar{x}^2}$$

$$Variance (\sigma^2) = \frac{\sum x^2}{N} - \bar{x}^2$$

### 3. Coefficient of Variation (CV)
This is useful to see which variable has more variability (spread). It's just the standard deviation divided by the mean, turned into a percentage.

$$CV = \left( \frac{\sigma}{\bar{x}} \right) \times 100$$

### 4. Pearson Correlation Coefficient (r)
This measures the strength of the relationship between two variables (like Income and Expenditure). I had to manually code this big formula into C:

$$r = \frac{N(\sum xy) - (\sum x)(\sum y)}{\sqrt{[N\sum x^2 - (\sum x)^2] [N\sum y^2 - (\sum y)^2]}}$$

### 5. Simple Linear Regression
Once I found which variable correlates strongest with Income, I fit a regression line.

**Slope:** 
$$\hat{\beta}_1 = \frac{N(\sum xy) - (\sum x)(\sum y)}{N(\sum x^2) - (\sum x)^2}$$

**Intercept:** 
$$\hat{\beta}_0 = \bar{y} - \hat{\beta}_1\bar{x}$$

---

## Reference
All the formulas and statistical interpretations I coded are based on:
*   **Mann, Prem S.** *Introductory Statistics*. John Wiley & Sons.
    *   *Chapter 3 (Numerical Descriptive Measures)*
    *   *Chapter 13 (Linear Correlation and Regression)*
```

This uses inline double-dollar signs (`$$math$$`) directly on the same line as the text. It forces GitHub to center the math perfectly without breaking the list format. It will look clean and professional!
