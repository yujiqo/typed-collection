To be honest I am not that familiar with building C++ projects using make/cmake etc. So here's how I compile this:
```
// run these once:
mkdir build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build

// then, to compile the project, run this:
cmake --build build

// now, you have an executable here:
./build/main.out
```

And the task ChatGPT gave me:
>Practice Task: Implement a simple Typed Collection class template
>Requirements:
>	1.	Create a template class TypedCollection<T> that stores objects of type T internally using a std::vector<std::shared_ptr<T>>.
>	2.	Add methods:
>	- void add(const T& item) — adds a copy of item (use smart pointers).
>	- template<typename Func> void forEach(Func func) — applies a lambda/function to each item.
>	- size_t count() const — returns number of items.
>	3.	Use a concept to constrain T so that only types that support copying (i.e., are CopyConstructible) can be used.
>	4.	Inside forEach, use a constexpr if to check if T is integral:
>	- If yes, apply func to double the item value (assume T supports * and assignment).
>	- Else just apply func as is.
>	5.	Demonstrate the class by:
>	- Adding int values and printing doubled values.
>	- Adding a user-defined class (e.g., a simple struct with a print() method) and printing with a lambda.
>	6.	Use lambda captures to capture external variables.
>	7.	Use #pragma once in your header file for the class.
>
>What this practices:
>	- Templates & concepts constraints
>	- Smart pointers (shared_ptr)
>	- Lambdas
>	- constexpr if inside templates
>	- Class design & copy/move constructors
>	- Using STL containers (vector)
>	- Preprocessor directive (#pragma once)