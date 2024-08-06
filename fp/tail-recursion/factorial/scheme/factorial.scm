; Non-tail recursive factorial
(define (fact-ntr n)
  (if (= n 1)
      1
      (* n (fact-ntr (- n 1)))))

; Tail recursive factorial
(define (fact-tr n result)
  (if (= n 1)
      result
      (fact-tr (- n 1) (* n result))))
