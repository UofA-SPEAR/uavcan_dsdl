# SPEAR UAVCAN Data Type Definitions #

This repository contains the custom DSDL definitions SPEAR uses for its rovers,
as well as scripting to easily generate this code.

In lieu of a build-level system to generate the DSDL, all generated code is
also checked in, to allow members to simply use this repository as a submodule
and not worry about extra dependancies or the increased build times.

*Bearing this in mind, please keep the amount of churn (i.e. number of times
DSDL is re-generated with changes or different versions of tools) to a minimum.
This will help keep download times low for future users of this repo,
especially if it transitions to DSDL-only.*

## Nunavut

Temporarily, until the PR gets merged into upstream, a fork of Nunavut is
included as a submodule. To install this version, make sure you have updated
all submodules, and are using a python version of 3.7 or higher.

Then

```
cd nunavut/
python setup.py install
```

*It may make sense to run this inside of a venv, virtualenv, or other
python local installation of your choice. At least until the PR is in.*

## Generating DSDL

Simply run the script. Currently it's only available on Linux (with bash),
however it should be easy enough to just do that nnvg commands by hand on
Windows or Mac if you want.

```
./generate_dsdl.sh out_dir
```

The `out_dir` is optional, nunavut will default to `nunavut_out` if none
is supplied.

