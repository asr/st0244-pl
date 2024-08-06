
;; composition
(define (comp f g)
  (lambda (x) (f (g x))))

;; map
(define (my-map f xs)
  (if (null? xs)
      '()
      (cons (f (car xs)) (my-map f (cdr xs)))))
