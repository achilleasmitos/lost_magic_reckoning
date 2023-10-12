# Function Arguments

## Pass-by-pointer vs pass-by-reference

It has been an everstanding question whether we should use pointers as function arguments or we should pass by reference. After some online research, we have reached the below conclusion:

**Prefer pass-by-reference wherever possible**. This is because the main difference between the two methods is the following:
1. Pointers can be re-assigned to a new variable.
2. Pointers can point to NULL, therefore the calling function needs to check for NULL before dereferencing a passed-in pointer.

So, unless the argument falls into one of the above categories, it is generally more preferable to pass by reference.
For some more talk on the matter, you may visit the following links:
[IBM docs](https://www.ibm.com/docs/en/zos/2.5.0?topic=calls-pass-by-reference-c-only), [Stackoverflow](https://stackoverflow.com/questions/334856/are-there-benefits-of-passing-by-pointer-over-passing-by-reference-in-c), [Geeks for geeks](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-cpp/)

A bad use of pointers would be for an argument representing the main character. As it stands, the main character variable is created upon game start-up, and should stay alive throughout the runtime of our application. Thus, a pointer to it would never be NULL. Moreover, it is hard to believe that we would need to re-assign a pointer to the main character to another variable, eliminating the first case above. Therefore, it is wise to pass the main character by reference to any function that means to modify it (which is most of them).

## Use of 'const'

We have been neglecting the use of the 'const' modifier in function arguments. It is imperative that we start fixing that, for the 'const' modifier is very helpful when dealing with code that somebody else (or you a very long time ago) wrote. Knowing what variables can/cannot be modified by a certain function may actually help the understanding of that particular piece of code. It can also prevent developer mistakes, when one tries to modify a value that shouldn't be modified (but is otherwise needed for the proper functionality of the function). **Use 'const' when passing-by-reference whenever the callee function should not modify the parameter**. **In classes, mark methods as 'const' whenever the method should not modify any member variable of the class** (such as getter methods). Also, use 'const' whenever declaring a variable that isn't meant to be changed (such as lambdas). Prefer to write 'const' to the right of the type that's meant to be non-modifiable, unless that is the 'auto' type or a simple data type, as described here: [Wikipedia 'const' Syntax](https://en.wikipedia.org/wiki/Const_(computer_programming)).
