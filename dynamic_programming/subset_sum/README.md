# Subset sum
- dato un insieme S di *n* numeri interi positivi e un target T intero positivo
- ritorna vero o falso, se esiste un sottoinsieme S' di S tale che la somma degli elementi di S' = T 
## complessità computazionale
### brute_force = ø(n*T)
  *T ≤ 2^(n/2) (OK per T piccolo)*
### split_and_list = O(n*2^(n/2))
  *T ≤ 2^(n/2) (OK per n piccolo < 50)*
