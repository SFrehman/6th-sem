@echo off
cls

:: 1. Ask for the file name
set /p input="Enter file name: "

:: Strip out .l or .lex if the user typed it, to get the bare filename
set "filename=%input:.l=%"
set "filename=%filename:.lex=%"

echo.
echo [1/3] Generating %filename%.yy.c ...
flex -o "%filename%.yy.c" "%filename%.l"
if %errorlevel% neq 0 goto fail

echo [2/3] Compiling %filename%.exe ...
gcc "%filename%.yy.c" -o "%filename%.exe"
if %errorlevel% neq 0 goto fail

echo [3/3] Running %filename%.exe ...
cls
echo ---------------------------------------
echo 	   %filename% is running
echo ---------------------------------------
"%filename%.exe"

echo.
echo ---------------------------------------
echo Execution finished.
pause
exit /b

:fail
echo.
echo ERROR: Compilation failed.
pause