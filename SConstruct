# -*- python -*-

import os

NAME='io'

skip = os.environ.get('SKIP')
if skip is None:
    skip = []
else:
    skip = skip.split()

commonEnv = Environment(
    ENV = {'PATH' : os.environ['PATH']},
    CPPPATH=["src/main"],
)

env = commonEnv.Clone(
    AS='m32c-elf-as',
    CC='m32c-elf-gcc',
    CXX='m32c-elf-g++',
    CFLAGS='-std=c99',
    CXXFLAGS='-std=c++17',
    CPPFLAGS='-Wall -Werror -Wno-unused-variable -fno-exceptions -Os -mcpu=r8c',
)
env.VariantDir("build/main", "src/main", duplicate=0)

testEnv = commonEnv.Clone(
    LIBS=['pthread', 'libgtest', 'gcov'],
    CPPFLAGS='-coverage',
)
testEnv.VariantDir("build/test", "src/test", duplicate=0)

lib = env.Library(
    f"build/main/{NAME}.a", [
        Glob("build/main/*.cpp"), Glob("build/main/*.c"), Glob("build/main/*.cc")
    ],
)
env.Alias("compile", lib)

testProg = testEnv.Program(
    f"build/test/{NAME}", [Glob("build/test/*.cpp"), Glob("build/test/*.c"), Glob("build/test/*.cc")]
)

TEST_ONLY = os.getenv('TEST_ONLY')
test = testEnv.Command(
    f"build/test/{NAME}.log", testProg,
    f"build/test/{NAME} " + ("" if TEST_ONLY is None else f"--gtest_filter={TEST_ONLY}") + f" | tee build/test/{NAME}.log"
)

coverage = testEnv.Command(
    "build/test/coverage.info",
    Glob("build/test/*.gcda"),
    "lcov -c -d build/test -o build/test/coverage.info && genhtml build/test/coverage.info  -o coverage"
)

Depends(coverage, test)
testEnv.Clean(test, ["coverage", "build/test"])

docs = testEnv.Command("html", [], "doxygen Doxyfile")
testEnv.Clean(docs, "html")

if "test" in skip:
    Alias("test", [])
else:
    Alias("test", [coverage])

if "docs" in skip:
    Alias("docs", [])
else:
    Alias("docs", docs)

Default(lib)
