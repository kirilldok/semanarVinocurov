(define (reverse lst)
  (define (reverse' lst rem)
	(cond ((null? lst) rem)
		  (else (reverse' (cdr lst) (cons (car lst) rem)))))
  (reverse' lst '()))


(define (reverse2 lst) 
  (let rev ((rem '())
			(l lst))
	(cond
	  ((null? l) rem)
	  (else (rev (cons (car l) rem) (cdr l)))))) 




(display (reverse '(1 2 3 4 5 6)))
(newline)
(display (reverse2 '(1 2 3 4 5 6 7)))
(newline)
