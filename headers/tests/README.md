# Module Header Tests
This directory can be used to add tests for existing module header files. The files in this directory provide the resources to run the tests with the corresponding workflow in Github Actions ([run-header-tests-Debug][header-tests-debug] and [run-header-tests-Release][header-tests-release]). The release workflow is run automatically for pull requests to the main branch. The debug workflow can be used by developers on their respective branches for testing in between.

## Adding Tests for a New Module
To add tests for another module, a few files need to be added and altered. This description assumes that the modules header files (fmi3LsBus<MODULE>.h and fmi3LsBusUtil<MODULE>.h) have already been added.

### Add Test Code
The files containing the test definitions according to gtest can are added in the subdirectory [tests/test][test-folder]. Each module has one file with all tests. The naming convention for files in this directory is 'fmi_3_ls_bus_header_tests_<MODULE>.cpp' with a lowercase module name (e.g. 'fmi_3_ls_bus_header_tests_can.cpp'). **The naming convention needs to be followed in order for the tests to run.**

### Add Helper Files
It is possible to add helper code for the tests in order to reduce complexity and line count in the main test code. Such files can be added to the subdirectory [tests/helper][helper-folder]. Each module can have one helper code-file (added to subdirectory 'src') and one helper header-file (added to subdirectory 'hdr'). The naming convention for files in these directories is 'fmi_3_ls_bus_header_test_helper_<MODULE>.\[cpp/h\]' with a lowercase module name (e.g. 'fmi_3_ls_bus_header_test-helper_can.\[cpp/h\]'). **The naming convention needs to be followed in order for the tests to run.**

### Adjust References to Other Files
Depending on how the files were structured when the code was initially written, the paths to e.g. header files might not be correct anymore. 

### Add Module as Option in Debug Workflow
The debug workflow ([run-header-tests-Debug]) provides the possibility to choose a subset of available modules to run tests for. In file [run-header-tests-Debug.yml][header-tests-debug-file], the module name needs to be added. It is important that the name is added **without blankspaces** in order for the workflow to run succesfully (**Correct**: line 9 - 'default: can;lin' **Wrong**: line 9 - 'default: can; lin). Also make sure that the module names are written in lowercase. In addition to this, the name needs to be added to the description in line 10 to the list of available modules.

[header-tests-debug]: https://github.com/emvahle/fmi-ls-bus/actions/workflows/run-header-tests-Debug.yml
[header-tests-release]: https://github.com/emvahle/fmi-ls-bus/actions/workflows/run-header-tests-Release.yml
[test-folder]: https://github.com/emvahle/fmi-ls-bus/tree/main/headers/tests/test
[helper-folder]: https://github.com/emvahle/fmi-ls-bus/tree/main/headers/tests/helper
