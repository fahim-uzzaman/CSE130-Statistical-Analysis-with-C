markdown
# CSE330-Statistical-Analysis-with-C

I used C to implement mean, variance, correlation, regression and other statistical measures from scratch. This project demonstrates what I learned in AST 101 (Introduction to Applied Statistics and Data Science) by calculating the mathematical formulas manually, without relying on built-in statistics libraries. 

The program reads a CSV file containing data for 50 ISRT alumni (Income, Expenditure, and Savings) and calculates the required metrics.

## How to Run
1. Compile the code (make sure to link the math library):
   ```bash
   gcc main.c -o stats_program -lm
Run the program:

bash
./stats_program
Enter 1 for Odd roll number data, or 2 for Even.

(I included the inc2_data1.csv and inc2_data2.csv files in the repo so it runs immediately).

The Math Used (From Scratch)
Since I couldn't use built-in statistics functions, I had to code the actual math formulas into the C file. The formulas are based on the concepts from Introductory Statistics by Prem S. Mann (Chapters 3 and 13).

Here is what I implemented:

1. Mean (Average)
Just the sum of all values divided by the total number of items (N).

x
ˉ
=
∑
x
N
x
ˉ
 = 
N
∑x
​
 
2. Standard Deviation & Variance
I used the population formula to find out how spread out the data is. Variance is just the standard deviation squared.

σ
=
∑
x
2
N
−
x
ˉ
2
σ= 
N
∑x 
2
 
​
 − 
x
ˉ
  
2
 
​
 
V
a
r
i
a
n
c
e
(
σ
2
)
=
∑
x
2
N
−
x
ˉ
2
Variance(σ 
2
 )= 
N
∑x 
2
 
​
 − 
x
ˉ
  
2
 
3. Coefficient of Variation (CV)
This is useful to see which variable has more variability (spread). It's just the standard deviation divided by the mean, turned into a percentage.

C
V
=
(
σ
x
ˉ
)
×
100
CV=( 
x
ˉ
 
σ
​
 )×100
4. Pearson Correlation Coefficient (r)
This measures the strength of the relationship between two variables (like Income and Expenditure). I had to manually code this big formula into C:

r
=
N
(
∑
x
y
)
−
(
∑
x
)
(
∑
y
)
[
N
∑
x
2
−
(
∑
x
)
2
]
[
N
∑
y
2
−
(
∑
y
)
2
]
r= 
[N∑x 
2
 −(∑x) 
2
 ][N∑y 
2
 −(∑y) 
2
 ]
​
 
N(∑xy)−(∑x)(∑y)
​
 
5. Simple Linear Regression
Once I found which variable correlates strongest with Income, I fit a regression line.

Slope:

β
^
1
=
N
(
∑
x
y
)
−
(
∑
x
)
(
∑
y
)
N
(
∑
x
2
)
−
(
∑
x
)
2
β
^
​
  
1
​
 = 
N(∑x 
2
 )−(∑x) 
2
 
N(∑xy)−(∑x)(∑y)
​
 
Intercept:

β
^
0
=
y
ˉ
−
β
^
1
x
ˉ
β
^
​
  
0
​
 = 
y
ˉ
​
 − 
β
^
​
  
1
​
  
x
ˉ
 
Reference
All the formulas and statistical interpretations I coded are based on:

Mann, Prem S. Introductory Statistics. John Wiley & Sons.

Chapter 3 (Numerical Descriptive Measures)

Chapter 13 (Linear Correlation and Regression)

text
