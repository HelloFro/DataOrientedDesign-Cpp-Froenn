# CST407SRS02
Data Oriented Design

Project Name(s):  

    - DODRC
    - DODShare

Purposes:  

    - Understand Data Oriented Design.  
    - Learn to use C++ concurrency library.  
    - Practice using the C++ random number generator and clocks.  

Specification:  

This SRS contains 2 parts. The 2 parts are distinct projects but related conceptually.  

You will need to create all the files needed for this SRS, including the .gitignore which you can take from an old SRS.  

For both parts of the SRS, you will need to do the following:  

- Create a contiguous array of bytes (std::byte or unsigned char) in 2 dimensions. Tip: Use a single dimensional vector\<std::byte\> and divide into chunks. For example, a 10 x 10 arrray can be thought of as an contiguous single dimension array of 100 where you calculate the index given a row and column. DO NOT create multiple contiguous (ragged) arrays. 
- Fill the array with uniformly distributed random values in the range \[0, 256).  
- Count the number of values greater than the threshold value T, where T is defined in each project below.  

Measure the time it takes to complete counting and graph time as the dependent variable. You may use a spreadsheet to do the graphing. Include the graph in your submission and note where it is located in your REPORT.md file.  

Before coding, write an hypothesis for your results in your REPORT.md file predicting the basic shape of the resulting graph. There are no points having your hypothesis confirmed, but a well thought out hypothesis will earn you points. When completed, review your hypothesis and compare to the actual results expected.  

Tips:  
- array\[N]\[N] does NOT mean a 'C' array in this specification. It means an arbitrary contiguous data structure. 
- You may use a vector<std::byte> and divide into chunks, but any contiguous data structure will work.  
- Compiler optimizations may make a huge difference. Be sure to analyze with and without optimizations turned on. The easiest way to do this is to provide both debug and release versions of your results in your report but feel free to play with other optimization settings.  
    
Create graphs as follows to test both your hypothesis:  

Part 1:  Row/Column Major  (DODRC)

Independent variable (x-axis):  
- Where N == \[1, 5000), create memory contiguous square array\[N]\[N].  

Dependent variable (y-axis):  
- Row order traversal where T is \[0, 255).  
- Column order traversal where T is \[0, 255).  
 
Invariants:  
- Single threaded. Do NOT create multiple threads for this part of the SRS. 

---

Part 2:  Shared  (DODShare)

In this part of the SRS you are going to use multiple threads to do the job. You may use high or low level C++ concurrency techniques, but if you choose low level, expect to feel the pain. You might want to talk to the instructor if you plan to use low level C++ concurrency (std::thread). One reason you might want to use a low level technique (such as std::thread) is you plan to work on Operating Systems as a career choice. This SRS assumes you will not use std::thread so the term "thread" below refers to software threads in general and not std::thread.  

There are 2 techniques for using creating multiple threads. One is to send a thread (think std::async) to process part of the array and return the result through a std::future. The other is to create a contiguous array that is shared between the threads doing the task where each is updating a value in the shared array. The main thread will process the array once all the threads have completed their tasks.  

An example of using a shared array for updaing is to have an array of 100 elements processed by 10 threads (think 10 std::async that return std::future<void> to simulate the lower level std::thread). Have an shared array of 10 counters, where each element is accessed and updated by one of 10 threads.  

Be prepared to run your code live during presentations. If all goes as planned, I'll choose a student demostrate a simple modification that will greatly impact performance.  

Independent variables:  
- Number of tasks that return the result though a std::future.  
- Number of threads using a shared array.  

Compare:  
- The shared array increment technique and the task based return technique.  
- For each technique have T equals 0, 63, 127, 191 and 254.  

Invariants:  
- Row order traversal. (Do NOT do column order traversal)  
- N == 5000, create a contiguous square array\[N]\[N]. This can be any contiguous container (ex. std::array<std::size_t, 5000*5000>) 

Note: If you notice a significantly slow running program due to an old computer, make a note in your REPORT.md and adjust your code as needed.  

###
