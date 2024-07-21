# locket

A C++ socket library. Please see the [examples](example) for usage.

## Building

1. Clone `locket`.

   ```
   $ git clone https://github.com/loganfin/locket.git
   ```

1. Add locket to your project's `CMakeLists.txt`.

   ```
   project(your_project)

   ...

   # Replace /path/to/locket with the path to your locket installation
   add_subdirectory(<path/to/locket>)

   target_link_libraries(your_project PRIVATE locket)
   ```

1. Build your project as normal.
