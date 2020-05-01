all: opt naive

opt: converter_opt.cc driver.cc
	gcc -O3 -std=c++17 -o driver_opt -Werror -Wall -Wextra -pedantic converter_opt.cc driver.cc

naive: converter.cc driver.cc
	gcc -O3 -std=c++17 -march=native -o driver -Werror -Wall -Wextra -pedantic converter.cc driver.cc
