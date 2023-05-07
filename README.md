# DesignPatternsAdapterToDecorator
Structural Design Patterns excercises: Adapter to Decorator

To get the project:
Following the steps in: https://github.com/microsoft/vcpkg/#getting-started
(And also from here: https://github.com/mrtazz/restclient-cpp)
* First, download and bootstrap vcpkg itself; it can be installed anywhere, and installing it globally for Visual Studio projects.
  We recommend somewhere like C:\src\vcpkg or C:\dev\vcpkg, since otherwise you may run into path issues for some port build systems:
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat

* To install the libraries for your project (x86 by default, x64 in the next command), run:
> .\vcpkg\vcpkg install [package name]

* Note: This will install x86 libraries by default. To install x64, run:
> .\vcpkg\vcpkg install restclient-cpp:x64-windows

* In order to use vcpkg with Visual Studio, run the following command (may require administrator elevation):
> .\vcpkg\vcpkg integrate install

* After this, you can now create a New non-CMake Project (or open an existing one). All installed libraries are immediately ready to be #include'd and used in your
  project without additional configuration.
