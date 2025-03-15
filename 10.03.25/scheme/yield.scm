(define (produceer n)
  (if (> n 0)
    (begin (yield!  n) (producer (- n 1)))))


(define (consumer prod)
  (for x in (prod 10)
       (yeild (* x x))))


(display (call/cc (lambda (yield)
		    (let lp ((n 10))
		      (if (> n 0) (begin (yield n)
					 (lp (- n 1))))))))



