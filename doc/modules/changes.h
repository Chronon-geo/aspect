/**
 * @page changes_after_0_3 Changes after Version 0.3

<p>
This is the list of changes made after the release of
Aspect version 0.3.
All entries are signed with the names of the author.
</p>

<ol>
  <li>New: There is now a cookbook describing the
  usage of the GPlates plugin and possible applications.
  The internal velocity representation in the plugin was
  changed to cartesian and a smoothing algorithm was
  introduced.
  <br>
  (Rene Gassmoeller, Wolfgang Bangerth, 2014/04/12)

<ol>
  <li>New: A global parameter ``Maximum time step''
  allows the user to select the largest time step that
  a simulation can take.  This may be useful for
  complicated models or benchmarking.
  <br>
  (Ian Rose, Wolfgang Bangerth, 2014/04/12)

<ol>
  <li>Fixed: The simple material model now ignores negative
  compositional values that can occur from numerical undershots
  and even interpolation onto the FE space. This makes the
  cookbook/composition-active.prm work again.
  <br>
  (Timo Heister, 2014/04/08)

  <li>New: New options to remove rotational/translational modes
  from the solution.
  <br>
  (Ian Rose, Timo Heister, 2014/04/07)

  <li>New: A geometry model implementing a full sphere. There is also
  a corresponding gravity model where gravity increases linearly as you
  move outward.
  <br>
  (Ian Rose, 2014/04/07)

  <li>New: The box geometry allows you to specify a repetition
  argument in each coordinate direction.
  <br>
  (Timo Heister, 2014/04/07)

  <li>New: On startup, ASPECT now prints out whether it is
  running in debug or optimized mode. This is now part of a general
  status message at the top of every run.
  <br>
  (Wolfgang Bangerth, Juliane Dannberg, 2014/04/7)

  <li>Changed: The GPlates plugin for surface velocities always
  interpreted the start time of the model and the time increment
  between individual input files in seconds. It now honors the
  'Use years in output instead of seconds' flag in the input file.
  <br>
  (Wolfgang Bangerth, Rene Gassmoeller, 2014/04/01)

  <li>New: CMake now passes down a preprocessor defined string constant
  called <code>ASPECT_SOURCE_DIR</code> that is set to the (top level)
  directory in which the ASPECT sources are located. This can be used
  by plugins to locate where data files are (e.g., in the <code>data/</code>
  directory of the source tree) independent of where the executable is
  finally called.
  <br>
  (Wolfgang Bangerth, 2014/03/31)

  <li>New: The manual now contains a cookbook section that discussed a
  model running in a 3d spherical shell. Movies for this model can
  be found at https://www.youtube.com/channel/UCDTTQ068ablZ8k9J31wNk_Q .
  <br>
  (Wolfgang Bangerth 2014/03/30)

  <li>Changed: The 'radial constant' gravity model had a default of
  $30 m/s^2$ for the magnitude of the gravity. This value makes no
  sense. It has therefore been changed to the value we have at
  Earth's surface: $9.81 m/s^2$.
  <br>
  (Wolfgang Bangerth, 2014/03/29)

  <li>Fixed: Correct computation of min/max composition statistics.
  <br>
  (Timo Heister, 2014/03/26)

  <li>Fixed: Corrected calculation of non-dimensional temperature in the
  temperature statistics postprocessor plugin.
  <br>
  (Eric Heien, 2014/03/24)

  <li>Fixed: Restarting from a previously checkpointed solution
  did not work when using the Intel compiler and its standard library.
  This is now fixed.
  <br>
  (Wolfgang Bangerth, Jacqueline Austermann 2014/03/21)

  <li>New: There is now a postprocessor that computes a measure of
  dynamic topography, based on the vertical component of the stress.
  There is also a visualization postprocessor that allows to write this
  information into the visualization files to generate graphical
  representations of the data.
  <br>
  (Wolfgang Bangerth, Jacqueline Austermann 2014/03/20)

  <li>New: Aspect now installs a file <code>AspectConfig.cmake</code>
  into the same directory as the executable that can be used by
  plugins to set up compiler flags, include paths, etc, to compile
  a set of source files into a shared library that can then be
  loaded at run time from the input file. See the manual for more
  information about this mechanism.
  <br>
  (Matthias Maier, Wolfgang Bangerth 2014/03/03)

  <li>New: The manual now contains a cookbook section introducing a
  model that runs in a two-dimensional annulus.
  <br>
  (Wolfgang Bangerth 2014/02/17)

  <li>New: When running long simulations, the output generated by
  the "depth average" postprocessor can become messy and hard
  to visualize in the format previously used because it was,
  essentially, just a text based table. The data is now written
  into a file, named <code>depth_average.ext</code> in the
  output directory, in any of the output formats supported
  by deal.II, where <code>ext</code> is the matching file
  name extension for the format. This allows visualization
  as a time-depth plot. The format is selected in the input
  file, along with a number of other settings.
  <br>
  (Wolfgang Bangerth 2014/02/16)

  <li>New: The "depth average" postprocessor now takes a run-time
  parameter in the "Postprocess/Depth average" section of the input
  file that specifies into how many depth slices the domain should
  be subdivided in computing depth averages.
  <br>
  (Wolfgang Bangerth 2014/02/14)

  <li>Fixed: The "depth average" postprocessor did not honor the
  "Use years in output instead of seconds" parameter in the input
  file and instead always printed time in seconds when generating
  output. This is now fixed.
  <br>
  (Wolfgang Bangerth 2014/02/11)

  <li>New: The "Simple setups" section of the manual now has a subsection
  detailing the generalization of the "Convection in a box" setup to
  a three-dimensional situation. This includes links to the movies
  already available http://www.youtube.com/watch?v=_bKqU_P4j48 and
  http://www.youtube.com/watch?v=CzCKYyR-cmg .
  <br>
  (Wolfgang Bangerth 2014/01/29)

  <li>New: The manual has a new subsection at the top of the "Cookbooks"
  section providing a bit of an outline of how one sets up situations.
  <br>
  (Wolfgang Bangerth 2014/01/29)

  <li>New: Linear algebra can be done using PETSc instead of Trilinos. For
  this, deal.II needs to be configured with PETSc and the preprocessor
  define <code>USE_PETSC</code>
  needs to be set in the Aspect file <code>include/aspect/global.h</code> before
  compiling. This feature is still experimental.
  <br>
  (Timo Heister, Ian Rose 2014/01/21)

  <li>Fixed: On systems where one needs to link executables statically
  (for example on big clusters), it is not possible to load additional
  plugins via external shared libraries. This is now disabled and any
  attempt to do so will lead to a run-time error.
  <br>
  (Rene Gassmoeller, Wolfgang Bangerth 2014/01/10)

  <li>New: There is now a section in the manual that describes how to
  reproduce the van Keken et al. benchmark.
  <br>
  (Cedric Thieulot, Juliane Dannberg,
   Timo Heister, Wolfgang Bangerth 2014/01/10)

  <li>Fixed: Using the 'density', 'nonadiabatic temperature', 'thermal
  energy' or 'viscosity' mesh refinement criterion for parallel computations
  led to meshes that made no sense. This was due to a bug in deal.II, not
  Aspect, and has been fixed starting with deal.II 8.1. Using this version
  of deal.II now also fixes the problem in Aspect.
  <br>
  (Wolfgang Bangerth 2013/12/18)

  <li>Fixed: The 'temperature statistics' postprocessor put a column
  'Average nondimensional temperature (K)' into the statistics file that
  was computed as the average temperature divided by the maximal temperature
  at the boundary. This made no sense if the maximal temperature at the
  boundary was zero or if the minimal temperature was nonzero. In fact,
  it also made no sense if the temperature at the boundary was not prescribed.
  This is now fixed: the column is computed as the ratio of the average temperature
  divided by the <i>difference</i> between maximal and minimal temperature,
  and it is omitted altogether if the temperature is not prescribed on any
  part of the boundary or if the difference between minimal and maximal
  prescribed boundary is zero.
  <br>
  (Wolfgang Bangerth 2013/12/05)

  <li>New: There is now a run time parameter that indices the minimal
  refinement level of the mesh.
  <br>
  (Juliane Dannberg 2013/12/03)

  <li>New: The 'composition' mesh refinement criterion now allows to scale
  the various compositional fields differently, through parameters given
  in the input file.
  <br>
  (Juliane Dannberg 2013/12/03)

  <li>New: There are now two new mesh refinement criteria: 'nonadiabatic
  temperature' refines based on the nonadiabatic part of the temperature
  field; 'viscosity' refines based on the viscosity considered as a spatially
  variable field.
  <br>
  (Juliane Dannberg 2013/12/03)

  <li>Fixed: When using adiabatic initial conditions with a shell geometry and
  an opening angle of 90 degrees, the perturbation was not located where it
  was supposed to be. This is now fixed.
  <br>
  (Juliane Dannberg 2013/12/02)

  <li>New: There are now boundary temperature and boundary composition models
  that simply use the initial temperature and composition as the values
  that should hold at the boundary for all future times.
  <br>
  (Juliane Dannberg 2013/12/02)

  <li>New: Material models can now include reactions between compositional
  species.
  <br>
  (Juliane Dannberg 2013/12/01)

  <li>Fixed: The shear heating term $2\eta \left(\varepsilon(\mathbf u)-
  \frac 13 (\textrm{div}\; \mathbf u)I\right):\left(\varepsilon(\mathbf u)-
  \frac 13 (\textrm{div}\; \mathbf u)I\right)$ was computed wrongly for
  compressible models for which the divergence of the velocity field is
  nonzero. This is now fixed.
  <br>
  (Wolfgang Bangerth 2013/11/25)

  <li>Fixed: The composition and temperature statistics postprocessors
  incorrectly computed the maximal compositional values and maximal
  temperature if this maximum was less than or equal to zero. This
  is now fixed.
  <br>
  (Wolfgang Bangerth 2013/11/25)

  <li>New: One can now select in the input file that the model should
  include latent heat. The generation of latent heat then needs to be
  described in the material model.
  <br>
  (Juliane Dannberg 2013/11/24)

  <li>New: It is now possible to prescribe boundary values for
  compositional fields in cases where there is inflow through
  a segment of the boundary. This is implemented through a set
  of plugins for boundary values in the same way as is done for
  temperature boundary values.
  <br>
  (Juliane Dannberg 2013/11/24)

  <li>New: There is now a refinement criterion "topography" that makes sure
  the mesh is always refined at the surface of the domain.
  <br>
  (Juliane Dannberg 2013/11/24)

  <li>Fixed: When using compressible models with nonlinear iterations
  such as "Stokes", "iterated IMPES" or "iterated Stokes" and prescribed
  boundary values, there were numerous bugs that should now be fixed.
  <br>
  (Wolfgang Bangerth 2013/11/21)

  <li>Changed: When the user selects to terminate by end time, the
  final time step is adjusted to hit the final time exactly.
  <br>
  (Ryan Grove 2013/11/19)

  <li>Fixed: When using compressible models, we fixed up the right hand side
  vector in a way so that the mean divergence is zero (even though it is of
  course locally nonzero due to the compressibility). This is necessary to ensure
  the solvability of the linear system, but it is wrong if the domain has open
  boundaries through which fluid can escape or enter. We now only perform
  this correction if there are no open boundaries and no boundaries with a
  prescribed velocity.
  <br>
  (Wolfgang Bangerth 2013/11/19)

  <li>New: It is now possible to prescribe the velocity only for certain
  components in the 'Prescribed velocity boundary indicators' parameter.
  <br>
  (Timo Heister 2013/11/08)

  <li>New: the "iterated Stokes" nonlinear solver will now stop iterating
  if the residual is smaller than the new "Nonlinear solver tolerance".
  <br>
  (Timo Heister 2013/11/02)

  <li>New: add a visual postprocessor that outputs the artificial
  viscosity parameter for the temperature equation on each cell.
  <br>
  (Timo Heister 2013/10/28)

  <li>Fixed: Moved particle generation to a class, changed particle
  integration and generation to be factory patterned classes. There
  should be no effect on the user but this will allow for easier
  extension of particle functionality in the future.
  <br>
  (Eric Heien 2013/10/14)

  <li>New: Aspect now not only generates a <code>solution-NNNNN.visit</code>
  file for each time step but also a global <code>solution.visit</code> file
  that Visit can use to visualize the entire time dependent solution. (Both
  of these work with versions of Visit that support this, including Visit 2.5.0.
  Unfortunately, versions of Visit between 2.5.1 and the version current at
  the time of writing this, 2.6.3, have a bug that prevents this.)
  <br>
  (Wolfgang Bangerth 2013/10/08)

  <li>Fixed: Performance of matrix assembly has been improved significantly,
  especially in 3d: assembly of the temperature system is up to three
  times faster, assembly of the Stokes system up to 50%.
  <br>
  (Timo Heister, Thomas Geenen, Wolfgang Bangerth 2013/10/08)

  <li>New: HDF5/XDMF will only output mesh data when the mesh changes,
  reducing total data output significantly. XDMF serialization is also
  properly implemented.
  <br>
  (Eric Heien, 2013/09/27)

  <li>New: HDF5 output now uses DataOutFilter to remove redundant
  vertices/values in output data.
  <br>
  (Eric Heien, 2013/09/27)

  <li>New: Aspect now supports periodic domains (a recent development version of deal.II
  is required).
  <br>
  (Ian Rose, Timo Heister, 2013/09/11)

  <li>New: The manual now has a new section discussing ways to make computations
  go faster.
  <br>
  (Wolfgang Bangerth, 2013/09/03)

  <li>Fixed: The assembly of the temperature and compositional linear systems
  in each time step used an unnecessarily large number of quadrature points.
  This is now fixed.
  <br>
  (Thomas Geenen, 2013/08/30)

  <li>Extended: The ability to compute with tracers has been completely
  overhauled. In particular, there is now a cookbook in the manual that
  describes how to use them.
  <br>
  (Wolfgang Bangerth, 2013/08/13)

  <li>Added: ability to terminate simulation after
  specified number of steps. This is implemented as one of the
  terminator modules that can be selected from the input file.
  <br>
  (Ted Studley, 2013/07/03)

  <li>Added: new initial conditions for the Box geometry
  to test different shaped inclusions.
  <br>
  (Ted Studley, 2013/06/20)

  <li>Removed: The parameter "Nonlinear iteration" was
  not used anywhere so it got removed. You might need
  to delete this line from your prm files.
  <br>
  (Timo Heister, 2013/06/20)

  <li>New: Nonlinear solver scheme = 'Stokes only' only
  solves the Stokes system and ignores temperature and
  compositional fields.
  <br>
  (Timo Heister, 2013/06/20)

  <li>New: If the underlying deal.II version supports this,
  then VTK or VTU files now contain information about the time
  and time step number corresponding to each file, and this
  is then displayed when using Visit as the visualization
  program.
  <br>
  (Wolfgang Bangerth, 2013/06/16)

  <li>New: In order to implement extensions, in particular
  new plugins for material models, geometries, etc, it used to
  be necessary to put the new files into the Aspect source
  directories and re-compile all of Aspect. This is now no
  longer necessary: You can just compile your additional
  plugins into a shared library and tell Aspect via the
  parameter file to load this shared library at start-up.
  Details on this process are provided in the manual in
  the section "How to write a plugin".
  <br>
  (Wolfgang Bangerth, 2013/06/16)
</ol>


*/
