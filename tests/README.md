# Module Header Tests
This directory can be used to add tests for existing module header files. The files in this directory provide the resources to run the tests with the corresponding workflow in Github Actions ([run-header-tests-Debug][header-tests-debug] and [run-header-tests-Release][header-tests-release]). The release workflow is run automatically for pull requests to the main branch. The debug workflow can be used by developers on their respective branches for testing in between.

## Adding Tests for a New Module
To add tests for another module, a few files need to be added and altered. This description assumes that the module's header files (fmi3LsBus<MODULE>.h and fmi3LsBusUtil<MODULE>.h) have already been added.

### Add Test Code
The files containing the test definitions according to gtest are added in the subdirectory [tests/test][test-folder]. Each module has one file with all tests. The naming convention for files in this directory is 'fmi_3_ls_bus_header_tests_<MODULE>.cpp' with a lowercase module name (e.g. 'fmi_3_ls_bus_header_tests_can.cpp'). **The naming convention needs to be followed in order for the tests to run.**

### Add Helper Files
It is possible to add helper code for the tests in order to reduce complexity and line count in the main test code. Such files can be added to the subdirectory [tests/helper][helper-folder]. Each module can have one helper code-file (added to subdirectory 'src') and one helper header-file (added to subdirectory 'hdr'). The naming convention for files in these directories is 'fmi_3_ls_bus_header_test_helper_<MODULE>.\[cpp/h\]' with a lowercase module name (e.g. 'fmi_3_ls_bus_header_test-helper_can.\[cpp/h\]'). **The naming convention needs to be followed in order for the tests to run.**

### Add Module as Option in Workflow
The workflow ([run-header-tests][header-tests]) provides the possibility to choose a subset of available modules to run tests for. In file [run-header-tests.yml][header-tests-file], the module name needs to be added to the input description in line 9 by separating it from the prior module with a semicolon. It is important that the name is added **without blankspaces** in order for the workflow to run succesfully (**Correct**: 'can;lin' **Wrong**: 'can; lin'). Also make sure that the module names are written in lowercase.

### Add Module to List in Makefile
When the tests are run for all available modules, the list of modules does not need to be entered manually. Thus, the makefile fills the list with all available modules. In the [makefile][makefile], the new module name needs to be added in line 5. **It is important that the seperate modules are listed with a blank space inbetween and without quotation marks for the workflow to work correctly**.

[header-tests]: https://github.com/modelica/fmi-ls-bus/actions/workflows/run-header-tests.yml
[header-tests-file]: https://github.com/modelica/fmi-ls-bus/tree/main/.github/workflows/run-header-tests.yml
[test-folder]: https://github.com/modelica/fmi-ls-bus/tree/main/headers/tests/test
[helper-folder]: https://github.com/modelica/fmi-ls-bus/tree/main/headers/tests/helper
[makefile]: https://github.com/modelica/fmi-ls-bus/tree/main/tests/CMakeLists.txt
