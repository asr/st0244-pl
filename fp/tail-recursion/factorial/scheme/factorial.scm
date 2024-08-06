; Non-tail recursive factorial
(define (fact-tr n)
  (if (= n 1)
      1
      (* n (fact-tr (- n 1)))))

; Tail recursive factorial
(define (fact-ntr n result)
  (if (= n 1)
      result
      (fact-ntr (- n 1) (* n result))))
