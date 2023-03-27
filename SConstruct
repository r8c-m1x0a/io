# -*- python -*-

import os

PROGRAM='io'

baseEnv = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    AS='m32c-elf-as',
    CC='m32c-elf-gcc',
    CXX='m32c-elf-g++',
    CFLAGS='-std=gnu99',
    CXXFLAGS='-std=c++14',
    CPPFLAGS='-Wall -Werror -Wno-unused-variable -fno-exceptions -Os -mcpu=r8c',
    CPPPATH=['src'],
)

env = baseEnv.Clone()
env.VariantDir('build', 'src', duplicate=0)

testEnv = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    LIBS=['pthread', 'libgtest', 'gcov'],
    CPPPATH=['src'],
    CPPFLAGS='-coverage',
)
testEnv.VariantDir('build', 'src', duplicate=0)

lib = env.Library(
    f"{PROGRAM}.a", [
        'build/r8c-m1xa-io.cpp',
    ],
)

testProg = testEnv.Program(
    PROGRAM, Glob('build/test/*.cpp')
)

BASE_DIR = Dir('.').srcnode().abspath

TEST_ONLY = os.getenv('TEST_ONLY')
test = testEnv.Command(
    f"{BASE_DIR}/{PROGRAM}.log", testProg,
    f"{BASE_DIR}/{PROGRAM} " + ("" if TEST_ONLY is None else f"--gtest_filter={TEST_ONLY}") + f" | tee {BASE_DIR}/{PROGRAM}.log"
)
testEnv.AlwaysBuild(test)

coverage = testEnv.Command(
    "coverage.info",
    Glob('build/test/*.gcda'),
    "lcov -c -d build/test -o coverage.info"
)

coverage_html = testEnv.Command(
    "coverage",
    "coverage.info",
    "rm -rf html && genhtml coverage.info  -o coverage"
)
Alias("test", [test, coverage_html])

docs = testEnv.Command("html/index.html", [], "doxygen Doxyfile")
testEnv.AlwaysBuild(docs)
Alias("docs", "html/index.html")

Default(lib)
