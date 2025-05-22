To be honest I am not that familiar with building C++ projects using make/cmake etc. So here's how I compile this:
```
// run these once:
make build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build

// then, to compile the project, run this:
cmake --build build

// now , you have an executable here:
./build/main.out
```
