"Create the temporal variable `array` which is an array of 5 positions
and run a sequence of 5 replacements."

| array |
array := Array new: 5.
array at: 1 put: 10.
array at: 2 put: 20.
array at: 3 put: 30.
array at: 4 put: 40.
array at: 5 put: 50.
array printNl.

"Create the temporal variable `array` which is an array of 5 positions
and run a sequence of 5 replacements in cascade."

| array |
array := Array new: 5.
array at: 1 put: 10;
      at: 2 put: 20;
      at: 3 put: 30;
      at: 4 put: 40;
      at: 5 put: 50.

array printNl.
