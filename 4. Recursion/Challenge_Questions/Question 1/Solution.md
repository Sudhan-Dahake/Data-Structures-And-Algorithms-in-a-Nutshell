## Question

```
True/False: Any recursion problem can be implemented sequentially?
```

## Solution

**True** - Any recursion problem can be implemented using an iterative (sequential)
approach, as recursion is fundamentally a mechanism of repeatedly solving subproblems by
maintaining a call stack, which can be mimicked using a data structure like an explicit stack or loop.

### Example:

**Recursive Approach (Factorial Calculation)**

```
int factorial(int n) {
    if (n <= 1) {
        return 1;
    };

    return n * factorial(n - 1);
};
```

**Iterative (Sequential) Approach**

```
int factorial(int n) {
    int result = 1;

    for(int i = 2; i <= n; i++) {
        result *= i;
    };

    return result;
};
```

```
Both implementations achieve the same result, but the recursive version relies on the function call stack,
while the iterative version uses a loop to eliminate the overhead of recursive calls.
```