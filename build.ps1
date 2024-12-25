cmake -B build -G Ninja -S .
cmake --build build

Remove-Item -Force .\compile_commands.json
Copy-Item .\build\compile_commands.json -Destination .
