#!/usr/bin/env  python3

import sys
import math

from functions import groundhog

def usage():
    print("SYNOPSIS")
    print("    ./groundhog period\n")
    print("DESCRIPTION")
    print("    period        the number of days defining a period")

def main():
    if (len(sys.argv) != 2):
        return (84)
    if (sys.argv[1] == "-h"):
        usage()
        return (0)
    groundhog(int(sys.argv[1]))



res = main()
exit(res)