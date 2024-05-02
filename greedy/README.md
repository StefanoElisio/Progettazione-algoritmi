# Algoritmi greedy

3 problemi diversi

## interval scheduling

### problema:
- ci sono *n* lavori indicizzati, e ogni lavoro *i* ha un tempo di inizio *s(i)* e uno di completamento *e(i)* > *s(i)*
- due lavori *i,j* sono compatibili se *[s(i),e(i)]* e *[s(j),e(j)]* sono disgiunti
- restituire il subset di lavori compatibili 

### complessità computazionale
interval_scheduling = O(n log.n)

## interval partitioning

### problema:
- ci sono *n* lavori indicizzati, e ogni lavoro *i* ha un tempo di inizio *s(i)* e uno di completamento *e(i)* > *s(i)*
- due lavori *i,j* sono compatibili se *[s(i),e(i)]* e *[s(j),e(j)]* sono disgiunti
- abbiamo *k* processori, ogni processore può solo processare lavori compatibili
- restituire il minimo numero di processori necessari per eseguire tutti i lavori

### complessità computazionale
interval_partitioning = O(n log.n)

## minimazing lateness

### problema:
- ci sono *n* lavori indicizzati, e ogni lavoro *i* ha una lunghezza *t(i)* e una deadline *d(i)*
- potendo eseguire solo un lavoro per volta, definiamo *li* la latenza di un lavoro *i*
- se un lavoro *i* finisce in tempo *f(i)* < *d(i)* allora *li*=0 altrimenti *li*= *f(i)* - *d(i)*
- minimizzare la massima latenza

### complessità computazionale
minimazing_lateness = O(n log.n)
 
