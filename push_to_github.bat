@echo off
:: %~dp0 automatically detects the folder where this bat file is running
cd /d "%~dp0"

echo [1/3] Staging your updated AI files...
git add .

echo [2/3] Committing updates...
git commit -m "Updated AI Practical scripts and datasets"

echo [3/3] Uploading changes to GitHub...
git push origin main

echo Sync complete!
pause
