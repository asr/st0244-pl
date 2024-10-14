" Toy home-finance accounting system based on the Smalltalk tutorial "
" (https://www.gnu.org/software/smalltalk/manual/html_node/Tutorial.html). "

"For using with gst:"

" $ gst "
" st> FileStream fileIn: 'tutorial.st' "

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" `Account` class. "

" 6.4.1 Creating a new class "

Object subclass: Account [
  | balance |
  <comment: 'I represent a place to deposit and withdraw money'>
]

" 6.4.3 Defining a method for the class "

" 'Account class' means that we are defining messages which are to be
sent to the Account class itself. "

Account class extend [
  new [
    | r |
    <category: 'instance creation'>
    r := super new.
    r init.
    ^r
  ]
]

" 6.4.4 Defining an instance method "

" It looks quite a bit like the previous method definition, except that "
" the first one said 'Account class extend', and ours says 'Account "
" extend'. "

" The difference is that the first one defined a method for messages "
" sent directly to 'Account', but the second one is for messages which are "
" sent to Account objects once they are created. "

Account extend [
  init [
    <category: 'initialization'>
    balance := 0
  ]
]

Account extend [
  printOn: stream [
    <category: 'printing'>
    super printOn: stream.
    stream nextPutAll: ' with balance: '.
    balance printOn: stream.
  ]
]

" 6.4.6 Moving money around "

Account extend [
  spend: amount [
    <category: 'moving money'>
    balance := balance - amount
  ]

  deposit: amount [
    <category: 'moving money'>
    balance := balance + amount
  ]
]

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" `Saving` subclass. "

" 6.5.2 The Checking class and 6.5.3 Writing checks "

Account subclass: Savings [
  | interest |

  init [
    <category: 'initialization'>
    interest := 0.
    ^super init
  ]

  interest: amount [
    interest := interest + amount.
    self deposit: amount
  ]

  clearInterest [
    | oldinterest |
    oldinterest := interest.
    interest := 0.
    ^oldinterest
  ]
]

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" `Checking` subclass. "

Account subclass: Checking [
  | checknum checksleft |

  init [
    <category: 'initialization'>
    checksleft := 0.
    ^super init
  ]

  newChecks: number count: checkcount [
    <category: 'spending'>
    checknum := number.
    checksleft := checkcount
  ]

  writeCheck: amount [
    <category: 'spending'>
    | num |
    num := checknum.
    checknum := checknum + 1.
    checksleft := checksleft - 1.
    self spend: amount.
    ^ num
  ]
]

" 6.6.1 Conditions and decision making "

Checking extend [
  writeCheck: amount [
    | num |

    (checksleft < 1)
      ifTrue: [ ^self error: 'Out of checks' ].
    num := checknum.
    checknum := checknum + 1.
    checksleft := checksleft - 1.
    self spend: amount.
    ^ num
  ]
]

Checking extend [
  | history |

  init [
    <category: 'initialization'>
    checksleft := 0.
    history := Dictionary new.
    ^ super init
  ]

  writeCheck: amount [
    <category: 'spending'>
    | num |

    "Sanity check that we have checks left in our checkbook"
    (checksleft < 1)
      ifTrue: [ ^self error: 'Out of checks' ].

    "Make sure we've never used this check number before"
    num := checknum.
    (history includesKey: num)
      ifTrue: [ ^self error: 'Duplicate check number' ].

    "Record the check number and amount"
    history at: num put: amount.

    "Update our next checknumber, checks left, and balance"
    checknum := checknum + 1.
    checksleft := checksleft - 1.
    self spend: amount.
    ^ num
  ]

  printOn: stream [
    super printOn: stream.
    ', checks left: ' printOn: stream.
    checksleft printOn: stream.
    ', checks written: ' printOn: stream.
    (history size) printOn: stream.
  ]

  " check: num [ "
  "   | c | "
  "   c := history "
  "          at: num "
  "          ifAbsent: [ ^self error: 'No such check #' ]. "
  "   ^c "
  " ] "

  printChecks [
    history keysAndValuesDo: [ :key :value |
      key print.
      ' - ' print.
      value printNl.
    ]
  ]
]
