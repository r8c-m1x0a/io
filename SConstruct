# -*- python -*-

import os

PROGRAM='r8c_io'

VariantDir('build', ['src'], duplicate=0)

env = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    AS='m32c-elf-as',
    CC='m32c-elf-gcc',
    CXX='m32c-elf-g++',
    CFLAGS='-std=gnu99',
    CXXFLAGS='-std=c++14',
    CPPFLAGS='-Wall -Werror -Wno-unused-variable -fno-exceptions -Os -mcpu=r8c',
    CPPPATH=['src'],
    LINK='m32c-elf-gcc',
    LINKFLAGS=f"-mcpu=r8c -nostartfiles -Wl,-Map,{PROGRAM}.map -T src/M120AN/m120an.ld -lsupc++",
)

testEnv = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    LIBS=['pthread', 'libgtest'],
    CPPFLAGS='-g3',
    CPPPATH=['src'],
)

lib = env.Library(
    f"{PROGRAM}.a", [
        'build/r8c-m1xa-io.cpp',
    ],
)
testProg = testEnv.Program(
    PROGRAM, [
        'build/test/test-r8c-m1xa-io.cpp',
        'build/test/test-mstrc.cpp',
        'build/test/test-ococr.cpp',
        'build/test/test-sckcr.cpp',
        'build/test/test-ckstpr.cpp',
        'build/test/test-u0mr.cpp',
        'build/test/test-u0c0.cpp',
        'build/test/test-u0c1.cpp',
        'build/test/test-u0ir.cpp',
        'build/test/test-pmh1.cpp',
        'build/test/test-pmh1e.cpp',
    ]
)

TEST_ONLY = os.getenv('TEST_ONLY')
print(f"TEST_ONLY: {TEST_ONLY}")
test = testEnv.Command(
    f"{PROGRAM}.log", testProg,
    f"./{PROGRAM} " + ("" if TEST_ONLY is None else f"--gtest_filter={TEST_ONLY}") + f" | tee {PROGRAM}.log"
)
testEnv.AlwaysBuild(test)
Alias("test", f"{PROGRAM}.log")

Default(lib)
