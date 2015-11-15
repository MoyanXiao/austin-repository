#!/bin/sh

set -e

if [ ! -z "$@" ]; then
    for argument in "$@"; do
        case $argument in
            # make curl silent
            "-s")
            curlopts="-s"
            ;;
    esac
done
fi

cd ${ROOT}
ROOT=`pwd`

if test ! -f build/common.make; then
    cat >&2 << __EOF__
directory error
__EOF__
    exit 1
fi


# Check that gmock is present.  Usually it is already there since the
# directory is set up as an SVN external.
if test ! -e google/include/gtest/gtest.h; then
    mkdir -p google/lib/ 
    mkdir tmp && cd tmp
    echo "Google Test not present.  Fetching googletest from the web..."
    curl $curlopts -O https://codeload.github.com/google/googletest/zip/master
    unzip -q master && rm master && mv googletest-master googletest
    cd googletest/googletest/make && make gtest.a && make gtest_main.a
    cp *.a ${ROOT}/google/lib/ && cd .. &&  cp -r include ${ROOT}/google/
    cd ../googlemock/make/ && make -e GTEST_DIR=../../googletest/
    cp -r *.a ${ROOT}/google/lib/ && cd .. &&  cp -r include ${ROOT}/google/
    cd ${ROOT} && rm -rf tmp
fi

set -ex

exit 0
