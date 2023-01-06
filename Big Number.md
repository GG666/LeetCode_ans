# Big Number

There are many big number questions. Unfortunately, C/C++ can handel numbers as large as 2^64^-1, so how do we deal with the problems with the number much big than it?

## Case : The problem ask to return the answer after mod

### Fermat's little theorem

![](https://i.imgur.com/1m86sik.png)

If a is not a multiplicative numbers of p, the theorem can be write as follows:

![](https://i.imgur.com/KA1RmX1.png)

Therefore, when we want to calculate n!(n factorial) mod p, we can use this theorem.

(x!)^p-1^ = 1(mod p) => (x!) * (x!)^p-2^ = 1(mod p)
Thus, we find the inverse element under the mod p operation.

If we want to calculate the x!/(a!)(b!)...
We can count the inverse of a!, b!, ... , one by one.


Or we can do it faster by using the property of mod.

### Speed up the calculate
![](https://i.imgur.com/i19kQcJ.png)
<[*reference*](https://ithelp.ithome.com.tw/articles/10205906)>

Consider the following equation:

**X! × Inv(X!) equivalence to 1(mod p)**

We can first count the Inverse of X! by Fermat's little theorem, then we get:

**Inv(X!) = X^p-2^**

Then we consider the following equation:

**(X-1)! × X × (X!)^p-2^ = (X!)^p-1^ = 1(mod p)**

There we found the Inv((X-1)!) equals to X × Inv(X!). Which means that we can calculate the inverse by multiply the large ones and its inverse.

```C++
long fact[100001];

const int speedup = []{
    long last = fact[0] = 1;
    for (int i = 1; i != 100001; ++i)
        fact[i] = last = i * last % mod;
    ifact[100000] = last = fastPow(last, mod - 2);
    for (int i = 100000; i; --i)
        ifact[i - 1] = last = i * last % mod;
    return 0;
}();
```

<note> Equality is stronger than congruence.
