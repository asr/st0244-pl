
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; comp: Compose two functions

;; ((comp f g) x) ⇒ g (f x)
;;
(define (comp g f)
  (lambda (x) (g (f x))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; map: Apply a function to every element of a list

;; (map f '(x1 x2 ... xn)) ⇒ ((f x1) (f x2) ... (f xn))

;; Laws:
;; (map f '())         ⇒ '()
;; (map f (cons x xs)) ⇒ (cons (f x) (map f xs))

(define (my-map f xs)
  (if (null? xs)
      '()
      (cons (f (car xs)) (my-map f (cdr xs)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; filter: Select the elements of a list that satisfy a predicate

;; Laws:
;; (filter p? '())         ⇒ '()
;; (filter p? (cons x xs)) ⇒ (cons x (filter p? xs)), if (p? x)
;; (filter p? (cons x ys)) == (filter p? xs), if (not (p? x))

(define (my-filter p? xs)
  (if (null? xs)
      '()
      (if (p? (car xs))
          (cons (car xs) (filter p? (cdr xs)))
          (filter p? (cdr xs)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; filter: Combine the elements of a list, from right to left, using a
; binary function and an initial value.

;; (foldr f z '(x1 x2 ... xn)) ⇒ (f x1 (f x2 ... (f xn z)))
;; (foldr + 0 '(1 2 3))        ⇒ (+ 1 (+ 2 (+ 3 0))) ⇒ 6

;; Laws:
;; (foldr f z '())         ⇒ z
;; (foldr f z (cons x xs)) ⇒ (f x (foldr f z xs))

(define (foldr f z xs)
  (if (null? xs)
      z
      (f (car xs) (foldr f z (cdr xs)))))
