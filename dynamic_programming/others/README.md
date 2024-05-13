# Altri problemi di programmazione dinamica

## Edit distance
- problema:
  - date due stringhe S=s1s2s3....sn e T=t1t2t3...tm
  - ritornare la distanza di modifica tra le due
    - dove la distanza di modifica rapprensenta il numero di modifiche necessarie per passare da S a T
- Modifiche:
  - inserire: inserisco carattere in una posizione di S
  - eliminare: rimuovo un carattere in S
  - sostituire: scambio un carattere in S con un'altro carattere
### complessità computazionale
no_path = O(n*m)

