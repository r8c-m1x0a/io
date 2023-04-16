# -*- python -*-

import os

PROGRAM='io'

skip = os.environ.get('SKIP')
if skip is None:
    skip = []
else:
    skip = skip.split()

BASE_DIR = Dir('.').srcnode().abspath

commonEnv = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    CPPPATH=[f"{BASE_DIR}/src"],
)

env = commonEnv.Clone(
    AS='m32c-elf-as',
    CC='m32c-elf-gcc',
    CXX='m32c-elf-g++',
    CFLAGS='-std=c99',
    CXXFLAGS='-std=c++17',
    CPPFLAGS='-Wall -Werror -Wno-unused-variable -fno-exceptions -Os -mcpu=r8c',
)
env.VariantDir(f"{BASE_DIR}/build", f"{BASE_DIR}/src", duplicate=0)

testEnv = commonEnv.Clone(
    LIBS=['pthread', 'libgtest', 'gcov'],
    CPPFLAGS='-coverage',
)
testEnv.VariantDir(f"{BASE_DIR}/build/test", f"{BASE_DIR}/src/test", duplicate=0)

lib = env.Library(
    f"{PROGRAM}.a", [
        f"{BASE_DIR}/build/r8c-m1xa-io.cpp",
    ],
)
env.Alias("lib", lib)

testProg = testEnv.Program(
    f"{BASE_DIR}/build/test/{PROGRAM}", Glob(f"{BASE_DIR}/build/test/*.cpp")
)

TEST_ONLY = os.getenv('TEST_ONLY')
test = testEnv.Command(
    f"{BASE_DIR}/build/test/{PROGRAM}.log", testProg,
    f"{BASE_DIR}/build/test/{PROGRAM} " + ("" if TEST_ONLY is None else f"--gtest_filter={TEST_ONLY}") + f" | tee {BASE_DIR}/build/test/{PROGRAM}.log"
)

coverage = testEnv.Command(
    f"{BASE_DIR}/build/test/coverage.info",
    Glob(f"{BASE_DIR}/build/test/*.gcda"),
    f"lcov -c -d {BASE_DIR}/build/test -o {BASE_DIR}/build/test/coverage.info"
)

coverage_html = testEnv.Command(
    f"{BASE_DIR}/coverage",
    f"{BASE_DIR}/build/test/coverage.info",
    f"genhtml {BASE_DIR}/build/test/coverage.info  -o {BASE_DIR}/coverage"
)

Depends(coverage_html, coverage)
Depends(coverage, test)
testEnv.Clean(test, [f"{BASE_DIR}/coverage", f"{BASE_DIR}/build/test"])

docs = testEnv.Command(f"{BASE_DIR}/html", [], f"doxygen {BASE_DIR}/Doxyfile")
testEnv.Clean(docs, f"{BASE_DIR}/html")

if "test" in skip:
    Alias("test", [])
else:
    Alias("test", [coverage_html])

if "docs" in skip:
    Alias("docs", [])
else:
    Alias("docs", docs)

Default(lib)
