
// Adapted from https://github.com/asr/CoCo.

#include <iostream>
#include <csignal>
#include <stdlib.h>

using namespace std;

void
sigHandler (int signum)
{
  cerr << "Signal received: ";

  switch (signum)
    {
    case SIGABRT:
      cerr << "Program execution aborted\n";
      break;

    case SIGFPE:
      cerr << "Fatal arithmetic error\n";
      break;

    case SIGINT:
      cerr << "Program interrupted (INT character)\n";
      break;

    case SIGTERM:
      cerr << "Termination requested\n";
      break;
    }
  exit(0);
}

int
zero_fn ()
{
  return 0;
}

int
main (int argc, char* argv[])
{
  signal(SIGABRT, sigHandler);
  signal(SIGFPE,  sigHandler);
  signal(SIGINT,  sigHandler);
  signal(SIGTERM, sigHandler);

  if (argc < 2)
    {
      cerr << "error: missing signal\n";
      return 1;
    }

  if (string (argv[1]) == "SIGABRT")
    abort ();
  else if (string (argv[1]) == "SIGFPE")
    cout << 4 / zero_fn ();
  else if (string (argv[1]) == "SIGINT")
    /* Use CTRL-c for interrupting the execution. */
    while(1);
  else if (string (argv[1]) ==  "SIGTERM")
    /* Use `kill pid` for interrupting the execution. */
    while(1);
  else
    {
      cerr << "error: bad signal name\n";
      return 1;
    }
}
