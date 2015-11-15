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

cd $ABS_ROOT
ABS_ROOT=`pwd`

if test ! -f build/common.make; then
    cat >&2 << __EOF__
directory error , current root: ${ABS_ROOT}
__EOF__
    exit 1
fi


# Check that benchmark is present.  Usually it is already there since the
# directory is set up as an SVN external.
if test ! -e google/include/benchmark/benchmark.h; then
    mkdir -p google/lib/ 
    mkdir tmp_bm && cd tmp_bm
    echo "Google benchmark not present.  Fetching from the web..."
    curl $curlopts -O https://codeload.github.com/google/benchmark/zip/master
    unzip -q master && rm master && mv benchmark-master benchmark &&\
        cd benchmark && cmake . && make && cp src/*.a ${ABS_ROOT}/google/lib/ && cp -r include ${ABS_ROOT}/google/ &&\
        cd ${ABS_ROOT} && rm -rf tmp_bm
fi

set -ex

exit 0
