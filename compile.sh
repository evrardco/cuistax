#!/bin/bash
build_folder="build"
cmake_args="-DCMAKE_EXPORT_COMPILE_COMMANDS=true -DCMAKE_BUILD_TYPE=RelWithDebInfo"
cxx_args="-g"
do_sanitize="false"
do_build="false"
while getopts "rcvlbs" opt; do
    case $opt in
      r)
        do_reset=true
        ;;
      c)
        do_configure=true
        ;;
      v)
        cmake_args+=" -DCMAKE_VERBOSE_MAKEFILE=ON"
        ;;
      l)
        cmake_args+=" -DLOG_LEVEL=4"
        ;;
      b)
        do_build="true"
        ;;
      s)
        do_sanitize="true"
        cxx_args+=" -fsanitize=address"
        ;;
      *)
        echo "invalid parameter: $opt"
        ;;
    esac
done
if [ -n "$do_reset" ]; then
    rm -rf "$build_folder"
    echo "Deleted build folder"
fi
if [ ! -d "$build_folder" ]; then
  mkdir "$build_folder"
  if [ -n "$do_configure" ]; then
    cd "$build_folder"
    CXXFLAGS="$cxx_args" cmake $cmake_args ..
    cp compile_commands.json ..
    cd ..
  fi
fi
if [ "$do_build" = "true" ]; then
  cd "$build_folder"
  make -j
fi

