(define (my-unless pred true-block false-block)
	(if pred false-block true-block))

;(my-unless (< 3 2)
;	(display "3 is greater than 2\n")
;  	(display "3 is less than 2\n")

(define-syntax right-unless
	      (syntax-rules ()
		((right-unless pred true-block false-block)
		 (if pred false-block true-block))))

(right-unless (< 3 2)
	      (display "3 is greater than 2\n")
	      (display "3 is less then 2\n")

(define-syntax for
  (syntax-rules (in)
    ((for var in lst block ...)
     	(letrec ((body (lambda (l)
			 (cond (null? l) '())
			 	(else 
				  (let (var (car l)))
				  	(begin block ...)
					(body (cdr l))))))
	  (body lst)))))

(for i in (iota 10)
     (display (* i i))
     (newline)







