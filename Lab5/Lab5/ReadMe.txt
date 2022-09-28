Lab 5 Readme

Ilan Barr: worked on questions 1, 5, 8-10

Adam Oubaita: worked on questions 2-4, 6-7

Errors:

Still failing 4 of the JUnit Tests:

Test	Duration	Traits	Error Message
Project: UnitTest Failed (4)	555 ms		
Namespace: UnitTest Failed (4)	555 ms		
Class: catCommand Failed (4)	555 ms		
executeTextFileNoAppendSavingMultipleLines Failed	< 1 ms		Assert failed. Expected:<foo> Actual:<hello world multiple lines>
executeTextFileNoAppendSaving Failed	< 1 ms		Assert failed. Expected:<foo> Actual:<hello world>
executeTextFileAppendSaving Failed	3 ms		Assert failed. Expected:<foo> Actual:<foohello world>
executeImageFileNoAppendSavingGoodInput Failed	552 ms		Assert failed. Expected:<> Actual:<X X X X X>




We have no warnings when building:
Build started...
1>------ Build started: Project: Lab5, Configuration: Debug x64 ------
1>Lab5.cpp
1>Lab5.vcxproj -> H:\332Work\STUD16\Lab5\x64\Debug\Lab5.exe
========== Build: 1 succeeded, 0 failed, 1 up-to-date, 0 skipped =========


For our extra command prompt function we implemented a close delete commmand.
This command can close and delete a file at once. It does not require the user to manually 
close and then delete the file.

