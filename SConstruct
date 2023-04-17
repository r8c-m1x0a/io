# -*- python -*-

import os

PROGRAM='io'

skip = os.environ.get('SKIP')
if skip is None:
    skip = []
else:
    skip = skip.split()

commonEnv = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    CPPPATH=["src"],
)

env = commonEnv.Clone(
    AS='m32c-elf-as',
    CC='m32c-elf-gcc',
    CXX='m32c-elf-g++',
    CFLAGS='-std=c99',
    CXXFLAGS='-std=c++17',
    CPPFLAGS='-Wall -Werror -Wno-unused-variable -fno-exceptions -Os -mcpu=r8c',
)
env.VariantDir("build", "src", duplicate=0)

testEnv = commonEnv.Clone(
    LIBS=['pthread', 'libgtest', 'gcov'],
    CPPFLAGS='-coverage',
)
testEnv.VariantDir("build/test", "src/test", duplicate=0)

lib = env.Library(
    f"{PROGRAM}.a", [
        "build/r8c-m1xa-io.cpp",
    ],
)
env.Alias("compile", lib)

testProg = testEnv.Program(
    f"build/test/{PROGRAM}", Glob("build/test/*.cpp")
)

TEST_ONLY = os.getenv('TEST_ONLY')
test = testEnv.Command(
    f"build/test/{PROGRAM}.log", testProg,
    f"build/test/{PROGRAM} " + ("" if TEST_ONLY is None else f"--gtest_filter={TEST_ONLY}") + f" | tee build/test/{PROGRAM}.log"
)

coverage = testEnv.Command(
    "build/test/coverage.info",
    Glob("build/test/*.gcda"),
    "lcov -c -d build/test -o build/test/coverage.info"
)

coverage_html = testEnv.Command(
    "coverage",
    "build/test/coverage.info",
    "genhtml build/test/coverage.info  -o coverage"
)

Depends(coverage_html, coverage)
Depends(coverage, test)
testEnv.Clean(test, ["coverage", "build/test"])

docs = testEnv.Command("html", [], "doxygen Doxyfile")
testEnv.Clean(docs, "html")

if "test" in skip:
    Alias("test", [])
else:
    Alias("test", [coverage_html])

if "docs" in skip:
    Alias("docs", [])
else:
    Alias("docs", docs)

Default(lib)
