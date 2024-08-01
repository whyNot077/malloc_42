#!/bin/bash

set -e
mkdir -p trace

export log=1 && export log_detail=1 && make fclean && make bonus \
&& gcc -o tmp/test0 test/test.c -L. -lft_malloc_x86_64_Darwin_bonus -lpthread \
&& gcc -o tmp/test1 test/test1.c -L. -lft_malloc_x86_64_Darwin_bonus -lpthread \
&& gcc -o tmp/test2 test/test2.c -L. -lft_malloc_x86_64_Darwin_bonus -lpthread \
&& gcc -o tmp/test3 test/test3.c -L. -lft_malloc_x86_64_Darwin_bonus -lpthread \
&& echo "Bonus build successful." \
&& ./tmp/test0 > trace/test_bonus_0.log \
&& ./tmp/test1 > trace/test_bonus_1.log \
&& ./tmp/test2 > trace/test_bonus_2.log \
&& ./tmp/test3 > trace/test_bonus_3.log