@echo off
cd /d "%~dp0"

echo.
echo Syncing files to GitHub...
echo [..........] 0%% Complete
echo.

:: Step 1
git add . >nul 2>&1
cls
echo Syncing files to GitHub...
echo [###.......] 33%% Complete
echo Staging files... Done.
echo.

:: Step 2
git commit -m "Updated scripts and datasets" >nul 2>&1
cls
echo Syncing files to GitHub...
echo [#######....] 66%% Complete
echo Staging files... Done.
echo Committing changes... Done.
echo.

:: Step 3
git push origin main >nul 2>&1
cls
echo Syncing files to GitHub...
echo [##########] 100%% Complete
echo Staging files... Done.
echo Committing changes... Done.
echo Uploading to GitHub... Done.
echo.
echo Sync complete!
pause