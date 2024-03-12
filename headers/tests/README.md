# Module Header Tests

This directory can be used to add tests for existing module header files. The files in this directory provide the resources to run the tests with the corresponding workflow in Github Actions ([run-header-tests-Debug][header-tests-debug]/[run-header-tests-Release][header-tests-release]).

## Adding Tests for a New Module
To add tests for another module, a few files need to be added and altered.











[![Build Specification](https://github.com/modelica/fmi-ls-bus/actions/workflows/build-ls-bus.yml/badge.svg)](https://github.com/modelica/fmi-ls-bus/actions/workflows/build-ls-bus.yml)

This repository contains a current prototype draft for the FMI Layered
Standard Network Communication (fmi-ls-bus) based on the 
[Functional Mock-up Interface][FMI] 3.0 standard for the exchange of
simulation models. Note that this draft is being worked on actively,
and thus are subject to change without notice.

This is currently not normative, nor is this document to be considered
officially endorsed by the Modelica Association or other involved
organisations prior to official adoption.

The [FMI 3.0 Layered Standard Network Communication][spec] is currently
maintained on [GitHub][githubspec] and is published [here][spec]. It is
based on the [FMI][] standard.

## Repository Structure
- `docs` -- Sources of the specification document
- `headers` -- Header files of the C-API
- `schema` -- XSD schema for this FMI Layered
Standard

## Getting Started
To help you get started, we provide introductory chapters.
The following resources are currently available:

* [Getting started with CAN, CAN FD and CAN XL]

## Demos
[Demo FMUs] are available within the [FMI LS Bus Implementers' Guide] to illustrate how to use and implement the fmi-ls bus.
More demos will be added iteratively in the near future.
See also the overview pages for the demos, categorized by the different supported bus types of the fmi-ls-bus.  

* [CAN, CAN FD and CAN XL Demo Overview] 

## FMI LS Bus Implementers' Guide
The [FMI LS Bus Implementers' Guide] is a free resource intended to give non-normative recommendations and guidance to implementers of the Functional Mock-up Interface layered standard Network Communication (FMI-LS-BUS).

## Copyright and License
Code and documentation copyright (C) 2008-2011 the MODELISAR consortium and 2012-2024 the Modelica Association Project FMI.
Code released under the [2-Clause BSD License].
Docs released under [Attribution-ShareAlike 4.0 International].

[header-tests-debug]: https://github.com/emvahle/fmi-ls-bus/actions/workflows/run-header-tests-Debug.yml
[header-tests-release]: https://github.com/emvahle/fmi-ls-bus/actions/workflows/run-header-tests-Release.yml
