// The smallest number with a given number of divisors
// You have a natural number d.
// You need to write a function f(d) which finds the smallest positive number n having d divisors .
// f(1) = 1
// f(3) = 4
// f(60) = 5040
// f(420) = 9979200
function f(d) {
    // TODO
    // Improve speed and performance of this code 
    start = d
    let stor = {}
    function primeFactors(n) {
        const factors = {};
        const cachn = n
        // Check for 2 as a prime factor
        while (n % 2 === 0) {
            factors[2] = (factors[2] || 0) + 1;
            n /= 2;
        }
        if (factors.hasOwnProperty(2)) factors[2] += 1
        if (n < cachn) {
            if (stor.hasOwnProperty(n)) {
                stor[cachn] = [...stor[n], factors[2]]
                return stor[cachn]
            }
        }
        // Check for other prime factors starting from 3
        for (let i = 3; i <= Math.sqrt(n); i += 2) {
            if (stor.hasOwnProperty(i)) {
                stor[cachn] = [...stor[i], ...Object.values(factors)]
                return stor[cachn]
            }
            while (n % i === 0) {
                factors[i] = (factors[i] || 0) + 1;
                n /= i;
            }
            if (factors.hasOwnProperty(i)) factors[i] += 1
        }
        if (n > 2) {

            factors[n] = 2
        }
        stor[cachn] = Object.values(factors)
        return Object.values(factors);
    }

    while (true) {
        if (primeFactors(start).reduce((prev, next) => { return prev * next }, 1) == d) {
            return BigInt(start)
        }
        start++
    }
}
console.log(f(420))
//9979200n