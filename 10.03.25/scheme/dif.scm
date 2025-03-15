(use-modules (ice-9 match))

(define (diff expr)
  (let ((D (lambda (e) (diff e var))))
  (match expr
	(('+ exp1 exp2) `(+ ,(D exp1) ,(D exp2)))
	(('- exp1 exp2) `(- ,(D exp1) ,(D exp2)))
	(('* exp1 exp2) `(+ (* ,(D exp1) ,exp2) (* ,(D exp2) ,exp1)))
	(('/ exp1 exp2) `(/ (- (* ,(D exp1) ,exp2) (* ,(D exp2) ,exp1)) (* ,exp2 ,exp2)))
	((? number? x) 0)
	(var 1)
	((? symbol? v) 1))))


(define (fold-const expr var)
  (let* ((F (lambda (e) (fold-const e var)))
	      (res (match expr
			  ((binop exp1 exp2) `(,binop ,(F exp1) ,(F exp2)))
			  (('- exp1) `(- ,(F exp1)))
		   	  ((? number? x) x)
			  (var var))))
	 (match res
		(('+ 0 exp1) exp1)
		(('+ exp1 0) exp1)
		(('- exp1 0) exp1)
		(('- 0 exp1) `(-, exp1))
		(('* 1 exp1) exp1)
		(('* exp1 1) exp1)
		(('/ exp1 1) exp1)
		(('* exp1 0) 0)
		(('* 0 exp1) 0)
		(x x))) )





	 







