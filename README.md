# FMI Layered Standard Network Communication

[![Build Specification](https://github.com/modelica/fmi-ls-bus/actions/workflows/build-ls-bus.yml/badge.svg)](https://github.com/modelica/fmi-ls-bus/actions/workflows/build-ls-bus.yml)

This repository contains a current prototype draft for the FMI Layered
Standard Network Communication (fmi-ls-bus) based on the upcoming
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
- <<README.md#,README.md>> -- This document

## Copyright and License
Code and documentation copyright (C) 2008-2011 the MODELISAR consortium and 2012-2023 the Modelica Association Project FMI.
Code released under the https://opensource.org/licenses/BSD-2-Clause[2-Clause BSD License].
Docs released under https://creativecommons.org/licenses/by-sa/4.0/[Attribution-ShareAlike 4.0 International].

[FMI]: https://fmi-standard.org/
[githubspec]: docs/index.adoc
[spec]: https://modelica.github.io/fmi-ls-bus/main/
