# Release Checklist
This (unformal) document provides a strategy description and checklist that can be used to assist in the creation of a new FMI-LS-BUS release.
It serves to ensure that no relevant activities are overlooked when creating a new release.
If new points arise, the list shall be updated accordingly.

## Strategy
The latest development status is currently on the `master` branch of the GitHub project.
Overall, it serves to ensure that the entire FMI-LS-BUS document and the specification of the different bus types can be formally harmonized with each another.
If a release is to be created at the current time, an independent branch must be created for this purpose.
The corresponding release must be created on this branch.
Maintenance also takes place on the created release branch.

## Checklist
The following checklist indicates which points must be taken into account when creating a release:

* [ ] **Document Version:** The `revnumber` and `revdate` fields of the `index.adoc` (see https://github.com/modelica/fmi-ls-bus/blob/main/docs/index.adoc) file needs to be updated accordingly to the specified release version.
* [ ] **Manifest File Example:** The FMI-LS-BUS manifest file example version shall be updated to the specified release version (see https://github.com/modelica/fmi-ls-bus/blob/main/docs/examples/fmi_ls_bus_manifest_example.xml)
* [ ] **Manifest Version:** Update fmi-ls-version of the chapter Layered Standard Manifest File to the respective release version.
* [ ] **MIME Types** Adaptation of the MIME Types (version part), if relevant changes have occurred (see https://modelica.github.io/fmi-ls-bus/main/#low-cut-mime-types).
An update is necessary if the operations have changed within the new target release.
* [ ] **Terminal File Examples:** The FMI-LS-BUS terminal file example MIME Type versions shall be updated corresponding to the specified release (see https://github.com/modelica/fmi-ls-bus/blob/main/docs/examples/) if required.
* [ ] **Remove unsupported Bus Types:** All unsupported buses and MIME Types (see MIME Types chapter) of the respective version (see https://github.com/modelica/fmi-ls-bus/milestones) must be removed before creating the respective release.
The removal takes place on the created side branch.
* [ ] **Milestones:** Can milestones (see https://github.com/modelica/fmi-ls-bus/milestones) be closed by the generated release? If so, close this on GitHub.
* [ ] **Copyright Date:** Checking and adjusting the copyright date of the FMI-LS-BUS document and corresponding header files (see https://github.com/modelica/fmi-ls-bus/tree/main/headers); if necessary.
* [ ] **Roadmap:** If the release to be created relates to a milestone within the roadmap, the roadmap (`roadmap.drawio`) must be updated accordingly.
After this the `roadmap.svg` file must then also be regenerated.
* [ ] **FMI-LS-BUS Implementer's Guide:** Update demo FMUs (modelDescription.xml, fmi-ls-manifest.xml, PackFMU.py) of FMI LS BUS Implementer's Guide (see https://github.com/modelica/fmi-guides/tree/main/ls-bus-guide/demos) if necessary.