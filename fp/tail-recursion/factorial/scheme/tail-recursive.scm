; Tail recursive factorial
(define factorial
  (lambda (n result)
    (if (= n 1)
        result
        (factorial (- n 1) (* n result)))))
