#include <cstdio>
#include <cstdlib>
#include <sys/mman.h>
#include <cerrno>
#include <iostream>
#include "fixer/fix.h"

uintptr_t getHexAddr(const char *addr) {
#ifndef __SO64__
    return (uintptr_t) strtoul(addr, nullptr, 16);
#else
    return (uintptr_t) strtoull(addr, nullptr, 16);
#endif
}

int main(int argc, char **argv) {
    if (argc < 3){
        puts("Illegal Argument in Fixer!");
        return -1;
    }

    std::string tempPath = argv[1];
    uintptr_t start_addr = getHexAddr(argv[2]);
    std::string outPath = argv[3];

    fix_so(tempPath.c_str(), outPath.c_str(), start_addr);
    return 0;
}