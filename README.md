[![Maven Test Build](https://github.com/jexxa-projects/clegmed-app/actions/workflows/cmakeBuild.yml/badge.svg)](https://github.com/jexxa-projects/clegmed-app/actions/workflows/cmakeBuild.yml)
[![New Release](https://github.com/jexxa-projects/clegmed-app/actions/workflows/newRelease.yml/badge.svg)](https://github.com/jexxa-projects/clegmed-app/actions/workflows/newRelease.yml)

# 
This template can be used to start your own JLegMed application

## Requirements

*   **Language Standard:** C++23 (Enforced via CMake)
*   **Build System:** CMake 4.1+ (Target-based architecture)
*   **Compiler:** Apple Clang 21.0.0 / GCC 13+
*   **Unit Testing Framework:** GoogleTest v1.17.0 (Integrated as SOUP via `FetchContent`)

## Build the Project

*   Check out the new project in your favorite IDE

*   Build the project:
    ```bash
    # 1. Create and enter the build directory
    mkdir -p build && cd build
    
    # 2. Configure the project and fetch dependencies (GoogleTest)
    cmake ..
    
    # 3. Compile the shared library and the test runner
    cmake --build .
    ```

## Start Developing your Project

### Set up your project on GitHub

To continuously build and deploy your application, we recommend using GitHub as described [here](README-GitHub.md).

### Package Structure
To organize our code, we recommend the following package structure. Since messages are treated as first-class objects, we strongly recommend a fine-grained packages structure:



``` 
(src)
    flowgraph // Provides app specific flow graphs 
        |    contract         // Data structures used between filters
        |    error            // Exceptions or error structs occurred during processing
        
    plugins   // Provides app specific filter 
    |    <technology 1>
    |    ...
    |    <technology n>
    dto
        |    consumedmessage  // Messages received by the app
        |    publishedmessage // Messages published by the app
        |    domainevent      // Domain events published by the app
        |    telemetrydata    // Telemetry data published by the app
 
```


### Cleanup Readme

After successfully setting up your new project, you should clean up the text of README as described [here](https://www.makeareadme.com)