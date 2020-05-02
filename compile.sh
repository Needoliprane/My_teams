#!/bin/bash

gcc -Wall -Wextra -Werror source_client/*.c lib/*.c -Iinclude -o client
gcc -Wall -Wextra -Werror source_server/*.c lib/*.c -Iinclude -o server