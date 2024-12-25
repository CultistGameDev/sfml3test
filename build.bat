@echo off

cmake -B build -G Ninja -S .
cmake --build build

del .\compile_commands.json
copy /a .\build\compile_commands.json .

