" Adapted from: "
" Kenneth C. Louden y Kenneth A. Lambert (2011). Programming "
" Languages. Principles and Practice. 3rd ed. Cengage Learning. "

"For using with gst:"

" $ gst "
" st> FileStream fileIn: 'Complex.st' "

Number subclass: Complex [
  | re im |

  Complex class >> realPart: r imaginaryPart: i [
    <category: 'creation'>
    ^self basicNew realPart: r imaginaryPart: i
  ]

  realPart: r imaginaryPart: i [
    <category: 'creation'>
    re := r.
    im := i.
    ^self
  ]

  real [
    <category: 'creation'>
    <comment: 'Answer the real part of the receiver'>
    ^re
  ]

  imaginary [
    <category: 'creation'>
    <comment: 'Answer the imaginary part of the receiver.'>
    ^im
    ]

  = z [
    <category: 'comparing'>
    ^self real = z real and: [self imaginary = z imaginary]
    ]

  + z [
    | rp ip |
    <category: 'math'>
    rp := self real + z real.
    ip := self imaginary + z imaginary.
    ^Complex realPart: rp imaginaryPart: ip
    ]

  printOn: stream [
    <category: 'printing'>
    stream
      nextPut: $(;
      print: self real;
      nextPut: $+;
      print: self imaginary;
      nextPut: $i;
      nextPut: $)
  ]
]
