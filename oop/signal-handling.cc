
// Adapted from https://github.com/asr/CoCo.

#include <iostream>
#include <csignal>
#include <stdlib.h>

// using namespace std;

using std::cerr;
using std::cout;

void sig_handler(int signum)
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

int zero_fn()
{
  return 0;
}

int main(int argc, char* argv[])
{
  signal(SIGABRT, sig_handler);
  signal(SIGFPE,  sig_handler);
  signal(SIGINT,  sig_handler);
  signal(SIGTERM, sig_handler);

  if (argc < 2)
    {
      cerr << "Error: Missing signal\n";
      return 1;
    }

  if (std::string (argv[1]) == "SIGABRT")
    abort();
  else if (std::string (argv[1]) == "SIGFPE")
    cout << 4 / zero_fn();
  else if (std::string (argv[1]) == "SIGINT")
    /* Use CTRL-c for interrupting the execution. */
    while (1);
  else if (std::string (argv[1]) ==  "SIGTERM")
    /* Use `kill pid` for interrupting the execution. */
    while (1);
  else
    {
      cerr << "Error: Bad signal name\n";
      return 1;
    }
}
