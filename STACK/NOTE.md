# ĐÂY LÀ NOTE TÌM ĐƯỢC TRÊN MẠNG CÓ NÓI VỀ ỨNG DỤNG CỦA STACK
## Ở PHẦN CUỐI CÓ ĐỀ CẬP ỨNG DỤNG STACK ĐỂ CHUYỂN BIỂU THỨC TRUNG TỐ THÀNH BIỂU THỨC HẬU TỐ


 ## Lecture 11
-----------------------------------------------------------------------------------------------------
    Applications using Stacks
    Postfix Notation
    Converting from Infix to Prefix by Hand
    Implementing Postfix Notation With a Stack
    Implementing Infix Notation With Stacks
    Converting from Infix to Postfix Using a Stack
    Prefix Notation
_____________________________________________________________________________________________________
### Applications using Stacks
-----------------------------------------------------------------------------------------------------
To help you to gain a clear understanding of how stacks work, we'll apply stacks to the pursuit of evaluating arithmetic expressions.

I'm sure that the following expression looks familiar to you.

2 + 2

The style used to write this expression (two, then plus, then two) is called infix notation, and it's the style most commonly seen in arithmetic. But there are other ways of writing arithmetic expressions.

You probably know that the 2's are operands, and that the + is the operator associated with the operands. The plus operates on the 2's.  Infix notation order is "operand operator operand" for all binary operators (e.g., + - * /).

But have you ever seen the same expression written this way?

2 2 +

maybe on a calculator display?

This is called postfix notation, because the operator comes after its operands.
_____________________________________________________________________________________________________

##### Postfix Notation
-----------------------------------------------------------------------------------------------------
When expressions get more complicated, parentheses come into play. For instance, take the expression

(3 + 6) * (2 - 4) + 7.

Remember the order of operations that you learned as a child in arithmetic?

You evaluate 3+6 and 2-4 first.
After you get 9 and -2, respectively, you multiply those together to get -18.
Finally, by adding 7, you achieve a final result of -11.

Postfix notation, on the other hand, looks like this:

2 4 +.

Now, instead of having "operand operator operand", you have "operand operand operator".

The "post" in postfix means that the operator comes after its operand(s).

Look at the infix expression.

(4 + 5) * 3 - 7

A quick infix evaluation will lead you to a result of 20.

In postfix notation, this expression would be

4 5 + 3 * 7 -

You know how to evaluate an infix expression, probably in your sleep. But do you know how to evaluate that same expression if it's in postfix notation? Here's how.

Work through the postfix expression from left to right. Every time you encounter an operator, evaluate the two operands that came before it. Save the result of the operation on the two operands, and continue until you have evaluated the entire expression.

What's so great about postfix notation? As you can see, it eliminates all parentheses. Postfix notation is used in some applications because it saves on memory. After a few times of looking at postfix notation, it becomes easier to read.

So how do you convert an infix expression to a postfix expression?
_____________________________________________________________________________________________________


### Converting from Infix Notation to Postfix Notation by Hand
-----------------------------------------------------------------------------------------------------
Converting an expression from infix to postfix is easy.

The first thing you need to do is fully parenthesize the expression.

So, the expression

(3 + 6) * (2 - 4) + 7

becomes

(((3 + 6) * (2 - 4)) + 7).

Now, move each of the operators immediately to the right of their respective right parentheses.

If you do this, you will see that

(((3 + 6) * (2 - 4)) + 7)

becomes

3 6 + 2 4 - * 7 +

Take a close look at the arrowheads. To convert an infix expression to postfix, you simply place each operator in the infix expression immediately to the right of its respective right parenthesis. Then you rewrite the expression in the new order, and what you get is the same expression in prefix notation.

Try converting some infix expressions of your own into prefix notation. As you can see, it's easy to do.

________________________________________________________________________________________________________

### Implementing Postfix Notation With a Stack
-----------------------------------------------------------------------------------------------------
One beautiful thing about postfix notation is that it is easily implemented in programming by using a stack. Here's how to do it.

Read in one symbol at a time from the postfix expression.
Any time you see an operand, push it onto the stack.
Any time you see a binary operator (+, -, *, /) or unary (square root, negative sign) operator
,

    If the operator is binary, pop two elements off of the stack.
    If the operator is unary, pop one element off the stack.
    Evaluate those operands with that operator
    Push the result back onto the stack.

When you're done with the entire expression, the only thing left on the stack should be the final result. If there are zero or more than 1 operands left on the stack, either your program is flawed, or the expression was invalid.

Very Important:
The first element you pop off of the stack in an operation should be evaluated on the right-hand side of the operator. For multiplication and addition, order doesn't matter, but for subtraction and division, your answer will  be incorrect if you switch your operands around.

 Step through this example. By the end of it, it will be clear to you how a stack can easily evaluate a postfix expression. Here, we use a stack to evaluate the expression 4 5 + 9 * 3 + 3 /.
____________________________________________________________________________________________________

### Implementing Infix Notation With Stacks
-----------------------------------------------------------------------------------------------------

Implementing infix notation with stacks is substantially more difficult.

Now you need 3 stacks: one for the parentheses, one for the operands, and one for the operators. Just like in the conversions, you need to fully parenthesize the infix expression before attempting to evaluate it.

To evaluate an expression in infix notation:
Keep pushing elements onto their respective stacks until you reach a closed parenthesis.
When you encounter a closed parenthesis,

    Pop an operator off the operator stack
    Pop the appropriate number of operands off the operand stack to perform the operation.
    Once again, you want to push the result back onto the operand stack.

As you can see, this is much more complicated than using a stack to evaluate a postfix expression.
____________________________________________________________________________________________________
 
### Converting Infix to Postfix Using a Stack
-----------------------------------------------------------------------------------------------------
Now we'll tackle the task of converting an infix expression to a postfix expression using a single stack. This approach will work with any infix expression - fully parenthesized or not. The results are suitable for evaluation using a single stack.

Here's the big picture:

    It is important to observe that operands never move. They appear in the same order in infix and postfix expressions. When we encounter an operand, we will immediately output it.
    Operators will always be pushed onto the stack. This is because operators always appear later in a post-fix expression than they do in the infix expression. This is because they appear before the second operand in infix, but after the second operand in postfix.
    ( are always stacked, since they must be paired with the corresponding ).
    ) force the popping of the stack, up to and including the (
    We pop operators from the stack when we they have a higher precedence than an operator just read from the input.

But this leaves many holes. How do we determine the precedence of an operator on input?

Well, "Please excuse my dear Aunt Sally."

    ()'s must be the highest
    * and / should be equal, below (), and above + and -
    + and - should be equal, and below * and /

But what if the expression is not fully parenthesized? Then we must give precedence to the operations on the left. This can be accomplished by giving operations on the stack a higher precedence than the same class of operation in the input, without changing its relationship to operations of a different class.

Parentheses are a special case. Since a ) parenthesis should force the stack to be popped until the (, it should have a lower precedence than anything else and it will never be pushed. This may seem paradoxical given the precedence that we described, but it is the ( that has the highest precedence on input.

(should have a precedence of 0 to ensure that all of the operators that can occur within the ()'ed expression can be stacked within it.

Given this, the following precedence table is a simplest solution:

 
  	Precedence
| Operator | Stack 	| Input |
| :------: | :----: | :---: |
|    ) 	   | N/A 	  |  0    |
|    ( 	   | 0 	    |  5    |
|    +,- 	 | 2 	    |  1    |
|    *,/ 	 | 4 	    |  3    |



#### **The Algorithm**

 

    Step 0: Initialize the stack by pushing a "(" -- this serves to mark the beginning of the stack and give it an initial precedence. Append a ")" to the input to pop the initial "(" from the stack.
    Step 1: If the input is empty, go to Finished.
    Step 2: Read one token (operand, parenthesis, operator) from the input.
    Step 3: If the token is an operand, output it and goto Step 1.
    Step 4: Look up the precedence of the input token in the "Input" column of the precedence table.
    Step 5: Look up the precedence of the token on top of the stack in the "Stack" column of the precedence table.
    Step 6: If the precedence of the top of the stack is greater than or equal to the precedence of the input, first pop the token off the top of the stack. If it is not a "(", output it. Either way, go to Step 5. Otherwise, if the precedence of the top of the stack is less than the precedence of the input, then if the input token is not a ")", push it onto the stack
    Step 7: Go to Step 1.
    Finished.

```
Infix to Postfix Example: 5*(4-2+2)-6/3

Action: Initialize
Input: 5 * (4 - 2 + 2) - 6 / 3 )
Output: <empty>
Stack: (
 

Action: Read 5, output 5
Input: * (4 - 2 + 2) - 6 / 3 )
Output: 5
Stack: (
 

Action: Read *, push *
Input precedence: * = 3
Stack precedence: ( = 0
Input: (4 - 2 + 2) - 6 / 3 )
Output: 5
Stack: ( *
 

Action: Read (, push (
Input precedence: ( = 5
Stack precedence: * = 4
Input: 4 - 2 + 2) - 6 / 3 )
Output: 5
Stack: ( * (
 

Action: Read 4, output 4
Input: - 2 + 2) - 6 / 3 )
Output: 5 4
Stack: ( * (
 

Action: Read -, push -
Input precedence: - = 1
Stack precedence: ( = 0
Input: 2 + 2) - 6 / 3 )
Output: 5
Stack: ( * ( -
 

Action: Read 2, output 2
Input: + 2) - 6 / 3 )
Output: 5 4 2
Stack: ( * (
 

Action: Read +, pop -, output -
Input precedence: + = 1
Stack precedence: - = 2
Input: 2 ) - 6 / 3 )
Output: 5 4 2 -
Stack: ( * (
 

Action: push +

Input precedence: + = 1
Stack precedence: ( = 0
Input: 2 ) - 6 / 3 )
Output: 5 4 2 -
Stack: ( * ( +
 

Action: Read 2, output 2
Input: ) - 6 / 3 )
Output: 5 4 2 - 2
Stack: ( * ( +
 

Action: Read ), pop +, output +
Input precedence: ) = 0
Stack precedence: + = 2
Input: - 6 / 3 )
Output: 5 4 2 - 2 +
Stack: ( * (
 

Action: Pop (
Input precedence: ) = 0
Stack precedence: ( = 0
Input: - 6 / 3 )
Output: 5 4 2 - 2 +
Stack: ( *
 

Action: Read -, pop *, output *, push -
Input precedence: - = 1
Stack precedence: * = 4
Input: 6 / 3 )
Output: 5 4 2 - 2 + *
Stack: ( -
 

Action: Read 6, output 6
Input: / 3 )
Output: 5 4 2 - 2 + * 6
Stack: ( -
 

Action: Read /, push /
Input precedence: / = 3
Stack precedence: - = 2
Input: 3 )
Output: 5 4 2 - 2 + * 6
Stack: ( - /
 

Action: Read 3, output 3
Input: )
Output: 5 4 2 - 2 + * 6 3
Stack: ( - /
 

Action: Read ), pop /, output /
Input precedence: ) = 0
Stack precedence: / = 4
Input: <empty>
Output: 5 4 2 - 2 + * 6 /
Stack: ( -
 

Action: pop -, output -
Input precedence: ) = 0
Stack precedence: - = 2
Input: <empty>
Output: 5 4 2 - 2 + * 6 / -
Stack: (
 

Action: pop )
Input precedence: ) = 0
Stack precedence: ( = 0
Input: <empty>
Output: 5 4 2 - 2 + * 6 / -
Stack: <empty>
 

The stack is empty.
The input is empty.
We've terminated in a normal way; the output is the input expresses as a postfix expression.
```
___________________________________________________________________________________________________

### Prefix Notation
-----------------------------------------------------------------------------------------------------
Prefix notation is just the opposite of postfix; the operators go before the operands. So, to convert to prefix, all you do is once again fully parenthesize the infix expression, and then move all of the operators to the immediate left of the left parentheses.
_____________________________________________________________________________________________________________
//NGUỒN:https://www.andrew.cmu.edu/course/15-200/s06/applications/ln/junk.html
