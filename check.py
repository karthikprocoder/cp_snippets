#!/usr/bin/env python3
from time import time
import os
from sys import stdout, argv
from colorama import init, Fore;
import re

# compile
comp = 'g++ ' + argv[1] + ' -Iinc/ -std=c++20 -Wall -fsanitize=undefined -o bin/a'
os.system(comp)

init()
 
start=time()
 
os.system("./bin/a > output.out")
 
end=time()
 

DIFF=os.system('diff expected_output.out output.out  -w --strip-trailing-cr -B -y')

if DIFF==0:
    stdout.write(f"\n{Fore.GREEN}Passed!!{Fore.RESET}\n\n")
else:
    stdout.write(f"\n{Fore.RED}WA{Fore.RESET}\n\n")
 
print("Time:", round((end-start)*1000), "ms\n")
 