---
layout: internal
---

## Scalar Transport

## Overview
Transport of a passive scalar `T` is done with `myScalarTransportFoam`. This solver is used to obtain a solution to the advection-diffusion equation given a known velocity field `U`.

`    dT           
    -- + Div(UT) - Laplacian(DTT) = Q
    dt           
`
The diffusion coefficient `DT` is assumed to be a constant scalar, `Q` is the source term.

## Steps
See [here](http://web.student.chalmers.se/groups/ofw5/Advanced_Training/SwirlTestWithGit.pdf) for an example. The following steps assume the velocity field `U` is already defined on a mesh. `myScalarTransportFoam` is compiled in `$FOAM_USER_APPBIN` and is based on `$FOAM_SOLVERS/basic/scalarTransportFoam`. The code is in `windninja/src/ninjafoam/utility/myScalarTransportFoam` and includes `createFields.H` and `myScalarTransportFoam.C`.

* The scalar field `T` and the vector field `U` are read in from `xx/T` and `xx/U`, where `xx` is the current time step. Boundary conditions are also specified here.
* The diffusion coefficient `DT` and fluid density `rho` are defined in `constant/transportProperties`. `DT` is read in with `createFields.H`.
* The source term is defined in `0/source`. A non-uniform source can be set by the `setFields` utility. The cells to set are specified in `system/setFieldsDict`. For example:


```
defaultFieldValues

(
    volScalarFieldValue source 0
);

regions
(
    boxToCell //distribute source in cells within a bounding box
    {
        box (-1 -1 -1) (1E10 1E10 1600);        
        fieldValues
        (
            volScalarFieldValue source 333.0
        );
    }
);

regions
(
    nearestToCell //distribute source in cell nearest to a point
    {
        points ((334707 4807053 2200));             
        fieldValues
        (         
            volScalarFieldValue source 333.0
        );
    }

);
```


* A template `controlDict` for `scalarTransportFoam` is included in `windninja/data/ninjafoam.zip`.

## Limitations
Currently we assume a single constant diffusion coefficient. A better approach would be to allow different diffusivities in the horizontal and vertical directions and based on atmospheric stability.

    dT/dt + Div(UT) - d/dx(Rx(dT/dx)) - d/dy(Ry(dT/dy)) - d/dz(Rz(dT/dz)) = 0

where `Rx`, `Ry`, and `Rz` are the eddy diffusivities. As a first attempt we could calculate the eddy diffusivities based on mixing length theory as:

    Rz = lm * dU/dz
    lm = 0.4 * z where z is distance to the wall
    Rx = Ry = 2*Rz

Stability parameterizations (e.g., Kumar and Sharan 2012) could also be used.