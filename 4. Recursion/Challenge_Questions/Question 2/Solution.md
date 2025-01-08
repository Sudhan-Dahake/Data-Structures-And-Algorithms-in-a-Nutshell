## Question

```
Consider the following recursive relation:

        F(n) = F(n/2) + F(n - 2)
        F(1) = 0
        F(0) = 0

(a) Draw the call tree.
(b) Write the call trace to evaluate F(8).
```

## Solution

(a) Diagram showing the above call tree.
![Diagram of a call tree](images/Call_Tree.png)

(b) Call trace to evalaute F(8).

```
F(8) = F(4) + F(6)      {This is using -> F(n) = F(n/2) + F(n - 2)}
     = {F(2) + F(2)} + {F(3) + F(4)}
     = {{F(1) + F(0)} + {F(1) + F(0)}} + {{F(1) + F(1)} + {F(2) + F(2)}}
     = {{F(1) + F(0)} + {F(1) + F(0)}} + {{F(1) + F(1)} + {{F(1) + F(0)} + {F(1) + F(0)}}}
     = 6.F(1) + 4.F(0)
     = 0 + 0
     = 0
```

# NOTE
The calculation F(3/2) = F(1) occurs because in the recursive relation F(n),
the term F(n/2) implies **integer division** (truncation of the result to an integer),
not floating-point division.