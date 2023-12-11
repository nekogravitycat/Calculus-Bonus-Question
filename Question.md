We have three ways to define the Euler number 𝑒, as follow:

1. The number 𝑒 is the number in the domain of the natural logarithm that satisfies $\ln 𝑒 = \int_{1}^{e} \frac{1}{t} dt = 1$

2. $𝑒 = \lim_{\delta \to 0}(1+\delta)^{\frac{1}{\delta}} = \lim_{n \to \infty } (1+\frac{1}{n})^{n}$

3. $𝑒 = \sum_{n=0}^{\infty}\frac{1}{n!}$

Is it possible to write codes to compute the number 𝑒 based on the above definitions? Which definition provides the most efficient approach to approximate the number 𝑒? In your answer, you should make sure the following:

- You need to submit the codes and the corresponding result.

- Your code for each should be based on an iterative algorithm. That is, your code should consist of a loop procedure and usually it needs the result of 𝑛 − 1 or the result less than or equal to 𝑛 − 1 to obtain the result of 𝑛.

- You may include the part to tell which code provides the most efficient approximation, in terms of the number of iterations or time.

- In each of the iteration, you may need to specify the stopping criteria such as when you believe the precision is good enough and you should terminate the loop.

Please write the code in C++.
