# CMake generated Testfile for 
# Source directory: /home/primarch21/Calculator/rpn_calculator/tests
# Build directory: /home/primarch21/Calculator/rpn_calculator/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[rpn_tests]=] "/home/primarch21/Calculator/rpn_calculator/build/tests/rpn_tests")
set_tests_properties([=[rpn_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/primarch21/Calculator/rpn_calculator/tests/CMakeLists.txt;20;add_test;/home/primarch21/Calculator/rpn_calculator/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
