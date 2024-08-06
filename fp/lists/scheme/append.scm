;; Concatenation of lists using the primitive procedures.
(define (my-append l m)
  (if (null? l)
      m
      (cons (car l) (my-append (cdr l) m))))
